#include "node.h"

parser::node::node(parser::nodeTypes nt):mytype(nt){}

parser::nodeTypes parser::node::type(){
  return mytype;
}