#include "tokenizer.h"
#include "lexbuffer.h"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>

lex::token lex::tokenizer::nextToken() {
  char c;
  state = 0;
  start = 0;

  while (true) {
    if (endOfStream) {
      throw -1;
    }
    c = lb.nextChar();
    if (state == -1) {
      return lex::token{tokentype[tokentypes::TOKEN_ERROR], lb.getlexeme(), lb.lineNumber};
    }
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
        return lex::token{tokentype[tokentypes::EQUAL], lb.getlexeme(), lb.lineNumber};
      else if (c == '>')
        state = 2;
      else if (c == '+')
        state = 9;
      else if (c == '-')
        state = 10;
      else if (c == '*')
        state = 11;
      else if (c == '/')
        state = 16;
      else if (c == ':')
        state = 17;
      else if (c == ';')
        return lex::token{tokentype[tokentypes::SEMICOLON], lb.getlexeme(), lb.lineNumber};
      else if (c == '{') {
        braceCount++;
        return lex::token{tokentype[tokentypes::LBRACE], lb.getlexeme(), lb.lineNumber};
      } else if (c == '}'){
        if (braceCount){
          braceCount--;
          return lex::token{tokentype[tokentypes::RBRACE], lb.getlexeme(), lb.lineNumber};
        }else{
          return lex::token{tokentype[tokentypes::TOKEN_ERROR], lb.getlexeme(), lb.lineNumber};
        }
      }
      else if (c == '['){
        bracketCount++;
        return lex::token{tokentype[tokentypes::LBRACKET], lb.getlexeme(), lb.lineNumber};
      }
      else if (c == ']'){
        if (bracketCount){
          bracketCount--;
          return lex::token{tokentype[tokentypes::RBRACKET], lb.getlexeme(), lb.lineNumber};
        }else{
          return lex::token{tokentype[tokentypes::TOKEN_ERROR], lb.getlexeme(), lb.lineNumber};
        }
      }
      else if (c == '(')
        state = 5;
      else if (c == ')'){
        if (parenCount){
          parenCount--;
          return lex::token{tokentype[tokentypes::RPAREN], lb.getlexeme(), lb.lineNumber};
        }else{
          return lex::token{tokentype[tokentypes::TOKEN_ERROR], lb.getlexeme(), lb.lineNumber};
        }
      }
      else if (c == '^')
        return lex::token{tokentype[tokentypes::CARAT], lb.getlexeme(), lb.lineNumber};
      else if (c == ',')
        return lex::token{tokentype[tokentypes::COMMA], lb.getlexeme(), lb.lineNumber};
      else if (c == '\'')
        state = 18;
      else if (c == '.')
        state = 21;
      else {
        fail();
      }
      break;
    case 1:
      if (c == '=')
        return lex::token{tokentype[tokentypes::LTEQ], lb.getlexeme(), lb.lineNumber};
      else if (c == '>')
        return lex::token{tokentype[tokentypes::NE], lb.getlexeme(), lb.lineNumber};
      else {
        lb.retract();
        return lex::token{tokentype[tokentypes::LTEQ], lb.getlexeme(), lb.lineNumber};
      }
      break;
    case 2:
      if (c == '=') {
        return lex::token{tokentype[tokentypes::GTEQ], lb.getlexeme(), lb.lineNumber};
      } else {
        lb.retract();
        return lex::token{tokentype[tokentypes::GT], lb.getlexeme(), lb.lineNumber};
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
          return lex::token{tokentype[rwid], word, lb.lineNumber};
        } else {
          return lex::token{tokentype[tokentypes::IDENTIFIER], word, lb.lineNumber};
        }
      }
      break;

      // Thomas
    case 5:
      if (c == '*')
        state = 19;
      // return lex::token{tokentype[tokentypes::LCOMMENT], lb.getlexeme(), lb.lineNumber};
      // more state
      else {
        lb.retract();
        parenCount++;
        return lex::token{tokentype[tokentypes::LPAREN], lb.getlexeme(), lb.lineNumber};
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
        return lex::token{tokentype[tokentypes::INTEGER], lb.getlexeme(), lb.lineNumber};
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
        return lex::token{tokentype[tokentypes::REAL], lb.getlexeme(), lb.lineNumber};
      }
      break;

    case 9:
      if (c == '=')
        return lex::token{tokentype[tokentypes::PLUSEQUAL], lb.getlexeme(), lb.lineNumber};
      else {
        lb.retract();
        return lex::token{tokentype[tokentypes::PLUSOP], lb.getlexeme(), lb.lineNumber};
      }
    case 10:
      if (c == '=')
        return lex::token{tokentype[tokentypes::MINUSEQUAL], lb.getlexeme(), lb.lineNumber};
      else {
        lb.retract();
        return lex::token{tokentype[tokentypes::MINUSOP], lb.getlexeme(), lb.lineNumber};
      }
    case 11:
      if (c == '=')
        return lex::token{tokentype[tokentypes::MULTEQUAL], lb.getlexeme(), lb.lineNumber};
      else {
        lb.retract();
        return lex::token{tokentype[tokentypes::MULTOP], lb.getlexeme(), lb.lineNumber};
      }
    case 16:
      if (c == '=')
        return lex::token{tokentype[tokentypes::DIVEQUAL], lb.getlexeme(), lb.lineNumber};
      else {
        lb.retract();
        return lex::token{tokentype[tokentypes::DIVEQUAL], lb.getlexeme(), lb.lineNumber};
      }
    case 17:
      if (c == '=')
        return lex::token{tokentype[tokentypes::ASSIGN], lb.getlexeme(), lb.lineNumber};
      else {
        lb.retract();
        return lex::token{tokentype[tokentypes::COLON], lb.getlexeme(), lb.lineNumber};
      }

    // String Parser
    case 18:
      if (c == '\'')
        return lex::token{tokentype[tokentypes::STRING], lb.getlexeme(), lb.lineNumber};
      else
        state = 18;
      break;

    case 19:
      if (c == '*')
        // return lex::token{tokentype[tokentypes::STRING], lb.getlexeme(), lb.lineNumber};
        state = 20;
      else
        state = 19;
      break;

    case 20:
      if (c == ')')
        return lex::token{tokentype[tokentypes::COMMENT], lb.getlexeme(), lb.lineNumber};
      else
        state = 19;
      break;

      // Dot & DOT DOT
    case 21:
      if (c == '.')
        return lex::token{tokentype[tokentypes::DOTDOT], lb.getlexeme(), lb.lineNumber};
      else {
        lb.retract();
        return lex::token{tokentype[tokentypes::PERIOD], lb.getlexeme(), lb.lineNumber};
      }
      break;

    default:
      std::cerr
          << "Invalid State Reached, This should not have happened! State:"
          << state << "\t Current Char" << c << std::endl;
      abort();
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
    // This is an error state, should return a problem
    start = state = -1;
    break;
    // panic("Fail Switch has reached the end of possible cases");
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