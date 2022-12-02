#include <vector>

#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "Directive.h"
#include "Instruction.h"
#include "Compiler.h"
#include "ProgramGenerator.h"
#include "StructuredDataGenerator.h"

namespace backend { namespace compiler {

using namespace std;

static const size_t STACKSIZE = 64;

void ProgramGenerator::emitProgram(PascalParser::ProgramContext *ctx)
{
    programId = ctx->programHeader()->programIdentifier()->entry;
    Symtab *programSymtab = programId->getRoutineSymtab();

    localVariables = new LocalVariables(programLocalsCount);

    emitRAW("prog\tSTART\t0\n\tEND\tfirst\n");
    emitRAW(
        ".stack variables\n"
        "stack\tRESW\t"+to_string(STACKSIZE)+"\n"
        "stptr\tRESW\t1\n"
        );

    emitProgramVariables();
    //emitInputScanner();
    emitSubroutines(ctx->block()->declarations()->routinesPart());
    emitMainMethod(ctx);
    close();
}

void ProgramGenerator::emitProgramVariables()
{
    // Runtime timer and standard in.

    Symtab *symtab = programId->getRoutineSymtab();
    vector<SymtabEntry *> ids = symtab->sortedEntries();


    //emitLine();
    emitComment("VARIABLE DECLARATIONS");

    // Loop over all the program's identifiers and
    // emit a .field directive for each variable.
    for (SymtabEntry *id : ids)
    {
        if (id->getKind() == VARIABLE)
        {
            //emitDirective(FIELD_PRIVATE_STATIC, id->getName(),typeDescriptor(id));
            if(typeDescriptor(id) == "S"){
                emitRAW(id->getName()+"\tRESW\t256\n");
            }else{
                emitRAW(id->getName()+"\tRESW\t1\n");
            }
        }
    }
}

void ProgramGenerator::emitInputScanner()
{
    emitLine();
    emitComment("Runtime input scanner");
    emitDirective(METHOD_STATIC, "<clinit>()V");
    emitLine();

    emit(NEW, "java/util/Scanner");
    emit(DUP);
    emit(GETSTATIC, "java/lang/System/in Ljava/io/InputStream;");
    emit(INVOKESPECIAL, "java/util/Scanner/<init>(Ljava/io/InputStream;)V");
    emit(PUTSTATIC, programName + "/_sysin Ljava/util/Scanner;");
    emit(RETURN);

    emitLine();
    emitDirective(LIMIT_LOCALS, 0);
    emitDirective(LIMIT_STACK,  3);
    emitDirective(END_METHOD);

    localStack->reset();
}

void ProgramGenerator::emitSubroutines(PascalParser::RoutinesPartContext *ctx)
{
    if (ctx != nullptr)
    {
        for (PascalParser::RoutineDefinitionContext *defnCtx :
                                                    ctx->routineDefinition())
        {
            compiler = new Compiler(compiler);
            compiler->visit(defnCtx);
        }
    }
}

void ProgramGenerator::emitMainMethod(PascalParser::ProgramContext *ctx)
{
    emitLine();
    emitComment("Main Method");
    emitMainPrologue(programId);

    // Emit code to allocate any arrays, records, and strings.
    //StructuredDataGenerator structureCode(this, compiler);
    //structureCode.emitData(programId);

    // Emit code for the compound statement.
    emitLine();
    compiler->visit(ctx->block()->compoundStatement());

    emitMainEpilogue();
}

void ProgramGenerator::emitMainPrologue(SymtabEntry *programId)
{
    localStack->increase(1);
    // Tell computer where first instruction is, and init stackpointer to point to stack
    emitRAW(
    "first\tLDA	#stack\n"
	"\tADD\t#"+to_string((STACKSIZE-1)*3)+"\n"
	"\tSTA\tstptr\n");
}

void ProgramGenerator::emitMainEpilogue()
{   
    emitComment("End Of Program, Halt");
    emitRAW("HALT\tJ\tHALT\n");
}

void ProgramGenerator::emitRoutine(PascalParser::RoutineDefinitionContext *ctx)
{
    SymtabEntry *routineId = ctx->procedureHead() != nullptr
                            ? ctx->procedureHead()->routineIdentifier()->entry
                            : ctx->functionHead()->routineIdentifier()->entry;
    Symtab *routineSymtab = routineId->getRoutineSymtab();

    emitRoutineHeader(routineId);
    emitRoutineLocals(routineId);

    // Generate code to allocate any arrays, records, and strings.
    //StructuredDataGenerator structuredCode(this, compiler);
    //structuredCode.emitData(routineId);

    localVariables = new LocalVariables(routineSymtab->getMaxSlotNumber());

    // Emit code for the compound statement.
    PascalParser::CompoundStatementContext *stmtCtx = (PascalParser::CompoundStatementContext *) routineId->getExecutable();
    compiler->visit(stmtCtx);

    emitRoutineReturn(routineId);
    //emitRoutineEpilogue();
}

void ProgramGenerator::emitRoutineHeader(SymtabEntry *routineId)
{
    string routineName = routineId->getName();
    vector<SymtabEntry *> *parmIds = routineId->getRoutineParameters();
    string header(routineName);

    // Parameter and return type descriptors.
    if (parmIds != nullptr)
    {
        for (SymtabEntry *parmId : *parmIds)
        {
            header += typeDescriptor(parmId);
        }
    }
    //header += typeDescriptor(routineId);

    emitLine();
    if (routineId->getKind() == PROCEDURE)
    {
        emitComment("PROCEDURE " + routineName);
    }
    else
    {
        emitComment("FUNCTION " + routineName);
    }

    //emitDirective(METHOD_PRIVATE_STATIC, header);
    emitRAW("routine"+header+ "\tRMO\tA,A\n");
}

void ProgramGenerator::emitRoutineLocals(SymtabEntry *routineId)
{   
    //TODO: NOT NEEDED?
    Symtab *symtab = routineId->getRoutineSymtab();
    vector<SymtabEntry *> ids = symtab->sortedEntries();

    emitLine();

    // Loop over all the routine's identifiers and
    // emit a .var directive for each variable and formal parameter.
    for (SymtabEntry *id : ids)
    {
        Kind kind = id->getKind();

        if ((kind == VARIABLE) || (kind == VALUE_PARAMETER)
                               || (kind == REFERENCE_PARAMETER))
        {
            int slot = id->getSlotNumber();
            //emitDirective(VAR, to_string(slot) + " is " + id->getName(),typeDescriptor(id));
            emitComment("store value in slot " + id->getName() + " "+ to_string(slot));
        }
    }
}

void ProgramGenerator::emitRoutineReturn(SymtabEntry *routineId)
{
    
    // Function: Return the value in the implied function variable.
    if (routineId->getKind() == FUNCTION)
    {
        Typespec *type = routineId->getType();

        // Get the slot number of the function variable.
        string varName = routineId->getName();
        SymtabEntry *varId = routineId->getRoutineSymtab()->lookup(varName);
        emitComment("Return a Value");
        emitLoadLocal(type, varId->getSlotNumber());
    }

    emitLine();
    // Procedure: Just return.
    emitRAW("\t.return\n"
	//"\tLDX\t#stack\n"
	"\tLDX\tstptr\n"
	"\tLDL\t0, X\n"
	"\tLDT\t6, X\n"
	"\tSTT\tstptr\n"
	"\tRSUB\n");
}

void ProgramGenerator::emitRoutineEpilogue()
{
    // emitLine();
    // emitDirective(LIMIT_LOCALS, localVariables->count());
    // emitDirective(LIMIT_STACK,  localStack->capacity());
    // emitDirective(END_METHOD);
}

}} // namespace backend::compiler
