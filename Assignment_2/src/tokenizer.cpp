#include "tokenizer.h"
#include "lexbuffer.h"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <ostream>
#define panic(s)                                                               \
  std::cerr << "Panic: " << s << std::endl;                                    \
  abort();

lex::token lex::tokenizer::nextToken() {
  char c;
  while (true) {
    switch (state) {
    case 0:
      c = lb.nextChar();
      if (std::isspace(c)) {
        state = 0;
        lb.clearcache();
      } else if (c == '<')
        state = 1;
      else if (c == '=')
        state = 5;
      else if (c == '>')
        state = 6;
      else {
        panic("Could not reach valid state");
      }
      break;
    case 1:
      c = lb.nextChar();
      if (c == '=')
        state = 2;
      if (c == '>')
        state = 3;
      else {
        lb.retract();
        return lex::token{tokentype[tokentypes::LT], lb.getlexeme()};
      }
      break;

    //Vincent 
    case 12:                      //input that switches to case 12 that just
      c = lb.nextChar();          //reads next char
      if (std::isdigit(c)) {      
        state = 13;               //starts loop to read in expected digits (state 13)
      }
      else {
        panic("should I panic?")  //or should it just move onto the next state if I didn't find a digit
      }
    case 13:
      c = lb.nextChar();
      if (std::isdigit(c)) {      //keep reading digits until
        state = 13;               
      }
      else if (c == '.'){         //you hit a decimal
        state = 14;               //then move on to decimal digit loop of a Real Number (14)
      }
      else {    //otherwise, if you never hit a decimal
        state = 17;               //state 17 will return an integer
      }
    case 14:
      c = lb.nextChar();          //reads next char for decimal digits
      if (std::isdigit(c)) {      
        state = 15;               //starts loop to read in expected digits (state 15)
      }
      else {
        panic("should I panic?")  //or should it just move onto the next state if I didn't find a digit
    }
    case 15: 
      c = lb.nextChar();
      if (std::isdigit(c)) {      //keep reading digits until
        state = 15;               
      }
      else {    //you hit the end where
        state = 16;               //state 16 will return an integer
      }
    //case 16: will return an integer
    //else {
    //  lb.retract();
    //  return lex::token{tokentype[tokentypes::INTEGER], lb.getlexeme()};
    //case 17: will return a real number
    //else {
    //  lb.retract();
    //  return lex::token{tokentype[tokentypes::REAL], lb.getlexeme()};

    }
  }
}

lex::tokenizer::tokenizer(std::istream &stream) : codestream(stream),lb(stream) {}