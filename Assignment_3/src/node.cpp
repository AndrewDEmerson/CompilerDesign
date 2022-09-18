#include "node.h"
#include <iostream>
#include <string>

node::node(nodeTypes nt) : mytype(nt) {}

node::node(nodeTypes nt, std::string name)
    : mytype(nt), id(name) {}
node::node(nodeTypes nt, void *val) : mytype(nt), value(val) {}

nodeTypes node::type() { return mytype; }

void node::attachChild(node *subtree) { children.push_back(subtree); }

void node::printTree(int level) {
  for (int i = 0; i < level; i++) {
    std::cout << "|  ";
  }
  std::cout << nodeNames[mytype];
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