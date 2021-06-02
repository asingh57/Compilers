
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
    setState(58);
    match(TigerParser::PROGRAM);
    setState(59);
    match(TigerParser::ID);
    setState(60);
    match(TigerParser::LET);
    setState(61);
    declaration_segment();
    setState(62);
    match(TigerParser::BEGIN);
    setState(63);
    funct_list();
    setState(64);
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
    setState(66);
    type_declaration_list();
    setState(67);
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
    setState(73);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(69);
        type_declaration();
        setState(70);
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
    setState(79);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::STATIC:
      case TigerParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(75);
        var_declaration();
        setState(76);
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
    setState(85);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::FUNCTION: {
        enterOuterAlt(_localctx, 1);
        setState(81);
        funct();
        setState(82);
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
    setState(87);
    match(TigerParser::TYPE);
    setState(88);
    match(TigerParser::ID);
    setState(89);
    match(TigerParser::TASSIGN);
    setState(90);
    type();
    setState(91);
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
    setState(101);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(93);
        type_id();
        break;
      }

      case TigerParser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(94);
        match(TigerParser::ARRAY);
        setState(95);
        match(TigerParser::OPENBRACK);
        setState(96);
        match(TigerParser::INTLIT);
        setState(97);
        match(TigerParser::CLOSEBRACK);
        setState(98);
        match(TigerParser::OF);
        setState(99);
        type_id();
        break;
      }

      case TigerParser::ID: {
        enterOuterAlt(_localctx, 3);
        setState(100);
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
    setState(103);
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
    setState(105);
    storage_class();
    setState(106);
    id_list();
    setState(107);
    match(TigerParser::COLON);
    setState(108);
    type();
    setState(109);
    optional_init();
    setState(110);
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
    setState(112);
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
    setState(118);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(114);
      match(TigerParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(115);
      match(TigerParser::ID);
      setState(116);
      match(TigerParser::COMMA);
      setState(117);
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
    setState(123);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::ASSIGN: {
        enterOuterAlt(_localctx, 1);
        setState(120);
        match(TigerParser::ASSIGN);
        setState(121);
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

TigerParser::Stat_seqContext* TigerParser::FunctContext::stat_seq() {
  return getRuleContext<TigerParser::Stat_seqContext>(0);
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
    setState(125);
    match(TigerParser::FUNCTION);
    setState(126);
    match(TigerParser::ID);
    setState(127);
    match(TigerParser::OPENPAREN);
    setState(128);
    param_list();
    setState(129);
    match(TigerParser::CLOSEPAREN);
    setState(130);
    ret_type();
    setState(131);
    match(TigerParser::BEGIN);
    setState(132);
    stat_seq();
    setState(133);
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
    setState(139);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(135);
        param();
        setState(136);
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
    setState(146);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(141);
        match(TigerParser::COMMA);
        setState(142);
        param();
        setState(143);
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
    setState(151);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::COLON: {
        enterOuterAlt(_localctx, 1);
        setState(148);
        match(TigerParser::COLON);
        setState(149);
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
    setState(153);
    match(TigerParser::ID);
    setState(154);
    match(TigerParser::COLON);
    setState(155);
    type();
   
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
  enterRule(_localctx, 34, TigerParser::RuleStat_seq);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(161);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(157);
      stat();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(158);
      stat();
      setState(159);
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

TigerParser::LvalueContext* TigerParser::StatContext::lvalue() {
  return getRuleContext<TigerParser::LvalueContext>(0);
}

TigerParser::L_tailContext* TigerParser::StatContext::l_tail() {
  return getRuleContext<TigerParser::L_tailContext>(0);
}

tree::TerminalNode* TigerParser::StatContext::ASSIGN() {
  return getToken(TigerParser::ASSIGN, 0);
}

std::vector<TigerParser::ExprContext *> TigerParser::StatContext::expr() {
  return getRuleContexts<TigerParser::ExprContext>();
}

TigerParser::ExprContext* TigerParser::StatContext::expr(size_t i) {
  return getRuleContext<TigerParser::ExprContext>(i);
}

tree::TerminalNode* TigerParser::StatContext::SEMICOLON() {
  return getToken(TigerParser::SEMICOLON, 0);
}

tree::TerminalNode* TigerParser::StatContext::IF() {
  return getToken(TigerParser::IF, 0);
}

tree::TerminalNode* TigerParser::StatContext::THEN() {
  return getToken(TigerParser::THEN, 0);
}

std::vector<TigerParser::Stat_seqContext *> TigerParser::StatContext::stat_seq() {
  return getRuleContexts<TigerParser::Stat_seqContext>();
}

TigerParser::Stat_seqContext* TigerParser::StatContext::stat_seq(size_t i) {
  return getRuleContext<TigerParser::Stat_seqContext>(i);
}

tree::TerminalNode* TigerParser::StatContext::ENDIF() {
  return getToken(TigerParser::ENDIF, 0);
}

tree::TerminalNode* TigerParser::StatContext::ELSE() {
  return getToken(TigerParser::ELSE, 0);
}

tree::TerminalNode* TigerParser::StatContext::WHILE() {
  return getToken(TigerParser::WHILE, 0);
}

tree::TerminalNode* TigerParser::StatContext::DO() {
  return getToken(TigerParser::DO, 0);
}

tree::TerminalNode* TigerParser::StatContext::ENDDO() {
  return getToken(TigerParser::ENDDO, 0);
}

tree::TerminalNode* TigerParser::StatContext::FOR() {
  return getToken(TigerParser::FOR, 0);
}

tree::TerminalNode* TigerParser::StatContext::ID() {
  return getToken(TigerParser::ID, 0);
}

tree::TerminalNode* TigerParser::StatContext::TO() {
  return getToken(TigerParser::TO, 0);
}

TigerParser::Opt_prefixContext* TigerParser::StatContext::opt_prefix() {
  return getRuleContext<TigerParser::Opt_prefixContext>(0);
}

tree::TerminalNode* TigerParser::StatContext::OPENPAREN() {
  return getToken(TigerParser::OPENPAREN, 0);
}

TigerParser::Expr_listContext* TigerParser::StatContext::expr_list() {
  return getRuleContext<TigerParser::Expr_listContext>(0);
}

tree::TerminalNode* TigerParser::StatContext::CLOSEPAREN() {
  return getToken(TigerParser::CLOSEPAREN, 0);
}

tree::TerminalNode* TigerParser::StatContext::BREAK() {
  return getToken(TigerParser::BREAK, 0);
}

tree::TerminalNode* TigerParser::StatContext::RETURN() {
  return getToken(TigerParser::RETURN, 0);
}

TigerParser::Opt_returnContext* TigerParser::StatContext::opt_return() {
  return getRuleContext<TigerParser::Opt_returnContext>(0);
}

tree::TerminalNode* TigerParser::StatContext::LET() {
  return getToken(TigerParser::LET, 0);
}

TigerParser::Declaration_segmentContext* TigerParser::StatContext::declaration_segment() {
  return getRuleContext<TigerParser::Declaration_segmentContext>(0);
}

tree::TerminalNode* TigerParser::StatContext::BEGIN() {
  return getToken(TigerParser::BEGIN, 0);
}

tree::TerminalNode* TigerParser::StatContext::END() {
  return getToken(TigerParser::END, 0);
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
  enterRule(_localctx, 36, TigerParser::RuleStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(222);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(163);
      lvalue();
      setState(164);
      l_tail();
      setState(165);
      match(TigerParser::ASSIGN);
      setState(166);
      expr(0);
      setState(167);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(169);
      match(TigerParser::IF);
      setState(170);
      expr(0);
      setState(171);
      match(TigerParser::THEN);
      setState(172);
      stat_seq();
      setState(173);
      match(TigerParser::ENDIF);
      setState(174);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(176);
      match(TigerParser::IF);
      setState(177);
      expr(0);
      setState(178);
      match(TigerParser::THEN);
      setState(179);
      stat_seq();
      setState(180);
      match(TigerParser::ELSE);
      setState(181);
      stat_seq();
      setState(182);
      match(TigerParser::ENDIF);
      setState(183);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(185);
      match(TigerParser::WHILE);
      setState(186);
      expr(0);
      setState(187);
      match(TigerParser::DO);
      setState(188);
      stat_seq();
      setState(189);
      match(TigerParser::ENDDO);
      setState(190);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(192);
      match(TigerParser::FOR);
      setState(193);
      match(TigerParser::ID);
      setState(194);
      match(TigerParser::ASSIGN);
      setState(195);
      expr(0);
      setState(196);
      match(TigerParser::TO);
      setState(197);
      expr(0);
      setState(198);
      match(TigerParser::DO);
      setState(199);
      stat_seq();
      setState(200);
      match(TigerParser::ENDDO);
      setState(201);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(203);
      opt_prefix();
      setState(204);
      match(TigerParser::ID);
      setState(205);
      match(TigerParser::OPENPAREN);
      setState(206);
      expr_list();
      setState(207);
      match(TigerParser::CLOSEPAREN);
      setState(208);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(210);
      match(TigerParser::BREAK);
      setState(211);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(212);
      match(TigerParser::RETURN);
      setState(213);
      opt_return();
      setState(214);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(216);
      match(TigerParser::LET);
      setState(217);
      declaration_segment();
      setState(218);
      match(TigerParser::BEGIN);
      setState(219);
      stat_seq();
      setState(220);
      match(TigerParser::END);
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
  enterRule(_localctx, 38, TigerParser::RuleOpt_return);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(226);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::OPENPAREN:
      case TigerParser::ID:
      case TigerParser::INTLIT: {
        enterOuterAlt(_localctx, 1);
        setState(224);
        expr(0);
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
  enterRule(_localctx, 40, TigerParser::RuleOpt_prefix);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(232);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(228);
      lvalue();
      setState(229);
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
  enterRule(_localctx, 42, TigerParser::RuleL_tail);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(234);
      match(TigerParser::ASSIGN);
      setState(235);
      lvalue();
      setState(236);
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

TigerParser::ConstantContext* TigerParser::ExprContext::constant() {
  return getRuleContext<TigerParser::ConstantContext>(0);
}

TigerParser::LvalueContext* TigerParser::ExprContext::lvalue() {
  return getRuleContext<TigerParser::LvalueContext>(0);
}

tree::TerminalNode* TigerParser::ExprContext::OPENPAREN() {
  return getToken(TigerParser::OPENPAREN, 0);
}

std::vector<TigerParser::ExprContext *> TigerParser::ExprContext::expr() {
  return getRuleContexts<TigerParser::ExprContext>();
}

TigerParser::ExprContext* TigerParser::ExprContext::expr(size_t i) {
  return getRuleContext<TigerParser::ExprContext>(i);
}

tree::TerminalNode* TigerParser::ExprContext::CLOSEPAREN() {
  return getToken(TigerParser::CLOSEPAREN, 0);
}

TigerParser::Binary_operatorContext* TigerParser::ExprContext::binary_operator() {
  return getRuleContext<TigerParser::Binary_operatorContext>(0);
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
   return expr(0);
}

TigerParser::ExprContext* TigerParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TigerParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  TigerParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, TigerParser::RuleExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(248);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::INTLIT: {
        setState(242);
        constant();
        break;
      }

      case TigerParser::ID: {
        setState(243);
        lvalue();
        break;
      }

      case TigerParser::OPENPAREN: {
        setState(244);
        match(TigerParser::OPENPAREN);
        setState(245);
        expr(0);
        setState(246);
        match(TigerParser::CLOSEPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(256);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(250);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(251);
        binary_operator();
        setState(252);
        expr(3); 
      }
      setState(258);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
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
  enterRule(_localctx, 46, TigerParser::RuleConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    match(TigerParser::INTLIT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binary_operatorContext ------------------------------------------------------------------

TigerParser::Binary_operatorContext::Binary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::Binary_operatorContext::PLUS() {
  return getToken(TigerParser::PLUS, 0);
}

tree::TerminalNode* TigerParser::Binary_operatorContext::MINUS() {
  return getToken(TigerParser::MINUS, 0);
}

tree::TerminalNode* TigerParser::Binary_operatorContext::MULT() {
  return getToken(TigerParser::MULT, 0);
}

tree::TerminalNode* TigerParser::Binary_operatorContext::DIV() {
  return getToken(TigerParser::DIV, 0);
}

tree::TerminalNode* TigerParser::Binary_operatorContext::POW() {
  return getToken(TigerParser::POW, 0);
}

tree::TerminalNode* TigerParser::Binary_operatorContext::EQUAL() {
  return getToken(TigerParser::EQUAL, 0);
}

tree::TerminalNode* TigerParser::Binary_operatorContext::NEQUAL() {
  return getToken(TigerParser::NEQUAL, 0);
}

tree::TerminalNode* TigerParser::Binary_operatorContext::LESS() {
  return getToken(TigerParser::LESS, 0);
}

tree::TerminalNode* TigerParser::Binary_operatorContext::GREAT() {
  return getToken(TigerParser::GREAT, 0);
}

tree::TerminalNode* TigerParser::Binary_operatorContext::LESSEQ() {
  return getToken(TigerParser::LESSEQ, 0);
}

tree::TerminalNode* TigerParser::Binary_operatorContext::GREATEQ() {
  return getToken(TigerParser::GREATEQ, 0);
}

tree::TerminalNode* TigerParser::Binary_operatorContext::AND() {
  return getToken(TigerParser::AND, 0);
}

tree::TerminalNode* TigerParser::Binary_operatorContext::OR() {
  return getToken(TigerParser::OR, 0);
}


size_t TigerParser::Binary_operatorContext::getRuleIndex() const {
  return TigerParser::RuleBinary_operator;
}

void TigerParser::Binary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary_operator(this);
}

void TigerParser::Binary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary_operator(this);
}

TigerParser::Binary_operatorContext* TigerParser::binary_operator() {
  Binary_operatorContext *_localctx = _tracker.createInstance<Binary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 48, TigerParser::RuleBinary_operator);
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
    setState(261);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TigerParser::PLUS)
      | (1ULL << TigerParser::MINUS)
      | (1ULL << TigerParser::MULT)
      | (1ULL << TigerParser::DIV)
      | (1ULL << TigerParser::POW)
      | (1ULL << TigerParser::EQUAL)
      | (1ULL << TigerParser::NEQUAL)
      | (1ULL << TigerParser::LESS)
      | (1ULL << TigerParser::GREAT)
      | (1ULL << TigerParser::LESSEQ)
      | (1ULL << TigerParser::GREATEQ)
      | (1ULL << TigerParser::AND)
      | (1ULL << TigerParser::OR))) != 0))) {
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
  enterRule(_localctx, 50, TigerParser::RuleExpr_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(267);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::OPENPAREN:
      case TigerParser::ID:
      case TigerParser::INTLIT: {
        enterOuterAlt(_localctx, 1);
        setState(263);
        expr(0);
        setState(264);
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
  enterRule(_localctx, 52, TigerParser::RuleExpr_list_tail);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(274);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(269);
        match(TigerParser::COMMA);
        setState(270);
        expr(0);
        setState(271);
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
  enterRule(_localctx, 54, TigerParser::RuleLvalue);

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
    match(TigerParser::ID);
    setState(277);
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
  enterRule(_localctx, 56, TigerParser::RuleLvalue_tail);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(284);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(279);
      match(TigerParser::OPENBRACK);
      setState(280);
      expr(0);
      setState(281);
      match(TigerParser::CLOSEBRACK);
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

bool TigerParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 22: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TigerParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
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
  "ret_type", "param", "stat_seq", "stat", "opt_return", "opt_prefix", "l_tail", 
  "expr", "constant", "binary_operator", "expr_list", "expr_list_tail", 
  "lvalue", "lvalue_tail"
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
  "LESSEQ", "GREATEQ", "AND", "OR", "ASSIGN", "TASSIGN", "WS", "ID", "INTLIT", 
  "COMMENT"
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
    0x3, 0x35, 0x121, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0x4c, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x52, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x58, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x68, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x79, 
    0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x7e, 0xa, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0x8e, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x5, 0x10, 0x95, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 
    0x11, 0x9a, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xa4, 0xa, 0x13, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x5, 0x14, 0xe1, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xe5, 0xa, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xeb, 0xa, 
    0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 
    0xf2, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0xfb, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x101, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 
    0x104, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x10e, 0xa, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x115, 0xa, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x11f, 0xa, 0x1e, 0x3, 0x1e, 0x2, 0x3, 0x2e, 
    0x1f, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
    0x32, 0x34, 0x36, 0x38, 0x3a, 0x2, 0x4, 0x4, 0x2, 0x13, 0x13, 0x17, 
    0x17, 0x3, 0x2, 0x23, 0x2f, 0x2, 0x11f, 0x2, 0x3c, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x44, 0x3, 0x2, 0x2, 0x2, 0x6, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x57, 0x3, 0x2, 0x2, 0x2, 0xc, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x67, 0x3, 0x2, 0x2, 0x2, 0x10, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x14, 0x72, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x78, 0x3, 0x2, 0x2, 0x2, 0x18, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x94, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x99, 0x3, 0x2, 0x2, 0x2, 0x22, 0x9b, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x26, 0xe0, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0xf1, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xfa, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x105, 0x3, 0x2, 0x2, 0x2, 0x32, 0x107, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x10d, 0x3, 0x2, 0x2, 0x2, 0x36, 0x114, 0x3, 0x2, 0x2, 0x2, 0x38, 0x116, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 
    0x11, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x33, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0xf, 
    0x2, 0x2, 0x3f, 0x40, 0x5, 0x4, 0x3, 0x2, 0x40, 0x41, 0x7, 0x4, 0x2, 
    0x2, 0x41, 0x42, 0x5, 0xa, 0x6, 0x2, 0x42, 0x43, 0x7, 0x8, 0x2, 0x2, 
    0x43, 0x3, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x5, 0x6, 0x4, 0x2, 0x45, 
    0x46, 0x5, 0x8, 0x5, 0x2, 0x46, 0x5, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 
    0x5, 0xc, 0x7, 0x2, 0x48, 0x49, 0x5, 0x6, 0x4, 0x2, 0x49, 0x4c, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x4b, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x4e, 0x5, 0x12, 0xa, 0x2, 0x4e, 0x4f, 0x5, 0x8, 0x5, 0x2, 
    0x4f, 0x52, 0x3, 0x2, 0x2, 0x2, 0x50, 0x52, 0x3, 0x2, 0x2, 0x2, 0x51, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x5, 0x1a, 0xe, 0x2, 0x54, 0x55, 0x5, 
    0xa, 0x6, 0x2, 0x55, 0x58, 0x3, 0x2, 0x2, 0x2, 0x56, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x57, 0x53, 0x3, 0x2, 0x2, 0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0xb, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x16, 0x2, 0x2, 
    0x5a, 0x5b, 0x7, 0x33, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x31, 0x2, 0x2, 0x5c, 
    0x5d, 0x5, 0xe, 0x8, 0x2, 0x5d, 0x5e, 0x7, 0x1c, 0x2, 0x2, 0x5e, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x68, 0x5, 0x10, 0x9, 0x2, 0x60, 0x61, 0x7, 
    0x3, 0x2, 0x2, 0x61, 0x62, 0x7, 0x1f, 0x2, 0x2, 0x62, 0x63, 0x7, 0x34, 
    0x2, 0x2, 0x63, 0x64, 0x7, 0x20, 0x2, 0x2, 0x64, 0x65, 0x7, 0x10, 0x2, 
    0x2, 0x65, 0x68, 0x5, 0x10, 0x9, 0x2, 0x66, 0x68, 0x7, 0x33, 0x2, 0x2, 
    0x67, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x67, 0x60, 0x3, 0x2, 0x2, 0x2, 0x67, 
    0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0xf, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 
    0x7, 0xe, 0x2, 0x2, 0x6a, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x5, 
    0x14, 0xb, 0x2, 0x6c, 0x6d, 0x5, 0x16, 0xc, 0x2, 0x6d, 0x6e, 0x7, 0x1b, 
    0x2, 0x2, 0x6e, 0x6f, 0x5, 0xe, 0x8, 0x2, 0x6f, 0x70, 0x5, 0x18, 0xd, 
    0x2, 0x70, 0x71, 0x7, 0x1c, 0x2, 0x2, 0x71, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x73, 0x9, 0x2, 0x2, 0x2, 0x73, 0x15, 0x3, 0x2, 0x2, 0x2, 0x74, 
    0x79, 0x7, 0x33, 0x2, 0x2, 0x75, 0x76, 0x7, 0x33, 0x2, 0x2, 0x76, 0x77, 
    0x7, 0x19, 0x2, 0x2, 0x77, 0x79, 0x5, 0x16, 0xc, 0x2, 0x78, 0x74, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x75, 0x3, 0x2, 0x2, 0x2, 0x79, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x7b, 0x7, 0x30, 0x2, 0x2, 0x7b, 0x7e, 0x5, 0x30, 0x19, 
    0x2, 0x7c, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7a, 0x3, 0x2, 0x2, 0x2, 
    0x7d, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x19, 0x3, 0x2, 0x2, 0x2, 0x7f, 
    0x80, 0x7, 0xc, 0x2, 0x2, 0x80, 0x81, 0x7, 0x33, 0x2, 0x2, 0x81, 0x82, 
    0x7, 0x1d, 0x2, 0x2, 0x82, 0x83, 0x5, 0x1c, 0xf, 0x2, 0x83, 0x84, 0x7, 
    0x1e, 0x2, 0x2, 0x84, 0x85, 0x5, 0x20, 0x11, 0x2, 0x85, 0x86, 0x7, 0x4, 
    0x2, 0x2, 0x86, 0x87, 0x5, 0x24, 0x13, 0x2, 0x87, 0x88, 0x7, 0x8, 0x2, 
    0x2, 0x88, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x5, 0x22, 0x12, 0x2, 
    0x8a, 0x8b, 0x5, 0x1e, 0x10, 0x2, 0x8b, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x8e, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8c, 
    0x3, 0x2, 0x2, 0x2, 0x8e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 
    0x19, 0x2, 0x2, 0x90, 0x91, 0x5, 0x22, 0x12, 0x2, 0x91, 0x92, 0x5, 0x1e, 
    0x10, 0x2, 0x92, 0x95, 0x3, 0x2, 0x2, 0x2, 0x93, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x94, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x94, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x95, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 0x1b, 0x2, 0x2, 0x97, 
    0x9a, 0x5, 0xe, 0x8, 0x2, 0x98, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x99, 0x96, 
    0x3, 0x2, 0x2, 0x2, 0x99, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x33, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x1b, 
    0x2, 0x2, 0x9d, 0x9e, 0x5, 0xe, 0x8, 0x2, 0x9e, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x9f, 0xa4, 0x5, 0x26, 0x14, 0x2, 0xa0, 0xa1, 0x5, 0x26, 0x14, 
    0x2, 0xa1, 0xa2, 0x5, 0x24, 0x13, 0x2, 0xa2, 0xa4, 0x3, 0x2, 0x2, 0x2, 
    0xa3, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0x38, 0x1d, 0x2, 0xa6, 0xa7, 
    0x5, 0x2c, 0x17, 0x2, 0xa7, 0xa8, 0x7, 0x30, 0x2, 0x2, 0xa8, 0xa9, 0x5, 
    0x2e, 0x18, 0x2, 0xa9, 0xaa, 0x7, 0x1c, 0x2, 0x2, 0xaa, 0xe1, 0x3, 0x2, 
    0x2, 0x2, 0xab, 0xac, 0x7, 0xd, 0x2, 0x2, 0xac, 0xad, 0x5, 0x2e, 0x18, 
    0x2, 0xad, 0xae, 0x7, 0x14, 0x2, 0x2, 0xae, 0xaf, 0x5, 0x24, 0x13, 0x2, 
    0xaf, 0xb0, 0x7, 0xa, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0x1c, 0x2, 0x2, 0xb1, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0xd, 0x2, 0x2, 0xb3, 0xb4, 
    0x5, 0x2e, 0x18, 0x2, 0xb4, 0xb5, 0x7, 0x14, 0x2, 0x2, 0xb5, 0xb6, 0x5, 
    0x24, 0x13, 0x2, 0xb6, 0xb7, 0x7, 0x7, 0x2, 0x2, 0xb7, 0xb8, 0x5, 0x24, 
    0x13, 0x2, 0xb8, 0xb9, 0x7, 0xa, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x1c, 0x2, 
    0x2, 0xba, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x18, 0x2, 0x2, 
    0xbc, 0xbd, 0x5, 0x2e, 0x18, 0x2, 0xbd, 0xbe, 0x7, 0x6, 0x2, 0x2, 0xbe, 
    0xbf, 0x5, 0x24, 0x13, 0x2, 0xbf, 0xc0, 0x7, 0x9, 0x2, 0x2, 0xc0, 0xc1, 
    0x7, 0x1c, 0x2, 0x2, 0xc1, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x7, 
    0xb, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x33, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0x30, 
    0x2, 0x2, 0xc5, 0xc6, 0x5, 0x2e, 0x18, 0x2, 0xc6, 0xc7, 0x7, 0x15, 0x2, 
    0x2, 0xc7, 0xc8, 0x5, 0x2e, 0x18, 0x2, 0xc8, 0xc9, 0x7, 0x6, 0x2, 0x2, 
    0xc9, 0xca, 0x5, 0x24, 0x13, 0x2, 0xca, 0xcb, 0x7, 0x9, 0x2, 0x2, 0xcb, 
    0xcc, 0x7, 0x1c, 0x2, 0x2, 0xcc, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 
    0x5, 0x2a, 0x16, 0x2, 0xce, 0xcf, 0x7, 0x33, 0x2, 0x2, 0xcf, 0xd0, 0x7, 
    0x1d, 0x2, 0x2, 0xd0, 0xd1, 0x5, 0x34, 0x1b, 0x2, 0xd1, 0xd2, 0x7, 0x1e, 
    0x2, 0x2, 0xd2, 0xd3, 0x7, 0x1c, 0x2, 0x2, 0xd3, 0xe1, 0x3, 0x2, 0x2, 
    0x2, 0xd4, 0xd5, 0x7, 0x5, 0x2, 0x2, 0xd5, 0xe1, 0x7, 0x1c, 0x2, 0x2, 
    0xd6, 0xd7, 0x7, 0x12, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0x28, 0x15, 0x2, 0xd8, 
    0xd9, 0x7, 0x1c, 0x2, 0x2, 0xd9, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 
    0x7, 0xf, 0x2, 0x2, 0xdb, 0xdc, 0x5, 0x4, 0x3, 0x2, 0xdc, 0xdd, 0x7, 
    0x4, 0x2, 0x2, 0xdd, 0xde, 0x5, 0x24, 0x13, 0x2, 0xde, 0xdf, 0x7, 0x8, 
    0x2, 0x2, 0xdf, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0xe0, 0xab, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xb2, 0x3, 0x2, 0x2, 0x2, 
    0xe0, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xe0, 
    0xcd, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xd6, 
    0x3, 0x2, 0x2, 0x2, 0xe0, 0xda, 0x3, 0x2, 0x2, 0x2, 0xe1, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe5, 0x5, 0x2e, 0x18, 0x2, 0xe3, 0xe5, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe3, 0x3, 0x2, 0x2, 
    0x2, 0xe5, 0x29, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0x38, 0x1d, 0x2, 
    0xe7, 0xe8, 0x7, 0x30, 0x2, 0x2, 0xe8, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe9, 
    0xeb, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe9, 
    0x3, 0x2, 0x2, 0x2, 0xeb, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 
    0x30, 0x2, 0x2, 0xed, 0xee, 0x5, 0x38, 0x1d, 0x2, 0xee, 0xef, 0x5, 0x2c, 
    0x17, 0x2, 0xef, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf2, 0x3, 0x2, 0x2, 
    0x2, 0xf1, 0xec, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf0, 0x3, 0x2, 0x2, 0x2, 
    0xf2, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x8, 0x18, 0x1, 0x2, 0xf4, 
    0xfb, 0x5, 0x30, 0x19, 0x2, 0xf5, 0xfb, 0x5, 0x38, 0x1d, 0x2, 0xf6, 
    0xf7, 0x7, 0x1d, 0x2, 0x2, 0xf7, 0xf8, 0x5, 0x2e, 0x18, 0x2, 0xf8, 0xf9, 
    0x7, 0x1e, 0x2, 0x2, 0xf9, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf3, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf6, 0x3, 0x2, 
    0x2, 0x2, 0xfb, 0x102, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0xc, 0x4, 0x2, 
    0x2, 0xfd, 0xfe, 0x5, 0x32, 0x1a, 0x2, 0xfe, 0xff, 0x5, 0x2e, 0x18, 
    0x5, 0xff, 0x101, 0x3, 0x2, 0x2, 0x2, 0x100, 0xfc, 0x3, 0x2, 0x2, 0x2, 
    0x101, 0x104, 0x3, 0x2, 0x2, 0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 
    0x102, 0x103, 0x3, 0x2, 0x2, 0x2, 0x103, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x104, 
    0x102, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0x34, 0x2, 0x2, 0x106, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x9, 0x3, 0x2, 0x2, 0x108, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x2e, 0x18, 0x2, 0x10a, 0x10b, 
    0x5, 0x36, 0x1c, 0x2, 0x10b, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10e, 
    0x3, 0x2, 0x2, 0x2, 0x10d, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10c, 
    0x3, 0x2, 0x2, 0x2, 0x10e, 0x35, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x7, 
    0x19, 0x2, 0x2, 0x110, 0x111, 0x5, 0x2e, 0x18, 0x2, 0x111, 0x112, 0x5, 
    0x36, 0x1c, 0x2, 0x112, 0x115, 0x3, 0x2, 0x2, 0x2, 0x113, 0x115, 0x3, 
    0x2, 0x2, 0x2, 0x114, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x114, 0x113, 0x3, 
    0x2, 0x2, 0x2, 0x115, 0x37, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x7, 0x33, 
    0x2, 0x2, 0x117, 0x118, 0x5, 0x3a, 0x1e, 0x2, 0x118, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x11a, 0x7, 0x1f, 0x2, 0x2, 0x11a, 0x11b, 0x5, 0x2e, 
    0x18, 0x2, 0x11b, 0x11c, 0x7, 0x20, 0x2, 0x2, 0x11c, 0x11f, 0x3, 0x2, 
    0x2, 0x2, 0x11d, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x119, 0x3, 0x2, 
    0x2, 0x2, 0x11e, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x15, 0x4b, 0x51, 0x57, 0x67, 0x78, 0x7d, 0x8d, 0x94, 0x99, 0xa3, 
    0xe0, 0xe4, 0xea, 0xf1, 0xfa, 0x102, 0x10d, 0x114, 0x11e, 
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
