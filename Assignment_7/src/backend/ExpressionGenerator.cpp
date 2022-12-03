#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "CodeGenerator.h"
#include "ExpressionGenerator.h"
#include "Compiler.h"

namespace backend { namespace compiler {

void ExpressionGenerator::emitExpression(PascalParser::ExpressionContext *ctx)
{
    //emitRAW("\tLDA\t#0");
    PascalParser::SimpleExpressionContext *simpleCtx1 =
                                            ctx->simpleExpression()[0];
    PascalParser::RelOpContext *relOpCtx = ctx->relOp();
    Typespec *type1 = simpleCtx1->type;
    // emitRAW("B");
    emitSimpleExpression(simpleCtx1);
    // emitRAW("B");
    
    // More than one simple expression?
    if (relOpCtx != nullptr)
    {
        string op = relOpCtx->getText();
        PascalParser::SimpleExpressionContext *simpleCtx2 =
                                            ctx->simpleExpression()[1];
        Typespec *type2 = simpleCtx2->type;

        bool integerMode   = false;
        bool realMode      = false;
        bool characterMode = false;

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
        else if (   (type1 == Predefined::charType)
                 && (type2 == Predefined::charType))
        {
            characterMode = true;
        }

        Label *trueLabel = new Label();
        Label *exitLabel = new Label();

        if (integerMode || characterMode)
        {
            // emitSimpleExpression(simpleCtx2);
            // Should probably make a function for these...
            // emitRAW(op);

            if      (!op.compare("=")) {
                emitRAW("\tCOMP\t#" + simpleCtx2->getText());
                emitRAW("\n\tLDA\t#1\n");
                emitRAW("\tJEQ\tEQ" + simpleCtx1->getText() + simpleCtx2->getText());
                emitRAW("\n\tLDA\t#0\n");
                emitRAW("EQ" + simpleCtx1->getText() + simpleCtx2->getText());
            }
            else if (!op.compare("<>")) {
                emitRAW("\tCOMP\t" + simpleCtx2->getText());
                emitRAW("\n");
            }
            else if (!op.compare("<")) {
                emitRAW("\tCOMP\t#" + simpleCtx2->getText());
                emitRAW("\n\tLDA\t#1\n");
                emitRAW("\tJLT\tLT" + simpleCtx1->getText() + simpleCtx2->getText());
                emitRAW("\n\tLDA\t#0\n");
                emitRAW("LT" + simpleCtx1->getText() + simpleCtx2->getText());
            }
            else if (!op.compare("<=")) {
                emitRAW("\tCOMP\t#" + simpleCtx2->getText());
                emitRAW("\n\tLDA\t#1\n");
                emitRAW("\tJLT\tLT" + simpleCtx1->getText() + simpleCtx2->getText());
                emitRAW("\n\tJEQ\tLT" + simpleCtx1->getText() + simpleCtx2->getText());
                emitRAW("\n\tLDA\t#0\n");
                emitRAW("LT" + simpleCtx1->getText() + simpleCtx2->getText());
            }
            else if (!op.compare(">")) {
                emitRAW("\tCOMP\t#" + simpleCtx2->getText());
                emitRAW("\n\tLDA\t#1\n");
                emitRAW("\tJGT\tGT" + simpleCtx1->getText() + simpleCtx2->getText());
                emitRAW("\n\tLDA\t#0\n");
                emitRAW("GT" + simpleCtx1->getText() + simpleCtx2->getText());
            }
            else if (!op.compare(">=")) {
                emitRAW("\tCOMP\t#" + simpleCtx2->getText());
                emitRAW("\n\tLDA\t#1\n");
                emitRAW("\tJGT\tGT" + simpleCtx1->getText() + simpleCtx2->getText());
                emitRAW("\n\tJEQ\tGT" + simpleCtx1->getText() + simpleCtx2->getText());
                emitRAW("\n\tLDA\t#0\n");
                emitRAW("GT" + simpleCtx1->getText() + simpleCtx2->getText());
            }
        }
        else if (realMode)
        {
            if (type1 == Predefined::integerType) emit(I2F);
            emitSimpleExpression(simpleCtx2);
            if (type2 == Predefined::integerType) emit(I2F);
            emitRAW("B");
            emit(FCMPG);

            if      (op == "=" ) emit(IFEQ, trueLabel);
            else if (op == "<>") emit(IFNE, trueLabel);
            else if (op == "<" ) emit(IFLT, trueLabel);
            else if (op == "<=") emit(IFLE, trueLabel);
            else if (op == ">" ) emit(IFGT, trueLabel);
            else if (op == ">=") emit(IFGE, trueLabel);
        }
        else  // stringMode
        {
            emitSimpleExpression(simpleCtx2);
            emitRAW("C");

            emit(INVOKEVIRTUAL,
                 "java/lang/String.compareTo(Ljava/lang/String;)I");
            localStack->decrease(1);

            if      (op == "=" ) emit(IFEQ, trueLabel);
            else if (op == "<>") emit(IFNE, trueLabel);
            else if (op == "<" ) emit(IFLT, trueLabel);
            else if (op == "<=") emit(IFLE, trueLabel);
            else if (op == ">" ) emit(IFGT, trueLabel);
            else if (op == ">=") emit(IFGE, trueLabel);
        }

        // emit(ICONST_0); // false
        // emit(GOTO, exitLabel);
        // emitLabel(trueLabel);
        // emit(ICONST_1); // true
        // emitLabel(exitLabel);

        // localStack->decrease(1);  // only one branch will be taken
    }
}

void ExpressionGenerator::emitSimpleExpression(PascalParser::SimpleExpressionContext *ctx)
{
    int count = ctx->term().size();
    bool negate =    (ctx->sign() != nullptr)
                  && (ctx->sign()->getText() == "-");

    // First term.
    PascalParser::TermContext *termCtx1 = ctx->term()[0];
    Typespec *type1 = termCtx1->type;
    // emitRAW("\tCLEAR\tA\n");
    emitTerm(termCtx1);
    // emitRAW("\tLDA\t" + termCtx1->getText() + "\n");             //Perform addition with register A

    if (negate) emit(type1 == Predefined::integerType ? INEG : FNEG);
    // emitRAW("\tLDA\t0\n");                           //Perform addition with register A

    // Loop over the subsequent terms.
    for (int i = 1; i < count; i++)
    {
        // if (i==1){

        // }
        // emitRAW("E");
        string op = toLowerCase(ctx->addOp()[i-1]->getText());

        // Replaced with above for <simple> <adding> <term>
        PascalParser::TermContext *termCtx2 = ctx->term()[i];
        Typespec *type2 = termCtx2->type;

        // Replaced with above for <term> <adding> <simple>
        // PascalParser::SimpleExpressionContext *simpleCtx2 =
        //                                     ctx->simpleExpression()[i];
        // Typespec *type2 = simpleCtx2->type;

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
        }

        if (integerMode)
        {
            // emitTerm(termCtx2);


            // doesnt differentiate ADD #5 vs ADD #a, when outputting #5, then emitRAW("#")!
            if (op == "+"){
                //needs to pass simple expression not gettext
                emitRAW("\tADD\t#" +  termCtx2->getText() + "\n"); //Add register A and variable 2
                // emitSimpleExpression(simpleCtx2);
            }
            else if(op == "-")           
                emitRAW("\tSUB\t#" + termCtx2->getText() + "\n");//emit(ISUB);
            // emitRAW("Adding");

//            localStack->decrease(1);
        }
        else if (realMode)
        {
            std::cerr << "realMode not implemented" << std::endl;
            exit(-1);
            if (type1 == Predefined::integerType) emit(I2F);
            // emitTerm(termCtx2);
            if (type2 == Predefined::integerType) emit(I2F);

            if (op == "+") emit(FADD);
            else           emit(FSUB);
        }
        else if (booleanMode)
        {

            // emitTerm(termCtx2);
            emit(IOR);
        }
        else  // stringMode
        {
            std::cerr << "stringMode not implemented" << std::endl;
            exit(-3);
            emit(NEW, "java/lang/StringBuilder");
            emit(DUP_X1);
            emit(SWAP);
            emit(INVOKESTATIC,
                 string("java/lang/String/valueOf(Ljava/lang/Object;)") +
                 string("Ljava/lang/String;"));
            emit(INVOKESPECIAL,
                 string("java/lang/StringBuilder/<init>") +
                 string("(Ljava/lang/String;)V"));
            localStack->decrease(1);

            // emitTerm(termCtx2);
            emit(INVOKEVIRTUAL,
                 string("java/lang/StringBuilder/append(Ljava/lang/String;)") +
                 string("Ljava/lang/StringBuilder;"));
            localStack->decrease(1);
            emit(INVOKEVIRTUAL,
                 string("java/lang/StringBuilder/toString()") +
                 string("Ljava/lang/String;"));
            localStack->decrease(1);
        }
    }
    // emitRAW("D");
}

void ExpressionGenerator::emitTerm(PascalParser::TermContext *ctx)
{
    int count = ctx->factor().size();

    // First factor.
    PascalParser::FactorContext *factorCtx1 = ctx->factor()[0];
    Typespec *type1 = factorCtx1->type;
    // emitRAW("Emitted0");

    // emits variable, unsigned constant, or <expression>
    compiler->visit(factorCtx1);
    // return;

    // Loop over the subsequent factors.
    for (int i = 1; i < count; i++)
    {
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
            if      (op == "*")   emitRAW("\tMUL\t" + factorCtx2->getText() + "\n");//emit(IMUL);
            else if (op == "/")   emitRAW("\tDIV\t" + factorCtx2->getText() + "\n");//emit(FDIV);
            else if (op == "div") emitRAW("\tDIV\t" + factorCtx2->getText() + "\n");//emit(IDIV);
            else if (op == "mod"){
                emitRAW("\tDIV\t" + emitLoadLocal() +
                        "\n\tMUL\t" + factorCtx2->getText() +
                        "\n\tLDX\t" + factorCtx1->getText() +
                        "\n\tSUBR\tA,X" +
                        "\n\tCLEAR\tA"  +
                        "\n\tADDR\tX,A\n");
            } 

            // compiler->visit(factorCtx2);
        }
        else if (realMode)
        {
            if (type1 == Predefined::integerType) emit(I2F);
            compiler->visit(factorCtx2);
            if (type2 == Predefined::integerType) emit(I2F);

            if      (op == "*") emit(FMUL);
            else if (op == "/") emit(FDIV);
        }
        else  // booleanMode
        {
            compiler->visit(factorCtx2);
            emit(IAND);
        }
    }
}

void ExpressionGenerator::emitNotFactor(PascalParser::NotFactorContext *ctx)
{
    std::cerr << "emitNotFactor not implemented" << std::endl;
    exit(-5);
    compiler->visit(ctx->factor());
    emit(ICONST_1);
    emit(IXOR);
}

void ExpressionGenerator::emitLoadValue(PascalParser::VariableContext *varCtx)
{
    // Load the scalar value or structure address.
    Typespec *variableType = emitLoadVariable(varCtx);
    // emitRAW("C");
    // Load an array element's or record field's value.
    int modifierCount = varCtx->modifier().size();
    if (modifierCount > 0)
    {
        PascalParser::ModifierContext *lastModCtx =
                                        varCtx->modifier()[modifierCount - 1];

        if (lastModCtx->indexList() != nullptr)
        {
            emitLoadArrayElementValue(variableType);
        }
        else
        {
            emitLoadRecordFieldValue(lastModCtx->field(), variableType);
        }
    }
    // emitRAW("C");
}

Typespec *ExpressionGenerator::emitLoadVariable(
                                        PascalParser::VariableContext *varCtx)
{
    SymtabEntry *variableId = varCtx->entry;
    Typespec *variableType = variableId->getType();
    int modifierCount = varCtx->modifier().size();
    // emitRAW("A");
    // Scalar value or structure address.
    CodeGenerator::emitLoadValue(variableId);  // why need CodeGenerator::? to outstream actual SIC/XE code
    // emitRAW("A");
    // Loop over subscript and field modifiers.
    for (int i = 0; i < modifierCount; ++i)
    {
        PascalParser::ModifierContext *modCtx = varCtx->modifier()[i];
        bool lastModifier = i == modifierCount - 1;

        // Subscript
        if (modCtx->indexList() != nullptr)
        {
            variableType = emitLoadArrayElementAccess(
                            modCtx->indexList(), variableType, lastModifier);
        }

        // Field
        else if (!lastModifier)
        {
            variableType = emitLoadRecordField(modCtx->field(), variableType);
        }
    }
    // emitRAW("A");
    return variableType;
}

Typespec *ExpressionGenerator::emitLoadArrayElementAccess(
                                PascalParser::IndexListContext *indexListCtx,
                                Typespec *elmtType, bool lastModifier)
{
    int indexCount = indexListCtx->index().size();

    // Loop over the subscripts.
    for (int i = 0; i < indexCount; i++)
    {
        PascalParser::IndexContext *indexCtx = indexListCtx->index()[i];
        emitExpression(indexCtx->expression());

        Typespec *indexType = elmtType->getArrayIndexType();

        if (indexType->getForm() == SUBRANGE)
        {
            int min = indexType->getSubrangeMinValue();
            if (min != 0)
            {
                emitLoadConstant(min);
                emit(ISUB);
            }
        }

        if (!lastModifier || (i < indexCount - 1)) emit(AALOAD);
        elmtType = elmtType->getArrayElementType();
    }

    return elmtType;
}

void ExpressionGenerator::emitLoadArrayElementValue(Typespec *elmtType)
{
    Form form = SCALAR;

    if (elmtType != nullptr)
    {
        elmtType = elmtType->baseType();
        form = elmtType->getForm();
    }

    // Load a character from a string.
    if (elmtType == Predefined::charType)
    {
        emit(INVOKEVIRTUAL, "java/lang/StringBuilder.charAt(I)C");
    }

    // Load an array element.
    else
    {
        emit(  elmtType == Predefined::integerType ? IALOAD
             : elmtType == Predefined::realType    ? FALOAD
             : elmtType == Predefined::booleanType ? BALOAD
             : elmtType == Predefined::charType    ? CALOAD
             : form == ENUMERATION                 ? IALOAD
             :                                       AALOAD);
    }
}

void ExpressionGenerator::emitLoadRecordFieldValue(
                    PascalParser::FieldContext *fieldCtx, Typespec *recordType)
{
    emitLoadRecordField(fieldCtx, recordType);
}

Typespec *ExpressionGenerator::emitLoadRecordField(
                    PascalParser::FieldContext *fieldCtx, Typespec *recordType)
{
    SymtabEntry *fieldId = fieldCtx->entry;
    string fieldName = fieldId->getName();
    Typespec *fieldType = fieldCtx->type;

    string recordTypePath = recordType->getRecordTypePath();
    string fieldPath = recordTypePath + "/" + fieldName;
    emit(GETFIELD, fieldPath, typeDescriptor(fieldType));

    return fieldType;
}

void ExpressionGenerator::emitLoadIntegerConstant(PascalParser::NumberContext *intCtx)
{
    std::clog << "emiting loadIntegerConstant" << std::endl;
    int value = stoi(intCtx->getText());
    emitLoadConstant(value);
}

void ExpressionGenerator::emitLoadRealConstant(PascalParser::NumberContext *realCtx)
{
    float value = stof(realCtx->getText());
    emitLoadConstant(value);
}

}} // namespace backend::compiler
