#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>

#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "CodeGenerator.h"
#include "Directive.h"
#include "Label.h"
#include "LocalVariables.h"
#include "LocalStack.h"

namespace backend { namespace compiler {

using namespace std;
using namespace std::chrono;
using namespace intermediate;

int Label::index = 0;
int CodeGenerator::count = 0;

void CodeGenerator::open(string programName, string suffix)
{
    objectFileName = programName + "." + suffix;
    objectFile = new ofstream(objectFileName);

    if (!objectFile->is_open())
    {
        cout << "ERROR: Failed to open object file \""
             << objectFileName << "\"." << endl;
        exit(-1);
    }
}

// =====================
// General code emitters
// =====================

/**
 * Emit a blank line.
 */
void CodeGenerator::emitLine()
{
    *objectFile << endl;;
    objectFile->flush();
}

void CodeGenerator::emitRAW(string text){
    *objectFile << text;
    objectFile->flush();
}

/**
 * Emit a comment.
 * @param text the comment text.
 */
void CodeGenerator::emitComment(string text)
{
    *objectFile << ". " << text << endl;
    objectFile->flush();
}

/**
 * Emit a statement comment.
 * @param ctx the StatementContext.
 */
void CodeGenerator::emitComment(PascalParser::StatementContext *ctx)
{
    string text = ctx->getText();
    if (text.length() > 70) text = text.substr(0, 70) + " ...";

    stringstream ss;
    ss << setw(3) << setfill('0') << ctx->getStart()->getLine() << " " << text;
    emitComment(ss.str());
}

void CodeGenerator::emitLabel(Label *label)
{
    *objectFile << label << '\n';
    objectFile->flush();
}

void CodeGenerator::emitLabel(int value, Label *label)
{
    *objectFile << "\t  " << value << ": " << label << endl;
    objectFile->flush();
}

void CodeGenerator::emitLabel(string value, Label *label)
{
    *objectFile << "\t  " << value << ": " << label << endl;
    objectFile->flush();
}

// =====
// Loads
// =====

/**
 * Emit a load of an integer constant value.
 * @param value the constant value.
 */
void CodeGenerator::emitLoadConstant(int value, bool loadToS)
{
    if (loadToS){
        emitRAW("\tLDS\t#"+to_string(value)+"\n");
    }else{
        emitRAW("\tLDA\t#"+to_string(value)+"\n");
    }
}

void CodeGenerator::emitLoadConstant(int value)
{
    emitRAW("\tLDA\t#"+to_string(value)+"\n"); 
}

/**
 * Emit a load of a real constant value.
 * @param value the constant value.
 */
void CodeGenerator::emitLoadConstant(double value)
{

}

void CodeGenerator::emitLoadConstant(string value)
{
    //emitRAW(LDC, "\"" + value + "\"");
}

void CodeGenerator::emitLoadValue(SymtabEntry *variableId)
{
    Typespec *type = variableId->getType()->baseType();
    Kind kind = variableId->getKind();
    int nestingLevel = variableId->getSymtab()->getNestingLevel();

    // Constant
    if (kind == CONSTANT)
    {
        Object value = variableId->getValue();

        if (type == Predefined::integerType)
        {
            emitComment("Emiiting a constant");
            emitLoadConstant(value.as<int>());
        }
        else if (type == Predefined::realType)
        {
            emitLoadConstant(value.as<float>());
        }
        else if (type == Predefined::charType)
        {
            int ch = value.as<char>();
            emitLoadConstant(ch);
        }
        else  // string
        {
            emitLoadConstant(value.as<string>());
        }
    }

    // Program variable.
    else if (nestingLevel == 1)
    {
        string variableName = variableId->getName();
        emitRAW("\tLDA\t"+variableName+"\n");
    }

    // Local variable.
    else
    {
        int slot = variableId->getSlotNumber();
        emitLoadLocal(type, slot);
    }
}

/**
 * Emit a load instruction for a local variable.
 * @param type the variable's data type.
 * @param index the variable's index into the local variables array.
 */
void CodeGenerator::emitLoadLocal(Typespec *type, int index)
{
    Form form = SCALAR;

    if (type != nullptr)
    {
        type = type->baseType();
        form = type->getForm();
    }

    if (   (type == Predefined::integerType)
        || (type == Predefined::booleanType)
        || (type == Predefined::charType)
        || (form == ENUMERATION))
    {
        emitRAW(
            "\tLDX\tstptr\n"
            "\tLDA\t"+to_string(9+3*index)+",X\n");
    }
    else{
        std::cerr << "returning of non-int types not currently supported" << std::endl;
        exit(-6);
    }
}

// ======
// Stores
// ======

void CodeGenerator::emitStoreValue(SymtabEntry *targetId, Typespec *targetType)
{
        emitStoreToUnmodifiedVariable(targetId, targetType);
}

void CodeGenerator::emitStoreToUnmodifiedVariable(SymtabEntry *targetId,
                                                  Typespec *targetType)
{
    int nestingLevel = targetId->getSymtab()->getNestingLevel();
    int slot = targetId->getSlotNumber();

    // Program variable.
    if (nestingLevel == 1)
    {
        string targetName = targetId->getName();
        string name = programName + "/" + targetName;

        char str[32];
        sprintf(str,"\tSTA\t%s\n",targetName.c_str());
        emitRAW(str);
    }

    // Local variable.
    else
    {
        emitStoreLocal(targetType->baseType(), slot);
    }
}

void CodeGenerator::emitStoreLocal(Typespec *type, int slot)
{
    emitComment("emiting storelocal");
    Form form = SCALAR;

    if (type != nullptr)
    {
        type = type->baseType();
        form = type->getForm();
    }

    if (   (type == Predefined::integerType)
        || (type == Predefined::booleanType)
        || (type == Predefined::charType)
        || (form == ENUMERATION))
    {
        emitRAW(
            "\tLDX\tstptr\n"
            "\tSTA\t"+to_string(9+3*slot)+",X\n");
    }
    else{
        std::cerr << "non-int not supported" << std::endl;
        exit(-7);
    }
}

// =========
// Utilities
// =========

}} // namespace backend::compiler
