#include <string>
#include <vector>
#include "antlr4-runtime.h"

// Based on tree->toStringTree(&parser)
std::string printTree(antlr4::tree::ParseTree *t, antlr4::Parser *recog) {
  const std::vector<std::string> &ruleNames = recog->getRuleNames();
  std::vector<std::string> table;
  std::string temp =
      antlrcpp::escapeWhitespace(antlr4::tree::Trees::getNodeText(t, ruleNames), false);
  if (t->children.empty()) {
    return temp;
  }

  std::stringstream ss;
  ss << temp;

  // Implement the recursive walk as iteration to avoid trouble with deep
  // nesting.
  std::stack<size_t> stack;
  size_t childIndex = 0;
  antlr4::tree::ParseTree *run = t;
  while (childIndex < run->children.size()) {
    antlr4::tree::ParseTree *child = run->children[childIndex];
    temp = antlrcpp::escapeWhitespace(
        antlr4::tree::Trees::getNodeText(child, ruleNames), false);
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
                  antlr4::tree::Trees::getNodeText(run->children[0], ruleNames), false)
           << "/>";
        if (temp == "identifier") {
          std::string varname = antlrcpp::escapeWhitespace(
              antlr4::tree::Trees::getNodeText(run->children[0], ruleNames), false);
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
              antlr4::tree::Trees::getNodeText(run, ruleNames), false);
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