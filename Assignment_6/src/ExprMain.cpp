#include <fstream>
#include <iostream>
#include <ostream>

#include "PascalLexer.h"
#include "PascalParser.h"
#include "antlr4-runtime.h"

#include "tableBuilder.h"
#include "treePrint.h"

// Given by Instructor
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"

static const bool print_tokens = false;
static const bool print_tree = false;
static const bool print_tables = true;

int main(int argc, const char *argv[]) {
  // Create the input stream.
  std::ifstream source;
  if (argc == 2) {
    source.open(argv[1]);
    if (!source.is_open()) {
      std::cerr << "Could not open file" << std::endl;
      return -1;
    }
  } else {
    std::cout << "Reading From CIN, use CTR-D to signal EOF" << std::endl;
  }
  antlr4::ANTLRInputStream input(argc == 2 ? source : std::cin);

  // create output stream
  std::ofstream output;
  output.open("output.txt");
  if (!output.is_open()) {
    std::cerr << "Could not open output.txt" << std::endl;
    return -1;
  }

  // Create a lexer which scans the input stream
  // to create a token stream.
  PascalLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);

  tokens.fill();
  if (print_tokens) {
    for (antlr4::Token *token : tokens.getTokens()) {
      std::cout << lexer.getVocabulary().getDisplayName(token->getType())
                << " : " << token->getText() << std::endl;
      output << lexer.getVocabulary().getDisplayName(token->getType()) << " : "
             << token->getText() << std::endl;
    }
  }

  // Create a parser which parses the token stream
  // to create a parse tree.
  PascalParser parser(&tokens);
  antlr4::tree::ParseTree *tree = parser.program();
  // Print the parse tree.
  if (print_tree) {
    std::string treeString = printTree(tree, &parser);
    std::cout << treeString << std::endl;
    output << treeString << std::endl;
  }

  tableBuilder *pass = new tableBuilder();
  pass->visit(tree);
  if (print_tables) {
    pass->printSymTableStack();
  }

  output.close();
  return 0;
}
