#include "tokenstream.h"
#include "tokenizer.h"
#include <istream>

lex::tokenStream::tokenStream(std::istream &stream):tokenMaker(stream){}

lex::token lex::tokenStream::nextToken(){
  if (rewindAmount == 0){
    buffer[writePos] = tokenMaker.nextToken();
    writePos = (writePos+1)%bufferSize;
  }else{
    rewindAmount--;
  }
  return buffer[(writePos-rewindAmount-1)%bufferSize];
}

bool lex::tokenStream::rewind(int amount){
  rewindAmount += amount;
  if (rewindAmount > bufferSize){
    return false;
  }
  return true;
}