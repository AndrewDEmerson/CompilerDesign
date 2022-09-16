#include "node.h"
#include "tokenizer.h"
#include "tokenstream.h"

parser::node *parseIF(lex::tokenStream &);
parser::node *parseSimpleExpression(lex::tokenStream &);
parser::node *parseExpression(lex::tokenStream &);
parser::node *parseTerm(lex::tokenStream &);
parser::node *parseFactor(lex::tokenStream &);
parser::node *parseVariable(lex::tokenStream &);
parser::node *parseUnsignedConstant(lex::tokenStream &);
parser::node *parseUnsignedInteger(lex::tokenStream &);
parser::node *parseUnsignedNumber(lex::tokenStream &);
parser::node *parseUnsignedReal(lex::tokenStream &);
parser::node *parseString(lex::tokenStream &);
parser::node *parseMultiplyingOperator(lex::tokenStream &);
parser::node *parseAddingOperator(lex::tokenStream &);
parser::node *parseSign(lex::tokenStream &);