#include "tokenizer.h"
#include <iostream>
#include <ostream>

int main() {
  std::fstream codefile("testing.txt");
  if (!codefile.is_open()) {
    throw "Could not open file";
  }
  lex::tokenizer tokenmaker(codefile);

  while (true) {
    try {
      lex::token a = tokenmaker.nextToken();
      std::cout << a.type << '\t' << a.lexeme << std::endl;
    } catch (int) {
      std::cout << "end of file" << std::endl;
      return 0;
    }
  }
  return 0;
}
