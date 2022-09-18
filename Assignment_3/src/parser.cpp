#include "parser.h"
#include "node.h"
#include "tokenizer.h"
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

unsigned int numErrors;

void logError(const char* err){
  std::cerr << err << std::endl;
}

int main() {
  std::fstream codefile("test.pas");
  lex::tokenStream tokenstream(codefile);
  parser::node *head;
  try {
    head = parseStatement(tokenstream);
  } catch (const char* error) {
    std::cout << error << std::endl;
  }
  head->printTree();
}

parser::node *parseIfStatement(lex::tokenStream &tokenstream) {
  if (tokenstream.nextToken().type != lex::tokentypes::IF) {
    tokenstream.rewind();
    return nullptr;
  }
  parser::node *child = parseExpression(tokenstream);
  if (child == nullptr) {
    throw "parseIfStatement: expected expression after IF";
  }
  if (tokenstream.nextToken().type != lex::tokentypes::THEN) {
    //std::cerr << "parsing IF: has no keyword THEN" << std::endl;
    logError("parseIfStatement: expected THEN");
    tokenstream.fastForward(lex::tokentypes::THEN);
  }
  parser::node *child2 = parseStatement(tokenstream);
  if (child2 == nullptr) {
    throw "parseIfStatement: expected statement after THEN";
  }
  parser::node *currentNode = new parser::node(parser::nodeTypes::if_statement);
  currentNode->attachChild(child);
  currentNode->attachChild(child2);
  if (tokenstream.nextToken().type != lex::tokentypes::ELSE) {
    tokenstream.rewind();
    return currentNode;
  }
  parser::node *child3 = parseStatement(tokenstream);
  if (child2 == nullptr) {
    throw "parseIfStatement: expected statement after ELSE";
  }
  currentNode->attachChild(child3);
  return currentNode;
}

parser::node *parseExpression(lex::tokenStream &tokenstream) {
  parser::node *child = parseSimpleExpression(tokenstream);
  if (child != nullptr) {
    parser::node *child2 = parseRelationalOperator(tokenstream);
    if (child2 != nullptr) {
      parser::node *child3 = parseSimpleExpression(tokenstream);
      if (child3 != nullptr) {
        parser::node *currentNode =
            new parser::node(parser::nodeTypes::expression);
        currentNode->attachChild(child);
        currentNode->attachChild(child2);
        currentNode->attachChild(child3);
        return currentNode;
      }
      throw "parseExpression: expected simple expression after relation operator";
    }
    parser::node *currentNode = new parser::node(parser::nodeTypes::expression);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}

parser::node *parseSimpleExpression(lex::tokenStream &tokenstream) {
  parser::node *currentNode;
  parser::node *child;
  child = parseTerm(tokenstream);
  if (child != nullptr) {
    parser::node *child2 = parseAddingOperator(tokenstream);
    if (child2 != nullptr) {
      parser::node *child3 = parseSimpleExpression(tokenstream);
      if (child3 != nullptr) {
        currentNode = new parser::node(parser::nodeTypes::simpleExpression);
        currentNode->attachChild(child);
        currentNode->attachChild(child2);
        currentNode->attachChild(child3);
        return currentNode;
      }
      throw "parseSimpleExpression: expected simple expresssion after TERM ADDINGOPERATOR";
    }
    currentNode = new parser::node(parser::nodeTypes::simpleExpression);
    currentNode->attachChild(child);
    return currentNode;
  }
  child = parseSign(tokenstream);
  if (child != nullptr) {
    parser::node *child2 = parseTerm(tokenstream);
    if (child2 != nullptr) {
      currentNode = new parser::node(parser::nodeTypes::simpleExpression);
      currentNode->attachChild(child);
      currentNode->attachChild(child2);
      return currentNode;
    }
    throw "parseSimpleExpression: expected TERM after SIGN";
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
      throw "parseTerm: expected TERM after MULTIPLYING OPERATOR";
    }
    currentNode = new parser::node(parser::nodeTypes::term);
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
  if (tokenstream.nextToken().type == lex::tokentypes::LPAREN) {
    child = parseExpression(tokenstream);
    if (child != nullptr) {
      if (tokenstream.nextToken().type == lex::tokentypes::RPAREN) {
        currentNode = new parser::node(parser::nodeTypes::factor);
        currentNode->attachChild(child);
        return currentNode;
      }
    }
    throw "parseFactor: expected expression after (";
  }
  tokenstream.rewind();
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
  if (currentToken.type == lex::tokentypes::PLUSOP ||
      currentToken.type == lex::tokentypes::MINUSOP) {
    return new parser::node(parser::nodeTypes::sign, currentToken.lexeme);
  }
  tokenstream.rewind();
  return nullptr;
}

parser::node *parseRelationalOperator(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::EQUAL ||
      currentToken.type == lex::tokentypes::NE ||
      currentToken.type == lex::tokentypes::LT ||
      currentToken.type == lex::tokentypes::LTEQ ||
      currentToken.type == lex::tokentypes::GTEQ ||
      currentToken.type == lex::tokentypes::GT ||
      currentToken.type == lex::tokentypes::IN) {
    return new parser::node(parser::nodeTypes::relationalOperator,
                            currentToken.lexeme);
  }
  tokenstream.rewind();
  return nullptr;
}

parser::node *parseStatement(lex::tokenStream &tokenstream) {
  parser::node *child = parseUnlabelledStatement(tokenstream);
  if (child != nullptr) {
    parser::node *currentNode = new parser::node(parser::nodeTypes::statement);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}

parser::node *parseUnlabelledStatement(lex::tokenStream &tokenstream) {
  parser::node *child;
  parser::node *currentNode;
  child = parseSimpleStatement(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::unlabelledStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  child = parseStructuredStatement(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::unlabelledStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}

parser::node *parseAssignmentStatement(lex::tokenStream &tokenstream) {
  parser::node *child;
  parser::node *currentNode;
  child = parseVariable(tokenstream);
  if (child != nullptr) {
    if (tokenstream.nextToken().type == lex::tokentypes::ASSIGN) {
      parser::node *child2 = parseExpression(tokenstream);
      if (child2 != nullptr) {
        currentNode = new parser::node(parser::nodeTypes::assignmentStatement);
        currentNode->attachChild(child);
        currentNode->attachChild(child2);
        return currentNode;
      }
    }
    std::cerr << "Missformed Variable Assignment Statement" << std::endl;
  }
  return nullptr;
}

parser::node *parseSimpleStatement(lex::tokenStream &tokenstream) {
  parser::node *child;
  parser::node *currentNode;
  child = parseAssignmentStatement(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::simpleStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  child = parseGoToStatement(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::simpleStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}

parser::node *parseStructuredStatement(lex::tokenStream &tokenstream) {
  parser::node *child;
  parser::node *currentNode;
  child = parseCompoundStatement(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::structuredStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  child = parseConditionalStatement(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::structuredStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}

parser::node *parseConditionalStatement(lex::tokenStream &tokenstream) {
  parser::node *child;
  parser::node *currentNode;
  child = parseIfStatement(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::conditionalStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}

parser::node *parseGoToStatement(lex::tokenStream &tokenstream) {
  parser::node *child;
  parser::node *currentNode;
  if (tokenstream.nextToken().type == lex::tokentypes::GOTO) {
    child = parseLabel(tokenstream);
    if (child != nullptr) {
      currentNode = new parser::node(parser::nodeTypes::gotoStatement);
      currentNode->attachChild(child);
      return currentNode;
    }
    std::cerr << "Parse GOTO: missing label" << std::endl;
  }
  tokenstream.rewind();
  return nullptr;
}

parser::node *parseLabel(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::INTEGER) {
    return new parser::node(parser::nodeTypes::label,
                            new int(stoi(currentToken.lexeme)));
  }
  tokenstream.rewind();
  return nullptr;
}

parser::node *parseCompoundStatement(lex::tokenStream &tokenstream) {
  parser::node *child;
  parser::node *currentNode;
  if (tokenstream.nextToken().type == lex::tokentypes::BEGIN) {
    currentNode = new parser::node(parser::nodeTypes::compoundStatement);
    while (true) {
      child = parseStatement(tokenstream);
      if (child == nullptr) {
        throw "parseCompoundStatement: expected statement";
      }
      if (tokenstream.nextToken().type != lex::tokentypes::SEMICOLON) {
        logError("parseCompoundStatement: expected semicolon");
        tokenstream.fastForward(lex::tokentypes::SEMICOLON);
      }
      currentNode->attachChild(child);
      if (tokenstream.nextToken().type == lex::tokentypes::END) {
        if (tokenstream.nextToken().type != lex::tokentypes::SEMICOLON) {
          logError("parseCompoundStatement: expected semicolon");
          tokenstream.fastForward(lex::tokentypes::SEMICOLON);
        }
        return currentNode;
      } else {
        tokenstream.rewind();
      }
    }
  }
  tokenstream.rewind();
  return nullptr;
}

/*
parser::node *parseTemplate(lex::tokenStream &tokenstream) {
  parser::node *child;
  parser::node *currentNode;
  child = parseChildNodeType(tokenstream);
  if (child != nullptr) {
    currentNode = new parser::node(parser::nodeTypes::template);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}
*/