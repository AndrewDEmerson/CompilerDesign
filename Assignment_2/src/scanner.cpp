#include "tokenizer.h"
#include <iostream>
#include <ostream>

int main(int argc, char *argv[]) {
  if (argc != 2){
    std::cout << "Please Specify the path to the source file as an argument, EXITING" << std::endl;
    return 0;
  }
  std::fstream codefile(argv[1]);
  if (!codefile.is_open()) {
    std::cerr << "Could not open file" << std::endl;
    return -1;
  }
  lex::tokenizer tokenmaker(codefile);

  while (true) {
    try {
      lex::token a = tokenmaker.nextToken();
      if (a.type == "TOKEN_ERROR"){
        std::cout << "TOKEN ERROR at line " << a.ln << ": Invalid token at '" << a.lexeme << "'" << std::endl;
      }else{
        std::cout << a.type << '\t' << a.lexeme << '\t' << std::endl;
      }
    } catch (int) {
      std::cout << "end of file" << std::endl;
      return 0;
    }
  }
  return 0;
}
