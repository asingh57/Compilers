
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
    setState(70);
    match(TigerParser::PROGRAM);
    setState(71);
    match(TigerParser::ID);
    setState(72);
    match(TigerParser::LET);
    setState(73);
    declaration_segment();
    setState(74);
    match(TigerParser::BEGIN);
    setState(75);
    funct_list();
    setState(76);
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
    setState(78);
    type_declaration_list();
    setState(79);
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
    setState(85);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(81);
        type_declaration();
        setState(82);
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
    setState(91);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::STATIC:
      case TigerParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(87);
        var_declaration();
        setState(88);
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
    setState(97);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::FUNCTION: {
        enterOuterAlt(_localctx, 1);
        setState(93);
        funct();
        setState(94);
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
    setState(99);
    match(TigerParser::TYPE);
    setState(100);
    match(TigerParser::ID);
    setState(101);
    match(TigerParser::TASSIGN);
    setState(102);
    type();
    setState(103);
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
    setState(113);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(105);
        type_id();
        break;
      }

      case TigerParser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(106);
        match(TigerParser::ARRAY);
        setState(107);
        match(TigerParser::OPENBRACK);
        setState(108);
        match(TigerParser::INTLIT);
        setState(109);
        match(TigerParser::CLOSEBRACK);
        setState(110);
        match(TigerParser::OF);
        setState(111);
        type_id();
        break;
      }

      case TigerParser::ID: {
        enterOuterAlt(_localctx, 3);
        setState(112);
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
    setState(115);
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
    setState(117);
    storage_class();
    setState(118);
    id_list();
    setState(119);
    match(TigerParser::COLON);
    setState(120);
    type();
    setState(121);
    optional_init();
    setState(122);
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
    setState(124);
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
    setState(130);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(126);
      match(TigerParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(127);
      match(TigerParser::ID);
      setState(128);
      match(TigerParser::COMMA);
      setState(129);
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
    setState(135);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::ASSIGN: {
        enterOuterAlt(_localctx, 1);
        setState(132);
        match(TigerParser::ASSIGN);
        setState(133);
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
    setState(137);
    match(TigerParser::FUNCTION);
    setState(138);
    match(TigerParser::ID);
    setState(139);
    match(TigerParser::OPENPAREN);
    setState(140);
    param_list();
    setState(141);
    match(TigerParser::CLOSEPAREN);
    setState(142);
    ret_type();
    setState(143);
    match(TigerParser::BEGIN);
    setState(144);
    stat_seq();
    setState(145);
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
    setState(151);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(147);
        param();
        setState(148);
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
    setState(158);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(153);
        match(TigerParser::COMMA);
        setState(154);
        param();
        setState(155);
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
    setState(163);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::COLON: {
        enterOuterAlt(_localctx, 1);
        setState(160);
        match(TigerParser::COLON);
        setState(161);
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
    setState(165);
    match(TigerParser::ID);
    setState(166);
    match(TigerParser::COLON);
    setState(167);
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
    setState(173);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(169);
      stat();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(170);
      stat();
      setState(171);
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
    setState(234);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(175);
      lvalue();
      setState(176);
      l_tail();
      setState(177);
      match(TigerParser::ASSIGN);
      setState(178);
      expr();
      setState(179);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(181);
      match(TigerParser::IF);
      setState(182);
      expr();
      setState(183);
      match(TigerParser::THEN);
      setState(184);
      stat_seq();
      setState(185);
      match(TigerParser::ENDIF);
      setState(186);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(188);
      match(TigerParser::IF);
      setState(189);
      expr();
      setState(190);
      match(TigerParser::THEN);
      setState(191);
      stat_seq();
      setState(192);
      match(TigerParser::ELSE);
      setState(193);
      stat_seq();
      setState(194);
      match(TigerParser::ENDIF);
      setState(195);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(197);
      match(TigerParser::WHILE);
      setState(198);
      expr();
      setState(199);
      match(TigerParser::DO);
      setState(200);
      stat_seq();
      setState(201);
      match(TigerParser::ENDDO);
      setState(202);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(204);
      match(TigerParser::FOR);
      setState(205);
      match(TigerParser::ID);
      setState(206);
      match(TigerParser::ASSIGN);
      setState(207);
      expr();
      setState(208);
      match(TigerParser::TO);
      setState(209);
      expr();
      setState(210);
      match(TigerParser::DO);
      setState(211);
      stat_seq();
      setState(212);
      match(TigerParser::ENDDO);
      setState(213);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(215);
      opt_prefix();
      setState(216);
      match(TigerParser::ID);
      setState(217);
      match(TigerParser::OPENPAREN);
      setState(218);
      expr_list();
      setState(219);
      match(TigerParser::CLOSEPAREN);
      setState(220);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(222);
      match(TigerParser::BREAK);
      setState(223);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(224);
      match(TigerParser::RETURN);
      setState(225);
      opt_return();
      setState(226);
      match(TigerParser::SEMICOLON);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(228);
      match(TigerParser::LET);
      setState(229);
      declaration_segment();
      setState(230);
      match(TigerParser::BEGIN);
      setState(231);
      stat_seq();
      setState(232);
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
    setState(238);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::OPENPAREN:
      case TigerParser::ID:
      case TigerParser::INTLIT: {
        enterOuterAlt(_localctx, 1);
        setState(236);
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
  enterRule(_localctx, 40, TigerParser::RuleOpt_prefix);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(244);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(240);
      lvalue();
      setState(241);
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
    setState(251);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(246);
      match(TigerParser::ASSIGN);
      setState(247);
      lvalue();
      setState(248);
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

TigerParser::Unambiguous_exprContext* TigerParser::ExprContext::unambiguous_expr() {
  return getRuleContext<TigerParser::Unambiguous_exprContext>(0);
}

tree::TerminalNode* TigerParser::ExprContext::OPENPAREN() {
  return getToken(TigerParser::OPENPAREN, 0);
}

TigerParser::ExprContext* TigerParser::ExprContext::expr() {
  return getRuleContext<TigerParser::ExprContext>(0);
}

tree::TerminalNode* TigerParser::ExprContext::CLOSEPAREN() {
  return getToken(TigerParser::CLOSEPAREN, 0);
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
  enterRule(_localctx, 44, TigerParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(260);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(253);
      constant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(254);
      lvalue();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(255);
      unambiguous_expr();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(256);
      match(TigerParser::OPENPAREN);
      setState(257);
      expr();
      setState(258);
      match(TigerParser::CLOSEPAREN);
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
  enterRule(_localctx, 46, TigerParser::RuleUnambiguous_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
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

std::vector<TigerParser::Compare_op_exprContext *> TigerParser::Logical_op_exprContext::compare_op_expr() {
  return getRuleContexts<TigerParser::Compare_op_exprContext>();
}

TigerParser::Compare_op_exprContext* TigerParser::Logical_op_exprContext::compare_op_expr(size_t i) {
  return getRuleContext<TigerParser::Compare_op_exprContext>(i);
}

tree::TerminalNode* TigerParser::Logical_op_exprContext::AND() {
  return getToken(TigerParser::AND, 0);
}

tree::TerminalNode* TigerParser::Logical_op_exprContext::OR() {
  return getToken(TigerParser::OR, 0);
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
  enterRule(_localctx, 48, TigerParser::RuleLogical_op_expr);
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
    setState(264);
    compare_op_expr();
    setState(267);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TigerParser::AND

    || _la == TigerParser::OR) {
      setState(265);
      _la = _input->LA(1);
      if (!(_la == TigerParser::AND

      || _la == TigerParser::OR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(266);
      compare_op_expr();
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

std::vector<TigerParser::Add_op_exprContext *> TigerParser::Compare_op_exprContext::add_op_expr() {
  return getRuleContexts<TigerParser::Add_op_exprContext>();
}

TigerParser::Add_op_exprContext* TigerParser::Compare_op_exprContext::add_op_expr(size_t i) {
  return getRuleContext<TigerParser::Add_op_exprContext>(i);
}

std::vector<tree::TerminalNode *> TigerParser::Compare_op_exprContext::EQUAL() {
  return getTokens(TigerParser::EQUAL);
}

tree::TerminalNode* TigerParser::Compare_op_exprContext::EQUAL(size_t i) {
  return getToken(TigerParser::EQUAL, i);
}

std::vector<tree::TerminalNode *> TigerParser::Compare_op_exprContext::NEQUAL() {
  return getTokens(TigerParser::NEQUAL);
}

tree::TerminalNode* TigerParser::Compare_op_exprContext::NEQUAL(size_t i) {
  return getToken(TigerParser::NEQUAL, i);
}

std::vector<tree::TerminalNode *> TigerParser::Compare_op_exprContext::LESS() {
  return getTokens(TigerParser::LESS);
}

tree::TerminalNode* TigerParser::Compare_op_exprContext::LESS(size_t i) {
  return getToken(TigerParser::LESS, i);
}

std::vector<tree::TerminalNode *> TigerParser::Compare_op_exprContext::GREAT() {
  return getTokens(TigerParser::GREAT);
}

tree::TerminalNode* TigerParser::Compare_op_exprContext::GREAT(size_t i) {
  return getToken(TigerParser::GREAT, i);
}

std::vector<tree::TerminalNode *> TigerParser::Compare_op_exprContext::LESSEQ() {
  return getTokens(TigerParser::LESSEQ);
}

tree::TerminalNode* TigerParser::Compare_op_exprContext::LESSEQ(size_t i) {
  return getToken(TigerParser::LESSEQ, i);
}

std::vector<tree::TerminalNode *> TigerParser::Compare_op_exprContext::GREATEQ() {
  return getTokens(TigerParser::GREATEQ);
}

tree::TerminalNode* TigerParser::Compare_op_exprContext::GREATEQ(size_t i) {
  return getToken(TigerParser::GREATEQ, i);
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
  enterRule(_localctx, 50, TigerParser::RuleCompare_op_expr);
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
    setState(269);
    add_op_expr();
    setState(274);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TigerParser::EQUAL)
      | (1ULL << TigerParser::NEQUAL)
      | (1ULL << TigerParser::LESS)
      | (1ULL << TigerParser::GREAT)
      | (1ULL << TigerParser::LESSEQ)
      | (1ULL << TigerParser::GREATEQ))) != 0)) {
      setState(270);
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
      setState(271);
      add_op_expr();
      setState(276);
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

//----------------- Add_op_exprContext ------------------------------------------------------------------

TigerParser::Add_op_exprContext::Add_op_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TigerParser::Mult_op_exprContext *> TigerParser::Add_op_exprContext::mult_op_expr() {
  return getRuleContexts<TigerParser::Mult_op_exprContext>();
}

TigerParser::Mult_op_exprContext* TigerParser::Add_op_exprContext::mult_op_expr(size_t i) {
  return getRuleContext<TigerParser::Mult_op_exprContext>(i);
}

std::vector<tree::TerminalNode *> TigerParser::Add_op_exprContext::PLUS() {
  return getTokens(TigerParser::PLUS);
}

tree::TerminalNode* TigerParser::Add_op_exprContext::PLUS(size_t i) {
  return getToken(TigerParser::PLUS, i);
}

std::vector<tree::TerminalNode *> TigerParser::Add_op_exprContext::MINUS() {
  return getTokens(TigerParser::MINUS);
}

tree::TerminalNode* TigerParser::Add_op_exprContext::MINUS(size_t i) {
  return getToken(TigerParser::MINUS, i);
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
  enterRule(_localctx, 52, TigerParser::RuleAdd_op_expr);
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
    setState(277);
    mult_op_expr();
    setState(282);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TigerParser::PLUS

    || _la == TigerParser::MINUS) {
      setState(278);
      _la = _input->LA(1);
      if (!(_la == TigerParser::PLUS

      || _la == TigerParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(279);
      mult_op_expr();
      setState(284);
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

//----------------- Mult_op_exprContext ------------------------------------------------------------------

TigerParser::Mult_op_exprContext::Mult_op_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TigerParser::Pow_op_exprContext *> TigerParser::Mult_op_exprContext::pow_op_expr() {
  return getRuleContexts<TigerParser::Pow_op_exprContext>();
}

TigerParser::Pow_op_exprContext* TigerParser::Mult_op_exprContext::pow_op_expr(size_t i) {
  return getRuleContext<TigerParser::Pow_op_exprContext>(i);
}

std::vector<tree::TerminalNode *> TigerParser::Mult_op_exprContext::MULT() {
  return getTokens(TigerParser::MULT);
}

tree::TerminalNode* TigerParser::Mult_op_exprContext::MULT(size_t i) {
  return getToken(TigerParser::MULT, i);
}

std::vector<tree::TerminalNode *> TigerParser::Mult_op_exprContext::DIV() {
  return getTokens(TigerParser::DIV);
}

tree::TerminalNode* TigerParser::Mult_op_exprContext::DIV(size_t i) {
  return getToken(TigerParser::DIV, i);
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
  enterRule(_localctx, 54, TigerParser::RuleMult_op_expr);
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
    setState(285);
    pow_op_expr();
    setState(290);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TigerParser::MULT

    || _la == TigerParser::DIV) {
      setState(286);
      _la = _input->LA(1);
      if (!(_la == TigerParser::MULT

      || _la == TigerParser::DIV)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(287);
      pow_op_expr();
      setState(292);
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

//----------------- Pow_op_exprContext ------------------------------------------------------------------

TigerParser::Pow_op_exprContext::Pow_op_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TigerParser::Expr_no_opContext *> TigerParser::Pow_op_exprContext::expr_no_op() {
  return getRuleContexts<TigerParser::Expr_no_opContext>();
}

TigerParser::Expr_no_opContext* TigerParser::Pow_op_exprContext::expr_no_op(size_t i) {
  return getRuleContext<TigerParser::Expr_no_opContext>(i);
}

std::vector<tree::TerminalNode *> TigerParser::Pow_op_exprContext::POW() {
  return getTokens(TigerParser::POW);
}

tree::TerminalNode* TigerParser::Pow_op_exprContext::POW(size_t i) {
  return getToken(TigerParser::POW, i);
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
  enterRule(_localctx, 56, TigerParser::RulePow_op_expr);
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
    setState(293);
    expr_no_op();
    setState(298);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TigerParser::POW) {
      setState(294);
      match(TigerParser::POW);
      setState(295);
      expr_no_op();
      setState(300);
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
  enterRule(_localctx, 58, TigerParser::RuleExpr_no_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(307);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::INTLIT: {
        enterOuterAlt(_localctx, 1);
        setState(301);
        constant();
        break;
      }

      case TigerParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(302);
        lvalue();
        break;
      }

      case TigerParser::OPENPAREN: {
        enterOuterAlt(_localctx, 3);
        setState(303);
        match(TigerParser::OPENPAREN);
        setState(304);
        expr();
        setState(305);
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
  enterRule(_localctx, 60, TigerParser::RuleConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
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
  enterRule(_localctx, 62, TigerParser::RuleExpr_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(315);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::OPENPAREN:
      case TigerParser::ID:
      case TigerParser::INTLIT: {
        enterOuterAlt(_localctx, 1);
        setState(311);
        expr();
        setState(312);
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
  enterRule(_localctx, 64, TigerParser::RuleExpr_list_tail);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(322);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(317);
        match(TigerParser::COMMA);
        setState(318);
        expr();
        setState(319);
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
  enterRule(_localctx, 66, TigerParser::RuleLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    match(TigerParser::ID);
    setState(325);
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
  enterRule(_localctx, 68, TigerParser::RuleLvalue_tail);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(332);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::OPENBRACK: {
        enterOuterAlt(_localctx, 1);
        setState(327);
        match(TigerParser::OPENBRACK);
        setState(328);
        expr();
        setState(329);
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
  "ret_type", "param", "stat_seq", "stat", "opt_return", "opt_prefix", "l_tail", 
  "expr", "unambiguous_expr", "logical_op_expr", "compare_op_expr", "add_op_expr", 
  "mult_op_expr", "pow_op_expr", "expr_no_op", "constant", "expr_list", 
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
    0x3, 0x35, 0x151, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x58, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x5e, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x64, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0x74, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x85, 0xa, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x8a, 0xa, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x9a, 
    0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 
    0x10, 0xa1, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xa6, 
    0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xb0, 0xa, 0x13, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 
    0xed, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xf1, 0xa, 0x15, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xf7, 0xa, 0x16, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0xfe, 0xa, 
    0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x5, 0x18, 0x107, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x10e, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x7, 0x1b, 0x113, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x116, 
    0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x11b, 0xa, 0x1c, 
    0xc, 0x1c, 0xe, 0x1c, 0x11e, 0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x7, 0x1d, 0x123, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x126, 0xb, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x12b, 0xa, 0x1e, 0xc, 0x1e, 
    0xe, 0x1e, 0x12e, 0xb, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x136, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x13e, 0xa, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x145, 
    0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x14f, 0xa, 0x24, 0x3, 0x24, 
    0x2, 0x2, 0x25, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 
    0x46, 0x2, 0x7, 0x4, 0x2, 0x13, 0x13, 0x17, 0x17, 0x3, 0x2, 0x2e, 0x2f, 
    0x3, 0x2, 0x28, 0x2d, 0x3, 0x2, 0x23, 0x24, 0x3, 0x2, 0x25, 0x26, 0x2, 
    0x150, 0x2, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x57, 0x3, 0x2, 0x2, 0x2, 0x8, 0x5d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x63, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x65, 0x3, 0x2, 0x2, 0x2, 0xe, 0x73, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x75, 0x3, 0x2, 0x2, 0x2, 0x12, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x16, 0x84, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x89, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x20, 0xa5, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x24, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0xec, 0x3, 0x2, 0x2, 0x2, 0x28, 0xf0, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xfd, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x106, 0x3, 0x2, 0x2, 0x2, 0x30, 0x108, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x34, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x117, 0x3, 0x2, 0x2, 0x2, 0x38, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x127, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x135, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x137, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x42, 0x144, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x146, 0x3, 0x2, 0x2, 0x2, 0x46, 0x14e, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x49, 0x7, 0x11, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x34, 0x2, 0x2, 
    0x4a, 0x4b, 0x7, 0xf, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0x4, 0x3, 0x2, 0x4c, 
    0x4d, 0x7, 0x4, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0xa, 0x6, 0x2, 0x4e, 0x4f, 
    0x7, 0x8, 0x2, 0x2, 0x4f, 0x3, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x5, 
    0x6, 0x4, 0x2, 0x51, 0x52, 0x5, 0x8, 0x5, 0x2, 0x52, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x53, 0x54, 0x5, 0xc, 0x7, 0x2, 0x54, 0x55, 0x5, 0x6, 0x4, 
    0x2, 0x55, 0x58, 0x3, 0x2, 0x2, 0x2, 0x56, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x53, 0x3, 0x2, 0x2, 0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x5, 0x12, 0xa, 0x2, 0x5a, 0x5b, 
    0x5, 0x8, 0x5, 0x2, 0x5b, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5e, 0x3, 
    0x2, 0x2, 0x2, 0x5d, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5c, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x5, 0x1a, 0xe, 
    0x2, 0x60, 0x61, 0x5, 0xa, 0x6, 0x2, 0x61, 0x64, 0x3, 0x2, 0x2, 0x2, 
    0x62, 0x64, 0x3, 0x2, 0x2, 0x2, 0x63, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0xb, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 
    0x7, 0x16, 0x2, 0x2, 0x66, 0x67, 0x7, 0x34, 0x2, 0x2, 0x67, 0x68, 0x7, 
    0x31, 0x2, 0x2, 0x68, 0x69, 0x5, 0xe, 0x8, 0x2, 0x69, 0x6a, 0x7, 0x1c, 
    0x2, 0x2, 0x6a, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x74, 0x5, 0x10, 0x9, 
    0x2, 0x6c, 0x6d, 0x7, 0x3, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x1f, 0x2, 0x2, 
    0x6e, 0x6f, 0x7, 0x35, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x20, 0x2, 0x2, 0x70, 
    0x71, 0x7, 0x10, 0x2, 0x2, 0x71, 0x74, 0x5, 0x10, 0x9, 0x2, 0x72, 0x74, 
    0x7, 0x34, 0x2, 0x2, 0x73, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x73, 0x6c, 0x3, 
    0x2, 0x2, 0x2, 0x73, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x75, 0x76, 0x7, 0xe, 0x2, 0x2, 0x76, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x77, 0x78, 0x5, 0x14, 0xb, 0x2, 0x78, 0x79, 0x5, 0x16, 0xc, 0x2, 
    0x79, 0x7a, 0x7, 0x1b, 0x2, 0x2, 0x7a, 0x7b, 0x5, 0xe, 0x8, 0x2, 0x7b, 
    0x7c, 0x5, 0x18, 0xd, 0x2, 0x7c, 0x7d, 0x7, 0x1c, 0x2, 0x2, 0x7d, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x9, 0x2, 0x2, 0x2, 0x7f, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x80, 0x85, 0x7, 0x34, 0x2, 0x2, 0x81, 0x82, 0x7, 0x34, 
    0x2, 0x2, 0x82, 0x83, 0x7, 0x19, 0x2, 0x2, 0x83, 0x85, 0x5, 0x16, 0xc, 
    0x2, 0x84, 0x80, 0x3, 0x2, 0x2, 0x2, 0x84, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x85, 0x17, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x7, 0x30, 0x2, 0x2, 0x87, 
    0x8a, 0x5, 0x3e, 0x20, 0x2, 0x88, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x89, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0xc, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x34, 
    0x2, 0x2, 0x8d, 0x8e, 0x7, 0x1d, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x1c, 0xf, 
    0x2, 0x8f, 0x90, 0x7, 0x1e, 0x2, 0x2, 0x90, 0x91, 0x5, 0x20, 0x11, 0x2, 
    0x91, 0x92, 0x7, 0x4, 0x2, 0x2, 0x92, 0x93, 0x5, 0x24, 0x13, 0x2, 0x93, 
    0x94, 0x7, 0x8, 0x2, 0x2, 0x94, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 
    0x5, 0x22, 0x12, 0x2, 0x96, 0x97, 0x5, 0x1e, 0x10, 0x2, 0x97, 0x9a, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x99, 0x95, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x9b, 0x9c, 0x7, 0x19, 0x2, 0x2, 0x9c, 0x9d, 0x5, 0x22, 0x12, 
    0x2, 0x9d, 0x9e, 0x5, 0x1e, 0x10, 0x2, 0x9e, 0xa1, 0x3, 0x2, 0x2, 0x2, 
    0x9f, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9b, 0x3, 0x2, 0x2, 0x2, 0xa0, 
    0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 
    0x7, 0x1b, 0x2, 0x2, 0xa3, 0xa6, 0x5, 0xe, 0x8, 0x2, 0xa4, 0xa6, 0x3, 
    0x2, 0x2, 0x2, 0xa5, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa4, 0x3, 0x2, 
    0x2, 0x2, 0xa6, 0x21, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x34, 0x2, 
    0x2, 0xa8, 0xa9, 0x7, 0x1b, 0x2, 0x2, 0xa9, 0xaa, 0x5, 0xe, 0x8, 0x2, 
    0xaa, 0x23, 0x3, 0x2, 0x2, 0x2, 0xab, 0xb0, 0x5, 0x26, 0x14, 0x2, 0xac, 
    0xad, 0x5, 0x26, 0x14, 0x2, 0xad, 0xae, 0x5, 0x24, 0x13, 0x2, 0xae, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xab, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0xb0, 0x25, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x5, 
    0x44, 0x23, 0x2, 0xb2, 0xb3, 0x5, 0x2c, 0x17, 0x2, 0xb3, 0xb4, 0x7, 
    0x30, 0x2, 0x2, 0xb4, 0xb5, 0x5, 0x2e, 0x18, 0x2, 0xb5, 0xb6, 0x7, 0x1c, 
    0x2, 0x2, 0xb6, 0xed, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0xd, 0x2, 
    0x2, 0xb8, 0xb9, 0x5, 0x2e, 0x18, 0x2, 0xb9, 0xba, 0x7, 0x14, 0x2, 0x2, 
    0xba, 0xbb, 0x5, 0x24, 0x13, 0x2, 0xbb, 0xbc, 0x7, 0xa, 0x2, 0x2, 0xbc, 
    0xbd, 0x7, 0x1c, 0x2, 0x2, 0xbd, 0xed, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 
    0x7, 0xd, 0x2, 0x2, 0xbf, 0xc0, 0x5, 0x2e, 0x18, 0x2, 0xc0, 0xc1, 0x7, 
    0x14, 0x2, 0x2, 0xc1, 0xc2, 0x5, 0x24, 0x13, 0x2, 0xc2, 0xc3, 0x7, 0x7, 
    0x2, 0x2, 0xc3, 0xc4, 0x5, 0x24, 0x13, 0x2, 0xc4, 0xc5, 0x7, 0xa, 0x2, 
    0x2, 0xc5, 0xc6, 0x7, 0x1c, 0x2, 0x2, 0xc6, 0xed, 0x3, 0x2, 0x2, 0x2, 
    0xc7, 0xc8, 0x7, 0x18, 0x2, 0x2, 0xc8, 0xc9, 0x5, 0x2e, 0x18, 0x2, 0xc9, 
    0xca, 0x7, 0x6, 0x2, 0x2, 0xca, 0xcb, 0x5, 0x24, 0x13, 0x2, 0xcb, 0xcc, 
    0x7, 0x9, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x1c, 0x2, 0x2, 0xcd, 0xed, 0x3, 
    0x2, 0x2, 0x2, 0xce, 0xcf, 0x7, 0xb, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x34, 
    0x2, 0x2, 0xd0, 0xd1, 0x7, 0x30, 0x2, 0x2, 0xd1, 0xd2, 0x5, 0x2e, 0x18, 
    0x2, 0xd2, 0xd3, 0x7, 0x15, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0x2e, 0x18, 0x2, 
    0xd4, 0xd5, 0x7, 0x6, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x24, 0x13, 0x2, 0xd6, 
    0xd7, 0x7, 0x9, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x1c, 0x2, 0x2, 0xd8, 0xed, 
    0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x5, 0x2a, 0x16, 0x2, 0xda, 0xdb, 0x7, 
    0x34, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x1d, 0x2, 0x2, 0xdc, 0xdd, 0x5, 0x40, 
    0x21, 0x2, 0xdd, 0xde, 0x7, 0x1e, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x1c, 0x2, 
    0x2, 0xdf, 0xed, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x5, 0x2, 0x2, 
    0xe1, 0xed, 0x7, 0x1c, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x12, 0x2, 0x2, 0xe3, 
    0xe4, 0x5, 0x28, 0x15, 0x2, 0xe4, 0xe5, 0x7, 0x1c, 0x2, 0x2, 0xe5, 0xed, 
    0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x7, 0xf, 0x2, 0x2, 0xe7, 0xe8, 0x5, 
    0x4, 0x3, 0x2, 0xe8, 0xe9, 0x7, 0x4, 0x2, 0x2, 0xe9, 0xea, 0x5, 0x24, 
    0x13, 0x2, 0xea, 0xeb, 0x7, 0x8, 0x2, 0x2, 0xeb, 0xed, 0x3, 0x2, 0x2, 
    0x2, 0xec, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xec, 0xb7, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xec, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xec, 
    0xce, 0x3, 0x2, 0x2, 0x2, 0xec, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe0, 
    0x3, 0x2, 0x2, 0x2, 0xec, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe6, 0x3, 
    0x2, 0x2, 0x2, 0xed, 0x27, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf1, 0x5, 0x2e, 
    0x18, 0x2, 0xef, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 
    0x2, 0xf0, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0xf2, 0xf3, 0x5, 0x44, 0x23, 0x2, 0xf3, 0xf4, 0x7, 0x30, 0x2, 0x2, 0xf4, 
    0xf7, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0xf6, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x30, 0x2, 0x2, 0xf9, 0xfa, 0x5, 0x44, 
    0x23, 0x2, 0xfa, 0xfb, 0x5, 0x2c, 0x17, 0x2, 0xfb, 0xfe, 0x3, 0x2, 0x2, 
    0x2, 0xfc, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xf8, 0x3, 0x2, 0x2, 0x2, 
    0xfd, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xff, 
    0x107, 0x5, 0x3e, 0x20, 0x2, 0x100, 0x107, 0x5, 0x44, 0x23, 0x2, 0x101, 
    0x107, 0x5, 0x30, 0x19, 0x2, 0x102, 0x103, 0x7, 0x1d, 0x2, 0x2, 0x103, 
    0x104, 0x5, 0x2e, 0x18, 0x2, 0x104, 0x105, 0x7, 0x1e, 0x2, 0x2, 0x105, 
    0x107, 0x3, 0x2, 0x2, 0x2, 0x106, 0xff, 0x3, 0x2, 0x2, 0x2, 0x106, 0x100, 
    0x3, 0x2, 0x2, 0x2, 0x106, 0x101, 0x3, 0x2, 0x2, 0x2, 0x106, 0x102, 
    0x3, 0x2, 0x2, 0x2, 0x107, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x5, 
    0x32, 0x1a, 0x2, 0x109, 0x31, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10d, 0x5, 
    0x34, 0x1b, 0x2, 0x10b, 0x10c, 0x9, 0x3, 0x2, 0x2, 0x10c, 0x10e, 0x5, 
    0x34, 0x1b, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 
    0x2, 0x2, 0x2, 0x10e, 0x33, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x114, 0x5, 0x36, 
    0x1c, 0x2, 0x110, 0x111, 0x9, 0x4, 0x2, 0x2, 0x111, 0x113, 0x5, 0x36, 
    0x1c, 0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 0x2, 0x113, 0x116, 0x3, 0x2, 
    0x2, 0x2, 0x114, 0x112, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x35, 0x3, 0x2, 0x2, 0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 
    0x2, 0x117, 0x11c, 0x5, 0x38, 0x1d, 0x2, 0x118, 0x119, 0x9, 0x5, 0x2, 
    0x2, 0x119, 0x11b, 0x5, 0x38, 0x1d, 0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 
    0x2, 0x11b, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x124, 0x5, 0x3a, 0x1e, 0x2, 
    0x120, 0x121, 0x9, 0x6, 0x2, 0x2, 0x121, 0x123, 0x5, 0x3a, 0x1e, 0x2, 
    0x122, 0x120, 0x3, 0x2, 0x2, 0x2, 0x123, 0x126, 0x3, 0x2, 0x2, 0x2, 
    0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2, 
    0x125, 0x39, 0x3, 0x2, 0x2, 0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 0x127, 
    0x12c, 0x5, 0x3c, 0x1f, 0x2, 0x128, 0x129, 0x7, 0x27, 0x2, 0x2, 0x129, 
    0x12b, 0x5, 0x3c, 0x1f, 0x2, 0x12a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12b, 
    0x12e, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 
    0x12d, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 
    0x3, 0x2, 0x2, 0x2, 0x12f, 0x136, 0x5, 0x3e, 0x20, 0x2, 0x130, 0x136, 
    0x5, 0x44, 0x23, 0x2, 0x131, 0x132, 0x7, 0x1d, 0x2, 0x2, 0x132, 0x133, 
    0x5, 0x2e, 0x18, 0x2, 0x133, 0x134, 0x7, 0x1e, 0x2, 0x2, 0x134, 0x136, 
    0x3, 0x2, 0x2, 0x2, 0x135, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x135, 0x130, 
    0x3, 0x2, 0x2, 0x2, 0x135, 0x131, 0x3, 0x2, 0x2, 0x2, 0x136, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x137, 0x138, 0x7, 0x35, 0x2, 0x2, 0x138, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x139, 0x13a, 0x5, 0x2e, 0x18, 0x2, 0x13a, 0x13b, 0x5, 
    0x42, 0x22, 0x2, 0x13b, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13e, 0x3, 
    0x2, 0x2, 0x2, 0x13d, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13c, 0x3, 
    0x2, 0x2, 0x2, 0x13e, 0x41, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x7, 0x19, 
    0x2, 0x2, 0x140, 0x141, 0x5, 0x2e, 0x18, 0x2, 0x141, 0x142, 0x5, 0x42, 
    0x22, 0x2, 0x142, 0x145, 0x3, 0x2, 0x2, 0x2, 0x143, 0x145, 0x3, 0x2, 
    0x2, 0x2, 0x144, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x144, 0x143, 0x3, 0x2, 
    0x2, 0x2, 0x145, 0x43, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x7, 0x34, 
    0x2, 0x2, 0x147, 0x148, 0x5, 0x46, 0x24, 0x2, 0x148, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x149, 0x14a, 0x7, 0x1f, 0x2, 0x2, 0x14a, 0x14b, 0x5, 0x2e, 
    0x18, 0x2, 0x14b, 0x14c, 0x7, 0x20, 0x2, 0x2, 0x14c, 0x14f, 0x3, 0x2, 
    0x2, 0x2, 0x14d, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x149, 0x3, 0x2, 
    0x2, 0x2, 0x14e, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x47, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x57, 0x5d, 0x63, 0x73, 0x84, 0x89, 0x99, 0xa0, 0xa5, 0xaf, 
    0xec, 0xf0, 0xf6, 0xfd, 0x106, 0x10d, 0x114, 0x11c, 0x124, 0x12c, 0x135, 
    0x13d, 0x144, 0x14e, 
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
