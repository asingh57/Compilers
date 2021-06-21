
// Generated from Tiger.g4 by ANTLR 4.9.1


#include "TigerListener.h"

#include "TigerParser.h"


using namespace antlrcpp;
using namespace antlr4;

TigerParser::TigerParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

TigerParser::~TigerParser() {
  delete _interpreter;
}

std::string TigerParser::getGrammarFileName() const {
  return "Tiger.g4";
}

const std::vector<std::string>& TigerParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& TigerParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Tiger_programContext ------------------------------------------------------------------

TigerParser::Tiger_programContext::Tiger_programContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Tiger_programContext::PROGRAM() {
  return getToken(TigerParser::PROGRAM, 0);
}

tree::TerminalNode* TigerParser::Tiger_programContext::ID() {
  return getToken(TigerParser::ID, 0);
}

tree::TerminalNode* TigerParser::Tiger_programContext::LET() {
  return getToken(TigerParser::LET, 0);
}

TigerParser::Declaration_segmentContext* TigerParser::Tiger_programContext::declaration_segment() {
  return getRuleContext<TigerParser::Declaration_segmentContext>(0);
}

tree::TerminalNode* TigerParser::Tiger_programContext::BEGIN() {
  return getToken(TigerParser::BEGIN, 0);
}

TigerParser::Funct_listContext* TigerParser::Tiger_programContext::funct_list() {
  return getRuleContext<TigerParser::Funct_listContext>(0);
}

tree::TerminalNode* TigerParser::Tiger_programContext::END() {
  return getToken(TigerParser::END, 0);
}


size_t TigerParser::Tiger_programContext::getRuleIndex() const {
  return TigerParser::RuleTiger_program;
}

void TigerParser::Tiger_programContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTiger_program(this);
}

void TigerParser::Tiger_programContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTiger_program(this);
}

TigerParser::Tiger_programContext* TigerParser::tiger_program() {
  Tiger_programContext *_localctx = _tracker.createInstance<Tiger_programContext>(_ctx, getState());
  enterRule(_localctx, 0, TigerParser::RuleTiger_program);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(TigerParser::PROGRAM);
    setState(109);
    match(TigerParser::ID);
    setState(110);
    match(TigerParser::LET);
    setState(111);
    declaration_segment();
    setState(112);
    match(TigerParser::BEGIN);
    setState(113);
    funct_list();
    setState(114);
    match(TigerParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_segmentContext ------------------------------------------------------------------

TigerParser::Declaration_segmentContext::Declaration_segmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Type_declaration_listContext* TigerParser::Declaration_segmentContext::type_declaration_list() {
  return getRuleContext<TigerParser::Type_declaration_listContext>(0);
}

TigerParser::Var_declaration_listContext* TigerParser::Declaration_segmentContext::var_declaration_list() {
  return getRuleContext<TigerParser::Var_declaration_listContext>(0);
}


size_t TigerParser::Declaration_segmentContext::getRuleIndex() const {
  return TigerParser::RuleDeclaration_segment;
}

void TigerParser::Declaration_segmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_segment(this);
}

void TigerParser::Declaration_segmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_segment(this);
}

TigerParser::Declaration_segmentContext* TigerParser::declaration_segment() {
  Declaration_segmentContext *_localctx = _tracker.createInstance<Declaration_segmentContext>(_ctx, getState());
  enterRule(_localctx, 2, TigerParser::RuleDeclaration_segment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    type_declaration_list();
    setState(117);
    var_declaration_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_declaration_listContext ------------------------------------------------------------------

TigerParser::Type_declaration_listContext::Type_declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Type_declarationContext* TigerParser::Type_declaration_listContext::type_declaration() {
  return getRuleContext<TigerParser::Type_declarationContext>(0);
}

TigerParser::Type_declaration_listContext* TigerParser::Type_declaration_listContext::type_declaration_list() {
  return getRuleContext<TigerParser::Type_declaration_listContext>(0);
}


size_t TigerParser::Type_declaration_listContext::getRuleIndex() const {
  return TigerParser::RuleType_declaration_list;
}

void TigerParser::Type_declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_declaration_list(this);
}

void TigerParser::Type_declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_declaration_list(this);
}

TigerParser::Type_declaration_listContext* TigerParser::type_declaration_list() {
  Type_declaration_listContext *_localctx = _tracker.createInstance<Type_declaration_listContext>(_ctx, getState());
  enterRule(_localctx, 4, TigerParser::RuleType_declaration_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(123);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(119);
        type_declaration();
        setState(120);
        type_declaration_list();
        break;
      }

      case TigerParser::BEGIN:
      case TigerParser::STATIC:
      case TigerParser::VAR: {
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

//----------------- Var_declaration_listContext ------------------------------------------------------------------

TigerParser::Var_declaration_listContext::Var_declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Var_declarationContext* TigerParser::Var_declaration_listContext::var_declaration() {
  return getRuleContext<TigerParser::Var_declarationContext>(0);
}

TigerParser::Var_declaration_listContext* TigerParser::Var_declaration_listContext::var_declaration_list() {
  return getRuleContext<TigerParser::Var_declaration_listContext>(0);
}


size_t TigerParser::Var_declaration_listContext::getRuleIndex() const {
  return TigerParser::RuleVar_declaration_list;
}

void TigerParser::Var_declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration_list(this);
}

void TigerParser::Var_declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration_list(this);
}

TigerParser::Var_declaration_listContext* TigerParser::var_declaration_list() {
  Var_declaration_listContext *_localctx = _tracker.createInstance<Var_declaration_listContext>(_ctx, getState());
  enterRule(_localctx, 6, TigerParser::RuleVar_declaration_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(129);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::STATIC:
      case TigerParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(125);
        var_declaration();
        setState(126);
        var_declaration_list();
        break;
      }

      case TigerParser::BEGIN: {
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

//----------------- Funct_listContext ------------------------------------------------------------------

TigerParser::Funct_listContext::Funct_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::FunctContext* TigerParser::Funct_listContext::funct() {
  return getRuleContext<TigerParser::FunctContext>(0);
}

TigerParser::Funct_listContext* TigerParser::Funct_listContext::funct_list() {
  return getRuleContext<TigerParser::Funct_listContext>(0);
}


size_t TigerParser::Funct_listContext::getRuleIndex() const {
  return TigerParser::RuleFunct_list;
}

void TigerParser::Funct_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunct_list(this);
}

void TigerParser::Funct_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunct_list(this);
}

TigerParser::Funct_listContext* TigerParser::funct_list() {
  Funct_listContext *_localctx = _tracker.createInstance<Funct_listContext>(_ctx, getState());
  enterRule(_localctx, 8, TigerParser::RuleFunct_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(135);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::FUNCTION: {
        enterOuterAlt(_localctx, 1);
        setState(131);
        funct();
        setState(132);
        funct_list();
        break;
      }

      case TigerParser::END: {
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

//----------------- Type_declarationContext ------------------------------------------------------------------

TigerParser::Type_declarationContext::Type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Type_declarationContext::TYPE() {
  return getToken(TigerParser::TYPE, 0);
}

tree::TerminalNode* TigerParser::Type_declarationContext::ID() {
  return getToken(TigerParser::ID, 0);
}

tree::TerminalNode* TigerParser::Type_declarationContext::TASSIGN() {
  return getToken(TigerParser::TASSIGN, 0);
}

TigerParser::TypeContext* TigerParser::Type_declarationContext::type() {
  return getRuleContext<TigerParser::TypeContext>(0);
}

tree::TerminalNode* TigerParser::Type_declarationContext::SEMICOLON() {
  return getToken(TigerParser::SEMICOLON, 0);
}


size_t TigerParser::Type_declarationContext::getRuleIndex() const {
  return TigerParser::RuleType_declaration;
}

void TigerParser::Type_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_declaration(this);
}

void TigerParser::Type_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_declaration(this);
}

TigerParser::Type_declarationContext* TigerParser::type_declaration() {
  Type_declarationContext *_localctx = _tracker.createInstance<Type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 10, TigerParser::RuleType_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(TigerParser::TYPE);
    setState(138);
    match(TigerParser::ID);
    setState(139);
    match(TigerParser::TASSIGN);
    setState(140);
    type();
    setState(141);
    match(TigerParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

TigerParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Type_idContext* TigerParser::TypeContext::type_id() {
  return getRuleContext<TigerParser::Type_idContext>(0);
}

tree::TerminalNode* TigerParser::TypeContext::ARRAY() {
  return getToken(TigerParser::ARRAY, 0);
}

tree::TerminalNode* TigerParser::TypeContext::OPENBRACK() {
  return getToken(TigerParser::OPENBRACK, 0);
}

tree::TerminalNode* TigerParser::TypeContext::INTLIT() {
  return getToken(TigerParser::INTLIT, 0);
}

tree::TerminalNode* TigerParser::TypeContext::CLOSEBRACK() {
  return getToken(TigerParser::CLOSEBRACK, 0);
}

tree::TerminalNode* TigerParser::TypeContext::OF() {
  return getToken(TigerParser::OF, 0);
}

tree::TerminalNode* TigerParser::TypeContext::ID() {
  return getToken(TigerParser::ID, 0);
}


size_t TigerParser::TypeContext::getRuleIndex() const {
  return TigerParser::RuleType;
}

void TigerParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void TigerParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

TigerParser::TypeContext* TigerParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 12, TigerParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(151);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(143);
        type_id();
        break;
      }

      case TigerParser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(144);
        match(TigerParser::ARRAY);
        setState(145);
        match(TigerParser::OPENBRACK);
        setState(146);
        match(TigerParser::INTLIT);
        setState(147);
        match(TigerParser::CLOSEBRACK);
        setState(148);
        match(TigerParser::OF);
        setState(149);
        type_id();
        break;
      }

      case TigerParser::ID: {
        enterOuterAlt(_localctx, 3);
        setState(150);
        match(TigerParser::ID);
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

//----------------- Type_idContext ------------------------------------------------------------------

TigerParser::Type_idContext::Type_idContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Type_idContext::INT() {
  return getToken(TigerParser::INT, 0);
}


size_t TigerParser::Type_idContext::getRuleIndex() const {
  return TigerParser::RuleType_id;
}

void TigerParser::Type_idContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_id(this);
}

void TigerParser::Type_idContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_id(this);
}

TigerParser::Type_idContext* TigerParser::type_id() {
  Type_idContext *_localctx = _tracker.createInstance<Type_idContext>(_ctx, getState());
  enterRule(_localctx, 14, TigerParser::RuleType_id);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(TigerParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

TigerParser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Storage_classContext* TigerParser::Var_declarationContext::storage_class() {
  return getRuleContext<TigerParser::Storage_classContext>(0);
}

TigerParser::Id_listContext* TigerParser::Var_declarationContext::id_list() {
  return getRuleContext<TigerParser::Id_listContext>(0);
}

tree::TerminalNode* TigerParser::Var_declarationContext::COLON() {
  return getToken(TigerParser::COLON, 0);
}

TigerParser::TypeContext* TigerParser::Var_declarationContext::type() {
  return getRuleContext<TigerParser::TypeContext>(0);
}

TigerParser::Optional_initContext* TigerParser::Var_declarationContext::optional_init() {
  return getRuleContext<TigerParser::Optional_initContext>(0);
}

tree::TerminalNode* TigerParser::Var_declarationContext::SEMICOLON() {
  return getToken(TigerParser::SEMICOLON, 0);
}


size_t TigerParser::Var_declarationContext::getRuleIndex() const {
  return TigerParser::RuleVar_declaration;
}

void TigerParser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void TigerParser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}

TigerParser::Var_declarationContext* TigerParser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 16, TigerParser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    storage_class();
    setState(156);
    id_list();
    setState(157);
    match(TigerParser::COLON);
    setState(158);
    type();
    setState(159);
    optional_init();
    setState(160);
    match(TigerParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Storage_classContext ------------------------------------------------------------------

TigerParser::Storage_classContext::Storage_classContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Storage_classContext::VAR() {
  return getToken(TigerParser::VAR, 0);
}

tree::TerminalNode* TigerParser::Storage_classContext::STATIC() {
  return getToken(TigerParser::STATIC, 0);
}


size_t TigerParser::Storage_classContext::getRuleIndex() const {
  return TigerParser::RuleStorage_class;
}

void TigerParser::Storage_classContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStorage_class(this);
}

void TigerParser::Storage_classContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStorage_class(this);
}

TigerParser::Storage_classContext* TigerParser::storage_class() {
  Storage_classContext *_localctx = _tracker.createInstance<Storage_classContext>(_ctx, getState());
  enterRule(_localctx, 18, TigerParser::RuleStorage_class);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    _la = _input->LA(1);
    if (!(_la == TigerParser::STATIC

    || _la == TigerParser::VAR)) {
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

//----------------- Id_listContext ------------------------------------------------------------------

TigerParser::Id_listContext::Id_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Id_listContext::ID() {
  return getToken(TigerParser::ID, 0);
}

tree::TerminalNode* TigerParser::Id_listContext::COMMA() {
  return getToken(TigerParser::COMMA, 0);
}

TigerParser::Id_listContext* TigerParser::Id_listContext::id_list() {
  return getRuleContext<TigerParser::Id_listContext>(0);
}


size_t TigerParser::Id_listContext::getRuleIndex() const {
  return TigerParser::RuleId_list;
}

void TigerParser::Id_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId_list(this);
}

void TigerParser::Id_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId_list(this);
}

TigerParser::Id_listContext* TigerParser::id_list() {
  Id_listContext *_localctx = _tracker.createInstance<Id_listContext>(_ctx, getState());
  enterRule(_localctx, 20, TigerParser::RuleId_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(168);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(164);
      match(TigerParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(165);
      match(TigerParser::ID);
      setState(166);
      match(TigerParser::COMMA);
      setState(167);
      id_list();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Optional_initContext ------------------------------------------------------------------

TigerParser::Optional_initContext::Optional_initContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Optional_initContext::ASSIGN() {
  return getToken(TigerParser::ASSIGN, 0);
}

TigerParser::ConstantContext* TigerParser::Optional_initContext::constant() {
  return getRuleContext<TigerParser::ConstantContext>(0);
}


size_t TigerParser::Optional_initContext::getRuleIndex() const {
  return TigerParser::RuleOptional_init;
}

void TigerParser::Optional_initContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOptional_init(this);
}

void TigerParser::Optional_initContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOptional_init(this);
}

TigerParser::Optional_initContext* TigerParser::optional_init() {
  Optional_initContext *_localctx = _tracker.createInstance<Optional_initContext>(_ctx, getState());
  enterRule(_localctx, 22, TigerParser::RuleOptional_init);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(173);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::ASSIGN: {
        enterOuterAlt(_localctx, 1);
        setState(170);
        match(TigerParser::ASSIGN);
        setState(171);
        constant();
        break;
      }

      case TigerParser::SEMICOLON: {
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

//----------------- FunctContext ------------------------------------------------------------------

TigerParser::FunctContext::FunctContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::FunctContext::FUNCTION() {
  return getToken(TigerParser::FUNCTION, 0);
}

tree::TerminalNode* TigerParser::FunctContext::ID() {
  return getToken(TigerParser::ID, 0);
}

tree::TerminalNode* TigerParser::FunctContext::OPENPAREN() {
  return getToken(TigerParser::OPENPAREN, 0);
}

TigerParser::Param_listContext* TigerParser::FunctContext::param_list() {
  return getRuleContext<TigerParser::Param_listContext>(0);
}

tree::TerminalNode* TigerParser::FunctContext::CLOSEPAREN() {
  return getToken(TigerParser::CLOSEPAREN, 0);
}

TigerParser::Ret_typeContext* TigerParser::FunctContext::ret_type() {
  return getRuleContext<TigerParser::Ret_typeContext>(0);
}

tree::TerminalNode* TigerParser::FunctContext::BEGIN() {
  return getToken(TigerParser::BEGIN, 0);
}

TigerParser::Stat_seq_funcContext* TigerParser::FunctContext::stat_seq_func() {
  return getRuleContext<TigerParser::Stat_seq_funcContext>(0);
}

tree::TerminalNode* TigerParser::FunctContext::END() {
  return getToken(TigerParser::END, 0);
}


size_t TigerParser::FunctContext::getRuleIndex() const {
  return TigerParser::RuleFunct;
}

void TigerParser::FunctContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunct(this);
}

void TigerParser::FunctContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunct(this);
}

TigerParser::FunctContext* TigerParser::funct() {
  FunctContext *_localctx = _tracker.createInstance<FunctContext>(_ctx, getState());
  enterRule(_localctx, 24, TigerParser::RuleFunct);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(TigerParser::FUNCTION);
    setState(176);
    match(TigerParser::ID);
    setState(177);
    match(TigerParser::OPENPAREN);
    setState(178);
    param_list();
    setState(179);
    match(TigerParser::CLOSEPAREN);
    setState(180);
    ret_type();
    setState(181);
    match(TigerParser::BEGIN);
    setState(182);
    stat_seq_func();
    setState(183);
    match(TigerParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Param_listContext ------------------------------------------------------------------

TigerParser::Param_listContext::Param_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::ParamContext* TigerParser::Param_listContext::param() {
  return getRuleContext<TigerParser::ParamContext>(0);
}

TigerParser::Param_list_tailContext* TigerParser::Param_listContext::param_list_tail() {
  return getRuleContext<TigerParser::Param_list_tailContext>(0);
}


size_t TigerParser::Param_listContext::getRuleIndex() const {
  return TigerParser::RuleParam_list;
}

void TigerParser::Param_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam_list(this);
}

void TigerParser::Param_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam_list(this);
}

TigerParser::Param_listContext* TigerParser::param_list() {
  Param_listContext *_localctx = _tracker.createInstance<Param_listContext>(_ctx, getState());
  enterRule(_localctx, 26, TigerParser::RuleParam_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(185);
        param();
        setState(186);
        param_list_tail();
        break;
      }

      case TigerParser::CLOSEPAREN: {
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

//----------------- Param_list_tailContext ------------------------------------------------------------------

TigerParser::Param_list_tailContext::Param_list_tailContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Param_list_tailContext::COMMA() {
  return getToken(TigerParser::COMMA, 0);
}

TigerParser::ParamContext* TigerParser::Param_list_tailContext::param() {
  return getRuleContext<TigerParser::ParamContext>(0);
}

TigerParser::Param_list_tailContext* TigerParser::Param_list_tailContext::param_list_tail() {
  return getRuleContext<TigerParser::Param_list_tailContext>(0);
}


size_t TigerParser::Param_list_tailContext::getRuleIndex() const {
  return TigerParser::RuleParam_list_tail;
}

void TigerParser::Param_list_tailContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam_list_tail(this);
}

void TigerParser::Param_list_tailContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam_list_tail(this);
}

TigerParser::Param_list_tailContext* TigerParser::param_list_tail() {
  Param_list_tailContext *_localctx = _tracker.createInstance<Param_list_tailContext>(_ctx, getState());
  enterRule(_localctx, 28, TigerParser::RuleParam_list_tail);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(196);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(191);
        match(TigerParser::COMMA);
        setState(192);
        param();
        setState(193);
        param_list_tail();
        break;
      }

      case TigerParser::CLOSEPAREN: {
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

//----------------- Ret_typeContext ------------------------------------------------------------------

TigerParser::Ret_typeContext::Ret_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Ret_typeContext::COLON() {
  return getToken(TigerParser::COLON, 0);
}

TigerParser::TypeContext* TigerParser::Ret_typeContext::type() {
  return getRuleContext<TigerParser::TypeContext>(0);
}


size_t TigerParser::Ret_typeContext::getRuleIndex() const {
  return TigerParser::RuleRet_type;
}

void TigerParser::Ret_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRet_type(this);
}

void TigerParser::Ret_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRet_type(this);
}

TigerParser::Ret_typeContext* TigerParser::ret_type() {
  Ret_typeContext *_localctx = _tracker.createInstance<Ret_typeContext>(_ctx, getState());
  enterRule(_localctx, 30, TigerParser::RuleRet_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(201);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::COLON: {
        enterOuterAlt(_localctx, 1);
        setState(198);
        match(TigerParser::COLON);
        setState(199);
        type();
        break;
      }

      case TigerParser::BEGIN: {
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

//----------------- ParamContext ------------------------------------------------------------------

TigerParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::ParamContext::ID() {
  return getToken(TigerParser::ID, 0);
}

tree::TerminalNode* TigerParser::ParamContext::COLON() {
  return getToken(TigerParser::COLON, 0);
}

TigerParser::TypeContext* TigerParser::ParamContext::type() {
  return getRuleContext<TigerParser::TypeContext>(0);
}


size_t TigerParser::ParamContext::getRuleIndex() const {
  return TigerParser::RuleParam;
}

void TigerParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void TigerParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}

TigerParser::ParamContext* TigerParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 32, TigerParser::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    match(TigerParser::ID);
    setState(204);
    match(TigerParser::COLON);
    setState(205);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stat_seq_funcContext ------------------------------------------------------------------

TigerParser::Stat_seq_funcContext::Stat_seq_funcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Stat_seqContext* TigerParser::Stat_seq_funcContext::stat_seq() {
  return getRuleContext<TigerParser::Stat_seqContext>(0);
}


size_t TigerParser::Stat_seq_funcContext::getRuleIndex() const {
  return TigerParser::RuleStat_seq_func;
}

void TigerParser::Stat_seq_funcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat_seq_func(this);
}

void TigerParser::Stat_seq_funcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat_seq_func(this);
}

TigerParser::Stat_seq_funcContext* TigerParser::stat_seq_func() {
  Stat_seq_funcContext *_localctx = _tracker.createInstance<Stat_seq_funcContext>(_ctx, getState());
  enterRule(_localctx, 34, TigerParser::RuleStat_seq_func);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    stat_seq();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stat_seqContext ------------------------------------------------------------------

TigerParser::Stat_seqContext::Stat_seqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::StatContext* TigerParser::Stat_seqContext::stat() {
  return getRuleContext<TigerParser::StatContext>(0);
}

TigerParser::Stat_seqContext* TigerParser::Stat_seqContext::stat_seq() {
  return getRuleContext<TigerParser::Stat_seqContext>(0);
}


size_t TigerParser::Stat_seqContext::getRuleIndex() const {
  return TigerParser::RuleStat_seq;
}

void TigerParser::Stat_seqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat_seq(this);
}

void TigerParser::Stat_seqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat_seq(this);
}

TigerParser::Stat_seqContext* TigerParser::stat_seq() {
  Stat_seqContext *_localctx = _tracker.createInstance<Stat_seqContext>(_ctx, getState());
  enterRule(_localctx, 36, TigerParser::RuleStat_seq);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(213);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(209);
      stat();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(210);
      stat();
      setState(211);
      stat_seq();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

TigerParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Assignment_statContext* TigerParser::StatContext::assignment_stat() {
  return getRuleContext<TigerParser::Assignment_statContext>(0);
}

TigerParser::If_statContext* TigerParser::StatContext::if_stat() {
  return getRuleContext<TigerParser::If_statContext>(0);
}

TigerParser::If_else_statContext* TigerParser::StatContext::if_else_stat() {
  return getRuleContext<TigerParser::If_else_statContext>(0);
}

TigerParser::While_statContext* TigerParser::StatContext::while_stat() {
  return getRuleContext<TigerParser::While_statContext>(0);
}

TigerParser::For_statContext* TigerParser::StatContext::for_stat() {
  return getRuleContext<TigerParser::For_statContext>(0);
}

TigerParser::Fncall_statContext* TigerParser::StatContext::fncall_stat() {
  return getRuleContext<TigerParser::Fncall_statContext>(0);
}

TigerParser::Break_statContext* TigerParser::StatContext::break_stat() {
  return getRuleContext<TigerParser::Break_statContext>(0);
}

TigerParser::Return_statContext* TigerParser::StatContext::return_stat() {
  return getRuleContext<TigerParser::Return_statContext>(0);
}

TigerParser::Sub_scope_statContext* TigerParser::StatContext::sub_scope_stat() {
  return getRuleContext<TigerParser::Sub_scope_statContext>(0);
}


size_t TigerParser::StatContext::getRuleIndex() const {
  return TigerParser::RuleStat;
}

void TigerParser::StatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat(this);
}

void TigerParser::StatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat(this);
}

TigerParser::StatContext* TigerParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 38, TigerParser::RuleStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(224);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(215);
      assignment_stat();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(216);
      if_stat();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(217);
      if_else_stat();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(218);
      while_stat();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(219);
      for_stat();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(220);
      fncall_stat();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(221);
      break_stat();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(222);
      return_stat();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(223);
      sub_scope_stat();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignment_statContext ------------------------------------------------------------------

TigerParser::Assignment_statContext::Assignment_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::LvalueContext* TigerParser::Assignment_statContext::lvalue() {
  return getRuleContext<TigerParser::LvalueContext>(0);
}

TigerParser::L_tailContext* TigerParser::Assignment_statContext::l_tail() {
  return getRuleContext<TigerParser::L_tailContext>(0);
}

tree::TerminalNode* TigerParser::Assignment_statContext::ASSIGN() {
  return getToken(TigerParser::ASSIGN, 0);
}

TigerParser::ExprContext* TigerParser::Assignment_statContext::expr() {
  return getRuleContext<TigerParser::ExprContext>(0);
}

tree::TerminalNode* TigerParser::Assignment_statContext::SEMICOLON() {
  return getToken(TigerParser::SEMICOLON, 0);
}


size_t TigerParser::Assignment_statContext::getRuleIndex() const {
  return TigerParser::RuleAssignment_stat;
}

void TigerParser::Assignment_statContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_stat(this);
}

void TigerParser::Assignment_statContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_stat(this);
}

TigerParser::Assignment_statContext* TigerParser::assignment_stat() {
  Assignment_statContext *_localctx = _tracker.createInstance<Assignment_statContext>(_ctx, getState());
  enterRule(_localctx, 40, TigerParser::RuleAssignment_stat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    lvalue();
    setState(227);
    l_tail();
    setState(228);
    match(TigerParser::ASSIGN);
    setState(229);
    expr();
    setState(230);
    match(TigerParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statContext ------------------------------------------------------------------

TigerParser::If_statContext::If_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::If_statContext::IF() {
  return getToken(TigerParser::IF, 0);
}

TigerParser::ExprContext* TigerParser::If_statContext::expr() {
  return getRuleContext<TigerParser::ExprContext>(0);
}

tree::TerminalNode* TigerParser::If_statContext::THEN() {
  return getToken(TigerParser::THEN, 0);
}

TigerParser::Stat_seq_ifContext* TigerParser::If_statContext::stat_seq_if() {
  return getRuleContext<TigerParser::Stat_seq_ifContext>(0);
}

tree::TerminalNode* TigerParser::If_statContext::ENDIF() {
  return getToken(TigerParser::ENDIF, 0);
}

tree::TerminalNode* TigerParser::If_statContext::SEMICOLON() {
  return getToken(TigerParser::SEMICOLON, 0);
}


size_t TigerParser::If_statContext::getRuleIndex() const {
  return TigerParser::RuleIf_stat;
}

void TigerParser::If_statContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_stat(this);
}

void TigerParser::If_statContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_stat(this);
}

TigerParser::If_statContext* TigerParser::if_stat() {
  If_statContext *_localctx = _tracker.createInstance<If_statContext>(_ctx, getState());
  enterRule(_localctx, 42, TigerParser::RuleIf_stat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(TigerParser::IF);
    setState(233);
    expr();
    setState(234);
    match(TigerParser::THEN);
    setState(235);
    stat_seq_if();
    setState(236);
    match(TigerParser::ENDIF);
    setState(237);
    match(TigerParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_else_statContext ------------------------------------------------------------------

TigerParser::If_else_statContext::If_else_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::If_else_statContext::IF() {
  return getToken(TigerParser::IF, 0);
}

TigerParser::ExprContext* TigerParser::If_else_statContext::expr() {
  return getRuleContext<TigerParser::ExprContext>(0);
}

tree::TerminalNode* TigerParser::If_else_statContext::THEN() {
  return getToken(TigerParser::THEN, 0);
}

TigerParser::Stat_seq_ifContext* TigerParser::If_else_statContext::stat_seq_if() {
  return getRuleContext<TigerParser::Stat_seq_ifContext>(0);
}

tree::TerminalNode* TigerParser::If_else_statContext::ELSE() {
  return getToken(TigerParser::ELSE, 0);
}

TigerParser::Stat_seq_elseContext* TigerParser::If_else_statContext::stat_seq_else() {
  return getRuleContext<TigerParser::Stat_seq_elseContext>(0);
}

tree::TerminalNode* TigerParser::If_else_statContext::ENDIF() {
  return getToken(TigerParser::ENDIF, 0);
}

tree::TerminalNode* TigerParser::If_else_statContext::SEMICOLON() {
  return getToken(TigerParser::SEMICOLON, 0);
}


size_t TigerParser::If_else_statContext::getRuleIndex() const {
  return TigerParser::RuleIf_else_stat;
}

void TigerParser::If_else_statContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_else_stat(this);
}

void TigerParser::If_else_statContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_else_stat(this);
}

TigerParser::If_else_statContext* TigerParser::if_else_stat() {
  If_else_statContext *_localctx = _tracker.createInstance<If_else_statContext>(_ctx, getState());
  enterRule(_localctx, 44, TigerParser::RuleIf_else_stat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    match(TigerParser::IF);
    setState(240);
    expr();
    setState(241);
    match(TigerParser::THEN);
    setState(242);
    stat_seq_if();
    setState(243);
    match(TigerParser::ELSE);
    setState(244);
    stat_seq_else();
    setState(245);
    match(TigerParser::ENDIF);
    setState(246);
    match(TigerParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_statContext ------------------------------------------------------------------

TigerParser::While_statContext::While_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::While_statContext::WHILE() {
  return getToken(TigerParser::WHILE, 0);
}

TigerParser::ExprContext* TigerParser::While_statContext::expr() {
  return getRuleContext<TigerParser::ExprContext>(0);
}

tree::TerminalNode* TigerParser::While_statContext::DO() {
  return getToken(TigerParser::DO, 0);
}

TigerParser::Stat_seq_whileContext* TigerParser::While_statContext::stat_seq_while() {
  return getRuleContext<TigerParser::Stat_seq_whileContext>(0);
}

tree::TerminalNode* TigerParser::While_statContext::ENDDO() {
  return getToken(TigerParser::ENDDO, 0);
}

tree::TerminalNode* TigerParser::While_statContext::SEMICOLON() {
  return getToken(TigerParser::SEMICOLON, 0);
}


size_t TigerParser::While_statContext::getRuleIndex() const {
  return TigerParser::RuleWhile_stat;
}

void TigerParser::While_statContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_stat(this);
}

void TigerParser::While_statContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_stat(this);
}

TigerParser::While_statContext* TigerParser::while_stat() {
  While_statContext *_localctx = _tracker.createInstance<While_statContext>(_ctx, getState());
  enterRule(_localctx, 46, TigerParser::RuleWhile_stat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    match(TigerParser::WHILE);
    setState(249);
    expr();
    setState(250);
    match(TigerParser::DO);
    setState(251);
    stat_seq_while();
    setState(252);
    match(TigerParser::ENDDO);
    setState(253);
    match(TigerParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_statContext ------------------------------------------------------------------

TigerParser::For_statContext::For_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::For_statContext::FOR() {
  return getToken(TigerParser::FOR, 0);
}

tree::TerminalNode* TigerParser::For_statContext::ID() {
  return getToken(TigerParser::ID, 0);
}

tree::TerminalNode* TigerParser::For_statContext::ASSIGN() {
  return getToken(TigerParser::ASSIGN, 0);
}

std::vector<TigerParser::ExprContext *> TigerParser::For_statContext::expr() {
  return getRuleContexts<TigerParser::ExprContext>();
}

TigerParser::ExprContext* TigerParser::For_statContext::expr(size_t i) {
  return getRuleContext<TigerParser::ExprContext>(i);
}

tree::TerminalNode* TigerParser::For_statContext::TO() {
  return getToken(TigerParser::TO, 0);
}

tree::TerminalNode* TigerParser::For_statContext::DO() {
  return getToken(TigerParser::DO, 0);
}

TigerParser::Stat_seq_forContext* TigerParser::For_statContext::stat_seq_for() {
  return getRuleContext<TigerParser::Stat_seq_forContext>(0);
}

tree::TerminalNode* TigerParser::For_statContext::ENDDO() {
  return getToken(TigerParser::ENDDO, 0);
}

tree::TerminalNode* TigerParser::For_statContext::SEMICOLON() {
  return getToken(TigerParser::SEMICOLON, 0);
}


size_t TigerParser::For_statContext::getRuleIndex() const {
  return TigerParser::RuleFor_stat;
}

void TigerParser::For_statContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_stat(this);
}

void TigerParser::For_statContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_stat(this);
}

TigerParser::For_statContext* TigerParser::for_stat() {
  For_statContext *_localctx = _tracker.createInstance<For_statContext>(_ctx, getState());
  enterRule(_localctx, 48, TigerParser::RuleFor_stat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    match(TigerParser::FOR);
    setState(256);
    match(TigerParser::ID);
    setState(257);
    match(TigerParser::ASSIGN);
    setState(258);
    expr();
    setState(259);
    match(TigerParser::TO);
    setState(260);
    expr();
    setState(261);
    match(TigerParser::DO);
    setState(262);
    stat_seq_for();
    setState(263);
    match(TigerParser::ENDDO);
    setState(264);
    match(TigerParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fncall_statContext ------------------------------------------------------------------

TigerParser::Fncall_statContext::Fncall_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Opt_prefixContext* TigerParser::Fncall_statContext::opt_prefix() {
  return getRuleContext<TigerParser::Opt_prefixContext>(0);
}

tree::TerminalNode* TigerParser::Fncall_statContext::ID() {
  return getToken(TigerParser::ID, 0);
}

tree::TerminalNode* TigerParser::Fncall_statContext::OPENPAREN() {
  return getToken(TigerParser::OPENPAREN, 0);
}

TigerParser::Expr_listContext* TigerParser::Fncall_statContext::expr_list() {
  return getRuleContext<TigerParser::Expr_listContext>(0);
}

tree::TerminalNode* TigerParser::Fncall_statContext::CLOSEPAREN() {
  return getToken(TigerParser::CLOSEPAREN, 0);
}

tree::TerminalNode* TigerParser::Fncall_statContext::SEMICOLON() {
  return getToken(TigerParser::SEMICOLON, 0);
}


size_t TigerParser::Fncall_statContext::getRuleIndex() const {
  return TigerParser::RuleFncall_stat;
}

void TigerParser::Fncall_statContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFncall_stat(this);
}

void TigerParser::Fncall_statContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFncall_stat(this);
}

TigerParser::Fncall_statContext* TigerParser::fncall_stat() {
  Fncall_statContext *_localctx = _tracker.createInstance<Fncall_statContext>(_ctx, getState());
  enterRule(_localctx, 50, TigerParser::RuleFncall_stat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
    opt_prefix();
    setState(267);
    match(TigerParser::ID);
    setState(268);
    match(TigerParser::OPENPAREN);
    setState(269);
    expr_list();
    setState(270);
    match(TigerParser::CLOSEPAREN);
    setState(271);
    match(TigerParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Break_statContext ------------------------------------------------------------------

TigerParser::Break_statContext::Break_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Break_statContext::BREAK() {
  return getToken(TigerParser::BREAK, 0);
}

tree::TerminalNode* TigerParser::Break_statContext::SEMICOLON() {
  return getToken(TigerParser::SEMICOLON, 0);
}


size_t TigerParser::Break_statContext::getRuleIndex() const {
  return TigerParser::RuleBreak_stat;
}

void TigerParser::Break_statContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreak_stat(this);
}

void TigerParser::Break_statContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreak_stat(this);
}

TigerParser::Break_statContext* TigerParser::break_stat() {
  Break_statContext *_localctx = _tracker.createInstance<Break_statContext>(_ctx, getState());
  enterRule(_localctx, 52, TigerParser::RuleBreak_stat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    match(TigerParser::BREAK);
    setState(274);
    match(TigerParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statContext ------------------------------------------------------------------

TigerParser::Return_statContext::Return_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Return_statContext::RETURN() {
  return getToken(TigerParser::RETURN, 0);
}

TigerParser::Opt_returnContext* TigerParser::Return_statContext::opt_return() {
  return getRuleContext<TigerParser::Opt_returnContext>(0);
}

tree::TerminalNode* TigerParser::Return_statContext::SEMICOLON() {
  return getToken(TigerParser::SEMICOLON, 0);
}


size_t TigerParser::Return_statContext::getRuleIndex() const {
  return TigerParser::RuleReturn_stat;
}

void TigerParser::Return_statContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_stat(this);
}

void TigerParser::Return_statContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_stat(this);
}

TigerParser::Return_statContext* TigerParser::return_stat() {
  Return_statContext *_localctx = _tracker.createInstance<Return_statContext>(_ctx, getState());
  enterRule(_localctx, 54, TigerParser::RuleReturn_stat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(276);
    match(TigerParser::RETURN);
    setState(277);
    opt_return();
    setState(278);
    match(TigerParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sub_scope_statContext ------------------------------------------------------------------

TigerParser::Sub_scope_statContext::Sub_scope_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Sub_scope_statContext::LET() {
  return getToken(TigerParser::LET, 0);
}

TigerParser::Declaration_segmentContext* TigerParser::Sub_scope_statContext::declaration_segment() {
  return getRuleContext<TigerParser::Declaration_segmentContext>(0);
}

tree::TerminalNode* TigerParser::Sub_scope_statContext::BEGIN() {
  return getToken(TigerParser::BEGIN, 0);
}

TigerParser::Stat_seqContext* TigerParser::Sub_scope_statContext::stat_seq() {
  return getRuleContext<TigerParser::Stat_seqContext>(0);
}

tree::TerminalNode* TigerParser::Sub_scope_statContext::END() {
  return getToken(TigerParser::END, 0);
}


size_t TigerParser::Sub_scope_statContext::getRuleIndex() const {
  return TigerParser::RuleSub_scope_stat;
}

void TigerParser::Sub_scope_statContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSub_scope_stat(this);
}

void TigerParser::Sub_scope_statContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSub_scope_stat(this);
}

TigerParser::Sub_scope_statContext* TigerParser::sub_scope_stat() {
  Sub_scope_statContext *_localctx = _tracker.createInstance<Sub_scope_statContext>(_ctx, getState());
  enterRule(_localctx, 56, TigerParser::RuleSub_scope_stat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    match(TigerParser::LET);
    setState(281);
    declaration_segment();
    setState(282);
    match(TigerParser::BEGIN);
    setState(283);
    stat_seq();
    setState(284);
    match(TigerParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stat_seq_ifContext ------------------------------------------------------------------

TigerParser::Stat_seq_ifContext::Stat_seq_ifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Stat_seqContext* TigerParser::Stat_seq_ifContext::stat_seq() {
  return getRuleContext<TigerParser::Stat_seqContext>(0);
}


size_t TigerParser::Stat_seq_ifContext::getRuleIndex() const {
  return TigerParser::RuleStat_seq_if;
}

void TigerParser::Stat_seq_ifContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat_seq_if(this);
}

void TigerParser::Stat_seq_ifContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat_seq_if(this);
}

TigerParser::Stat_seq_ifContext* TigerParser::stat_seq_if() {
  Stat_seq_ifContext *_localctx = _tracker.createInstance<Stat_seq_ifContext>(_ctx, getState());
  enterRule(_localctx, 58, TigerParser::RuleStat_seq_if);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    stat_seq();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stat_seq_elseContext ------------------------------------------------------------------

TigerParser::Stat_seq_elseContext::Stat_seq_elseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Stat_seqContext* TigerParser::Stat_seq_elseContext::stat_seq() {
  return getRuleContext<TigerParser::Stat_seqContext>(0);
}


size_t TigerParser::Stat_seq_elseContext::getRuleIndex() const {
  return TigerParser::RuleStat_seq_else;
}

void TigerParser::Stat_seq_elseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat_seq_else(this);
}

void TigerParser::Stat_seq_elseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat_seq_else(this);
}

TigerParser::Stat_seq_elseContext* TigerParser::stat_seq_else() {
  Stat_seq_elseContext *_localctx = _tracker.createInstance<Stat_seq_elseContext>(_ctx, getState());
  enterRule(_localctx, 60, TigerParser::RuleStat_seq_else);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    stat_seq();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stat_seq_whileContext ------------------------------------------------------------------

TigerParser::Stat_seq_whileContext::Stat_seq_whileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Stat_seqContext* TigerParser::Stat_seq_whileContext::stat_seq() {
  return getRuleContext<TigerParser::Stat_seqContext>(0);
}


size_t TigerParser::Stat_seq_whileContext::getRuleIndex() const {
  return TigerParser::RuleStat_seq_while;
}

void TigerParser::Stat_seq_whileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat_seq_while(this);
}

void TigerParser::Stat_seq_whileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat_seq_while(this);
}

TigerParser::Stat_seq_whileContext* TigerParser::stat_seq_while() {
  Stat_seq_whileContext *_localctx = _tracker.createInstance<Stat_seq_whileContext>(_ctx, getState());
  enterRule(_localctx, 62, TigerParser::RuleStat_seq_while);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    stat_seq();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stat_seq_forContext ------------------------------------------------------------------

TigerParser::Stat_seq_forContext::Stat_seq_forContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Stat_seqContext* TigerParser::Stat_seq_forContext::stat_seq() {
  return getRuleContext<TigerParser::Stat_seqContext>(0);
}


size_t TigerParser::Stat_seq_forContext::getRuleIndex() const {
  return TigerParser::RuleStat_seq_for;
}

void TigerParser::Stat_seq_forContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat_seq_for(this);
}

void TigerParser::Stat_seq_forContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat_seq_for(this);
}

TigerParser::Stat_seq_forContext* TigerParser::stat_seq_for() {
  Stat_seq_forContext *_localctx = _tracker.createInstance<Stat_seq_forContext>(_ctx, getState());
  enterRule(_localctx, 64, TigerParser::RuleStat_seq_for);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    stat_seq();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Opt_returnContext ------------------------------------------------------------------

TigerParser::Opt_returnContext::Opt_returnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::ExprContext* TigerParser::Opt_returnContext::expr() {
  return getRuleContext<TigerParser::ExprContext>(0);
}


size_t TigerParser::Opt_returnContext::getRuleIndex() const {
  return TigerParser::RuleOpt_return;
}

void TigerParser::Opt_returnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpt_return(this);
}

void TigerParser::Opt_returnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpt_return(this);
}

TigerParser::Opt_returnContext* TigerParser::opt_return() {
  Opt_returnContext *_localctx = _tracker.createInstance<Opt_returnContext>(_ctx, getState());
  enterRule(_localctx, 66, TigerParser::RuleOpt_return);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(296);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::OPENPAREN:
      case TigerParser::ID:
      case TigerParser::INTLIT: {
        enterOuterAlt(_localctx, 1);
        setState(294);
        expr();
        break;
      }

      case TigerParser::SEMICOLON: {
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

//----------------- Opt_prefixContext ------------------------------------------------------------------

TigerParser::Opt_prefixContext::Opt_prefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::LvalueContext* TigerParser::Opt_prefixContext::lvalue() {
  return getRuleContext<TigerParser::LvalueContext>(0);
}

tree::TerminalNode* TigerParser::Opt_prefixContext::ASSIGN() {
  return getToken(TigerParser::ASSIGN, 0);
}


size_t TigerParser::Opt_prefixContext::getRuleIndex() const {
  return TigerParser::RuleOpt_prefix;
}

void TigerParser::Opt_prefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpt_prefix(this);
}

void TigerParser::Opt_prefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpt_prefix(this);
}

TigerParser::Opt_prefixContext* TigerParser::opt_prefix() {
  Opt_prefixContext *_localctx = _tracker.createInstance<Opt_prefixContext>(_ctx, getState());
  enterRule(_localctx, 68, TigerParser::RuleOpt_prefix);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(302);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(298);
      lvalue();
      setState(299);
      match(TigerParser::ASSIGN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- L_tailContext ------------------------------------------------------------------

TigerParser::L_tailContext::L_tailContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::L_tailContext::ASSIGN() {
  return getToken(TigerParser::ASSIGN, 0);
}

TigerParser::LvalueContext* TigerParser::L_tailContext::lvalue() {
  return getRuleContext<TigerParser::LvalueContext>(0);
}

TigerParser::L_tailContext* TigerParser::L_tailContext::l_tail() {
  return getRuleContext<TigerParser::L_tailContext>(0);
}


size_t TigerParser::L_tailContext::getRuleIndex() const {
  return TigerParser::RuleL_tail;
}

void TigerParser::L_tailContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterL_tail(this);
}

void TigerParser::L_tailContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitL_tail(this);
}

TigerParser::L_tailContext* TigerParser::l_tail() {
  L_tailContext *_localctx = _tracker.createInstance<L_tailContext>(_ctx, getState());
  enterRule(_localctx, 70, TigerParser::RuleL_tail);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(309);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(304);
      match(TigerParser::ASSIGN);
      setState(305);
      lvalue();
      setState(306);
      l_tail();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

TigerParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Expr_no_opContext* TigerParser::ExprContext::expr_no_op() {
  return getRuleContext<TigerParser::Expr_no_opContext>(0);
}

TigerParser::Unambiguous_exprContext* TigerParser::ExprContext::unambiguous_expr() {
  return getRuleContext<TigerParser::Unambiguous_exprContext>(0);
}


size_t TigerParser::ExprContext::getRuleIndex() const {
  return TigerParser::RuleExpr;
}

void TigerParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void TigerParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}

TigerParser::ExprContext* TigerParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 72, TigerParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(313);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(311);
      expr_no_op();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(312);
      unambiguous_expr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unambiguous_exprContext ------------------------------------------------------------------

TigerParser::Unambiguous_exprContext::Unambiguous_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Logical_op_exprContext* TigerParser::Unambiguous_exprContext::logical_op_expr() {
  return getRuleContext<TigerParser::Logical_op_exprContext>(0);
}


size_t TigerParser::Unambiguous_exprContext::getRuleIndex() const {
  return TigerParser::RuleUnambiguous_expr;
}

void TigerParser::Unambiguous_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnambiguous_expr(this);
}

void TigerParser::Unambiguous_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnambiguous_expr(this);
}

TigerParser::Unambiguous_exprContext* TigerParser::unambiguous_expr() {
  Unambiguous_exprContext *_localctx = _tracker.createInstance<Unambiguous_exprContext>(_ctx, getState());
  enterRule(_localctx, 74, TigerParser::RuleUnambiguous_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    logical_op_expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logical_op_exprContext ------------------------------------------------------------------

TigerParser::Logical_op_exprContext::Logical_op_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Compare_op_exprContext* TigerParser::Logical_op_exprContext::compare_op_expr() {
  return getRuleContext<TigerParser::Compare_op_exprContext>(0);
}

TigerParser::Logical_op_expr_extContext* TigerParser::Logical_op_exprContext::logical_op_expr_ext() {
  return getRuleContext<TigerParser::Logical_op_expr_extContext>(0);
}


size_t TigerParser::Logical_op_exprContext::getRuleIndex() const {
  return TigerParser::RuleLogical_op_expr;
}

void TigerParser::Logical_op_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_op_expr(this);
}

void TigerParser::Logical_op_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_op_expr(this);
}

TigerParser::Logical_op_exprContext* TigerParser::logical_op_expr() {
  Logical_op_exprContext *_localctx = _tracker.createInstance<Logical_op_exprContext>(_ctx, getState());
  enterRule(_localctx, 76, TigerParser::RuleLogical_op_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(317);
    compare_op_expr();
    setState(318);
    logical_op_expr_ext();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logical_op_expr_extContext ------------------------------------------------------------------

TigerParser::Logical_op_expr_extContext::Logical_op_expr_extContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Compare_op_exprContext* TigerParser::Logical_op_expr_extContext::compare_op_expr() {
  return getRuleContext<TigerParser::Compare_op_exprContext>(0);
}

TigerParser::Logical_op_expr_extContext* TigerParser::Logical_op_expr_extContext::logical_op_expr_ext() {
  return getRuleContext<TigerParser::Logical_op_expr_extContext>(0);
}

tree::TerminalNode* TigerParser::Logical_op_expr_extContext::AND() {
  return getToken(TigerParser::AND, 0);
}

tree::TerminalNode* TigerParser::Logical_op_expr_extContext::OR() {
  return getToken(TigerParser::OR, 0);
}


size_t TigerParser::Logical_op_expr_extContext::getRuleIndex() const {
  return TigerParser::RuleLogical_op_expr_ext;
}

void TigerParser::Logical_op_expr_extContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_op_expr_ext(this);
}

void TigerParser::Logical_op_expr_extContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_op_expr_ext(this);
}

TigerParser::Logical_op_expr_extContext* TigerParser::logical_op_expr_ext() {
  Logical_op_expr_extContext *_localctx = _tracker.createInstance<Logical_op_expr_extContext>(_ctx, getState());
  enterRule(_localctx, 78, TigerParser::RuleLogical_op_expr_ext);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(325);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::AND:
      case TigerParser::OR: {
        enterOuterAlt(_localctx, 1);
        setState(320);
        _la = _input->LA(1);
        if (!(_la == TigerParser::AND

        || _la == TigerParser::OR)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(321);
        compare_op_expr();
        setState(322);
        logical_op_expr_ext();
        break;
      }

      case TigerParser::DO:
      case TigerParser::THEN:
      case TigerParser::TO:
      case TigerParser::COMMA:
      case TigerParser::SEMICOLON:
      case TigerParser::CLOSEPAREN:
      case TigerParser::CLOSEBRACK: {
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

//----------------- Compare_op_exprContext ------------------------------------------------------------------

TigerParser::Compare_op_exprContext::Compare_op_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Add_op_exprContext* TigerParser::Compare_op_exprContext::add_op_expr() {
  return getRuleContext<TigerParser::Add_op_exprContext>(0);
}

TigerParser::Compare_op_expr_extContext* TigerParser::Compare_op_exprContext::compare_op_expr_ext() {
  return getRuleContext<TigerParser::Compare_op_expr_extContext>(0);
}


size_t TigerParser::Compare_op_exprContext::getRuleIndex() const {
  return TigerParser::RuleCompare_op_expr;
}

void TigerParser::Compare_op_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompare_op_expr(this);
}

void TigerParser::Compare_op_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompare_op_expr(this);
}

TigerParser::Compare_op_exprContext* TigerParser::compare_op_expr() {
  Compare_op_exprContext *_localctx = _tracker.createInstance<Compare_op_exprContext>(_ctx, getState());
  enterRule(_localctx, 80, TigerParser::RuleCompare_op_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    add_op_expr();
    setState(328);
    compare_op_expr_ext();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compare_op_expr_extContext ------------------------------------------------------------------

TigerParser::Compare_op_expr_extContext::Compare_op_expr_extContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Add_op_exprContext* TigerParser::Compare_op_expr_extContext::add_op_expr() {
  return getRuleContext<TigerParser::Add_op_exprContext>(0);
}

TigerParser::Compare_op_expr_extContext* TigerParser::Compare_op_expr_extContext::compare_op_expr_ext() {
  return getRuleContext<TigerParser::Compare_op_expr_extContext>(0);
}

tree::TerminalNode* TigerParser::Compare_op_expr_extContext::EQUAL() {
  return getToken(TigerParser::EQUAL, 0);
}

tree::TerminalNode* TigerParser::Compare_op_expr_extContext::NEQUAL() {
  return getToken(TigerParser::NEQUAL, 0);
}

tree::TerminalNode* TigerParser::Compare_op_expr_extContext::LESS() {
  return getToken(TigerParser::LESS, 0);
}

tree::TerminalNode* TigerParser::Compare_op_expr_extContext::GREAT() {
  return getToken(TigerParser::GREAT, 0);
}

tree::TerminalNode* TigerParser::Compare_op_expr_extContext::LESSEQ() {
  return getToken(TigerParser::LESSEQ, 0);
}

tree::TerminalNode* TigerParser::Compare_op_expr_extContext::GREATEQ() {
  return getToken(TigerParser::GREATEQ, 0);
}


size_t TigerParser::Compare_op_expr_extContext::getRuleIndex() const {
  return TigerParser::RuleCompare_op_expr_ext;
}

void TigerParser::Compare_op_expr_extContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompare_op_expr_ext(this);
}

void TigerParser::Compare_op_expr_extContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompare_op_expr_ext(this);
}

TigerParser::Compare_op_expr_extContext* TigerParser::compare_op_expr_ext() {
  Compare_op_expr_extContext *_localctx = _tracker.createInstance<Compare_op_expr_extContext>(_ctx, getState());
  enterRule(_localctx, 82, TigerParser::RuleCompare_op_expr_ext);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(335);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::EQUAL:
      case TigerParser::NEQUAL:
      case TigerParser::LESS:
      case TigerParser::GREAT:
      case TigerParser::LESSEQ:
      case TigerParser::GREATEQ: {
        enterOuterAlt(_localctx, 1);
        setState(330);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << TigerParser::EQUAL)
          | (1ULL << TigerParser::NEQUAL)
          | (1ULL << TigerParser::LESS)
          | (1ULL << TigerParser::GREAT)
          | (1ULL << TigerParser::LESSEQ)
          | (1ULL << TigerParser::GREATEQ))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(331);
        add_op_expr();
        setState(332);
        compare_op_expr_ext();
        break;
      }

      case TigerParser::DO:
      case TigerParser::THEN:
      case TigerParser::TO:
      case TigerParser::COMMA:
      case TigerParser::SEMICOLON:
      case TigerParser::CLOSEPAREN:
      case TigerParser::CLOSEBRACK:
      case TigerParser::AND:
      case TigerParser::OR: {
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

//----------------- Add_op_exprContext ------------------------------------------------------------------

TigerParser::Add_op_exprContext::Add_op_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Mult_op_exprContext* TigerParser::Add_op_exprContext::mult_op_expr() {
  return getRuleContext<TigerParser::Mult_op_exprContext>(0);
}

TigerParser::Add_op_expr_extContext* TigerParser::Add_op_exprContext::add_op_expr_ext() {
  return getRuleContext<TigerParser::Add_op_expr_extContext>(0);
}


size_t TigerParser::Add_op_exprContext::getRuleIndex() const {
  return TigerParser::RuleAdd_op_expr;
}

void TigerParser::Add_op_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd_op_expr(this);
}

void TigerParser::Add_op_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd_op_expr(this);
}

TigerParser::Add_op_exprContext* TigerParser::add_op_expr() {
  Add_op_exprContext *_localctx = _tracker.createInstance<Add_op_exprContext>(_ctx, getState());
  enterRule(_localctx, 84, TigerParser::RuleAdd_op_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(337);
    mult_op_expr();
    setState(338);
    add_op_expr_ext();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Add_op_expr_extContext ------------------------------------------------------------------

TigerParser::Add_op_expr_extContext::Add_op_expr_extContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Mult_op_exprContext* TigerParser::Add_op_expr_extContext::mult_op_expr() {
  return getRuleContext<TigerParser::Mult_op_exprContext>(0);
}

TigerParser::Add_op_expr_extContext* TigerParser::Add_op_expr_extContext::add_op_expr_ext() {
  return getRuleContext<TigerParser::Add_op_expr_extContext>(0);
}

tree::TerminalNode* TigerParser::Add_op_expr_extContext::PLUS() {
  return getToken(TigerParser::PLUS, 0);
}

tree::TerminalNode* TigerParser::Add_op_expr_extContext::MINUS() {
  return getToken(TigerParser::MINUS, 0);
}


size_t TigerParser::Add_op_expr_extContext::getRuleIndex() const {
  return TigerParser::RuleAdd_op_expr_ext;
}

void TigerParser::Add_op_expr_extContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd_op_expr_ext(this);
}

void TigerParser::Add_op_expr_extContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd_op_expr_ext(this);
}

TigerParser::Add_op_expr_extContext* TigerParser::add_op_expr_ext() {
  Add_op_expr_extContext *_localctx = _tracker.createInstance<Add_op_expr_extContext>(_ctx, getState());
  enterRule(_localctx, 86, TigerParser::RuleAdd_op_expr_ext);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(345);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::PLUS:
      case TigerParser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(340);
        _la = _input->LA(1);
        if (!(_la == TigerParser::PLUS

        || _la == TigerParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(341);
        mult_op_expr();
        setState(342);
        add_op_expr_ext();
        break;
      }

      case TigerParser::DO:
      case TigerParser::THEN:
      case TigerParser::TO:
      case TigerParser::COMMA:
      case TigerParser::SEMICOLON:
      case TigerParser::CLOSEPAREN:
      case TigerParser::CLOSEBRACK:
      case TigerParser::EQUAL:
      case TigerParser::NEQUAL:
      case TigerParser::LESS:
      case TigerParser::GREAT:
      case TigerParser::LESSEQ:
      case TigerParser::GREATEQ:
      case TigerParser::AND:
      case TigerParser::OR: {
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

//----------------- Mult_op_exprContext ------------------------------------------------------------------

TigerParser::Mult_op_exprContext::Mult_op_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Pow_op_exprContext* TigerParser::Mult_op_exprContext::pow_op_expr() {
  return getRuleContext<TigerParser::Pow_op_exprContext>(0);
}

TigerParser::Mult_op_expr_extContext* TigerParser::Mult_op_exprContext::mult_op_expr_ext() {
  return getRuleContext<TigerParser::Mult_op_expr_extContext>(0);
}


size_t TigerParser::Mult_op_exprContext::getRuleIndex() const {
  return TigerParser::RuleMult_op_expr;
}

void TigerParser::Mult_op_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMult_op_expr(this);
}

void TigerParser::Mult_op_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMult_op_expr(this);
}

TigerParser::Mult_op_exprContext* TigerParser::mult_op_expr() {
  Mult_op_exprContext *_localctx = _tracker.createInstance<Mult_op_exprContext>(_ctx, getState());
  enterRule(_localctx, 88, TigerParser::RuleMult_op_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(347);
    pow_op_expr();
    setState(348);
    mult_op_expr_ext();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mult_op_expr_extContext ------------------------------------------------------------------

TigerParser::Mult_op_expr_extContext::Mult_op_expr_extContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Pow_op_exprContext* TigerParser::Mult_op_expr_extContext::pow_op_expr() {
  return getRuleContext<TigerParser::Pow_op_exprContext>(0);
}

TigerParser::Mult_op_expr_extContext* TigerParser::Mult_op_expr_extContext::mult_op_expr_ext() {
  return getRuleContext<TigerParser::Mult_op_expr_extContext>(0);
}

tree::TerminalNode* TigerParser::Mult_op_expr_extContext::MULT() {
  return getToken(TigerParser::MULT, 0);
}

tree::TerminalNode* TigerParser::Mult_op_expr_extContext::DIV() {
  return getToken(TigerParser::DIV, 0);
}


size_t TigerParser::Mult_op_expr_extContext::getRuleIndex() const {
  return TigerParser::RuleMult_op_expr_ext;
}

void TigerParser::Mult_op_expr_extContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMult_op_expr_ext(this);
}

void TigerParser::Mult_op_expr_extContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMult_op_expr_ext(this);
}

TigerParser::Mult_op_expr_extContext* TigerParser::mult_op_expr_ext() {
  Mult_op_expr_extContext *_localctx = _tracker.createInstance<Mult_op_expr_extContext>(_ctx, getState());
  enterRule(_localctx, 90, TigerParser::RuleMult_op_expr_ext);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(355);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::MULT:
      case TigerParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(350);
        _la = _input->LA(1);
        if (!(_la == TigerParser::MULT

        || _la == TigerParser::DIV)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(351);
        pow_op_expr();
        setState(352);
        mult_op_expr_ext();
        break;
      }

      case TigerParser::DO:
      case TigerParser::THEN:
      case TigerParser::TO:
      case TigerParser::COMMA:
      case TigerParser::SEMICOLON:
      case TigerParser::CLOSEPAREN:
      case TigerParser::CLOSEBRACK:
      case TigerParser::PLUS:
      case TigerParser::MINUS:
      case TigerParser::EQUAL:
      case TigerParser::NEQUAL:
      case TigerParser::LESS:
      case TigerParser::GREAT:
      case TigerParser::LESSEQ:
      case TigerParser::GREATEQ:
      case TigerParser::AND:
      case TigerParser::OR: {
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

//----------------- Pow_op_exprContext ------------------------------------------------------------------

TigerParser::Pow_op_exprContext::Pow_op_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Expr_no_opContext* TigerParser::Pow_op_exprContext::expr_no_op() {
  return getRuleContext<TigerParser::Expr_no_opContext>(0);
}

TigerParser::Pow_op_expr_extContext* TigerParser::Pow_op_exprContext::pow_op_expr_ext() {
  return getRuleContext<TigerParser::Pow_op_expr_extContext>(0);
}


size_t TigerParser::Pow_op_exprContext::getRuleIndex() const {
  return TigerParser::RulePow_op_expr;
}

void TigerParser::Pow_op_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPow_op_expr(this);
}

void TigerParser::Pow_op_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPow_op_expr(this);
}

TigerParser::Pow_op_exprContext* TigerParser::pow_op_expr() {
  Pow_op_exprContext *_localctx = _tracker.createInstance<Pow_op_exprContext>(_ctx, getState());
  enterRule(_localctx, 92, TigerParser::RulePow_op_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    expr_no_op();
    setState(358);
    pow_op_expr_ext();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pow_op_expr_extContext ------------------------------------------------------------------

TigerParser::Pow_op_expr_extContext::Pow_op_expr_extContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Expr_no_opContext* TigerParser::Pow_op_expr_extContext::expr_no_op() {
  return getRuleContext<TigerParser::Expr_no_opContext>(0);
}

TigerParser::Pow_op_expr_extContext* TigerParser::Pow_op_expr_extContext::pow_op_expr_ext() {
  return getRuleContext<TigerParser::Pow_op_expr_extContext>(0);
}

tree::TerminalNode* TigerParser::Pow_op_expr_extContext::POW() {
  return getToken(TigerParser::POW, 0);
}


size_t TigerParser::Pow_op_expr_extContext::getRuleIndex() const {
  return TigerParser::RulePow_op_expr_ext;
}

void TigerParser::Pow_op_expr_extContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPow_op_expr_ext(this);
}

void TigerParser::Pow_op_expr_extContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPow_op_expr_ext(this);
}

TigerParser::Pow_op_expr_extContext* TigerParser::pow_op_expr_ext() {
  Pow_op_expr_extContext *_localctx = _tracker.createInstance<Pow_op_expr_extContext>(_ctx, getState());
  enterRule(_localctx, 94, TigerParser::RulePow_op_expr_ext);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(365);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::POW: {
        enterOuterAlt(_localctx, 1);
        setState(360);
        match(TigerParser::POW);
        setState(361);
        expr_no_op();
        setState(362);
        pow_op_expr_ext();
        break;
      }

      case TigerParser::DO:
      case TigerParser::THEN:
      case TigerParser::TO:
      case TigerParser::COMMA:
      case TigerParser::SEMICOLON:
      case TigerParser::CLOSEPAREN:
      case TigerParser::CLOSEBRACK:
      case TigerParser::PLUS:
      case TigerParser::MINUS:
      case TigerParser::MULT:
      case TigerParser::DIV:
      case TigerParser::EQUAL:
      case TigerParser::NEQUAL:
      case TigerParser::LESS:
      case TigerParser::GREAT:
      case TigerParser::LESSEQ:
      case TigerParser::GREATEQ:
      case TigerParser::AND:
      case TigerParser::OR: {
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

//----------------- Expr_no_opContext ------------------------------------------------------------------

TigerParser::Expr_no_opContext::Expr_no_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::ConstantContext* TigerParser::Expr_no_opContext::constant() {
  return getRuleContext<TigerParser::ConstantContext>(0);
}

TigerParser::LvalueContext* TigerParser::Expr_no_opContext::lvalue() {
  return getRuleContext<TigerParser::LvalueContext>(0);
}

tree::TerminalNode* TigerParser::Expr_no_opContext::OPENPAREN() {
  return getToken(TigerParser::OPENPAREN, 0);
}

TigerParser::ExprContext* TigerParser::Expr_no_opContext::expr() {
  return getRuleContext<TigerParser::ExprContext>(0);
}

tree::TerminalNode* TigerParser::Expr_no_opContext::CLOSEPAREN() {
  return getToken(TigerParser::CLOSEPAREN, 0);
}


size_t TigerParser::Expr_no_opContext::getRuleIndex() const {
  return TigerParser::RuleExpr_no_op;
}

void TigerParser::Expr_no_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_no_op(this);
}

void TigerParser::Expr_no_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_no_op(this);
}

TigerParser::Expr_no_opContext* TigerParser::expr_no_op() {
  Expr_no_opContext *_localctx = _tracker.createInstance<Expr_no_opContext>(_ctx, getState());
  enterRule(_localctx, 96, TigerParser::RuleExpr_no_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(373);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::INTLIT: {
        enterOuterAlt(_localctx, 1);
        setState(367);
        constant();
        break;
      }

      case TigerParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(368);
        lvalue();
        break;
      }

      case TigerParser::OPENPAREN: {
        enterOuterAlt(_localctx, 3);
        setState(369);
        match(TigerParser::OPENPAREN);
        setState(370);
        expr();
        setState(371);
        match(TigerParser::CLOSEPAREN);
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

//----------------- ConstantContext ------------------------------------------------------------------

TigerParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::ConstantContext::INTLIT() {
  return getToken(TigerParser::INTLIT, 0);
}


size_t TigerParser::ConstantContext::getRuleIndex() const {
  return TigerParser::RuleConstant;
}

void TigerParser::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}

void TigerParser::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}

TigerParser::ConstantContext* TigerParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 98, TigerParser::RuleConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(375);
    match(TigerParser::INTLIT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_listContext ------------------------------------------------------------------

TigerParser::Expr_listContext::Expr_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::ExprContext* TigerParser::Expr_listContext::expr() {
  return getRuleContext<TigerParser::ExprContext>(0);
}

TigerParser::Expr_list_tailContext* TigerParser::Expr_listContext::expr_list_tail() {
  return getRuleContext<TigerParser::Expr_list_tailContext>(0);
}


size_t TigerParser::Expr_listContext::getRuleIndex() const {
  return TigerParser::RuleExpr_list;
}

void TigerParser::Expr_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_list(this);
}

void TigerParser::Expr_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_list(this);
}

TigerParser::Expr_listContext* TigerParser::expr_list() {
  Expr_listContext *_localctx = _tracker.createInstance<Expr_listContext>(_ctx, getState());
  enterRule(_localctx, 100, TigerParser::RuleExpr_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(381);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::OPENPAREN:
      case TigerParser::ID:
      case TigerParser::INTLIT: {
        enterOuterAlt(_localctx, 1);
        setState(377);
        expr();
        setState(378);
        expr_list_tail();
        break;
      }

      case TigerParser::CLOSEPAREN: {
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

//----------------- Expr_list_tailContext ------------------------------------------------------------------

TigerParser::Expr_list_tailContext::Expr_list_tailContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Expr_list_tailContext::COMMA() {
  return getToken(TigerParser::COMMA, 0);
}

TigerParser::ExprContext* TigerParser::Expr_list_tailContext::expr() {
  return getRuleContext<TigerParser::ExprContext>(0);
}

TigerParser::Expr_list_tailContext* TigerParser::Expr_list_tailContext::expr_list_tail() {
  return getRuleContext<TigerParser::Expr_list_tailContext>(0);
}


size_t TigerParser::Expr_list_tailContext::getRuleIndex() const {
  return TigerParser::RuleExpr_list_tail;
}

void TigerParser::Expr_list_tailContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_list_tail(this);
}

void TigerParser::Expr_list_tailContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_list_tail(this);
}

TigerParser::Expr_list_tailContext* TigerParser::expr_list_tail() {
  Expr_list_tailContext *_localctx = _tracker.createInstance<Expr_list_tailContext>(_ctx, getState());
  enterRule(_localctx, 102, TigerParser::RuleExpr_list_tail);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(388);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(383);
        match(TigerParser::COMMA);
        setState(384);
        expr();
        setState(385);
        expr_list_tail();
        break;
      }

      case TigerParser::CLOSEPAREN: {
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

//----------------- LvalueContext ------------------------------------------------------------------

TigerParser::LvalueContext::LvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::LvalueContext::ID() {
  return getToken(TigerParser::ID, 0);
}

TigerParser::Lvalue_tailContext* TigerParser::LvalueContext::lvalue_tail() {
  return getRuleContext<TigerParser::Lvalue_tailContext>(0);
}


size_t TigerParser::LvalueContext::getRuleIndex() const {
  return TigerParser::RuleLvalue;
}

void TigerParser::LvalueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLvalue(this);
}

void TigerParser::LvalueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLvalue(this);
}

TigerParser::LvalueContext* TigerParser::lvalue() {
  LvalueContext *_localctx = _tracker.createInstance<LvalueContext>(_ctx, getState());
  enterRule(_localctx, 104, TigerParser::RuleLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    match(TigerParser::ID);
    setState(391);
    lvalue_tail();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Lvalue_tailContext ------------------------------------------------------------------

TigerParser::Lvalue_tailContext::Lvalue_tailContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Lvalue_tailContext::OPENBRACK() {
  return getToken(TigerParser::OPENBRACK, 0);
}

TigerParser::ExprContext* TigerParser::Lvalue_tailContext::expr() {
  return getRuleContext<TigerParser::ExprContext>(0);
}

tree::TerminalNode* TigerParser::Lvalue_tailContext::CLOSEBRACK() {
  return getToken(TigerParser::CLOSEBRACK, 0);
}


size_t TigerParser::Lvalue_tailContext::getRuleIndex() const {
  return TigerParser::RuleLvalue_tail;
}

void TigerParser::Lvalue_tailContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLvalue_tail(this);
}

void TigerParser::Lvalue_tailContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLvalue_tail(this);
}

TigerParser::Lvalue_tailContext* TigerParser::lvalue_tail() {
  Lvalue_tailContext *_localctx = _tracker.createInstance<Lvalue_tailContext>(_ctx, getState());
  enterRule(_localctx, 106, TigerParser::RuleLvalue_tail);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(398);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::OPENBRACK: {
        enterOuterAlt(_localctx, 1);
        setState(393);
        match(TigerParser::OPENBRACK);
        setState(394);
        expr();
        setState(395);
        match(TigerParser::CLOSEBRACK);
        break;
      }

      case TigerParser::DO:
      case TigerParser::THEN:
      case TigerParser::TO:
      case TigerParser::COMMA:
      case TigerParser::SEMICOLON:
      case TigerParser::CLOSEPAREN:
      case TigerParser::CLOSEBRACK:
      case TigerParser::PLUS:
      case TigerParser::MINUS:
      case TigerParser::MULT:
      case TigerParser::DIV:
      case TigerParser::POW:
      case TigerParser::EQUAL:
      case TigerParser::NEQUAL:
      case TigerParser::LESS:
      case TigerParser::GREAT:
      case TigerParser::LESSEQ:
      case TigerParser::GREATEQ:
      case TigerParser::AND:
      case TigerParser::OR:
      case TigerParser::ASSIGN: {
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

// Static vars and initialization.
std::vector<dfa::DFA> TigerParser::_decisionToDFA;
atn::PredictionContextCache TigerParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN TigerParser::_atn;
std::vector<uint16_t> TigerParser::_serializedATN;

std::vector<std::string> TigerParser::_ruleNames = {
  "tiger_program", "declaration_segment", "type_declaration_list", "var_declaration_list", 
  "funct_list", "type_declaration", "type", "type_id", "var_declaration", 
  "storage_class", "id_list", "optional_init", "funct", "param_list", "param_list_tail", 
  "ret_type", "param", "stat_seq_func", "stat_seq", "stat", "assignment_stat", 
  "if_stat", "if_else_stat", "while_stat", "for_stat", "fncall_stat", "break_stat", 
  "return_stat", "sub_scope_stat", "stat_seq_if", "stat_seq_else", "stat_seq_while", 
  "stat_seq_for", "opt_return", "opt_prefix", "l_tail", "expr", "unambiguous_expr", 
  "logical_op_expr", "logical_op_expr_ext", "compare_op_expr", "compare_op_expr_ext", 
  "add_op_expr", "add_op_expr_ext", "mult_op_expr", "mult_op_expr_ext", 
  "pow_op_expr", "pow_op_expr_ext", "expr_no_op", "constant", "expr_list", 
  "expr_list_tail", "lvalue", "lvalue_tail"
};

std::vector<std::string> TigerParser::_literalNames = {
  "", "'array'", "'begin'", "'break'", "'do'", "'else'", "'end'", "'enddo'", 
  "'endif'", "'for'", "'function'", "'if'", "'int'", "'let'", "'of'", "'program'", 
  "'return'", "'static'", "'then'", "'to'", "'type'", "'var'", "'while'", 
  "','", "'.'", "':'", "';'", "'('", "')'", "'['", "']'", "'{'", "'}'", 
  "'+'", "'-'", "'*'", "'/'", "'**'", "'=='", "'!='", "'<'", "'>'", "'<='", 
  "'>='", "'&'", "'|'", "':='", "'='"
};

std::vector<std::string> TigerParser::_symbolicNames = {
  "", "ARRAY", "BEGIN", "BREAK", "DO", "ELSE", "END", "ENDDO", "ENDIF", 
  "FOR", "FUNCTION", "IF", "INT", "LET", "OF", "PROGRAM", "RETURN", "STATIC", 
  "THEN", "TO", "TYPE", "VAR", "WHILE", "COMMA", "DOT", "COLON", "SEMICOLON", 
  "OPENPAREN", "CLOSEPAREN", "OPENBRACK", "CLOSEBRACK", "OPENCURLY", "CLOSECURLY", 
  "PLUS", "MINUS", "MULT", "DIV", "POW", "EQUAL", "NEQUAL", "LESS", "GREAT", 
  "LESSEQ", "GREATEQ", "AND", "OR", "ASSIGN", "TASSIGN", "WS", "COMMENT", 
  "ID", "INTLIT"
};

dfa::Vocabulary TigerParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> TigerParser::_tokenNames;

TigerParser::Initializer::Initializer() {
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
    0x3, 0x35, 0x193, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x7e, 
    0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x84, 0xa, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x8a, 0xa, 0x6, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0x9a, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xab, 0xa, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xb0, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xc0, 0xa, 0xf, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xc7, 
    0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xcc, 0xa, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xd8, 0xa, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xe3, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x12b, 0xa, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x131, 0xa, 0x24, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x138, 0xa, 0x25, 
    0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x13c, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
    0x29, 0x3, 0x29, 0x5, 0x29, 0x148, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 
    0x2b, 0x152, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x15c, 0xa, 0x2d, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
    0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x166, 0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 
    0x31, 0x170, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x178, 0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x180, 0xa, 0x34, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x187, 
    0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 
    0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x191, 0xa, 0x37, 0x3, 0x37, 
    0x2, 0x2, 0x38, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 
    0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 
    0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x2, 0x7, 0x4, 0x2, 
    0x13, 0x13, 0x17, 0x17, 0x3, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x28, 0x2d, 
    0x3, 0x2, 0x23, 0x24, 0x3, 0x2, 0x25, 0x26, 0x2, 0x17d, 0x2, 0x6e, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x76, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x83, 0x3, 0x2, 0x2, 0x2, 0xa, 0x89, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0xe, 0x99, 0x3, 0x2, 0x2, 0x2, 0x10, 0x9b, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x14, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x18, 0xaf, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xbf, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0xc6, 0x3, 0x2, 0x2, 0x2, 0x20, 0xcb, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x24, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0xd7, 0x3, 0x2, 0x2, 0x2, 0x28, 0xe2, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xe4, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0xea, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x32, 0x101, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x36, 0x113, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0x116, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x11a, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x120, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x122, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x124, 0x3, 0x2, 0x2, 0x2, 0x42, 0x126, 0x3, 0x2, 0x2, 0x2, 0x44, 0x12a, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x130, 0x3, 0x2, 0x2, 0x2, 0x48, 0x137, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x13d, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x50, 0x147, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x149, 0x3, 0x2, 0x2, 0x2, 0x54, 0x151, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x153, 0x3, 0x2, 0x2, 0x2, 0x58, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x15d, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x165, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x167, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x62, 0x177, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x179, 0x3, 0x2, 0x2, 0x2, 0x66, 0x17f, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x186, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x188, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x190, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x11, 0x2, 0x2, 
    0x6f, 0x70, 0x7, 0x34, 0x2, 0x2, 0x70, 0x71, 0x7, 0xf, 0x2, 0x2, 0x71, 
    0x72, 0x5, 0x4, 0x3, 0x2, 0x72, 0x73, 0x7, 0x4, 0x2, 0x2, 0x73, 0x74, 
    0x5, 0xa, 0x6, 0x2, 0x74, 0x75, 0x7, 0x8, 0x2, 0x2, 0x75, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x76, 0x77, 0x5, 0x6, 0x4, 0x2, 0x77, 0x78, 0x5, 0x8, 
    0x5, 0x2, 0x78, 0x5, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x5, 0xc, 0x7, 
    0x2, 0x7a, 0x7b, 0x5, 0x6, 0x4, 0x2, 0x7b, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0x7c, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7d, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 
    0x5, 0x12, 0xa, 0x2, 0x80, 0x81, 0x5, 0x8, 0x5, 0x2, 0x81, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x84, 0x3, 0x2, 0x2, 0x2, 0x83, 0x7f, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x82, 0x3, 0x2, 0x2, 0x2, 0x84, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x85, 0x86, 0x5, 0x1a, 0xe, 0x2, 0x86, 0x87, 0x5, 0xa, 0x6, 0x2, 
    0x87, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x89, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x16, 0x2, 0x2, 0x8c, 0x8d, 0x7, 
    0x34, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x31, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0xe, 
    0x8, 0x2, 0x8f, 0x90, 0x7, 0x1c, 0x2, 0x2, 0x90, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x91, 0x9a, 0x5, 0x10, 0x9, 0x2, 0x92, 0x93, 0x7, 0x3, 0x2, 0x2, 
    0x93, 0x94, 0x7, 0x1f, 0x2, 0x2, 0x94, 0x95, 0x7, 0x35, 0x2, 0x2, 0x95, 
    0x96, 0x7, 0x20, 0x2, 0x2, 0x96, 0x97, 0x7, 0x10, 0x2, 0x2, 0x97, 0x9a, 
    0x5, 0x10, 0x9, 0x2, 0x98, 0x9a, 0x7, 0x34, 0x2, 0x2, 0x99, 0x91, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x92, 0x3, 0x2, 0x2, 0x2, 0x99, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0xf, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0xe, 0x2, 
    0x2, 0x9c, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x5, 0x14, 0xb, 0x2, 
    0x9e, 0x9f, 0x5, 0x16, 0xc, 0x2, 0x9f, 0xa0, 0x7, 0x1b, 0x2, 0x2, 0xa0, 
    0xa1, 0x5, 0xe, 0x8, 0x2, 0xa1, 0xa2, 0x5, 0x18, 0xd, 0x2, 0xa2, 0xa3, 
    0x7, 0x1c, 0x2, 0x2, 0xa3, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x9, 
    0x2, 0x2, 0x2, 0xa5, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xab, 0x7, 0x34, 
    0x2, 0x2, 0xa7, 0xa8, 0x7, 0x34, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x19, 0x2, 
    0x2, 0xa9, 0xab, 0x5, 0x16, 0xc, 0x2, 0xaa, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0xaa, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xab, 0x17, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0xad, 0x7, 0x30, 0x2, 0x2, 0xad, 0xb0, 0x5, 0x64, 0x33, 0x2, 0xae, 0xb0, 
    0x3, 0x2, 0x2, 0x2, 0xaf, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xae, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0x19, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0xc, 
    0x2, 0x2, 0xb2, 0xb3, 0x7, 0x34, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x1d, 0x2, 
    0x2, 0xb4, 0xb5, 0x5, 0x1c, 0xf, 0x2, 0xb5, 0xb6, 0x7, 0x1e, 0x2, 0x2, 
    0xb6, 0xb7, 0x5, 0x20, 0x11, 0x2, 0xb7, 0xb8, 0x7, 0x4, 0x2, 0x2, 0xb8, 
    0xb9, 0x5, 0x24, 0x13, 0x2, 0xb9, 0xba, 0x7, 0x8, 0x2, 0x2, 0xba, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x5, 0x22, 0x12, 0x2, 0xbc, 0xbd, 0x5, 
    0x1e, 0x10, 0x2, 0xbd, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc0, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 
    0x2, 0xc0, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x19, 0x2, 0x2, 
    0xc2, 0xc3, 0x5, 0x22, 0x12, 0x2, 0xc3, 0xc4, 0x5, 0x1e, 0x10, 0x2, 
    0xc4, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0xc1, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x1b, 0x2, 0x2, 0xc9, 0xcc, 0x5, 
    0xe, 0x8, 0x2, 0xca, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc8, 0x3, 0x2, 
    0x2, 0x2, 0xcb, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0xcd, 0xce, 0x7, 0x34, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x1b, 0x2, 0x2, 
    0xcf, 0xd0, 0x5, 0xe, 0x8, 0x2, 0xd0, 0x23, 0x3, 0x2, 0x2, 0x2, 0xd1, 
    0xd2, 0x5, 0x26, 0x14, 0x2, 0xd2, 0x25, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd8, 
    0x5, 0x28, 0x15, 0x2, 0xd4, 0xd5, 0x5, 0x28, 0x15, 0x2, 0xd5, 0xd6, 
    0x5, 0x26, 0x14, 0x2, 0xd6, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd3, 0x3, 
    0x2, 0x2, 0x2, 0xd7, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0xd9, 0xe3, 0x5, 0x2a, 0x16, 0x2, 0xda, 0xe3, 0x5, 0x2c, 0x17, 
    0x2, 0xdb, 0xe3, 0x5, 0x2e, 0x18, 0x2, 0xdc, 0xe3, 0x5, 0x30, 0x19, 
    0x2, 0xdd, 0xe3, 0x5, 0x32, 0x1a, 0x2, 0xde, 0xe3, 0x5, 0x34, 0x1b, 
    0x2, 0xdf, 0xe3, 0x5, 0x36, 0x1c, 0x2, 0xe0, 0xe3, 0x5, 0x38, 0x1d, 
    0x2, 0xe1, 0xe3, 0x5, 0x3a, 0x1e, 0x2, 0xe2, 0xd9, 0x3, 0x2, 0x2, 0x2, 
    0xe2, 0xda, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xe2, 
    0xdc, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xde, 
    0x3, 0x2, 0x2, 0x2, 0xe2, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe3, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0xe5, 0x5, 0x6a, 0x36, 0x2, 0xe5, 0xe6, 0x5, 0x48, 0x25, 
    0x2, 0xe6, 0xe7, 0x7, 0x30, 0x2, 0x2, 0xe7, 0xe8, 0x5, 0x4a, 0x26, 0x2, 
    0xe8, 0xe9, 0x7, 0x1c, 0x2, 0x2, 0xe9, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xea, 
    0xeb, 0x7, 0xd, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x4a, 0x26, 0x2, 0xec, 0xed, 
    0x7, 0x14, 0x2, 0x2, 0xed, 0xee, 0x5, 0x3c, 0x1f, 0x2, 0xee, 0xef, 0x7, 
    0xa, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x1c, 0x2, 0x2, 0xf0, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xf2, 0x7, 0xd, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x4a, 0x26, 
    0x2, 0xf3, 0xf4, 0x7, 0x14, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x3c, 0x1f, 0x2, 
    0xf5, 0xf6, 0x7, 0x7, 0x2, 0x2, 0xf6, 0xf7, 0x5, 0x3e, 0x20, 0x2, 0xf7, 
    0xf8, 0x7, 0xa, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x1c, 0x2, 0x2, 0xf9, 0x2f, 
    0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x18, 0x2, 0x2, 0xfb, 0xfc, 0x5, 
    0x4a, 0x26, 0x2, 0xfc, 0xfd, 0x7, 0x6, 0x2, 0x2, 0xfd, 0xfe, 0x5, 0x40, 
    0x21, 0x2, 0xfe, 0xff, 0x7, 0x9, 0x2, 0x2, 0xff, 0x100, 0x7, 0x1c, 0x2, 
    0x2, 0x100, 0x31, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x7, 0xb, 0x2, 0x2, 
    0x102, 0x103, 0x7, 0x34, 0x2, 0x2, 0x103, 0x104, 0x7, 0x30, 0x2, 0x2, 
    0x104, 0x105, 0x5, 0x4a, 0x26, 0x2, 0x105, 0x106, 0x7, 0x15, 0x2, 0x2, 
    0x106, 0x107, 0x5, 0x4a, 0x26, 0x2, 0x107, 0x108, 0x7, 0x6, 0x2, 0x2, 
    0x108, 0x109, 0x5, 0x42, 0x22, 0x2, 0x109, 0x10a, 0x7, 0x9, 0x2, 0x2, 
    0x10a, 0x10b, 0x7, 0x1c, 0x2, 0x2, 0x10b, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x10c, 0x10d, 0x5, 0x46, 0x24, 0x2, 0x10d, 0x10e, 0x7, 0x34, 0x2, 0x2, 
    0x10e, 0x10f, 0x7, 0x1d, 0x2, 0x2, 0x10f, 0x110, 0x5, 0x66, 0x34, 0x2, 
    0x110, 0x111, 0x7, 0x1e, 0x2, 0x2, 0x111, 0x112, 0x7, 0x1c, 0x2, 0x2, 
    0x112, 0x35, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x7, 0x5, 0x2, 0x2, 0x114, 
    0x115, 0x7, 0x1c, 0x2, 0x2, 0x115, 0x37, 0x3, 0x2, 0x2, 0x2, 0x116, 
    0x117, 0x7, 0x12, 0x2, 0x2, 0x117, 0x118, 0x5, 0x44, 0x23, 0x2, 0x118, 
    0x119, 0x7, 0x1c, 0x2, 0x2, 0x119, 0x39, 0x3, 0x2, 0x2, 0x2, 0x11a, 
    0x11b, 0x7, 0xf, 0x2, 0x2, 0x11b, 0x11c, 0x5, 0x4, 0x3, 0x2, 0x11c, 
    0x11d, 0x7, 0x4, 0x2, 0x2, 0x11d, 0x11e, 0x5, 0x26, 0x14, 0x2, 0x11e, 
    0x11f, 0x7, 0x8, 0x2, 0x2, 0x11f, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 
    0x5, 0x26, 0x14, 0x2, 0x121, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 
    0x5, 0x26, 0x14, 0x2, 0x123, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 
    0x5, 0x26, 0x14, 0x2, 0x125, 0x41, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 
    0x5, 0x26, 0x14, 0x2, 0x127, 0x43, 0x3, 0x2, 0x2, 0x2, 0x128, 0x12b, 
    0x5, 0x4a, 0x26, 0x2, 0x129, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x128, 
    0x3, 0x2, 0x2, 0x2, 0x12a, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x45, 0x3, 
    0x2, 0x2, 0x2, 0x12c, 0x12d, 0x5, 0x6a, 0x36, 0x2, 0x12d, 0x12e, 0x7, 
    0x30, 0x2, 0x2, 0x12e, 0x131, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x131, 0x3, 
    0x2, 0x2, 0x2, 0x130, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x130, 0x12f, 0x3, 
    0x2, 0x2, 0x2, 0x131, 0x47, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x7, 0x30, 
    0x2, 0x2, 0x133, 0x134, 0x5, 0x6a, 0x36, 0x2, 0x134, 0x135, 0x5, 0x48, 
    0x25, 0x2, 0x135, 0x138, 0x3, 0x2, 0x2, 0x2, 0x136, 0x138, 0x3, 0x2, 
    0x2, 0x2, 0x137, 0x132, 0x3, 0x2, 0x2, 0x2, 0x137, 0x136, 0x3, 0x2, 
    0x2, 0x2, 0x138, 0x49, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13c, 0x5, 0x62, 
    0x32, 0x2, 0x13a, 0x13c, 0x5, 0x4c, 0x27, 0x2, 0x13b, 0x139, 0x3, 0x2, 
    0x2, 0x2, 0x13b, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x13d, 0x13e, 0x5, 0x4e, 0x28, 0x2, 0x13e, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x13f, 0x140, 0x5, 0x52, 0x2a, 0x2, 0x140, 0x141, 0x5, 0x50, 0x29, 
    0x2, 0x141, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x9, 0x3, 0x2, 0x2, 
    0x143, 0x144, 0x5, 0x52, 0x2a, 0x2, 0x144, 0x145, 0x5, 0x50, 0x29, 0x2, 
    0x145, 0x148, 0x3, 0x2, 0x2, 0x2, 0x146, 0x148, 0x3, 0x2, 0x2, 0x2, 
    0x147, 0x142, 0x3, 0x2, 0x2, 0x2, 0x147, 0x146, 0x3, 0x2, 0x2, 0x2, 
    0x148, 0x51, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x5, 0x56, 0x2c, 0x2, 
    0x14a, 0x14b, 0x5, 0x54, 0x2b, 0x2, 0x14b, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x14c, 0x14d, 0x9, 0x4, 0x2, 0x2, 0x14d, 0x14e, 0x5, 0x56, 0x2c, 0x2, 
    0x14e, 0x14f, 0x5, 0x54, 0x2b, 0x2, 0x14f, 0x152, 0x3, 0x2, 0x2, 0x2, 
    0x150, 0x152, 0x3, 0x2, 0x2, 0x2, 0x151, 0x14c, 0x3, 0x2, 0x2, 0x2, 
    0x151, 0x150, 0x3, 0x2, 0x2, 0x2, 0x152, 0x55, 0x3, 0x2, 0x2, 0x2, 0x153, 
    0x154, 0x5, 0x5a, 0x2e, 0x2, 0x154, 0x155, 0x5, 0x58, 0x2d, 0x2, 0x155, 
    0x57, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x9, 0x5, 0x2, 0x2, 0x157, 0x158, 
    0x5, 0x5a, 0x2e, 0x2, 0x158, 0x159, 0x5, 0x58, 0x2d, 0x2, 0x159, 0x15c, 
    0x3, 0x2, 0x2, 0x2, 0x15a, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x156, 
    0x3, 0x2, 0x2, 0x2, 0x15b, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x15d, 0x15e, 0x5, 0x5e, 0x30, 0x2, 0x15e, 0x15f, 0x5, 
    0x5c, 0x2f, 0x2, 0x15f, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x9, 
    0x6, 0x2, 0x2, 0x161, 0x162, 0x5, 0x5e, 0x30, 0x2, 0x162, 0x163, 0x5, 
    0x5c, 0x2f, 0x2, 0x163, 0x166, 0x3, 0x2, 0x2, 0x2, 0x164, 0x166, 0x3, 
    0x2, 0x2, 0x2, 0x165, 0x160, 0x3, 0x2, 0x2, 0x2, 0x165, 0x164, 0x3, 
    0x2, 0x2, 0x2, 0x166, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x5, 0x62, 
    0x32, 0x2, 0x168, 0x169, 0x5, 0x60, 0x31, 0x2, 0x169, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x16a, 0x16b, 0x7, 0x27, 0x2, 0x2, 0x16b, 0x16c, 0x5, 0x62, 
    0x32, 0x2, 0x16c, 0x16d, 0x5, 0x60, 0x31, 0x2, 0x16d, 0x170, 0x3, 0x2, 
    0x2, 0x2, 0x16e, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16a, 0x3, 0x2, 
    0x2, 0x2, 0x16f, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x170, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x171, 0x178, 0x5, 0x64, 0x33, 0x2, 0x172, 0x178, 0x5, 0x6a, 0x36, 
    0x2, 0x173, 0x174, 0x7, 0x1d, 0x2, 0x2, 0x174, 0x175, 0x5, 0x4a, 0x26, 
    0x2, 0x175, 0x176, 0x7, 0x1e, 0x2, 0x2, 0x176, 0x178, 0x3, 0x2, 0x2, 
    0x2, 0x177, 0x171, 0x3, 0x2, 0x2, 0x2, 0x177, 0x172, 0x3, 0x2, 0x2, 
    0x2, 0x177, 0x173, 0x3, 0x2, 0x2, 0x2, 0x178, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x179, 0x17a, 0x7, 0x35, 0x2, 0x2, 0x17a, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x17b, 0x17c, 0x5, 0x4a, 0x26, 0x2, 0x17c, 0x17d, 0x5, 0x68, 0x35, 0x2, 
    0x17d, 0x180, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x180, 0x3, 0x2, 0x2, 0x2, 
    0x17f, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x17e, 0x3, 0x2, 0x2, 0x2, 
    0x180, 0x67, 0x3, 0x2, 0x2, 0x2, 0x181, 0x182, 0x7, 0x19, 0x2, 0x2, 
    0x182, 0x183, 0x5, 0x4a, 0x26, 0x2, 0x183, 0x184, 0x5, 0x68, 0x35, 0x2, 
    0x184, 0x187, 0x3, 0x2, 0x2, 0x2, 0x185, 0x187, 0x3, 0x2, 0x2, 0x2, 
    0x186, 0x181, 0x3, 0x2, 0x2, 0x2, 0x186, 0x185, 0x3, 0x2, 0x2, 0x2, 
    0x187, 0x69, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x7, 0x34, 0x2, 0x2, 
    0x189, 0x18a, 0x5, 0x6c, 0x37, 0x2, 0x18a, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x18b, 0x18c, 0x7, 0x1f, 0x2, 0x2, 0x18c, 0x18d, 0x5, 0x4a, 0x26, 0x2, 
    0x18d, 0x18e, 0x7, 0x20, 0x2, 0x2, 0x18e, 0x191, 0x3, 0x2, 0x2, 0x2, 
    0x18f, 0x191, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18b, 0x3, 0x2, 0x2, 0x2, 
    0x190, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x191, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x7d, 0x83, 0x89, 0x99, 0xaa, 0xaf, 0xbf, 0xc6, 0xcb, 0xd7, 0xe2, 0x12a, 
    0x130, 0x137, 0x13b, 0x147, 0x151, 0x15b, 0x165, 0x16f, 0x177, 0x17f, 
    0x186, 0x190, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

TigerParser::Initializer TigerParser::_init;
