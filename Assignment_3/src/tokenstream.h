#include "tokenizer.h"
#include <vector>
namespace lex {

class tokenStream {
public:
  tokenStream(std::istream &stream);
  lex::token nextToken();
  bool rewind(int amount = 1);

private:
  int writePos = 0;
  unsigned const static int bufferSize = 16;
  lex::token buffer[bufferSize];
  int rewindAmount = 0;
  lex::tokenizer tokenMaker;

};

} // namespace lex