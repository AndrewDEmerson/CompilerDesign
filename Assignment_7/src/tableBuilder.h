#pragma once

#include "ErrorHandler.h"
#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/type/Typespec.h"

class tableBuilder : public PascalBaseVisitor {
public:
  tableBuilder() : programId(nullptr) {
    // Create and initialize the symbol table stack.
    symtabStack = new SymtabStack();
    Predefined::initialize(symtabStack);
  }

  void printSymTableStack();
  SymtabEntry *getProgramId() { return programId; }

  Object visitProgram(PascalParser::ProgramContext *context);
  Object visitProgramHeader(PascalParser::ProgramHeaderContext *context);
  Object visitConstantDefinition(PascalParser::ConstantDefinitionContext *context);
  Object visitConstant(PascalParser::ConstantContext *context);
  Object visitTypeDefinition(PascalParser::TypeDefinitionContext *context);
  Object visitSimpleTypespec(PascalParser::SimpleTypespecContext *context);
  Object visitTypeIdentifierTypespec(PascalParser::TypeIdentifierTypespecContext *context);
  Object visitTypeIdentifier(PascalParser::TypeIdentifierContext *context);
  Object visitArrayTypespec(PascalParser::ArrayTypespecContext *context);
  Object visitVariableDeclarations(PascalParser::VariableDeclarationsContext *context);
  Object visitRoutineDefinition(PascalParser::RoutineDefinitionContext *context);
  Object visitParameterDeclarationsList(PascalParser::ParameterDeclarationsListContext *context);
  Object visitParameterDeclarations(PascalParser::ParameterDeclarationsContext *context);
  Object visitAssignmentStatement(PascalParser::AssignmentStatementContext *context);
  Object visitLhs(PascalParser::LhsContext *context);
  Object visitIfStatement(PascalParser::IfStatementContext *context);
  Object visitCaseStatement(PascalParser::CaseStatementContext *context);
  Object visitRepeatStatement(PascalParser::RepeatStatementContext *context);
  Object visitWhileStatement(PascalParser::WhileStatementContext *context);
  Object visitForStatement(PascalParser::ForStatementContext *context);
  Object visitProcedureCallStatement(PascalParser::ProcedureCallStatementContext *context);
  Object visitFunctionCallFactor(PascalParser::FunctionCallFactorContext *context);
  Object visitExpression(PascalParser::ExpressionContext *context);
  Object visitSimpleExpression(PascalParser::SimpleExpressionContext *context);
  Object visitTerm(PascalParser::TermContext *context);
  Object visitVariableFactor(PascalParser::VariableFactorContext *context);
  Object visitVariable(PascalParser::VariableContext *context);
  Object visitVariableIdentifier(PascalParser::VariableIdentifierContext *context);
  Object visitNumberFactor(PascalParser::NumberFactorContext *context);
  Object visitCharacterFactor(PascalParser::CharacterFactorContext *context);
  Object visitStringFactor(PascalParser::StringFactorContext *context);
  Object visitNotFactor(PascalParser::NotFactorContext *context);
  Object visitParenthesizedFactor(PascalParser::ParenthesizedFactorContext *context);
  Object visitSubrangeTypespec(PascalParser::SubrangeTypespecContext *context);

private:
  SymtabStack *symtabStack;
  SymtabEntry *programId;
  ErrorHandler error;

  //Determine whether or not an expression is a variable only.
  bool expressionIsVariable(PascalParser::ExpressionContext *exprcontext);

  //Perform semantic operations on procedure and function call arguments.
  void checkCallArguments(PascalParser::ArgumentListContext *listcontext,
                          vector<SymtabEntry *> *parms);

  //Determine the datatype of a variable that can have modifiers.
  Typespec *variableDatatype(PascalParser::VariableContext *varcontext,
                             Typespec *varType);
};