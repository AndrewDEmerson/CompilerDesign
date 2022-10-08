#include <fstream>
#include <iostream>
#include <ostream>

#include "ExprLexer.h"
#include "ExprParser.h"
#include "antlr4-runtime.h"

using namespace antlrcpp;
using namespace antlr4;

int main(int argc, const char *args[]) {
  std::ifstream source;
  std::ofstream output;
  // Create the input stream.
  source.open(args[1]);
  output.open("output.txt");
  if (argc != 2) {
    std::cout << "Reading From CIN, use CTR-D to signal EOF" << std::endl;
  }
  ANTLRInputStream input(argc == 2 ? source : std::cin);

  // Create a lexer which scans the input stream
  // to create a token stream.
  ExprLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  // Print the token stream.
  std::cout << "Tokens:" << std::endl;

  tokens.fill();
  for (Token *token : tokens.getTokens()) {
    std::cout << lexer.getVocabulary().getDisplayName(token->getType())
              << " : " << token->getText() << std::endl;
    output << lexer.getVocabulary().getDisplayName(token->getType())
              << " : " << token->getText() << std::endl;
    // std::cout << token->toString() << std::endl;
  }
  return 0;
}
