
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from src/Pascal.g4 by ANTLR 4.7.2


#include "PascalVisitor.h"

#include "PascalParser.h"


using namespace antlrcpp;
using namespace antlr4;

PascalParser::PascalParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

PascalParser::~PascalParser() {
  delete _interpreter;
}

std::string PascalParser::getGrammarFileName() const {
  return "Pascal.g4";
}

const std::vector<std::string>& PascalParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& PascalParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

PascalParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ProgramHeaderContext* PascalParser::ProgramContext::programHeader() {
  return getRuleContext<PascalParser::ProgramHeaderContext>(0);
}

PascalParser::BlockContext* PascalParser::ProgramContext::block() {
  return getRuleContext<PascalParser::BlockContext>(0);
}


size_t PascalParser::ProgramContext::getRuleIndex() const {
  return PascalParser::RuleProgram;
}


antlrcpp::Any PascalParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProgramContext* PascalParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, PascalParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    programHeader();
    setState(183);
    block();
    setState(184);
    match(PascalParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramHeaderContext ------------------------------------------------------------------

PascalParser::ProgramHeaderContext::ProgramHeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ProgramHeaderContext::PROGRAM() {
  return getToken(PascalParser::PROGRAM, 0);
}

PascalParser::ProgramIdentifierContext* PascalParser::ProgramHeaderContext::programIdentifier() {
  return getRuleContext<PascalParser::ProgramIdentifierContext>(0);
}

PascalParser::ProgramParametersContext* PascalParser::ProgramHeaderContext::programParameters() {
  return getRuleContext<PascalParser::ProgramParametersContext>(0);
}


size_t PascalParser::ProgramHeaderContext::getRuleIndex() const {
  return PascalParser::RuleProgramHeader;
}


antlrcpp::Any PascalParser::ProgramHeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProgramHeader(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProgramHeaderContext* PascalParser::programHeader() {
  ProgramHeaderContext *_localctx = _tracker.createInstance<ProgramHeaderContext>(_ctx, getState());
  enterRule(_localctx, 2, PascalParser::RuleProgramHeader);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(PascalParser::PROGRAM);
    setState(187);
    programIdentifier();
    setState(189);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__2) {
      setState(188);
      programParameters();
    }
    setState(191);
    match(PascalParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramParametersContext ------------------------------------------------------------------

PascalParser::ProgramParametersContext::ProgramParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PascalParser::ProgramParametersContext::IDENTIFIER() {
  return getTokens(PascalParser::IDENTIFIER);
}

tree::TerminalNode* PascalParser::ProgramParametersContext::IDENTIFIER(size_t i) {
  return getToken(PascalParser::IDENTIFIER, i);
}


size_t PascalParser::ProgramParametersContext::getRuleIndex() const {
  return PascalParser::RuleProgramParameters;
}


antlrcpp::Any PascalParser::ProgramParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProgramParameters(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProgramParametersContext* PascalParser::programParameters() {
  ProgramParametersContext *_localctx = _tracker.createInstance<ProgramParametersContext>(_ctx, getState());
  enterRule(_localctx, 4, PascalParser::RuleProgramParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    match(PascalParser::T__2);
    setState(194);
    match(PascalParser::IDENTIFIER);
    setState(199);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__3) {
      setState(195);
      match(PascalParser::T__3);
      setState(196);
      match(PascalParser::IDENTIFIER);
      setState(201);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(202);
    match(PascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramIdentifierContext ------------------------------------------------------------------

PascalParser::ProgramIdentifierContext::ProgramIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ProgramIdentifierContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::ProgramIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleProgramIdentifier;
}


antlrcpp::Any PascalParser::ProgramIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProgramIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProgramIdentifierContext* PascalParser::programIdentifier() {
  ProgramIdentifierContext *_localctx = _tracker.createInstance<ProgramIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 6, PascalParser::RuleProgramIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

PascalParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::DeclarationsContext* PascalParser::BlockContext::declarations() {
  return getRuleContext<PascalParser::DeclarationsContext>(0);
}

PascalParser::CompoundStatementContext* PascalParser::BlockContext::compoundStatement() {
  return getRuleContext<PascalParser::CompoundStatementContext>(0);
}


size_t PascalParser::BlockContext::getRuleIndex() const {
  return PascalParser::RuleBlock;
}


antlrcpp::Any PascalParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::BlockContext* PascalParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 8, PascalParser::RuleBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    declarations();
    setState(207);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

PascalParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ConstantsPartContext* PascalParser::DeclarationsContext::constantsPart() {
  return getRuleContext<PascalParser::ConstantsPartContext>(0);
}

PascalParser::TypesPartContext* PascalParser::DeclarationsContext::typesPart() {
  return getRuleContext<PascalParser::TypesPartContext>(0);
}

PascalParser::VariablesPartContext* PascalParser::DeclarationsContext::variablesPart() {
  return getRuleContext<PascalParser::VariablesPartContext>(0);
}

PascalParser::RoutinesPartContext* PascalParser::DeclarationsContext::routinesPart() {
  return getRuleContext<PascalParser::RoutinesPartContext>(0);
}


size_t PascalParser::DeclarationsContext::getRuleIndex() const {
  return PascalParser::RuleDeclarations;
}


antlrcpp::Any PascalParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::DeclarationsContext* PascalParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 10, PascalParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::CONST) {
      setState(209);
      constantsPart();
      setState(210);
      match(PascalParser::T__1);
    }
    setState(217);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::TYPE) {
      setState(214);
      typesPart();
      setState(215);
      match(PascalParser::T__1);
    }
    setState(222);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::VAR) {
      setState(219);
      variablesPart();
      setState(220);
      match(PascalParser::T__1);
    }
    setState(227);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::PROCEDURE

    || _la == PascalParser::FUNCTION) {
      setState(224);
      routinesPart();
      setState(225);
      match(PascalParser::T__1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantsPartContext ------------------------------------------------------------------

PascalParser::ConstantsPartContext::ConstantsPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ConstantsPartContext::CONST() {
  return getToken(PascalParser::CONST, 0);
}

PascalParser::ConstantDefinitionsListContext* PascalParser::ConstantsPartContext::constantDefinitionsList() {
  return getRuleContext<PascalParser::ConstantDefinitionsListContext>(0);
}


size_t PascalParser::ConstantsPartContext::getRuleIndex() const {
  return PascalParser::RuleConstantsPart;
}


antlrcpp::Any PascalParser::ConstantsPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstantsPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantsPartContext* PascalParser::constantsPart() {
  ConstantsPartContext *_localctx = _tracker.createInstance<ConstantsPartContext>(_ctx, getState());
  enterRule(_localctx, 12, PascalParser::RuleConstantsPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    match(PascalParser::CONST);
    setState(230);
    constantDefinitionsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDefinitionsListContext ------------------------------------------------------------------

PascalParser::ConstantDefinitionsListContext::ConstantDefinitionsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::ConstantDefinitionContext *> PascalParser::ConstantDefinitionsListContext::constantDefinition() {
  return getRuleContexts<PascalParser::ConstantDefinitionContext>();
}

PascalParser::ConstantDefinitionContext* PascalParser::ConstantDefinitionsListContext::constantDefinition(size_t i) {
  return getRuleContext<PascalParser::ConstantDefinitionContext>(i);
}


size_t PascalParser::ConstantDefinitionsListContext::getRuleIndex() const {
  return PascalParser::RuleConstantDefinitionsList;
}


antlrcpp::Any PascalParser::ConstantDefinitionsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstantDefinitionsList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantDefinitionsListContext* PascalParser::constantDefinitionsList() {
  ConstantDefinitionsListContext *_localctx = _tracker.createInstance<ConstantDefinitionsListContext>(_ctx, getState());
  enterRule(_localctx, 14, PascalParser::RuleConstantDefinitionsList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(232);
    constantDefinition();
    setState(237);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(233);
        match(PascalParser::T__1);
        setState(234);
        constantDefinition(); 
      }
      setState(239);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDefinitionContext ------------------------------------------------------------------

PascalParser::ConstantDefinitionContext::ConstantDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ConstantIdentifierContext* PascalParser::ConstantDefinitionContext::constantIdentifier() {
  return getRuleContext<PascalParser::ConstantIdentifierContext>(0);
}

PascalParser::ConstantContext* PascalParser::ConstantDefinitionContext::constant() {
  return getRuleContext<PascalParser::ConstantContext>(0);
}


size_t PascalParser::ConstantDefinitionContext::getRuleIndex() const {
  return PascalParser::RuleConstantDefinition;
}


antlrcpp::Any PascalParser::ConstantDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstantDefinition(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantDefinitionContext* PascalParser::constantDefinition() {
  ConstantDefinitionContext *_localctx = _tracker.createInstance<ConstantDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 16, PascalParser::RuleConstantDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    constantIdentifier();
    setState(241);
    match(PascalParser::T__5);
    setState(242);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantIdentifierContext ------------------------------------------------------------------

PascalParser::ConstantIdentifierContext::ConstantIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ConstantIdentifierContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::ConstantIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleConstantIdentifier;
}


antlrcpp::Any PascalParser::ConstantIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstantIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantIdentifierContext* PascalParser::constantIdentifier() {
  ConstantIdentifierContext *_localctx = _tracker.createInstance<ConstantIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 18, PascalParser::RuleConstantIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

PascalParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ConstantContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}

PascalParser::UnsignedNumberContext* PascalParser::ConstantContext::unsignedNumber() {
  return getRuleContext<PascalParser::UnsignedNumberContext>(0);
}

PascalParser::SignContext* PascalParser::ConstantContext::sign() {
  return getRuleContext<PascalParser::SignContext>(0);
}

PascalParser::CharacterConstantContext* PascalParser::ConstantContext::characterConstant() {
  return getRuleContext<PascalParser::CharacterConstantContext>(0);
}

PascalParser::StringConstantContext* PascalParser::ConstantContext::stringConstant() {
  return getRuleContext<PascalParser::StringConstantContext>(0);
}


size_t PascalParser::ConstantContext::getRuleIndex() const {
  return PascalParser::RuleConstant;
}


antlrcpp::Any PascalParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantContext* PascalParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 20, PascalParser::RuleConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(255);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::T__6:
      case PascalParser::T__7:
      case PascalParser::IDENTIFIER:
      case PascalParser::INTEGER:
      case PascalParser::REAL: {
        enterOuterAlt(_localctx, 1);
        setState(247);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PascalParser::T__6

        || _la == PascalParser::T__7) {
          setState(246);
          sign();
        }
        setState(251);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PascalParser::IDENTIFIER: {
            setState(249);
            match(PascalParser::IDENTIFIER);
            break;
          }

          case PascalParser::INTEGER:
          case PascalParser::REAL: {
            setState(250);
            unsignedNumber();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case PascalParser::CHARACTER: {
        enterOuterAlt(_localctx, 2);
        setState(253);
        characterConstant();
        break;
      }

      case PascalParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(254);
        stringConstant();
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

//----------------- SignContext ------------------------------------------------------------------

PascalParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalParser::SignContext::getRuleIndex() const {
  return PascalParser::RuleSign;
}


antlrcpp::Any PascalParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::SignContext* PascalParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 22, PascalParser::RuleSign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    _la = _input->LA(1);
    if (!(_la == PascalParser::T__6

    || _la == PascalParser::T__7)) {
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

//----------------- TypesPartContext ------------------------------------------------------------------

PascalParser::TypesPartContext::TypesPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::TypesPartContext::TYPE() {
  return getToken(PascalParser::TYPE, 0);
}

PascalParser::TypeDefinitionsListContext* PascalParser::TypesPartContext::typeDefinitionsList() {
  return getRuleContext<PascalParser::TypeDefinitionsListContext>(0);
}


size_t PascalParser::TypesPartContext::getRuleIndex() const {
  return PascalParser::RuleTypesPart;
}


antlrcpp::Any PascalParser::TypesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypesPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TypesPartContext* PascalParser::typesPart() {
  TypesPartContext *_localctx = _tracker.createInstance<TypesPartContext>(_ctx, getState());
  enterRule(_localctx, 24, PascalParser::RuleTypesPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    match(PascalParser::TYPE);
    setState(260);
    typeDefinitionsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefinitionsListContext ------------------------------------------------------------------

PascalParser::TypeDefinitionsListContext::TypeDefinitionsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::TypeDefinitionContext *> PascalParser::TypeDefinitionsListContext::typeDefinition() {
  return getRuleContexts<PascalParser::TypeDefinitionContext>();
}

PascalParser::TypeDefinitionContext* PascalParser::TypeDefinitionsListContext::typeDefinition(size_t i) {
  return getRuleContext<PascalParser::TypeDefinitionContext>(i);
}


size_t PascalParser::TypeDefinitionsListContext::getRuleIndex() const {
  return PascalParser::RuleTypeDefinitionsList;
}


antlrcpp::Any PascalParser::TypeDefinitionsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypeDefinitionsList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TypeDefinitionsListContext* PascalParser::typeDefinitionsList() {
  TypeDefinitionsListContext *_localctx = _tracker.createInstance<TypeDefinitionsListContext>(_ctx, getState());
  enterRule(_localctx, 26, PascalParser::RuleTypeDefinitionsList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(262);
    typeDefinition();
    setState(267);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(263);
        match(PascalParser::T__1);
        setState(264);
        typeDefinition(); 
      }
      setState(269);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefinitionContext ------------------------------------------------------------------

PascalParser::TypeDefinitionContext::TypeDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::TypeIdentifierContext* PascalParser::TypeDefinitionContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}

PascalParser::TypeSpecificationContext* PascalParser::TypeDefinitionContext::typeSpecification() {
  return getRuleContext<PascalParser::TypeSpecificationContext>(0);
}


size_t PascalParser::TypeDefinitionContext::getRuleIndex() const {
  return PascalParser::RuleTypeDefinition;
}


antlrcpp::Any PascalParser::TypeDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypeDefinition(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TypeDefinitionContext* PascalParser::typeDefinition() {
  TypeDefinitionContext *_localctx = _tracker.createInstance<TypeDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 28, PascalParser::RuleTypeDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    typeIdentifier();
    setState(271);
    match(PascalParser::T__5);
    setState(272);
    typeSpecification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeIdentifierContext ------------------------------------------------------------------

PascalParser::TypeIdentifierContext::TypeIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::TypeIdentifierContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::TypeIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleTypeIdentifier;
}


antlrcpp::Any PascalParser::TypeIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TypeIdentifierContext* PascalParser::typeIdentifier() {
  TypeIdentifierContext *_localctx = _tracker.createInstance<TypeIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 30, PascalParser::RuleTypeIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecificationContext ------------------------------------------------------------------

PascalParser::TypeSpecificationContext::TypeSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalParser::TypeSpecificationContext::getRuleIndex() const {
  return PascalParser::RuleTypeSpecification;
}

void PascalParser::TypeSpecificationContext::copyFrom(TypeSpecificationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- SimpleTypespecContext ------------------------------------------------------------------

PascalParser::SimpleTypeContext* PascalParser::SimpleTypespecContext::simpleType() {
  return getRuleContext<PascalParser::SimpleTypeContext>(0);
}

PascalParser::SimpleTypespecContext::SimpleTypespecContext(TypeSpecificationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::SimpleTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSimpleTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayTypespecContext ------------------------------------------------------------------

PascalParser::ArrayTypeContext* PascalParser::ArrayTypespecContext::arrayType() {
  return getRuleContext<PascalParser::ArrayTypeContext>(0);
}

PascalParser::ArrayTypespecContext::ArrayTypespecContext(TypeSpecificationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::ArrayTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitArrayTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RecordTypespecContext ------------------------------------------------------------------

PascalParser::RecordTypeContext* PascalParser::RecordTypespecContext::recordType() {
  return getRuleContext<PascalParser::RecordTypeContext>(0);
}

PascalParser::RecordTypespecContext::RecordTypespecContext(TypeSpecificationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::RecordTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRecordTypespec(this);
  else
    return visitor->visitChildren(this);
}
PascalParser::TypeSpecificationContext* PascalParser::typeSpecification() {
  TypeSpecificationContext *_localctx = _tracker.createInstance<TypeSpecificationContext>(_ctx, getState());
  enterRule(_localctx, 32, PascalParser::RuleTypeSpecification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(279);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::T__2:
      case PascalParser::T__6:
      case PascalParser::T__7:
      case PascalParser::IDENTIFIER:
      case PascalParser::INTEGER:
      case PascalParser::REAL:
      case PascalParser::CHARACTER:
      case PascalParser::STRING: {
        _localctx = dynamic_cast<TypeSpecificationContext *>(_tracker.createInstance<PascalParser::SimpleTypespecContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(276);
        simpleType();
        break;
      }

      case PascalParser::ARRAY: {
        _localctx = dynamic_cast<TypeSpecificationContext *>(_tracker.createInstance<PascalParser::ArrayTypespecContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(277);
        arrayType();
        break;
      }

      case PascalParser::RECORD: {
        _localctx = dynamic_cast<TypeSpecificationContext *>(_tracker.createInstance<PascalParser::RecordTypespecContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(278);
        recordType();
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

PascalParser::SimpleTypeContext::SimpleTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalParser::SimpleTypeContext::getRuleIndex() const {
  return PascalParser::RuleSimpleType;
}

void PascalParser::SimpleTypeContext::copyFrom(SimpleTypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- SubrangeTypespecContext ------------------------------------------------------------------

PascalParser::SubrangeTypeContext* PascalParser::SubrangeTypespecContext::subrangeType() {
  return getRuleContext<PascalParser::SubrangeTypeContext>(0);
}

PascalParser::SubrangeTypespecContext::SubrangeTypespecContext(SimpleTypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::SubrangeTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSubrangeTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EnumerationTypespecContext ------------------------------------------------------------------

PascalParser::EnumerationTypeContext* PascalParser::EnumerationTypespecContext::enumerationType() {
  return getRuleContext<PascalParser::EnumerationTypeContext>(0);
}

PascalParser::EnumerationTypespecContext::EnumerationTypespecContext(SimpleTypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::EnumerationTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitEnumerationTypespec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeIdentifierTypespecContext ------------------------------------------------------------------

PascalParser::TypeIdentifierContext* PascalParser::TypeIdentifierTypespecContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}

PascalParser::TypeIdentifierTypespecContext::TypeIdentifierTypespecContext(SimpleTypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::TypeIdentifierTypespecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifierTypespec(this);
  else
    return visitor->visitChildren(this);
}
PascalParser::SimpleTypeContext* PascalParser::simpleType() {
  SimpleTypeContext *_localctx = _tracker.createInstance<SimpleTypeContext>(_ctx, getState());
  enterRule(_localctx, 34, PascalParser::RuleSimpleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(284);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<SimpleTypeContext *>(_tracker.createInstance<PascalParser::TypeIdentifierTypespecContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(281);
      typeIdentifier();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<SimpleTypeContext *>(_tracker.createInstance<PascalParser::EnumerationTypespecContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(282);
      enumerationType();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<SimpleTypeContext *>(_tracker.createInstance<PascalParser::SubrangeTypespecContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(283);
      subrangeType();
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

//----------------- EnumerationTypeContext ------------------------------------------------------------------

PascalParser::EnumerationTypeContext::EnumerationTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::EnumerationConstantContext *> PascalParser::EnumerationTypeContext::enumerationConstant() {
  return getRuleContexts<PascalParser::EnumerationConstantContext>();
}

PascalParser::EnumerationConstantContext* PascalParser::EnumerationTypeContext::enumerationConstant(size_t i) {
  return getRuleContext<PascalParser::EnumerationConstantContext>(i);
}


size_t PascalParser::EnumerationTypeContext::getRuleIndex() const {
  return PascalParser::RuleEnumerationType;
}


antlrcpp::Any PascalParser::EnumerationTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitEnumerationType(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::EnumerationTypeContext* PascalParser::enumerationType() {
  EnumerationTypeContext *_localctx = _tracker.createInstance<EnumerationTypeContext>(_ctx, getState());
  enterRule(_localctx, 36, PascalParser::RuleEnumerationType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    match(PascalParser::T__2);
    setState(287);
    enumerationConstant();
    setState(292);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__3) {
      setState(288);
      match(PascalParser::T__3);
      setState(289);
      enumerationConstant();
      setState(294);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(295);
    match(PascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumerationConstantContext ------------------------------------------------------------------

PascalParser::EnumerationConstantContext::EnumerationConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ConstantIdentifierContext* PascalParser::EnumerationConstantContext::constantIdentifier() {
  return getRuleContext<PascalParser::ConstantIdentifierContext>(0);
}


size_t PascalParser::EnumerationConstantContext::getRuleIndex() const {
  return PascalParser::RuleEnumerationConstant;
}


antlrcpp::Any PascalParser::EnumerationConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitEnumerationConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::EnumerationConstantContext* PascalParser::enumerationConstant() {
  EnumerationConstantContext *_localctx = _tracker.createInstance<EnumerationConstantContext>(_ctx, getState());
  enterRule(_localctx, 38, PascalParser::RuleEnumerationConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    constantIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubrangeTypeContext ------------------------------------------------------------------

PascalParser::SubrangeTypeContext::SubrangeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::ConstantContext *> PascalParser::SubrangeTypeContext::constant() {
  return getRuleContexts<PascalParser::ConstantContext>();
}

PascalParser::ConstantContext* PascalParser::SubrangeTypeContext::constant(size_t i) {
  return getRuleContext<PascalParser::ConstantContext>(i);
}


size_t PascalParser::SubrangeTypeContext::getRuleIndex() const {
  return PascalParser::RuleSubrangeType;
}


antlrcpp::Any PascalParser::SubrangeTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSubrangeType(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::SubrangeTypeContext* PascalParser::subrangeType() {
  SubrangeTypeContext *_localctx = _tracker.createInstance<SubrangeTypeContext>(_ctx, getState());
  enterRule(_localctx, 40, PascalParser::RuleSubrangeType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    constant();
    setState(300);
    match(PascalParser::T__8);
    setState(301);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

PascalParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ArrayTypeContext::ARRAY() {
  return getToken(PascalParser::ARRAY, 0);
}

PascalParser::ArrayDimensionListContext* PascalParser::ArrayTypeContext::arrayDimensionList() {
  return getRuleContext<PascalParser::ArrayDimensionListContext>(0);
}

tree::TerminalNode* PascalParser::ArrayTypeContext::OF() {
  return getToken(PascalParser::OF, 0);
}

PascalParser::TypeSpecificationContext* PascalParser::ArrayTypeContext::typeSpecification() {
  return getRuleContext<PascalParser::TypeSpecificationContext>(0);
}


size_t PascalParser::ArrayTypeContext::getRuleIndex() const {
  return PascalParser::RuleArrayType;
}


antlrcpp::Any PascalParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ArrayTypeContext* PascalParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 42, PascalParser::RuleArrayType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    match(PascalParser::ARRAY);
    setState(304);
    match(PascalParser::T__9);
    setState(305);
    arrayDimensionList();
    setState(306);
    match(PascalParser::T__10);
    setState(307);
    match(PascalParser::OF);
    setState(308);
    typeSpecification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayDimensionListContext ------------------------------------------------------------------

PascalParser::ArrayDimensionListContext::ArrayDimensionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::SimpleTypeContext *> PascalParser::ArrayDimensionListContext::simpleType() {
  return getRuleContexts<PascalParser::SimpleTypeContext>();
}

PascalParser::SimpleTypeContext* PascalParser::ArrayDimensionListContext::simpleType(size_t i) {
  return getRuleContext<PascalParser::SimpleTypeContext>(i);
}


size_t PascalParser::ArrayDimensionListContext::getRuleIndex() const {
  return PascalParser::RuleArrayDimensionList;
}


antlrcpp::Any PascalParser::ArrayDimensionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitArrayDimensionList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ArrayDimensionListContext* PascalParser::arrayDimensionList() {
  ArrayDimensionListContext *_localctx = _tracker.createInstance<ArrayDimensionListContext>(_ctx, getState());
  enterRule(_localctx, 44, PascalParser::RuleArrayDimensionList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    simpleType();
    setState(315);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__3) {
      setState(311);
      match(PascalParser::T__3);
      setState(312);
      simpleType();
      setState(317);
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

//----------------- RecordTypeContext ------------------------------------------------------------------

PascalParser::RecordTypeContext::RecordTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::RecordTypeContext::RECORD() {
  return getToken(PascalParser::RECORD, 0);
}

PascalParser::RecordFieldsContext* PascalParser::RecordTypeContext::recordFields() {
  return getRuleContext<PascalParser::RecordFieldsContext>(0);
}

tree::TerminalNode* PascalParser::RecordTypeContext::END() {
  return getToken(PascalParser::END, 0);
}


size_t PascalParser::RecordTypeContext::getRuleIndex() const {
  return PascalParser::RuleRecordType;
}


antlrcpp::Any PascalParser::RecordTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRecordType(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RecordTypeContext* PascalParser::recordType() {
  RecordTypeContext *_localctx = _tracker.createInstance<RecordTypeContext>(_ctx, getState());
  enterRule(_localctx, 46, PascalParser::RuleRecordType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    match(PascalParser::RECORD);
    setState(319);
    recordFields();
    setState(321);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__1) {
      setState(320);
      match(PascalParser::T__1);
    }
    setState(323);
    match(PascalParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RecordFieldsContext ------------------------------------------------------------------

PascalParser::RecordFieldsContext::RecordFieldsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::VariableDeclarationsListContext* PascalParser::RecordFieldsContext::variableDeclarationsList() {
  return getRuleContext<PascalParser::VariableDeclarationsListContext>(0);
}


size_t PascalParser::RecordFieldsContext::getRuleIndex() const {
  return PascalParser::RuleRecordFields;
}


antlrcpp::Any PascalParser::RecordFieldsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRecordFields(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RecordFieldsContext* PascalParser::recordFields() {
  RecordFieldsContext *_localctx = _tracker.createInstance<RecordFieldsContext>(_ctx, getState());
  enterRule(_localctx, 48, PascalParser::RuleRecordFields);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(325);
    variableDeclarationsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariablesPartContext ------------------------------------------------------------------

PascalParser::VariablesPartContext::VariablesPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::VariablesPartContext::VAR() {
  return getToken(PascalParser::VAR, 0);
}

PascalParser::VariableDeclarationsListContext* PascalParser::VariablesPartContext::variableDeclarationsList() {
  return getRuleContext<PascalParser::VariableDeclarationsListContext>(0);
}


size_t PascalParser::VariablesPartContext::getRuleIndex() const {
  return PascalParser::RuleVariablesPart;
}


antlrcpp::Any PascalParser::VariablesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariablesPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariablesPartContext* PascalParser::variablesPart() {
  VariablesPartContext *_localctx = _tracker.createInstance<VariablesPartContext>(_ctx, getState());
  enterRule(_localctx, 50, PascalParser::RuleVariablesPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    match(PascalParser::VAR);
    setState(328);
    variableDeclarationsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationsListContext ------------------------------------------------------------------

PascalParser::VariableDeclarationsListContext::VariableDeclarationsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::VariableDeclarationsContext *> PascalParser::VariableDeclarationsListContext::variableDeclarations() {
  return getRuleContexts<PascalParser::VariableDeclarationsContext>();
}

PascalParser::VariableDeclarationsContext* PascalParser::VariableDeclarationsListContext::variableDeclarations(size_t i) {
  return getRuleContext<PascalParser::VariableDeclarationsContext>(i);
}


size_t PascalParser::VariableDeclarationsListContext::getRuleIndex() const {
  return PascalParser::RuleVariableDeclarationsList;
}


antlrcpp::Any PascalParser::VariableDeclarationsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationsList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableDeclarationsListContext* PascalParser::variableDeclarationsList() {
  VariableDeclarationsListContext *_localctx = _tracker.createInstance<VariableDeclarationsListContext>(_ctx, getState());
  enterRule(_localctx, 52, PascalParser::RuleVariableDeclarationsList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(330);
    variableDeclarations();
    setState(335);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(331);
        match(PascalParser::T__1);
        setState(332);
        variableDeclarations(); 
      }
      setState(337);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationsContext ------------------------------------------------------------------

PascalParser::VariableDeclarationsContext::VariableDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::VariableIdentifierListContext* PascalParser::VariableDeclarationsContext::variableIdentifierList() {
  return getRuleContext<PascalParser::VariableIdentifierListContext>(0);
}

PascalParser::TypeSpecificationContext* PascalParser::VariableDeclarationsContext::typeSpecification() {
  return getRuleContext<PascalParser::TypeSpecificationContext>(0);
}


size_t PascalParser::VariableDeclarationsContext::getRuleIndex() const {
  return PascalParser::RuleVariableDeclarations;
}


antlrcpp::Any PascalParser::VariableDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarations(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableDeclarationsContext* PascalParser::variableDeclarations() {
  VariableDeclarationsContext *_localctx = _tracker.createInstance<VariableDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 54, PascalParser::RuleVariableDeclarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    variableIdentifierList();
    setState(339);
    match(PascalParser::T__11);
    setState(340);
    typeSpecification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableIdentifierListContext ------------------------------------------------------------------

PascalParser::VariableIdentifierListContext::VariableIdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::VariableIdentifierContext *> PascalParser::VariableIdentifierListContext::variableIdentifier() {
  return getRuleContexts<PascalParser::VariableIdentifierContext>();
}

PascalParser::VariableIdentifierContext* PascalParser::VariableIdentifierListContext::variableIdentifier(size_t i) {
  return getRuleContext<PascalParser::VariableIdentifierContext>(i);
}


size_t PascalParser::VariableIdentifierListContext::getRuleIndex() const {
  return PascalParser::RuleVariableIdentifierList;
}


antlrcpp::Any PascalParser::VariableIdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableIdentifierListContext* PascalParser::variableIdentifierList() {
  VariableIdentifierListContext *_localctx = _tracker.createInstance<VariableIdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 56, PascalParser::RuleVariableIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    variableIdentifier();
    setState(347);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__3) {
      setState(343);
      match(PascalParser::T__3);
      setState(344);
      variableIdentifier();
      setState(349);
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

//----------------- VariableIdentifierContext ------------------------------------------------------------------

PascalParser::VariableIdentifierContext::VariableIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::VariableIdentifierContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::VariableIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleVariableIdentifier;
}


antlrcpp::Any PascalParser::VariableIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableIdentifierContext* PascalParser::variableIdentifier() {
  VariableIdentifierContext *_localctx = _tracker.createInstance<VariableIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 58, PascalParser::RuleVariableIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutinesPartContext ------------------------------------------------------------------

PascalParser::RoutinesPartContext::RoutinesPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::RoutineDefinitionContext *> PascalParser::RoutinesPartContext::routineDefinition() {
  return getRuleContexts<PascalParser::RoutineDefinitionContext>();
}

PascalParser::RoutineDefinitionContext* PascalParser::RoutinesPartContext::routineDefinition(size_t i) {
  return getRuleContext<PascalParser::RoutineDefinitionContext>(i);
}


size_t PascalParser::RoutinesPartContext::getRuleIndex() const {
  return PascalParser::RuleRoutinesPart;
}


antlrcpp::Any PascalParser::RoutinesPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRoutinesPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RoutinesPartContext* PascalParser::routinesPart() {
  RoutinesPartContext *_localctx = _tracker.createInstance<RoutinesPartContext>(_ctx, getState());
  enterRule(_localctx, 60, PascalParser::RuleRoutinesPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(352);
    routineDefinition();
    setState(357);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(353);
        match(PascalParser::T__1);
        setState(354);
        routineDefinition(); 
      }
      setState(359);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutineDefinitionContext ------------------------------------------------------------------

PascalParser::RoutineDefinitionContext::RoutineDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::BlockContext* PascalParser::RoutineDefinitionContext::block() {
  return getRuleContext<PascalParser::BlockContext>(0);
}

PascalParser::ProcedureHeadContext* PascalParser::RoutineDefinitionContext::procedureHead() {
  return getRuleContext<PascalParser::ProcedureHeadContext>(0);
}

PascalParser::FunctionHeadContext* PascalParser::RoutineDefinitionContext::functionHead() {
  return getRuleContext<PascalParser::FunctionHeadContext>(0);
}


size_t PascalParser::RoutineDefinitionContext::getRuleIndex() const {
  return PascalParser::RuleRoutineDefinition;
}


antlrcpp::Any PascalParser::RoutineDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRoutineDefinition(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RoutineDefinitionContext* PascalParser::routineDefinition() {
  RoutineDefinitionContext *_localctx = _tracker.createInstance<RoutineDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 62, PascalParser::RuleRoutineDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::PROCEDURE: {
        setState(360);
        procedureHead();
        break;
      }

      case PascalParser::FUNCTION: {
        setState(361);
        functionHead();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(364);
    match(PascalParser::T__1);
    setState(365);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureHeadContext ------------------------------------------------------------------

PascalParser::ProcedureHeadContext::ProcedureHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ProcedureHeadContext::PROCEDURE() {
  return getToken(PascalParser::PROCEDURE, 0);
}

PascalParser::RoutineIdentifierContext* PascalParser::ProcedureHeadContext::routineIdentifier() {
  return getRuleContext<PascalParser::RoutineIdentifierContext>(0);
}

PascalParser::ParametersContext* PascalParser::ProcedureHeadContext::parameters() {
  return getRuleContext<PascalParser::ParametersContext>(0);
}


size_t PascalParser::ProcedureHeadContext::getRuleIndex() const {
  return PascalParser::RuleProcedureHead;
}


antlrcpp::Any PascalParser::ProcedureHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProcedureHead(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProcedureHeadContext* PascalParser::procedureHead() {
  ProcedureHeadContext *_localctx = _tracker.createInstance<ProcedureHeadContext>(_ctx, getState());
  enterRule(_localctx, 64, PascalParser::RuleProcedureHead);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    match(PascalParser::PROCEDURE);
    setState(368);
    routineIdentifier();
    setState(370);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__2) {
      setState(369);
      parameters();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionHeadContext ------------------------------------------------------------------

PascalParser::FunctionHeadContext::FunctionHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::FunctionHeadContext::FUNCTION() {
  return getToken(PascalParser::FUNCTION, 0);
}

PascalParser::RoutineIdentifierContext* PascalParser::FunctionHeadContext::routineIdentifier() {
  return getRuleContext<PascalParser::RoutineIdentifierContext>(0);
}

PascalParser::TypeIdentifierContext* PascalParser::FunctionHeadContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}

PascalParser::ParametersContext* PascalParser::FunctionHeadContext::parameters() {
  return getRuleContext<PascalParser::ParametersContext>(0);
}


size_t PascalParser::FunctionHeadContext::getRuleIndex() const {
  return PascalParser::RuleFunctionHead;
}


antlrcpp::Any PascalParser::FunctionHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFunctionHead(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FunctionHeadContext* PascalParser::functionHead() {
  FunctionHeadContext *_localctx = _tracker.createInstance<FunctionHeadContext>(_ctx, getState());
  enterRule(_localctx, 66, PascalParser::RuleFunctionHead);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(372);
    match(PascalParser::FUNCTION);
    setState(373);
    routineIdentifier();
    setState(375);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__2) {
      setState(374);
      parameters();
    }
    setState(377);
    match(PascalParser::T__11);
    setState(378);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutineIdentifierContext ------------------------------------------------------------------

PascalParser::RoutineIdentifierContext::RoutineIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::RoutineIdentifierContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::RoutineIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleRoutineIdentifier;
}


antlrcpp::Any PascalParser::RoutineIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRoutineIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RoutineIdentifierContext* PascalParser::routineIdentifier() {
  RoutineIdentifierContext *_localctx = _tracker.createInstance<RoutineIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 68, PascalParser::RuleRoutineIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

PascalParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ParameterDeclarationsListContext* PascalParser::ParametersContext::parameterDeclarationsList() {
  return getRuleContext<PascalParser::ParameterDeclarationsListContext>(0);
}


size_t PascalParser::ParametersContext::getRuleIndex() const {
  return PascalParser::RuleParameters;
}


antlrcpp::Any PascalParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ParametersContext* PascalParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 70, PascalParser::RuleParameters);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(382);
    match(PascalParser::T__2);
    setState(383);
    parameterDeclarationsList();
    setState(384);
    match(PascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationsListContext ------------------------------------------------------------------

PascalParser::ParameterDeclarationsListContext::ParameterDeclarationsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::ParameterDeclarationsContext *> PascalParser::ParameterDeclarationsListContext::parameterDeclarations() {
  return getRuleContexts<PascalParser::ParameterDeclarationsContext>();
}

PascalParser::ParameterDeclarationsContext* PascalParser::ParameterDeclarationsListContext::parameterDeclarations(size_t i) {
  return getRuleContext<PascalParser::ParameterDeclarationsContext>(i);
}


size_t PascalParser::ParameterDeclarationsListContext::getRuleIndex() const {
  return PascalParser::RuleParameterDeclarationsList;
}


antlrcpp::Any PascalParser::ParameterDeclarationsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParameterDeclarationsList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ParameterDeclarationsListContext* PascalParser::parameterDeclarationsList() {
  ParameterDeclarationsListContext *_localctx = _tracker.createInstance<ParameterDeclarationsListContext>(_ctx, getState());
  enterRule(_localctx, 72, PascalParser::RuleParameterDeclarationsList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    parameterDeclarations();
    setState(391);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__1) {
      setState(387);
      match(PascalParser::T__1);
      setState(388);
      parameterDeclarations();
      setState(393);
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

//----------------- ParameterDeclarationsContext ------------------------------------------------------------------

PascalParser::ParameterDeclarationsContext::ParameterDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ParameterIdentifierListContext* PascalParser::ParameterDeclarationsContext::parameterIdentifierList() {
  return getRuleContext<PascalParser::ParameterIdentifierListContext>(0);
}

PascalParser::TypeIdentifierContext* PascalParser::ParameterDeclarationsContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}

tree::TerminalNode* PascalParser::ParameterDeclarationsContext::VAR() {
  return getToken(PascalParser::VAR, 0);
}


size_t PascalParser::ParameterDeclarationsContext::getRuleIndex() const {
  return PascalParser::RuleParameterDeclarations;
}


antlrcpp::Any PascalParser::ParameterDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParameterDeclarations(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ParameterDeclarationsContext* PascalParser::parameterDeclarations() {
  ParameterDeclarationsContext *_localctx = _tracker.createInstance<ParameterDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 74, PascalParser::RuleParameterDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::VAR) {
      setState(394);
      match(PascalParser::VAR);
    }
    setState(397);
    parameterIdentifierList();
    setState(398);
    match(PascalParser::T__11);
    setState(399);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterIdentifierListContext ------------------------------------------------------------------

PascalParser::ParameterIdentifierListContext::ParameterIdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::ParameterIdentifierContext *> PascalParser::ParameterIdentifierListContext::parameterIdentifier() {
  return getRuleContexts<PascalParser::ParameterIdentifierContext>();
}

PascalParser::ParameterIdentifierContext* PascalParser::ParameterIdentifierListContext::parameterIdentifier(size_t i) {
  return getRuleContext<PascalParser::ParameterIdentifierContext>(i);
}


size_t PascalParser::ParameterIdentifierListContext::getRuleIndex() const {
  return PascalParser::RuleParameterIdentifierList;
}


antlrcpp::Any PascalParser::ParameterIdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParameterIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ParameterIdentifierListContext* PascalParser::parameterIdentifierList() {
  ParameterIdentifierListContext *_localctx = _tracker.createInstance<ParameterIdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 76, PascalParser::RuleParameterIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    parameterIdentifier();
    setState(406);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__3) {
      setState(402);
      match(PascalParser::T__3);
      setState(403);
      parameterIdentifier();
      setState(408);
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

//----------------- ParameterIdentifierContext ------------------------------------------------------------------

PascalParser::ParameterIdentifierContext::ParameterIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ParameterIdentifierContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::ParameterIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleParameterIdentifier;
}


antlrcpp::Any PascalParser::ParameterIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParameterIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ParameterIdentifierContext* PascalParser::parameterIdentifier() {
  ParameterIdentifierContext *_localctx = _tracker.createInstance<ParameterIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 78, PascalParser::RuleParameterIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(409);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

PascalParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::CompoundStatementContext* PascalParser::StatementContext::compoundStatement() {
  return getRuleContext<PascalParser::CompoundStatementContext>(0);
}

PascalParser::AssignmentStatementContext* PascalParser::StatementContext::assignmentStatement() {
  return getRuleContext<PascalParser::AssignmentStatementContext>(0);
}

PascalParser::IfStatementContext* PascalParser::StatementContext::ifStatement() {
  return getRuleContext<PascalParser::IfStatementContext>(0);
}

PascalParser::CaseStatementContext* PascalParser::StatementContext::caseStatement() {
  return getRuleContext<PascalParser::CaseStatementContext>(0);
}

PascalParser::RepeatStatementContext* PascalParser::StatementContext::repeatStatement() {
  return getRuleContext<PascalParser::RepeatStatementContext>(0);
}

PascalParser::WhileStatementContext* PascalParser::StatementContext::whileStatement() {
  return getRuleContext<PascalParser::WhileStatementContext>(0);
}

PascalParser::ForStatementContext* PascalParser::StatementContext::forStatement() {
  return getRuleContext<PascalParser::ForStatementContext>(0);
}

PascalParser::WriteStatementContext* PascalParser::StatementContext::writeStatement() {
  return getRuleContext<PascalParser::WriteStatementContext>(0);
}

PascalParser::WritelnStatementContext* PascalParser::StatementContext::writelnStatement() {
  return getRuleContext<PascalParser::WritelnStatementContext>(0);
}

PascalParser::ReadStatementContext* PascalParser::StatementContext::readStatement() {
  return getRuleContext<PascalParser::ReadStatementContext>(0);
}

PascalParser::ReadlnStatementContext* PascalParser::StatementContext::readlnStatement() {
  return getRuleContext<PascalParser::ReadlnStatementContext>(0);
}

PascalParser::ProcedureCallStatementContext* PascalParser::StatementContext::procedureCallStatement() {
  return getRuleContext<PascalParser::ProcedureCallStatementContext>(0);
}

PascalParser::EmptyStatementContext* PascalParser::StatementContext::emptyStatement() {
  return getRuleContext<PascalParser::EmptyStatementContext>(0);
}


size_t PascalParser::StatementContext::getRuleIndex() const {
  return PascalParser::RuleStatement;
}


antlrcpp::Any PascalParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::StatementContext* PascalParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 80, PascalParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(424);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(411);
      compoundStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(412);
      assignmentStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(413);
      ifStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(414);
      caseStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(415);
      repeatStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(416);
      whileStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(417);
      forStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(418);
      writeStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(419);
      writelnStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(420);
      readStatement();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(421);
      readlnStatement();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(422);
      procedureCallStatement();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(423);
      emptyStatement();
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

//----------------- CompoundStatementContext ------------------------------------------------------------------

PascalParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::CompoundStatementContext::BEGIN() {
  return getToken(PascalParser::BEGIN, 0);
}

PascalParser::StatementListContext* PascalParser::CompoundStatementContext::statementList() {
  return getRuleContext<PascalParser::StatementListContext>(0);
}

tree::TerminalNode* PascalParser::CompoundStatementContext::END() {
  return getToken(PascalParser::END, 0);
}


size_t PascalParser::CompoundStatementContext::getRuleIndex() const {
  return PascalParser::RuleCompoundStatement;
}


antlrcpp::Any PascalParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CompoundStatementContext* PascalParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 82, PascalParser::RuleCompoundStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(426);
    match(PascalParser::BEGIN);
    setState(427);
    statementList();
    setState(428);
    match(PascalParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatementContext ------------------------------------------------------------------

PascalParser::EmptyStatementContext::EmptyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalParser::EmptyStatementContext::getRuleIndex() const {
  return PascalParser::RuleEmptyStatement;
}


antlrcpp::Any PascalParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::EmptyStatementContext* PascalParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 84, PascalParser::RuleEmptyStatement);

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

//----------------- StatementListContext ------------------------------------------------------------------

PascalParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::StatementContext *> PascalParser::StatementListContext::statement() {
  return getRuleContexts<PascalParser::StatementContext>();
}

PascalParser::StatementContext* PascalParser::StatementListContext::statement(size_t i) {
  return getRuleContext<PascalParser::StatementContext>(i);
}


size_t PascalParser::StatementListContext::getRuleIndex() const {
  return PascalParser::RuleStatementList;
}


antlrcpp::Any PascalParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::StatementListContext* PascalParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 86, PascalParser::RuleStatementList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    statement();
    setState(437);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__1) {
      setState(433);
      match(PascalParser::T__1);
      setState(434);
      statement();
      setState(439);
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

//----------------- AssignmentStatementContext ------------------------------------------------------------------

PascalParser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::LhsContext* PascalParser::AssignmentStatementContext::lhs() {
  return getRuleContext<PascalParser::LhsContext>(0);
}

PascalParser::RhsContext* PascalParser::AssignmentStatementContext::rhs() {
  return getRuleContext<PascalParser::RhsContext>(0);
}


size_t PascalParser::AssignmentStatementContext::getRuleIndex() const {
  return PascalParser::RuleAssignmentStatement;
}


antlrcpp::Any PascalParser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::AssignmentStatementContext* PascalParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 88, PascalParser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(440);
    lhs();
    setState(441);
    match(PascalParser::T__12);
    setState(442);
    rhs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LhsContext ------------------------------------------------------------------

PascalParser::LhsContext::LhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::VariableContext* PascalParser::LhsContext::variable() {
  return getRuleContext<PascalParser::VariableContext>(0);
}


size_t PascalParser::LhsContext::getRuleIndex() const {
  return PascalParser::RuleLhs;
}


antlrcpp::Any PascalParser::LhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitLhs(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::LhsContext* PascalParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 90, PascalParser::RuleLhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444);
    variable();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RhsContext ------------------------------------------------------------------

PascalParser::RhsContext::RhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ExpressionContext* PascalParser::RhsContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::RhsContext::getRuleIndex() const {
  return PascalParser::RuleRhs;
}


antlrcpp::Any PascalParser::RhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRhs(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RhsContext* PascalParser::rhs() {
  RhsContext *_localctx = _tracker.createInstance<RhsContext>(_ctx, getState());
  enterRule(_localctx, 92, PascalParser::RuleRhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(446);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

PascalParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::IfStatementContext::IF() {
  return getToken(PascalParser::IF, 0);
}

PascalParser::ExpressionContext* PascalParser::IfStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalParser::IfStatementContext::THEN() {
  return getToken(PascalParser::THEN, 0);
}

PascalParser::TrueStatementContext* PascalParser::IfStatementContext::trueStatement() {
  return getRuleContext<PascalParser::TrueStatementContext>(0);
}

tree::TerminalNode* PascalParser::IfStatementContext::ELSE() {
  return getToken(PascalParser::ELSE, 0);
}

PascalParser::FalseStatementContext* PascalParser::IfStatementContext::falseStatement() {
  return getRuleContext<PascalParser::FalseStatementContext>(0);
}


size_t PascalParser::IfStatementContext::getRuleIndex() const {
  return PascalParser::RuleIfStatement;
}


antlrcpp::Any PascalParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::IfStatementContext* PascalParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 94, PascalParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(448);
    match(PascalParser::IF);
    setState(449);
    expression();
    setState(450);
    match(PascalParser::THEN);
    setState(451);
    trueStatement();
    setState(454);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      setState(452);
      match(PascalParser::ELSE);
      setState(453);
      falseStatement();
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

//----------------- TrueStatementContext ------------------------------------------------------------------

PascalParser::TrueStatementContext::TrueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::StatementContext* PascalParser::TrueStatementContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}


size_t PascalParser::TrueStatementContext::getRuleIndex() const {
  return PascalParser::RuleTrueStatement;
}


antlrcpp::Any PascalParser::TrueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTrueStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TrueStatementContext* PascalParser::trueStatement() {
  TrueStatementContext *_localctx = _tracker.createInstance<TrueStatementContext>(_ctx, getState());
  enterRule(_localctx, 96, PascalParser::RuleTrueStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(456);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FalseStatementContext ------------------------------------------------------------------

PascalParser::FalseStatementContext::FalseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::StatementContext* PascalParser::FalseStatementContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}


size_t PascalParser::FalseStatementContext::getRuleIndex() const {
  return PascalParser::RuleFalseStatement;
}


antlrcpp::Any PascalParser::FalseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFalseStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FalseStatementContext* PascalParser::falseStatement() {
  FalseStatementContext *_localctx = _tracker.createInstance<FalseStatementContext>(_ctx, getState());
  enterRule(_localctx, 98, PascalParser::RuleFalseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(458);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

PascalParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::CaseStatementContext::CASE() {
  return getToken(PascalParser::CASE, 0);
}

PascalParser::ExpressionContext* PascalParser::CaseStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalParser::CaseStatementContext::OF() {
  return getToken(PascalParser::OF, 0);
}

PascalParser::CaseBranchListContext* PascalParser::CaseStatementContext::caseBranchList() {
  return getRuleContext<PascalParser::CaseBranchListContext>(0);
}

tree::TerminalNode* PascalParser::CaseStatementContext::END() {
  return getToken(PascalParser::END, 0);
}


size_t PascalParser::CaseStatementContext::getRuleIndex() const {
  return PascalParser::RuleCaseStatement;
}


antlrcpp::Any PascalParser::CaseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCaseStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CaseStatementContext* PascalParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 100, PascalParser::RuleCaseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    match(PascalParser::CASE);
    setState(461);
    expression();
    setState(462);
    match(PascalParser::OF);
    setState(463);
    caseBranchList();
    setState(464);
    match(PascalParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseBranchListContext ------------------------------------------------------------------

PascalParser::CaseBranchListContext::CaseBranchListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::CaseBranchContext *> PascalParser::CaseBranchListContext::caseBranch() {
  return getRuleContexts<PascalParser::CaseBranchContext>();
}

PascalParser::CaseBranchContext* PascalParser::CaseBranchListContext::caseBranch(size_t i) {
  return getRuleContext<PascalParser::CaseBranchContext>(i);
}


size_t PascalParser::CaseBranchListContext::getRuleIndex() const {
  return PascalParser::RuleCaseBranchList;
}


antlrcpp::Any PascalParser::CaseBranchListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCaseBranchList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CaseBranchListContext* PascalParser::caseBranchList() {
  CaseBranchListContext *_localctx = _tracker.createInstance<CaseBranchListContext>(_ctx, getState());
  enterRule(_localctx, 102, PascalParser::RuleCaseBranchList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(466);
    caseBranch();
    setState(471);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__1) {
      setState(467);
      match(PascalParser::T__1);
      setState(468);
      caseBranch();
      setState(473);
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

//----------------- CaseBranchContext ------------------------------------------------------------------

PascalParser::CaseBranchContext::CaseBranchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::CaseConstantListContext* PascalParser::CaseBranchContext::caseConstantList() {
  return getRuleContext<PascalParser::CaseConstantListContext>(0);
}

PascalParser::StatementContext* PascalParser::CaseBranchContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}


size_t PascalParser::CaseBranchContext::getRuleIndex() const {
  return PascalParser::RuleCaseBranch;
}


antlrcpp::Any PascalParser::CaseBranchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCaseBranch(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CaseBranchContext* PascalParser::caseBranch() {
  CaseBranchContext *_localctx = _tracker.createInstance<CaseBranchContext>(_ctx, getState());
  enterRule(_localctx, 104, PascalParser::RuleCaseBranch);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(479);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::T__6:
      case PascalParser::T__7:
      case PascalParser::IDENTIFIER:
      case PascalParser::INTEGER:
      case PascalParser::REAL:
      case PascalParser::CHARACTER:
      case PascalParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(474);
        caseConstantList();
        setState(475);
        match(PascalParser::T__11);
        setState(476);
        statement();
        break;
      }

      case PascalParser::T__1:
      case PascalParser::END: {
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

//----------------- CaseConstantListContext ------------------------------------------------------------------

PascalParser::CaseConstantListContext::CaseConstantListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::CaseConstantContext *> PascalParser::CaseConstantListContext::caseConstant() {
  return getRuleContexts<PascalParser::CaseConstantContext>();
}

PascalParser::CaseConstantContext* PascalParser::CaseConstantListContext::caseConstant(size_t i) {
  return getRuleContext<PascalParser::CaseConstantContext>(i);
}


size_t PascalParser::CaseConstantListContext::getRuleIndex() const {
  return PascalParser::RuleCaseConstantList;
}


antlrcpp::Any PascalParser::CaseConstantListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCaseConstantList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CaseConstantListContext* PascalParser::caseConstantList() {
  CaseConstantListContext *_localctx = _tracker.createInstance<CaseConstantListContext>(_ctx, getState());
  enterRule(_localctx, 106, PascalParser::RuleCaseConstantList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(481);
    caseConstant();
    setState(486);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__3) {
      setState(482);
      match(PascalParser::T__3);
      setState(483);
      caseConstant();
      setState(488);
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

//----------------- CaseConstantContext ------------------------------------------------------------------

PascalParser::CaseConstantContext::CaseConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ConstantContext* PascalParser::CaseConstantContext::constant() {
  return getRuleContext<PascalParser::ConstantContext>(0);
}


size_t PascalParser::CaseConstantContext::getRuleIndex() const {
  return PascalParser::RuleCaseConstant;
}


antlrcpp::Any PascalParser::CaseConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCaseConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CaseConstantContext* PascalParser::caseConstant() {
  CaseConstantContext *_localctx = _tracker.createInstance<CaseConstantContext>(_ctx, getState());
  enterRule(_localctx, 108, PascalParser::RuleCaseConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(489);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RepeatStatementContext ------------------------------------------------------------------

PascalParser::RepeatStatementContext::RepeatStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::RepeatStatementContext::REPEAT() {
  return getToken(PascalParser::REPEAT, 0);
}

PascalParser::StatementListContext* PascalParser::RepeatStatementContext::statementList() {
  return getRuleContext<PascalParser::StatementListContext>(0);
}

tree::TerminalNode* PascalParser::RepeatStatementContext::UNTIL() {
  return getToken(PascalParser::UNTIL, 0);
}

PascalParser::ExpressionContext* PascalParser::RepeatStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::RepeatStatementContext::getRuleIndex() const {
  return PascalParser::RuleRepeatStatement;
}


antlrcpp::Any PascalParser::RepeatStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRepeatStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RepeatStatementContext* PascalParser::repeatStatement() {
  RepeatStatementContext *_localctx = _tracker.createInstance<RepeatStatementContext>(_ctx, getState());
  enterRule(_localctx, 110, PascalParser::RuleRepeatStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(491);
    match(PascalParser::REPEAT);
    setState(492);
    statementList();
    setState(493);
    match(PascalParser::UNTIL);
    setState(494);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

PascalParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::WhileStatementContext::WHILE() {
  return getToken(PascalParser::WHILE, 0);
}

PascalParser::ExpressionContext* PascalParser::WhileStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalParser::WhileStatementContext::DO() {
  return getToken(PascalParser::DO, 0);
}

PascalParser::StatementContext* PascalParser::WhileStatementContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}


size_t PascalParser::WhileStatementContext::getRuleIndex() const {
  return PascalParser::RuleWhileStatement;
}


antlrcpp::Any PascalParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WhileStatementContext* PascalParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 112, PascalParser::RuleWhileStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496);
    match(PascalParser::WHILE);
    setState(497);
    expression();
    setState(498);
    match(PascalParser::DO);
    setState(499);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

PascalParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ForStatementContext::FOR() {
  return getToken(PascalParser::FOR, 0);
}

PascalParser::VariableContext* PascalParser::ForStatementContext::variable() {
  return getRuleContext<PascalParser::VariableContext>(0);
}

std::vector<PascalParser::ExpressionContext *> PascalParser::ForStatementContext::expression() {
  return getRuleContexts<PascalParser::ExpressionContext>();
}

PascalParser::ExpressionContext* PascalParser::ForStatementContext::expression(size_t i) {
  return getRuleContext<PascalParser::ExpressionContext>(i);
}

tree::TerminalNode* PascalParser::ForStatementContext::DO() {
  return getToken(PascalParser::DO, 0);
}

PascalParser::StatementContext* PascalParser::ForStatementContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}

tree::TerminalNode* PascalParser::ForStatementContext::TO() {
  return getToken(PascalParser::TO, 0);
}

tree::TerminalNode* PascalParser::ForStatementContext::DOWNTO() {
  return getToken(PascalParser::DOWNTO, 0);
}


size_t PascalParser::ForStatementContext::getRuleIndex() const {
  return PascalParser::RuleForStatement;
}


antlrcpp::Any PascalParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ForStatementContext* PascalParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 114, PascalParser::RuleForStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    match(PascalParser::FOR);
    setState(502);
    variable();
    setState(503);
    match(PascalParser::T__12);
    setState(504);
    expression();
    setState(505);
    _la = _input->LA(1);
    if (!(_la == PascalParser::TO

    || _la == PascalParser::DOWNTO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(506);
    expression();
    setState(507);
    match(PascalParser::DO);
    setState(508);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureCallStatementContext ------------------------------------------------------------------

PascalParser::ProcedureCallStatementContext::ProcedureCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ProcedureNameContext* PascalParser::ProcedureCallStatementContext::procedureName() {
  return getRuleContext<PascalParser::ProcedureNameContext>(0);
}

PascalParser::ArgumentListContext* PascalParser::ProcedureCallStatementContext::argumentList() {
  return getRuleContext<PascalParser::ArgumentListContext>(0);
}


size_t PascalParser::ProcedureCallStatementContext::getRuleIndex() const {
  return PascalParser::RuleProcedureCallStatement;
}


antlrcpp::Any PascalParser::ProcedureCallStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProcedureCallStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProcedureCallStatementContext* PascalParser::procedureCallStatement() {
  ProcedureCallStatementContext *_localctx = _tracker.createInstance<ProcedureCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 116, PascalParser::RuleProcedureCallStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(510);
    procedureName();
    setState(511);
    match(PascalParser::T__2);
    setState(513);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__2)
      | (1ULL << PascalParser::T__6)
      | (1ULL << PascalParser::T__7)
      | (1ULL << PascalParser::NOT)
      | (1ULL << PascalParser::IDENTIFIER)
      | (1ULL << PascalParser::INTEGER)
      | (1ULL << PascalParser::REAL)
      | (1ULL << PascalParser::CHARACTER)
      | (1ULL << PascalParser::STRING))) != 0)) {
      setState(512);
      argumentList();
    }
    setState(515);
    match(PascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureNameContext ------------------------------------------------------------------

PascalParser::ProcedureNameContext::ProcedureNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ProcedureNameContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::ProcedureNameContext::getRuleIndex() const {
  return PascalParser::RuleProcedureName;
}


antlrcpp::Any PascalParser::ProcedureNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProcedureName(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProcedureNameContext* PascalParser::procedureName() {
  ProcedureNameContext *_localctx = _tracker.createInstance<ProcedureNameContext>(_ctx, getState());
  enterRule(_localctx, 118, PascalParser::RuleProcedureName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(517);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

PascalParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::ArgumentContext *> PascalParser::ArgumentListContext::argument() {
  return getRuleContexts<PascalParser::ArgumentContext>();
}

PascalParser::ArgumentContext* PascalParser::ArgumentListContext::argument(size_t i) {
  return getRuleContext<PascalParser::ArgumentContext>(i);
}


size_t PascalParser::ArgumentListContext::getRuleIndex() const {
  return PascalParser::RuleArgumentList;
}


antlrcpp::Any PascalParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ArgumentListContext* PascalParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 120, PascalParser::RuleArgumentList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(519);
    argument();
    setState(524);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__3) {
      setState(520);
      match(PascalParser::T__3);
      setState(521);
      argument();
      setState(526);
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

//----------------- ArgumentContext ------------------------------------------------------------------

PascalParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ExpressionContext* PascalParser::ArgumentContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::ArgumentContext::getRuleIndex() const {
  return PascalParser::RuleArgument;
}


antlrcpp::Any PascalParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ArgumentContext* PascalParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 122, PascalParser::RuleArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(527);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WriteStatementContext ------------------------------------------------------------------

PascalParser::WriteStatementContext::WriteStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::WriteStatementContext::WRITE() {
  return getToken(PascalParser::WRITE, 0);
}

PascalParser::WriteArgumentsContext* PascalParser::WriteStatementContext::writeArguments() {
  return getRuleContext<PascalParser::WriteArgumentsContext>(0);
}


size_t PascalParser::WriteStatementContext::getRuleIndex() const {
  return PascalParser::RuleWriteStatement;
}


antlrcpp::Any PascalParser::WriteStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWriteStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WriteStatementContext* PascalParser::writeStatement() {
  WriteStatementContext *_localctx = _tracker.createInstance<WriteStatementContext>(_ctx, getState());
  enterRule(_localctx, 124, PascalParser::RuleWriteStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(529);
    match(PascalParser::WRITE);
    setState(530);
    writeArguments();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WritelnStatementContext ------------------------------------------------------------------

PascalParser::WritelnStatementContext::WritelnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::WritelnStatementContext::WRITELN() {
  return getToken(PascalParser::WRITELN, 0);
}

PascalParser::WriteArgumentsContext* PascalParser::WritelnStatementContext::writeArguments() {
  return getRuleContext<PascalParser::WriteArgumentsContext>(0);
}


size_t PascalParser::WritelnStatementContext::getRuleIndex() const {
  return PascalParser::RuleWritelnStatement;
}


antlrcpp::Any PascalParser::WritelnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWritelnStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WritelnStatementContext* PascalParser::writelnStatement() {
  WritelnStatementContext *_localctx = _tracker.createInstance<WritelnStatementContext>(_ctx, getState());
  enterRule(_localctx, 126, PascalParser::RuleWritelnStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(532);
    match(PascalParser::WRITELN);
    setState(534);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__2) {
      setState(533);
      writeArguments();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WriteArgumentsContext ------------------------------------------------------------------

PascalParser::WriteArgumentsContext::WriteArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::WriteArgumentContext *> PascalParser::WriteArgumentsContext::writeArgument() {
  return getRuleContexts<PascalParser::WriteArgumentContext>();
}

PascalParser::WriteArgumentContext* PascalParser::WriteArgumentsContext::writeArgument(size_t i) {
  return getRuleContext<PascalParser::WriteArgumentContext>(i);
}


size_t PascalParser::WriteArgumentsContext::getRuleIndex() const {
  return PascalParser::RuleWriteArguments;
}


antlrcpp::Any PascalParser::WriteArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWriteArguments(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WriteArgumentsContext* PascalParser::writeArguments() {
  WriteArgumentsContext *_localctx = _tracker.createInstance<WriteArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 128, PascalParser::RuleWriteArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(536);
    match(PascalParser::T__2);
    setState(537);
    writeArgument();
    setState(542);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__3) {
      setState(538);
      match(PascalParser::T__3);
      setState(539);
      writeArgument();
      setState(544);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(545);
    match(PascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WriteArgumentContext ------------------------------------------------------------------

PascalParser::WriteArgumentContext::WriteArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ExpressionContext* PascalParser::WriteArgumentContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

PascalParser::FieldWidthContext* PascalParser::WriteArgumentContext::fieldWidth() {
  return getRuleContext<PascalParser::FieldWidthContext>(0);
}


size_t PascalParser::WriteArgumentContext::getRuleIndex() const {
  return PascalParser::RuleWriteArgument;
}


antlrcpp::Any PascalParser::WriteArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWriteArgument(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WriteArgumentContext* PascalParser::writeArgument() {
  WriteArgumentContext *_localctx = _tracker.createInstance<WriteArgumentContext>(_ctx, getState());
  enterRule(_localctx, 130, PascalParser::RuleWriteArgument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(547);
    expression();
    setState(550);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__11) {
      setState(548);
      match(PascalParser::T__11);
      setState(549);
      fieldWidth();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldWidthContext ------------------------------------------------------------------

PascalParser::FieldWidthContext::FieldWidthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IntegerConstantContext* PascalParser::FieldWidthContext::integerConstant() {
  return getRuleContext<PascalParser::IntegerConstantContext>(0);
}

PascalParser::SignContext* PascalParser::FieldWidthContext::sign() {
  return getRuleContext<PascalParser::SignContext>(0);
}

PascalParser::DecimalPlacesContext* PascalParser::FieldWidthContext::decimalPlaces() {
  return getRuleContext<PascalParser::DecimalPlacesContext>(0);
}


size_t PascalParser::FieldWidthContext::getRuleIndex() const {
  return PascalParser::RuleFieldWidth;
}


antlrcpp::Any PascalParser::FieldWidthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFieldWidth(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FieldWidthContext* PascalParser::fieldWidth() {
  FieldWidthContext *_localctx = _tracker.createInstance<FieldWidthContext>(_ctx, getState());
  enterRule(_localctx, 132, PascalParser::RuleFieldWidth);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(553);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__6

    || _la == PascalParser::T__7) {
      setState(552);
      sign();
    }
    setState(555);
    integerConstant();
    setState(558);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__11) {
      setState(556);
      match(PascalParser::T__11);
      setState(557);
      decimalPlaces();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecimalPlacesContext ------------------------------------------------------------------

PascalParser::DecimalPlacesContext::DecimalPlacesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IntegerConstantContext* PascalParser::DecimalPlacesContext::integerConstant() {
  return getRuleContext<PascalParser::IntegerConstantContext>(0);
}


size_t PascalParser::DecimalPlacesContext::getRuleIndex() const {
  return PascalParser::RuleDecimalPlaces;
}


antlrcpp::Any PascalParser::DecimalPlacesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitDecimalPlaces(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::DecimalPlacesContext* PascalParser::decimalPlaces() {
  DecimalPlacesContext *_localctx = _tracker.createInstance<DecimalPlacesContext>(_ctx, getState());
  enterRule(_localctx, 134, PascalParser::RuleDecimalPlaces);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(560);
    integerConstant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadStatementContext ------------------------------------------------------------------

PascalParser::ReadStatementContext::ReadStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ReadStatementContext::READ() {
  return getToken(PascalParser::READ, 0);
}

PascalParser::ReadArgumentsContext* PascalParser::ReadStatementContext::readArguments() {
  return getRuleContext<PascalParser::ReadArgumentsContext>(0);
}


size_t PascalParser::ReadStatementContext::getRuleIndex() const {
  return PascalParser::RuleReadStatement;
}


antlrcpp::Any PascalParser::ReadStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitReadStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ReadStatementContext* PascalParser::readStatement() {
  ReadStatementContext *_localctx = _tracker.createInstance<ReadStatementContext>(_ctx, getState());
  enterRule(_localctx, 136, PascalParser::RuleReadStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(562);
    match(PascalParser::READ);
    setState(563);
    readArguments();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadlnStatementContext ------------------------------------------------------------------

PascalParser::ReadlnStatementContext::ReadlnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ReadlnStatementContext::READLN() {
  return getToken(PascalParser::READLN, 0);
}

PascalParser::ReadArgumentsContext* PascalParser::ReadlnStatementContext::readArguments() {
  return getRuleContext<PascalParser::ReadArgumentsContext>(0);
}


size_t PascalParser::ReadlnStatementContext::getRuleIndex() const {
  return PascalParser::RuleReadlnStatement;
}


antlrcpp::Any PascalParser::ReadlnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitReadlnStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ReadlnStatementContext* PascalParser::readlnStatement() {
  ReadlnStatementContext *_localctx = _tracker.createInstance<ReadlnStatementContext>(_ctx, getState());
  enterRule(_localctx, 138, PascalParser::RuleReadlnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(565);
    match(PascalParser::READLN);
    setState(566);
    readArguments();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadArgumentsContext ------------------------------------------------------------------

PascalParser::ReadArgumentsContext::ReadArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::VariableContext *> PascalParser::ReadArgumentsContext::variable() {
  return getRuleContexts<PascalParser::VariableContext>();
}

PascalParser::VariableContext* PascalParser::ReadArgumentsContext::variable(size_t i) {
  return getRuleContext<PascalParser::VariableContext>(i);
}


size_t PascalParser::ReadArgumentsContext::getRuleIndex() const {
  return PascalParser::RuleReadArguments;
}


antlrcpp::Any PascalParser::ReadArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitReadArguments(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ReadArgumentsContext* PascalParser::readArguments() {
  ReadArgumentsContext *_localctx = _tracker.createInstance<ReadArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 140, PascalParser::RuleReadArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(568);
    match(PascalParser::T__2);
    setState(569);
    variable();
    setState(574);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__3) {
      setState(570);
      match(PascalParser::T__3);
      setState(571);
      variable();
      setState(576);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(577);
    match(PascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

PascalParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::SimpleExpressionContext *> PascalParser::ExpressionContext::simpleExpression() {
  return getRuleContexts<PascalParser::SimpleExpressionContext>();
}

PascalParser::SimpleExpressionContext* PascalParser::ExpressionContext::simpleExpression(size_t i) {
  return getRuleContext<PascalParser::SimpleExpressionContext>(i);
}

PascalParser::RelOpContext* PascalParser::ExpressionContext::relOp() {
  return getRuleContext<PascalParser::RelOpContext>(0);
}


size_t PascalParser::ExpressionContext::getRuleIndex() const {
  return PascalParser::RuleExpression;
}


antlrcpp::Any PascalParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ExpressionContext* PascalParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 142, PascalParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(579);
    simpleExpression();
    setState(583);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__5)
      | (1ULL << PascalParser::T__13)
      | (1ULL << PascalParser::T__14)
      | (1ULL << PascalParser::T__15)
      | (1ULL << PascalParser::T__16)
      | (1ULL << PascalParser::T__17))) != 0)) {
      setState(580);
      relOp();
      setState(581);
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

//----------------- SimpleExpressionContext ------------------------------------------------------------------

PascalParser::SimpleExpressionContext::SimpleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::TermContext *> PascalParser::SimpleExpressionContext::term() {
  return getRuleContexts<PascalParser::TermContext>();
}

PascalParser::TermContext* PascalParser::SimpleExpressionContext::term(size_t i) {
  return getRuleContext<PascalParser::TermContext>(i);
}

PascalParser::SignContext* PascalParser::SimpleExpressionContext::sign() {
  return getRuleContext<PascalParser::SignContext>(0);
}

std::vector<PascalParser::AddOpContext *> PascalParser::SimpleExpressionContext::addOp() {
  return getRuleContexts<PascalParser::AddOpContext>();
}

PascalParser::AddOpContext* PascalParser::SimpleExpressionContext::addOp(size_t i) {
  return getRuleContext<PascalParser::AddOpContext>(i);
}


size_t PascalParser::SimpleExpressionContext::getRuleIndex() const {
  return PascalParser::RuleSimpleExpression;
}


antlrcpp::Any PascalParser::SimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSimpleExpression(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::SimpleExpressionContext* PascalParser::simpleExpression() {
  SimpleExpressionContext *_localctx = _tracker.createInstance<SimpleExpressionContext>(_ctx, getState());
  enterRule(_localctx, 144, PascalParser::RuleSimpleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(586);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(585);
      sign();
      break;
    }

    }
    setState(588);
    term();
    setState(594);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__6)
      | (1ULL << PascalParser::T__7)
      | (1ULL << PascalParser::OR))) != 0)) {
      setState(589);
      addOp();
      setState(590);
      term();
      setState(596);
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

//----------------- TermContext ------------------------------------------------------------------

PascalParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::FactorContext *> PascalParser::TermContext::factor() {
  return getRuleContexts<PascalParser::FactorContext>();
}

PascalParser::FactorContext* PascalParser::TermContext::factor(size_t i) {
  return getRuleContext<PascalParser::FactorContext>(i);
}

std::vector<PascalParser::MulOpContext *> PascalParser::TermContext::mulOp() {
  return getRuleContexts<PascalParser::MulOpContext>();
}

PascalParser::MulOpContext* PascalParser::TermContext::mulOp(size_t i) {
  return getRuleContext<PascalParser::MulOpContext>(i);
}


size_t PascalParser::TermContext::getRuleIndex() const {
  return PascalParser::RuleTerm;
}


antlrcpp::Any PascalParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TermContext* PascalParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 146, PascalParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(597);
    factor();
    setState(603);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__18)
      | (1ULL << PascalParser::T__19)
      | (1ULL << PascalParser::DIV)
      | (1ULL << PascalParser::MOD)
      | (1ULL << PascalParser::AND))) != 0)) {
      setState(598);
      mulOp();
      setState(599);
      factor();
      setState(605);
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

//----------------- FactorContext ------------------------------------------------------------------

PascalParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalParser::FactorContext::getRuleIndex() const {
  return PascalParser::RuleFactor;
}

void PascalParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- NumberFactorContext ------------------------------------------------------------------

PascalParser::NumberContext* PascalParser::NumberFactorContext::number() {
  return getRuleContext<PascalParser::NumberContext>(0);
}

PascalParser::NumberFactorContext::NumberFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::NumberFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitNumberFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringFactorContext ------------------------------------------------------------------

PascalParser::StringConstantContext* PascalParser::StringFactorContext::stringConstant() {
  return getRuleContext<PascalParser::StringConstantContext>(0);
}

PascalParser::StringFactorContext::StringFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::StringFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStringFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharacterFactorContext ------------------------------------------------------------------

PascalParser::CharacterConstantContext* PascalParser::CharacterFactorContext::characterConstant() {
  return getRuleContext<PascalParser::CharacterConstantContext>(0);
}

PascalParser::CharacterFactorContext::CharacterFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::CharacterFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCharacterFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableFactorContext ------------------------------------------------------------------

PascalParser::VariableContext* PascalParser::VariableFactorContext::variable() {
  return getRuleContext<PascalParser::VariableContext>(0);
}

PascalParser::VariableFactorContext::VariableFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::VariableFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariableFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallFactorContext ------------------------------------------------------------------

PascalParser::FunctionCallContext* PascalParser::FunctionCallFactorContext::functionCall() {
  return getRuleContext<PascalParser::FunctionCallContext>(0);
}

PascalParser::FunctionCallFactorContext::FunctionCallFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::FunctionCallFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFunctionCallFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotFactorContext ------------------------------------------------------------------

tree::TerminalNode* PascalParser::NotFactorContext::NOT() {
  return getToken(PascalParser::NOT, 0);
}

PascalParser::FactorContext* PascalParser::NotFactorContext::factor() {
  return getRuleContext<PascalParser::FactorContext>(0);
}

PascalParser::NotFactorContext::NotFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::NotFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitNotFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedFactorContext ------------------------------------------------------------------

PascalParser::ExpressionContext* PascalParser::ParenthesizedFactorContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

PascalParser::ParenthesizedFactorContext::ParenthesizedFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any PascalParser::ParenthesizedFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParenthesizedFactor(this);
  else
    return visitor->visitChildren(this);
}
PascalParser::FactorContext* PascalParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 148, PascalParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(617);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::VariableFactorContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(606);
      variable();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::NumberFactorContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(607);
      number();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::CharacterFactorContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(608);
      characterConstant();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::StringFactorContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(609);
      stringConstant();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::FunctionCallFactorContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(610);
      functionCall();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::NotFactorContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(611);
      match(PascalParser::NOT);
      setState(612);
      factor();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<PascalParser::ParenthesizedFactorContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(613);
      match(PascalParser::T__2);
      setState(614);
      expression();
      setState(615);
      match(PascalParser::T__4);
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

//----------------- VariableContext ------------------------------------------------------------------

PascalParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::VariableIdentifierContext* PascalParser::VariableContext::variableIdentifier() {
  return getRuleContext<PascalParser::VariableIdentifierContext>(0);
}

std::vector<PascalParser::ModifierContext *> PascalParser::VariableContext::modifier() {
  return getRuleContexts<PascalParser::ModifierContext>();
}

PascalParser::ModifierContext* PascalParser::VariableContext::modifier(size_t i) {
  return getRuleContext<PascalParser::ModifierContext>(i);
}


size_t PascalParser::VariableContext::getRuleIndex() const {
  return PascalParser::RuleVariable;
}


antlrcpp::Any PascalParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableContext* PascalParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 150, PascalParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(619);
    variableIdentifier();
    setState(623);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__0

    || _la == PascalParser::T__9) {
      setState(620);
      modifier();
      setState(625);
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

//----------------- ModifierContext ------------------------------------------------------------------

PascalParser::ModifierContext::ModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IndexListContext* PascalParser::ModifierContext::indexList() {
  return getRuleContext<PascalParser::IndexListContext>(0);
}

PascalParser::FieldContext* PascalParser::ModifierContext::field() {
  return getRuleContext<PascalParser::FieldContext>(0);
}


size_t PascalParser::ModifierContext::getRuleIndex() const {
  return PascalParser::RuleModifier;
}


antlrcpp::Any PascalParser::ModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitModifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ModifierContext* PascalParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 152, PascalParser::RuleModifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(632);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(626);
        match(PascalParser::T__9);
        setState(627);
        indexList();
        setState(628);
        match(PascalParser::T__10);
        break;
      }

      case PascalParser::T__0: {
        enterOuterAlt(_localctx, 2);
        setState(630);
        match(PascalParser::T__0);
        setState(631);
        field();
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

//----------------- IndexListContext ------------------------------------------------------------------

PascalParser::IndexListContext::IndexListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::IndexContext *> PascalParser::IndexListContext::index() {
  return getRuleContexts<PascalParser::IndexContext>();
}

PascalParser::IndexContext* PascalParser::IndexListContext::index(size_t i) {
  return getRuleContext<PascalParser::IndexContext>(i);
}


size_t PascalParser::IndexListContext::getRuleIndex() const {
  return PascalParser::RuleIndexList;
}


antlrcpp::Any PascalParser::IndexListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitIndexList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::IndexListContext* PascalParser::indexList() {
  IndexListContext *_localctx = _tracker.createInstance<IndexListContext>(_ctx, getState());
  enterRule(_localctx, 154, PascalParser::RuleIndexList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(634);
    index();
    setState(639);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::T__3) {
      setState(635);
      match(PascalParser::T__3);
      setState(636);
      index();
      setState(641);
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

//----------------- IndexContext ------------------------------------------------------------------

PascalParser::IndexContext::IndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ExpressionContext* PascalParser::IndexContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::IndexContext::getRuleIndex() const {
  return PascalParser::RuleIndex;
}


antlrcpp::Any PascalParser::IndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitIndex(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::IndexContext* PascalParser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 156, PascalParser::RuleIndex);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(642);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldContext ------------------------------------------------------------------

PascalParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::FieldContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::FieldContext::getRuleIndex() const {
  return PascalParser::RuleField;
}


antlrcpp::Any PascalParser::FieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitField(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FieldContext* PascalParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 158, PascalParser::RuleField);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(644);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

PascalParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::FunctionNameContext* PascalParser::FunctionCallContext::functionName() {
  return getRuleContext<PascalParser::FunctionNameContext>(0);
}

PascalParser::ArgumentListContext* PascalParser::FunctionCallContext::argumentList() {
  return getRuleContext<PascalParser::ArgumentListContext>(0);
}


size_t PascalParser::FunctionCallContext::getRuleIndex() const {
  return PascalParser::RuleFunctionCall;
}


antlrcpp::Any PascalParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FunctionCallContext* PascalParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 160, PascalParser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(646);
    functionName();
    setState(647);
    match(PascalParser::T__2);
    setState(649);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__2)
      | (1ULL << PascalParser::T__6)
      | (1ULL << PascalParser::T__7)
      | (1ULL << PascalParser::NOT)
      | (1ULL << PascalParser::IDENTIFIER)
      | (1ULL << PascalParser::INTEGER)
      | (1ULL << PascalParser::REAL)
      | (1ULL << PascalParser::CHARACTER)
      | (1ULL << PascalParser::STRING))) != 0)) {
      setState(648);
      argumentList();
    }
    setState(651);
    match(PascalParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionNameContext ------------------------------------------------------------------

PascalParser::FunctionNameContext::FunctionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::FunctionNameContext::IDENTIFIER() {
  return getToken(PascalParser::IDENTIFIER, 0);
}


size_t PascalParser::FunctionNameContext::getRuleIndex() const {
  return PascalParser::RuleFunctionName;
}


antlrcpp::Any PascalParser::FunctionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFunctionName(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FunctionNameContext* PascalParser::functionName() {
  FunctionNameContext *_localctx = _tracker.createInstance<FunctionNameContext>(_ctx, getState());
  enterRule(_localctx, 162, PascalParser::RuleFunctionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(653);
    match(PascalParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

PascalParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::UnsignedNumberContext* PascalParser::NumberContext::unsignedNumber() {
  return getRuleContext<PascalParser::UnsignedNumberContext>(0);
}

PascalParser::SignContext* PascalParser::NumberContext::sign() {
  return getRuleContext<PascalParser::SignContext>(0);
}


size_t PascalParser::NumberContext::getRuleIndex() const {
  return PascalParser::RuleNumber;
}


antlrcpp::Any PascalParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::NumberContext* PascalParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 164, PascalParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(656);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::T__6

    || _la == PascalParser::T__7) {
      setState(655);
      sign();
    }
    setState(658);
    unsignedNumber();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedNumberContext ------------------------------------------------------------------

PascalParser::UnsignedNumberContext::UnsignedNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IntegerConstantContext* PascalParser::UnsignedNumberContext::integerConstant() {
  return getRuleContext<PascalParser::IntegerConstantContext>(0);
}

PascalParser::RealConstantContext* PascalParser::UnsignedNumberContext::realConstant() {
  return getRuleContext<PascalParser::RealConstantContext>(0);
}


size_t PascalParser::UnsignedNumberContext::getRuleIndex() const {
  return PascalParser::RuleUnsignedNumber;
}


antlrcpp::Any PascalParser::UnsignedNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitUnsignedNumber(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::UnsignedNumberContext* PascalParser::unsignedNumber() {
  UnsignedNumberContext *_localctx = _tracker.createInstance<UnsignedNumberContext>(_ctx, getState());
  enterRule(_localctx, 166, PascalParser::RuleUnsignedNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(662);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(660);
        integerConstant();
        break;
      }

      case PascalParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(661);
        realConstant();
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

//----------------- IntegerConstantContext ------------------------------------------------------------------

PascalParser::IntegerConstantContext::IntegerConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::IntegerConstantContext::INTEGER() {
  return getToken(PascalParser::INTEGER, 0);
}


size_t PascalParser::IntegerConstantContext::getRuleIndex() const {
  return PascalParser::RuleIntegerConstant;
}


antlrcpp::Any PascalParser::IntegerConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitIntegerConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::IntegerConstantContext* PascalParser::integerConstant() {
  IntegerConstantContext *_localctx = _tracker.createInstance<IntegerConstantContext>(_ctx, getState());
  enterRule(_localctx, 168, PascalParser::RuleIntegerConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(664);
    match(PascalParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RealConstantContext ------------------------------------------------------------------

PascalParser::RealConstantContext::RealConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::RealConstantContext::REAL() {
  return getToken(PascalParser::REAL, 0);
}


size_t PascalParser::RealConstantContext::getRuleIndex() const {
  return PascalParser::RuleRealConstant;
}


antlrcpp::Any PascalParser::RealConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRealConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RealConstantContext* PascalParser::realConstant() {
  RealConstantContext *_localctx = _tracker.createInstance<RealConstantContext>(_ctx, getState());
  enterRule(_localctx, 170, PascalParser::RuleRealConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(666);
    match(PascalParser::REAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CharacterConstantContext ------------------------------------------------------------------

PascalParser::CharacterConstantContext::CharacterConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::CharacterConstantContext::CHARACTER() {
  return getToken(PascalParser::CHARACTER, 0);
}


size_t PascalParser::CharacterConstantContext::getRuleIndex() const {
  return PascalParser::RuleCharacterConstant;
}


antlrcpp::Any PascalParser::CharacterConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCharacterConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CharacterConstantContext* PascalParser::characterConstant() {
  CharacterConstantContext *_localctx = _tracker.createInstance<CharacterConstantContext>(_ctx, getState());
  enterRule(_localctx, 172, PascalParser::RuleCharacterConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(668);
    match(PascalParser::CHARACTER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringConstantContext ------------------------------------------------------------------

PascalParser::StringConstantContext::StringConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::StringConstantContext::STRING() {
  return getToken(PascalParser::STRING, 0);
}


size_t PascalParser::StringConstantContext::getRuleIndex() const {
  return PascalParser::RuleStringConstant;
}


antlrcpp::Any PascalParser::StringConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStringConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::StringConstantContext* PascalParser::stringConstant() {
  StringConstantContext *_localctx = _tracker.createInstance<StringConstantContext>(_ctx, getState());
  enterRule(_localctx, 174, PascalParser::RuleStringConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(670);
    match(PascalParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

PascalParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalParser::RelOpContext::getRuleIndex() const {
  return PascalParser::RuleRelOp;
}


antlrcpp::Any PascalParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RelOpContext* PascalParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 176, PascalParser::RuleRelOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(672);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__5)
      | (1ULL << PascalParser::T__13)
      | (1ULL << PascalParser::T__14)
      | (1ULL << PascalParser::T__15)
      | (1ULL << PascalParser::T__16)
      | (1ULL << PascalParser::T__17))) != 0))) {
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

//----------------- AddOpContext ------------------------------------------------------------------

PascalParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::AddOpContext::OR() {
  return getToken(PascalParser::OR, 0);
}


size_t PascalParser::AddOpContext::getRuleIndex() const {
  return PascalParser::RuleAddOp;
}


antlrcpp::Any PascalParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::AddOpContext* PascalParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 178, PascalParser::RuleAddOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(674);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__6)
      | (1ULL << PascalParser::T__7)
      | (1ULL << PascalParser::OR))) != 0))) {
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

//----------------- MulOpContext ------------------------------------------------------------------

PascalParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::MulOpContext::DIV() {
  return getToken(PascalParser::DIV, 0);
}

tree::TerminalNode* PascalParser::MulOpContext::MOD() {
  return getToken(PascalParser::MOD, 0);
}

tree::TerminalNode* PascalParser::MulOpContext::AND() {
  return getToken(PascalParser::AND, 0);
}


size_t PascalParser::MulOpContext::getRuleIndex() const {
  return PascalParser::RuleMulOp;
}


antlrcpp::Any PascalParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::MulOpContext* PascalParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 180, PascalParser::RuleMulOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(676);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::T__18)
      | (1ULL << PascalParser::T__19)
      | (1ULL << PascalParser::DIV)
      | (1ULL << PascalParser::MOD)
      | (1ULL << PascalParser::AND))) != 0))) {
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

// Static vars and initialization.
std::vector<dfa::DFA> PascalParser::_decisionToDFA;
atn::PredictionContextCache PascalParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PascalParser::_atn;
std::vector<uint16_t> PascalParser::_serializedATN;

std::vector<std::string> PascalParser::_ruleNames = {
  "program", "programHeader", "programParameters", "programIdentifier", 
  "block", "declarations", "constantsPart", "constantDefinitionsList", "constantDefinition", 
  "constantIdentifier", "constant", "sign", "typesPart", "typeDefinitionsList", 
  "typeDefinition", "typeIdentifier", "typeSpecification", "simpleType", 
  "enumerationType", "enumerationConstant", "subrangeType", "arrayType", 
  "arrayDimensionList", "recordType", "recordFields", "variablesPart", "variableDeclarationsList", 
  "variableDeclarations", "variableIdentifierList", "variableIdentifier", 
  "routinesPart", "routineDefinition", "procedureHead", "functionHead", 
  "routineIdentifier", "parameters", "parameterDeclarationsList", "parameterDeclarations", 
  "parameterIdentifierList", "parameterIdentifier", "statement", "compoundStatement", 
  "emptyStatement", "statementList", "assignmentStatement", "lhs", "rhs", 
  "ifStatement", "trueStatement", "falseStatement", "caseStatement", "caseBranchList", 
  "caseBranch", "caseConstantList", "caseConstant", "repeatStatement", "whileStatement", 
  "forStatement", "procedureCallStatement", "procedureName", "argumentList", 
  "argument", "writeStatement", "writelnStatement", "writeArguments", "writeArgument", 
  "fieldWidth", "decimalPlaces", "readStatement", "readlnStatement", "readArguments", 
  "expression", "simpleExpression", "term", "factor", "variable", "modifier", 
  "indexList", "index", "field", "functionCall", "functionName", "number", 
  "unsignedNumber", "integerConstant", "realConstant", "characterConstant", 
  "stringConstant", "relOp", "addOp", "mulOp"
};

std::vector<std::string> PascalParser::_literalNames = {
  "", "'.'", "';'", "'('", "','", "')'", "'='", "'-'", "'+'", "'..'", "'['", 
  "']'", "':'", "':='", "'<>'", "'<'", "'<='", "'>'", "'>='", "'*'", "'/'", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "'''"
};

std::vector<std::string> PascalParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "PROGRAM", "CONST", "TYPE", "ARRAY", "OF", "RECORD", "VAR", 
  "BEGIN", "END", "DIV", "MOD", "AND", "OR", "NOT", "IF", "THEN", "ELSE", 
  "CASE", "REPEAT", "UNTIL", "WHILE", "DO", "FOR", "TO", "DOWNTO", "WRITE", 
  "WRITELN", "READ", "READLN", "PROCEDURE", "FUNCTION", "IDENTIFIER", "INTEGER", 
  "REAL", "NEWLINE", "WS", "QUOTE", "CHARACTER", "STRING", "COMMENT"
};

dfa::Vocabulary PascalParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> PascalParser::_tokenNames;

PascalParser::Initializer::Initializer() {
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
    0x3, 0x3e, 0x2a9, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0xc0, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x7, 0x4, 0xc8, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xcb, 0xb, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xd7, 0xa, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xdc, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0xe1, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 
    0xe6, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x7, 0x9, 0xee, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xf1, 0xb, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x5, 
    0xc, 0xfa, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xfe, 0xa, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0x102, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x10c, 0xa, 
    0xf, 0xc, 0xf, 0xe, 0xf, 0x10f, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x5, 0x12, 0x11a, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 
    0x11f, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 
    0x125, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x128, 0xb, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x13c, 0xa, 0x18, 
    0xc, 0x18, 0xe, 0x18, 0x13f, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x5, 0x19, 0x144, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 
    0x1c, 0x150, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x153, 0xb, 0x1c, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x7, 0x1e, 0x15c, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x15f, 0xb, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x166, 
    0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x169, 0xb, 0x20, 0x3, 0x21, 0x3, 0x21, 
    0x5, 0x21, 0x16d, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x175, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x5, 0x23, 0x17a, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
    0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x188, 0xa, 0x26, 0xc, 0x26, 
    0xe, 0x26, 0x18b, 0xb, 0x26, 0x3, 0x27, 0x5, 0x27, 0x18e, 0xa, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x28, 0x7, 0x28, 0x197, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x19a, 0xb, 
    0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
    0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1ab, 0xa, 0x2a, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x1b6, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 
    0x1b9, 0xb, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x1c9, 0xa, 0x31, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
    0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 
    0x1d8, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x1db, 0xb, 0x35, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x1e2, 0xa, 0x36, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 0x1e7, 0xa, 0x37, 0xc, 0x37, 
    0xe, 0x37, 0x1ea, 0xb, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
    0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x5, 0x3c, 0x204, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x20d, 0xa, 0x3e, 
    0xc, 0x3e, 0xe, 0x3e, 0x210, 0xb, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 0x219, 0xa, 0x41, 
    0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x7, 0x42, 0x21f, 0xa, 0x42, 
    0xc, 0x42, 0xe, 0x42, 0x222, 0xb, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x229, 0xa, 0x43, 0x3, 0x44, 0x5, 0x44, 
    0x22c, 0xa, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x231, 
    0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 
    0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 
    0x7, 0x48, 0x23f, 0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x242, 0xb, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 
    0x49, 0x24a, 0xa, 0x49, 0x3, 0x4a, 0x5, 0x4a, 0x24d, 0xa, 0x4a, 0x3, 
    0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x7, 0x4a, 0x253, 0xa, 0x4a, 
    0xc, 0x4a, 0xe, 0x4a, 0x256, 0xb, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 
    0x3, 0x4b, 0x7, 0x4b, 0x25c, 0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 0x25f, 
    0xb, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 
    0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x5, 0x4c, 
    0x26c, 0xa, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x7, 0x4d, 0x270, 0xa, 0x4d, 
    0xc, 0x4d, 0xe, 0x4d, 0x273, 0xb, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x27b, 0xa, 0x4e, 0x3, 0x4f, 
    0x3, 0x4f, 0x3, 0x4f, 0x7, 0x4f, 0x280, 0xa, 0x4f, 0xc, 0x4f, 0xe, 0x4f, 
    0x283, 0xb, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 
    0x3, 0x52, 0x3, 0x52, 0x5, 0x52, 0x28c, 0xa, 0x52, 0x3, 0x52, 0x3, 0x52, 
    0x3, 0x53, 0x3, 0x53, 0x3, 0x54, 0x5, 0x54, 0x293, 0xa, 0x54, 0x3, 0x54, 
    0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x5, 0x55, 0x299, 0xa, 0x55, 0x3, 0x56, 
    0x3, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x3, 
    0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 
    0x3, 0x5c, 0x2, 0x2, 0x5d, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 
    0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 
    0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 
    0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 
    0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 
    0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0x2, 
    0x7, 0x3, 0x2, 0x9, 0xa, 0x3, 0x2, 0x2e, 0x2f, 0x4, 0x2, 0x8, 0x8, 0x10, 
    0x14, 0x4, 0x2, 0x9, 0xa, 0x23, 0x23, 0x4, 0x2, 0x15, 0x16, 0x20, 0x22, 
    0x2, 0x292, 0x2, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x4, 0xbc, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x8, 0xce, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0xd0, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xe, 0xe7, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xea, 0x3, 0x2, 0x2, 0x2, 0x12, 0xf2, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x16, 0x101, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x103, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x105, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x108, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x110, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x114, 0x3, 0x2, 0x2, 0x2, 0x22, 0x119, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x11e, 0x3, 0x2, 0x2, 0x2, 0x26, 0x120, 0x3, 0x2, 0x2, 0x2, 0x28, 0x12b, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x131, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x138, 0x3, 0x2, 0x2, 0x2, 0x30, 0x140, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x147, 0x3, 0x2, 0x2, 0x2, 0x34, 0x149, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x38, 0x154, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x158, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x160, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x162, 0x3, 0x2, 0x2, 0x2, 0x40, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x42, 0x171, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x176, 0x3, 0x2, 0x2, 0x2, 0x46, 0x17e, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x180, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x184, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x193, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1aa, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x1b2, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1be, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1c2, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1cc, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1d4, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x1e3, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x70, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x72, 
    0x1f2, 0x3, 0x2, 0x2, 0x2, 0x74, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x76, 0x200, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x207, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x209, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x211, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x213, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x216, 0x3, 0x2, 0x2, 0x2, 0x82, 0x21a, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x225, 0x3, 0x2, 0x2, 0x2, 0x86, 0x22b, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x232, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x234, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x237, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x90, 0x245, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x94, 0x257, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x98, 0x26d, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x27c, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0x284, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x286, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0x288, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x28f, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0x292, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x298, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x29a, 
    0x3, 0x2, 0x2, 0x2, 0xac, 0x29c, 0x3, 0x2, 0x2, 0x2, 0xae, 0x29e, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x2a2, 0x3, 0x2, 
    0x2, 0x2, 0xb4, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x2a6, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xb9, 0x5, 0x4, 0x3, 0x2, 0xb9, 0xba, 0x5, 0xa, 0x6, 0x2, 
    0xba, 0xbb, 0x7, 0x3, 0x2, 0x2, 0xbb, 0x3, 0x3, 0x2, 0x2, 0x2, 0xbc, 
    0xbd, 0x7, 0x17, 0x2, 0x2, 0xbd, 0xbf, 0x5, 0x8, 0x5, 0x2, 0xbe, 0xc0, 
    0x5, 0x6, 0x4, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x4, 
    0x2, 0x2, 0xc2, 0x5, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x5, 0x2, 
    0x2, 0xc4, 0xc9, 0x7, 0x36, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0x6, 0x2, 0x2, 
    0xc6, 0xc8, 0x7, 0x36, 0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc8, 
    0xcb, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 
    0x3, 0x2, 0x2, 0x2, 0xca, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x7, 0x2, 0x2, 0xcd, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0xce, 0xcf, 0x7, 0x36, 0x2, 0x2, 0xcf, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0xd0, 0xd1, 0x5, 0xc, 0x7, 0x2, 0xd1, 0xd2, 0x5, 0x54, 0x2b, 0x2, 
    0xd2, 0xb, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0xe, 0x8, 0x2, 0xd4, 
    0xd5, 0x7, 0x4, 0x2, 0x2, 0xd5, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd3, 
    0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xdb, 0x3, 
    0x2, 0x2, 0x2, 0xd8, 0xd9, 0x5, 0x1a, 0xe, 0x2, 0xd9, 0xda, 0x7, 0x4, 
    0x2, 0x2, 0xda, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd8, 0x3, 0x2, 0x2, 
    0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xdd, 0xde, 0x5, 0x34, 0x1b, 0x2, 0xde, 0xdf, 0x7, 0x4, 0x2, 0x2, 0xdf, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 
    0x3, 0x2, 0x2, 0x2, 0xe1, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x5, 
    0x3e, 0x20, 0x2, 0xe3, 0xe4, 0x7, 0x4, 0x2, 0x2, 0xe4, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0xe5, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x3, 0x2, 0x2, 
    0x2, 0xe6, 0xd, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x18, 0x2, 0x2, 
    0xe8, 0xe9, 0x5, 0x10, 0x9, 0x2, 0xe9, 0xf, 0x3, 0x2, 0x2, 0x2, 0xea, 
    0xef, 0x5, 0x12, 0xa, 0x2, 0xeb, 0xec, 0x7, 0x4, 0x2, 0x2, 0xec, 0xee, 
    0x5, 0x12, 0xa, 0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 
    0x2, 0x2, 0xf0, 0x11, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 
    0x2, 0xf2, 0xf3, 0x5, 0x14, 0xb, 0x2, 0xf3, 0xf4, 0x7, 0x8, 0x2, 0x2, 
    0xf4, 0xf5, 0x5, 0x16, 0xc, 0x2, 0xf5, 0x13, 0x3, 0x2, 0x2, 0x2, 0xf6, 
    0xf7, 0x7, 0x36, 0x2, 0x2, 0xf7, 0x15, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfa, 
    0x5, 0x18, 0xd, 0x2, 0xf9, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfe, 0x7, 0x36, 
    0x2, 0x2, 0xfc, 0xfe, 0x5, 0xa8, 0x55, 0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 
    0x2, 0xfd, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x102, 0x3, 0x2, 0x2, 0x2, 
    0xff, 0x102, 0x5, 0xae, 0x58, 0x2, 0x100, 0x102, 0x5, 0xb0, 0x59, 0x2, 
    0x101, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 
    0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x17, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 
    0x9, 0x2, 0x2, 0x2, 0x104, 0x19, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 
    0x19, 0x2, 0x2, 0x106, 0x107, 0x5, 0x1c, 0xf, 0x2, 0x107, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0x10d, 0x5, 0x1e, 0x10, 0x2, 0x109, 0x10a, 0x7, 
    0x4, 0x2, 0x2, 0x10a, 0x10c, 0x5, 0x1e, 0x10, 0x2, 0x10b, 0x109, 0x3, 
    0x2, 0x2, 0x2, 0x10c, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10b, 0x3, 
    0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x5, 0x20, 
    0x11, 0x2, 0x111, 0x112, 0x7, 0x8, 0x2, 0x2, 0x112, 0x113, 0x5, 0x22, 
    0x12, 0x2, 0x113, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x7, 0x36, 
    0x2, 0x2, 0x115, 0x21, 0x3, 0x2, 0x2, 0x2, 0x116, 0x11a, 0x5, 0x24, 
    0x13, 0x2, 0x117, 0x11a, 0x5, 0x2c, 0x17, 0x2, 0x118, 0x11a, 0x5, 0x30, 
    0x19, 0x2, 0x119, 0x116, 0x3, 0x2, 0x2, 0x2, 0x119, 0x117, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x11b, 0x11f, 0x5, 0x20, 0x11, 0x2, 0x11c, 0x11f, 0x5, 0x26, 0x14, 
    0x2, 0x11d, 0x11f, 0x5, 0x2a, 0x16, 0x2, 0x11e, 0x11b, 0x3, 0x2, 0x2, 
    0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11d, 0x3, 0x2, 0x2, 
    0x2, 0x11f, 0x25, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x7, 0x5, 0x2, 0x2, 
    0x121, 0x126, 0x5, 0x28, 0x15, 0x2, 0x122, 0x123, 0x7, 0x6, 0x2, 0x2, 
    0x123, 0x125, 0x5, 0x28, 0x15, 0x2, 0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 
    0x125, 0x128, 0x3, 0x2, 0x2, 0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 
    0x126, 0x127, 0x3, 0x2, 0x2, 0x2, 0x127, 0x129, 0x3, 0x2, 0x2, 0x2, 
    0x128, 0x126, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x7, 0x7, 0x2, 0x2, 
    0x12a, 0x27, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x5, 0x14, 0xb, 0x2, 
    0x12c, 0x29, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x5, 0x16, 0xc, 0x2, 
    0x12e, 0x12f, 0x7, 0xb, 0x2, 0x2, 0x12f, 0x130, 0x5, 0x16, 0xc, 0x2, 
    0x130, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x7, 0x1a, 0x2, 0x2, 
    0x132, 0x133, 0x7, 0xc, 0x2, 0x2, 0x133, 0x134, 0x5, 0x2e, 0x18, 0x2, 
    0x134, 0x135, 0x7, 0xd, 0x2, 0x2, 0x135, 0x136, 0x7, 0x1b, 0x2, 0x2, 
    0x136, 0x137, 0x5, 0x22, 0x12, 0x2, 0x137, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x138, 0x13d, 0x5, 0x24, 0x13, 0x2, 0x139, 0x13a, 0x7, 0x6, 0x2, 0x2, 
    0x13a, 0x13c, 0x5, 0x24, 0x13, 0x2, 0x13b, 0x139, 0x3, 0x2, 0x2, 0x2, 
    0x13c, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13b, 0x3, 0x2, 0x2, 0x2, 
    0x13d, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x13f, 
    0x13d, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0x7, 0x1c, 0x2, 0x2, 0x141, 
    0x143, 0x5, 0x32, 0x1a, 0x2, 0x142, 0x144, 0x7, 0x4, 0x2, 0x2, 0x143, 
    0x142, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x3, 0x2, 0x2, 0x2, 0x144, 
    0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x7, 0x1f, 0x2, 0x2, 0x146, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0x5, 0x36, 0x1c, 0x2, 0x148, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x7, 0x1d, 0x2, 0x2, 0x14a, 
    0x14b, 0x5, 0x36, 0x1c, 0x2, 0x14b, 0x35, 0x3, 0x2, 0x2, 0x2, 0x14c, 
    0x151, 0x5, 0x38, 0x1d, 0x2, 0x14d, 0x14e, 0x7, 0x4, 0x2, 0x2, 0x14e, 
    0x150, 0x5, 0x38, 0x1d, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x150, 
    0x153, 0x3, 0x2, 0x2, 0x2, 0x151, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x151, 
    0x152, 0x3, 0x2, 0x2, 0x2, 0x152, 0x37, 0x3, 0x2, 0x2, 0x2, 0x153, 0x151, 
    0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x5, 0x3a, 0x1e, 0x2, 0x155, 0x156, 
    0x7, 0xe, 0x2, 0x2, 0x156, 0x157, 0x5, 0x22, 0x12, 0x2, 0x157, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0x158, 0x15d, 0x5, 0x3c, 0x1f, 0x2, 0x159, 0x15a, 
    0x7, 0x6, 0x2, 0x2, 0x15a, 0x15c, 0x5, 0x3c, 0x1f, 0x2, 0x15b, 0x159, 
    0x3, 0x2, 0x2, 0x2, 0x15c, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15b, 
    0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x15f, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x7, 
    0x36, 0x2, 0x2, 0x161, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x162, 0x167, 0x5, 
    0x40, 0x21, 0x2, 0x163, 0x164, 0x7, 0x4, 0x2, 0x2, 0x164, 0x166, 0x5, 
    0x40, 0x21, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 0x2, 0x166, 0x169, 0x3, 
    0x2, 0x2, 0x2, 0x167, 0x165, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x3, 
    0x2, 0x2, 0x2, 0x168, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x169, 0x167, 0x3, 0x2, 
    0x2, 0x2, 0x16a, 0x16d, 0x5, 0x42, 0x22, 0x2, 0x16b, 0x16d, 0x5, 0x44, 
    0x23, 0x2, 0x16c, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16b, 0x3, 0x2, 
    0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x7, 0x4, 
    0x2, 0x2, 0x16f, 0x170, 0x5, 0xa, 0x6, 0x2, 0x170, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x171, 0x172, 0x7, 0x34, 0x2, 0x2, 0x172, 0x174, 0x5, 0x46, 0x24, 
    0x2, 0x173, 0x175, 0x5, 0x48, 0x25, 0x2, 0x174, 0x173, 0x3, 0x2, 0x2, 
    0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x176, 0x177, 0x7, 0x35, 0x2, 0x2, 0x177, 0x179, 0x5, 0x46, 0x24, 0x2, 
    0x178, 0x17a, 0x5, 0x48, 0x25, 0x2, 0x179, 0x178, 0x3, 0x2, 0x2, 0x2, 
    0x179, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 0x2, 0x2, 
    0x17b, 0x17c, 0x7, 0xe, 0x2, 0x2, 0x17c, 0x17d, 0x5, 0x20, 0x11, 0x2, 
    0x17d, 0x45, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x7, 0x36, 0x2, 0x2, 
    0x17f, 0x47, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 0x7, 0x5, 0x2, 0x2, 0x181, 
    0x182, 0x5, 0x4a, 0x26, 0x2, 0x182, 0x183, 0x7, 0x7, 0x2, 0x2, 0x183, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x184, 0x189, 0x5, 0x4c, 0x27, 0x2, 0x185, 
    0x186, 0x7, 0x4, 0x2, 0x2, 0x186, 0x188, 0x5, 0x4c, 0x27, 0x2, 0x187, 
    0x185, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x189, 
    0x187, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18a, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x189, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18e, 
    0x7, 0x1d, 0x2, 0x2, 0x18d, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 
    0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 
    0x5, 0x4e, 0x28, 0x2, 0x190, 0x191, 0x7, 0xe, 0x2, 0x2, 0x191, 0x192, 
    0x5, 0x20, 0x11, 0x2, 0x192, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x193, 0x198, 
    0x5, 0x50, 0x29, 0x2, 0x194, 0x195, 0x7, 0x6, 0x2, 0x2, 0x195, 0x197, 
    0x5, 0x50, 0x29, 0x2, 0x196, 0x194, 0x3, 0x2, 0x2, 0x2, 0x197, 0x19a, 
    0x3, 0x2, 0x2, 0x2, 0x198, 0x196, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 
    0x3, 0x2, 0x2, 0x2, 0x199, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x198, 0x3, 
    0x2, 0x2, 0x2, 0x19b, 0x19c, 0x7, 0x36, 0x2, 0x2, 0x19c, 0x51, 0x3, 
    0x2, 0x2, 0x2, 0x19d, 0x1ab, 0x5, 0x54, 0x2b, 0x2, 0x19e, 0x1ab, 0x5, 
    0x5a, 0x2e, 0x2, 0x19f, 0x1ab, 0x5, 0x60, 0x31, 0x2, 0x1a0, 0x1ab, 0x5, 
    0x66, 0x34, 0x2, 0x1a1, 0x1ab, 0x5, 0x70, 0x39, 0x2, 0x1a2, 0x1ab, 0x5, 
    0x72, 0x3a, 0x2, 0x1a3, 0x1ab, 0x5, 0x74, 0x3b, 0x2, 0x1a4, 0x1ab, 0x5, 
    0x7e, 0x40, 0x2, 0x1a5, 0x1ab, 0x5, 0x80, 0x41, 0x2, 0x1a6, 0x1ab, 0x5, 
    0x8a, 0x46, 0x2, 0x1a7, 0x1ab, 0x5, 0x8c, 0x47, 0x2, 0x1a8, 0x1ab, 0x5, 
    0x76, 0x3c, 0x2, 0x1a9, 0x1ab, 0x5, 0x56, 0x2c, 0x2, 0x1aa, 0x19d, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x19f, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a1, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a3, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a5, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a7, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a9, 0x3, 
    0x2, 0x2, 0x2, 0x1ab, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x7, 0x1e, 
    0x2, 0x2, 0x1ad, 0x1ae, 0x5, 0x58, 0x2d, 0x2, 0x1ae, 0x1af, 0x7, 0x1f, 
    0x2, 0x2, 0x1af, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b7, 0x5, 0x52, 0x2a, 
    0x2, 0x1b3, 0x1b4, 0x7, 0x4, 0x2, 0x2, 0x1b4, 0x1b6, 0x5, 0x52, 0x2a, 
    0x2, 0x1b5, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b9, 0x3, 0x2, 0x2, 
    0x2, 0x1b7, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x3, 0x2, 0x2, 
    0x2, 0x1b8, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1b7, 0x3, 0x2, 0x2, 0x2, 
    0x1ba, 0x1bb, 0x5, 0x5c, 0x2f, 0x2, 0x1bb, 0x1bc, 0x7, 0xf, 0x2, 0x2, 
    0x1bc, 0x1bd, 0x5, 0x5e, 0x30, 0x2, 0x1bd, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x1be, 0x1bf, 0x5, 0x98, 0x4d, 0x2, 0x1bf, 0x5d, 0x3, 0x2, 0x2, 0x2, 
    0x1c0, 0x1c1, 0x5, 0x90, 0x49, 0x2, 0x1c1, 0x5f, 0x3, 0x2, 0x2, 0x2, 
    0x1c2, 0x1c3, 0x7, 0x25, 0x2, 0x2, 0x1c3, 0x1c4, 0x5, 0x90, 0x49, 0x2, 
    0x1c4, 0x1c5, 0x7, 0x26, 0x2, 0x2, 0x1c5, 0x1c8, 0x5, 0x62, 0x32, 0x2, 
    0x1c6, 0x1c7, 0x7, 0x27, 0x2, 0x2, 0x1c7, 0x1c9, 0x5, 0x64, 0x33, 0x2, 
    0x1c8, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0x3, 0x2, 0x2, 0x2, 
    0x1c9, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cb, 0x5, 0x52, 0x2a, 0x2, 
    0x1cb, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x5, 0x52, 0x2a, 0x2, 
    0x1cd, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cf, 0x7, 0x28, 0x2, 0x2, 
    0x1cf, 0x1d0, 0x5, 0x90, 0x49, 0x2, 0x1d0, 0x1d1, 0x7, 0x1b, 0x2, 0x2, 
    0x1d1, 0x1d2, 0x5, 0x68, 0x35, 0x2, 0x1d2, 0x1d3, 0x7, 0x1f, 0x2, 0x2, 
    0x1d3, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d9, 0x5, 0x6a, 0x36, 0x2, 
    0x1d5, 0x1d6, 0x7, 0x4, 0x2, 0x2, 0x1d6, 0x1d8, 0x5, 0x6a, 0x36, 0x2, 
    0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1db, 0x3, 0x2, 0x2, 0x2, 
    0x1d9, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1da, 0x3, 0x2, 0x2, 0x2, 
    0x1da, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1dc, 
    0x1dd, 0x5, 0x6c, 0x37, 0x2, 0x1dd, 0x1de, 0x7, 0xe, 0x2, 0x2, 0x1de, 
    0x1df, 0x5, 0x52, 0x2a, 0x2, 0x1df, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e0, 
    0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1e1, 
    0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e8, 
    0x5, 0x6e, 0x38, 0x2, 0x1e4, 0x1e5, 0x7, 0x6, 0x2, 0x2, 0x1e5, 0x1e7, 
    0x5, 0x6e, 0x38, 0x2, 0x1e6, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1ea, 
    0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 
    0x3, 0x2, 0x2, 0x2, 0x1e9, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1e8, 0x3, 
    0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0x5, 0x16, 0xc, 0x2, 0x1ec, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x1ed, 0x1ee, 0x7, 0x29, 0x2, 0x2, 0x1ee, 0x1ef, 0x5, 
    0x58, 0x2d, 0x2, 0x1ef, 0x1f0, 0x7, 0x2a, 0x2, 0x2, 0x1f0, 0x1f1, 0x5, 
    0x90, 0x49, 0x2, 0x1f1, 0x71, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f3, 0x7, 
    0x2b, 0x2, 0x2, 0x1f3, 0x1f4, 0x5, 0x90, 0x49, 0x2, 0x1f4, 0x1f5, 0x7, 
    0x2c, 0x2, 0x2, 0x1f5, 0x1f6, 0x5, 0x52, 0x2a, 0x2, 0x1f6, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x1f7, 0x1f8, 0x7, 0x2d, 0x2, 0x2, 0x1f8, 0x1f9, 0x5, 
    0x98, 0x4d, 0x2, 0x1f9, 0x1fa, 0x7, 0xf, 0x2, 0x2, 0x1fa, 0x1fb, 0x5, 
    0x90, 0x49, 0x2, 0x1fb, 0x1fc, 0x9, 0x3, 0x2, 0x2, 0x1fc, 0x1fd, 0x5, 
    0x90, 0x49, 0x2, 0x1fd, 0x1fe, 0x7, 0x2c, 0x2, 0x2, 0x1fe, 0x1ff, 0x5, 
    0x52, 0x2a, 0x2, 0x1ff, 0x75, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x5, 
    0x78, 0x3d, 0x2, 0x201, 0x203, 0x7, 0x5, 0x2, 0x2, 0x202, 0x204, 0x5, 
    0x7a, 0x3e, 0x2, 0x203, 0x202, 0x3, 0x2, 0x2, 0x2, 0x203, 0x204, 0x3, 
    0x2, 0x2, 0x2, 0x204, 0x205, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x7, 
    0x7, 0x2, 0x2, 0x206, 0x77, 0x3, 0x2, 0x2, 0x2, 0x207, 0x208, 0x7, 0x36, 
    0x2, 0x2, 0x208, 0x79, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20e, 0x5, 0x7c, 
    0x3f, 0x2, 0x20a, 0x20b, 0x7, 0x6, 0x2, 0x2, 0x20b, 0x20d, 0x5, 0x7c, 
    0x3f, 0x2, 0x20c, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x210, 0x3, 0x2, 
    0x2, 0x2, 0x20e, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20f, 0x3, 0x2, 
    0x2, 0x2, 0x20f, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20e, 0x3, 0x2, 0x2, 
    0x2, 0x211, 0x212, 0x5, 0x90, 0x49, 0x2, 0x212, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x213, 0x214, 0x7, 0x30, 0x2, 0x2, 0x214, 0x215, 0x5, 0x82, 0x42, 
    0x2, 0x215, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x216, 0x218, 0x7, 0x31, 0x2, 
    0x2, 0x217, 0x219, 0x5, 0x82, 0x42, 0x2, 0x218, 0x217, 0x3, 0x2, 0x2, 
    0x2, 0x218, 0x219, 0x3, 0x2, 0x2, 0x2, 0x219, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x21a, 0x21b, 0x7, 0x5, 0x2, 0x2, 0x21b, 0x220, 0x5, 0x84, 0x43, 0x2, 
    0x21c, 0x21d, 0x7, 0x6, 0x2, 0x2, 0x21d, 0x21f, 0x5, 0x84, 0x43, 0x2, 
    0x21e, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x222, 0x3, 0x2, 0x2, 0x2, 
    0x220, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0x3, 0x2, 0x2, 0x2, 
    0x221, 0x223, 0x3, 0x2, 0x2, 0x2, 0x222, 0x220, 0x3, 0x2, 0x2, 0x2, 
    0x223, 0x224, 0x7, 0x7, 0x2, 0x2, 0x224, 0x83, 0x3, 0x2, 0x2, 0x2, 0x225, 
    0x228, 0x5, 0x90, 0x49, 0x2, 0x226, 0x227, 0x7, 0xe, 0x2, 0x2, 0x227, 
    0x229, 0x5, 0x86, 0x44, 0x2, 0x228, 0x226, 0x3, 0x2, 0x2, 0x2, 0x228, 
    0x229, 0x3, 0x2, 0x2, 0x2, 0x229, 0x85, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22c, 
    0x5, 0x18, 0xd, 0x2, 0x22b, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22c, 
    0x3, 0x2, 0x2, 0x2, 0x22c, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x230, 
    0x5, 0xaa, 0x56, 0x2, 0x22e, 0x22f, 0x7, 0xe, 0x2, 0x2, 0x22f, 0x231, 
    0x5, 0x88, 0x45, 0x2, 0x230, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x230, 0x231, 
    0x3, 0x2, 0x2, 0x2, 0x231, 0x87, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 0x5, 
    0xaa, 0x56, 0x2, 0x233, 0x89, 0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x7, 
    0x32, 0x2, 0x2, 0x235, 0x236, 0x5, 0x8e, 0x48, 0x2, 0x236, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x237, 0x238, 0x7, 0x33, 0x2, 0x2, 0x238, 0x239, 0x5, 
    0x8e, 0x48, 0x2, 0x239, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 0x7, 
    0x5, 0x2, 0x2, 0x23b, 0x240, 0x5, 0x98, 0x4d, 0x2, 0x23c, 0x23d, 0x7, 
    0x6, 0x2, 0x2, 0x23d, 0x23f, 0x5, 0x98, 0x4d, 0x2, 0x23e, 0x23c, 0x3, 
    0x2, 0x2, 0x2, 0x23f, 0x242, 0x3, 0x2, 0x2, 0x2, 0x240, 0x23e, 0x3, 
    0x2, 0x2, 0x2, 0x240, 0x241, 0x3, 0x2, 0x2, 0x2, 0x241, 0x243, 0x3, 
    0x2, 0x2, 0x2, 0x242, 0x240, 0x3, 0x2, 0x2, 0x2, 0x243, 0x244, 0x7, 
    0x7, 0x2, 0x2, 0x244, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x245, 0x249, 0x5, 0x92, 
    0x4a, 0x2, 0x246, 0x247, 0x5, 0xb2, 0x5a, 0x2, 0x247, 0x248, 0x5, 0x92, 
    0x4a, 0x2, 0x248, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x249, 0x246, 0x3, 0x2, 
    0x2, 0x2, 0x249, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x24b, 0x24d, 0x5, 0x18, 0xd, 0x2, 0x24c, 0x24b, 0x3, 0x2, 0x2, 
    0x2, 0x24c, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 0x3, 0x2, 0x2, 
    0x2, 0x24e, 0x254, 0x5, 0x94, 0x4b, 0x2, 0x24f, 0x250, 0x5, 0xb4, 0x5b, 
    0x2, 0x250, 0x251, 0x5, 0x94, 0x4b, 0x2, 0x251, 0x253, 0x3, 0x2, 0x2, 
    0x2, 0x252, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x253, 0x256, 0x3, 0x2, 0x2, 
    0x2, 0x254, 0x252, 0x3, 0x2, 0x2, 0x2, 0x254, 0x255, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x93, 0x3, 0x2, 0x2, 0x2, 0x256, 0x254, 0x3, 0x2, 0x2, 0x2, 
    0x257, 0x25d, 0x5, 0x96, 0x4c, 0x2, 0x258, 0x259, 0x5, 0xb6, 0x5c, 0x2, 
    0x259, 0x25a, 0x5, 0x96, 0x4c, 0x2, 0x25a, 0x25c, 0x3, 0x2, 0x2, 0x2, 
    0x25b, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25f, 0x3, 0x2, 0x2, 0x2, 
    0x25d, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25e, 0x3, 0x2, 0x2, 0x2, 
    0x25e, 0x95, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x260, 
    0x26c, 0x5, 0x98, 0x4d, 0x2, 0x261, 0x26c, 0x5, 0xa6, 0x54, 0x2, 0x262, 
    0x26c, 0x5, 0xae, 0x58, 0x2, 0x263, 0x26c, 0x5, 0xb0, 0x59, 0x2, 0x264, 
    0x26c, 0x5, 0xa2, 0x52, 0x2, 0x265, 0x266, 0x7, 0x24, 0x2, 0x2, 0x266, 
    0x26c, 0x5, 0x96, 0x4c, 0x2, 0x267, 0x268, 0x7, 0x5, 0x2, 0x2, 0x268, 
    0x269, 0x5, 0x90, 0x49, 0x2, 0x269, 0x26a, 0x7, 0x7, 0x2, 0x2, 0x26a, 
    0x26c, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x260, 0x3, 0x2, 0x2, 0x2, 0x26b, 
    0x261, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x262, 0x3, 0x2, 0x2, 0x2, 0x26b, 
    0x263, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x264, 0x3, 0x2, 0x2, 0x2, 0x26b, 
    0x265, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x267, 0x3, 0x2, 0x2, 0x2, 0x26c, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x271, 0x5, 0x3c, 0x1f, 0x2, 0x26e, 
    0x270, 0x5, 0x9a, 0x4e, 0x2, 0x26f, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x270, 
    0x273, 0x3, 0x2, 0x2, 0x2, 0x271, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x271, 
    0x272, 0x3, 0x2, 0x2, 0x2, 0x272, 0x99, 0x3, 0x2, 0x2, 0x2, 0x273, 0x271, 
    0x3, 0x2, 0x2, 0x2, 0x274, 0x275, 0x7, 0xc, 0x2, 0x2, 0x275, 0x276, 
    0x5, 0x9c, 0x4f, 0x2, 0x276, 0x277, 0x7, 0xd, 0x2, 0x2, 0x277, 0x27b, 
    0x3, 0x2, 0x2, 0x2, 0x278, 0x279, 0x7, 0x3, 0x2, 0x2, 0x279, 0x27b, 
    0x5, 0xa0, 0x51, 0x2, 0x27a, 0x274, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x278, 
    0x3, 0x2, 0x2, 0x2, 0x27b, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x281, 0x5, 
    0x9e, 0x50, 0x2, 0x27d, 0x27e, 0x7, 0x6, 0x2, 0x2, 0x27e, 0x280, 0x5, 
    0x9e, 0x50, 0x2, 0x27f, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x280, 0x283, 0x3, 
    0x2, 0x2, 0x2, 0x281, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x281, 0x282, 0x3, 
    0x2, 0x2, 0x2, 0x282, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x283, 0x281, 0x3, 0x2, 
    0x2, 0x2, 0x284, 0x285, 0x5, 0x90, 0x49, 0x2, 0x285, 0x9f, 0x3, 0x2, 
    0x2, 0x2, 0x286, 0x287, 0x7, 0x36, 0x2, 0x2, 0x287, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0x288, 0x289, 0x5, 0xa4, 0x53, 0x2, 0x289, 0x28b, 0x7, 0x5, 
    0x2, 0x2, 0x28a, 0x28c, 0x5, 0x7a, 0x3e, 0x2, 0x28b, 0x28a, 0x3, 0x2, 
    0x2, 0x2, 0x28b, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28d, 0x3, 0x2, 
    0x2, 0x2, 0x28d, 0x28e, 0x7, 0x7, 0x2, 0x2, 0x28e, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0x28f, 0x290, 0x7, 0x36, 0x2, 0x2, 0x290, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0x291, 0x293, 0x5, 0x18, 0xd, 0x2, 0x292, 0x291, 0x3, 0x2, 0x2, 
    0x2, 0x292, 0x293, 0x3, 0x2, 0x2, 0x2, 0x293, 0x294, 0x3, 0x2, 0x2, 
    0x2, 0x294, 0x295, 0x5, 0xa8, 0x55, 0x2, 0x295, 0xa7, 0x3, 0x2, 0x2, 
    0x2, 0x296, 0x299, 0x5, 0xaa, 0x56, 0x2, 0x297, 0x299, 0x5, 0xac, 0x57, 
    0x2, 0x298, 0x296, 0x3, 0x2, 0x2, 0x2, 0x298, 0x297, 0x3, 0x2, 0x2, 
    0x2, 0x299, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x29b, 0x7, 0x37, 0x2, 
    0x2, 0x29b, 0xab, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 0x7, 0x38, 0x2, 
    0x2, 0x29d, 0xad, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x29f, 0x7, 0x3c, 0x2, 
    0x2, 0x29f, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x2a1, 0x7, 0x3d, 0x2, 
    0x2, 0x2a1, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a3, 0x9, 0x4, 0x2, 0x2, 
    0x2a3, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x9, 0x5, 0x2, 0x2, 0x2a5, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a7, 0x9, 0x6, 0x2, 0x2, 0x2a7, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0xbf, 0xc9, 0xd6, 0xdb, 0xe0, 0xe5, 0xef, 
    0xf9, 0xfd, 0x101, 0x10d, 0x119, 0x11e, 0x126, 0x13d, 0x143, 0x151, 
    0x15d, 0x167, 0x16c, 0x174, 0x179, 0x189, 0x18d, 0x198, 0x1aa, 0x1b7, 
    0x1c8, 0x1d9, 0x1e1, 0x1e8, 0x203, 0x20e, 0x218, 0x220, 0x228, 0x22b, 
    0x230, 0x240, 0x249, 0x24c, 0x254, 0x25d, 0x26b, 0x271, 0x27a, 0x281, 
    0x28b, 0x292, 0x298, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

PascalParser::Initializer PascalParser::_init;
