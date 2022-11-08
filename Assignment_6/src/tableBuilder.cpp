#include <vector>
#include "antlr4-runtime.h"

#include "ErrorHandler.h"
#include "tableBuilder.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/symtab/Symtab.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/type/TypeChecker.h"
#include "intermediate/type/Typespec.h"
#include "intermediate/util/CrossReferencer.h"

int intermediate::symtab::Symtab::unnamedIndex = 0;

void tableBuilder::printSymTableStack(){
  intermediate::util::CrossReferencer crossReferencer;
  crossReferencer.print(symtabStack);
}

Object tableBuilder::visitProgram(PascalParser::ProgramContext *context) {
  visit(context->programHeader());
  visit(context->block()->declarations());
  visit(context->block()->compoundStatement());
  return nullptr;
}

Object tableBuilder::visitProgramHeader(PascalParser::ProgramHeaderContext *context) {
  PascalParser::ProgramIdentifierContext *idcontext = context->programIdentifier();
  string programName = idcontext->IDENTIFIER()->getText(); // don't shift case

  programId = symtabStack->enterLocal(programName, PROGRAM);
  programId->setRoutineSymtab(symtabStack->push());

  symtabStack->setProgramId(programId);
  symtabStack->getLocalSymtab()->setOwner(programId);

  idcontext->entry = programId;
  return nullptr;
}

Object tableBuilder::visitConstantDefinition(
    PascalParser::ConstantDefinitionContext *context) {
  PascalParser::ConstantIdentifierContext *idcontext = context->constantIdentifier();
  string constantName = toLowerCase(idcontext->IDENTIFIER()->getText());
  SymtabEntry *constantId = symtabStack->lookupLocal(constantName);

  if (constantId == nullptr) {
    PascalParser::ConstantContext *constcontext = context->constant();
    Object constValue = visit(constcontext);

    constantId = symtabStack->enterLocal(constantName, CONSTANT);
    constantId->setValue(constValue);
    constantId->setType(constcontext->type);

    idcontext->entry = constantId;
    idcontext->type = constcontext->type;
  } else {
    error.log(ErrorHandler::Error::REDECLARED_IDENTIFIER, context);

    idcontext->entry = constantId;
    idcontext->type = Predefined::integerType;
  }

  constantId->appendLineNumber(context->getStart()->getLine());
  return nullptr;
}

Object tableBuilder::visitConstant(PascalParser::ConstantContext *context) {
  if (context->IDENTIFIER() != nullptr) {
    string constantName = toLowerCase(context->IDENTIFIER()->getText());
    SymtabEntry *constantId = symtabStack->lookup(constantName);

    if (constantId != nullptr) {
      Kind kind = constantId->getKind();
      if ((kind != CONSTANT)) {
        error.log(ErrorHandler::Error::INVALID_CONSTANT, context);
      }

      context->type = constantId->getType();
      context->value = constantId->getValue();

      constantId->appendLineNumber(context->getStart()->getLine());
    } else {
      error.log(ErrorHandler::Error::UNDECLARED_IDENTIFIER, context);
      context->type = Predefined::integerType;
      context->value = 0;
    }
  } else if (context->characterConstant() != nullptr) {
    context->type = Predefined::charType;
    context->value = context->getText()[1];
  } else if (context->stringConstant() != nullptr) {
    string pascalString = context->stringConstant()->STRING()->getText();
    string unquoted = pascalString.substr(1, pascalString.length() - 2);

    size_t pos = 0;
    while ((pos = unquoted.find("''", pos)) != string::npos) {
      unquoted.replace(pos++, 2, "'");
    }

    pos = 0;
    while ((pos = unquoted.find("\"", pos)) != string::npos) {
      unquoted.replace(pos++, 2, "\\\"");
    }

    context->type = Predefined::stringType;
    context->value = new string(unquoted);
  } else // number
  {
    PascalParser::UnsignedNumberContext *unsignedcontext = context->unsignedNumber();

    if (unsignedcontext->integerConstant() != nullptr) {
      context->type = Predefined::integerType;
      context->value = stoi(context->getText());
    } else {
      context->type = Predefined::realType;
      context->value = stod(context->getText());
    }
  }

  return context->value;
}

Object
tableBuilder::visitTypeDefinition(PascalParser::TypeDefinitionContext *context) {
  PascalParser::TypeIdentifierContext *idcontext = context->typeIdentifier();
  string typeName = toLowerCase(idcontext->IDENTIFIER()->getText());
  SymtabEntry *typeId = symtabStack->lookupLocal(typeName);

  PascalParser::TypeSpecificationContext *typespeccontext =
      context->typeSpecification();

  // Enter the type name of any other type into the symbol table.
  if (typeId == nullptr) {
    PascalParser::TypeSpecificationContext *typecontext = context->typeSpecification();
    visit(typecontext);

    typeId = symtabStack->enterLocal(typeName, TYPE);
    typeId->setType(typecontext->type);
    typecontext->type->setIdentifier(typeId);
  } else {
    error.log(ErrorHandler::Error::REDECLARED_IDENTIFIER, context);
  }

  idcontext->entry = typeId;
  idcontext->type = typespeccontext->type;

  typeId->appendLineNumber(context->getStart()->getLine());
  return nullptr;
}

Object
tableBuilder::visitSimpleTypespec(PascalParser::SimpleTypespecContext *context) {
  visit(context->simpleType());
  context->type = context->simpleType()->type;

  return nullptr;
}

Object tableBuilder::visitTypeIdentifierTypespec(
    PascalParser::TypeIdentifierTypespecContext *context) {
  visit(context->typeIdentifier());
  context->type = context->typeIdentifier()->type;

  return nullptr;
}

Object
tableBuilder::visitTypeIdentifier(PascalParser::TypeIdentifierContext *context) {
  string typeName = toLowerCase(context->IDENTIFIER()->getText());
  SymtabEntry *typeId = symtabStack->lookup(typeName);

  if (typeId != nullptr) {
    if (typeId->getKind() != TYPE) {
      error.log(ErrorHandler::Error::INVALID_TYPE, context);
      context->type = Predefined::integerType;
    } else {
      context->type = typeId->getType();
    }

    typeId->appendLineNumber(context->start->getLine());
  } else {
    error.log(ErrorHandler::Error::UNDECLARED_IDENTIFIER, context);
    context->type = Predefined::integerType;
  }

  context->entry = typeId;
  return nullptr;
}

Object tableBuilder::visitArrayTypespec(PascalParser::ArrayTypespecContext *context) {
  Typespec *arrayType = new Typespec(ARRAY);
  PascalParser::ArrayTypeContext *arraycontext = context->arrayType();
  PascalParser::ArrayDimensionListContext *listcontext =
      arraycontext->arrayDimensionList();

  context->type = arrayType;

  // Loop over the array dimensions.
  int count = listcontext->simpleType().size();
  for (int i = 0; i < count; i++) {
    PascalParser::SimpleTypeContext *simplecontext = listcontext->simpleType()[i];
    visit(simplecontext);
    arrayType->setArrayIndexType(simplecontext->type);
    arrayType->setArrayElementCount(0);

    if (i < count - 1) {
      Typespec *elmtType = new Typespec(ARRAY);
      arrayType->setArrayElementType(elmtType);
      arrayType = elmtType;
    }
  }

  visit(arraycontext->typeSpecification());
  Typespec *elmtType = arraycontext->typeSpecification()->type;
  arrayType->setArrayElementType(elmtType);

  return nullptr;
}

Object tableBuilder::visitVariableDeclarations(
    PascalParser::VariableDeclarationsContext *context) {
  PascalParser::TypeSpecificationContext *typecontext = context->typeSpecification();
  visit(typecontext);

  PascalParser::VariableIdentifierListContext *listcontext =
      context->variableIdentifierList();

  // Loop over the variables being declared.
  for (PascalParser::VariableIdentifierContext *idcontext :
       listcontext->variableIdentifier()) {
    int lineNumber = idcontext->getStart()->getLine();
    string variableName = toLowerCase(idcontext->IDENTIFIER()->getText());
    SymtabEntry *variableId = symtabStack->lookupLocal(variableName);

    if (variableId == nullptr) {
      variableId = symtabStack->enterLocal(variableName, VARIABLE);
      variableId->setType(typecontext->type);

      // Assign slot numbers to local variables.
      Symtab *symtab = variableId->getSymtab();
      if (symtab->getNestingLevel() > 1) {
        variableId->setSlotNumber(symtab->nextSlotNumber());
      }

      idcontext->entry = variableId;
    } else {
      error.log(ErrorHandler::Error::REDECLARED_IDENTIFIER, context);
    }

    variableId->appendLineNumber(lineNumber);
  }

  return nullptr;
}

Object
tableBuilder::visitRoutineDefinition(PascalParser::RoutineDefinitionContext *context) {
  PascalParser::FunctionHeadContext *funccontext = context->functionHead();
  PascalParser::ProcedureHeadContext *proccontext = context->procedureHead();
  PascalParser::RoutineIdentifierContext *idcontext = nullptr;
  PascalParser::ParametersContext *parameters = nullptr;
  bool functionDefinition = funccontext != nullptr;
  Typespec *returnType = nullptr;
  string routineName;

  if (functionDefinition) {
    idcontext = funccontext->routineIdentifier();
    parameters = funccontext->parameters();
  } else {
    idcontext = proccontext->routineIdentifier();
    parameters = proccontext->parameters();
  }

  routineName = toLowerCase(idcontext->IDENTIFIER()->getText());
  SymtabEntry *routineId = symtabStack->lookupLocal(routineName);

  if (routineId != nullptr) {
    error.log(ErrorHandler::Error::REDECLARED_IDENTIFIER,
              context->getStart()->getLine(), routineName);
    return nullptr;
  }

  routineId = symtabStack->enterLocal(
      routineName, functionDefinition ? FUNCTION : PROCEDURE);
  routineId->setRoutineCode(DECLARED);
  idcontext->entry = routineId;

  // Append to the parent routine's list of subroutines.
  SymtabEntry *parentId = symtabStack->getLocalSymtab()->getOwner();
  parentId->appendSubroutine(routineId);

  routineId->setRoutineSymtab(symtabStack->push());
  idcontext->entry = routineId;

  Symtab *symtab = symtabStack->getLocalSymtab();
  symtab->setOwner(routineId);

  if (parameters != nullptr) {
    vector<SymtabEntry *> *parameterIds =
        visit(parameters->parameterDeclarationsList())
            .as<vector<SymtabEntry *> *>();
    routineId->setRoutineParameters(parameterIds);

    for (SymtabEntry *parmId : *parameterIds) {
      parmId->setSlotNumber(symtab->nextSlotNumber());
    }
  }

  if (functionDefinition) {
    PascalParser::TypeIdentifierContext *typeIdcontext = funccontext->typeIdentifier();
    visit(typeIdcontext);
    returnType = typeIdcontext->type;

    if (returnType->getForm() != SCALAR) {
      error.log(ErrorHandler::Error::INVALID_RETURN_TYPE, typeIdcontext);
      returnType = Predefined::integerType;
    }

    routineId->setType(returnType);
    idcontext->type = returnType;
  } else {
    idcontext->type = nullptr;
  }

  visit(context->block()->declarations());

  // Enter the function's associated variable into its symbol table.
  if (functionDefinition) {
    SymtabEntry *assocVarId = symtabStack->enterLocal(routineName, VARIABLE);
    assocVarId->setSlotNumber(symtab->nextSlotNumber());
    assocVarId->setType(returnType);
  }

  visit(context->block()->compoundStatement());
  routineId->setExecutable(context->block()->compoundStatement());

  symtabStack->pop();
  return nullptr;
}

Object tableBuilder::visitParameterDeclarationsList(
    PascalParser::ParameterDeclarationsListContext *context) {
  vector<SymtabEntry *> *parameterList = new vector<SymtabEntry *>();

  // Loop over the parameter declarations.
  for (PascalParser::ParameterDeclarationsContext *dclcontext :
       context->parameterDeclarations()) {
    vector<SymtabEntry *> parameterSublist =
        visit(dclcontext).as<vector<SymtabEntry *>>();
    for (SymtabEntry *id : parameterSublist)
      parameterList->push_back(id);
  }

  return parameterList;
}

Object tableBuilder::visitParameterDeclarations(
    PascalParser::ParameterDeclarationsContext *context) {
  Kind kind = context->VAR() != nullptr ? REFERENCE_PARAMETER : VALUE_PARAMETER;
  PascalParser::TypeIdentifierContext *typecontext = context->typeIdentifier();

  visit(typecontext);
  Typespec *parmType = typecontext->type;

  vector<SymtabEntry *> parameterSublist;

  // Loop over the parameter identifiers.
  PascalParser::ParameterIdentifierListContext *listcontext =
      context->parameterIdentifierList();
  for (PascalParser::ParameterIdentifierContext *idcontext :
       listcontext->parameterIdentifier()) {
    int lineNumber = idcontext->getStart()->getLine();
    string parmName = toLowerCase(idcontext->IDENTIFIER()->getText());
    SymtabEntry *parmId = symtabStack->lookupLocal(parmName);

    if (parmId == nullptr) {
      parmId = symtabStack->enterLocal(parmName, kind);
      parmId->setType(parmType);
    } else {
      error.log(ErrorHandler::Error::REDECLARED_IDENTIFIER, idcontext);
    }

    idcontext->entry = parmId;
    idcontext->type = parmType;

    parameterSublist.push_back(parmId);
    parmId->appendLineNumber(lineNumber);
  }

  return parameterSublist;
}

Object tableBuilder::visitAssignmentStatement(
    PascalParser::AssignmentStatementContext *context) {
  PascalParser::LhsContext *lhscontext = context->lhs();
  PascalParser::RhsContext *rhscontext = context->rhs();

  visitChildren(context);

  Typespec *lhsType = lhscontext->type;
  Typespec *rhsType = rhscontext->expression()->type;

  if (!TypeChecker::areAssignmentCompatible(lhsType, rhsType)) {
    error.log(ErrorHandler::Error::INVALID_ASSIGNMENT, context);
  }

  return nullptr;
}

Object tableBuilder::visitLhs(PascalParser::LhsContext *context) {
  PascalParser::VariableContext *varcontext = context->variable();
  visit(varcontext);
  context->type = varcontext->type;

  return nullptr;
}

Object tableBuilder::visitIfStatement(PascalParser::IfStatementContext *context) {
  PascalParser::ExpressionContext *exprcontext = context->expression();
  PascalParser::TrueStatementContext *truecontext = context->trueStatement();
  PascalParser::FalseStatementContext *falsecontext = context->falseStatement();

  visit(exprcontext);
  Typespec *expr_type = exprcontext->type;

  if (!TypeChecker::isBoolean(expr_type)) {
    error.log(ErrorHandler::Error::EXPECTED_TYPE_BOOLEAN, exprcontext);
  }

  visit(truecontext);
  if (falsecontext != nullptr)
    visit(falsecontext);

  return nullptr;
}

Object tableBuilder::visitCaseStatement(PascalParser::CaseStatementContext *context) {
  PascalParser::ExpressionContext *exprcontext = context->expression();
  visit(exprcontext);
  Typespec *exprType = exprcontext->type;
  Form exprTypeForm = exprType->getForm();

  if (((exprTypeForm != SCALAR) && (exprTypeForm != ENUMERATION)) ||
      (exprType == Predefined::realType) ||
      (exprType == Predefined::stringType)) {
    error.log(ErrorHandler::Error::MISMATCHED_TYPE, exprcontext);
    exprType = Predefined::integerType;
  }

  set<int> constants;
  PascalParser::CaseBranchListContext *branchListcontext = context->caseBranchList();

  // Loop over the CASE branches.
  for (PascalParser::CaseBranchContext *branchcontext :
       branchListcontext->caseBranch()) {
    PascalParser::CaseConstantListContext *constListcontext =
        branchcontext->caseConstantList();
    PascalParser::StatementContext *stmtcontext = branchcontext->statement();

    if (constListcontext != nullptr) {
      // Loop over the CASE constants in each branch.
      for (PascalParser::CaseConstantContext *caseConstcontext :
           constListcontext->caseConstant()) {
        PascalParser::ConstantContext *constcontext = caseConstcontext->constant();
        Object constValue = visit(constcontext);

        caseConstcontext->type = constcontext->type;
        caseConstcontext->value = 0;

        if (constcontext->type != exprType) {
          error.log(ErrorHandler::Error::MISMATCHED_TYPE, constcontext);
        } else if (constcontext->type == Predefined::integerType) {
          caseConstcontext->value = constValue.as<int>();
        } else if (constcontext->type == Predefined::charType) {
          caseConstcontext->value = constValue.as<char>();
        }

        if (constants.find(caseConstcontext->value) != constants.end()) {
          error.log(ErrorHandler::Error::DUPLICATE_CASE_CONSTANT, constcontext);
        } else {
          constants.insert(caseConstcontext->value);
        }
      }
    }

    if (stmtcontext != nullptr)
      visit(stmtcontext);
  }

  return nullptr;
}

Object
tableBuilder::visitRepeatStatement(PascalParser::RepeatStatementContext *context) {
  PascalParser::ExpressionContext *exprcontext = context->expression();
  visit(exprcontext);
  Typespec *exprType = exprcontext->type;

  if (!TypeChecker::isBoolean(exprType)) {
    error.log(ErrorHandler::Error::EXPECTED_TYPE_BOOLEAN, exprcontext);
  }

  visit(context->statementList());
  return nullptr;
}

Object
tableBuilder::visitWhileStatement(PascalParser::WhileStatementContext *context) {
  PascalParser::ExpressionContext *exprcontext = context->expression();
  visit(exprcontext);
  Typespec *exprType = exprcontext->type;

  if (!TypeChecker::isBoolean(exprType)) {
    error.log(ErrorHandler::Error::EXPECTED_TYPE_BOOLEAN, exprcontext);
  }

  visit(context->statement());
  return nullptr;
}

Object tableBuilder::visitForStatement(PascalParser::ForStatementContext *context) {
  PascalParser::VariableContext *varcontext = context->variable();
  visit(varcontext);

  string controlName = toLowerCase(varcontext->variableIdentifier()->getText());
  Typespec *controlType = Predefined::integerType;

  if (varcontext->entry != nullptr) {
    controlType = varcontext->type;
    if ((controlType->getForm() != SCALAR) ||
        (controlType == Predefined::realType) ||
        (controlType == Predefined::stringType)) {
      error.log(ErrorHandler::Error::INVALID_CONTROL_VARIABLE, varcontext);
    }
  } else {
    error.log(ErrorHandler::Error::UNDECLARED_IDENTIFIER,
              context->getStart()->getLine(), controlName);
  }

  PascalParser::ExpressionContext *startcontext = context->expression()[0];
  PascalParser::ExpressionContext *endcontext = context->expression()[1];

  visit(startcontext);
  visit(endcontext);

  if (startcontext->type != controlType)
    error.log(ErrorHandler::Error::MISMATCHED_TYPE, startcontext);
  if (startcontext->type != endcontext->type)
    error.log(ErrorHandler::Error::MISMATCHED_TYPE, endcontext);

  visit(context->statement());
  return nullptr;
}

Object tableBuilder::visitProcedureCallStatement(
    PascalParser::ProcedureCallStatementContext *context) {
  PascalParser::ProcedureNameContext *namecontext = context->procedureName();
  PascalParser::ArgumentListContext *listcontext = context->argumentList();
  string name = toLowerCase(context->procedureName()->getText());
  SymtabEntry *procedureId = symtabStack->lookup(name);
  bool badName = false;

  if (procedureId == nullptr) {
    error.log(ErrorHandler::Error::UNDECLARED_IDENTIFIER, namecontext);
    badName = true;
  } else if (procedureId->getKind() != PROCEDURE) {
    error.log(ErrorHandler::Error::NAME_MUST_BE_PROCEDURE, namecontext);
    badName = true;
  }

  // Bad procedure name. Do a simple arguments check and then leave.
  if (badName) {
    for (PascalParser::ArgumentContext *exprcontext : listcontext->argument()) {
      visit(exprcontext);
    }
  }

  // Good procedure name.
  else {
    vector<SymtabEntry *> *parms = procedureId->getRoutineParameters();
    checkCallArguments(listcontext, parms);
  }

  namecontext->entry = procedureId;
  return nullptr;
}

Object tableBuilder::visitFunctionCallFactor(
    PascalParser::FunctionCallFactorContext *context) {
  PascalParser::FunctionCallContext *callcontext = context->functionCall();
  PascalParser::FunctionNameContext *namecontext = callcontext->functionName();
  PascalParser::ArgumentListContext *listcontext = callcontext->argumentList();
  string name = toLowerCase(callcontext->functionName()->getText());
  SymtabEntry *functionId = symtabStack->lookup(name);
  bool badName = false;

  context->type = Predefined::integerType;

  if (functionId == nullptr) {
    error.log(ErrorHandler::Error::UNDECLARED_IDENTIFIER, namecontext);
    badName = true;
  } else if (functionId->getKind() != FUNCTION) {
    error.log(ErrorHandler::Error::NAME_MUST_BE_FUNCTION, namecontext);
    badName = true;
  }

  // Bad function name. Do a simple arguments check and then leave.
  if (badName) {
    for (PascalParser::ArgumentContext *exprcontext : listcontext->argument()) {
      visit(exprcontext);
    }
  }

  // Good function name.
  else {
    vector<SymtabEntry *> *parms = functionId->getRoutineParameters();
    checkCallArguments(listcontext, parms);
    context->type = functionId->getType();
  }

  namecontext->entry = functionId;
  namecontext->type = context->type;

  return nullptr;
}

void tableBuilder::checkCallArguments(PascalParser::ArgumentListContext *listcontext,
                                   vector<SymtabEntry *> *parms) {
  int parmsCount = parms->size();
  int argsCount = listcontext != nullptr ? listcontext->argument().size() : 0;

  if (parmsCount != argsCount) {
    error.log(ErrorHandler::Error::UNEQUAL_ARGUMENT_COUNTS, listcontext);
    return;
  }

  // Check each argument against the corresponding parameter.
  for (int i = 0; i < parmsCount; i++) {
    PascalParser::ArgumentContext *argcontext = listcontext->argument()[i];
    PascalParser::ExpressionContext *exprcontext = argcontext->expression();
    visit(exprcontext);

    SymtabEntry *parmId = (*parms)[i];
    Typespec *parmType = parmId->getType();
    Typespec *argType = exprcontext->type;

    // For a VAR parameter, the argument must be a variable
    // with the same datatype.
    if (parmId->getKind() == REFERENCE_PARAMETER) {
      if (expressionIsVariable(exprcontext)) {
        if (parmType != argType) {
          error.log(ErrorHandler::Error::MISMATCHED_TYPE, exprcontext);
        }
      } else {
        error.log(ErrorHandler::Error::ARGUMENT_MUST_BE_VARIABLE, exprcontext);
      }
    }

    // For a value parameter, the argument type must be
    // assignment compatible with the parameter type.
    else if (!TypeChecker::areAssignmentCompatible(parmType, argType)) {
      error.log(ErrorHandler::Error::MISMATCHED_TYPE, exprcontext);
    }
  }
}

bool tableBuilder::expressionIsVariable(PascalParser::ExpressionContext *exprcontext) {
  // Only a single simple expression?
  if (exprcontext->simpleExpression().size() == 1) {
    PascalParser::SimpleExpressionContext *simplecontext =
        exprcontext->simpleExpression()[0];
    // Only a single term?
    if (simplecontext->term().size() == 1) {
      PascalParser::TermContext *termcontext = simplecontext->term()[0];

      // Only a single factor?
      if (termcontext->factor().size() == 1) {
        return dynamic_cast<PascalParser::VariableFactorContext *>(
                   termcontext->factor()[0]) != nullptr;
      }
    }
  }

  return false;
}

Object tableBuilder::visitExpression(PascalParser::ExpressionContext *context) {
  PascalParser::SimpleExpressionContext *simplecontext1 =
      context->simpleExpression()[0];

  // First simple expression.
  visit(simplecontext1);

  Typespec *simpleType1 = simplecontext1->type;
  context->type = simpleType1;

  PascalParser::RelOpContext *relopcontext = context->relOp();

  // Second simple expression?
  if (relopcontext != nullptr) {
    PascalParser::SimpleExpressionContext *simplecontext2 =
        context->simpleExpression()[1];
    visit(simplecontext2);

    Typespec *simpleType2 = simplecontext2->type;
    if (!TypeChecker::areComparisonCompatible(simpleType1, simpleType2)) {
      error.log(ErrorHandler::Error::INVALID_COMPARISON, context);
    }

    context->type = Predefined::booleanType;
  }

  return nullptr;
}

Object
tableBuilder::visitSimpleExpression(PascalParser::SimpleExpressionContext *context) {
  int count = context->term().size();
  PascalParser::SignContext *signcontext = context->sign();
  bool hasSign = signcontext != nullptr;
  PascalParser::TermContext *termcontext1 = context->term()[0];

  if (hasSign) {
    string sign = signcontext->getText();
    if ((sign == "+") && (sign == "-")) {
      error.log(ErrorHandler::Error::INVALID_SIGN, signcontext);
    }
  }

  // First term.
  visit(termcontext1);
  Typespec *termType1 = termcontext1->type;

  // Loop over any subsequent terms.
  for (int i = 1; i < count; i++) {
    string op = toLowerCase(context->addOp()[i - 1]->getText());
    PascalParser::TermContext *termcontext2 = context->term()[i];
    visit(termcontext2);
    Typespec *termType2 = termcontext2->type;

    // Both operands bool ==> bool result. Else type mismatch.
    if (op == "or") {
      if (!TypeChecker::isBoolean(termType1)) {
        error.log(ErrorHandler::Error::EXPECTED_TYPE_BOOLEAN, termcontext1);
      }
      if (!TypeChecker::isBoolean(termType2)) {
        error.log(ErrorHandler::Error::EXPECTED_TYPE_BOOLEAN, termcontext2);
      }
      if (hasSign) {
        error.log(ErrorHandler::Error::INVALID_SIGN, signcontext);
      }

      termType2 = Predefined::booleanType;
    } else if (op == "+") {
      // Both operands integer ==> integer result
      if (TypeChecker::areBothInteger(termType1, termType2)) {
        termType2 = Predefined::integerType;
      }

      // Both real operands ==> real result
      // One real and one integer operand ==> real result
      else if (TypeChecker::isAtLeastOneReal(termType1, termType2)) {
        termType2 = Predefined::realType;
      }

      // Both operands string ==> string result
      else if (TypeChecker::areBothString(termType1, termType2)) {
        if (hasSign)
          error.log(ErrorHandler::Error::INVALID_SIGN, signcontext);
        termType2 = Predefined::stringType;
      }

      // Type mismatch.
      else {
        if (!TypeChecker::isIntegerOrReal(termType1)) {
          error.log(ErrorHandler::Error::EXPECTED_TYPE_NUMERIC, termcontext1);
          termType2 = Predefined::integerType;
        }
        if (!TypeChecker::isIntegerOrReal(termType2)) {
          error.log(ErrorHandler::Error::EXPECTED_TYPE_NUMERIC, termcontext2);
          termType2 = Predefined::integerType;
        }
      }
    } else // -
    {
      // Both operands integer ==> integer result
      if (TypeChecker::areBothInteger(termType1, termType2)) {
        termType2 = Predefined::integerType;
      }

      // Both real operands ==> real result
      // One real and one integer operand ==> real result
      else if (TypeChecker::isAtLeastOneReal(termType1, termType2)) {
        termType2 = Predefined::realType;
      }

      // Type mismatch.
      else {
        if (!TypeChecker::isIntegerOrReal(termType1)) {
          error.log(ErrorHandler::Error::EXPECTED_TYPE_NUMERIC, termcontext1);
          termType2 = Predefined::integerType;
        }
        if (!TypeChecker::isIntegerOrReal(termType2)) {
          error.log(ErrorHandler::Error::EXPECTED_TYPE_NUMERIC, termcontext2);
          termType2 = Predefined::integerType;
        }
      }
    }

    termType1 = termType2;
  }

  context->type = termType1;
  return nullptr;
}

Object tableBuilder::visitTerm(PascalParser::TermContext *context) {
  int count = context->factor().size();
  PascalParser::FactorContext *factorcontext1 = context->factor()[0];

  // First factor.
  visit(factorcontext1);
  Typespec *factorType1 = factorcontext1->type;

  // Loop over any subsequent factors.
  for (int i = 1; i < count; i++) {
    string op = toLowerCase(context->mulOp()[i - 1]->getText());
    PascalParser::FactorContext *factorcontext2 = context->factor()[i];
    visit(factorcontext2);
    Typespec *factorType2 = factorcontext2->type;

    if (op == "*") {
      // Both operands integer  ==> integer result
      if (TypeChecker::areBothInteger(factorType1, factorType2)) {
        factorType2 = Predefined::integerType;
      }

      // Both real operands ==> real result
      // One real and one integer operand ==> real result
      else if (TypeChecker::isAtLeastOneReal(factorType1, factorType2)) {
        factorType2 = Predefined::realType;
      }

      // Type mismatch.
      else {
        if (!TypeChecker::isIntegerOrReal(factorType1)) {
          error.log(ErrorHandler::Error::EXPECTED_TYPE_NUMERIC, factorcontext1);
          factorType2 = Predefined::integerType;
        }
        if (!TypeChecker::isIntegerOrReal(factorType2)) {
          error.log(ErrorHandler::Error::EXPECTED_TYPE_NUMERIC, factorcontext2);
          factorType2 = Predefined::integerType;
        }
      }
    } else if (op == "/") {
      // All integer and real operand combinations ==> real result
      if (TypeChecker::areBothInteger(factorType1, factorType2) ||
          TypeChecker::isAtLeastOneReal(factorType1, factorType2)) {
        factorType2 = Predefined::realType;
      }

      // Type mismatch.
      else {
        if (!TypeChecker::isIntegerOrReal(factorType1)) {
          error.log(ErrorHandler::Error::EXPECTED_TYPE_NUMERIC, factorcontext1);
          factorType2 = Predefined::integerType;
        }
        if (!TypeChecker::isIntegerOrReal(factorType2)) {
          error.log(ErrorHandler::Error::EXPECTED_TYPE_NUMERIC, factorcontext2);
          factorType2 = Predefined::integerType;
        }
      }
    } else if ((op == "div") || (op == "mod")) {
      // Both operands integer ==> integer result. Else type mismatch.
      if (!TypeChecker::isInteger(factorType1)) {
        error.log(ErrorHandler::Error::EXPECTED_TYPE_INTEGER, factorcontext1);
        factorType2 = Predefined::integerType;
      }
      if (!TypeChecker::isInteger(factorType2)) {
        error.log(ErrorHandler::Error::EXPECTED_TYPE_INTEGER, factorcontext2);
        factorType2 = Predefined::integerType;
      }

      context->type = Predefined::integerType;
    } else if (op == "and") {
      // Both operands bool ==> bool result. Else type mismatch.
      if (!TypeChecker::isBoolean(factorType1)) {
        error.log(ErrorHandler::Error::EXPECTED_TYPE_BOOLEAN, factorcontext1);
        factorType2 = Predefined::booleanType;
      }
      if (!TypeChecker::isBoolean(factorType2)) {
        error.log(ErrorHandler::Error::EXPECTED_TYPE_BOOLEAN, factorcontext2);
        factorType2 = Predefined::booleanType;
      }
    }

    factorType1 = factorType2;
  }

  context->type = factorType1;
  return nullptr;
}

Object
tableBuilder::visitVariableFactor(PascalParser::VariableFactorContext *context) {
  PascalParser::VariableContext *varcontext = context->variable();
  visit(varcontext);
  context->type = varcontext->type;

  return nullptr;
}

Object tableBuilder::visitVariable(PascalParser::VariableContext *context) {
  PascalParser::VariableIdentifierContext *varIdcontext = context->variableIdentifier();

  visit(varIdcontext);
  context->entry = varIdcontext->entry;
  context->type = variableDatatype(context, varIdcontext->type);

  return nullptr;
}

Object tableBuilder::visitVariableIdentifier(
    PascalParser::VariableIdentifierContext *context) {

  string variableName = toLowerCase(context->IDENTIFIER()->getText());
  SymtabEntry *variableId = symtabStack->lookup(variableName);

  if (variableId != nullptr) {
    int lineNumber = context->getStart()->getLine();
    context->type = variableId->getType();
    context->entry = variableId;
    variableId->appendLineNumber(lineNumber);

    Kind kind = variableId->getKind();
    switch (kind) {
    case TYPE:
    case PROGRAM:
    case PROGRAM_PARAMETER:
    case PROCEDURE:
    case UNDEFINED:
      error.log(ErrorHandler::Error::INVALID_VARIABLE, context);
      break;

    default:
      break;
    }
  } else {
    error.log(ErrorHandler::Error::UNDECLARED_IDENTIFIER, context);
    context->type = Predefined::integerType;
  }

  return nullptr;
}

Typespec *tableBuilder::variableDatatype(PascalParser::VariableContext *varcontext,
                                      Typespec *varType) {
  Typespec *type = varType;

  for (PascalParser::ModifierContext *modcontext : varcontext->modifier()) {
    // Subscripts.
    if (modcontext->indexList() != nullptr) {
      PascalParser::IndexListContext *indexListcontext = modcontext->indexList();

      // Loop over the subscripts.
      for (PascalParser::IndexContext *indexcontext : indexListcontext->index()) {
        if (type->getForm() == ARRAY) {
          Typespec *indexType = type->getArrayIndexType();
          PascalParser::ExpressionContext *exprcontext = indexcontext->expression();
          visit(exprcontext);

          if (indexType->baseType() != exprcontext->type->baseType()) {
            error.log(ErrorHandler::Error::MISMATCHED_TYPE, exprcontext);
          }

          // Datatype of the next dimension.
          type = type->getArrayElementType();
        } else {
          error.log(ErrorHandler::Error::INVALID_SUBSCRIPTS, indexcontext);
        }
      }
    }
  }

  return type;
}

Object tableBuilder::visitNumberFactor(PascalParser::NumberFactorContext *context) {
  PascalParser::NumberContext *numbercontext = context->number();
  PascalParser::UnsignedNumberContext *unsignedcontext =
      numbercontext->unsignedNumber();
  PascalParser::IntegerConstantContext *integercontext =
      unsignedcontext->integerConstant();

  context->type =
      (integercontext != nullptr) ? Predefined::integerType : Predefined::realType;

  return nullptr;
}

Object
tableBuilder::visitCharacterFactor(PascalParser::CharacterFactorContext *context) {
  context->type = Predefined::charType;
  return nullptr;
}

Object tableBuilder::visitStringFactor(PascalParser::StringFactorContext *context) {
  context->type = Predefined::stringType;
  return nullptr;
}

Object tableBuilder::visitNotFactor(PascalParser::NotFactorContext *context) {
  PascalParser::FactorContext *factorcontext = context->factor();
  visit(factorcontext);

  if (factorcontext->type != Predefined::booleanType) {
    error.log(ErrorHandler::Error::EXPECTED_TYPE_BOOLEAN, factorcontext);
  }

  context->type = Predefined::booleanType;
  return nullptr;
}

Object tableBuilder::visitParenthesizedFactor(
    PascalParser::ParenthesizedFactorContext *context) {
  PascalParser::ExpressionContext *exprcontext = context->expression();
  visit(exprcontext);
  context->type = exprcontext->type;

  return nullptr;
}

