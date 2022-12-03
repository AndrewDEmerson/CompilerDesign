#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "CodeGenerator.h"
#include "ExpressionGenerator.h"
#include "Compiler.h"

namespace backend { namespace compiler {

void ExpressionGenerator::emitExpression(PascalParser::ExpressionContext *ctx) {
    PascalParser::SimpleExpressionContext *simpleCtx1 = ctx->simpleExpression()[0];
    PascalParser::RelOpContext *relOpCtx = ctx->relOp();
    Typespec *type1 = simpleCtx1->type;
    emitSimpleExpression(simpleCtx1);

    // More than one simple expression
    if (relOpCtx != nullptr)
    {
        string op = relOpCtx->getText();
        PascalParser::SimpleExpressionContext *simpleCtx2 = ctx->simpleExpression()[1];
        Typespec *type2 = simpleCtx2->type;

        bool integerMode   = false;
        bool realMode      = false;
        bool characterMode = false;

        if (   (type1 == Predefined::integerType) && (type2 == Predefined::integerType)) integerMode = true;
        else if (   (type1 == Predefined::realType) || (type2 == Predefined::realType)) realMode = true; 
        else if (   (type1 == Predefined::charType)  && (type2 == Predefined::charType))characterMode = true;

        auto *neLabel = new Label();
        if (integerMode || characterMode) {
            emitSimpleExpression(simpleCtx2);            
            if      (op == "=" ) emitRAW("\tCOMP " + simpleCtx1->getText() + "\n\tJEQ ");
            else if (op == "<>") emitRAW("\tCOMP " + simpleCtx1->getText() + "\n\tJEQ ");
            else if (op == "<" ) emitRAW("\tCOMP " + simpleCtx1->getText() + "\n\tJGT ");
            else if (op == "<=") emitRAW("\tCOMP " + simpleCtx1->getText() + "\n\tJGT ");
            else if (op == ">" ) emitRAW("\tCOMP " + simpleCtx1->getText() + "\n\tJLT ");
            else if (op == ">=") emitRAW("\tCOMP " + simpleCtx1->getText() + "\n\tJLT ");
        }
        else if (realMode) {
            std::cerr << "realMode not implemented" << std::endl;
            exit(-1);
        }
        else  // stringMode
        {
            std::cerr << "stringMode not implemented" << std::endl;
            exit(-3);
        }
        localStack->decrease(1);  // only one branch will be taken
    }
}

void ExpressionGenerator::emitSimpleExpression(PascalParser::SimpleExpressionContext *ctx)
{
    
    int count = ctx->term().size();
    bool negate = (ctx->sign() != nullptr) && (ctx->sign()->getText() == "-");

    // First term.
    PascalParser::TermContext *termCtx1 = ctx->term()[0];
    Typespec *type1 = termCtx1->type;
    emitTerm(termCtx1);

    if(count > 1) emitRAW("\tSTA\ttempAreg\n");
    // Loop over the subsequent terms.
    for (int i = 1; i < count; i++) {
        string op = toLowerCase(ctx->addOp()[i-1]->getText());
        PascalParser::TermContext *termCtx2 = ctx->term()[i];
        Typespec *type2 = termCtx2->type;

        bool integerMode = false;
        bool realMode    = false;
        bool booleanMode = false;

        if (   (type1 == Predefined::integerType)
            && (type2 == Predefined::integerType))
        {
            integerMode = true;
        }
        else if (   (type1 == Predefined::realType)
                 || (type2 == Predefined::realType))
        {
            realMode = true;
        }
        else if (   (type1 == Predefined::booleanType)
                 && (type2 == Predefined::booleanType))
        {
            booleanMode = true;
        }else{
            std::cerr << "Unknown type" << std::endl;
        }

        if (integerMode)
        {
            if (i != 1) shouldLoadIntoS = true;
            emitTerm(termCtx2);
            shouldLoadIntoS = false;
        if (count > 1) emitRAW("\tRMO A,S\n\tLDS\ttempAreg\n");
            if (op == "+") emitRAW("\tADDR\tS,A\n");
            else           emitRAW("\tSUBR\tS,A\n");
        }
        else if (realMode) {
            std::cerr << "realMode not implemented" << std::endl;
            exit(-1);
        }
        else if (booleanMode) {
            std::cerr << "booleanMode not implemented" << std::endl;
            exit(-2);
        }
        else  // stringMode
        {
            std::cerr << "stringMode not implemented" << std::endl;
            exit(-3);
        }
    }

}

void ExpressionGenerator::emitTerm(PascalParser::TermContext *ctx)
{
    int count = ctx->factor().size();

    // First factor.
    PascalParser::FactorContext *factorCtx1 = ctx->factor()[0];
    Typespec *type1 = factorCtx1->type;
    compiler->visit(factorCtx1);
    if (count > 1) {
        //emitRAW("\tSTA\ttempAreg\n");
    }
    // Loop over the subsequent factors.
    for (int i = 1; i < count; i++) {
        string op = toLowerCase(ctx->mulOp()[i-1]->getText());
        PascalParser::FactorContext *factorCtx2 = ctx->factor()[i];
        Typespec *type2 = factorCtx2->type;

        bool integerMode = false;
        bool realMode    = false;

        if (   (type1 == Predefined::integerType)
            && (type2 == Predefined::integerType))
        {
            integerMode = true;
        }
        else if (   (type1 == Predefined::realType)
                 || (type2 == Predefined::realType))
        {
            realMode = true;
        }

        if (integerMode)
        {
            shouldLoadIntoS = true;
            compiler->visit(factorCtx2);
            shouldLoadIntoS = false;
            
            if      (op == "*")   emitRAW("\tMULR\tS,A\n");
            else if (op == "/")   emitRAW("\tDIVR\tS,A\n");
            else if (op == "div") emitRAW("\tDIVR\tS,A\n");
        }else{
            std::cerr << "nonint not supported" << std::endl;
        }

    }
    //if (count > 1) emitRAW("\tLDA\ttempAreg\n");
}

void ExpressionGenerator::emitNotFactor(PascalParser::NotFactorContext *ctx)
{
    std::cerr << "emitNotFactor not implemented" << std::endl;
}

void ExpressionGenerator::emitLoadValue(PascalParser::VariableContext *varCtx) {
    // Load the scalar value or structure address.
    Typespec *variableType = emitLoadVariable(varCtx);
}

Typespec *ExpressionGenerator::emitLoadVariable(PascalParser::VariableContext *varCtx) {
    SymtabEntry *variableId = varCtx->entry;
    Typespec *variableType = variableId->getType();
    int modifierCount = varCtx->modifier().size();

    // Scalar value or structure address.
    CodeGenerator::emitLoadValue(variableId);  // why need CodeGenerator::?

    return variableType;
}

void ExpressionGenerator::emitLoadIntegerConstant(PascalParser::NumberContext *intCtx) {
    int value = stoi(intCtx->getText());
    emitLoadConstant(value, shouldLoadIntoS);
}

void ExpressionGenerator::emitLoadRealConstant(PascalParser::NumberContext *realCtx) {
    float value = stof(realCtx->getText());
    emitLoadConstant(value);
}

}} // namespace backend::compiler
