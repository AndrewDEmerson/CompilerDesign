#include <fstream>
#include <iostream>
#include <ostream>

#include "ExprLexer.h"
#include "ExprParser.h"
#include "antlr4-runtime.h"

using namespace antlrcpp;
using namespace antlr4;

static const bool print_tokens = false;
static const bool print_tree = true;

std::string printTree(tree::ParseTree *t, Parser *recog);

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
  ANTLRInputStream input(argc == 2 ? source : std::cin);

  // create output stream
  std::ofstream output;
  output.open("output.txt");
  if (!output.is_open()) {
    std::cerr << "Could not open output.txt" << std::endl;
    return -1;
  }

  // Create a lexer which scans the input stream
  // to create a token stream.
  ExprLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();
  if (print_tokens) {
    for (Token *token : tokens.getTokens()) {
      std::cout << lexer.getVocabulary().getDisplayName(token->getType())
                << " : " << token->getText() << std::endl;
      output << lexer.getVocabulary().getDisplayName(token->getType()) << " : "
             << token->getText() << std::endl;
    }
  }

  // Create a parser which parses the token stream
  // to create a parse tree.
  ExprParser parser(&tokens);
  tree::ParseTree *tree = parser.program();
  // Print the parse tree.
  if (print_tree) {
    std::string treeString = printTree(tree, &parser);
    std::cout << treeString << std::endl;
    output << treeString << std::endl;
  }
  output.close();
  return 0;
}

// Based on tree->toStringTree(&parser)
std::string printTree(tree::ParseTree *t, Parser *recog) {
  const std::vector<std::string> &ruleNames = recog->getRuleNames();
  std::vector<std::string> table;
  std::string temp =
      antlrcpp::escapeWhitespace(tree::Trees::getNodeText(t, ruleNames), false);
  if (t->children.empty()) {
    return temp;
  }

  std::stringstream ss;
  ss << temp;

  // Implement the recursive walk as iteration to avoid trouble with deep
  // nesting.
  std::stack<size_t> stack;
  size_t childIndex = 0;
  tree::ParseTree *run = t;
  while (childIndex < run->children.size()) {
    tree::ParseTree *child = run->children[childIndex];
    temp = antlrcpp::escapeWhitespace(
        tree::Trees::getNodeText(child, ruleNames), false);
    if (!child->children.empty()) {
      // Go deeper one level.
      stack.push(childIndex);
      run = child;
      childIndex = 0;
      ss << '\n';
      for (int i = 0; i < stack.size(); i++)
        ss << "  ";
      ss << "<" << temp;
      // Prints var/identifier name if terminal node
      if (temp == "unsignedInteger" | temp == "simpleStatement" |
          temp == "identifier") {
        ss << " : "
           << antlrcpp::escapeWhitespace(
                  tree::Trees::getNodeText(run->children[0], ruleNames), false)
           << "/>";
        if (temp == "identifier") {
          std::string varname = antlrcpp::escapeWhitespace(
              tree::Trees::getNodeText(run->children[0], ruleNames), false);
          bool alreadyintable = false;
          for (int i = 0; i < table.size(); i++) {
            if (table[i] == varname) {
              alreadyintable = true;
              break;
            }
          }
          if (!alreadyintable)
            table.push_back(varname);
        }
      } else
        ss << ">";
    } else {
      while (++childIndex == run->children.size()) {
        if (stack.size() > 0) {
          // Reached the end of the current level. See if we can step up from
          // here.
          childIndex = stack.top();
          stack.pop();
          run = run->parent;
          temp = antlrcpp::escapeWhitespace(
              tree::Trees::getNodeText(run, ruleNames), false);
          ss << "\n";
          for (int i = stack.size(); i > 0; i--) {
            ss << "  ";
          }
          ss << "<" << temp << "/>";
        } else {
          break;
        }
      }
    }
  }
  ss << "\n\nSymbol Table:\n";
  // Assume all vars are ints
  for (int i = 0; i < table.size(); i++) {
    ss << "\t" << table[i] << ":\tint\n";
  }
  return ss.str();
}
