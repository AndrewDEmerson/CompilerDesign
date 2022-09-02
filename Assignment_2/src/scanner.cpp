#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>
#include "tokenizer.h"
int main() {
  std::fstream codefile("testing.txt");
  if (!codefile.is_open()) {
    throw "Could not open file";
  }
  lex::tokenizer tokenmaker(codefile);
  lex::token a = tokenmaker.nextToken();
  std::cout << a.type << std::endl;

  return 0;
}
