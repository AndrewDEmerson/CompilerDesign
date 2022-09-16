#include "node.h"
#include "tokenizer.h"
#include "tokenstream.h"
#include <cstddef>
#include <fstream>
#include <iostream>
parser::node *parseIF(lex::tokenStream &);

int main() {
  std::fstream codefile("test.txt");
  lex::tokenStream tokenstream(codefile);
  std::cout << parseIF(tokenstream)->type() << std::endl;
}

parser::node *parseIF(lex::tokenStream &tokenstream) {
  if (tokenstream.nextToken().type != lex::tokentypes::IF) {
    tokenstream.rewind();
    return nullptr;
  }
  /*parseExpression()*/ tokenstream.nextToken(); // TODO Replace this with real function
  if (tokenstream.nextToken().type != lex::tokentypes::THEN) {
    // TODO: PANIC
    throw -1;
  }
  /*parseStatement()*/ tokenstream.nextToken(); // TODO Replace this with real function
  //TODO add children to if node before returning
  return new parser::node(parser::nodeTypes::if_statement);
}