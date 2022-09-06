#include "tokenizer.h"
#include "lexbuffer.h"
#include <cstddef>
#include <iostream>

#define panic(s)                                                               \
  std::cerr << "Panic: " << s << std::endl;                                    \
  abort();

lex::token lex::tokenizer::nextToken() {
  char c;
  state = 0;
  start = 0;
  if (endOfStream) {
    throw -1;
  }
  while (true) {
    c = lb.nextChar();
    if (c == -1) {
      endOfStream = true;
      c = ' ';
    }
    switch (state) {
      // Begin of State machine for Symbol Pattern Matching
    case 0:
      if (std::isspace(c)) {
        state = 0;
        lb.clearcache();
      } else if (c == '<')
        state = 1;
      else if (c == '=')
        return lex::token{tokentype[tokentypes::EQUAL], lb.getlexeme()};
      else if (c == '>')
        state = 2;
      else {
        fail();
      }
      break;
    case 1:
      if (c == '=')
        return lex::token{tokentype[tokentypes::LTEQ], lb.getlexeme()};
      else if (c == '>')
        return lex::token{tokentype[tokentypes::NE], lb.getlexeme()};
      else {
        lb.retract();
        return lex::token{tokentype[tokentypes::LT], lb.getlexeme()};
      }
      break;
    case 2:
      if (c == '=') {
        return lex::token{tokentype[tokentypes::GTEQ], lb.getlexeme()};
      } else {
        lb.retract();
        return lex::token{tokentype[tokentypes::GT], lb.getlexeme()};
      }
      // Begin of State Machine for Keyword/Variable pattern matching
    case 3:
      if (std::isalpha(c)) {
        state = 4;
      } else {
        fail();
      }
      break;
    case 4:
      if (std::isalnum(c)) {
        state = 4;
      } else {
        lb.retract();
        std::string word = lb.getlexeme();
        int rwid = isKeyword(&word);
        if (rwid >= 0) {
          return lex::token{tokentype[rwid], word};
        } else {
          return lex::token{tokentype[tokentypes::IDENTIFIER], word};
        }
      }
      break;

    // Vincent
    case 12: // input that switches to case 12 that just
      if (std::isdigit(c)) {
        state = 13; // starts loop to read in expected digits (state 13)
      } else {
        fail(); // or should it just move onto the next state if I didn't find a
                // digit
      }
      break;
    case 13:
      if (std::isdigit(c)) { // keep reading digits until
        state = 13;
      } else if (c == '.') { // you hit a decimal
        state = 14; // then move on to decimal digit loop of a Real Number (14)
      } else {      // otherwise, if you never hit a decimal
        lb.retract();
        return lex::token{tokentype[tokentypes::INTEGER], lb.getlexeme()};
      }
      break;
    case 14:
      if (std::isdigit(c)) {
        state = 15; // starts loop to read in expected digits (state 15)
      } else {
        fail(); // or should it just move onto the next state if I didn't find a
                // digit
      }
      break;
    case 15:
      if (std::isdigit(c)) { // keep reading digits until
        state = 15;
      } else { // you hit the end where
        lb.retract();
        return lex::token{tokentype[tokentypes::REAL], lb.getlexeme()};
      }
      break;
    default:
      panic("Invalid State Reached");
    }
  }
}

void lex::tokenizer::fail() {
  lb.fail();
  switch (start) {
  case 0:
    start = state = 3;
    break;
  case 3:
    start = state = 12;
    break;
  default:
    panic("Fail Switch has reached the end of possible cases");
  }
}

int lex::tokenizer::isKeyword(std::string *word) {
  for (int i = 0; i < 51; i++) {
    if (word->compare(tokentype[i]) == 0) {
      return i;
    }
  }
  return -1;
}

lex::tokenizer::tokenizer(std::istream &stream)
    : codestream(stream), lb(stream) {}