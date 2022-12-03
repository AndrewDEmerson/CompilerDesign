#include <string>
#include <vector>
#include <map>

#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"
#include "StatementGenerator.h"

namespace backend { namespace compiler {

using namespace std;
using namespace intermediate;

string StatementGenerator::typeToString(Typespec *type){
    static std::map<Typespec*,string> typeMap= {
            {Predefined::integerType,"I"},
            {Predefined::charType,"C"},
            {Predefined::booleanType,"Z"},
            {Predefined::realType,"F"},
            {Predefined::stringType,"S"},
            {Predefined::undefinedType,"V"}
    };
    return typeMap[type];
}

// Done
void StatementGenerator::emitAssignment(PascalParser::AssignmentStatementContext *ctx)
{
    PascalParser::VariableContext *varCtx  = ctx->lhs()->variable();
    PascalParser::ExpressionContext *exprCtx = ctx->rhs()->expression();
    SymtabEntry *varId = varCtx->entry;
    Typespec *varType  = varCtx->type;
    Typespec *exprType = exprCtx->type;

    // The last modifier, if any, is the variable's last subscript or field.
    int modifierCount = varCtx->modifier().size();
    PascalParser::ModifierContext *lastModCtx = modifierCount == 0
                            ? nullptr : varCtx->modifier()[modifierCount - 1];

    // The target variable has subscripts and/or fields.
    if (modifierCount > 0)
    {
        lastModCtx = varCtx->modifier()[modifierCount - 1];
        compiler->visit(varCtx);
    }

    // Emit code to evaluate the expression.
    compiler->visit(exprCtx);

    // Emit code to store the expression value into the target variable.
    // The target variable has no subscripts or fields.
    if (lastModCtx == nullptr) emitStoreValue(varId, varId->getType());
}

// Done? 
void StatementGenerator::emitIf(PascalParser::IfStatementContext *ctx)
{
    auto *truelab = new Label();
    auto *exitlab = new Label();
    auto *falselab = new Label();

    //Print the condition 
    compiler->visitExpression(ctx->expression());

    // If there is a false statement then print 
    // The label to jump to
    if (ctx->ELSE()) {
        emitRAW(falselab->getString() +'\n');
        compiler->visit(ctx->trueStatement());
        emitRAW("\tJ " + exitlab->getString() + '\n');  
    }
    else {
        emitRAW(exitlab->getString() + "\n");
        compiler->visit(ctx->trueStatement());
    }

    if (ctx->ELSE()) {
        emitLabel(falselab);
        compiler->visit(ctx->falseStatement());
    }

    emitRAW(exitlab->getString() + " RMO A, A\n");
}

// Done 
void StatementGenerator::emitCase(PascalParser::CaseStatementContext *ctx)
{
    std::vector<std::pair<PascalParser::CaseBranchContext *, Label *>> branchLabels;

    for (PascalParser::CaseBranchContext *branch: ctx->caseBranchList()->caseBranch()) branchLabels.emplace_back(branch, new Label);
    auto *exitCase = new Label;

    std::set<std::pair<int, Label *>> labelSet;
    for (auto &branchLabel: branchLabels) {
        if (!branchLabel.first->caseConstantList()) continue;
        for (PascalParser::CaseConstantContext *constantCtx: branchLabel.first->caseConstantList()->caseConstant()) {
            labelSet.insert(std::make_pair(constantCtx->value, branchLabel.second));
        }
    }
    int j = 0;
    compiler->visit(ctx->expression());
    for (auto entry: labelSet){
        int i = 0;
        for (auto &branchLabel: branchLabels) {
            if (i!=0) break;
            emitRAW("\tCOMP #"+to_string(entry.first)+ "\n");
            emitRAW("\tJEQ " + branchLabels[j].second->getString() + "\n");
            i++;
        }
        j++;
    }
    emitRAW("\tJ "+exitCase->getString()+"\n");

    int k = 0; 
    for (auto entry: branchLabels) {
        if (k==branchLabels.size()-1) break;
        emitLabel(entry.second);
        if (entry.first->statement() != nullptr) compiler->visit(entry.first->statement());
        emitRAW("\tJ "+exitCase->getString() + '\n');
        k++;
    }

    emitRAW(exitCase->getString() + " RMO A, A\n");
}

// Done
void StatementGenerator::emitRepeat(PascalParser::RepeatStatementContext *ctx)
{
    Label *loopTopLabel  = new Label();
    Label *loopExitLabel = new Label();

    emitLabel(loopTopLabel);

    compiler->visit(ctx->statementList());
    compiler->visit(ctx->expression());
    emitLabel(loopExitLabel);
    emitRAW("\tJ " + loopTopLabel->getString()+ '\n');
    emitRAW(loopExitLabel->getString() + "\tRMO A, A\n");
}

// Done 
void StatementGenerator::emitWhile(PascalParser::WhileStatementContext *ctx)
{
    auto *topLabel = new Label();
    auto *exitLabel = new Label();

    emitLabel(topLabel);
    compiler->visitExpression(ctx->expression());
    emitLabel(exitLabel);

    compiler->visit(ctx->statement());
    emitRAW("\tJ " + topLabel->getString() + "\n");
    emitRAW(exitLabel->getString() + " RMO A, A\n");
}

// Done
void StatementGenerator::emitFor(PascalParser::ForStatementContext *ctx)
{
    auto *topLabel = new Label();
    auto *exitLabel = new Label();
    auto *add = new Label();
    auto *sub = new Label(); 
    auto *stateLabel = new Label();

    compiler->visit(ctx->expression()[0]);
    emitStoreValue(ctx->variable()->entry, ctx->variable()->type);

    emitLabel(topLabel);

    compiler->visit(ctx->expression()[1]);
    emitRAW("\tCOMP " + ctx->variable()->getText() +"\n");
    emitRAW("\tJLT " + add->getString() + '\n');
    emitRAW("\tJGT " + sub->getString() + '\n');
    emitRAW("\tJ " + exitLabel->getString() + '\n');
    
    emitLabel(add);
    emitRAW("\tLDA b\n\tADD 1\n\tSTA b\n");
    emitRAW("\tJ " + stateLabel->getString() + "\n");

    emitLabel(sub);
    emitRAW("\tLDA b\n\tSUB 1\n\tSTA b\n");
    emitRAW("\tJ " + stateLabel->getString() + "\n");

    emitLabel(stateLabel);
    compiler->visit(ctx->statement());
    emitRAW("\tJ " + topLabel->getString() + "\n");

    emitRAW(exitLabel->getString() + " RMO A, A\n");
}
 
void StatementGenerator::emitProcedureCall(PascalParser::ProcedureCallStatementContext *ctx)
{
    emitCall(ctx->procedureName()->entry,ctx->argumentList());
}

void StatementGenerator::emitFunctionCall(PascalParser::FunctionCallContext *ctx)
{
    emitComment("emittingFunctionCall");
    emitCall(ctx->functionName()->entry,ctx->argumentList());
}

void StatementGenerator::emitCall(SymtabEntry *routineId,
                                  PascalParser::ArgumentListContext *argListCtx)
{
    string argType;

    if (argListCtx) {
        std::vector<Typespec *> expectedArgType;
        expectedArgType.reserve(argListCtx->argument().size());
        for (auto argSymTabEntry: *routineId->getRoutineParameters()) {
            expectedArgType.push_back(argSymTabEntry->getType());
            argType += typeToString(argSymTabEntry->getType());
        }
    }

    // Only static functions
    string functionName = "routine"+routineId->getName()+argType;   //programName + routineId->getName() + argType;
    string retpt = "returnpt" + to_string(static_cast<int>(rand()%9999));
    char str[256];
    emitRAW(
    "\tLDA\tstptr\n"
	"\tSUB\t#9\n"
	"\tSUB\t#"+to_string(routineId->getRoutineSymtab()->sortedEntries().size()*3)+"\t.space for local vars\n"
	"\tRMO\tA, X\n"
    "\tRMO\tA, B\n"
	"\tLDA\tstptr\n"
	//"\tSTX\tstptr\n"
	"\tSTA\t6, X\t.previous frame index\n"
	"\tLDL\t#"+retpt+"\n"
	"\tSTL\t0, X	.Return address\n"
	"\tLDA\t#1	.value Inserted by compiler\n"
	"\tSTA\t3, X	.scope\n");
    if (argListCtx) {
        emitComment("Add parameters to stack");
        for (unsigned int i = 0; i < argListCtx->argument().size(); i++) {
            auto argCtx = argListCtx->argument(i);
            compiler->visit(argCtx->expression());
            /*if (argCtx->expression()->type != expectedArgType[i])
                //emitCast(argCtx->expression()->type, expectedArgType[i]);
                std::cerr << "Cast not implemented" << std::endl;*/
            emitRAW(            
                //"\tLDX\tstptr\n"
                "\tRMO\tB, X\n"
                "\tSTA\t"+to_string(9+3*i)+",X\n");
        }
    }
	emitRAW(
    "\tSTB\tstptr\n"
    "\tJSUB\t"+functionName+"\n"
    ""+retpt+"\tRMO\tA, A\n");
}

void StatementGenerator::emitWrite(PascalParser::WriteStatementContext *ctx)
{
    emitWrite(ctx->writeArguments(), false);
}

void StatementGenerator::emitWriteln(PascalParser::WritelnStatementContext *ctx)
{
    std::cerr << "emitWriteLn not implemented" << std::endl;
    emitWrite(ctx->writeArguments(), true);
}

void StatementGenerator::emitWrite(PascalParser::WriteArgumentsContext *argsCtx,
                      bool needLF)
{
    std::cerr << "emitWrite not implemented" << std::endl;
}

int StatementGenerator::createWriteFormat(
                                PascalParser::WriteArgumentsContext *argsCtx,
                                string& format, bool needLF)
{

    return 0;
}

void StatementGenerator::emitRead(PascalParser::ReadStatementContext *ctx)
{
    emitRead(ctx->readArguments(), false);
}

void StatementGenerator::emitReadln(PascalParser::ReadlnStatementContext *ctx)
{
    emitRead(ctx->readArguments(), true);
}

void StatementGenerator::emitRead(PascalParser::ReadArgumentsContext *argsCtx,
                                  bool needSkip)
{
    
}

}} // namespace backend::compiler
