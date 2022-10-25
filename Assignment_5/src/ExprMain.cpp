#include <fstream>
#include <iostream>
#include <ostream>

#include "ExprLexer.h"
#include "ExprParser.h"
#include "antlr4-runtime.h"

using namespace antlrcpp;
using namespace antlr4;

std::string printTree(tree::ParseTree *t, Parser *recog);

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

  tokens.fill();
  // for (Token *token : tokens.getTokens()) {
  //   std::cout << lexer.getVocabulary().getDisplayName(token->getType()) << " : "
  //             << token->getText() << std::endl;
  //   output << lexer.getVocabulary().getDisplayName(token->getType()) << " : "
  //          << token->getText() << std::endl;
  // }

  // Create a parser which parses the token stream
  // to create a parse tree.
  ExprParser parser(&tokens);
  tree::ParseTree *tree = parser.program();
  // Print the parse tree.
  std::cout << printTree(tree,&parser) << std::endl;
  //std::cout << tree->toStringTree(&parser) << std::endl;
  return 0;
}


//Based on toStringTree()
//TODO output as xml
std::string printTree(tree::ParseTree *t, Parser *recog) {
  const std::vector<std::string> &ruleNames = recog->getRuleNames();
  std::vector<std::string> table;
  std::string temp = antlrcpp::escapeWhitespace(tree::Trees::getNodeText(t, ruleNames), false);
  if (t->children.empty()) {
    return temp;
  }

  std::stringstream ss;
  ss <<  temp;

  // Implement the recursive walk as iteration to avoid trouble with deep nesting.
  std::stack<size_t> stack;
  size_t childIndex = 0;
  tree::ParseTree *run = t;
  while (childIndex < run->children.size()) {
    tree::ParseTree *child = run->children[childIndex];
    temp = antlrcpp::escapeWhitespace(tree::Trees::getNodeText(child, ruleNames), false);
    if (!child->children.empty()) {
      // Go deeper one level.
      stack.push(childIndex);
      run = child;
      childIndex = 0;
      ss << '\n';
      for (int i = 0; i < stack.size(); i++)
        ss << "  ";
      ss << "<" << temp;
      //Prints var/identifier name if terminal node
      if (temp == "unsignedInteger" | temp == "simpleStatement" | temp == "identifier") {
        ss <<  " : " << antlrcpp::escapeWhitespace(tree::Trees::getNodeText(run->children[0], ruleNames), false) << "/>";
      }
      else ss << ">";
    } 
    else {
      //Push variables and identifiers to the symbol table
      // if (/*child parent == identifier or var*/) {
      //   table.push_back(/*child.text*/);
      // }
      while (++childIndex == run->children.size()) {
        if (stack.size() > 0) {
          // Reached the end of the current level. See if we can step up from here.
          childIndex = stack.top();
          stack.pop();
          run = run->parent;
          temp = antlrcpp::escapeWhitespace(tree::Trees::getNodeText(run, ruleNames),false);
          ss << "\n"; 
          for (int i = stack.size(); i>0; i--) {
            ss << "  ";
          }
          ss << "<" << temp << "/>"; 
        } 
        else {
          break;
        }
      }
    }
  }
  ss << "\n\nSymbol Table:\n";
  for (int i = 0; i < table.size(); i++){
    ss << "| " << table[i] << "\n"; 
  }
  return ss.str();
}
