
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
    READLN = 29, PROCEDURE = 30, FUNCTION = 31, IDENTIFIER = 32, INTEGER = 33, 
    REAL = 34, NEWLINE = 35, WS = 36, SEMICOLON = 37, PERIOD = 38, QUOTE = 39, 
    CHARACTER = 40, STRING = 41, COMMENT = 42
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

