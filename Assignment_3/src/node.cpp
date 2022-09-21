#include "node.h"
#include <iostream>
#include <string>
#include <fstream>

node::node(nodeTypes nt) : mytype(nt) {}
node::node(nodeTypes nt, int ln) : mytype(nt), lnum(ln) {}
node::node(nodeTypes nt, std::string name) : mytype(nt), id(name) {}
node::node(nodeTypes nt, std::string name, int ln)
    : mytype(nt), id(name), lnum(ln) {}
node::node(nodeTypes nt, void *val, int ln) : mytype(nt), value(val), lnum(ln) {}
node::node(nodeTypes nt, void *val) : mytype(nt), value(val) {}

nodeTypes node::type() { return mytype; }

void node::attachChild(node *subtree) { children.push_back(subtree); }

void node::printTree(int level) {
  for (int i = 0; i < level; i++) {
    std::cout << "  ";
  }
  std::cout << "<" << nodeNames[mytype];
  if (mytype == nodeTypes::program) 
    std::cout << " : " << id;
  if (mytype == nodeTypes::unsignedInteger || mytype == nodeTypes::label) {
    std::cout << " : " << *static_cast<int*>(value);
  } else if (mytype == nodeTypes::variable || mytype == nodeTypes::multiplyingOperator || mytype == nodeTypes::addingOperator 
              || mytype == nodeTypes::relationalOperator || mytype == nodeTypes::sign) {
    std::cout << " : " << id;
  } else if (mytype == nodeTypes::unsignedReal) {
    std::cout << " : " << *static_cast<float*>(value);
  }
  if (mytype == nodeTypes::variable || mytype == nodeTypes::unsignedReal || mytype == nodeTypes::unsignedInteger || mytype == nodeTypes::label || mytype == nodeTypes::multiplyingOperator || mytype == nodeTypes::addingOperator || mytype == nodeTypes::relationalOperator || mytype == nodeTypes::sign) {
    std::cout << " />" << std::endl;
    goto END;
  }
  else std::cout << ">" << std::endl;
  if (children.size()==0) std::cout << "nochildren";
  for (int i = 0; i < children.size(); i++) {
    children[i]->printTree(level + 1);
  }
  for (int i = 0; i < level; i++) {
    std::cout << "  ";
  }
  std::cout << "</" << nodeNames[mytype] << ">" << std::endl;
  END:
  std::cout << "";
}

void node::printFile(int level) {
  std::ofstream output;
  output.open("out.txt");
  
  for (int i = 0; i < level; i++) {
    output << "  ";
  }
  output << "<" << nodeNames[mytype];
  if (mytype == nodeTypes::unsignedInteger || mytype == nodeTypes::label) {
    output << " : " << *static_cast<int*>(value);
  } else if (mytype == nodeTypes::variable || mytype == nodeTypes::multiplyingOperator || mytype == nodeTypes::addingOperator 
              || mytype == nodeTypes::relationalOperator || mytype == nodeTypes::sign) {
    output << " : " << id;
  } else if (mytype == nodeTypes::unsignedReal) {
    output << " : " << *static_cast<float*>(value);
  }
  if (mytype == nodeTypes::variable || mytype == nodeTypes::multiplyingOperator || mytype == nodeTypes::addingOperator || mytype == nodeTypes::relationalOperator || mytype == nodeTypes::sign) output << "/>" << std::endl;
  else output << ">" << std::endl;
  for (int i = 0; i < children.size(); i++) {
    children[i]->printFile(level + 1);
  }
  for (int i = 0; i < level; i++) {
    output << "  ";
  }
  output << "</" << nodeNames[mytype] << ">" << std::endl;
}

void node::setLnum(int a){
  lnum = a;
}

int node::retLnum(){
  return lnum;
}

/*
 << " Line number: " << lnum
*/