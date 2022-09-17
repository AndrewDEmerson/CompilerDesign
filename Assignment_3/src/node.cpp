#include "node.h"
#include <iostream>
#include <string>

parser::node::node(parser::nodeTypes nt) : mytype(nt) {}

parser::node::node(parser::nodeTypes nt, std::string name)
    : mytype(nt), id(name) {}
parser::node::node(parser::nodeTypes nt, void *val) : mytype(nt), value(val) {}

parser::nodeTypes parser::node::type() { return mytype; }

void parser::node::attachChild(node *subtree) { children.push_back(subtree); }

void parser::node::printTree(int level) {
  for (int i = 0; i < level; i++) {
    std::cout << "|  ";
  }
  std::cout << parser::nodeNames[mytype];
  if (mytype == nodeTypes::unsignedInteger || mytype == nodeTypes::label) {
    std::cout << ": " << *static_cast<int*>(value);
  } else if (mytype == nodeTypes::variable ||
             mytype == nodeTypes::multiplyingOperator ||
             mytype == nodeTypes::addingOperator ||
             mytype == nodeTypes::relationalOperator ||
             mytype == nodeTypes::sign) {
    std::cout << ": " << id;
  } else if (mytype == nodeTypes::unsignedReal) {
    std::cout << ": " << *static_cast<float*>(value);
  }
  std::cout << std::endl;
  for (int i = 0; i < children.size(); i++) {
    children[i]->printTree(level + 1);
  }
}