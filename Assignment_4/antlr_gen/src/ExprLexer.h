
// Generated from src/Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  ExprLexer : public antlr4::Lexer {
public:
  enum {
    PROGRAM = 1, CONST = 2, TYPE = 3, ARRAY = 4, OF = 5, RECORD = 6, VAR = 7, 
    BEGIN = 8, END = 9, DIV = 10, MOD = 11, AND = 12, OR = 13, NOT = 14, 
    IF = 15, THEN = 16, ELSE = 17, CASE = 18, REPEAT = 19, UNTIL = 20, WHILE = 21, 
    DO = 22, FOR = 23, TO = 24, DOWNTO = 25, WRITE = 26, WRITELN = 27, READ = 28, 
    READLN = 29, PROCEDURE = 30, FUNCTION = 31, ASM = 32, BREAK = 33, CONSTRUCTOR = 34, 
    CONTINUE = 35, DESTRCUTOR = 36, FALSE = 37, FILE = 38, GOTO = 39, IMPLEMENTATION = 40, 
    INLINE = 41, INTERFACE = 42, LABEL = 43, NIL = 44, OBJECT = 45, ON = 46, 
    OPERATOR = 47, PAKCED = 48, SET = 49, SHL = 50, SHR = 51, TRUE = 52, 
    UNIT = 53, USES = 54, WITH = 55, XOR = 56, PLUSOP = 57, MINUSOP = 58, 
    MULTOP = 59, DIVOP = 60, ASSIGN = 61, EQUAL = 62, NE = 63, LTEQ = 64, 
    GTEQ = 65, LT = 66, GT = 67, PLUSEQUAL = 68, MINUSEQUAL = 69, MULTEQUAL = 70, 
    DIVEQUAL = 71, CARAT = 72, COMMA = 73, LPAREN = 74, RPAREN = 75, LBRACKET = 76, 
    RBRACKET = 77, LBRACE = 78, RBRACE = 79, LCOMMENT = 80, RCOMMENT = 81, 
    COLON = 82, IDENTIFIER = 83, INTEGER = 84, REAL = 85, NEWLINE = 86, 
    WS = 87, SEMICOLON = 88, PERIOD = 89, QUOTE = 90, CHARACTER = 91, STRING = 92, 
    COMMENT = 93
  };

  ExprLexer(antlr4::CharStream *input);
  ~ExprLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

