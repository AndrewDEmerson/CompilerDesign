
// Generated from src/Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExprParser.
 */
class  ExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExprParser.
   */
    virtual antlrcpp::Any visitProgram(ExprParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitProgramHeading(ExprParser::ProgramHeadingContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(ExprParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitBlock(ExprParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitUsesUnitsPart(ExprParser::UsesUnitsPartContext *context) = 0;

    virtual antlrcpp::Any visitLabelDeclarationPart(ExprParser::LabelDeclarationPartContext *context) = 0;

    virtual antlrcpp::Any visitLabel(ExprParser::LabelContext *context) = 0;

    virtual antlrcpp::Any visitConstantDefinitionPart(ExprParser::ConstantDefinitionPartContext *context) = 0;

    virtual antlrcpp::Any visitConstantDefinition(ExprParser::ConstantDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitConstantChr(ExprParser::ConstantChrContext *context) = 0;

    virtual antlrcpp::Any visitConstant(ExprParser::ConstantContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedNumber(ExprParser::UnsignedNumberContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedInteger(ExprParser::UnsignedIntegerContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedReal(ExprParser::UnsignedRealContext *context) = 0;

    virtual antlrcpp::Any visitSign(ExprParser::SignContext *context) = 0;

    virtual antlrcpp::Any visitBool_(ExprParser::Bool_Context *context) = 0;

    virtual antlrcpp::Any visitString(ExprParser::StringContext *context) = 0;

    virtual antlrcpp::Any visitTypeDefinitionPart(ExprParser::TypeDefinitionPartContext *context) = 0;

    virtual antlrcpp::Any visitTypeDefinition(ExprParser::TypeDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionType(ExprParser::FunctionTypeContext *context) = 0;

    virtual antlrcpp::Any visitProcedureType(ExprParser::ProcedureTypeContext *context) = 0;

    virtual antlrcpp::Any visitType_(ExprParser::Type_Context *context) = 0;

    virtual antlrcpp::Any visitSimpleType(ExprParser::SimpleTypeContext *context) = 0;

    virtual antlrcpp::Any visitScalarType(ExprParser::ScalarTypeContext *context) = 0;

    virtual antlrcpp::Any visitSubrangeType(ExprParser::SubrangeTypeContext *context) = 0;

    virtual antlrcpp::Any visitTypeIdentifier(ExprParser::TypeIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitStructuredType(ExprParser::StructuredTypeContext *context) = 0;

    virtual antlrcpp::Any visitUnpackedStructuredType(ExprParser::UnpackedStructuredTypeContext *context) = 0;

    virtual antlrcpp::Any visitStringtype(ExprParser::StringtypeContext *context) = 0;

    virtual antlrcpp::Any visitArrayType(ExprParser::ArrayTypeContext *context) = 0;

    virtual antlrcpp::Any visitTypeList(ExprParser::TypeListContext *context) = 0;

    virtual antlrcpp::Any visitIndexType(ExprParser::IndexTypeContext *context) = 0;

    virtual antlrcpp::Any visitComponentType(ExprParser::ComponentTypeContext *context) = 0;

    virtual antlrcpp::Any visitRecordType(ExprParser::RecordTypeContext *context) = 0;

    virtual antlrcpp::Any visitFieldList(ExprParser::FieldListContext *context) = 0;

    virtual antlrcpp::Any visitFixedPart(ExprParser::FixedPartContext *context) = 0;

    virtual antlrcpp::Any visitRecordSection(ExprParser::RecordSectionContext *context) = 0;

    virtual antlrcpp::Any visitVariantPart(ExprParser::VariantPartContext *context) = 0;

    virtual antlrcpp::Any visitTag(ExprParser::TagContext *context) = 0;

    virtual antlrcpp::Any visitVariant(ExprParser::VariantContext *context) = 0;

    virtual antlrcpp::Any visitSetType(ExprParser::SetTypeContext *context) = 0;

    virtual antlrcpp::Any visitBaseType(ExprParser::BaseTypeContext *context) = 0;

    virtual antlrcpp::Any visitFileType(ExprParser::FileTypeContext *context) = 0;

    virtual antlrcpp::Any visitPointerType(ExprParser::PointerTypeContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarationPart(ExprParser::VariableDeclarationPartContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclaration(ExprParser::VariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitProcedureAndFunctionDeclarationPart(ExprParser::ProcedureAndFunctionDeclarationPartContext *context) = 0;

    virtual antlrcpp::Any visitProcedureOrFunctionDeclaration(ExprParser::ProcedureOrFunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitProcedureDeclaration(ExprParser::ProcedureDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFormalParameterList(ExprParser::FormalParameterListContext *context) = 0;

    virtual antlrcpp::Any visitFormalParameterSection(ExprParser::FormalParameterSectionContext *context) = 0;

    virtual antlrcpp::Any visitParameterGroup(ExprParser::ParameterGroupContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierList(ExprParser::IdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitConstList(ExprParser::ConstListContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclaration(ExprParser::FunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitResultType(ExprParser::ResultTypeContext *context) = 0;

    virtual antlrcpp::Any visitStatement(ExprParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitUnlabelledStatement(ExprParser::UnlabelledStatementContext *context) = 0;

    virtual antlrcpp::Any visitSimpleStatement(ExprParser::SimpleStatementContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentStatement(ExprParser::AssignmentStatementContext *context) = 0;

    virtual antlrcpp::Any visitVariable(ExprParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitExpression(ExprParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitRelationaloperator(ExprParser::RelationaloperatorContext *context) = 0;

    virtual antlrcpp::Any visitSimpleExpression(ExprParser::SimpleExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveoperator(ExprParser::AdditiveoperatorContext *context) = 0;

    virtual antlrcpp::Any visitTerm(ExprParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeoperator(ExprParser::MultiplicativeoperatorContext *context) = 0;

    virtual antlrcpp::Any visitSignedFactor(ExprParser::SignedFactorContext *context) = 0;

    virtual antlrcpp::Any visitFactor(ExprParser::FactorContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedConstant(ExprParser::UnsignedConstantContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDesignator(ExprParser::FunctionDesignatorContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(ExprParser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitSet_(ExprParser::Set_Context *context) = 0;

    virtual antlrcpp::Any visitElementList(ExprParser::ElementListContext *context) = 0;

    virtual antlrcpp::Any visitElement(ExprParser::ElementContext *context) = 0;

    virtual antlrcpp::Any visitProcedureStatement(ExprParser::ProcedureStatementContext *context) = 0;

    virtual antlrcpp::Any visitActualParameter(ExprParser::ActualParameterContext *context) = 0;

    virtual antlrcpp::Any visitParameterwidth(ExprParser::ParameterwidthContext *context) = 0;

    virtual antlrcpp::Any visitGotoStatement(ExprParser::GotoStatementContext *context) = 0;

    virtual antlrcpp::Any visitEmptyStatement_(ExprParser::EmptyStatement_Context *context) = 0;

    virtual antlrcpp::Any visitEmpty_(ExprParser::Empty_Context *context) = 0;

    virtual antlrcpp::Any visitStructuredStatement(ExprParser::StructuredStatementContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(ExprParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitStatements(ExprParser::StatementsContext *context) = 0;

    virtual antlrcpp::Any visitConditionalStatement(ExprParser::ConditionalStatementContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(ExprParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitCaseStatement(ExprParser::CaseStatementContext *context) = 0;

    virtual antlrcpp::Any visitCaseListElement(ExprParser::CaseListElementContext *context) = 0;

    virtual antlrcpp::Any visitRepetetiveStatement(ExprParser::RepetetiveStatementContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(ExprParser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitRepeatStatement(ExprParser::RepeatStatementContext *context) = 0;

    virtual antlrcpp::Any visitForStatement(ExprParser::ForStatementContext *context) = 0;

    virtual antlrcpp::Any visitForList(ExprParser::ForListContext *context) = 0;

    virtual antlrcpp::Any visitInitialValue(ExprParser::InitialValueContext *context) = 0;

    virtual antlrcpp::Any visitFinalValue(ExprParser::FinalValueContext *context) = 0;

    virtual antlrcpp::Any visitWithStatement(ExprParser::WithStatementContext *context) = 0;

    virtual antlrcpp::Any visitRecordVariableList(ExprParser::RecordVariableListContext *context) = 0;


};

