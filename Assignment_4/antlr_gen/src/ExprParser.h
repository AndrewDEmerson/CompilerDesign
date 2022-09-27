
// Generated from src/Expr.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  ExprParser : public antlr4::Parser {
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

  enum {
    RuleProg = 0
  };

  explicit ExprParser(antlr4::TokenStream *input);

  ExprParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ExprParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROGRAM();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

