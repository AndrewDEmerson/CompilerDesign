#pragma once

#include <fstream>

#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/type/Typespec.h"
#include "Directive.h"
#include "Label.h"
#include "LocalVariables.h"
#include "LocalStack.h"

namespace backend { namespace compiler {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class Compiler;

class CodeGenerator
{
private:
    string objectFileName;

protected:
    ofstream *objectFile;
    string programName;
    LocalVariables *localVariables;
    LocalStack *localStack;
    Compiler *compiler;

    static int count;

public:
    /**
     * Constructor.
     * @param programName the name of the program.
     * @param suffix the suffix for the object file name.
     * @param compiler the compiler to use.
     */
    CodeGenerator(string programName, string suffix, Compiler *compiler)
        : objectFile(nullptr), programName(programName),
          localVariables(nullptr), localStack(nullptr),
          compiler(nullptr)
	{
    	open(programName, suffix);
	}

    /**
     * Constructor for code generator subclasses.
     * @param parent the parent code generator.
     * @param compiler the compiler to use.
     */
    CodeGenerator(CodeGenerator *parent, Compiler *compiler)
        : objectFile(parent->objectFile), programName(parent->programName),
          localVariables(parent->localVariables),
          localStack(parent->localStack),
          compiler(compiler) {}

    string getObjectFileName() const { return objectFileName; }

    /**
     * Open the object file.
     * @param programName the name of the program.
     * @param suffix the suffix of the object file name.
     */
    void open(string programName, string suffix);

    /**
     * Close the object file.
     */
    void close() { objectFile->close(); }

    /**
     * Emit a blank line.
     */
    void emitLine();

    /**
     * Emit a comment.
     * @param text the comment text.
     */
    void emitComment(string text);

    /**
     * Emit a statement comment.
     * @param ctx the StatementContext.
     */
    void emitComment(PascalParser::StatementContext *ctx);

    void emitRAW(string text);
    /**
     * Emit a label.
     * @param label the label.
     */
    void emitLabel(Label *label);

    /**
     * Emit a label preceded by an integer value for a switch table.
     * @param label the label.
     */
    void emitLabel(int value, Label *label);

    /**
     * Emit a label preceded by a string value for a switch table.
     * @param label the label.
     */
    void emitLabel(string value, Label *label);

    /**
     * Emit a directive.
     * @param directive the directive code.
     */
    void emitDirective(Directive directive);

    /**
     * Emit a 1-operand directive.
     * @param directive the directive code.
     * @param operand the directive operand.
     */
    void emitDirective(Directive directive, string operand);

    /**
     * Emit a 1-operand directive.
     * @param directive the directive code.
     * @param operand the directive operand.
     */
    void emitDirective(Directive directive, int operand);

    /**
     * Emit a 2-operand directive.
     * @param directive the directive code.
     * @param operand the operand.
     */
    void emitDirective(Directive directive, string operand1, string operand2);

    /**
     * Emit a 3-operand directive.
     * @param directive the directive code.
     * @param operand the operand.
     */
    void emitDirective(Directive directive,
                       string operand1, string operand2, string operand3);

    // =====
    // Loads
    // =====

    /**
     * Emit a load of an integer constant value.
     * @param value the constant value.
     */
    void emitLoadConstant(int value);
    void emitLoadConstant(int value, bool loadToS);

    /**
     * Emit a load of a real constant value.
     * @param value the constant value.
     */
    void emitLoadConstant(double value);

    /**
     * Emit a load of a string constant value.
     * @param value the constant value.
     */
    void emitLoadConstant(string value);

    /**
     * Emit code to load the value of a variable, which can be
     * a program variable, a local variable, a constant, or a VAR parameter.
     * @param variableId the variable's symbol table entry.
     */
    void emitLoadValue(SymtabEntry *variableId);

    /**
     * Emit a load instruction for a local variable.
     * @param type the variable's data type.
     * @param index the variable's index into the local variables array.
     */
    void emitLoadLocal(Typespec *type, int index);

    // ======
    // Stores
    // ======

    /**
     * Emit a store of a value that is on top of the operand stack.
     * Store to an array element, a record field, or an ummodified variable.
     * @param targetId the symbol table entry of the target.
     * @param targetType the target's datatype.
     */
    void emitStoreValue(SymtabEntry *targetId, Typespec *targetType);

    /**
     * Emit a store instruction into a local variable.
     * @param type the data type of the variable.
     * @param slot the variable's slot number.
     */
    void emitStoreLocal(Typespec *type, int slot);

    /**
     * Emit a function return of a value.
     * @param type the type of the return value.
     */
    void emitReturnValue(Typespec *type);

private:
    /**
     * Emit code to store a value to an ummodified target variable,
     * which can be a program variable or a local variable.
     * @param targetId the symbol table entry of the variable.
     */
    void emitStoreToUnmodifiedVariable(SymtabEntry *targetId,
                                       Typespec *targetType);


    /**
     * Emit a store to an array element.
     * @param elmtType the element type.
     */
    void emitStoreToArrayElement(Typespec *elmtType);

    /**
     * Emit a store to a record field.
     * @param fieldId the symbol table entry of the field.
     */
    void emitStoreToRecordField(SymtabEntry *fieldId);
};

}} // namespace backend::compiler
