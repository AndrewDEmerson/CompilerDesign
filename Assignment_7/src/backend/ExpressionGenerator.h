#pragma once

#include "CodeGenerator.h"

namespace backend { namespace compiler {

class ExpressionGenerator : public CodeGenerator
{
public:
    /**
     * Constructor.
     * @param parent the parent code generator.
     * @param compiler the compiler to use.
     */
    ExpressionGenerator(CodeGenerator *parent, Compiler *compiler)
        : CodeGenerator(parent, compiler) {}

    /**
     * Emit code for an expression.
     * @param ctx the ExpressionContext.
     */
    void emitExpression(PascalParser::ExpressionContext *ctx);

    /**
     * Emit code for a simple expression.
     * @param ctx the SimpleExpressionContext.
     */
    void emitSimpleExpression(PascalParser::SimpleExpressionContext *ctx);

    /**
     * Emit code for a term.
     * @param ctx the TermContext.
     */
    void emitTerm(PascalParser::TermContext *ctx);

    /**
     * Emit code for NOT.
     * @param ctx the NotFactorContext.
     */
    void emitNotFactor(PascalParser::NotFactorContext *ctx);

    /**
     * Emit code to load a scalar variable's value
     * or a structured variable's address.
     * @param ctx the VariableContext.
     */
    void emitLoadValue(PascalParser::VariableContext *varCtx);

    /**
     * Emit code to load a scalar variable's value
     * or a structured variable's address.
     * @param variableNode the variable node.
     */
    Typespec *emitLoadVariable(PascalParser::VariableContext *varCtx);

    /**
     * Emit code to load an integer constant.
     * @parm intCtx the IntegerConstantContext.
     */
    void emitLoadIntegerConstant(PascalParser::NumberContext *intCtx);

    /**
     * Emit code to load real constant.
     * @parm intCtx the IntegerConstantContext.
     */
    void emitLoadRealConstant(PascalParser::NumberContext *realCtx);

private:

    bool shouldLoadIntoS = false;

};

}} // namespace backend::compiler
