#include "lexbuffer.h"
#include <iostream>

lexbuffer::lexbuffer(std::istream &stream):codestream(stream),lineNumber(1) {
  
}

char lexbuffer::nextChar(){
  if (readFromBuffer){
    if (buffer[buffer.size()-readFromBuffer] == '\n'){
      lineNumber++;
            //std::cout << "NewLine----" << std::endl;

    }
    return buffer[buffer.size()-readFromBuffer--];
  }
  if (codestream){
    buffer.push_back(codestream.get());
    if (buffer.back() == '\n'){
      //std::cout << "NewLine----" << std::endl;
      lineNumber++;
    }
    return buffer.back();
  }
  return -1;
}

void lexbuffer::fail(){
  readFromBuffer = buffer.size();
  for (int i = buffer.size()-readFromBuffer; i < buffer.size(); i++){
    if (buffer[i] == '\n'){
      lineNumber--;
    }
  }
}

void lexbuffer::retract(unsigned int retractAmount){
  readFromBuffer = retractAmount;
  for (int i = buffer.size()-readFromBuffer; i < buffer.size(); i++){
    if (buffer[i] == '\n'){
      lineNumber--;
    }
  }
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