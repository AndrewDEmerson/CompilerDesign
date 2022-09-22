#include "parser.h"
#include "node.h"
#include "symbolTable.h"
#include "tokenizer.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

int main() {
  std::fstream codefile("test.pas");
  lex::tokenStream tokenstream(codefile);
  node *head;
  parser prse;
  try {
    // prse.short_print = false;
    head = prse.parseProgram(tokenstream);
    head->printTree();
    prse.symTab.printTable();
    head->printFile();
  } catch (const char *error) {
    std::cerr << "Could not recover from error: " << error << "\nExiting"
              << std::endl;
  }
}

node *parser::parseProgram(lex::tokenStream &tokenstream) {
  node *child;
  node *currentNode;
  if (tokenstream.nextToken().type != lex::tokentypes::PROGRAM) {
    throw "Parse Program: expected PROGRAM";
  }
  lex::token id = tokenstream.nextToken();
  if (id.type != lex::tokentypes::IDENTIFIER) {
    throw "Expected Identifier";
  }
  if (tokenstream.nextToken().type != lex::tokentypes::SEMICOLON) {
    throw "Parse Program: expected PROGRAM";
  }
  child = parseCompoundStatement(tokenstream);
  if (child == nullptr){
    throw "Parse Program: expected compound statement";
  }
  if (tokenstream.nextToken().type != lex::tokentypes::PERIOD) {
    throw "Parse Program: expected PERIOD at end of program";
  }
  currentNode = new node(nodeTypes::program, id.lexeme);
  currentNode->attachChild(child);
  return currentNode;
}

node *parser::parseIfStatement(lex::tokenStream &tokenstream) {
  if (tokenstream.nextToken().type != lex::tokentypes::IF) {
    tokenstream.rewind();
    return nullptr;
  }
  node *child = parseExpression(tokenstream);
  if (child == nullptr) {
    throw "parseIfStatement: expected expression after IF";
  }
  if (tokenstream.nextToken().type != lex::tokentypes::THEN) {
    // std::cerr << "parsing IF: has no keyword THEN" << std::endl;
    logError("parseIfStatement: expected THEN");
    tokenstream.fastForward(lex::tokentypes::THEN);
  }
  node *child2 = parseStatement(tokenstream);
  if (child2 == nullptr) {
    throw "parseIfStatement: expected statement after THEN";
  }
  node *currentNode = new node(nodeTypes::if_statement);
  currentNode->attachChild(child);
  currentNode->attachChild(child2);
  if (tokenstream.nextToken().type != lex::tokentypes::ELSE) {
    tokenstream.rewind();
    return currentNode;
  }
  node *child3 = parseStatement(tokenstream);
  if (child2 == nullptr) {
    throw "parseIfStatement: expected statement after ELSE";
  }
  currentNode->attachChild(child3);
  return currentNode;
}

void parser::logError(const char *err) {
  std::cerr << err << std::endl;
  if (++numErrors >= 3) {
    std::cerr << "To many errors, Exiting" << std::endl;
    exit(1);
  }
}

node *parser::parseExpression(lex::tokenStream &tokenstream) {
  node *child = parseSimpleExpression(tokenstream);
  if (child != nullptr) {
    node *child2 = parseRelationalOperator(tokenstream);
    if (child2 != nullptr) {
      node *child3 = parseSimpleExpression(tokenstream);
      if (child3 != nullptr) {
        node *currentNode = new node(nodeTypes::expression);
        currentNode->attachChild(child);
        currentNode->attachChild(child2);
        currentNode->attachChild(child3);
        return currentNode;
      }
      throw "parseExpression: expected simple expression after relation "
            "operator";
    }
    if (short_print)
      return child;
    node *currentNode = new node(nodeTypes::expression);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}

node *parser::parseSimpleExpression(lex::tokenStream &tokenstream) {
  node *currentNode;
  node *child;
  child = parseTerm(tokenstream);
  if (child != nullptr) {
    node *child2 = parseAddingOperator(tokenstream);
    if (child2 != nullptr) {
      node *child3 = parseSimpleExpression(tokenstream);
      if (child3 != nullptr) {
        currentNode = new node(nodeTypes::simpleExpression);
        currentNode->attachChild(child);
        currentNode->attachChild(child2);
        currentNode->attachChild(child3);
        return currentNode;
      }
      throw "parseSimpleExpression: expected simple expresssion after TERM "
            "ADDINGOPERATOR";
    }
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::simpleExpression);
    currentNode->attachChild(child);
    return currentNode;
  }
  child = parseSign(tokenstream);
  if (child != nullptr) {
    node *child2 = parseTerm(tokenstream);
    if (child2 != nullptr) {
      currentNode = new node(nodeTypes::simpleExpression);
      currentNode->attachChild(child);
      currentNode->attachChild(child2);
      return currentNode;
    }
    throw "parseSimpleExpression: expected TERM after SIGN";
  }
  return nullptr;
}

node *parser::parseTerm(lex::tokenStream &tokenstream) {
  node *currentNode;
  node *child;
  //<term> <multiplying op> <factor>
  child = parseFactor(tokenstream);
  if (child != nullptr) {
    node *child2 = parseMultiplyingOperator(tokenstream);
    if (child2 != nullptr) {
      node *child3 = parseTerm(tokenstream);
      if (child3 != nullptr) {
        currentNode = new node(nodeTypes::term);
        currentNode->attachChild(child);
        currentNode->attachChild(child2);
        currentNode->attachChild(child3);
        return currentNode;
      }
      throw "parseTerm: expected TERM after MULTIPLYING OPERATOR";
    }
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::term);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}

node *parser::parseFactor(lex::tokenStream &tokenstream) {
  node *currentNode;
  node *child;
  //<Variable>
  child = parseVariable(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::factor);
    currentNode->attachChild(child);
    return currentNode;
  }
  //<Unsigned Constant>
  child = parseUnsignedConstant(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::factor);
    currentNode->attachChild(child);
    return currentNode;
  }
  //< (Expression) >
  if (tokenstream.nextToken().type == lex::tokentypes::LPAREN) {
    child = parseExpression(tokenstream);
    if (child != nullptr) {
      if (tokenstream.nextToken().type == lex::tokentypes::RPAREN) {
        if (short_print)
          return child;
        currentNode = new node(nodeTypes::factor);
        currentNode->attachChild(child);
        return currentNode;
      }
    }
    throw "parseFactor: expected expression after (";
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseVariable(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::IDENTIFIER) {
    symTab.updateTable(currentToken.lexeme);
    return new node(nodeTypes::variable, currentToken.lexeme);
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseUnsignedConstant(lex::tokenStream &tokenstream) {
  node *currentNode;
  node *child;
  //<unsigned number>
  child = parseUnsignedNumber(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::unsignedConstant);
    currentNode->attachChild(child);
    return currentNode;
  }
  //<String>
  child = parseString(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::unsignedConstant);
    currentNode->attachChild(child);
    return currentNode;
  }
  //<NIL>
  if (tokenstream.nextToken().type == lex::tokentypes::NIL) {
    if (short_print)
      return new node(nodeTypes::nil);
    currentNode = new node(nodeTypes::unsignedNumber);
    currentNode->attachChild(new node(nodeTypes::nil));
    return currentNode;
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseUnsignedNumber(lex::tokenStream &tokenstream) {
  node *currentNode;
  node *child;
  //<unsigned Integer>
  child = parseUnsignedInteger(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::unsignedNumber);
    currentNode->attachChild(child);
    return currentNode;
  }
  //<unsigned Real>
  child = parseUnsignedReal(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::unsignedNumber);
    currentNode->attachChild(child);
    return currentNode;
  }

  return nullptr;
}

node *parser::parseUnsignedInteger(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::INTEGER) {
    return new node(nodeTypes::unsignedInteger,
                    new int(stoi(currentToken.lexeme)));
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseUnsignedReal(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::REAL) {
    return new node(nodeTypes::unsignedReal,
                    new float(stof(currentToken.lexeme)));
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseString(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::STRING) {
    return new node(nodeTypes::string, currentToken.lexeme);
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseMultiplyingOperator(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::MULTOP ||
      currentToken.type == lex::tokentypes::DIVOP ||
      currentToken.type == lex::tokentypes::DIV ||
      currentToken.type == lex::tokentypes::MOD ||
      currentToken.type == lex::tokentypes::AND) {
    return new node(nodeTypes::multiplyingOperator, currentToken.lexeme);
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseAddingOperator(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::PLUSOP ||
      currentToken.type == lex::tokentypes::MINUSOP) {
    return new node(nodeTypes::addingOperator, currentToken.lexeme);
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseSign(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::PLUSOP ||
      currentToken.type == lex::tokentypes::MINUSOP) {
    return new node(nodeTypes::sign, currentToken.lexeme);
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseRelationalOperator(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::EQUAL ||
      currentToken.type == lex::tokentypes::NE ||
      currentToken.type == lex::tokentypes::LT ||
      currentToken.type == lex::tokentypes::LTEQ ||
      currentToken.type == lex::tokentypes::GTEQ ||
      currentToken.type == lex::tokentypes::GT ||
      currentToken.type == lex::tokentypes::IN) {
    return new node(nodeTypes::relationalOperator, currentToken.lexeme);
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseStatement(lex::tokenStream &tokenstream) {
  node *child = parseUnlabelledStatement(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    node *currentNode = new node(nodeTypes::statement);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}

node *parser::parseUnlabelledStatement(lex::tokenStream &tokenstream) {
  node *child;
  node *currentNode;
  child = parseSimpleStatement(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::unlabelledStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  child = parseStructuredStatement(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::unlabelledStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}

node *parser::parseAssignmentStatement(lex::tokenStream &tokenstream) {
  node *child;
  node *currentNode;
  child = parseVariable(tokenstream);
  if (child != nullptr) {
    if (tokenstream.nextToken().type == lex::tokentypes::ASSIGN) {
      node *child2 = parseExpression(tokenstream);
      if (child2 != nullptr) {
        currentNode = new node(nodeTypes::assignmentStatement);
        currentNode->attachChild(child);
        currentNode->attachChild(child2);
        return currentNode;
      }
    }
    std::cerr << "Missformed Variable Assignment Statement" << std::endl;
  }
  return nullptr;
}

node *parser::parseSimpleStatement(lex::tokenStream &tokenstream) {
  node *child;
  node *currentNode;
  child = parseAssignmentStatement(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::simpleStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  child = parseGoToStatement(tokenstream);
  if (child != nullptr) {
    // currentNode = new node(nodeTypes::simpleStatement);
    // currentNode->attachChild(child);
    // return currentNode;
    return child;
  }
  return nullptr;
}

node *parser::parseStructuredStatement(lex::tokenStream &tokenstream) {
  node *child;
  node *currentNode;
  child = parseCompoundStatement(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::structuredStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  child = parseConditionalStatement(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::structuredStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  child = parseRepetitiveStatement(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::structuredStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  child = parseWithStatement(tokenstream);
  if (child != nullptr) {
      if (short_print)
          return child;
      currentNode = new node(nodeTypes::structuredStatement);
      currentNode->attachChild(child);
      return currentNode;
  }
  return nullptr;
}

node *parser::parseConditionalStatement(lex::tokenStream &tokenstream) {
  node *child;
  node *currentNode;
  child = parseIfStatement(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::conditionalStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  child = parseCaseStatement(tokenstream);
  if (child != nullptr) {
    if (short_print)
      return child;
    currentNode = new node(nodeTypes::conditionalStatement);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}

node *parser::parseGoToStatement(lex::tokenStream &tokenstream) {
  node *child;
  node *currentNode;
  if (tokenstream.nextToken().type == lex::tokentypes::GOTO) {
    child = parseLabel(tokenstream);
    if (child != nullptr) {
      currentNode = new node(nodeTypes::gotoStatement);
      currentNode->attachChild(child);
      return currentNode;
    }
    std::cerr << "Parse GOTO: missing label" << std::endl;
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseLabel(lex::tokenStream &tokenstream) {
  lex::token currentToken = tokenstream.nextToken();
  if (currentToken.type == lex::tokentypes::INTEGER) {
    return new node(nodeTypes::label, new int(stoi(currentToken.lexeme)));
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseCompoundStatement(lex::tokenStream &tokenstream) {
  node *child;
  node *currentNode;
  if (tokenstream.nextToken().type == lex::tokentypes::BEGIN) {
    currentNode = new node(nodeTypes::compoundStatement);
    while (true) {
      child = parseStatement(tokenstream);
      if (child == nullptr) {
        throw "parseCompoundStatement: expected statement";
      }
      currentNode->attachChild(child);
      if (tokenstream.nextToken().type != lex::tokentypes::SEMICOLON) {
        tokenstream.rewind();
      }
      if (tokenstream.nextToken().type == lex::tokentypes::END) {
        if (tokenstream.nextToken().type != lex::tokentypes::SEMICOLON) {
          tokenstream.rewind();
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

node *parser::parseWhileStatement(lex::tokenStream &tokenstream) {
  node *child;
  node *child2;
  node *currentNode;
  if (tokenstream.nextToken().type == lex::tokentypes::WHILE) {
    currentNode = new node(nodeTypes::whileStatement);
    child = parseExpression(tokenstream);
    if (child == nullptr) {
      throw "parseWhileStatement: expected expression";
    }
    currentNode->attachChild(child);
    if (tokenstream.nextToken().type != lex::tokentypes::DO) {
      throw "parseWhileStatement: expected DO";
    }
    child2 = parseStatement(tokenstream);
    if (child2 == nullptr) {
      throw "parseWhileStatement: expected statement";
    }
    currentNode->attachChild(child2);
    return currentNode;
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseRepetitiveStatement(lex::tokenStream &tokenstream) {
  node *currentNode;
  node *childNode;
  childNode = parseWhileStatement(tokenstream);
  if (childNode != nullptr) {
    if (short_print)
      return childNode;
    currentNode = new node(nodeTypes::repetitiveStatement);
    currentNode->attachChild(childNode);
    return currentNode;
  }
  childNode = parseRepeatStatement(tokenstream);
  if (childNode != nullptr) {
    if (short_print)
      return childNode;
    currentNode = new node(nodeTypes::repetitiveStatement);
    currentNode->attachChild(childNode);
    return currentNode;
  }
  childNode = parseForStatement(tokenstream);
  if (childNode != nullptr) {
    if (short_print)
      return childNode;
    currentNode = new node(nodeTypes::repetitiveStatement);
    currentNode->attachChild(childNode);
    return currentNode;
  }
  return nullptr;
}

node *parser::parseRepeatStatement(lex::tokenStream &tokenstream) {
  node *currentNode;
  node *child1;
  node *child2;
  node *loopChild;
  if (tokenstream.nextToken().type == lex::tokentypes::REPEAT) {
    currentNode = new node(nodeTypes::repeatStatement);
    child1 = parseStatement(tokenstream);
    if (child1 == nullptr) {
      throw "parserRepeatStatement: expected statement";
    }
    currentNode->attachChild(child1);
    while (tokenstream.nextToken().type == lex::tokentypes::SEMICOLON) {
      loopChild = parseStatement(tokenstream);
      if (loopChild == nullptr) {
        tokenstream.nextToken();
        break; //last statement may or may not have a semicolon
        //throw "parserRepeatStatement: expected statement";
      }
      currentNode->attachChild(loopChild);
    }
    tokenstream.rewind();
    if (tokenstream.nextToken().type != lex::tokentypes::UNTIL) {
      throw "parserRepeatStatement: expected UNTIL";
    }
    child2 = parseExpression(tokenstream);
    if (child2 == nullptr) {
      throw "parserRepeatStatement: expected expression";
    }
    currentNode->attachChild(child2);
    return currentNode;
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseForStatement(lex::tokenStream &tokenstream) {
  node *currentNode;
  node *child1;
  node *child2;
  node *child3;
  if (tokenstream.nextToken().type == lex::tokentypes::FOR) {
    currentNode = new node(nodeTypes::forStatement);
    child1 = parseVariable(tokenstream);
    if (child1 == nullptr) {
      throw "parseForStatement: expected variable";
    }
    if (tokenstream.nextToken().type != lex::tokentypes::ASSIGN) {
      throw "parseForStatement: expected assignment";
    }
    child2 = parseForList(tokenstream);
    if (child2 == nullptr) {
      throw "parseForStatement: expected for list";
    }
    if (tokenstream.nextToken().type != lex::tokentypes::DO) {
      throw "parseForStatement: expected DO";
    }
    child3 = parseStatement(tokenstream);
    if (child3 == nullptr) {
      throw "parseForStatement: expected statement";
    }
    currentNode->attachChild(child1);
    currentNode->attachChild(child2);
    currentNode->attachChild(child3);
    return currentNode;
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseForList(lex::tokenStream &tokenstream) {
  node *currentNode;
  node *child1;
  node *child2;
  child1 = parseExpression(tokenstream);
  if (child1 != nullptr) {
    currentNode = new node(nodeTypes::forList);
    if (tokenstream.nextToken().type != lex::tokentypes::TO) {
      tokenstream.rewind();
      if (tokenstream.nextToken().type != lex::tokentypes::DOWNTO) {
        throw "parseForList: expected TO or DOWNTO";
      }
    }
    child2 = parseExpression(tokenstream);
    if (child2 == nullptr) {
      throw "parseForList: expected final value";
    }
    currentNode->attachChild(child1);
    currentNode->attachChild(child2);
    return currentNode;
  }
  tokenstream.rewind();
  return nullptr;
}

node *parser::parseWithStatement(lex::tokenStream &tokenstream) {
    node *currentNode;
    node *childNode1;
    node* childNode2;
    if (tokenstream.nextToken().type == lex::tokentypes::WITH) {
        currentNode = new node(nodeTypes::withStatement);
        childNode1 = parseVariable(tokenstream);
        if (childNode1 == nullptr) {
            throw "parseWithStatement: expected variable";
        }
        currentNode->attachChild(childNode1);
        if (tokenstream.nextToken().type != lex::tokentypes::DO) {
            throw "parseWithStatement: expected DO";
        }
        childNode2 = parseStatement(tokenstream);
        if (childNode2 == nullptr) {
            throw "parseWithStatement: expted statement";
        }
        currentNode->attachChild(childNode2);
        return currentNode;
    }
    tokenstream.rewind();
    return nullptr;
}

node *parser::parseCaseLabelList(lex::tokenStream &tokenstream) {
  node *child;
  node *currentNode;
  child = parseUnsignedInteger(tokenstream);
  if (child == nullptr) return nullptr;
  currentNode = new node(nodeTypes::labelList);
  currentNode->attachChild(child);
  while (tokenstream.nextToken().type == lex::tokentypes::COMMA){
    child = parseUnsignedInteger(tokenstream);
    if (child == nullptr) throw "LabelList Expected Int";
    currentNode->attachChild(child);
  }
  tokenstream.rewind();
  return currentNode;
}

node *parser::parseCaseListElement(lex::tokenStream &tokenstream) {
  node *child;
  node *currentNode;
  child = parseCaseLabelList(tokenstream);
  if(child == nullptr) throw "expected case list label";
  currentNode = new node(nodeTypes::caseListElement);
  currentNode->attachChild(child);
  if (tokenstream.nextToken().type != lex::tokentypes::COLON) throw "ParseCaseListElement: expected :";
  child = parseStatement(tokenstream);
  currentNode->attachChild(child);
  return currentNode;
}

node *parser::parseCaseStatement(lex::tokenStream &tokenstream) {
  node *child;
  node *currentNode;
  if (tokenstream.nextToken().type != lex::tokentypes::CASE) {
    tokenstream.rewind();
    return nullptr;
  }
  child = parseExpression(tokenstream);
  if (child == nullptr)
    throw "parseCaseStatement: Expexted expression";
  if (tokenstream.nextToken().type != lex::tokentypes::OF) {
    tokenstream.rewind();
    throw "parseCaseStatement: Expected OF";
  }
  currentNode = new node(nodeTypes::caseStatement);
  currentNode->attachChild(child);
  child = parseCaseListElement(tokenstream);
  if (child == nullptr)
    throw "parseCaseStatement: CaseListElement";
  currentNode->attachChild(child);
  while (tokenstream.nextToken().type == lex::tokentypes::SEMICOLON) {
    if (tokenstream.nextToken().type == lex::tokentypes::END){
      return currentNode;
    }
    tokenstream.rewind();
    child = parseCaseListElement(tokenstream);
    if (child == nullptr) {
      tokenstream.nextToken();
      break; // last statement may or may not have a semicolon
      // throw "parserRepeatStatement: expected statement";
    }
    currentNode->attachChild(child);
  }
  tokenstream.rewind();
  if (tokenstream.nextToken().type != lex::tokentypes::END) {
    tokenstream.rewind();
    throw "parseCaseStatement: Expexted end";
  }
  return currentNode;
}

/*
node *parseTemplate(lex::tokenStream &tokenstream) {
  node *child;
  node *currentNode;
  child = parseChildNodeType(tokenstream);
  if (child != nullptr) {
    currentNode = new node(nodeTypes::template);
    currentNode->attachChild(child);
    return currentNode;
  }
  return nullptr;
}
*/
//with statement will fall under structured statement along with repetitive statement