#pragma once

#include <string>
#include <vector>
#include <fstream>

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
  unsignedIntegerConstant,
  unsignedReal,
  unsignedNumber,
  nil,
  string,
  multiplyingOperator,
  addingOperator,
  relationalOperator,
  sign,
  unlabelledStatement,
  assignmentStatement,
  simpleStatement,
  gotoStatement,
  label,
  compoundStatement,
  structuredStatement,
  conditionalStatement,
  whileStatement,
  repetitiveStatement,
  repeatStatement,
  forStatement,
  forList,
  controlVariable,
  initialValue,
  finalValue,
  program,
  withStatement,
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
  "unsignedIntegerConstant",
  "unsignedReal",
  "unsignedNumber",
  "nil",
  "string",
  "multiplyingOperator",
  "addingOperator",
  "relationalOperator",
  "sign",
  "unlabelledStatement",
  "assignmentStatement",
  "simpleStatement",
  "gotoStatement",
  "label",
  "compoundStatement",
  "structuredStatement",
  "conditionalStatement",
  "whileStatement",
  "repetitiveStatement",
  "repeatStatement",
  "forStatement",
  "forList",
  "controlVariable",
  "initialValue",
  "finalValue",
  "program"
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
    void printFile(int level = 0);
    void setLnum(int);
    int retLnum();
  private:
    nodeTypes mytype;
    int lnum;
    std::vector<node*> children;
};
