
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from src/Pascal.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "PascalParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PascalParser.
 */
class  PascalVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PascalParser.
   */
    virtual antlrcpp::Any visitProgram(PascalParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitProgramHeader(PascalParser::ProgramHeaderContext *context) = 0;

    virtual antlrcpp::Any visitProgramParameters(PascalParser::ProgramParametersContext *context) = 0;

    virtual antlrcpp::Any visitProgramIdentifier(PascalParser::ProgramIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitBlock(PascalParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitDeclarations(PascalParser::DeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitConstantsPart(PascalParser::ConstantsPartContext *context) = 0;

    virtual antlrcpp::Any visitConstantDefinitionsList(PascalParser::ConstantDefinitionsListContext *context) = 0;

    virtual antlrcpp::Any visitConstantDefinition(PascalParser::ConstantDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitConstantIdentifier(PascalParser::ConstantIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitConstant(PascalParser::ConstantContext *context) = 0;

    virtual antlrcpp::Any visitSign(PascalParser::SignContext *context) = 0;

    virtual antlrcpp::Any visitTypesPart(PascalParser::TypesPartContext *context) = 0;

    virtual antlrcpp::Any visitTypeDefinitionsList(PascalParser::TypeDefinitionsListContext *context) = 0;

    virtual antlrcpp::Any visitTypeDefinition(PascalParser::TypeDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitTypeIdentifier(PascalParser::TypeIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitSimpleTypespec(PascalParser::SimpleTypespecContext *context) = 0;

    virtual antlrcpp::Any visitArrayTypespec(PascalParser::ArrayTypespecContext *context) = 0;

    virtual antlrcpp::Any visitRecordTypespec(PascalParser::RecordTypespecContext *context) = 0;

    virtual antlrcpp::Any visitTypeIdentifierTypespec(PascalParser::TypeIdentifierTypespecContext *context) = 0;

    virtual antlrcpp::Any visitEnumerationTypespec(PascalParser::EnumerationTypespecContext *context) = 0;

    virtual antlrcpp::Any visitSubrangeTypespec(PascalParser::SubrangeTypespecContext *context) = 0;

    virtual antlrcpp::Any visitEnumerationType(PascalParser::EnumerationTypeContext *context) = 0;

    virtual antlrcpp::Any visitEnumerationConstant(PascalParser::EnumerationConstantContext *context) = 0;

    virtual antlrcpp::Any visitSubrangeType(PascalParser::SubrangeTypeContext *context) = 0;

    virtual antlrcpp::Any visitArrayType(PascalParser::ArrayTypeContext *context) = 0;

    virtual antlrcpp::Any visitArrayDimensionList(PascalParser::ArrayDimensionListContext *context) = 0;

    virtual antlrcpp::Any visitRecordType(PascalParser::RecordTypeContext *context) = 0;

    virtual antlrcpp::Any visitRecordFields(PascalParser::RecordFieldsContext *context) = 0;

    virtual antlrcpp::Any visitVariablesPart(PascalParser::VariablesPartContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarationsList(PascalParser::VariableDeclarationsListContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarations(PascalParser::VariableDeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitVariableIdentifierList(PascalParser::VariableIdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitVariableIdentifier(PascalParser::VariableIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitRoutinesPart(PascalParser::RoutinesPartContext *context) = 0;

    virtual antlrcpp::Any visitRoutineDefinition(PascalParser::RoutineDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitProcedureHead(PascalParser::ProcedureHeadContext *context) = 0;

    virtual antlrcpp::Any visitFunctionHead(PascalParser::FunctionHeadContext *context) = 0;

    virtual antlrcpp::Any visitRoutineIdentifier(PascalParser::RoutineIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitParameters(PascalParser::ParametersContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclarationsList(PascalParser::ParameterDeclarationsListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclarations(PascalParser::ParameterDeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitParameterIdentifierList(PascalParser::ParameterIdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitParameterIdentifier(PascalParser::ParameterIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitStatement(PascalParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(PascalParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitEmptyStatement(PascalParser::EmptyStatementContext *context) = 0;

    virtual antlrcpp::Any visitStatementList(PascalParser::StatementListContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentStatement(PascalParser::AssignmentStatementContext *context) = 0;

    virtual antlrcpp::Any visitLhs(PascalParser::LhsContext *context) = 0;

    virtual antlrcpp::Any visitRhs(PascalParser::RhsContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(PascalParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitTrueStatement(PascalParser::TrueStatementContext *context) = 0;

    virtual antlrcpp::Any visitFalseStatement(PascalParser::FalseStatementContext *context) = 0;

    virtual antlrcpp::Any visitCaseStatement(PascalParser::CaseStatementContext *context) = 0;

    virtual antlrcpp::Any visitCaseBranchList(PascalParser::CaseBranchListContext *context) = 0;

    virtual antlrcpp::Any visitCaseBranch(PascalParser::CaseBranchContext *context) = 0;

    virtual antlrcpp::Any visitCaseConstantList(PascalParser::CaseConstantListContext *context) = 0;

    virtual antlrcpp::Any visitCaseConstant(PascalParser::CaseConstantContext *context) = 0;

    virtual antlrcpp::Any visitRepeatStatement(PascalParser::RepeatStatementContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(PascalParser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitForStatement(PascalParser::ForStatementContext *context) = 0;

    virtual antlrcpp::Any visitProcedureCallStatement(PascalParser::ProcedureCallStatementContext *context) = 0;

    virtual antlrcpp::Any visitProcedureName(PascalParser::ProcedureNameContext *context) = 0;

    virtual antlrcpp::Any visitArgumentList(PascalParser::ArgumentListContext *context) = 0;

    virtual antlrcpp::Any visitArgument(PascalParser::ArgumentContext *context) = 0;

    virtual antlrcpp::Any visitWriteStatement(PascalParser::WriteStatementContext *context) = 0;

    virtual antlrcpp::Any visitWritelnStatement(PascalParser::WritelnStatementContext *context) = 0;

    virtual antlrcpp::Any visitWriteArguments(PascalParser::WriteArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitWriteArgument(PascalParser::WriteArgumentContext *context) = 0;

    virtual antlrcpp::Any visitFieldWidth(PascalParser::FieldWidthContext *context) = 0;

    virtual antlrcpp::Any visitDecimalPlaces(PascalParser::DecimalPlacesContext *context) = 0;

    virtual antlrcpp::Any visitReadStatement(PascalParser::ReadStatementContext *context) = 0;

    virtual antlrcpp::Any visitReadlnStatement(PascalParser::ReadlnStatementContext *context) = 0;

    virtual antlrcpp::Any visitReadArguments(PascalParser::ReadArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitExpression(PascalParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSimpleExpression(PascalParser::SimpleExpressionContext *context) = 0;

    virtual antlrcpp::Any visitTerm(PascalParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitVariableFactor(PascalParser::VariableFactorContext *context) = 0;

    virtual antlrcpp::Any visitNumberFactor(PascalParser::NumberFactorContext *context) = 0;

    virtual antlrcpp::Any visitCharacterFactor(PascalParser::CharacterFactorContext *context) = 0;

    virtual antlrcpp::Any visitStringFactor(PascalParser::StringFactorContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCallFactor(PascalParser::FunctionCallFactorContext *context) = 0;

    virtual antlrcpp::Any visitNotFactor(PascalParser::NotFactorContext *context) = 0;

    virtual antlrcpp::Any visitParenthesizedFactor(PascalParser::ParenthesizedFactorContext *context) = 0;

    virtual antlrcpp::Any visitVariable(PascalParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitModifier(PascalParser::ModifierContext *context) = 0;

    virtual antlrcpp::Any visitIndexList(PascalParser::IndexListContext *context) = 0;

    virtual antlrcpp::Any visitIndex(PascalParser::IndexContext *context) = 0;

    virtual antlrcpp::Any visitField(PascalParser::FieldContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCall(PascalParser::FunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitFunctionName(PascalParser::FunctionNameContext *context) = 0;

    virtual antlrcpp::Any visitNumber(PascalParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedNumber(PascalParser::UnsignedNumberContext *context) = 0;

    virtual antlrcpp::Any visitIntegerConstant(PascalParser::IntegerConstantContext *context) = 0;

    virtual antlrcpp::Any visitRealConstant(PascalParser::RealConstantContext *context) = 0;

    virtual antlrcpp::Any visitCharacterConstant(PascalParser::CharacterConstantContext *context) = 0;

    virtual antlrcpp::Any visitStringConstant(PascalParser::StringConstantContext *context) = 0;

    virtual antlrcpp::Any visitRelOp(PascalParser::RelOpContext *context) = 0;

    virtual antlrcpp::Any visitAddOp(PascalParser::AddOpContext *context) = 0;

    virtual antlrcpp::Any visitMulOp(PascalParser::MulOpContext *context) = 0;


};

