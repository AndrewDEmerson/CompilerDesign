#include "parser.h"
#include "node.h"
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>

int main() {
  std::fstream codefile("test.txt");
  lex::tokenStream tokenstream(codefile);
  parser::node *head;
    head = parseExpression(tokenstream);
    head->printTree();
}

parser::node *parseIF(lex::tokenStream &tokenstream) {
  if (tokenstream.nextToken().type != lex::tokentypes::IF) {
    tokenstream.rewind();
    return nullptr;
  }
  parser::node *exp = parseExpression(tokenstream);
  if (exp == nullptr)
    throw -1;
  if (tokenstream.nextToken().type != lex::tokentypes::THEN) {
    // TODO: PANIC
    std::cerr << "parse if has no then keyword" << std::endl;
    throw -1;
  }
  /*parseStatement()*/ tokenstream
      .nextToken(); // TODO Replace this with real function
  parser::node *currentNode = new parser::node(parser::nodeTypes::if_statement);
  currentNode->attachChild(exp);
  return currentNode;
}

parser::node *parseExpression(lex::tokenStream &tokenstream) {
  parser::node *child = parseSimpleExpression(tokenstream);
  if (child == nullptr)
    return nullptr;
  parser::node *currentNode = new parser::node(parser::nodeTypes::expression);
  currentNode->attachChild(child);
  return currentNode;
}

parser::node *parseSimpleExpression(lex::tokenStream &tokenstream) {
  parser::node *currentNode;
  parser::node *child;
  child = parseTerm(tokenstream);
  if (child != nullptr) {
    parser::node *child2 = parseAddingOperator(tokenstream);
    if(child2 != nullptr){
      parser::node *child3 = parseSimpleExpression(tokenstream);
      if(child3 != nullptr){
        currentNode = new parser::node(parser::nodeTypes::simpleExpression);
        currentNode->attachChild(child);
        currentNode->attachChild(child2);
        currentNode->attachChild(child3);
        return currentNode;
      }
      std::cerr << "Parse simple expression expected simple expression after adding operator" << std::endl;
      throw -1;
    }
    currentNode = new parser::node(parser::nodeTypes::simpleExpression);
    currentNode->attachChild(child);
    return currentNode;
  }
  child = parseSign(tokenstream);
  if (child != nullptr) {
      parser::node *child2 = parseTerm(tokenstream);
      if(child2 != nullptr){
        currentNode = new parser::node(parser::nodeTypes::simpleExpression);
        currentNode->attachChild(child);
        currentNode->attachChild(child2);
        return currentNode;
      }
      std::cerr << "In parse simple expression, expected term after sign" << std::endl;
      throw -1;
  }
  return nullptr;
}

parser::node *parseTerm(lex::tokenStream &tokenstream) {
  parser::node *currentNode;
  parser::node *child;
  //<term> <multiplying op> <factor>
  child = parseFactor(tokenstream);
  if (child != nullptr) {
    parser::node *child2 = parseMultiplyingOperator(tokenstream);
    if (child2 != nullptr) {
      parser::node *child3 = parseTerm(tokenstream);
      if (child3 != nullptr) {
        currentNode = new parser::node(parser::nodeTypes::term);
        currentNode->attachChild(child);
        currentNode->attachChild(child2);
        currentNode->attachChild(child3);
        return currentNode;
      }
      std::cerr << "Throw at parse term" << std::endl;
      throw -1;
    }
    currentNode = new parser::node(parser::nodeTypes::factor);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}

parser::node *parseFactor(lex::tokenStream &tokenstream) {
  parser::node *currentNode;
  parser::node *child;
  //<Variable>
  child = parseVariable(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::factor);
    currentNode->attachChild(child);
    return currentNode;
  }
  //<Unsigned Constant>
  child = parseUnsignedConstant(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::factor);
    currentNode->attachChild(child);
    return currentNode;
  }
  //< (Expression) >
  return nullptr;
}

parser::node *parseVariable(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::IDENTIFIER) {
    return new parser::node(parser::nodeTypes::variable, currentToken.lexeme);
  }
  tokenstream.rewind();
  return nullptr;
}

parser::node *parseUnsignedConstant(lex::tokenStream &tokenstream) {
  parser::node *currentNode;
  parser::node *child;
  //<unsigned number>
  child = parseUnsignedNumber(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::unsignedConstant);
    currentNode->attachChild(child);
    return currentNode;
  }
  //<String>
  child = parseString(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::unsignedConstant);
    currentNode->attachChild(child);
    return currentNode;
  }
  //<NIL>
  if (tokenstream.nextToken().type == lex::tokentypes::NIL) {
    currentNode = new parser::node(parser::nodeTypes::unsignedNumber);
    currentNode->attachChild(new parser::node(parser::nodeTypes::nil));
    return currentNode;
  }
  tokenstream.rewind();
  return nullptr;
}

parser::node *parseUnsignedNumber(lex::tokenStream &tokenstream) {
  parser::node *currentNode;
  parser::node *child;
  //<unsigned Integer>
  child = parseUnsignedInteger(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::unsignedNumber);
    currentNode->attachChild(child);
    return currentNode;
  }
  //<unsigned Real>
  child = parseUnsignedReal(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::unsignedNumber);
    currentNode->attachChild(child);
    return currentNode;
  }

  return nullptr;
}

parser::node *parseUnsignedInteger(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::INTEGER) {
    return new parser::node(parser::nodeTypes::unsignedInteger,
                            new int(stoi(currentToken.lexeme)));
  }
  tokenstream.rewind();
  return nullptr;
}

parser::node *parseUnsignedReal(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::REAL) {
    return new parser::node(parser::nodeTypes::unsignedReal,
                            new float(stof(currentToken.lexeme)));
  }
  tokenstream.rewind();
  return nullptr;
}

parser::node *parseString(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::STRING) {
    return new parser::node(parser::nodeTypes::string, currentToken.lexeme);
  }
  tokenstream.rewind();
  return nullptr;
}

parser::node *parseMultiplyingOperator(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::MULTOP ||
      currentToken.type == lex::tokentypes::DIVOP ||
      currentToken.type == lex::tokentypes::DIV ||
      currentToken.type == lex::tokentypes::MOD ||
      currentToken.type == lex::tokentypes::AND) {
    return new parser::node(parser::nodeTypes::multiplyingOperator,
                            currentToken.lexeme);
  }
  tokenstream.rewind();
  return nullptr;
}

parser::node *parseAddingOperator(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::PLUSOP ||
      currentToken.type == lex::tokentypes::MINUSOP) {
    return new parser::node(parser::nodeTypes::addingOperator,
                            currentToken.lexeme);
  }
  tokenstream.rewind();
  return nullptr;
}

parser::node *parseSign(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::PLUSOP || currentToken.type == lex::tokentypes::MINUSOP) {
    return new parser::node(parser::nodeTypes::sign, currentToken.lexeme);
  }
  tokenstream.rewind();
  return nullptr;
}

