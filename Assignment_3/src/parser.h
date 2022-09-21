#include "node.h"
#include "tokenizer.h"
#include "tokenstream.h"
#include "symbolTable.h"

class parser {
public:
  node *parseIfStatement(lex::tokenStream &);
  node *parseSimpleExpression(lex::tokenStream &);
  node *parseExpression(lex::tokenStream &);
  node *parseTerm(lex::tokenStream &);
  node *parseFactor(lex::tokenStream &);
  node *parseVariable(lex::tokenStream &);
  node *parseUnsignedConstant(lex::tokenStream &);
  node *parseUnsignedInteger(lex::tokenStream &);
  node *parseUnsignedNumber(lex::tokenStream &);
  node *parseUnsignedReal(lex::tokenStream &);
  node *parseString(lex::tokenStream &);
  node *parseMultiplyingOperator(lex::tokenStream &);
  node *parseAddingOperator(lex::tokenStream &);
  node *parseRelationalOperator(lex::tokenStream &);
  node *parseSign(lex::tokenStream &);
  node *parseStatement(lex::tokenStream &);
  node *parseUnlabelledStatement(lex::tokenStream &);
  node *parseAssignmentStatement(lex::tokenStream &);
  node *parseSimpleStatement(lex::tokenStream &);
  node *parseGoToStatement(lex::tokenStream &);
  node *parseLabel(lex::tokenStream &);
  node *parseCompoundStatement(lex::tokenStream &);
  node *parseStructuredStatement(lex::tokenStream &);
  node *parseConditionalStatement(lex::tokenStream &);
  node *parseWhileStatement(lex::tokenStream&);
  node *parseRepetitiveStatement(lex::tokenStream&);
  node *parseRepeatStatement(lex::tokenStream&);
  node* parseForStatement(lex::tokenStream&);
  node* parseForList(lex::tokenStream&);
  node* parseProgram(lex::tokenStream&);
  node* parseCaseLabelList(lex::tokenStream&);
  node* parseCaseListElement(lex::tokenStream&);
  node* parseCaseStatement(lex::tokenStream&);
  node *parseWithStatement(lex::tokenStream&);

  void logError(const char *err);
  symbolTable symTab;
  bool short_print = true;

private:
  int numErrors = 0;
};