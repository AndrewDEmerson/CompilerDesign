#pragma once
#include <istream>
#include <vector>

class lexbuffer {
private:
  std::vector<char> buffer;
  std::istream &codestream;
  // std::ifstream codefile;
  int readFromBuffer = 0;

public:
  lexbuffer(std::istream &stream);
  char nextChar();
  void retract(unsigned int retractAmount = 1);
  void fail();
  void clearcache();
  std::string getlexeme();
  int lineNumber = 1;
};