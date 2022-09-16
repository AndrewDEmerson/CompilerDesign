#pragma once

#include <vector>
namespace parser {

enum nodeTypes{
  if_statement,
  expression,
  statement,
};

class node{
  public:
    node(nodeTypes);
    nodeTypes type();
  private:
    nodeTypes mytype;
    std::vector<node*> children;
};

class variableNode: public node{

};

}