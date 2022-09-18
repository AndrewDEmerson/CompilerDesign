#include "tokenstream.h"
#include "tokenizer.h"
#include <iostream>
#include <istream>

lex::tokenStream::tokenStream(std::istream &stream) : tokenMaker(stream) {}

lex::token lex::tokenStream::nextToken() {
  if (rewindAmount == 0) {
    try {
      do {
        buffer[writePos] = tokenMaker.nextToken();
      } while (buffer[writePos].type == lex::tokentypes::COMMENT ||
               buffer[writePos].type == lex::tokentypes::TOKEN_ERROR);
    } catch (int) {
      // Reached EOF
      buffer[writePos] =
          lex::token{tokentypes::TOKEN_ERROR, "end of file catch", -1};
    }
    writePos = (writePos + 1) % bufferSize;
  } else {
    rewindAmount--;
  }
  return buffer[(writePos - rewindAmount - 1) % bufferSize];
}

bool lex::tokenStream::rewind(int amount) {
  rewindAmount += amount;
  if (rewindAmount > bufferSize) {
    return false;
  }
  return true;
}

lex::token lex::tokenStream::fastForward(lex::tokentypes type) {
  lex::token readIN;
  do {
    readIN = nextToken();
    if (readIN.type == lex::tokentypes::TOKEN_ERROR) {
      throw "Reached EOF before expected";
    }
  } while (readIN.type != type);
  return readIN;
}