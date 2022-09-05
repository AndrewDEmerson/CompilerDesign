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
        return lex::token{tokentype[tokentypes::LT], lb.getlexeme()};
      else if (c == '{')
        return lex::token{tokentype[tokentypes::LT], lb.getlexeme()};
      else if (c == '}')
        return lex::token{tokentype[tokentypes::LT], lb.getlexeme()};
      else if (c == '[')
        return lex::token{tokentype[tokentypes::LT], lb.getlexeme()};
      else if (c == ']')
        return lex::token{tokentype[tokentypes::LT], lb.getlexeme()};
      else if (c == '(')
        state = 12;
      else if (c == ')')
        return lex::token{tokentype[tokentypes::LT], lb.getlexeme()};
      else if (c == '^')
        return lex::token{tokentype[tokentypes::LT], lb.getlexeme()};
      else if (c == ',')
        return lex::token{tokentype[tokentypes::LT], lb.getlexeme()};

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
    case 12: 
      c = lb.nextChar();
      if (c == '*') 
        return lex::token{tokentype[tokentypes::LT], lb.getlexeme()};
      else 
        lb.retract();
        return lex::token{tokentype[tokentypes::LT], lb.getlexeme()};
      break;
    }
  }
}

lex::tokenizer::tokenizer(std::istream &stream) : codestream(stream),lb(stream) {}