
// Generated from src/Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ExprVisitor.h"


/**
 * This class provides an empty implementation of ExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ExprBaseVisitor : public ExprVisitor {
public:

  virtual antlrcpp::Any visitProgram(ExprParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgramHeading(ExprParser::ProgramHeadingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(ExprParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(ExprParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUsesUnitsPart(ExprParser::UsesUnitsPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabelDeclarationPart(ExprParser::LabelDeclarationPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabel(ExprParser::LabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstantDefinitionPart(ExprParser::ConstantDefinitionPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstantDefinition(ExprParser::ConstantDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstantChr(ExprParser::ConstantChrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant(ExprParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsignedNumber(ExprParser::UnsignedNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsignedInteger(ExprParser::UnsignedIntegerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsignedReal(ExprParser::UnsignedRealContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSign(ExprParser::SignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBool_(ExprParser::Bool_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(ExprParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeDefinitionPart(ExprParser::TypeDefinitionPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeDefinition(ExprParser::TypeDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionType(ExprParser::FunctionTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureType(ExprParser::ProcedureTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_(ExprParser::Type_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleType(ExprParser::SimpleTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScalarType(ExprParser::ScalarTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubrangeType(ExprParser::SubrangeTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeIdentifier(ExprParser::TypeIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructuredType(ExprParser::StructuredTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnpackedStructuredType(ExprParser::UnpackedStructuredTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringtype(ExprParser::StringtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayType(ExprParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeList(ExprParser::TypeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexType(ExprParser::IndexTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComponentType(ExprParser::ComponentTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecordType(ExprParser::RecordTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFieldList(ExprParser::FieldListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFixedPart(ExprParser::FixedPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecordSection(ExprParser::RecordSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariantPart(ExprParser::VariantPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTag(ExprParser::TagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariant(ExprParser::VariantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetType(ExprParser::SetTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBaseType(ExprParser::BaseTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFileType(ExprParser::FileTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPointerType(ExprParser::PointerTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclarationPart(ExprParser::VariableDeclarationPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclaration(ExprParser::VariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureAndFunctionDeclarationPart(ExprParser::ProcedureAndFunctionDeclarationPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureOrFunctionDeclaration(ExprParser::ProcedureOrFunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureDeclaration(ExprParser::ProcedureDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormalParameterList(ExprParser::FormalParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormalParameterSection(ExprParser::FormalParameterSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterGroup(ExprParser::ParameterGroupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierList(ExprParser::IdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstList(ExprParser::ConstListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclaration(ExprParser::FunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResultType(ExprParser::ResultTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(ExprParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnlabelledStatement(ExprParser::UnlabelledStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleStatement(ExprParser::SimpleStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentStatement(ExprParser::AssignmentStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(ExprParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(ExprParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationaloperator(ExprParser::RelationaloperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleExpression(ExprParser::SimpleExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditiveoperator(ExprParser::AdditiveoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(ExprParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicativeoperator(ExprParser::MultiplicativeoperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignedFactor(ExprParser::SignedFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactor(ExprParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsignedConstant(ExprParser::UnsignedConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDesignator(ExprParser::FunctionDesignatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterList(ExprParser::ParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSet_(ExprParser::Set_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElementList(ExprParser::ElementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElement(ExprParser::ElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureStatement(ExprParser::ProcedureStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitActualParameter(ExprParser::ActualParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterwidth(ExprParser::ParameterwidthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGotoStatement(ExprParser::GotoStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyStatement_(ExprParser::EmptyStatement_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmpty_(ExprParser::Empty_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructuredStatement(ExprParser::StructuredStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompoundStatement(ExprParser::CompoundStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatements(ExprParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditionalStatement(ExprParser::ConditionalStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(ExprParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseStatement(ExprParser::CaseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseListElement(ExprParser::CaseListElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRepetetiveStatement(ExprParser::RepetetiveStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStatement(ExprParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRepeatStatement(ExprParser::RepeatStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStatement(ExprParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForList(ExprParser::ForListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitialValue(ExprParser::InitialValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFinalValue(ExprParser::FinalValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWithStatement(ExprParser::WithStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecordVariableList(ExprParser::RecordVariableListContext *ctx) override {
    return visitChildren(ctx);
  }


};

