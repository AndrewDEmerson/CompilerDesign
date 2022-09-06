#include "lexbuffer.h"

lexbuffer::lexbuffer(std::istream &stream):codestream(stream) {
  
}

char lexbuffer::nextChar(){
  if (readFromBuffer){
    return buffer[buffer.size()-readFromBuffer--];
  }
  if (codestream){
    buffer.push_back(codestream.get());
    return buffer.back();
  }
  return -1;
}

void lexbuffer::fail(){
  readFromBuffer = buffer.size();
}

void lexbuffer::retract(unsigned int retractAmount){
  readFromBuffer = retractAmount;
}


void lexbuffer::clearcache(){
  buffer.clear();
}

std::string lexbuffer::getlexeme(){
  std::string s;
  for (int i = 0; i < buffer.size()-readFromBuffer;i++){
    s.push_back(toupper(buffer[i]));
  }
  buffer.erase(buffer.begin(),buffer.end()-readFromBuffer);
  return s;
}