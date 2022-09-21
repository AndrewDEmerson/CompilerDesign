#pragma once

#include <string>
#include <vector>

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
  labelList,
  caseListElement,
  caseStatement,
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
  "program",
  "labelList",
  "caseListElement",
  "caseStatement",
  "withStatement"
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
