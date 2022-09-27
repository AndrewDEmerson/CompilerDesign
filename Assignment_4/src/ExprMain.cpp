#include <iostream>
#include <fstream>

#include "antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"

using namespace antlrcpp;
using namespace antlr4;
using namespace std;

int main(int argc, const char *args[])
{
    ifstream source;

    // Create the input stream.
    source.open(args[1]);
    ANTLRInputStream input(source);

    // Create a lexer which scans the input stream
    // to create a token stream.
    ExprLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    // Print the token stream.
    cout << "Tokens:" << endl;
    tokens.fill();
    for (Token *token : tokens.getTokens())
    {
        std::cout << token->toString() << std::endl;
    }
    return 0;

    // Create a parser which parses the token stream
    // to create a parse tree.
    //ExprParser parser(&tokens);
    //tree::ParseTree *tree = parser.program();

    // Print the parse tree in Lisp format.
    //cout << endl << "Parse tree (Lisp format):" << endl;
    //std::cout << tree->toStringTree(&parser) << endl;

    //return 0;
}
