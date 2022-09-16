#pragma once

#include <string>
#include <vector>
namespace parser {

enum nodeTypes{
  if_statement,
  expression,
  statement,
  variable,
  factor,
  term,
  simpleExpression,
  unsignedConstant,
  unsignedInteger,
  unsignedReal,
  unsignedNumber,
  nil,
  string,
  multiplyingOperator,
  addingOperator,
  sign,
};

static std::string nodeNames[] = {
  "if_statement",
  "expression",
  "statement",
  "variable",
  "factor",
  "term",
  "simpleExpression",
  "unsignedConstant",
  "unsignedInteger",
  "unsignedReal",
  "unsignedNumber",
  "nil",
  "string",
  "multiplyingOperator",
  "addingOperator",
  "sign",
};

class node{
  public:
    node(nodeTypes);
    node(nodeTypes, std::string);
    node(nodeTypes, void*);
    nodeTypes type();
    void attachChild(node*);
    std::string id;
    void* value;
    void printTree(int level = 0);
  private:
    nodeTypes mytype;
    std::vector<node*> children;
};

}