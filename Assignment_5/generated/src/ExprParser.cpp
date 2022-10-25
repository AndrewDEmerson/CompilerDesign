
// Generated from src/Expr.g4 by ANTLR 4.7.2


#include "ExprVisitor.h"

#include "ExprParser.h"


using namespace antlrcpp;
using namespace antlr4;

ExprParser::ExprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ExprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

ExprParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ProgramHeadingContext* ExprParser::ProgramContext::programHeading() {
  return getRuleContext<ExprParser::ProgramHeadingContext>(0);
}

ExprParser::BlockContext* ExprParser::ProgramContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}

tree::TerminalNode* ExprParser::ProgramContext::DOT() {
  return getToken(ExprParser::DOT, 0);
}

tree::TerminalNode* ExprParser::ProgramContext::INTERFACE() {
  return getToken(ExprParser::INTERFACE, 0);
}


size_t ExprParser::ProgramContext::getRuleIndex() const {
  return ExprParser::RuleProgram;
}


antlrcpp::Any ExprParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProgramContext* ExprParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    programHeading();
    setState(196);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::INTERFACE) {
      setState(195);
      match(ExprParser::INTERFACE);
    }
    setState(198);
    block();
    setState(199);
    match(ExprParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramHeadingContext ------------------------------------------------------------------

ExprParser::ProgramHeadingContext::ProgramHeadingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ProgramHeadingContext::PROGRAM() {
  return getToken(ExprParser::PROGRAM, 0);
}

ExprParser::IdentifierContext* ExprParser::ProgramHeadingContext::identifier() {
  return getRuleContext<ExprParser::IdentifierContext>(0);
}

tree::TerminalNode* ExprParser::ProgramHeadingContext::SEMICOLON() {
  return getToken(ExprParser::SEMICOLON, 0);
}

tree::TerminalNode* ExprParser::ProgramHeadingContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

ExprParser::IdentifierListContext* ExprParser::ProgramHeadingContext::identifierList() {
  return getRuleContext<ExprParser::IdentifierListContext>(0);
}

tree::TerminalNode* ExprParser::ProgramHeadingContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}

tree::TerminalNode* ExprParser::ProgramHeadingContext::UNIT() {
  return getToken(ExprParser::UNIT, 0);
}


size_t ExprParser::ProgramHeadingContext::getRuleIndex() const {
  return ExprParser::RuleProgramHeading;
}


antlrcpp::Any ExprParser::ProgramHeadingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProgramHeading(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProgramHeadingContext* ExprParser::programHeading() {
  ProgramHeadingContext *_localctx = _tracker.createInstance<ProgramHeadingContext>(_ctx, getState());
  enterRule(_localctx, 2, ExprParser::RuleProgramHeading);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(219);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(201);
      match(ExprParser::PROGRAM);
      setState(202);
      identifier();
      setState(207);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == ExprParser::LPAREN) {
        setState(203);
        match(ExprParser::LPAREN);
        setState(204);
        identifierList();
        setState(205);
        match(ExprParser::RPAREN);
      }
      setState(209);
      match(ExprParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(211);
      match(ExprParser::UNIT);
      setState(212);
      identifier();
      setState(213);
      match(ExprParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(215);
      match(ExprParser::PROGRAM);
      setState(216);
      identifier();
      setState(217);
      match(ExprParser::SEMICOLON);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

ExprParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::IdentifierContext::IDENT() {
  return getToken(ExprParser::IDENT, 0);
}


size_t ExprParser::IdentifierContext::getRuleIndex() const {
  return ExprParser::RuleIdentifier;
}


antlrcpp::Any ExprParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::IdentifierContext* ExprParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 4, ExprParser::RuleIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    match(ExprParser::IDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

ExprParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::CompoundStatementContext* ExprParser::BlockContext::compoundStatement() {
  return getRuleContext<ExprParser::CompoundStatementContext>(0);
}

std::vector<ExprParser::LabelDeclarationPartContext *> ExprParser::BlockContext::labelDeclarationPart() {
  return getRuleContexts<ExprParser::LabelDeclarationPartContext>();
}

ExprParser::LabelDeclarationPartContext* ExprParser::BlockContext::labelDeclarationPart(size_t i) {
  return getRuleContext<ExprParser::LabelDeclarationPartContext>(i);
}

std::vector<ExprParser::ConstantDefinitionPartContext *> ExprParser::BlockContext::constantDefinitionPart() {
  return getRuleContexts<ExprParser::ConstantDefinitionPartContext>();
}

ExprParser::ConstantDefinitionPartContext* ExprParser::BlockContext::constantDefinitionPart(size_t i) {
  return getRuleContext<ExprParser::ConstantDefinitionPartContext>(i);
}

std::vector<ExprParser::TypeDefinitionPartContext *> ExprParser::BlockContext::typeDefinitionPart() {
  return getRuleContexts<ExprParser::TypeDefinitionPartContext>();
}

ExprParser::TypeDefinitionPartContext* ExprParser::BlockContext::typeDefinitionPart(size_t i) {
  return getRuleContext<ExprParser::TypeDefinitionPartContext>(i);
}

std::vector<ExprParser::VariableDeclarationPartContext *> ExprParser::BlockContext::variableDeclarationPart() {
  return getRuleContexts<ExprParser::VariableDeclarationPartContext>();
}

ExprParser::VariableDeclarationPartContext* ExprParser::BlockContext::variableDeclarationPart(size_t i) {
  return getRuleContext<ExprParser::VariableDeclarationPartContext>(i);
}

std::vector<ExprParser::ProcedureAndFunctionDeclarationPartContext *> ExprParser::BlockContext::procedureAndFunctionDeclarationPart() {
  return getRuleContexts<ExprParser::ProcedureAndFunctionDeclarationPartContext>();
}

ExprParser::ProcedureAndFunctionDeclarationPartContext* ExprParser::BlockContext::procedureAndFunctionDeclarationPart(size_t i) {
  return getRuleContext<ExprParser::ProcedureAndFunctionDeclarationPartContext>(i);
}

std::vector<ExprParser::UsesUnitsPartContext *> ExprParser::BlockContext::usesUnitsPart() {
  return getRuleContexts<ExprParser::UsesUnitsPartContext>();
}

ExprParser::UsesUnitsPartContext* ExprParser::BlockContext::usesUnitsPart(size_t i) {
  return getRuleContext<ExprParser::UsesUnitsPartContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::BlockContext::IMPLEMENTATION() {
  return getTokens(ExprParser::IMPLEMENTATION);
}

tree::TerminalNode* ExprParser::BlockContext::IMPLEMENTATION(size_t i) {
  return getToken(ExprParser::IMPLEMENTATION, i);
}


size_t ExprParser::BlockContext::getRuleIndex() const {
  return ExprParser::RuleBlock;
}


antlrcpp::Any ExprParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::BlockContext* ExprParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 6, ExprParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 8) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 8)) & ((1ULL << (ExprParser::CONST - 8))
      | (1ULL << (ExprParser::FUNCTION - 8))
      | (1ULL << (ExprParser::LABEL - 8))
      | (1ULL << (ExprParser::PROCEDURE - 8))
      | (1ULL << (ExprParser::TYPE - 8))
      | (1ULL << (ExprParser::VAR - 8))
      | (1ULL << (ExprParser::USES - 8))
      | (1ULL << (ExprParser::IMPLEMENTATION - 8)))) != 0)) {
      setState(230);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case ExprParser::LABEL: {
          setState(223);
          labelDeclarationPart();
          break;
        }

        case ExprParser::CONST: {
          setState(224);
          constantDefinitionPart();
          break;
        }

        case ExprParser::TYPE: {
          setState(225);
          typeDefinitionPart();
          break;
        }

        case ExprParser::VAR: {
          setState(226);
          variableDeclarationPart();
          break;
        }

        case ExprParser::FUNCTION:
        case ExprParser::PROCEDURE: {
          setState(227);
          procedureAndFunctionDeclarationPart();
          break;
        }

        case ExprParser::USES: {
          setState(228);
          usesUnitsPart();
          break;
        }

        case ExprParser::IMPLEMENTATION: {
          setState(229);
          match(ExprParser::IMPLEMENTATION);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(234);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(235);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UsesUnitsPartContext ------------------------------------------------------------------

ExprParser::UsesUnitsPartContext::UsesUnitsPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::UsesUnitsPartContext::USES() {
  return getToken(ExprParser::USES, 0);
}

ExprParser::IdentifierListContext* ExprParser::UsesUnitsPartContext::identifierList() {
  return getRuleContext<ExprParser::IdentifierListContext>(0);
}

tree::TerminalNode* ExprParser::UsesUnitsPartContext::SEMICOLON() {
  return getToken(ExprParser::SEMICOLON, 0);
}


size_t ExprParser::UsesUnitsPartContext::getRuleIndex() const {
  return ExprParser::RuleUsesUnitsPart;
}


antlrcpp::Any ExprParser::UsesUnitsPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitUsesUnitsPart(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::UsesUnitsPartContext* ExprParser::usesUnitsPart() {
  UsesUnitsPartContext *_localctx = _tracker.createInstance<UsesUnitsPartContext>(_ctx, getState());
  enterRule(_localctx, 8, ExprParser::RuleUsesUnitsPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    match(ExprParser::USES);
    setState(238);
    identifierList();
    setState(239);
    match(ExprParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelDeclarationPartContext ------------------------------------------------------------------

ExprParser::LabelDeclarationPartContext::LabelDeclarationPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::LabelDeclarationPartContext::LABEL() {
  return getToken(ExprParser::LABEL, 0);
}

std::vector<ExprParser::LabelContext *> ExprParser::LabelDeclarationPartContext::label() {
  return getRuleContexts<ExprParser::LabelContext>();
}

ExprParser::LabelContext* ExprParser::LabelDeclarationPartContext::label(size_t i) {
  return getRuleContext<ExprParser::LabelContext>(i);
}

tree::TerminalNode* ExprParser::LabelDeclarationPartContext::SEMICOLON() {
  return getToken(ExprParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> ExprParser::LabelDeclarationPartContext::COMMA() {
  return getTokens(ExprParser::COMMA);
}

tree::TerminalNode* ExprParser::LabelDeclarationPartContext::COMMA(size_t i) {
  return getToken(ExprParser::COMMA, i);
}


size_t ExprParser::LabelDeclarationPartContext::getRuleIndex() const {
  return ExprParser::RuleLabelDeclarationPart;
}


antlrcpp::Any ExprParser::LabelDeclarationPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLabelDeclarationPart(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::LabelDeclarationPartContext* ExprParser::labelDeclarationPart() {
  LabelDeclarationPartContext *_localctx = _tracker.createInstance<LabelDeclarationPartContext>(_ctx, getState());
  enterRule(_localctx, 10, ExprParser::RuleLabelDeclarationPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    match(ExprParser::LABEL);
    setState(242);
    label();
    setState(247);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::COMMA) {
      setState(243);
      match(ExprParser::COMMA);
      setState(244);
      label();
      setState(249);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(250);
    match(ExprParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelContext ------------------------------------------------------------------

ExprParser::LabelContext::LabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::UnsignedIntegerContext* ExprParser::LabelContext::unsignedInteger() {
  return getRuleContext<ExprParser::UnsignedIntegerContext>(0);
}


size_t ExprParser::LabelContext::getRuleIndex() const {
  return ExprParser::RuleLabel;
}


antlrcpp::Any ExprParser::LabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLabel(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::LabelContext* ExprParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 12, ExprParser::RuleLabel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    unsignedInteger();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDefinitionPartContext ------------------------------------------------------------------

ExprParser::ConstantDefinitionPartContext::ConstantDefinitionPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ConstantDefinitionPartContext::CONST() {
  return getToken(ExprParser::CONST, 0);
}

std::vector<ExprParser::ConstantDefinitionContext *> ExprParser::ConstantDefinitionPartContext::constantDefinition() {
  return getRuleContexts<ExprParser::ConstantDefinitionContext>();
}

ExprParser::ConstantDefinitionContext* ExprParser::ConstantDefinitionPartContext::constantDefinition(size_t i) {
  return getRuleContext<ExprParser::ConstantDefinitionContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::ConstantDefinitionPartContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::ConstantDefinitionPartContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}


size_t ExprParser::ConstantDefinitionPartContext::getRuleIndex() const {
  return ExprParser::RuleConstantDefinitionPart;
}


antlrcpp::Any ExprParser::ConstantDefinitionPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitConstantDefinitionPart(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ConstantDefinitionPartContext* ExprParser::constantDefinitionPart() {
  ConstantDefinitionPartContext *_localctx = _tracker.createInstance<ConstantDefinitionPartContext>(_ctx, getState());
  enterRule(_localctx, 14, ExprParser::RuleConstantDefinitionPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    match(ExprParser::CONST);
    setState(258); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(255);
      constantDefinition();
      setState(256);
      match(ExprParser::SEMICOLON);
      setState(260); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ExprParser::IDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDefinitionContext ------------------------------------------------------------------

ExprParser::ConstantDefinitionContext::ConstantDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::IdentifierContext* ExprParser::ConstantDefinitionContext::identifier() {
  return getRuleContext<ExprParser::IdentifierContext>(0);
}

tree::TerminalNode* ExprParser::ConstantDefinitionContext::EQUAL() {
  return getToken(ExprParser::EQUAL, 0);
}

ExprParser::ConstantContext* ExprParser::ConstantDefinitionContext::constant() {
  return getRuleContext<ExprParser::ConstantContext>(0);
}


size_t ExprParser::ConstantDefinitionContext::getRuleIndex() const {
  return ExprParser::RuleConstantDefinition;
}


antlrcpp::Any ExprParser::ConstantDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitConstantDefinition(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ConstantDefinitionContext* ExprParser::constantDefinition() {
  ConstantDefinitionContext *_localctx = _tracker.createInstance<ConstantDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 16, ExprParser::RuleConstantDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    identifier();
    setState(263);
    match(ExprParser::EQUAL);
    setState(264);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantChrContext ------------------------------------------------------------------

ExprParser::ConstantChrContext::ConstantChrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ConstantChrContext::CHR() {
  return getToken(ExprParser::CHR, 0);
}

tree::TerminalNode* ExprParser::ConstantChrContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

ExprParser::UnsignedIntegerContext* ExprParser::ConstantChrContext::unsignedInteger() {
  return getRuleContext<ExprParser::UnsignedIntegerContext>(0);
}

tree::TerminalNode* ExprParser::ConstantChrContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}


size_t ExprParser::ConstantChrContext::getRuleIndex() const {
  return ExprParser::RuleConstantChr;
}


antlrcpp::Any ExprParser::ConstantChrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitConstantChr(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ConstantChrContext* ExprParser::constantChr() {
  ConstantChrContext *_localctx = _tracker.createInstance<ConstantChrContext>(_ctx, getState());
  enterRule(_localctx, 18, ExprParser::RuleConstantChr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(ExprParser::CHR);
    setState(267);
    match(ExprParser::LPAREN);
    setState(268);
    unsignedInteger();
    setState(269);
    match(ExprParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

ExprParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::UnsignedNumberContext* ExprParser::ConstantContext::unsignedNumber() {
  return getRuleContext<ExprParser::UnsignedNumberContext>(0);
}

ExprParser::SignContext* ExprParser::ConstantContext::sign() {
  return getRuleContext<ExprParser::SignContext>(0);
}

ExprParser::IdentifierContext* ExprParser::ConstantContext::identifier() {
  return getRuleContext<ExprParser::IdentifierContext>(0);
}

ExprParser::StringContext* ExprParser::ConstantContext::string() {
  return getRuleContext<ExprParser::StringContext>(0);
}

ExprParser::ConstantChrContext* ExprParser::ConstantContext::constantChr() {
  return getRuleContext<ExprParser::ConstantChrContext>(0);
}


size_t ExprParser::ConstantContext::getRuleIndex() const {
  return ExprParser::RuleConstant;
}


antlrcpp::Any ExprParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ConstantContext* ExprParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 20, ExprParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(281);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(271);
      unsignedNumber();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(272);
      sign();
      setState(273);
      unsignedNumber();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(275);
      identifier();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(276);
      sign();
      setState(277);
      identifier();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(279);
      string();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(280);
      constantChr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedNumberContext ------------------------------------------------------------------

ExprParser::UnsignedNumberContext::UnsignedNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::UnsignedIntegerContext* ExprParser::UnsignedNumberContext::unsignedInteger() {
  return getRuleContext<ExprParser::UnsignedIntegerContext>(0);
}

ExprParser::UnsignedRealContext* ExprParser::UnsignedNumberContext::unsignedReal() {
  return getRuleContext<ExprParser::UnsignedRealContext>(0);
}


size_t ExprParser::UnsignedNumberContext::getRuleIndex() const {
  return ExprParser::RuleUnsignedNumber;
}


antlrcpp::Any ExprParser::UnsignedNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitUnsignedNumber(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::UnsignedNumberContext* ExprParser::unsignedNumber() {
  UnsignedNumberContext *_localctx = _tracker.createInstance<UnsignedNumberContext>(_ctx, getState());
  enterRule(_localctx, 22, ExprParser::RuleUnsignedNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(285);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::NUM_INT: {
        enterOuterAlt(_localctx, 1);
        setState(283);
        unsignedInteger();
        break;
      }

      case ExprParser::NUM_REAL: {
        enterOuterAlt(_localctx, 2);
        setState(284);
        unsignedReal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedIntegerContext ------------------------------------------------------------------

ExprParser::UnsignedIntegerContext::UnsignedIntegerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::UnsignedIntegerContext::NUM_INT() {
  return getToken(ExprParser::NUM_INT, 0);
}


size_t ExprParser::UnsignedIntegerContext::getRuleIndex() const {
  return ExprParser::RuleUnsignedInteger;
}


antlrcpp::Any ExprParser::UnsignedIntegerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitUnsignedInteger(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::UnsignedIntegerContext* ExprParser::unsignedInteger() {
  UnsignedIntegerContext *_localctx = _tracker.createInstance<UnsignedIntegerContext>(_ctx, getState());
  enterRule(_localctx, 24, ExprParser::RuleUnsignedInteger);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    match(ExprParser::NUM_INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedRealContext ------------------------------------------------------------------

ExprParser::UnsignedRealContext::UnsignedRealContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::UnsignedRealContext::NUM_REAL() {
  return getToken(ExprParser::NUM_REAL, 0);
}


size_t ExprParser::UnsignedRealContext::getRuleIndex() const {
  return ExprParser::RuleUnsignedReal;
}


antlrcpp::Any ExprParser::UnsignedRealContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitUnsignedReal(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::UnsignedRealContext* ExprParser::unsignedReal() {
  UnsignedRealContext *_localctx = _tracker.createInstance<UnsignedRealContext>(_ctx, getState());
  enterRule(_localctx, 26, ExprParser::RuleUnsignedReal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    match(ExprParser::NUM_REAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignContext ------------------------------------------------------------------

ExprParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::SignContext::PLUS() {
  return getToken(ExprParser::PLUS, 0);
}

tree::TerminalNode* ExprParser::SignContext::MINUS() {
  return getToken(ExprParser::MINUS, 0);
}


size_t ExprParser::SignContext::getRuleIndex() const {
  return ExprParser::RuleSign;
}


antlrcpp::Any ExprParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::SignContext* ExprParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 28, ExprParser::RuleSign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    _la = _input->LA(1);
    if (!(_la == ExprParser::PLUS

    || _la == ExprParser::MINUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bool_Context ------------------------------------------------------------------

ExprParser::Bool_Context::Bool_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Bool_Context::TRUE() {
  return getToken(ExprParser::TRUE, 0);
}

tree::TerminalNode* ExprParser::Bool_Context::FALSE() {
  return getToken(ExprParser::FALSE, 0);
}


size_t ExprParser::Bool_Context::getRuleIndex() const {
  return ExprParser::RuleBool_;
}


antlrcpp::Any ExprParser::Bool_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitBool_(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Bool_Context* ExprParser::bool_() {
  Bool_Context *_localctx = _tracker.createInstance<Bool_Context>(_ctx, getState());
  enterRule(_localctx, 30, ExprParser::RuleBool_);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    _la = _input->LA(1);
    if (!(_la == ExprParser::TRUE

    || _la == ExprParser::FALSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

ExprParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::StringContext::STRING_LITERAL() {
  return getToken(ExprParser::STRING_LITERAL, 0);
}


size_t ExprParser::StringContext::getRuleIndex() const {
  return ExprParser::RuleString;
}


antlrcpp::Any ExprParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::StringContext* ExprParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 32, ExprParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    match(ExprParser::STRING_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefinitionPartContext ------------------------------------------------------------------

ExprParser::TypeDefinitionPartContext::TypeDefinitionPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::TypeDefinitionPartContext::TYPE() {
  return getToken(ExprParser::TYPE, 0);
}

std::vector<ExprParser::TypeDefinitionContext *> ExprParser::TypeDefinitionPartContext::typeDefinition() {
  return getRuleContexts<ExprParser::TypeDefinitionContext>();
}

ExprParser::TypeDefinitionContext* ExprParser::TypeDefinitionPartContext::typeDefinition(size_t i) {
  return getRuleContext<ExprParser::TypeDefinitionContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::TypeDefinitionPartContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::TypeDefinitionPartContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}


size_t ExprParser::TypeDefinitionPartContext::getRuleIndex() const {
  return ExprParser::RuleTypeDefinitionPart;
}


antlrcpp::Any ExprParser::TypeDefinitionPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitTypeDefinitionPart(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::TypeDefinitionPartContext* ExprParser::typeDefinitionPart() {
  TypeDefinitionPartContext *_localctx = _tracker.createInstance<TypeDefinitionPartContext>(_ctx, getState());
  enterRule(_localctx, 34, ExprParser::RuleTypeDefinitionPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(ExprParser::TYPE);
    setState(301); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(298);
      typeDefinition();
      setState(299);
      match(ExprParser::SEMICOLON);
      setState(303); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ExprParser::IDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefinitionContext ------------------------------------------------------------------

ExprParser::TypeDefinitionContext::TypeDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::IdentifierContext* ExprParser::TypeDefinitionContext::identifier() {
  return getRuleContext<ExprParser::IdentifierContext>(0);
}

tree::TerminalNode* ExprParser::TypeDefinitionContext::EQUAL() {
  return getToken(ExprParser::EQUAL, 0);
}

ExprParser::Type_Context* ExprParser::TypeDefinitionContext::type_() {
  return getRuleContext<ExprParser::Type_Context>(0);
}

ExprParser::FunctionTypeContext* ExprParser::TypeDefinitionContext::functionType() {
  return getRuleContext<ExprParser::FunctionTypeContext>(0);
}

ExprParser::ProcedureTypeContext* ExprParser::TypeDefinitionContext::procedureType() {
  return getRuleContext<ExprParser::ProcedureTypeContext>(0);
}


size_t ExprParser::TypeDefinitionContext::getRuleIndex() const {
  return ExprParser::RuleTypeDefinition;
}


antlrcpp::Any ExprParser::TypeDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitTypeDefinition(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::TypeDefinitionContext* ExprParser::typeDefinition() {
  TypeDefinitionContext *_localctx = _tracker.createInstance<TypeDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 36, ExprParser::RuleTypeDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(305);
    identifier();
    setState(306);
    match(ExprParser::EQUAL);
    setState(310);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::ARRAY:
      case ExprParser::BOOLEAN:
      case ExprParser::CHAR:
      case ExprParser::CHR:
      case ExprParser::FILE:
      case ExprParser::INTEGER:
      case ExprParser::PACKED:
      case ExprParser::REAL:
      case ExprParser::RECORD:
      case ExprParser::SET:
      case ExprParser::PLUS:
      case ExprParser::MINUS:
      case ExprParser::LPAREN:
      case ExprParser::POINTER:
      case ExprParser::STRING:
      case ExprParser::IDENT:
      case ExprParser::STRING_LITERAL:
      case ExprParser::NUM_INT:
      case ExprParser::NUM_REAL: {
        setState(307);
        type_();
        break;
      }

      case ExprParser::FUNCTION: {
        setState(308);
        functionType();
        break;
      }

      case ExprParser::PROCEDURE: {
        setState(309);
        procedureType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionTypeContext ------------------------------------------------------------------

ExprParser::FunctionTypeContext::FunctionTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::FunctionTypeContext::FUNCTION() {
  return getToken(ExprParser::FUNCTION, 0);
}

tree::TerminalNode* ExprParser::FunctionTypeContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

ExprParser::ResultTypeContext* ExprParser::FunctionTypeContext::resultType() {
  return getRuleContext<ExprParser::ResultTypeContext>(0);
}

ExprParser::FormalParameterListContext* ExprParser::FunctionTypeContext::formalParameterList() {
  return getRuleContext<ExprParser::FormalParameterListContext>(0);
}


size_t ExprParser::FunctionTypeContext::getRuleIndex() const {
  return ExprParser::RuleFunctionType;
}


antlrcpp::Any ExprParser::FunctionTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFunctionType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::FunctionTypeContext* ExprParser::functionType() {
  FunctionTypeContext *_localctx = _tracker.createInstance<FunctionTypeContext>(_ctx, getState());
  enterRule(_localctx, 38, ExprParser::RuleFunctionType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    match(ExprParser::FUNCTION);
    setState(314);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::LPAREN) {
      setState(313);
      formalParameterList();
    }
    setState(316);
    match(ExprParser::COLON);
    setState(317);
    resultType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureTypeContext ------------------------------------------------------------------

ExprParser::ProcedureTypeContext::ProcedureTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ProcedureTypeContext::PROCEDURE() {
  return getToken(ExprParser::PROCEDURE, 0);
}

ExprParser::FormalParameterListContext* ExprParser::ProcedureTypeContext::formalParameterList() {
  return getRuleContext<ExprParser::FormalParameterListContext>(0);
}


size_t ExprParser::ProcedureTypeContext::getRuleIndex() const {
  return ExprParser::RuleProcedureType;
}


antlrcpp::Any ExprParser::ProcedureTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProcedureType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProcedureTypeContext* ExprParser::procedureType() {
  ProcedureTypeContext *_localctx = _tracker.createInstance<ProcedureTypeContext>(_ctx, getState());
  enterRule(_localctx, 40, ExprParser::RuleProcedureType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    match(ExprParser::PROCEDURE);
    setState(321);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::LPAREN) {
      setState(320);
      formalParameterList();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_Context ------------------------------------------------------------------

ExprParser::Type_Context::Type_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::SimpleTypeContext* ExprParser::Type_Context::simpleType() {
  return getRuleContext<ExprParser::SimpleTypeContext>(0);
}

ExprParser::StructuredTypeContext* ExprParser::Type_Context::structuredType() {
  return getRuleContext<ExprParser::StructuredTypeContext>(0);
}

ExprParser::PointerTypeContext* ExprParser::Type_Context::pointerType() {
  return getRuleContext<ExprParser::PointerTypeContext>(0);
}


size_t ExprParser::Type_Context::getRuleIndex() const {
  return ExprParser::RuleType_;
}


antlrcpp::Any ExprParser::Type_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitType_(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Type_Context* ExprParser::type_() {
  Type_Context *_localctx = _tracker.createInstance<Type_Context>(_ctx, getState());
  enterRule(_localctx, 42, ExprParser::RuleType_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(326);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::BOOLEAN:
      case ExprParser::CHAR:
      case ExprParser::CHR:
      case ExprParser::INTEGER:
      case ExprParser::REAL:
      case ExprParser::PLUS:
      case ExprParser::MINUS:
      case ExprParser::LPAREN:
      case ExprParser::STRING:
      case ExprParser::IDENT:
      case ExprParser::STRING_LITERAL:
      case ExprParser::NUM_INT:
      case ExprParser::NUM_REAL: {
        enterOuterAlt(_localctx, 1);
        setState(323);
        simpleType();
        break;
      }

      case ExprParser::ARRAY:
      case ExprParser::FILE:
      case ExprParser::PACKED:
      case ExprParser::RECORD:
      case ExprParser::SET: {
        enterOuterAlt(_localctx, 2);
        setState(324);
        structuredType();
        break;
      }

      case ExprParser::POINTER: {
        enterOuterAlt(_localctx, 3);
        setState(325);
        pointerType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleTypeContext ------------------------------------------------------------------

ExprParser::SimpleTypeContext::SimpleTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ScalarTypeContext* ExprParser::SimpleTypeContext::scalarType() {
  return getRuleContext<ExprParser::ScalarTypeContext>(0);
}

ExprParser::SubrangeTypeContext* ExprParser::SimpleTypeContext::subrangeType() {
  return getRuleContext<ExprParser::SubrangeTypeContext>(0);
}

ExprParser::TypeIdentifierContext* ExprParser::SimpleTypeContext::typeIdentifier() {
  return getRuleContext<ExprParser::TypeIdentifierContext>(0);
}

ExprParser::StringtypeContext* ExprParser::SimpleTypeContext::stringtype() {
  return getRuleContext<ExprParser::StringtypeContext>(0);
}


size_t ExprParser::SimpleTypeContext::getRuleIndex() const {
  return ExprParser::RuleSimpleType;
}


antlrcpp::Any ExprParser::SimpleTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSimpleType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::SimpleTypeContext* ExprParser::simpleType() {
  SimpleTypeContext *_localctx = _tracker.createInstance<SimpleTypeContext>(_ctx, getState());
  enterRule(_localctx, 44, ExprParser::RuleSimpleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(332);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(328);
      scalarType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(329);
      subrangeType();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(330);
      typeIdentifier();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(331);
      stringtype();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarTypeContext ------------------------------------------------------------------

ExprParser::ScalarTypeContext::ScalarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ScalarTypeContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

ExprParser::IdentifierListContext* ExprParser::ScalarTypeContext::identifierList() {
  return getRuleContext<ExprParser::IdentifierListContext>(0);
}

tree::TerminalNode* ExprParser::ScalarTypeContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}


size_t ExprParser::ScalarTypeContext::getRuleIndex() const {
  return ExprParser::RuleScalarType;
}


antlrcpp::Any ExprParser::ScalarTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitScalarType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ScalarTypeContext* ExprParser::scalarType() {
  ScalarTypeContext *_localctx = _tracker.createInstance<ScalarTypeContext>(_ctx, getState());
  enterRule(_localctx, 46, ExprParser::RuleScalarType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(334);
    match(ExprParser::LPAREN);
    setState(335);
    identifierList();
    setState(336);
    match(ExprParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubrangeTypeContext ------------------------------------------------------------------

ExprParser::SubrangeTypeContext::SubrangeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::ConstantContext *> ExprParser::SubrangeTypeContext::constant() {
  return getRuleContexts<ExprParser::ConstantContext>();
}

ExprParser::ConstantContext* ExprParser::SubrangeTypeContext::constant(size_t i) {
  return getRuleContext<ExprParser::ConstantContext>(i);
}

tree::TerminalNode* ExprParser::SubrangeTypeContext::DOTDOT() {
  return getToken(ExprParser::DOTDOT, 0);
}


size_t ExprParser::SubrangeTypeContext::getRuleIndex() const {
  return ExprParser::RuleSubrangeType;
}


antlrcpp::Any ExprParser::SubrangeTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSubrangeType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::SubrangeTypeContext* ExprParser::subrangeType() {
  SubrangeTypeContext *_localctx = _tracker.createInstance<SubrangeTypeContext>(_ctx, getState());
  enterRule(_localctx, 48, ExprParser::RuleSubrangeType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    constant();
    setState(339);
    match(ExprParser::DOTDOT);
    setState(340);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeIdentifierContext ------------------------------------------------------------------

ExprParser::TypeIdentifierContext::TypeIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::IdentifierContext* ExprParser::TypeIdentifierContext::identifier() {
  return getRuleContext<ExprParser::IdentifierContext>(0);
}

tree::TerminalNode* ExprParser::TypeIdentifierContext::CHAR() {
  return getToken(ExprParser::CHAR, 0);
}

tree::TerminalNode* ExprParser::TypeIdentifierContext::BOOLEAN() {
  return getToken(ExprParser::BOOLEAN, 0);
}

tree::TerminalNode* ExprParser::TypeIdentifierContext::INTEGER() {
  return getToken(ExprParser::INTEGER, 0);
}

tree::TerminalNode* ExprParser::TypeIdentifierContext::REAL() {
  return getToken(ExprParser::REAL, 0);
}

tree::TerminalNode* ExprParser::TypeIdentifierContext::STRING() {
  return getToken(ExprParser::STRING, 0);
}


size_t ExprParser::TypeIdentifierContext::getRuleIndex() const {
  return ExprParser::RuleTypeIdentifier;
}


antlrcpp::Any ExprParser::TypeIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifier(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::TypeIdentifierContext* ExprParser::typeIdentifier() {
  TypeIdentifierContext *_localctx = _tracker.createInstance<TypeIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 50, ExprParser::RuleTypeIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(344);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(342);
        identifier();
        break;
      }

      case ExprParser::BOOLEAN:
      case ExprParser::CHAR:
      case ExprParser::INTEGER:
      case ExprParser::REAL:
      case ExprParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(343);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << ExprParser::BOOLEAN)
          | (1ULL << ExprParser::CHAR)
          | (1ULL << ExprParser::INTEGER)
          | (1ULL << ExprParser::REAL))) != 0) || _la == ExprParser::STRING)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructuredTypeContext ------------------------------------------------------------------

ExprParser::StructuredTypeContext::StructuredTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::StructuredTypeContext::PACKED() {
  return getToken(ExprParser::PACKED, 0);
}

ExprParser::UnpackedStructuredTypeContext* ExprParser::StructuredTypeContext::unpackedStructuredType() {
  return getRuleContext<ExprParser::UnpackedStructuredTypeContext>(0);
}


size_t ExprParser::StructuredTypeContext::getRuleIndex() const {
  return ExprParser::RuleStructuredType;
}


antlrcpp::Any ExprParser::StructuredTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStructuredType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::StructuredTypeContext* ExprParser::structuredType() {
  StructuredTypeContext *_localctx = _tracker.createInstance<StructuredTypeContext>(_ctx, getState());
  enterRule(_localctx, 52, ExprParser::RuleStructuredType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(349);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::PACKED: {
        enterOuterAlt(_localctx, 1);
        setState(346);
        match(ExprParser::PACKED);
        setState(347);
        unpackedStructuredType();
        break;
      }

      case ExprParser::ARRAY:
      case ExprParser::FILE:
      case ExprParser::RECORD:
      case ExprParser::SET: {
        enterOuterAlt(_localctx, 2);
        setState(348);
        unpackedStructuredType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnpackedStructuredTypeContext ------------------------------------------------------------------

ExprParser::UnpackedStructuredTypeContext::UnpackedStructuredTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ArrayTypeContext* ExprParser::UnpackedStructuredTypeContext::arrayType() {
  return getRuleContext<ExprParser::ArrayTypeContext>(0);
}

ExprParser::RecordTypeContext* ExprParser::UnpackedStructuredTypeContext::recordType() {
  return getRuleContext<ExprParser::RecordTypeContext>(0);
}

ExprParser::SetTypeContext* ExprParser::UnpackedStructuredTypeContext::setType() {
  return getRuleContext<ExprParser::SetTypeContext>(0);
}

ExprParser::FileTypeContext* ExprParser::UnpackedStructuredTypeContext::fileType() {
  return getRuleContext<ExprParser::FileTypeContext>(0);
}


size_t ExprParser::UnpackedStructuredTypeContext::getRuleIndex() const {
  return ExprParser::RuleUnpackedStructuredType;
}


antlrcpp::Any ExprParser::UnpackedStructuredTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitUnpackedStructuredType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::UnpackedStructuredTypeContext* ExprParser::unpackedStructuredType() {
  UnpackedStructuredTypeContext *_localctx = _tracker.createInstance<UnpackedStructuredTypeContext>(_ctx, getState());
  enterRule(_localctx, 54, ExprParser::RuleUnpackedStructuredType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(355);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::ARRAY: {
        enterOuterAlt(_localctx, 1);
        setState(351);
        arrayType();
        break;
      }

      case ExprParser::RECORD: {
        enterOuterAlt(_localctx, 2);
        setState(352);
        recordType();
        break;
      }

      case ExprParser::SET: {
        enterOuterAlt(_localctx, 3);
        setState(353);
        setType();
        break;
      }

      case ExprParser::FILE: {
        enterOuterAlt(_localctx, 4);
        setState(354);
        fileType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringtypeContext ------------------------------------------------------------------

ExprParser::StringtypeContext::StringtypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::StringtypeContext::STRING() {
  return getToken(ExprParser::STRING, 0);
}

tree::TerminalNode* ExprParser::StringtypeContext::LBRACK() {
  return getToken(ExprParser::LBRACK, 0);
}

tree::TerminalNode* ExprParser::StringtypeContext::RBRACK() {
  return getToken(ExprParser::RBRACK, 0);
}

ExprParser::IdentifierContext* ExprParser::StringtypeContext::identifier() {
  return getRuleContext<ExprParser::IdentifierContext>(0);
}

ExprParser::UnsignedNumberContext* ExprParser::StringtypeContext::unsignedNumber() {
  return getRuleContext<ExprParser::UnsignedNumberContext>(0);
}


size_t ExprParser::StringtypeContext::getRuleIndex() const {
  return ExprParser::RuleStringtype;
}


antlrcpp::Any ExprParser::StringtypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStringtype(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::StringtypeContext* ExprParser::stringtype() {
  StringtypeContext *_localctx = _tracker.createInstance<StringtypeContext>(_ctx, getState());
  enterRule(_localctx, 56, ExprParser::RuleStringtype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(ExprParser::STRING);
    setState(358);
    match(ExprParser::LBRACK);
    setState(361);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::IDENT: {
        setState(359);
        identifier();
        break;
      }

      case ExprParser::NUM_INT:
      case ExprParser::NUM_REAL: {
        setState(360);
        unsignedNumber();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(363);
    match(ExprParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

ExprParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ArrayTypeContext::ARRAY() {
  return getToken(ExprParser::ARRAY, 0);
}

tree::TerminalNode* ExprParser::ArrayTypeContext::LBRACK() {
  return getToken(ExprParser::LBRACK, 0);
}

ExprParser::TypeListContext* ExprParser::ArrayTypeContext::typeList() {
  return getRuleContext<ExprParser::TypeListContext>(0);
}

tree::TerminalNode* ExprParser::ArrayTypeContext::RBRACK() {
  return getToken(ExprParser::RBRACK, 0);
}

tree::TerminalNode* ExprParser::ArrayTypeContext::OF() {
  return getToken(ExprParser::OF, 0);
}

ExprParser::ComponentTypeContext* ExprParser::ArrayTypeContext::componentType() {
  return getRuleContext<ExprParser::ComponentTypeContext>(0);
}

tree::TerminalNode* ExprParser::ArrayTypeContext::LBRACK2() {
  return getToken(ExprParser::LBRACK2, 0);
}

tree::TerminalNode* ExprParser::ArrayTypeContext::RBRACK2() {
  return getToken(ExprParser::RBRACK2, 0);
}


size_t ExprParser::ArrayTypeContext::getRuleIndex() const {
  return ExprParser::RuleArrayType;
}


antlrcpp::Any ExprParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ArrayTypeContext* ExprParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 58, ExprParser::RuleArrayType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(379);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(365);
      match(ExprParser::ARRAY);
      setState(366);
      match(ExprParser::LBRACK);
      setState(367);
      typeList();
      setState(368);
      match(ExprParser::RBRACK);
      setState(369);
      match(ExprParser::OF);
      setState(370);
      componentType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(372);
      match(ExprParser::ARRAY);
      setState(373);
      match(ExprParser::LBRACK2);
      setState(374);
      typeList();
      setState(375);
      match(ExprParser::RBRACK2);
      setState(376);
      match(ExprParser::OF);
      setState(377);
      componentType();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeListContext ------------------------------------------------------------------

ExprParser::TypeListContext::TypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::IndexTypeContext *> ExprParser::TypeListContext::indexType() {
  return getRuleContexts<ExprParser::IndexTypeContext>();
}

ExprParser::IndexTypeContext* ExprParser::TypeListContext::indexType(size_t i) {
  return getRuleContext<ExprParser::IndexTypeContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::TypeListContext::COMMA() {
  return getTokens(ExprParser::COMMA);
}

tree::TerminalNode* ExprParser::TypeListContext::COMMA(size_t i) {
  return getToken(ExprParser::COMMA, i);
}


size_t ExprParser::TypeListContext::getRuleIndex() const {
  return ExprParser::RuleTypeList;
}


antlrcpp::Any ExprParser::TypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitTypeList(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::TypeListContext* ExprParser::typeList() {
  TypeListContext *_localctx = _tracker.createInstance<TypeListContext>(_ctx, getState());
  enterRule(_localctx, 60, ExprParser::RuleTypeList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(381);
    indexType();
    setState(386);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::COMMA) {
      setState(382);
      match(ExprParser::COMMA);
      setState(383);
      indexType();
      setState(388);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexTypeContext ------------------------------------------------------------------

ExprParser::IndexTypeContext::IndexTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::SimpleTypeContext* ExprParser::IndexTypeContext::simpleType() {
  return getRuleContext<ExprParser::SimpleTypeContext>(0);
}


size_t ExprParser::IndexTypeContext::getRuleIndex() const {
  return ExprParser::RuleIndexType;
}


antlrcpp::Any ExprParser::IndexTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitIndexType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::IndexTypeContext* ExprParser::indexType() {
  IndexTypeContext *_localctx = _tracker.createInstance<IndexTypeContext>(_ctx, getState());
  enterRule(_localctx, 62, ExprParser::RuleIndexType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(389);
    simpleType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComponentTypeContext ------------------------------------------------------------------

ExprParser::ComponentTypeContext::ComponentTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::Type_Context* ExprParser::ComponentTypeContext::type_() {
  return getRuleContext<ExprParser::Type_Context>(0);
}


size_t ExprParser::ComponentTypeContext::getRuleIndex() const {
  return ExprParser::RuleComponentType;
}


antlrcpp::Any ExprParser::ComponentTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitComponentType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ComponentTypeContext* ExprParser::componentType() {
  ComponentTypeContext *_localctx = _tracker.createInstance<ComponentTypeContext>(_ctx, getState());
  enterRule(_localctx, 64, ExprParser::RuleComponentType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(391);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RecordTypeContext ------------------------------------------------------------------

ExprParser::RecordTypeContext::RecordTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::RecordTypeContext::RECORD() {
  return getToken(ExprParser::RECORD, 0);
}

tree::TerminalNode* ExprParser::RecordTypeContext::END() {
  return getToken(ExprParser::END, 0);
}

ExprParser::FieldListContext* ExprParser::RecordTypeContext::fieldList() {
  return getRuleContext<ExprParser::FieldListContext>(0);
}


size_t ExprParser::RecordTypeContext::getRuleIndex() const {
  return ExprParser::RuleRecordType;
}


antlrcpp::Any ExprParser::RecordTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitRecordType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::RecordTypeContext* ExprParser::recordType() {
  RecordTypeContext *_localctx = _tracker.createInstance<RecordTypeContext>(_ctx, getState());
  enterRule(_localctx, 66, ExprParser::RuleRecordType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    match(ExprParser::RECORD);
    setState(395);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::CASE || _la == ExprParser::IDENT) {
      setState(394);
      fieldList();
    }
    setState(397);
    match(ExprParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldListContext ------------------------------------------------------------------

ExprParser::FieldListContext::FieldListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::FixedPartContext* ExprParser::FieldListContext::fixedPart() {
  return getRuleContext<ExprParser::FixedPartContext>(0);
}

tree::TerminalNode* ExprParser::FieldListContext::SEMICOLON() {
  return getToken(ExprParser::SEMICOLON, 0);
}

ExprParser::VariantPartContext* ExprParser::FieldListContext::variantPart() {
  return getRuleContext<ExprParser::VariantPartContext>(0);
}


size_t ExprParser::FieldListContext::getRuleIndex() const {
  return ExprParser::RuleFieldList;
}


antlrcpp::Any ExprParser::FieldListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFieldList(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::FieldListContext* ExprParser::fieldList() {
  FieldListContext *_localctx = _tracker.createInstance<FieldListContext>(_ctx, getState());
  enterRule(_localctx, 68, ExprParser::RuleFieldList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(405);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(399);
        fixedPart();
        setState(402);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ExprParser::SEMICOLON) {
          setState(400);
          match(ExprParser::SEMICOLON);
          setState(401);
          variantPart();
        }
        break;
      }

      case ExprParser::CASE: {
        enterOuterAlt(_localctx, 2);
        setState(404);
        variantPart();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FixedPartContext ------------------------------------------------------------------

ExprParser::FixedPartContext::FixedPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::RecordSectionContext *> ExprParser::FixedPartContext::recordSection() {
  return getRuleContexts<ExprParser::RecordSectionContext>();
}

ExprParser::RecordSectionContext* ExprParser::FixedPartContext::recordSection(size_t i) {
  return getRuleContext<ExprParser::RecordSectionContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::FixedPartContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::FixedPartContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}


size_t ExprParser::FixedPartContext::getRuleIndex() const {
  return ExprParser::RuleFixedPart;
}


antlrcpp::Any ExprParser::FixedPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFixedPart(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::FixedPartContext* ExprParser::fixedPart() {
  FixedPartContext *_localctx = _tracker.createInstance<FixedPartContext>(_ctx, getState());
  enterRule(_localctx, 70, ExprParser::RuleFixedPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(407);
    recordSection();
    setState(412);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(408);
        match(ExprParser::SEMICOLON);
        setState(409);
        recordSection(); 
      }
      setState(414);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RecordSectionContext ------------------------------------------------------------------

ExprParser::RecordSectionContext::RecordSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::IdentifierListContext* ExprParser::RecordSectionContext::identifierList() {
  return getRuleContext<ExprParser::IdentifierListContext>(0);
}

tree::TerminalNode* ExprParser::RecordSectionContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

ExprParser::Type_Context* ExprParser::RecordSectionContext::type_() {
  return getRuleContext<ExprParser::Type_Context>(0);
}


size_t ExprParser::RecordSectionContext::getRuleIndex() const {
  return ExprParser::RuleRecordSection;
}


antlrcpp::Any ExprParser::RecordSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitRecordSection(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::RecordSectionContext* ExprParser::recordSection() {
  RecordSectionContext *_localctx = _tracker.createInstance<RecordSectionContext>(_ctx, getState());
  enterRule(_localctx, 72, ExprParser::RuleRecordSection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(415);
    identifierList();
    setState(416);
    match(ExprParser::COLON);
    setState(417);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariantPartContext ------------------------------------------------------------------

ExprParser::VariantPartContext::VariantPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::VariantPartContext::CASE() {
  return getToken(ExprParser::CASE, 0);
}

ExprParser::TagContext* ExprParser::VariantPartContext::tag() {
  return getRuleContext<ExprParser::TagContext>(0);
}

tree::TerminalNode* ExprParser::VariantPartContext::OF() {
  return getToken(ExprParser::OF, 0);
}

std::vector<ExprParser::VariantContext *> ExprParser::VariantPartContext::variant() {
  return getRuleContexts<ExprParser::VariantContext>();
}

ExprParser::VariantContext* ExprParser::VariantPartContext::variant(size_t i) {
  return getRuleContext<ExprParser::VariantContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::VariantPartContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::VariantPartContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}


size_t ExprParser::VariantPartContext::getRuleIndex() const {
  return ExprParser::RuleVariantPart;
}


antlrcpp::Any ExprParser::VariantPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariantPart(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::VariantPartContext* ExprParser::variantPart() {
  VariantPartContext *_localctx = _tracker.createInstance<VariantPartContext>(_ctx, getState());
  enterRule(_localctx, 74, ExprParser::RuleVariantPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(419);
    match(ExprParser::CASE);
    setState(420);
    tag();
    setState(421);
    match(ExprParser::OF);
    setState(422);
    variant();
    setState(427);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::SEMICOLON) {
      setState(423);
      match(ExprParser::SEMICOLON);
      setState(424);
      variant();
      setState(429);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TagContext ------------------------------------------------------------------

ExprParser::TagContext::TagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::IdentifierContext* ExprParser::TagContext::identifier() {
  return getRuleContext<ExprParser::IdentifierContext>(0);
}

tree::TerminalNode* ExprParser::TagContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

ExprParser::TypeIdentifierContext* ExprParser::TagContext::typeIdentifier() {
  return getRuleContext<ExprParser::TypeIdentifierContext>(0);
}


size_t ExprParser::TagContext::getRuleIndex() const {
  return ExprParser::RuleTag;
}


antlrcpp::Any ExprParser::TagContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitTag(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::TagContext* ExprParser::tag() {
  TagContext *_localctx = _tracker.createInstance<TagContext>(_ctx, getState());
  enterRule(_localctx, 76, ExprParser::RuleTag);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(435);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(430);
      identifier();
      setState(431);
      match(ExprParser::COLON);
      setState(432);
      typeIdentifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(434);
      typeIdentifier();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariantContext ------------------------------------------------------------------

ExprParser::VariantContext::VariantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ConstListContext* ExprParser::VariantContext::constList() {
  return getRuleContext<ExprParser::ConstListContext>(0);
}

tree::TerminalNode* ExprParser::VariantContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

tree::TerminalNode* ExprParser::VariantContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

ExprParser::FieldListContext* ExprParser::VariantContext::fieldList() {
  return getRuleContext<ExprParser::FieldListContext>(0);
}

tree::TerminalNode* ExprParser::VariantContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}


size_t ExprParser::VariantContext::getRuleIndex() const {
  return ExprParser::RuleVariant;
}


antlrcpp::Any ExprParser::VariantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariant(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::VariantContext* ExprParser::variant() {
  VariantContext *_localctx = _tracker.createInstance<VariantContext>(_ctx, getState());
  enterRule(_localctx, 78, ExprParser::RuleVariant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(437);
    constList();
    setState(438);
    match(ExprParser::COLON);
    setState(439);
    match(ExprParser::LPAREN);
    setState(440);
    fieldList();
    setState(441);
    match(ExprParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetTypeContext ------------------------------------------------------------------

ExprParser::SetTypeContext::SetTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::SetTypeContext::SET() {
  return getToken(ExprParser::SET, 0);
}

tree::TerminalNode* ExprParser::SetTypeContext::OF() {
  return getToken(ExprParser::OF, 0);
}

ExprParser::BaseTypeContext* ExprParser::SetTypeContext::baseType() {
  return getRuleContext<ExprParser::BaseTypeContext>(0);
}


size_t ExprParser::SetTypeContext::getRuleIndex() const {
  return ExprParser::RuleSetType;
}


antlrcpp::Any ExprParser::SetTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSetType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::SetTypeContext* ExprParser::setType() {
  SetTypeContext *_localctx = _tracker.createInstance<SetTypeContext>(_ctx, getState());
  enterRule(_localctx, 80, ExprParser::RuleSetType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(443);
    match(ExprParser::SET);
    setState(444);
    match(ExprParser::OF);
    setState(445);
    baseType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseTypeContext ------------------------------------------------------------------

ExprParser::BaseTypeContext::BaseTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::SimpleTypeContext* ExprParser::BaseTypeContext::simpleType() {
  return getRuleContext<ExprParser::SimpleTypeContext>(0);
}


size_t ExprParser::BaseTypeContext::getRuleIndex() const {
  return ExprParser::RuleBaseType;
}


antlrcpp::Any ExprParser::BaseTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitBaseType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::BaseTypeContext* ExprParser::baseType() {
  BaseTypeContext *_localctx = _tracker.createInstance<BaseTypeContext>(_ctx, getState());
  enterRule(_localctx, 82, ExprParser::RuleBaseType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(447);
    simpleType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FileTypeContext ------------------------------------------------------------------

ExprParser::FileTypeContext::FileTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::FileTypeContext::FILE() {
  return getToken(ExprParser::FILE, 0);
}

tree::TerminalNode* ExprParser::FileTypeContext::OF() {
  return getToken(ExprParser::OF, 0);
}

ExprParser::Type_Context* ExprParser::FileTypeContext::type_() {
  return getRuleContext<ExprParser::Type_Context>(0);
}


size_t ExprParser::FileTypeContext::getRuleIndex() const {
  return ExprParser::RuleFileType;
}


antlrcpp::Any ExprParser::FileTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFileType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::FileTypeContext* ExprParser::fileType() {
  FileTypeContext *_localctx = _tracker.createInstance<FileTypeContext>(_ctx, getState());
  enterRule(_localctx, 84, ExprParser::RuleFileType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(453);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(449);
      match(ExprParser::FILE);
      setState(450);
      match(ExprParser::OF);
      setState(451);
      type_();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(452);
      match(ExprParser::FILE);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PointerTypeContext ------------------------------------------------------------------

ExprParser::PointerTypeContext::PointerTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::PointerTypeContext::POINTER() {
  return getToken(ExprParser::POINTER, 0);
}

ExprParser::TypeIdentifierContext* ExprParser::PointerTypeContext::typeIdentifier() {
  return getRuleContext<ExprParser::TypeIdentifierContext>(0);
}


size_t ExprParser::PointerTypeContext::getRuleIndex() const {
  return ExprParser::RulePointerType;
}


antlrcpp::Any ExprParser::PointerTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitPointerType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::PointerTypeContext* ExprParser::pointerType() {
  PointerTypeContext *_localctx = _tracker.createInstance<PointerTypeContext>(_ctx, getState());
  enterRule(_localctx, 86, ExprParser::RulePointerType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(455);
    match(ExprParser::POINTER);
    setState(456);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationPartContext ------------------------------------------------------------------

ExprParser::VariableDeclarationPartContext::VariableDeclarationPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::VariableDeclarationPartContext::VAR() {
  return getToken(ExprParser::VAR, 0);
}

std::vector<ExprParser::VariableDeclarationContext *> ExprParser::VariableDeclarationPartContext::variableDeclaration() {
  return getRuleContexts<ExprParser::VariableDeclarationContext>();
}

ExprParser::VariableDeclarationContext* ExprParser::VariableDeclarationPartContext::variableDeclaration(size_t i) {
  return getRuleContext<ExprParser::VariableDeclarationContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::VariableDeclarationPartContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::VariableDeclarationPartContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}


size_t ExprParser::VariableDeclarationPartContext::getRuleIndex() const {
  return ExprParser::RuleVariableDeclarationPart;
}


antlrcpp::Any ExprParser::VariableDeclarationPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationPart(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::VariableDeclarationPartContext* ExprParser::variableDeclarationPart() {
  VariableDeclarationPartContext *_localctx = _tracker.createInstance<VariableDeclarationPartContext>(_ctx, getState());
  enterRule(_localctx, 88, ExprParser::RuleVariableDeclarationPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(458);
    match(ExprParser::VAR);
    setState(459);
    variableDeclaration();
    setState(464);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(460);
        match(ExprParser::SEMICOLON);
        setState(461);
        variableDeclaration(); 
      }
      setState(466);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
    setState(467);
    match(ExprParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

ExprParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::IdentifierListContext* ExprParser::VariableDeclarationContext::identifierList() {
  return getRuleContext<ExprParser::IdentifierListContext>(0);
}

tree::TerminalNode* ExprParser::VariableDeclarationContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

ExprParser::Type_Context* ExprParser::VariableDeclarationContext::type_() {
  return getRuleContext<ExprParser::Type_Context>(0);
}


size_t ExprParser::VariableDeclarationContext::getRuleIndex() const {
  return ExprParser::RuleVariableDeclaration;
}


antlrcpp::Any ExprParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::VariableDeclarationContext* ExprParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 90, ExprParser::RuleVariableDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(469);
    identifierList();
    setState(470);
    match(ExprParser::COLON);
    setState(471);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureAndFunctionDeclarationPartContext ------------------------------------------------------------------

ExprParser::ProcedureAndFunctionDeclarationPartContext::ProcedureAndFunctionDeclarationPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ProcedureOrFunctionDeclarationContext* ExprParser::ProcedureAndFunctionDeclarationPartContext::procedureOrFunctionDeclaration() {
  return getRuleContext<ExprParser::ProcedureOrFunctionDeclarationContext>(0);
}

tree::TerminalNode* ExprParser::ProcedureAndFunctionDeclarationPartContext::SEMICOLON() {
  return getToken(ExprParser::SEMICOLON, 0);
}


size_t ExprParser::ProcedureAndFunctionDeclarationPartContext::getRuleIndex() const {
  return ExprParser::RuleProcedureAndFunctionDeclarationPart;
}


antlrcpp::Any ExprParser::ProcedureAndFunctionDeclarationPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProcedureAndFunctionDeclarationPart(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProcedureAndFunctionDeclarationPartContext* ExprParser::procedureAndFunctionDeclarationPart() {
  ProcedureAndFunctionDeclarationPartContext *_localctx = _tracker.createInstance<ProcedureAndFunctionDeclarationPartContext>(_ctx, getState());
  enterRule(_localctx, 92, ExprParser::RuleProcedureAndFunctionDeclarationPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(473);
    procedureOrFunctionDeclaration();
    setState(474);
    match(ExprParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureOrFunctionDeclarationContext ------------------------------------------------------------------

ExprParser::ProcedureOrFunctionDeclarationContext::ProcedureOrFunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ProcedureDeclarationContext* ExprParser::ProcedureOrFunctionDeclarationContext::procedureDeclaration() {
  return getRuleContext<ExprParser::ProcedureDeclarationContext>(0);
}

ExprParser::FunctionDeclarationContext* ExprParser::ProcedureOrFunctionDeclarationContext::functionDeclaration() {
  return getRuleContext<ExprParser::FunctionDeclarationContext>(0);
}


size_t ExprParser::ProcedureOrFunctionDeclarationContext::getRuleIndex() const {
  return ExprParser::RuleProcedureOrFunctionDeclaration;
}


antlrcpp::Any ExprParser::ProcedureOrFunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProcedureOrFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProcedureOrFunctionDeclarationContext* ExprParser::procedureOrFunctionDeclaration() {
  ProcedureOrFunctionDeclarationContext *_localctx = _tracker.createInstance<ProcedureOrFunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 94, ExprParser::RuleProcedureOrFunctionDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(478);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::PROCEDURE: {
        enterOuterAlt(_localctx, 1);
        setState(476);
        procedureDeclaration();
        break;
      }

      case ExprParser::FUNCTION: {
        enterOuterAlt(_localctx, 2);
        setState(477);
        functionDeclaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureDeclarationContext ------------------------------------------------------------------

ExprParser::ProcedureDeclarationContext::ProcedureDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ProcedureDeclarationContext::PROCEDURE() {
  return getToken(ExprParser::PROCEDURE, 0);
}

ExprParser::IdentifierContext* ExprParser::ProcedureDeclarationContext::identifier() {
  return getRuleContext<ExprParser::IdentifierContext>(0);
}

tree::TerminalNode* ExprParser::ProcedureDeclarationContext::SEMICOLON() {
  return getToken(ExprParser::SEMICOLON, 0);
}

ExprParser::BlockContext* ExprParser::ProcedureDeclarationContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}

ExprParser::FormalParameterListContext* ExprParser::ProcedureDeclarationContext::formalParameterList() {
  return getRuleContext<ExprParser::FormalParameterListContext>(0);
}


size_t ExprParser::ProcedureDeclarationContext::getRuleIndex() const {
  return ExprParser::RuleProcedureDeclaration;
}


antlrcpp::Any ExprParser::ProcedureDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProcedureDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProcedureDeclarationContext* ExprParser::procedureDeclaration() {
  ProcedureDeclarationContext *_localctx = _tracker.createInstance<ProcedureDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 96, ExprParser::RuleProcedureDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(480);
    match(ExprParser::PROCEDURE);
    setState(481);
    identifier();
    setState(483);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::LPAREN) {
      setState(482);
      formalParameterList();
    }
    setState(485);
    match(ExprParser::SEMICOLON);
    setState(486);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterListContext ------------------------------------------------------------------

ExprParser::FormalParameterListContext::FormalParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::FormalParameterListContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

std::vector<ExprParser::FormalParameterSectionContext *> ExprParser::FormalParameterListContext::formalParameterSection() {
  return getRuleContexts<ExprParser::FormalParameterSectionContext>();
}

ExprParser::FormalParameterSectionContext* ExprParser::FormalParameterListContext::formalParameterSection(size_t i) {
  return getRuleContext<ExprParser::FormalParameterSectionContext>(i);
}

tree::TerminalNode* ExprParser::FormalParameterListContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> ExprParser::FormalParameterListContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::FormalParameterListContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}


size_t ExprParser::FormalParameterListContext::getRuleIndex() const {
  return ExprParser::RuleFormalParameterList;
}


antlrcpp::Any ExprParser::FormalParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFormalParameterList(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::FormalParameterListContext* ExprParser::formalParameterList() {
  FormalParameterListContext *_localctx = _tracker.createInstance<FormalParameterListContext>(_ctx, getState());
  enterRule(_localctx, 98, ExprParser::RuleFormalParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(488);
    match(ExprParser::LPAREN);
    setState(489);
    formalParameterSection();
    setState(494);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::SEMICOLON) {
      setState(490);
      match(ExprParser::SEMICOLON);
      setState(491);
      formalParameterSection();
      setState(496);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(497);
    match(ExprParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterSectionContext ------------------------------------------------------------------

ExprParser::FormalParameterSectionContext::FormalParameterSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ParameterGroupContext* ExprParser::FormalParameterSectionContext::parameterGroup() {
  return getRuleContext<ExprParser::ParameterGroupContext>(0);
}

tree::TerminalNode* ExprParser::FormalParameterSectionContext::VAR() {
  return getToken(ExprParser::VAR, 0);
}

tree::TerminalNode* ExprParser::FormalParameterSectionContext::FUNCTION() {
  return getToken(ExprParser::FUNCTION, 0);
}

tree::TerminalNode* ExprParser::FormalParameterSectionContext::PROCEDURE() {
  return getToken(ExprParser::PROCEDURE, 0);
}


size_t ExprParser::FormalParameterSectionContext::getRuleIndex() const {
  return ExprParser::RuleFormalParameterSection;
}


antlrcpp::Any ExprParser::FormalParameterSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFormalParameterSection(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::FormalParameterSectionContext* ExprParser::formalParameterSection() {
  FormalParameterSectionContext *_localctx = _tracker.createInstance<FormalParameterSectionContext>(_ctx, getState());
  enterRule(_localctx, 100, ExprParser::RuleFormalParameterSection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(506);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(499);
        parameterGroup();
        break;
      }

      case ExprParser::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(500);
        match(ExprParser::VAR);
        setState(501);
        parameterGroup();
        break;
      }

      case ExprParser::FUNCTION: {
        enterOuterAlt(_localctx, 3);
        setState(502);
        match(ExprParser::FUNCTION);
        setState(503);
        parameterGroup();
        break;
      }

      case ExprParser::PROCEDURE: {
        enterOuterAlt(_localctx, 4);
        setState(504);
        match(ExprParser::PROCEDURE);
        setState(505);
        parameterGroup();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterGroupContext ------------------------------------------------------------------

ExprParser::ParameterGroupContext::ParameterGroupContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::IdentifierListContext* ExprParser::ParameterGroupContext::identifierList() {
  return getRuleContext<ExprParser::IdentifierListContext>(0);
}

tree::TerminalNode* ExprParser::ParameterGroupContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

ExprParser::TypeIdentifierContext* ExprParser::ParameterGroupContext::typeIdentifier() {
  return getRuleContext<ExprParser::TypeIdentifierContext>(0);
}


size_t ExprParser::ParameterGroupContext::getRuleIndex() const {
  return ExprParser::RuleParameterGroup;
}


antlrcpp::Any ExprParser::ParameterGroupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitParameterGroup(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ParameterGroupContext* ExprParser::parameterGroup() {
  ParameterGroupContext *_localctx = _tracker.createInstance<ParameterGroupContext>(_ctx, getState());
  enterRule(_localctx, 102, ExprParser::RuleParameterGroup);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(508);
    identifierList();
    setState(509);
    match(ExprParser::COLON);
    setState(510);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

ExprParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::IdentifierContext *> ExprParser::IdentifierListContext::identifier() {
  return getRuleContexts<ExprParser::IdentifierContext>();
}

ExprParser::IdentifierContext* ExprParser::IdentifierListContext::identifier(size_t i) {
  return getRuleContext<ExprParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::IdentifierListContext::COMMA() {
  return getTokens(ExprParser::COMMA);
}

tree::TerminalNode* ExprParser::IdentifierListContext::COMMA(size_t i) {
  return getToken(ExprParser::COMMA, i);
}


size_t ExprParser::IdentifierListContext::getRuleIndex() const {
  return ExprParser::RuleIdentifierList;
}


antlrcpp::Any ExprParser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::IdentifierListContext* ExprParser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 104, ExprParser::RuleIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(512);
    identifier();
    setState(517);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::COMMA) {
      setState(513);
      match(ExprParser::COMMA);
      setState(514);
      identifier();
      setState(519);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstListContext ------------------------------------------------------------------

ExprParser::ConstListContext::ConstListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::ConstantContext *> ExprParser::ConstListContext::constant() {
  return getRuleContexts<ExprParser::ConstantContext>();
}

ExprParser::ConstantContext* ExprParser::ConstListContext::constant(size_t i) {
  return getRuleContext<ExprParser::ConstantContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::ConstListContext::COMMA() {
  return getTokens(ExprParser::COMMA);
}

tree::TerminalNode* ExprParser::ConstListContext::COMMA(size_t i) {
  return getToken(ExprParser::COMMA, i);
}


size_t ExprParser::ConstListContext::getRuleIndex() const {
  return ExprParser::RuleConstList;
}


antlrcpp::Any ExprParser::ConstListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitConstList(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ConstListContext* ExprParser::constList() {
  ConstListContext *_localctx = _tracker.createInstance<ConstListContext>(_ctx, getState());
  enterRule(_localctx, 106, ExprParser::RuleConstList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(520);
    constant();
    setState(525);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::COMMA) {
      setState(521);
      match(ExprParser::COMMA);
      setState(522);
      constant();
      setState(527);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

ExprParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::FunctionDeclarationContext::FUNCTION() {
  return getToken(ExprParser::FUNCTION, 0);
}

ExprParser::IdentifierContext* ExprParser::FunctionDeclarationContext::identifier() {
  return getRuleContext<ExprParser::IdentifierContext>(0);
}

tree::TerminalNode* ExprParser::FunctionDeclarationContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

ExprParser::ResultTypeContext* ExprParser::FunctionDeclarationContext::resultType() {
  return getRuleContext<ExprParser::ResultTypeContext>(0);
}

tree::TerminalNode* ExprParser::FunctionDeclarationContext::SEMICOLON() {
  return getToken(ExprParser::SEMICOLON, 0);
}

ExprParser::BlockContext* ExprParser::FunctionDeclarationContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}

ExprParser::FormalParameterListContext* ExprParser::FunctionDeclarationContext::formalParameterList() {
  return getRuleContext<ExprParser::FormalParameterListContext>(0);
}


size_t ExprParser::FunctionDeclarationContext::getRuleIndex() const {
  return ExprParser::RuleFunctionDeclaration;
}


antlrcpp::Any ExprParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::FunctionDeclarationContext* ExprParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 108, ExprParser::RuleFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(528);
    match(ExprParser::FUNCTION);
    setState(529);
    identifier();
    setState(531);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::LPAREN) {
      setState(530);
      formalParameterList();
    }
    setState(533);
    match(ExprParser::COLON);
    setState(534);
    resultType();
    setState(535);
    match(ExprParser::SEMICOLON);
    setState(536);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResultTypeContext ------------------------------------------------------------------

ExprParser::ResultTypeContext::ResultTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::TypeIdentifierContext* ExprParser::ResultTypeContext::typeIdentifier() {
  return getRuleContext<ExprParser::TypeIdentifierContext>(0);
}


size_t ExprParser::ResultTypeContext::getRuleIndex() const {
  return ExprParser::RuleResultType;
}


antlrcpp::Any ExprParser::ResultTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitResultType(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ResultTypeContext* ExprParser::resultType() {
  ResultTypeContext *_localctx = _tracker.createInstance<ResultTypeContext>(_ctx, getState());
  enterRule(_localctx, 110, ExprParser::RuleResultType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(538);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ExprParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::LabelContext* ExprParser::StatementContext::label() {
  return getRuleContext<ExprParser::LabelContext>(0);
}

tree::TerminalNode* ExprParser::StatementContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

ExprParser::UnlabelledStatementContext* ExprParser::StatementContext::unlabelledStatement() {
  return getRuleContext<ExprParser::UnlabelledStatementContext>(0);
}


size_t ExprParser::StatementContext::getRuleIndex() const {
  return ExprParser::RuleStatement;
}


antlrcpp::Any ExprParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::StatementContext* ExprParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 112, ExprParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(545);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::NUM_INT: {
        enterOuterAlt(_localctx, 1);
        setState(540);
        label();
        setState(541);
        match(ExprParser::COLON);
        setState(542);
        unlabelledStatement();
        break;
      }

      case ExprParser::BEGIN:
      case ExprParser::CASE:
      case ExprParser::ELSE:
      case ExprParser::END:
      case ExprParser::FOR:
      case ExprParser::GOTO:
      case ExprParser::IF:
      case ExprParser::REPEAT:
      case ExprParser::UNTIL:
      case ExprParser::WHILE:
      case ExprParser::WITH:
      case ExprParser::SEMICOLON:
      case ExprParser::AT:
      case ExprParser::IDENT: {
        enterOuterAlt(_localctx, 2);
        setState(544);
        unlabelledStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnlabelledStatementContext ------------------------------------------------------------------

ExprParser::UnlabelledStatementContext::UnlabelledStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::SimpleStatementContext* ExprParser::UnlabelledStatementContext::simpleStatement() {
  return getRuleContext<ExprParser::SimpleStatementContext>(0);
}

ExprParser::StructuredStatementContext* ExprParser::UnlabelledStatementContext::structuredStatement() {
  return getRuleContext<ExprParser::StructuredStatementContext>(0);
}


size_t ExprParser::UnlabelledStatementContext::getRuleIndex() const {
  return ExprParser::RuleUnlabelledStatement;
}


antlrcpp::Any ExprParser::UnlabelledStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitUnlabelledStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::UnlabelledStatementContext* ExprParser::unlabelledStatement() {
  UnlabelledStatementContext *_localctx = _tracker.createInstance<UnlabelledStatementContext>(_ctx, getState());
  enterRule(_localctx, 114, ExprParser::RuleUnlabelledStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(549);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::ELSE:
      case ExprParser::END:
      case ExprParser::GOTO:
      case ExprParser::UNTIL:
      case ExprParser::SEMICOLON:
      case ExprParser::AT:
      case ExprParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(547);
        simpleStatement();
        break;
      }

      case ExprParser::BEGIN:
      case ExprParser::CASE:
      case ExprParser::FOR:
      case ExprParser::IF:
      case ExprParser::REPEAT:
      case ExprParser::WHILE:
      case ExprParser::WITH: {
        enterOuterAlt(_localctx, 2);
        setState(548);
        structuredStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleStatementContext ------------------------------------------------------------------

ExprParser::SimpleStatementContext::SimpleStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::AssignmentStatementContext* ExprParser::SimpleStatementContext::assignmentStatement() {
  return getRuleContext<ExprParser::AssignmentStatementContext>(0);
}

ExprParser::ProcedureStatementContext* ExprParser::SimpleStatementContext::procedureStatement() {
  return getRuleContext<ExprParser::ProcedureStatementContext>(0);
}

ExprParser::GotoStatementContext* ExprParser::SimpleStatementContext::gotoStatement() {
  return getRuleContext<ExprParser::GotoStatementContext>(0);
}

ExprParser::EmptyStatement_Context* ExprParser::SimpleStatementContext::emptyStatement_() {
  return getRuleContext<ExprParser::EmptyStatement_Context>(0);
}


size_t ExprParser::SimpleStatementContext::getRuleIndex() const {
  return ExprParser::RuleSimpleStatement;
}


antlrcpp::Any ExprParser::SimpleStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSimpleStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::SimpleStatementContext* ExprParser::simpleStatement() {
  SimpleStatementContext *_localctx = _tracker.createInstance<SimpleStatementContext>(_ctx, getState());
  enterRule(_localctx, 116, ExprParser::RuleSimpleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(555);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(551);
      assignmentStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(552);
      procedureStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(553);
      gotoStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(554);
      emptyStatement_();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

ExprParser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::VariableContext* ExprParser::AssignmentStatementContext::variable() {
  return getRuleContext<ExprParser::VariableContext>(0);
}

tree::TerminalNode* ExprParser::AssignmentStatementContext::ASSIGN() {
  return getToken(ExprParser::ASSIGN, 0);
}

ExprParser::ExpressionContext* ExprParser::AssignmentStatementContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}


size_t ExprParser::AssignmentStatementContext::getRuleIndex() const {
  return ExprParser::RuleAssignmentStatement;
}


antlrcpp::Any ExprParser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::AssignmentStatementContext* ExprParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 118, ExprParser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(557);
    variable();
    setState(558);
    match(ExprParser::ASSIGN);
    setState(559);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

ExprParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::VariableContext::AT() {
  return getToken(ExprParser::AT, 0);
}

std::vector<ExprParser::IdentifierContext *> ExprParser::VariableContext::identifier() {
  return getRuleContexts<ExprParser::IdentifierContext>();
}

ExprParser::IdentifierContext* ExprParser::VariableContext::identifier(size_t i) {
  return getRuleContext<ExprParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::VariableContext::LBRACK() {
  return getTokens(ExprParser::LBRACK);
}

tree::TerminalNode* ExprParser::VariableContext::LBRACK(size_t i) {
  return getToken(ExprParser::LBRACK, i);
}

std::vector<ExprParser::ExpressionContext *> ExprParser::VariableContext::expression() {
  return getRuleContexts<ExprParser::ExpressionContext>();
}

ExprParser::ExpressionContext* ExprParser::VariableContext::expression(size_t i) {
  return getRuleContext<ExprParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::VariableContext::RBRACK() {
  return getTokens(ExprParser::RBRACK);
}

tree::TerminalNode* ExprParser::VariableContext::RBRACK(size_t i) {
  return getToken(ExprParser::RBRACK, i);
}

std::vector<tree::TerminalNode *> ExprParser::VariableContext::LBRACK2() {
  return getTokens(ExprParser::LBRACK2);
}

tree::TerminalNode* ExprParser::VariableContext::LBRACK2(size_t i) {
  return getToken(ExprParser::LBRACK2, i);
}

std::vector<tree::TerminalNode *> ExprParser::VariableContext::RBRACK2() {
  return getTokens(ExprParser::RBRACK2);
}

tree::TerminalNode* ExprParser::VariableContext::RBRACK2(size_t i) {
  return getToken(ExprParser::RBRACK2, i);
}

std::vector<tree::TerminalNode *> ExprParser::VariableContext::DOT() {
  return getTokens(ExprParser::DOT);
}

tree::TerminalNode* ExprParser::VariableContext::DOT(size_t i) {
  return getToken(ExprParser::DOT, i);
}

std::vector<tree::TerminalNode *> ExprParser::VariableContext::POINTER() {
  return getTokens(ExprParser::POINTER);
}

tree::TerminalNode* ExprParser::VariableContext::POINTER(size_t i) {
  return getToken(ExprParser::POINTER, i);
}

std::vector<tree::TerminalNode *> ExprParser::VariableContext::COMMA() {
  return getTokens(ExprParser::COMMA);
}

tree::TerminalNode* ExprParser::VariableContext::COMMA(size_t i) {
  return getToken(ExprParser::COMMA, i);
}


size_t ExprParser::VariableContext::getRuleIndex() const {
  return ExprParser::RuleVariable;
}


antlrcpp::Any ExprParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::VariableContext* ExprParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 120, ExprParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(564);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::AT: {
        setState(561);
        match(ExprParser::AT);
        setState(562);
        identifier();
        break;
      }

      case ExprParser::IDENT: {
        setState(563);
        identifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(593);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::LBRACK)
      | (1ULL << ExprParser::LBRACK2)
      | (1ULL << ExprParser::POINTER)
      | (1ULL << ExprParser::DOT))) != 0)) {
      setState(591);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case ExprParser::LBRACK: {
          setState(566);
          match(ExprParser::LBRACK);
          setState(567);
          expression();
          setState(572);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == ExprParser::COMMA) {
            setState(568);
            match(ExprParser::COMMA);
            setState(569);
            expression();
            setState(574);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(575);
          match(ExprParser::RBRACK);
          break;
        }

        case ExprParser::LBRACK2: {
          setState(577);
          match(ExprParser::LBRACK2);
          setState(578);
          expression();
          setState(583);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == ExprParser::COMMA) {
            setState(579);
            match(ExprParser::COMMA);
            setState(580);
            expression();
            setState(585);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(586);
          match(ExprParser::RBRACK2);
          break;
        }

        case ExprParser::DOT: {
          setState(588);
          match(ExprParser::DOT);
          setState(589);
          identifier();
          break;
        }

        case ExprParser::POINTER: {
          setState(590);
          match(ExprParser::POINTER);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(595);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

ExprParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::SimpleExpressionContext* ExprParser::ExpressionContext::simpleExpression() {
  return getRuleContext<ExprParser::SimpleExpressionContext>(0);
}

ExprParser::RelationaloperatorContext* ExprParser::ExpressionContext::relationaloperator() {
  return getRuleContext<ExprParser::RelationaloperatorContext>(0);
}

ExprParser::ExpressionContext* ExprParser::ExpressionContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}


size_t ExprParser::ExpressionContext::getRuleIndex() const {
  return ExprParser::RuleExpression;
}


antlrcpp::Any ExprParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ExpressionContext* ExprParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 122, ExprParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(596);
    simpleExpression();
    setState(600);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::IN)
      | (1ULL << ExprParser::EQUAL)
      | (1ULL << ExprParser::NOT_EQUAL)
      | (1ULL << ExprParser::LT)
      | (1ULL << ExprParser::LE)
      | (1ULL << ExprParser::GE)
      | (1ULL << ExprParser::GT))) != 0)) {
      setState(597);
      relationaloperator();
      setState(598);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationaloperatorContext ------------------------------------------------------------------

ExprParser::RelationaloperatorContext::RelationaloperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::RelationaloperatorContext::EQUAL() {
  return getToken(ExprParser::EQUAL, 0);
}

tree::TerminalNode* ExprParser::RelationaloperatorContext::NOT_EQUAL() {
  return getToken(ExprParser::NOT_EQUAL, 0);
}

tree::TerminalNode* ExprParser::RelationaloperatorContext::LT() {
  return getToken(ExprParser::LT, 0);
}

tree::TerminalNode* ExprParser::RelationaloperatorContext::LE() {
  return getToken(ExprParser::LE, 0);
}

tree::TerminalNode* ExprParser::RelationaloperatorContext::GE() {
  return getToken(ExprParser::GE, 0);
}

tree::TerminalNode* ExprParser::RelationaloperatorContext::GT() {
  return getToken(ExprParser::GT, 0);
}

tree::TerminalNode* ExprParser::RelationaloperatorContext::IN() {
  return getToken(ExprParser::IN, 0);
}


size_t ExprParser::RelationaloperatorContext::getRuleIndex() const {
  return ExprParser::RuleRelationaloperator;
}


antlrcpp::Any ExprParser::RelationaloperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitRelationaloperator(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::RelationaloperatorContext* ExprParser::relationaloperator() {
  RelationaloperatorContext *_localctx = _tracker.createInstance<RelationaloperatorContext>(_ctx, getState());
  enterRule(_localctx, 124, ExprParser::RuleRelationaloperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(602);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::IN)
      | (1ULL << ExprParser::EQUAL)
      | (1ULL << ExprParser::NOT_EQUAL)
      | (1ULL << ExprParser::LT)
      | (1ULL << ExprParser::LE)
      | (1ULL << ExprParser::GE)
      | (1ULL << ExprParser::GT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleExpressionContext ------------------------------------------------------------------

ExprParser::SimpleExpressionContext::SimpleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::TermContext* ExprParser::SimpleExpressionContext::term() {
  return getRuleContext<ExprParser::TermContext>(0);
}

ExprParser::AdditiveoperatorContext* ExprParser::SimpleExpressionContext::additiveoperator() {
  return getRuleContext<ExprParser::AdditiveoperatorContext>(0);
}

ExprParser::SimpleExpressionContext* ExprParser::SimpleExpressionContext::simpleExpression() {
  return getRuleContext<ExprParser::SimpleExpressionContext>(0);
}


size_t ExprParser::SimpleExpressionContext::getRuleIndex() const {
  return ExprParser::RuleSimpleExpression;
}


antlrcpp::Any ExprParser::SimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSimpleExpression(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::SimpleExpressionContext* ExprParser::simpleExpression() {
  SimpleExpressionContext *_localctx = _tracker.createInstance<SimpleExpressionContext>(_ctx, getState());
  enterRule(_localctx, 126, ExprParser::RuleSimpleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(604);
    term();
    setState(608);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::OR)
      | (1ULL << ExprParser::PLUS)
      | (1ULL << ExprParser::MINUS))) != 0)) {
      setState(605);
      additiveoperator();
      setState(606);
      simpleExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AdditiveoperatorContext ------------------------------------------------------------------

ExprParser::AdditiveoperatorContext::AdditiveoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::AdditiveoperatorContext::PLUS() {
  return getToken(ExprParser::PLUS, 0);
}

tree::TerminalNode* ExprParser::AdditiveoperatorContext::MINUS() {
  return getToken(ExprParser::MINUS, 0);
}

tree::TerminalNode* ExprParser::AdditiveoperatorContext::OR() {
  return getToken(ExprParser::OR, 0);
}


size_t ExprParser::AdditiveoperatorContext::getRuleIndex() const {
  return ExprParser::RuleAdditiveoperator;
}


antlrcpp::Any ExprParser::AdditiveoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitAdditiveoperator(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::AdditiveoperatorContext* ExprParser::additiveoperator() {
  AdditiveoperatorContext *_localctx = _tracker.createInstance<AdditiveoperatorContext>(_ctx, getState());
  enterRule(_localctx, 128, ExprParser::RuleAdditiveoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(610);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::OR)
      | (1ULL << ExprParser::PLUS)
      | (1ULL << ExprParser::MINUS))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

ExprParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::SignedFactorContext* ExprParser::TermContext::signedFactor() {
  return getRuleContext<ExprParser::SignedFactorContext>(0);
}

ExprParser::MultiplicativeoperatorContext* ExprParser::TermContext::multiplicativeoperator() {
  return getRuleContext<ExprParser::MultiplicativeoperatorContext>(0);
}

ExprParser::TermContext* ExprParser::TermContext::term() {
  return getRuleContext<ExprParser::TermContext>(0);
}


size_t ExprParser::TermContext::getRuleIndex() const {
  return ExprParser::RuleTerm;
}


antlrcpp::Any ExprParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::TermContext* ExprParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 130, ExprParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(612);
    signedFactor();
    setState(616);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::AND)
      | (1ULL << ExprParser::DIV)
      | (1ULL << ExprParser::MOD)
      | (1ULL << ExprParser::STAR)
      | (1ULL << ExprParser::SLASH))) != 0)) {
      setState(613);
      multiplicativeoperator();
      setState(614);
      term();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeoperatorContext ------------------------------------------------------------------

ExprParser::MultiplicativeoperatorContext::MultiplicativeoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::MultiplicativeoperatorContext::STAR() {
  return getToken(ExprParser::STAR, 0);
}

tree::TerminalNode* ExprParser::MultiplicativeoperatorContext::SLASH() {
  return getToken(ExprParser::SLASH, 0);
}

tree::TerminalNode* ExprParser::MultiplicativeoperatorContext::DIV() {
  return getToken(ExprParser::DIV, 0);
}

tree::TerminalNode* ExprParser::MultiplicativeoperatorContext::MOD() {
  return getToken(ExprParser::MOD, 0);
}

tree::TerminalNode* ExprParser::MultiplicativeoperatorContext::AND() {
  return getToken(ExprParser::AND, 0);
}


size_t ExprParser::MultiplicativeoperatorContext::getRuleIndex() const {
  return ExprParser::RuleMultiplicativeoperator;
}


antlrcpp::Any ExprParser::MultiplicativeoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeoperator(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::MultiplicativeoperatorContext* ExprParser::multiplicativeoperator() {
  MultiplicativeoperatorContext *_localctx = _tracker.createInstance<MultiplicativeoperatorContext>(_ctx, getState());
  enterRule(_localctx, 132, ExprParser::RuleMultiplicativeoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(618);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::AND)
      | (1ULL << ExprParser::DIV)
      | (1ULL << ExprParser::MOD)
      | (1ULL << ExprParser::STAR)
      | (1ULL << ExprParser::SLASH))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignedFactorContext ------------------------------------------------------------------

ExprParser::SignedFactorContext::SignedFactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::FactorContext* ExprParser::SignedFactorContext::factor() {
  return getRuleContext<ExprParser::FactorContext>(0);
}

tree::TerminalNode* ExprParser::SignedFactorContext::PLUS() {
  return getToken(ExprParser::PLUS, 0);
}

tree::TerminalNode* ExprParser::SignedFactorContext::MINUS() {
  return getToken(ExprParser::MINUS, 0);
}


size_t ExprParser::SignedFactorContext::getRuleIndex() const {
  return ExprParser::RuleSignedFactor;
}


antlrcpp::Any ExprParser::SignedFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSignedFactor(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::SignedFactorContext* ExprParser::signedFactor() {
  SignedFactorContext *_localctx = _tracker.createInstance<SignedFactorContext>(_ctx, getState());
  enterRule(_localctx, 134, ExprParser::RuleSignedFactor);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(621);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::PLUS

    || _la == ExprParser::MINUS) {
      setState(620);
      _la = _input->LA(1);
      if (!(_la == ExprParser::PLUS

      || _la == ExprParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(623);
    factor();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

ExprParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::VariableContext* ExprParser::FactorContext::variable() {
  return getRuleContext<ExprParser::VariableContext>(0);
}

tree::TerminalNode* ExprParser::FactorContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

ExprParser::ExpressionContext* ExprParser::FactorContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}

tree::TerminalNode* ExprParser::FactorContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}

ExprParser::FunctionDesignatorContext* ExprParser::FactorContext::functionDesignator() {
  return getRuleContext<ExprParser::FunctionDesignatorContext>(0);
}

ExprParser::UnsignedConstantContext* ExprParser::FactorContext::unsignedConstant() {
  return getRuleContext<ExprParser::UnsignedConstantContext>(0);
}

ExprParser::Set_Context* ExprParser::FactorContext::set_() {
  return getRuleContext<ExprParser::Set_Context>(0);
}

tree::TerminalNode* ExprParser::FactorContext::NOT() {
  return getToken(ExprParser::NOT, 0);
}

ExprParser::FactorContext* ExprParser::FactorContext::factor() {
  return getRuleContext<ExprParser::FactorContext>(0);
}

ExprParser::Bool_Context* ExprParser::FactorContext::bool_() {
  return getRuleContext<ExprParser::Bool_Context>(0);
}


size_t ExprParser::FactorContext::getRuleIndex() const {
  return ExprParser::RuleFactor;
}


antlrcpp::Any ExprParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::FactorContext* ExprParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 136, ExprParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(636);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(625);
      variable();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(626);
      match(ExprParser::LPAREN);
      setState(627);
      expression();
      setState(628);
      match(ExprParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(630);
      functionDesignator();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(631);
      unsignedConstant();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(632);
      set_();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(633);
      match(ExprParser::NOT);
      setState(634);
      factor();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(635);
      bool_();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedConstantContext ------------------------------------------------------------------

ExprParser::UnsignedConstantContext::UnsignedConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::UnsignedNumberContext* ExprParser::UnsignedConstantContext::unsignedNumber() {
  return getRuleContext<ExprParser::UnsignedNumberContext>(0);
}

ExprParser::ConstantChrContext* ExprParser::UnsignedConstantContext::constantChr() {
  return getRuleContext<ExprParser::ConstantChrContext>(0);
}

ExprParser::StringContext* ExprParser::UnsignedConstantContext::string() {
  return getRuleContext<ExprParser::StringContext>(0);
}

tree::TerminalNode* ExprParser::UnsignedConstantContext::NIL() {
  return getToken(ExprParser::NIL, 0);
}


size_t ExprParser::UnsignedConstantContext::getRuleIndex() const {
  return ExprParser::RuleUnsignedConstant;
}


antlrcpp::Any ExprParser::UnsignedConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitUnsignedConstant(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::UnsignedConstantContext* ExprParser::unsignedConstant() {
  UnsignedConstantContext *_localctx = _tracker.createInstance<UnsignedConstantContext>(_ctx, getState());
  enterRule(_localctx, 138, ExprParser::RuleUnsignedConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(642);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::NUM_INT:
      case ExprParser::NUM_REAL: {
        enterOuterAlt(_localctx, 1);
        setState(638);
        unsignedNumber();
        break;
      }

      case ExprParser::CHR: {
        enterOuterAlt(_localctx, 2);
        setState(639);
        constantChr();
        break;
      }

      case ExprParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(640);
        string();
        break;
      }

      case ExprParser::NIL: {
        enterOuterAlt(_localctx, 4);
        setState(641);
        match(ExprParser::NIL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDesignatorContext ------------------------------------------------------------------

ExprParser::FunctionDesignatorContext::FunctionDesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::IdentifierContext* ExprParser::FunctionDesignatorContext::identifier() {
  return getRuleContext<ExprParser::IdentifierContext>(0);
}

tree::TerminalNode* ExprParser::FunctionDesignatorContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

ExprParser::ParameterListContext* ExprParser::FunctionDesignatorContext::parameterList() {
  return getRuleContext<ExprParser::ParameterListContext>(0);
}

tree::TerminalNode* ExprParser::FunctionDesignatorContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}


size_t ExprParser::FunctionDesignatorContext::getRuleIndex() const {
  return ExprParser::RuleFunctionDesignator;
}


antlrcpp::Any ExprParser::FunctionDesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFunctionDesignator(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::FunctionDesignatorContext* ExprParser::functionDesignator() {
  FunctionDesignatorContext *_localctx = _tracker.createInstance<FunctionDesignatorContext>(_ctx, getState());
  enterRule(_localctx, 140, ExprParser::RuleFunctionDesignator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(644);
    identifier();
    setState(645);
    match(ExprParser::LPAREN);
    setState(646);
    parameterList();
    setState(647);
    match(ExprParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

ExprParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::ActualParameterContext *> ExprParser::ParameterListContext::actualParameter() {
  return getRuleContexts<ExprParser::ActualParameterContext>();
}

ExprParser::ActualParameterContext* ExprParser::ParameterListContext::actualParameter(size_t i) {
  return getRuleContext<ExprParser::ActualParameterContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::ParameterListContext::COMMA() {
  return getTokens(ExprParser::COMMA);
}

tree::TerminalNode* ExprParser::ParameterListContext::COMMA(size_t i) {
  return getToken(ExprParser::COMMA, i);
}


size_t ExprParser::ParameterListContext::getRuleIndex() const {
  return ExprParser::RuleParameterList;
}


antlrcpp::Any ExprParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ParameterListContext* ExprParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 142, ExprParser::RuleParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(649);
    actualParameter();
    setState(654);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::COMMA) {
      setState(650);
      match(ExprParser::COMMA);
      setState(651);
      actualParameter();
      setState(656);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_Context ------------------------------------------------------------------

ExprParser::Set_Context::Set_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Set_Context::LBRACK() {
  return getToken(ExprParser::LBRACK, 0);
}

ExprParser::ElementListContext* ExprParser::Set_Context::elementList() {
  return getRuleContext<ExprParser::ElementListContext>(0);
}

tree::TerminalNode* ExprParser::Set_Context::RBRACK() {
  return getToken(ExprParser::RBRACK, 0);
}

tree::TerminalNode* ExprParser::Set_Context::LBRACK2() {
  return getToken(ExprParser::LBRACK2, 0);
}

tree::TerminalNode* ExprParser::Set_Context::RBRACK2() {
  return getToken(ExprParser::RBRACK2, 0);
}


size_t ExprParser::Set_Context::getRuleIndex() const {
  return ExprParser::RuleSet_;
}


antlrcpp::Any ExprParser::Set_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSet_(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Set_Context* ExprParser::set_() {
  Set_Context *_localctx = _tracker.createInstance<Set_Context>(_ctx, getState());
  enterRule(_localctx, 144, ExprParser::RuleSet_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(665);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::LBRACK: {
        enterOuterAlt(_localctx, 1);
        setState(657);
        match(ExprParser::LBRACK);
        setState(658);
        elementList();
        setState(659);
        match(ExprParser::RBRACK);
        break;
      }

      case ExprParser::LBRACK2: {
        enterOuterAlt(_localctx, 2);
        setState(661);
        match(ExprParser::LBRACK2);
        setState(662);
        elementList();
        setState(663);
        match(ExprParser::RBRACK2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementListContext ------------------------------------------------------------------

ExprParser::ElementListContext::ElementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::ElementContext *> ExprParser::ElementListContext::element() {
  return getRuleContexts<ExprParser::ElementContext>();
}

ExprParser::ElementContext* ExprParser::ElementListContext::element(size_t i) {
  return getRuleContext<ExprParser::ElementContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::ElementListContext::COMMA() {
  return getTokens(ExprParser::COMMA);
}

tree::TerminalNode* ExprParser::ElementListContext::COMMA(size_t i) {
  return getToken(ExprParser::COMMA, i);
}


size_t ExprParser::ElementListContext::getRuleIndex() const {
  return ExprParser::RuleElementList;
}


antlrcpp::Any ExprParser::ElementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitElementList(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ElementListContext* ExprParser::elementList() {
  ElementListContext *_localctx = _tracker.createInstance<ElementListContext>(_ctx, getState());
  enterRule(_localctx, 146, ExprParser::RuleElementList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(676);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::CHR:
      case ExprParser::NIL:
      case ExprParser::NOT:
      case ExprParser::PLUS:
      case ExprParser::MINUS:
      case ExprParser::LPAREN:
      case ExprParser::LBRACK:
      case ExprParser::LBRACK2:
      case ExprParser::AT:
      case ExprParser::TRUE:
      case ExprParser::FALSE:
      case ExprParser::IDENT:
      case ExprParser::STRING_LITERAL:
      case ExprParser::NUM_INT:
      case ExprParser::NUM_REAL: {
        enterOuterAlt(_localctx, 1);
        setState(667);
        element();
        setState(672);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ExprParser::COMMA) {
          setState(668);
          match(ExprParser::COMMA);
          setState(669);
          element();
          setState(674);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case ExprParser::RBRACK:
      case ExprParser::RBRACK2: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementContext ------------------------------------------------------------------

ExprParser::ElementContext::ElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::ExpressionContext *> ExprParser::ElementContext::expression() {
  return getRuleContexts<ExprParser::ExpressionContext>();
}

ExprParser::ExpressionContext* ExprParser::ElementContext::expression(size_t i) {
  return getRuleContext<ExprParser::ExpressionContext>(i);
}

tree::TerminalNode* ExprParser::ElementContext::DOTDOT() {
  return getToken(ExprParser::DOTDOT, 0);
}


size_t ExprParser::ElementContext::getRuleIndex() const {
  return ExprParser::RuleElement;
}


antlrcpp::Any ExprParser::ElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitElement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ElementContext* ExprParser::element() {
  ElementContext *_localctx = _tracker.createInstance<ElementContext>(_ctx, getState());
  enterRule(_localctx, 148, ExprParser::RuleElement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(678);
    expression();
    setState(681);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::DOTDOT) {
      setState(679);
      match(ExprParser::DOTDOT);
      setState(680);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureStatementContext ------------------------------------------------------------------

ExprParser::ProcedureStatementContext::ProcedureStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::IdentifierContext* ExprParser::ProcedureStatementContext::identifier() {
  return getRuleContext<ExprParser::IdentifierContext>(0);
}

tree::TerminalNode* ExprParser::ProcedureStatementContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

ExprParser::ParameterListContext* ExprParser::ProcedureStatementContext::parameterList() {
  return getRuleContext<ExprParser::ParameterListContext>(0);
}

tree::TerminalNode* ExprParser::ProcedureStatementContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}


size_t ExprParser::ProcedureStatementContext::getRuleIndex() const {
  return ExprParser::RuleProcedureStatement;
}


antlrcpp::Any ExprParser::ProcedureStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProcedureStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProcedureStatementContext* ExprParser::procedureStatement() {
  ProcedureStatementContext *_localctx = _tracker.createInstance<ProcedureStatementContext>(_ctx, getState());
  enterRule(_localctx, 150, ExprParser::RuleProcedureStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(683);
    identifier();
    setState(688);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::LPAREN) {
      setState(684);
      match(ExprParser::LPAREN);
      setState(685);
      parameterList();
      setState(686);
      match(ExprParser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActualParameterContext ------------------------------------------------------------------

ExprParser::ActualParameterContext::ActualParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ExpressionContext* ExprParser::ActualParameterContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}

std::vector<ExprParser::ParameterwidthContext *> ExprParser::ActualParameterContext::parameterwidth() {
  return getRuleContexts<ExprParser::ParameterwidthContext>();
}

ExprParser::ParameterwidthContext* ExprParser::ActualParameterContext::parameterwidth(size_t i) {
  return getRuleContext<ExprParser::ParameterwidthContext>(i);
}


size_t ExprParser::ActualParameterContext::getRuleIndex() const {
  return ExprParser::RuleActualParameter;
}


antlrcpp::Any ExprParser::ActualParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitActualParameter(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ActualParameterContext* ExprParser::actualParameter() {
  ActualParameterContext *_localctx = _tracker.createInstance<ActualParameterContext>(_ctx, getState());
  enterRule(_localctx, 152, ExprParser::RuleActualParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(690);
    expression();
    setState(694);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::COLON) {
      setState(691);
      parameterwidth();
      setState(696);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterwidthContext ------------------------------------------------------------------

ExprParser::ParameterwidthContext::ParameterwidthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ParameterwidthContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

ExprParser::ExpressionContext* ExprParser::ParameterwidthContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}


size_t ExprParser::ParameterwidthContext::getRuleIndex() const {
  return ExprParser::RuleParameterwidth;
}


antlrcpp::Any ExprParser::ParameterwidthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitParameterwidth(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ParameterwidthContext* ExprParser::parameterwidth() {
  ParameterwidthContext *_localctx = _tracker.createInstance<ParameterwidthContext>(_ctx, getState());
  enterRule(_localctx, 154, ExprParser::RuleParameterwidth);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(697);
    match(ExprParser::COLON);
    setState(698);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GotoStatementContext ------------------------------------------------------------------

ExprParser::GotoStatementContext::GotoStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::GotoStatementContext::GOTO() {
  return getToken(ExprParser::GOTO, 0);
}

ExprParser::LabelContext* ExprParser::GotoStatementContext::label() {
  return getRuleContext<ExprParser::LabelContext>(0);
}


size_t ExprParser::GotoStatementContext::getRuleIndex() const {
  return ExprParser::RuleGotoStatement;
}


antlrcpp::Any ExprParser::GotoStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitGotoStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::GotoStatementContext* ExprParser::gotoStatement() {
  GotoStatementContext *_localctx = _tracker.createInstance<GotoStatementContext>(_ctx, getState());
  enterRule(_localctx, 156, ExprParser::RuleGotoStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(700);
    match(ExprParser::GOTO);
    setState(701);
    label();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatement_Context ------------------------------------------------------------------

ExprParser::EmptyStatement_Context::EmptyStatement_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::EmptyStatement_Context::getRuleIndex() const {
  return ExprParser::RuleEmptyStatement_;
}


antlrcpp::Any ExprParser::EmptyStatement_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement_(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::EmptyStatement_Context* ExprParser::emptyStatement_() {
  EmptyStatement_Context *_localctx = _tracker.createInstance<EmptyStatement_Context>(_ctx, getState());
  enterRule(_localctx, 158, ExprParser::RuleEmptyStatement_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Empty_Context ------------------------------------------------------------------

ExprParser::Empty_Context::Empty_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::Empty_Context::getRuleIndex() const {
  return ExprParser::RuleEmpty_;
}


antlrcpp::Any ExprParser::Empty_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitEmpty_(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Empty_Context* ExprParser::empty_() {
  Empty_Context *_localctx = _tracker.createInstance<Empty_Context>(_ctx, getState());
  enterRule(_localctx, 160, ExprParser::RuleEmpty_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructuredStatementContext ------------------------------------------------------------------

ExprParser::StructuredStatementContext::StructuredStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::CompoundStatementContext* ExprParser::StructuredStatementContext::compoundStatement() {
  return getRuleContext<ExprParser::CompoundStatementContext>(0);
}

ExprParser::ConditionalStatementContext* ExprParser::StructuredStatementContext::conditionalStatement() {
  return getRuleContext<ExprParser::ConditionalStatementContext>(0);
}

ExprParser::RepetetiveStatementContext* ExprParser::StructuredStatementContext::repetetiveStatement() {
  return getRuleContext<ExprParser::RepetetiveStatementContext>(0);
}

ExprParser::WithStatementContext* ExprParser::StructuredStatementContext::withStatement() {
  return getRuleContext<ExprParser::WithStatementContext>(0);
}


size_t ExprParser::StructuredStatementContext::getRuleIndex() const {
  return ExprParser::RuleStructuredStatement;
}


antlrcpp::Any ExprParser::StructuredStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStructuredStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::StructuredStatementContext* ExprParser::structuredStatement() {
  StructuredStatementContext *_localctx = _tracker.createInstance<StructuredStatementContext>(_ctx, getState());
  enterRule(_localctx, 162, ExprParser::RuleStructuredStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(711);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::BEGIN: {
        enterOuterAlt(_localctx, 1);
        setState(707);
        compoundStatement();
        break;
      }

      case ExprParser::CASE:
      case ExprParser::IF: {
        enterOuterAlt(_localctx, 2);
        setState(708);
        conditionalStatement();
        break;
      }

      case ExprParser::FOR:
      case ExprParser::REPEAT:
      case ExprParser::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(709);
        repetetiveStatement();
        break;
      }

      case ExprParser::WITH: {
        enterOuterAlt(_localctx, 4);
        setState(710);
        withStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

ExprParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::CompoundStatementContext::BEGIN() {
  return getToken(ExprParser::BEGIN, 0);
}

ExprParser::StatementsContext* ExprParser::CompoundStatementContext::statements() {
  return getRuleContext<ExprParser::StatementsContext>(0);
}

tree::TerminalNode* ExprParser::CompoundStatementContext::END() {
  return getToken(ExprParser::END, 0);
}


size_t ExprParser::CompoundStatementContext::getRuleIndex() const {
  return ExprParser::RuleCompoundStatement;
}


antlrcpp::Any ExprParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::CompoundStatementContext* ExprParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 164, ExprParser::RuleCompoundStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(713);
    match(ExprParser::BEGIN);
    setState(714);
    statements();
    setState(715);
    match(ExprParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

ExprParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::StatementContext *> ExprParser::StatementsContext::statement() {
  return getRuleContexts<ExprParser::StatementContext>();
}

ExprParser::StatementContext* ExprParser::StatementsContext::statement(size_t i) {
  return getRuleContext<ExprParser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::StatementsContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::StatementsContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}


size_t ExprParser::StatementsContext::getRuleIndex() const {
  return ExprParser::RuleStatements;
}


antlrcpp::Any ExprParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::StatementsContext* ExprParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 166, ExprParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(717);
    statement();
    setState(722);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::SEMICOLON) {
      setState(718);
      match(ExprParser::SEMICOLON);
      setState(719);
      statement();
      setState(724);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalStatementContext ------------------------------------------------------------------

ExprParser::ConditionalStatementContext::ConditionalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::IfStatementContext* ExprParser::ConditionalStatementContext::ifStatement() {
  return getRuleContext<ExprParser::IfStatementContext>(0);
}

ExprParser::CaseStatementContext* ExprParser::ConditionalStatementContext::caseStatement() {
  return getRuleContext<ExprParser::CaseStatementContext>(0);
}


size_t ExprParser::ConditionalStatementContext::getRuleIndex() const {
  return ExprParser::RuleConditionalStatement;
}


antlrcpp::Any ExprParser::ConditionalStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitConditionalStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ConditionalStatementContext* ExprParser::conditionalStatement() {
  ConditionalStatementContext *_localctx = _tracker.createInstance<ConditionalStatementContext>(_ctx, getState());
  enterRule(_localctx, 168, ExprParser::RuleConditionalStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(727);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(725);
        ifStatement();
        break;
      }

      case ExprParser::CASE: {
        enterOuterAlt(_localctx, 2);
        setState(726);
        caseStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

ExprParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::IfStatementContext::IF() {
  return getToken(ExprParser::IF, 0);
}

ExprParser::ExpressionContext* ExprParser::IfStatementContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}

tree::TerminalNode* ExprParser::IfStatementContext::THEN() {
  return getToken(ExprParser::THEN, 0);
}

std::vector<ExprParser::StatementContext *> ExprParser::IfStatementContext::statement() {
  return getRuleContexts<ExprParser::StatementContext>();
}

ExprParser::StatementContext* ExprParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<ExprParser::StatementContext>(i);
}

tree::TerminalNode* ExprParser::IfStatementContext::ELSE() {
  return getToken(ExprParser::ELSE, 0);
}


size_t ExprParser::IfStatementContext::getRuleIndex() const {
  return ExprParser::RuleIfStatement;
}


antlrcpp::Any ExprParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::IfStatementContext* ExprParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 170, ExprParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(729);
    match(ExprParser::IF);
    setState(730);
    expression();
    setState(731);
    match(ExprParser::THEN);
    setState(732);
    statement();
    setState(735);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      setState(733);
      match(ExprParser::ELSE);
      setState(734);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

ExprParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::CaseStatementContext::CASE() {
  return getToken(ExprParser::CASE, 0);
}

ExprParser::ExpressionContext* ExprParser::CaseStatementContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}

tree::TerminalNode* ExprParser::CaseStatementContext::OF() {
  return getToken(ExprParser::OF, 0);
}

std::vector<ExprParser::CaseListElementContext *> ExprParser::CaseStatementContext::caseListElement() {
  return getRuleContexts<ExprParser::CaseListElementContext>();
}

ExprParser::CaseListElementContext* ExprParser::CaseStatementContext::caseListElement(size_t i) {
  return getRuleContext<ExprParser::CaseListElementContext>(i);
}

tree::TerminalNode* ExprParser::CaseStatementContext::END() {
  return getToken(ExprParser::END, 0);
}

std::vector<tree::TerminalNode *> ExprParser::CaseStatementContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::CaseStatementContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}

tree::TerminalNode* ExprParser::CaseStatementContext::ELSE() {
  return getToken(ExprParser::ELSE, 0);
}

ExprParser::StatementsContext* ExprParser::CaseStatementContext::statements() {
  return getRuleContext<ExprParser::StatementsContext>(0);
}


size_t ExprParser::CaseStatementContext::getRuleIndex() const {
  return ExprParser::RuleCaseStatement;
}


antlrcpp::Any ExprParser::CaseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitCaseStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::CaseStatementContext* ExprParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 172, ExprParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(737);
    match(ExprParser::CASE);
    setState(738);
    expression();
    setState(739);
    match(ExprParser::OF);
    setState(740);
    caseListElement();
    setState(745);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(741);
        match(ExprParser::SEMICOLON);
        setState(742);
        caseListElement(); 
      }
      setState(747);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    }
    setState(751);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::SEMICOLON) {
      setState(748);
      match(ExprParser::SEMICOLON);
      setState(749);
      match(ExprParser::ELSE);
      setState(750);
      statements();
    }
    setState(753);
    match(ExprParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseListElementContext ------------------------------------------------------------------

ExprParser::CaseListElementContext::CaseListElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ConstListContext* ExprParser::CaseListElementContext::constList() {
  return getRuleContext<ExprParser::ConstListContext>(0);
}

tree::TerminalNode* ExprParser::CaseListElementContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

ExprParser::StatementContext* ExprParser::CaseListElementContext::statement() {
  return getRuleContext<ExprParser::StatementContext>(0);
}


size_t ExprParser::CaseListElementContext::getRuleIndex() const {
  return ExprParser::RuleCaseListElement;
}


antlrcpp::Any ExprParser::CaseListElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitCaseListElement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::CaseListElementContext* ExprParser::caseListElement() {
  CaseListElementContext *_localctx = _tracker.createInstance<CaseListElementContext>(_ctx, getState());
  enterRule(_localctx, 174, ExprParser::RuleCaseListElement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(755);
    constList();
    setState(756);
    match(ExprParser::COLON);
    setState(757);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RepetetiveStatementContext ------------------------------------------------------------------

ExprParser::RepetetiveStatementContext::RepetetiveStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::WhileStatementContext* ExprParser::RepetetiveStatementContext::whileStatement() {
  return getRuleContext<ExprParser::WhileStatementContext>(0);
}

ExprParser::RepeatStatementContext* ExprParser::RepetetiveStatementContext::repeatStatement() {
  return getRuleContext<ExprParser::RepeatStatementContext>(0);
}

ExprParser::ForStatementContext* ExprParser::RepetetiveStatementContext::forStatement() {
  return getRuleContext<ExprParser::ForStatementContext>(0);
}


size_t ExprParser::RepetetiveStatementContext::getRuleIndex() const {
  return ExprParser::RuleRepetetiveStatement;
}


antlrcpp::Any ExprParser::RepetetiveStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitRepetetiveStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::RepetetiveStatementContext* ExprParser::repetetiveStatement() {
  RepetetiveStatementContext *_localctx = _tracker.createInstance<RepetetiveStatementContext>(_ctx, getState());
  enterRule(_localctx, 176, ExprParser::RuleRepetetiveStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(762);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::WHILE: {
        enterOuterAlt(_localctx, 1);
        setState(759);
        whileStatement();
        break;
      }

      case ExprParser::REPEAT: {
        enterOuterAlt(_localctx, 2);
        setState(760);
        repeatStatement();
        break;
      }

      case ExprParser::FOR: {
        enterOuterAlt(_localctx, 3);
        setState(761);
        forStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

ExprParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::WhileStatementContext::WHILE() {
  return getToken(ExprParser::WHILE, 0);
}

ExprParser::ExpressionContext* ExprParser::WhileStatementContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}

tree::TerminalNode* ExprParser::WhileStatementContext::DO() {
  return getToken(ExprParser::DO, 0);
}

ExprParser::StatementContext* ExprParser::WhileStatementContext::statement() {
  return getRuleContext<ExprParser::StatementContext>(0);
}


size_t ExprParser::WhileStatementContext::getRuleIndex() const {
  return ExprParser::RuleWhileStatement;
}


antlrcpp::Any ExprParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::WhileStatementContext* ExprParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 178, ExprParser::RuleWhileStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(764);
    match(ExprParser::WHILE);
    setState(765);
    expression();
    setState(766);
    match(ExprParser::DO);
    setState(767);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RepeatStatementContext ------------------------------------------------------------------

ExprParser::RepeatStatementContext::RepeatStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::RepeatStatementContext::REPEAT() {
  return getToken(ExprParser::REPEAT, 0);
}

ExprParser::StatementsContext* ExprParser::RepeatStatementContext::statements() {
  return getRuleContext<ExprParser::StatementsContext>(0);
}

tree::TerminalNode* ExprParser::RepeatStatementContext::UNTIL() {
  return getToken(ExprParser::UNTIL, 0);
}

ExprParser::ExpressionContext* ExprParser::RepeatStatementContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}


size_t ExprParser::RepeatStatementContext::getRuleIndex() const {
  return ExprParser::RuleRepeatStatement;
}


antlrcpp::Any ExprParser::RepeatStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitRepeatStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::RepeatStatementContext* ExprParser::repeatStatement() {
  RepeatStatementContext *_localctx = _tracker.createInstance<RepeatStatementContext>(_ctx, getState());
  enterRule(_localctx, 180, ExprParser::RuleRepeatStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(769);
    match(ExprParser::REPEAT);
    setState(770);
    statements();
    setState(771);
    match(ExprParser::UNTIL);
    setState(772);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

ExprParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ForStatementContext::FOR() {
  return getToken(ExprParser::FOR, 0);
}

ExprParser::IdentifierContext* ExprParser::ForStatementContext::identifier() {
  return getRuleContext<ExprParser::IdentifierContext>(0);
}

tree::TerminalNode* ExprParser::ForStatementContext::ASSIGN() {
  return getToken(ExprParser::ASSIGN, 0);
}

ExprParser::ForListContext* ExprParser::ForStatementContext::forList() {
  return getRuleContext<ExprParser::ForListContext>(0);
}

tree::TerminalNode* ExprParser::ForStatementContext::DO() {
  return getToken(ExprParser::DO, 0);
}

ExprParser::StatementContext* ExprParser::ForStatementContext::statement() {
  return getRuleContext<ExprParser::StatementContext>(0);
}


size_t ExprParser::ForStatementContext::getRuleIndex() const {
  return ExprParser::RuleForStatement;
}


antlrcpp::Any ExprParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ForStatementContext* ExprParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 182, ExprParser::RuleForStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(774);
    match(ExprParser::FOR);
    setState(775);
    identifier();
    setState(776);
    match(ExprParser::ASSIGN);
    setState(777);
    forList();
    setState(778);
    match(ExprParser::DO);
    setState(779);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForListContext ------------------------------------------------------------------

ExprParser::ForListContext::ForListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::InitialValueContext* ExprParser::ForListContext::initialValue() {
  return getRuleContext<ExprParser::InitialValueContext>(0);
}

ExprParser::FinalValueContext* ExprParser::ForListContext::finalValue() {
  return getRuleContext<ExprParser::FinalValueContext>(0);
}

tree::TerminalNode* ExprParser::ForListContext::TO() {
  return getToken(ExprParser::TO, 0);
}

tree::TerminalNode* ExprParser::ForListContext::DOWNTO() {
  return getToken(ExprParser::DOWNTO, 0);
}


size_t ExprParser::ForListContext::getRuleIndex() const {
  return ExprParser::RuleForList;
}


antlrcpp::Any ExprParser::ForListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitForList(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ForListContext* ExprParser::forList() {
  ForListContext *_localctx = _tracker.createInstance<ForListContext>(_ctx, getState());
  enterRule(_localctx, 184, ExprParser::RuleForList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(781);
    initialValue();
    setState(782);
    _la = _input->LA(1);
    if (!(_la == ExprParser::DOWNTO

    || _la == ExprParser::TO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(783);
    finalValue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitialValueContext ------------------------------------------------------------------

ExprParser::InitialValueContext::InitialValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ExpressionContext* ExprParser::InitialValueContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}


size_t ExprParser::InitialValueContext::getRuleIndex() const {
  return ExprParser::RuleInitialValue;
}


antlrcpp::Any ExprParser::InitialValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitInitialValue(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::InitialValueContext* ExprParser::initialValue() {
  InitialValueContext *_localctx = _tracker.createInstance<InitialValueContext>(_ctx, getState());
  enterRule(_localctx, 186, ExprParser::RuleInitialValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(785);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FinalValueContext ------------------------------------------------------------------

ExprParser::FinalValueContext::FinalValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ExpressionContext* ExprParser::FinalValueContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}


size_t ExprParser::FinalValueContext::getRuleIndex() const {
  return ExprParser::RuleFinalValue;
}


antlrcpp::Any ExprParser::FinalValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFinalValue(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::FinalValueContext* ExprParser::finalValue() {
  FinalValueContext *_localctx = _tracker.createInstance<FinalValueContext>(_ctx, getState());
  enterRule(_localctx, 188, ExprParser::RuleFinalValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(787);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithStatementContext ------------------------------------------------------------------

ExprParser::WithStatementContext::WithStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::WithStatementContext::WITH() {
  return getToken(ExprParser::WITH, 0);
}

ExprParser::RecordVariableListContext* ExprParser::WithStatementContext::recordVariableList() {
  return getRuleContext<ExprParser::RecordVariableListContext>(0);
}

tree::TerminalNode* ExprParser::WithStatementContext::DO() {
  return getToken(ExprParser::DO, 0);
}

ExprParser::StatementContext* ExprParser::WithStatementContext::statement() {
  return getRuleContext<ExprParser::StatementContext>(0);
}


size_t ExprParser::WithStatementContext::getRuleIndex() const {
  return ExprParser::RuleWithStatement;
}


antlrcpp::Any ExprParser::WithStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitWithStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::WithStatementContext* ExprParser::withStatement() {
  WithStatementContext *_localctx = _tracker.createInstance<WithStatementContext>(_ctx, getState());
  enterRule(_localctx, 190, ExprParser::RuleWithStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(789);
    match(ExprParser::WITH);
    setState(790);
    recordVariableList();
    setState(791);
    match(ExprParser::DO);
    setState(792);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RecordVariableListContext ------------------------------------------------------------------

ExprParser::RecordVariableListContext::RecordVariableListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::VariableContext *> ExprParser::RecordVariableListContext::variable() {
  return getRuleContexts<ExprParser::VariableContext>();
}

ExprParser::VariableContext* ExprParser::RecordVariableListContext::variable(size_t i) {
  return getRuleContext<ExprParser::VariableContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::RecordVariableListContext::COMMA() {
  return getTokens(ExprParser::COMMA);
}

tree::TerminalNode* ExprParser::RecordVariableListContext::COMMA(size_t i) {
  return getToken(ExprParser::COMMA, i);
}


size_t ExprParser::RecordVariableListContext::getRuleIndex() const {
  return ExprParser::RuleRecordVariableList;
}


antlrcpp::Any ExprParser::RecordVariableListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitRecordVariableList(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::RecordVariableListContext* ExprParser::recordVariableList() {
  RecordVariableListContext *_localctx = _tracker.createInstance<RecordVariableListContext>(_ctx, getState());
  enterRule(_localctx, 192, ExprParser::RuleRecordVariableList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(794);
    variable();
    setState(799);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::COMMA) {
      setState(795);
      match(ExprParser::COMMA);
      setState(796);
      variable();
      setState(801);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExprParser::_decisionToDFA;
atn::PredictionContextCache ExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExprParser::_atn;
std::vector<uint16_t> ExprParser::_serializedATN;

std::vector<std::string> ExprParser::_ruleNames = {
  "program", "programHeading", "identifier", "block", "usesUnitsPart", "labelDeclarationPart", 
  "label", "constantDefinitionPart", "constantDefinition", "constantChr", 
  "constant", "unsignedNumber", "unsignedInteger", "unsignedReal", "sign", 
  "bool_", "string", "typeDefinitionPart", "typeDefinition", "functionType", 
  "procedureType", "type_", "simpleType", "scalarType", "subrangeType", 
  "typeIdentifier", "structuredType", "unpackedStructuredType", "stringtype", 
  "arrayType", "typeList", "indexType", "componentType", "recordType", "fieldList", 
  "fixedPart", "recordSection", "variantPart", "tag", "variant", "setType", 
  "baseType", "fileType", "pointerType", "variableDeclarationPart", "variableDeclaration", 
  "procedureAndFunctionDeclarationPart", "procedureOrFunctionDeclaration", 
  "procedureDeclaration", "formalParameterList", "formalParameterSection", 
  "parameterGroup", "identifierList", "constList", "functionDeclaration", 
  "resultType", "statement", "unlabelledStatement", "simpleStatement", "assignmentStatement", 
  "variable", "expression", "relationaloperator", "simpleExpression", "additiveoperator", 
  "term", "multiplicativeoperator", "signedFactor", "factor", "unsignedConstant", 
  "functionDesignator", "parameterList", "set_", "elementList", "element", 
  "procedureStatement", "actualParameter", "parameterwidth", "gotoStatement", 
  "emptyStatement_", "empty_", "structuredStatement", "compoundStatement", 
  "statements", "conditionalStatement", "ifStatement", "caseStatement", 
  "caseListElement", "repetetiveStatement", "whileStatement", "repeatStatement", 
  "forStatement", "forList", "initialValue", "finalValue", "withStatement", 
  "recordVariableList"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "'+'", "'-'", "'*'", "'/'", "", "','", "';'", "':'", 
  "'='", "'<>'", "'<'", "'<='", "'>='", "'>'", "'('", "')'", "'['", "'(.'", 
  "']'", "'.)'", "'^'", "'@'", "'.'", "'..'", "'{'", "'}'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "AND", "ARRAY", "BEGIN", "BOOLEAN", "CASE", "CHAR", "CHR", "CONST", 
  "DIV", "DO", "DOWNTO", "ELSE", "END", "FILE", "FOR", "FUNCTION", "GOTO", 
  "IF", "IN", "INTEGER", "LABEL", "MOD", "NIL", "NOT", "OF", "OR", "PACKED", 
  "PROCEDURE", "PROGRAM", "REAL", "RECORD", "REPEAT", "SET", "THEN", "TO", 
  "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "PLUS", "MINUS", "STAR", "SLASH", 
  "ASSIGN", "COMMA", "SEMICOLON", "COLON", "EQUAL", "NOT_EQUAL", "LT", "LE", 
  "GE", "GT", "LPAREN", "RPAREN", "LBRACK", "LBRACK2", "RBRACK", "RBRACK2", 
  "POINTER", "AT", "DOT", "DOTDOT", "LCURLY", "RCURLY", "UNIT", "INTERFACE", 
  "USES", "STRING", "IMPLEMENTATION", "TRUE", "FALSE", "WS", "COMMENT_1", 
  "COMMENT_2", "IDENT", "STRING_LITERAL", "NUM_INT", "NUM_REAL"
};

dfa::Vocabulary ExprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ExprParser::_tokenNames;

ExprParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x52, 0x325, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 0x9, 0x62, 0x3, 0x2, 
    0x3, 0x2, 0x5, 0x2, 0xc7, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0xd2, 
    0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0xde, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x7, 0x5, 0xe9, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0xec, 0xb, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0xf8, 0xa, 0x7, 0xc, 0x7, 
    0xe, 0x7, 0xfb, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x6, 0x9, 0x105, 0xa, 0x9, 0xd, 0x9, 
    0xe, 0x9, 0x106, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 
    0xc, 0x11c, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x120, 0xa, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x6, 0x13, 0x130, 0xa, 0x13, 0xd, 0x13, 0xe, 0x13, 0x131, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x139, 
    0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x13d, 0xa, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x144, 0xa, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x149, 0xa, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x14f, 0xa, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x15b, 0xa, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x160, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x166, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x16c, 0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x5, 0x1f, 0x17e, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x7, 0x20, 0x183, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x186, 0xb, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x5, 
    0x23, 0x18e, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x195, 0xa, 0x24, 0x3, 0x24, 0x5, 0x24, 0x198, 
    0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x19d, 0xa, 0x25, 
    0xc, 0x25, 0xe, 0x25, 0x1a0, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x7, 0x27, 0x1ac, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x1af, 0xb, 
    0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 
    0x1b6, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 
    0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x1c8, 
    0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x1d1, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 
    0x1d4, 0xb, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x5, 
    0x31, 0x1e1, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 
    0x1e6, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x7, 0x33, 0x1ef, 0xa, 0x33, 0xc, 0x33, 0xe, 0x33, 
    0x1f2, 0xb, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x1fd, 0xa, 0x34, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 
    0x36, 0x7, 0x36, 0x206, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 0x209, 0xb, 
    0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 0x20e, 0xa, 0x37, 
    0xc, 0x37, 0xe, 0x37, 0x211, 0xb, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x5, 0x38, 0x216, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
    0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x224, 0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 
    0x5, 0x3b, 0x228, 0xa, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x5, 0x3c, 0x22e, 0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x237, 0xa, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x23d, 0xa, 0x3e, 0xc, 0x3e, 
    0xe, 0x3e, 0x240, 0xb, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x248, 0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 
    0x24b, 0xb, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x7, 0x3e, 0x252, 0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 0x255, 0xb, 0x3e, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x25b, 0xa, 0x3f, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x5, 
    0x41, 0x263, 0xa, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x26b, 0xa, 0x43, 0x3, 0x44, 0x3, 0x44, 
    0x3, 0x45, 0x5, 0x45, 0x270, 0xa, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 
    0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x27f, 0xa, 0x46, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x5, 0x47, 0x285, 0xa, 0x47, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 
    0x49, 0x3, 0x49, 0x7, 0x49, 0x28f, 0xa, 0x49, 0xc, 0x49, 0xe, 0x49, 
    0x292, 0xb, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 
    0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x5, 0x4a, 0x29c, 0xa, 0x4a, 0x3, 0x4b, 
    0x3, 0x4b, 0x3, 0x4b, 0x7, 0x4b, 0x2a1, 0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 
    0x2a4, 0xb, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x2a7, 0xa, 0x4b, 0x3, 0x4c, 
    0x3, 0x4c, 0x3, 0x4c, 0x5, 0x4c, 0x2ac, 0xa, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 
    0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x5, 0x4d, 0x2b3, 0xa, 0x4d, 0x3, 0x4e, 
    0x3, 0x4e, 0x7, 0x4e, 0x2b7, 0xa, 0x4e, 0xc, 0x4e, 0xe, 0x4e, 0x2ba, 
    0xb, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 
    0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 
    0x3, 0x53, 0x3, 0x53, 0x5, 0x53, 0x2ca, 0xa, 0x53, 0x3, 0x54, 0x3, 0x54, 
    0x3, 0x54, 0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x7, 0x55, 0x2d3, 
    0xa, 0x55, 0xc, 0x55, 0xe, 0x55, 0x2d6, 0xb, 0x55, 0x3, 0x56, 0x3, 0x56, 
    0x5, 0x56, 0x2da, 0xa, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 
    0x3, 0x57, 0x3, 0x57, 0x5, 0x57, 0x2e2, 0xa, 0x57, 0x3, 0x58, 0x3, 0x58, 
    0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x7, 0x58, 0x2ea, 0xa, 0x58, 
    0xc, 0x58, 0xe, 0x58, 0x2ed, 0xb, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 
    0x5, 0x58, 0x2f2, 0xa, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x3, 0x59, 
    0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 0x2fd, 
    0xa, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 
    0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 
    0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5e, 0x3, 
    0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x60, 0x3, 0x60, 
    0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x62, 0x3, 
    0x62, 0x3, 0x62, 0x7, 0x62, 0x320, 0xa, 0x62, 0xc, 0x62, 0xe, 0x62, 
    0x323, 0xb, 0x62, 0x3, 0x62, 0x2, 0x2, 0x63, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 
    0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 
    0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 
    0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 
    0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 
    0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 
    0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0xc2, 0x2, 0x9, 0x3, 0x2, 
    0x2b, 0x2c, 0x3, 0x2, 0x4a, 0x4b, 0x7, 0x2, 0x6, 0x6, 0x8, 0x8, 0x16, 
    0x16, 0x20, 0x20, 0x48, 0x48, 0x4, 0x2, 0x15, 0x15, 0x33, 0x38, 0x4, 
    0x2, 0x1c, 0x1c, 0x2b, 0x2c, 0x6, 0x2, 0x3, 0x3, 0xb, 0xb, 0x18, 0x18, 
    0x2d, 0x2e, 0x4, 0x2, 0xd, 0xd, 0x25, 0x25, 0x2, 0x324, 0x2, 0xc4, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x6, 0xdf, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0xea, 0x3, 0x2, 0x2, 0x2, 0xa, 0xef, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0xf3, 0x3, 0x2, 0x2, 0x2, 0xe, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x10, 0x100, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x108, 0x3, 0x2, 0x2, 0x2, 0x14, 0x10c, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x11f, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x121, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x123, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x125, 0x3, 0x2, 0x2, 0x2, 0x20, 0x127, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x129, 0x3, 0x2, 0x2, 0x2, 0x24, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x133, 0x3, 0x2, 0x2, 0x2, 0x28, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x141, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x148, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x14e, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x150, 0x3, 0x2, 0x2, 0x2, 0x32, 0x154, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x36, 0x15f, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0x165, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x167, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x187, 0x3, 0x2, 0x2, 0x2, 0x42, 0x189, 0x3, 0x2, 0x2, 0x2, 0x44, 0x18b, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x197, 0x3, 0x2, 0x2, 0x2, 0x48, 0x199, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1a5, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1b7, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1c1, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x1cc, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1db, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1e2, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x66, 0x1fc, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x202, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x212, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x72, 0x223, 0x3, 0x2, 0x2, 0x2, 0x74, 
    0x227, 0x3, 0x2, 0x2, 0x2, 0x76, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x78, 0x22f, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x236, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x256, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x80, 0x25e, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x264, 0x3, 0x2, 0x2, 0x2, 0x84, 0x266, 0x3, 0x2, 0x2, 
    0x2, 0x86, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x88, 0x26f, 0x3, 0x2, 0x2, 0x2, 
    0x8a, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x284, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x286, 0x3, 0x2, 0x2, 0x2, 0x90, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x92, 0x29b, 
    0x3, 0x2, 0x2, 0x2, 0x94, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x96, 0x2a8, 0x3, 
    0x2, 0x2, 0x2, 0x98, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x2b4, 0x3, 0x2, 
    0x2, 0x2, 0x9c, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x2be, 0x3, 0x2, 0x2, 
    0x2, 0xa0, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x2c3, 0x3, 0x2, 0x2, 0x2, 
    0xa4, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0x2cf, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0xac, 0x2db, 
    0x3, 0x2, 0x2, 0x2, 0xae, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x2f5, 0x3, 
    0x2, 0x2, 0x2, 0xb2, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x2fe, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0x303, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x308, 0x3, 0x2, 0x2, 
    0x2, 0xba, 0x30f, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x313, 0x3, 0x2, 0x2, 0x2, 
    0xbe, 0x315, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x317, 0x3, 0x2, 0x2, 0x2, 0xc2, 
    0x31c, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc6, 0x5, 0x4, 0x3, 0x2, 0xc5, 0xc7, 
    0x7, 0x46, 0x2, 0x2, 0xc6, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x5, 0x8, 
    0x5, 0x2, 0xc9, 0xca, 0x7, 0x41, 0x2, 0x2, 0xca, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0xcb, 0xcc, 0x7, 0x1f, 0x2, 0x2, 0xcc, 0xd1, 0x5, 0x6, 0x4, 0x2, 
    0xcd, 0xce, 0x7, 0x39, 0x2, 0x2, 0xce, 0xcf, 0x5, 0x6a, 0x36, 0x2, 0xcf, 
    0xd0, 0x7, 0x3a, 0x2, 0x2, 0xd0, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xcd, 
    0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 
    0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x31, 0x2, 0x2, 0xd4, 0xde, 0x3, 0x2, 
    0x2, 0x2, 0xd5, 0xd6, 0x7, 0x45, 0x2, 0x2, 0xd6, 0xd7, 0x5, 0x6, 0x4, 
    0x2, 0xd7, 0xd8, 0x7, 0x31, 0x2, 0x2, 0xd8, 0xde, 0x3, 0x2, 0x2, 0x2, 
    0xd9, 0xda, 0x7, 0x1f, 0x2, 0x2, 0xda, 0xdb, 0x5, 0x6, 0x4, 0x2, 0xdb, 
    0xdc, 0x7, 0x31, 0x2, 0x2, 0xdc, 0xde, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xdd, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xd9, 0x3, 
    0x2, 0x2, 0x2, 0xde, 0x5, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x4f, 
    0x2, 0x2, 0xe0, 0x7, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe9, 0x5, 0xc, 0x7, 
    0x2, 0xe2, 0xe9, 0x5, 0x10, 0x9, 0x2, 0xe3, 0xe9, 0x5, 0x24, 0x13, 0x2, 
    0xe4, 0xe9, 0x5, 0x5a, 0x2e, 0x2, 0xe5, 0xe9, 0x5, 0x5e, 0x30, 0x2, 
    0xe6, 0xe9, 0x5, 0xa, 0x6, 0x2, 0xe7, 0xe9, 0x7, 0x49, 0x2, 0x2, 0xe8, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe3, 
    0x3, 0x2, 0x2, 0x2, 0xe8, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe5, 0x3, 
    0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe7, 0x3, 0x2, 
    0x2, 0x2, 0xe9, 0xec, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe8, 0x3, 0x2, 0x2, 
    0x2, 0xea, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xed, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x5, 0xa6, 0x54, 0x2, 0xee, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x47, 0x2, 0x2, 0xf0, 0xf1, 
    0x5, 0x6a, 0x36, 0x2, 0xf1, 0xf2, 0x7, 0x31, 0x2, 0x2, 0xf2, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0x17, 0x2, 0x2, 0xf4, 0xf9, 0x5, 0xe, 
    0x8, 0x2, 0xf5, 0xf6, 0x7, 0x30, 0x2, 0x2, 0xf6, 0xf8, 0x5, 0xe, 0x8, 
    0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfb, 0x3, 0x2, 0x2, 0x2, 
    0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfa, 
    0xfc, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 
    0x7, 0x31, 0x2, 0x2, 0xfd, 0xd, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x5, 
    0x1a, 0xe, 0x2, 0xff, 0xf, 0x3, 0x2, 0x2, 0x2, 0x100, 0x104, 0x7, 0xa, 
    0x2, 0x2, 0x101, 0x102, 0x5, 0x12, 0xa, 0x2, 0x102, 0x103, 0x7, 0x31, 
    0x2, 0x2, 0x103, 0x105, 0x3, 0x2, 0x2, 0x2, 0x104, 0x101, 0x3, 0x2, 
    0x2, 0x2, 0x105, 0x106, 0x3, 0x2, 0x2, 0x2, 0x106, 0x104, 0x3, 0x2, 
    0x2, 0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x108, 0x109, 0x5, 0x6, 0x4, 0x2, 0x109, 0x10a, 0x7, 0x33, 0x2, 
    0x2, 0x10a, 0x10b, 0x5, 0x16, 0xc, 0x2, 0x10b, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x10c, 0x10d, 0x7, 0x9, 0x2, 0x2, 0x10d, 0x10e, 0x7, 0x39, 0x2, 
    0x2, 0x10e, 0x10f, 0x5, 0x1a, 0xe, 0x2, 0x10f, 0x110, 0x7, 0x3a, 0x2, 
    0x2, 0x110, 0x15, 0x3, 0x2, 0x2, 0x2, 0x111, 0x11c, 0x5, 0x18, 0xd, 
    0x2, 0x112, 0x113, 0x5, 0x1e, 0x10, 0x2, 0x113, 0x114, 0x5, 0x18, 0xd, 
    0x2, 0x114, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x115, 0x11c, 0x5, 0x6, 0x4, 
    0x2, 0x116, 0x117, 0x5, 0x1e, 0x10, 0x2, 0x117, 0x118, 0x5, 0x6, 0x4, 
    0x2, 0x118, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11c, 0x5, 0x22, 0x12, 
    0x2, 0x11a, 0x11c, 0x5, 0x14, 0xb, 0x2, 0x11b, 0x111, 0x3, 0x2, 0x2, 
    0x2, 0x11b, 0x112, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x115, 0x3, 0x2, 0x2, 
    0x2, 0x11b, 0x116, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 0x2, 
    0x2, 0x11b, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x11d, 0x120, 0x5, 0x1a, 0xe, 0x2, 0x11e, 0x120, 0x5, 0x1c, 0xf, 0x2, 
    0x11f, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11e, 0x3, 0x2, 0x2, 0x2, 
    0x120, 0x19, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x7, 0x51, 0x2, 0x2, 
    0x122, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x7, 0x52, 0x2, 0x2, 
    0x124, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x9, 0x2, 0x2, 0x2, 0x126, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x9, 0x3, 0x2, 0x2, 0x128, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x7, 0x50, 0x2, 0x2, 0x12a, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x12b, 0x12f, 0x7, 0x26, 0x2, 0x2, 0x12c, 0x12d, 
    0x5, 0x26, 0x14, 0x2, 0x12d, 0x12e, 0x7, 0x31, 0x2, 0x2, 0x12e, 0x130, 
    0x3, 0x2, 0x2, 0x2, 0x12f, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 
    0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 
    0x3, 0x2, 0x2, 0x2, 0x132, 0x25, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x5, 
    0x6, 0x4, 0x2, 0x134, 0x138, 0x7, 0x33, 0x2, 0x2, 0x135, 0x139, 0x5, 
    0x2c, 0x17, 0x2, 0x136, 0x139, 0x5, 0x28, 0x15, 0x2, 0x137, 0x139, 0x5, 
    0x2a, 0x16, 0x2, 0x138, 0x135, 0x3, 0x2, 0x2, 0x2, 0x138, 0x136, 0x3, 
    0x2, 0x2, 0x2, 0x138, 0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x13a, 0x13c, 0x7, 0x12, 0x2, 0x2, 0x13b, 0x13d, 0x5, 0x64, 
    0x33, 0x2, 0x13c, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 0x3, 0x2, 
    0x2, 0x2, 0x13d, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x32, 
    0x2, 0x2, 0x13f, 0x140, 0x5, 0x70, 0x39, 0x2, 0x140, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x143, 0x7, 0x1e, 0x2, 0x2, 0x142, 0x144, 0x5, 0x64, 
    0x33, 0x2, 0x143, 0x142, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x3, 0x2, 
    0x2, 0x2, 0x144, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x145, 0x149, 0x5, 0x2e, 
    0x18, 0x2, 0x146, 0x149, 0x5, 0x36, 0x1c, 0x2, 0x147, 0x149, 0x5, 0x58, 
    0x2d, 0x2, 0x148, 0x145, 0x3, 0x2, 0x2, 0x2, 0x148, 0x146, 0x3, 0x2, 
    0x2, 0x2, 0x148, 0x147, 0x3, 0x2, 0x2, 0x2, 0x149, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0x14a, 0x14f, 0x5, 0x30, 0x19, 0x2, 0x14b, 0x14f, 0x5, 0x32, 0x1a, 
    0x2, 0x14c, 0x14f, 0x5, 0x34, 0x1b, 0x2, 0x14d, 0x14f, 0x5, 0x3a, 0x1e, 
    0x2, 0x14e, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14b, 0x3, 0x2, 0x2, 
    0x2, 0x14e, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14d, 0x3, 0x2, 0x2, 
    0x2, 0x14f, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x150, 0x151, 0x7, 0x39, 0x2, 
    0x2, 0x151, 0x152, 0x5, 0x6a, 0x36, 0x2, 0x152, 0x153, 0x7, 0x3a, 0x2, 
    0x2, 0x153, 0x31, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x5, 0x16, 0xc, 
    0x2, 0x155, 0x156, 0x7, 0x42, 0x2, 0x2, 0x156, 0x157, 0x5, 0x16, 0xc, 
    0x2, 0x157, 0x33, 0x3, 0x2, 0x2, 0x2, 0x158, 0x15b, 0x5, 0x6, 0x4, 0x2, 
    0x159, 0x15b, 0x9, 0x4, 0x2, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 0x2, 
    0x15a, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x35, 0x3, 0x2, 0x2, 0x2, 0x15c, 
    0x15d, 0x7, 0x1d, 0x2, 0x2, 0x15d, 0x160, 0x5, 0x38, 0x1d, 0x2, 0x15e, 
    0x160, 0x5, 0x38, 0x1d, 0x2, 0x15f, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15f, 
    0x15e, 0x3, 0x2, 0x2, 0x2, 0x160, 0x37, 0x3, 0x2, 0x2, 0x2, 0x161, 0x166, 
    0x5, 0x3c, 0x1f, 0x2, 0x162, 0x166, 0x5, 0x44, 0x23, 0x2, 0x163, 0x166, 
    0x5, 0x52, 0x2a, 0x2, 0x164, 0x166, 0x5, 0x56, 0x2c, 0x2, 0x165, 0x161, 
    0x3, 0x2, 0x2, 0x2, 0x165, 0x162, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 
    0x3, 0x2, 0x2, 0x2, 0x165, 0x164, 0x3, 0x2, 0x2, 0x2, 0x166, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x167, 0x168, 0x7, 0x48, 0x2, 0x2, 0x168, 0x16b, 0x7, 
    0x3b, 0x2, 0x2, 0x169, 0x16c, 0x5, 0x6, 0x4, 0x2, 0x16a, 0x16c, 0x5, 
    0x18, 0xd, 0x2, 0x16b, 0x169, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16a, 0x3, 
    0x2, 0x2, 0x2, 0x16c, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0x7, 
    0x3d, 0x2, 0x2, 0x16e, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 0x7, 
    0x4, 0x2, 0x2, 0x170, 0x171, 0x7, 0x3b, 0x2, 0x2, 0x171, 0x172, 0x5, 
    0x3e, 0x20, 0x2, 0x172, 0x173, 0x7, 0x3d, 0x2, 0x2, 0x173, 0x174, 0x7, 
    0x1b, 0x2, 0x2, 0x174, 0x175, 0x5, 0x42, 0x22, 0x2, 0x175, 0x17e, 0x3, 
    0x2, 0x2, 0x2, 0x176, 0x177, 0x7, 0x4, 0x2, 0x2, 0x177, 0x178, 0x7, 
    0x3c, 0x2, 0x2, 0x178, 0x179, 0x5, 0x3e, 0x20, 0x2, 0x179, 0x17a, 0x7, 
    0x3e, 0x2, 0x2, 0x17a, 0x17b, 0x7, 0x1b, 0x2, 0x2, 0x17b, 0x17c, 0x5, 
    0x42, 0x22, 0x2, 0x17c, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x16f, 0x3, 
    0x2, 0x2, 0x2, 0x17d, 0x176, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x17f, 0x184, 0x5, 0x40, 0x21, 0x2, 0x180, 0x181, 0x7, 0x30, 
    0x2, 0x2, 0x181, 0x183, 0x5, 0x40, 0x21, 0x2, 0x182, 0x180, 0x3, 0x2, 
    0x2, 0x2, 0x183, 0x186, 0x3, 0x2, 0x2, 0x2, 0x184, 0x182, 0x3, 0x2, 
    0x2, 0x2, 0x184, 0x185, 0x3, 0x2, 0x2, 0x2, 0x185, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x186, 0x184, 0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 0x5, 0x2e, 0x18, 
    0x2, 0x188, 0x41, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x5, 0x2c, 0x17, 
    0x2, 0x18a, 0x43, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18d, 0x7, 0x21, 0x2, 
    0x2, 0x18c, 0x18e, 0x5, 0x46, 0x24, 0x2, 0x18d, 0x18c, 0x3, 0x2, 0x2, 
    0x2, 0x18d, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 0x3, 0x2, 0x2, 
    0x2, 0x18f, 0x190, 0x7, 0xf, 0x2, 0x2, 0x190, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x191, 0x194, 0x5, 0x48, 0x25, 0x2, 0x192, 0x193, 0x7, 0x31, 0x2, 0x2, 
    0x193, 0x195, 0x5, 0x4c, 0x27, 0x2, 0x194, 0x192, 0x3, 0x2, 0x2, 0x2, 
    0x194, 0x195, 0x3, 0x2, 0x2, 0x2, 0x195, 0x198, 0x3, 0x2, 0x2, 0x2, 
    0x196, 0x198, 0x5, 0x4c, 0x27, 0x2, 0x197, 0x191, 0x3, 0x2, 0x2, 0x2, 
    0x197, 0x196, 0x3, 0x2, 0x2, 0x2, 0x198, 0x47, 0x3, 0x2, 0x2, 0x2, 0x199, 
    0x19e, 0x5, 0x4a, 0x26, 0x2, 0x19a, 0x19b, 0x7, 0x31, 0x2, 0x2, 0x19b, 
    0x19d, 0x5, 0x4a, 0x26, 0x2, 0x19c, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19d, 
    0x1a0, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19e, 
    0x19f, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x19e, 
    0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x5, 0x6a, 0x36, 0x2, 0x1a2, 0x1a3, 
    0x7, 0x32, 0x2, 0x2, 0x1a3, 0x1a4, 0x5, 0x2c, 0x17, 0x2, 0x1a4, 0x4b, 
    0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a6, 0x7, 0x7, 0x2, 0x2, 0x1a6, 0x1a7, 
    0x5, 0x4e, 0x28, 0x2, 0x1a7, 0x1a8, 0x7, 0x1b, 0x2, 0x2, 0x1a8, 0x1ad, 
    0x5, 0x50, 0x29, 0x2, 0x1a9, 0x1aa, 0x7, 0x31, 0x2, 0x2, 0x1aa, 0x1ac, 
    0x5, 0x50, 0x29, 0x2, 0x1ab, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1af, 
    0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 
    0x3, 0x2, 0x2, 0x2, 0x1ae, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1ad, 0x3, 
    0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x5, 0x6, 0x4, 0x2, 0x1b1, 0x1b2, 0x7, 
    0x32, 0x2, 0x2, 0x1b2, 0x1b3, 0x5, 0x34, 0x1b, 0x2, 0x1b3, 0x1b6, 0x3, 
    0x2, 0x2, 0x2, 0x1b4, 0x1b6, 0x5, 0x34, 0x1b, 0x2, 0x1b5, 0x1b0, 0x3, 
    0x2, 0x2, 0x2, 0x1b5, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x1b7, 0x1b8, 0x5, 0x6c, 0x37, 0x2, 0x1b8, 0x1b9, 0x7, 0x32, 
    0x2, 0x2, 0x1b9, 0x1ba, 0x7, 0x39, 0x2, 0x2, 0x1ba, 0x1bb, 0x5, 0x46, 
    0x24, 0x2, 0x1bb, 0x1bc, 0x7, 0x3a, 0x2, 0x2, 0x1bc, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x1bd, 0x1be, 0x7, 0x23, 0x2, 0x2, 0x1be, 0x1bf, 0x7, 0x1b, 
    0x2, 0x2, 0x1bf, 0x1c0, 0x5, 0x54, 0x2b, 0x2, 0x1c0, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x1c1, 0x1c2, 0x5, 0x2e, 0x18, 0x2, 0x1c2, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0x1c3, 0x1c4, 0x7, 0x10, 0x2, 0x2, 0x1c4, 0x1c5, 0x7, 0x1b, 
    0x2, 0x2, 0x1c5, 0x1c8, 0x5, 0x2c, 0x17, 0x2, 0x1c6, 0x1c8, 0x7, 0x10, 
    0x2, 0x2, 0x1c7, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c6, 0x3, 0x2, 
    0x2, 0x2, 0x1c8, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x7, 0x3f, 
    0x2, 0x2, 0x1ca, 0x1cb, 0x5, 0x34, 0x1b, 0x2, 0x1cb, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x1cc, 0x1cd, 0x7, 0x28, 0x2, 0x2, 0x1cd, 0x1d2, 0x5, 0x5c, 
    0x2f, 0x2, 0x1ce, 0x1cf, 0x7, 0x31, 0x2, 0x2, 0x1cf, 0x1d1, 0x5, 0x5c, 
    0x2f, 0x2, 0x1d0, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d4, 0x3, 0x2, 
    0x2, 0x2, 0x1d2, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d3, 0x3, 0x2, 
    0x2, 0x2, 0x1d3, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d2, 0x3, 0x2, 
    0x2, 0x2, 0x1d5, 0x1d6, 0x7, 0x31, 0x2, 0x2, 0x1d6, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x1d7, 0x1d8, 0x5, 0x6a, 0x36, 0x2, 0x1d8, 0x1d9, 0x7, 0x32, 
    0x2, 0x2, 0x1d9, 0x1da, 0x5, 0x2c, 0x17, 0x2, 0x1da, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0x1db, 0x1dc, 0x5, 0x60, 0x31, 0x2, 0x1dc, 0x1dd, 0x7, 0x31, 
    0x2, 0x2, 0x1dd, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e1, 0x5, 0x62, 
    0x32, 0x2, 0x1df, 0x1e1, 0x5, 0x6e, 0x38, 0x2, 0x1e0, 0x1de, 0x3, 0x2, 
    0x2, 0x2, 0x1e0, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x1e2, 0x1e3, 0x7, 0x1e, 0x2, 0x2, 0x1e3, 0x1e5, 0x5, 0x6, 0x4, 
    0x2, 0x1e4, 0x1e6, 0x5, 0x64, 0x33, 0x2, 0x1e5, 0x1e4, 0x3, 0x2, 0x2, 
    0x2, 0x1e5, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e7, 0x3, 0x2, 0x2, 
    0x2, 0x1e7, 0x1e8, 0x7, 0x31, 0x2, 0x2, 0x1e8, 0x1e9, 0x5, 0x8, 0x5, 
    0x2, 0x1e9, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x7, 0x39, 0x2, 
    0x2, 0x1eb, 0x1f0, 0x5, 0x66, 0x34, 0x2, 0x1ec, 0x1ed, 0x7, 0x31, 0x2, 
    0x2, 0x1ed, 0x1ef, 0x5, 0x66, 0x34, 0x2, 0x1ee, 0x1ec, 0x3, 0x2, 0x2, 
    0x2, 0x1ef, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1ee, 0x3, 0x2, 0x2, 
    0x2, 0x1f0, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f3, 0x3, 0x2, 0x2, 
    0x2, 0x1f2, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x7, 0x3a, 0x2, 
    0x2, 0x1f4, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1fd, 0x5, 0x68, 0x35, 
    0x2, 0x1f6, 0x1f7, 0x7, 0x28, 0x2, 0x2, 0x1f7, 0x1fd, 0x5, 0x68, 0x35, 
    0x2, 0x1f8, 0x1f9, 0x7, 0x12, 0x2, 0x2, 0x1f9, 0x1fd, 0x5, 0x68, 0x35, 
    0x2, 0x1fa, 0x1fb, 0x7, 0x1e, 0x2, 0x2, 0x1fb, 0x1fd, 0x5, 0x68, 0x35, 
    0x2, 0x1fc, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1f6, 0x3, 0x2, 0x2, 
    0x2, 0x1fc, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fa, 0x3, 0x2, 0x2, 
    0x2, 0x1fd, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ff, 0x5, 0x6a, 0x36, 
    0x2, 0x1ff, 0x200, 0x7, 0x32, 0x2, 0x2, 0x200, 0x201, 0x5, 0x34, 0x1b, 
    0x2, 0x201, 0x69, 0x3, 0x2, 0x2, 0x2, 0x202, 0x207, 0x5, 0x6, 0x4, 0x2, 
    0x203, 0x204, 0x7, 0x30, 0x2, 0x2, 0x204, 0x206, 0x5, 0x6, 0x4, 0x2, 
    0x205, 0x203, 0x3, 0x2, 0x2, 0x2, 0x206, 0x209, 0x3, 0x2, 0x2, 0x2, 
    0x207, 0x205, 0x3, 0x2, 0x2, 0x2, 0x207, 0x208, 0x3, 0x2, 0x2, 0x2, 
    0x208, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x209, 0x207, 0x3, 0x2, 0x2, 0x2, 0x20a, 
    0x20f, 0x5, 0x16, 0xc, 0x2, 0x20b, 0x20c, 0x7, 0x30, 0x2, 0x2, 0x20c, 
    0x20e, 0x5, 0x16, 0xc, 0x2, 0x20d, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x20e, 
    0x211, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20f, 
    0x210, 0x3, 0x2, 0x2, 0x2, 0x210, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x211, 0x20f, 
    0x3, 0x2, 0x2, 0x2, 0x212, 0x213, 0x7, 0x12, 0x2, 0x2, 0x213, 0x215, 
    0x5, 0x6, 0x4, 0x2, 0x214, 0x216, 0x5, 0x64, 0x33, 0x2, 0x215, 0x214, 
    0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 
    0x3, 0x2, 0x2, 0x2, 0x217, 0x218, 0x7, 0x32, 0x2, 0x2, 0x218, 0x219, 
    0x5, 0x70, 0x39, 0x2, 0x219, 0x21a, 0x7, 0x31, 0x2, 0x2, 0x21a, 0x21b, 
    0x5, 0x8, 0x5, 0x2, 0x21b, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21d, 0x5, 
    0x34, 0x1b, 0x2, 0x21d, 0x71, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21f, 0x5, 
    0xe, 0x8, 0x2, 0x21f, 0x220, 0x7, 0x32, 0x2, 0x2, 0x220, 0x221, 0x5, 
    0x74, 0x3b, 0x2, 0x221, 0x224, 0x3, 0x2, 0x2, 0x2, 0x222, 0x224, 0x5, 
    0x74, 0x3b, 0x2, 0x223, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x223, 0x222, 0x3, 
    0x2, 0x2, 0x2, 0x224, 0x73, 0x3, 0x2, 0x2, 0x2, 0x225, 0x228, 0x5, 0x76, 
    0x3c, 0x2, 0x226, 0x228, 0x5, 0xa4, 0x53, 0x2, 0x227, 0x225, 0x3, 0x2, 
    0x2, 0x2, 0x227, 0x226, 0x3, 0x2, 0x2, 0x2, 0x228, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x229, 0x22e, 0x5, 0x78, 0x3d, 0x2, 0x22a, 0x22e, 0x5, 0x98, 0x4d, 
    0x2, 0x22b, 0x22e, 0x5, 0x9e, 0x50, 0x2, 0x22c, 0x22e, 0x5, 0xa0, 0x51, 
    0x2, 0x22d, 0x229, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22a, 0x3, 0x2, 0x2, 
    0x2, 0x22d, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22c, 0x3, 0x2, 0x2, 
    0x2, 0x22e, 0x77, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x230, 0x5, 0x7a, 0x3e, 
    0x2, 0x230, 0x231, 0x7, 0x2f, 0x2, 0x2, 0x231, 0x232, 0x5, 0x7c, 0x3f, 
    0x2, 0x232, 0x79, 0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 0x7, 0x40, 0x2, 
    0x2, 0x234, 0x237, 0x5, 0x6, 0x4, 0x2, 0x235, 0x237, 0x5, 0x6, 0x4, 
    0x2, 0x236, 0x233, 0x3, 0x2, 0x2, 0x2, 0x236, 0x235, 0x3, 0x2, 0x2, 
    0x2, 0x237, 0x253, 0x3, 0x2, 0x2, 0x2, 0x238, 0x239, 0x7, 0x3b, 0x2, 
    0x2, 0x239, 0x23e, 0x5, 0x7c, 0x3f, 0x2, 0x23a, 0x23b, 0x7, 0x30, 0x2, 
    0x2, 0x23b, 0x23d, 0x5, 0x7c, 0x3f, 0x2, 0x23c, 0x23a, 0x3, 0x2, 0x2, 
    0x2, 0x23d, 0x240, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23c, 0x3, 0x2, 0x2, 
    0x2, 0x23e, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x241, 0x3, 0x2, 0x2, 
    0x2, 0x240, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x241, 0x242, 0x7, 0x3d, 0x2, 
    0x2, 0x242, 0x252, 0x3, 0x2, 0x2, 0x2, 0x243, 0x244, 0x7, 0x3c, 0x2, 
    0x2, 0x244, 0x249, 0x5, 0x7c, 0x3f, 0x2, 0x245, 0x246, 0x7, 0x30, 0x2, 
    0x2, 0x246, 0x248, 0x5, 0x7c, 0x3f, 0x2, 0x247, 0x245, 0x3, 0x2, 0x2, 
    0x2, 0x248, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x249, 0x247, 0x3, 0x2, 0x2, 
    0x2, 0x249, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x24c, 0x3, 0x2, 0x2, 
    0x2, 0x24b, 0x249, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24d, 0x7, 0x3e, 0x2, 
    0x2, 0x24d, 0x252, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 0x7, 0x41, 0x2, 
    0x2, 0x24f, 0x252, 0x5, 0x6, 0x4, 0x2, 0x250, 0x252, 0x7, 0x3f, 0x2, 
    0x2, 0x251, 0x238, 0x3, 0x2, 0x2, 0x2, 0x251, 0x243, 0x3, 0x2, 0x2, 
    0x2, 0x251, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x251, 0x250, 0x3, 0x2, 0x2, 
    0x2, 0x252, 0x255, 0x3, 0x2, 0x2, 0x2, 0x253, 0x251, 0x3, 0x2, 0x2, 
    0x2, 0x253, 0x254, 0x3, 0x2, 0x2, 0x2, 0x254, 0x7b, 0x3, 0x2, 0x2, 0x2, 
    0x255, 0x253, 0x3, 0x2, 0x2, 0x2, 0x256, 0x25a, 0x5, 0x80, 0x41, 0x2, 
    0x257, 0x258, 0x5, 0x7e, 0x40, 0x2, 0x258, 0x259, 0x5, 0x7c, 0x3f, 0x2, 
    0x259, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x257, 0x3, 0x2, 0x2, 0x2, 
    0x25a, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x25c, 
    0x25d, 0x9, 0x5, 0x2, 0x2, 0x25d, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x262, 
    0x5, 0x84, 0x43, 0x2, 0x25f, 0x260, 0x5, 0x82, 0x42, 0x2, 0x260, 0x261, 
    0x5, 0x80, 0x41, 0x2, 0x261, 0x263, 0x3, 0x2, 0x2, 0x2, 0x262, 0x25f, 
    0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x3, 0x2, 0x2, 0x2, 0x263, 0x81, 0x3, 
    0x2, 0x2, 0x2, 0x264, 0x265, 0x9, 0x6, 0x2, 0x2, 0x265, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x266, 0x26a, 0x5, 0x88, 0x45, 0x2, 0x267, 0x268, 0x5, 0x86, 
    0x44, 0x2, 0x268, 0x269, 0x5, 0x84, 0x43, 0x2, 0x269, 0x26b, 0x3, 0x2, 
    0x2, 0x2, 0x26a, 0x267, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x26b, 0x3, 0x2, 
    0x2, 0x2, 0x26b, 0x85, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26d, 0x9, 0x7, 0x2, 
    0x2, 0x26d, 0x87, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x270, 0x9, 0x2, 0x2, 0x2, 
    0x26f, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 0x3, 0x2, 0x2, 0x2, 
    0x270, 0x271, 0x3, 0x2, 0x2, 0x2, 0x271, 0x272, 0x5, 0x8a, 0x46, 0x2, 
    0x272, 0x89, 0x3, 0x2, 0x2, 0x2, 0x273, 0x27f, 0x5, 0x7a, 0x3e, 0x2, 
    0x274, 0x275, 0x7, 0x39, 0x2, 0x2, 0x275, 0x276, 0x5, 0x7c, 0x3f, 0x2, 
    0x276, 0x277, 0x7, 0x3a, 0x2, 0x2, 0x277, 0x27f, 0x3, 0x2, 0x2, 0x2, 
    0x278, 0x27f, 0x5, 0x8e, 0x48, 0x2, 0x279, 0x27f, 0x5, 0x8c, 0x47, 0x2, 
    0x27a, 0x27f, 0x5, 0x92, 0x4a, 0x2, 0x27b, 0x27c, 0x7, 0x1a, 0x2, 0x2, 
    0x27c, 0x27f, 0x5, 0x8a, 0x46, 0x2, 0x27d, 0x27f, 0x5, 0x20, 0x11, 0x2, 
    0x27e, 0x273, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x274, 0x3, 0x2, 0x2, 0x2, 
    0x27e, 0x278, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x279, 0x3, 0x2, 0x2, 0x2, 
    0x27e, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27b, 0x3, 0x2, 0x2, 0x2, 
    0x27e, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x280, 
    0x285, 0x5, 0x18, 0xd, 0x2, 0x281, 0x285, 0x5, 0x14, 0xb, 0x2, 0x282, 
    0x285, 0x5, 0x22, 0x12, 0x2, 0x283, 0x285, 0x7, 0x19, 0x2, 0x2, 0x284, 
    0x280, 0x3, 0x2, 0x2, 0x2, 0x284, 0x281, 0x3, 0x2, 0x2, 0x2, 0x284, 
    0x282, 0x3, 0x2, 0x2, 0x2, 0x284, 0x283, 0x3, 0x2, 0x2, 0x2, 0x285, 
    0x8d, 0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 0x5, 0x6, 0x4, 0x2, 0x287, 0x288, 
    0x7, 0x39, 0x2, 0x2, 0x288, 0x289, 0x5, 0x90, 0x49, 0x2, 0x289, 0x28a, 
    0x7, 0x3a, 0x2, 0x2, 0x28a, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x290, 
    0x5, 0x9a, 0x4e, 0x2, 0x28c, 0x28d, 0x7, 0x30, 0x2, 0x2, 0x28d, 0x28f, 
    0x5, 0x9a, 0x4e, 0x2, 0x28e, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x292, 
    0x3, 0x2, 0x2, 0x2, 0x290, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x290, 0x291, 
    0x3, 0x2, 0x2, 0x2, 0x291, 0x91, 0x3, 0x2, 0x2, 0x2, 0x292, 0x290, 0x3, 
    0x2, 0x2, 0x2, 0x293, 0x294, 0x7, 0x3b, 0x2, 0x2, 0x294, 0x295, 0x5, 
    0x94, 0x4b, 0x2, 0x295, 0x296, 0x7, 0x3d, 0x2, 0x2, 0x296, 0x29c, 0x3, 
    0x2, 0x2, 0x2, 0x297, 0x298, 0x7, 0x3c, 0x2, 0x2, 0x298, 0x299, 0x5, 
    0x94, 0x4b, 0x2, 0x299, 0x29a, 0x7, 0x3e, 0x2, 0x2, 0x29a, 0x29c, 0x3, 
    0x2, 0x2, 0x2, 0x29b, 0x293, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x297, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x93, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x2a2, 0x5, 0x96, 
    0x4c, 0x2, 0x29e, 0x29f, 0x7, 0x30, 0x2, 0x2, 0x29f, 0x2a1, 0x5, 0x96, 
    0x4c, 0x2, 0x2a0, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a4, 0x3, 0x2, 
    0x2, 0x2, 0x2a2, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a3, 0x3, 0x2, 
    0x2, 0x2, 0x2a3, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a2, 0x3, 0x2, 
    0x2, 0x2, 0x2a5, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x29d, 0x3, 0x2, 
    0x2, 0x2, 0x2a6, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x2a8, 0x2ab, 0x5, 0x7c, 0x3f, 0x2, 0x2a9, 0x2aa, 0x7, 0x42, 0x2, 
    0x2, 0x2aa, 0x2ac, 0x5, 0x7c, 0x3f, 0x2, 0x2ab, 0x2a9, 0x3, 0x2, 0x2, 
    0x2, 0x2ab, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x2ad, 0x2b2, 0x5, 0x6, 0x4, 0x2, 0x2ae, 0x2af, 0x7, 0x39, 0x2, 0x2, 
    0x2af, 0x2b0, 0x5, 0x90, 0x49, 0x2, 0x2b0, 0x2b1, 0x7, 0x3a, 0x2, 0x2, 
    0x2b1, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2ae, 0x3, 0x2, 0x2, 0x2, 
    0x2b2, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x99, 0x3, 0x2, 0x2, 0x2, 0x2b4, 
    0x2b8, 0x5, 0x7c, 0x3f, 0x2, 0x2b5, 0x2b7, 0x5, 0x9c, 0x4f, 0x2, 0x2b6, 
    0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2b8, 
    0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2b9, 
    0x9b, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2bc, 
    0x7, 0x32, 0x2, 0x2, 0x2bc, 0x2bd, 0x5, 0x7c, 0x3f, 0x2, 0x2bd, 0x9d, 
    0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 0x7, 0x13, 0x2, 0x2, 0x2bf, 0x2c0, 
    0x5, 0xe, 0x8, 0x2, 0x2c0, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c2, 0x3, 
    0x2, 0x2, 0x2, 0x2c2, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 0x3, 0x2, 
    0x2, 0x2, 0x2c4, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2ca, 0x5, 0xa6, 
    0x54, 0x2, 0x2c6, 0x2ca, 0x5, 0xaa, 0x56, 0x2, 0x2c7, 0x2ca, 0x5, 0xb2, 
    0x5a, 0x2, 0x2c8, 0x2ca, 0x5, 0xc0, 0x61, 0x2, 0x2c9, 0x2c5, 0x3, 0x2, 
    0x2, 0x2, 0x2c9, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c9, 0x2c7, 0x3, 0x2, 
    0x2, 0x2, 0x2c9, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0x2cb, 0x2cc, 0x7, 0x5, 0x2, 0x2, 0x2cc, 0x2cd, 0x5, 0xa8, 0x55, 
    0x2, 0x2cd, 0x2ce, 0x7, 0xf, 0x2, 0x2, 0x2ce, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0x2cf, 0x2d4, 0x5, 0x72, 0x3a, 0x2, 0x2d0, 0x2d1, 0x7, 0x31, 0x2, 0x2, 
    0x2d1, 0x2d3, 0x5, 0x72, 0x3a, 0x2, 0x2d2, 0x2d0, 0x3, 0x2, 0x2, 0x2, 
    0x2d3, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d2, 0x3, 0x2, 0x2, 0x2, 
    0x2d4, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x2d6, 
    0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2da, 0x5, 0xac, 0x57, 0x2, 0x2d8, 
    0x2da, 0x5, 0xae, 0x58, 0x2, 0x2d9, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2d9, 
    0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2da, 0xab, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2dc, 
    0x7, 0x14, 0x2, 0x2, 0x2dc, 0x2dd, 0x5, 0x7c, 0x3f, 0x2, 0x2dd, 0x2de, 
    0x7, 0x24, 0x2, 0x2, 0x2de, 0x2e1, 0x5, 0x72, 0x3a, 0x2, 0x2df, 0x2e0, 
    0x7, 0xe, 0x2, 0x2, 0x2e0, 0x2e2, 0x5, 0x72, 0x3a, 0x2, 0x2e1, 0x2df, 
    0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e2, 0xad, 0x3, 
    0x2, 0x2, 0x2, 0x2e3, 0x2e4, 0x7, 0x7, 0x2, 0x2, 0x2e4, 0x2e5, 0x5, 
    0x7c, 0x3f, 0x2, 0x2e5, 0x2e6, 0x7, 0x1b, 0x2, 0x2, 0x2e6, 0x2eb, 0x5, 
    0xb0, 0x59, 0x2, 0x2e7, 0x2e8, 0x7, 0x31, 0x2, 0x2, 0x2e8, 0x2ea, 0x5, 
    0xb0, 0x59, 0x2, 0x2e9, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2ed, 0x3, 
    0x2, 0x2, 0x2, 0x2eb, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2ec, 0x3, 
    0x2, 0x2, 0x2, 0x2ec, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2eb, 0x3, 
    0x2, 0x2, 0x2, 0x2ee, 0x2ef, 0x7, 0x31, 0x2, 0x2, 0x2ef, 0x2f0, 0x7, 
    0xe, 0x2, 0x2, 0x2f0, 0x2f2, 0x5, 0xa8, 0x55, 0x2, 0x2f1, 0x2ee, 0x3, 
    0x2, 0x2, 0x2, 0x2f1, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f3, 0x3, 
    0x2, 0x2, 0x2, 0x2f3, 0x2f4, 0x7, 0xf, 0x2, 0x2, 0x2f4, 0xaf, 0x3, 0x2, 
    0x2, 0x2, 0x2f5, 0x2f6, 0x5, 0x6c, 0x37, 0x2, 0x2f6, 0x2f7, 0x7, 0x32, 
    0x2, 0x2, 0x2f7, 0x2f8, 0x5, 0x72, 0x3a, 0x2, 0x2f8, 0xb1, 0x3, 0x2, 
    0x2, 0x2, 0x2f9, 0x2fd, 0x5, 0xb4, 0x5b, 0x2, 0x2fa, 0x2fd, 0x5, 0xb6, 
    0x5c, 0x2, 0x2fb, 0x2fd, 0x5, 0xb8, 0x5d, 0x2, 0x2fc, 0x2f9, 0x3, 0x2, 
    0x2, 0x2, 0x2fc, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fb, 0x3, 0x2, 
    0x2, 0x2, 0x2fd, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2ff, 0x7, 0x29, 
    0x2, 0x2, 0x2ff, 0x300, 0x5, 0x7c, 0x3f, 0x2, 0x300, 0x301, 0x7, 0xc, 
    0x2, 0x2, 0x301, 0x302, 0x5, 0x72, 0x3a, 0x2, 0x302, 0xb5, 0x3, 0x2, 
    0x2, 0x2, 0x303, 0x304, 0x7, 0x22, 0x2, 0x2, 0x304, 0x305, 0x5, 0xa8, 
    0x55, 0x2, 0x305, 0x306, 0x7, 0x27, 0x2, 0x2, 0x306, 0x307, 0x5, 0x7c, 
    0x3f, 0x2, 0x307, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x308, 0x309, 0x7, 0x11, 
    0x2, 0x2, 0x309, 0x30a, 0x5, 0x6, 0x4, 0x2, 0x30a, 0x30b, 0x7, 0x2f, 
    0x2, 0x2, 0x30b, 0x30c, 0x5, 0xba, 0x5e, 0x2, 0x30c, 0x30d, 0x7, 0xc, 
    0x2, 0x2, 0x30d, 0x30e, 0x5, 0x72, 0x3a, 0x2, 0x30e, 0xb9, 0x3, 0x2, 
    0x2, 0x2, 0x30f, 0x310, 0x5, 0xbc, 0x5f, 0x2, 0x310, 0x311, 0x9, 0x8, 
    0x2, 0x2, 0x311, 0x312, 0x5, 0xbe, 0x60, 0x2, 0x312, 0xbb, 0x3, 0x2, 
    0x2, 0x2, 0x313, 0x314, 0x5, 0x7c, 0x3f, 0x2, 0x314, 0xbd, 0x3, 0x2, 
    0x2, 0x2, 0x315, 0x316, 0x5, 0x7c, 0x3f, 0x2, 0x316, 0xbf, 0x3, 0x2, 
    0x2, 0x2, 0x317, 0x318, 0x7, 0x2a, 0x2, 0x2, 0x318, 0x319, 0x5, 0xc2, 
    0x62, 0x2, 0x319, 0x31a, 0x7, 0xc, 0x2, 0x2, 0x31a, 0x31b, 0x5, 0x72, 
    0x3a, 0x2, 0x31b, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x321, 0x5, 0x7a, 
    0x3e, 0x2, 0x31d, 0x31e, 0x7, 0x30, 0x2, 0x2, 0x31e, 0x320, 0x5, 0x7a, 
    0x3e, 0x2, 0x31f, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x320, 0x323, 0x3, 0x2, 
    0x2, 0x2, 0x321, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x321, 0x322, 0x3, 0x2, 
    0x2, 0x2, 0x322, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x323, 0x321, 0x3, 0x2, 0x2, 
    0x2, 0x43, 0xc6, 0xd1, 0xdd, 0xe8, 0xea, 0xf9, 0x106, 0x11b, 0x11f, 
    0x131, 0x138, 0x13c, 0x143, 0x148, 0x14e, 0x15a, 0x15f, 0x165, 0x16b, 
    0x17d, 0x184, 0x18d, 0x194, 0x197, 0x19e, 0x1ad, 0x1b5, 0x1c7, 0x1d2, 
    0x1e0, 0x1e5, 0x1f0, 0x1fc, 0x207, 0x20f, 0x215, 0x223, 0x227, 0x22d, 
    0x236, 0x23e, 0x249, 0x251, 0x253, 0x25a, 0x262, 0x26a, 0x26f, 0x27e, 
    0x284, 0x290, 0x29b, 0x2a2, 0x2a6, 0x2ab, 0x2b2, 0x2b8, 0x2c9, 0x2d4, 
    0x2d9, 0x2e1, 0x2eb, 0x2f1, 0x2fc, 0x321, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ExprParser::Initializer ExprParser::_init;
