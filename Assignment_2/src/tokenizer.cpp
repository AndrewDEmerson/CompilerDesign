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


      else if (c == ';')
        return lex::token{tokentype[tokentypes::SEMICOLON], lb.getlexeme()};
      else if (c == '{')
        return lex::token{tokentype[tokentypes::LBRACE], lb.getlexeme()};
      else if (c == '}')
        return lex::token{tokentype[tokentypes::RBRACE], lb.getlexeme()};
      else if (c == '[')
        return lex::token{tokentype[tokentypes::LBRACKET], lb.getlexeme()};
      else if (c == ']')
        return lex::token{tokentype[tokentypes::RBRACKET], lb.getlexeme()};
      else if (c == '(')
        state = 5;
      else if (c == ')')
        return lex::token{tokentype[tokentypes::RPAREN], lb.getlexeme()};
      else if (c == '^')
        return lex::token{tokentype[tokentypes::CARAT], lb.getlexeme()};
      else if (c == ',')
        return lex::token{tokentype[tokentypes::COMMA], lb.getlexeme()};

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
        return lex::token{tokentype[tokentypes::LTEQ], lb.getlexeme()};
      }
      break;
    case 5: 
      c = lb.nextChar();
      if (c == '*') 
        return lex::token{tokentype[tokentypes::LCOMMENT], lb.getlexeme()};
      else 
        lb.retract();
        return lex::token{tokentype[tokentypes::LPAREN], lb.getlexeme()};
      break;
    }
  }
}

lex::tokenizer::tokenizer(std::istream &stream) : codestream(stream),lb(stream) {}