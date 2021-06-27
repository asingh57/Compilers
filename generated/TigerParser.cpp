
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
    setState(110);
    match(TigerParser::PROGRAM);
    setState(111);
    match(TigerParser::ID);
    setState(112);
    match(TigerParser::LET);
    setState(113);
    declaration_segment();
    setState(114);
    match(TigerParser::BEGIN);
    setState(115);
    funct_list();
    setState(116);
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
    setState(118);
    type_declaration_list();
    setState(119);
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
    setState(125);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(121);
        type_declaration();
        setState(122);
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
    setState(131);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::STATIC:
      case TigerParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(127);
        var_declaration();
        setState(128);
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
    setState(137);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::FUNCTION: {
        enterOuterAlt(_localctx, 1);
        setState(133);
        funct();
        setState(134);
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
    setState(139);
    match(TigerParser::TYPE);
    setState(140);
    match(TigerParser::ID);
    setState(141);
    match(TigerParser::TASSIGN);
    setState(142);
    type();
    setState(143);
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
    setState(153);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(145);
        type_id();
        break;
      }

      case TigerParser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(146);
        match(TigerParser::ARRAY);
        setState(147);
        match(TigerParser::OPENBRACK);
        setState(148);
        match(TigerParser::INTLIT);
        setState(149);
        match(TigerParser::CLOSEBRACK);
        setState(150);
        match(TigerParser::OF);
        setState(151);
        type_id();
        break;
      }

      case TigerParser::ID: {
        enterOuterAlt(_localctx, 3);
        setState(152);
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
    setState(155);
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
    setState(157);
    storage_class();
    setState(158);
    id_list();
    setState(159);
    match(TigerParser::COLON);
    setState(160);
    type();
    setState(161);
    optional_init();
    setState(162);
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
    setState(164);
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
    setState(170);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(166);
      match(TigerParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(167);
      match(TigerParser::ID);
      setState(168);
      match(TigerParser::COMMA);
      setState(169);
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
    setState(175);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::ASSIGN: {
        enterOuterAlt(_localctx, 1);
        setState(172);
        match(TigerParser::ASSIGN);
        setState(173);
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
    setState(177);
    match(TigerParser::FUNCTION);
    setState(178);
    match(TigerParser::ID);
    setState(179);
    match(TigerParser::OPENPAREN);
    setState(180);
    param_list();
    setState(181);
    match(TigerParser::CLOSEPAREN);
    setState(182);
    ret_type();
    setState(183);
    match(TigerParser::BEGIN);
    setState(184);
    stat_seq_func();
    setState(185);
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
    setState(191);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(187);
        param();
        setState(188);
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
    setState(198);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(193);
        match(TigerParser::COMMA);
        setState(194);
        param();
        setState(195);
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
    setState(203);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::COLON: {
        enterOuterAlt(_localctx, 1);
        setState(200);
        match(TigerParser::COLON);
        setState(201);
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
    setState(205);
    match(TigerParser::ID);
    setState(206);
    match(TigerParser::COLON);
    setState(207);
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
    setState(209);
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
    setState(215);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(211);
      stat();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(212);
      stat();
      setState(213);
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
    setState(226);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(217);
      assignment_stat();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(218);
      if_stat();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(219);
      if_else_stat();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(220);
      while_stat();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(221);
      for_stat();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(222);
      fncall_stat();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(223);
      break_stat();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(224);
      return_stat();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(225);
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
    setState(228);
    lvalue();
    setState(229);
    l_tail();
    setState(230);
    match(TigerParser::ASSIGN);
    setState(231);
    expr();
    setState(232);
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

TigerParser::If_stat_lhsContext* TigerParser::If_statContext::if_stat_lhs() {
  return getRuleContext<TigerParser::If_stat_lhsContext>(0);
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
    setState(234);
    if_stat_lhs();
    setState(235);
    match(TigerParser::ENDIF);
    setState(236);
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

TigerParser::If_stat_lhsContext* TigerParser::If_else_statContext::if_stat_lhs() {
  return getRuleContext<TigerParser::If_stat_lhsContext>(0);
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
    setState(238);
    if_stat_lhs();
    setState(239);
    match(TigerParser::ELSE);
    setState(240);
    stat_seq_else();
    setState(241);
    match(TigerParser::ENDIF);
    setState(242);
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
    setState(244);
    match(TigerParser::WHILE);
    setState(245);
    expr();
    setState(246);
    match(TigerParser::DO);
    setState(247);
    stat_seq_while();
    setState(248);
    match(TigerParser::ENDDO);
    setState(249);
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
    setState(251);
    match(TigerParser::FOR);
    setState(252);
    match(TigerParser::ID);
    setState(253);
    match(TigerParser::ASSIGN);
    setState(254);
    expr();
    setState(255);
    match(TigerParser::TO);
    setState(256);
    expr();
    setState(257);
    match(TigerParser::DO);
    setState(258);
    stat_seq_for();
    setState(259);
    match(TigerParser::ENDDO);
    setState(260);
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
    setState(262);
    opt_prefix();
    setState(263);
    match(TigerParser::ID);
    setState(264);
    match(TigerParser::OPENPAREN);
    setState(265);
    expr_list();
    setState(266);
    match(TigerParser::CLOSEPAREN);
    setState(267);
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
    setState(269);
    match(TigerParser::BREAK);
    setState(270);
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
    setState(272);
    match(TigerParser::RETURN);
    setState(273);
    opt_return();
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
    setState(276);
    match(TigerParser::LET);
    setState(277);
    declaration_segment();
    setState(278);
    match(TigerParser::BEGIN);
    setState(279);
    stat_seq();
    setState(280);
    match(TigerParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_stat_lhsContext ------------------------------------------------------------------

TigerParser::If_stat_lhsContext::If_stat_lhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TigerParser::If_stat_lhsContext::IF() {
  return getToken(TigerParser::IF, 0);
}

TigerParser::ExprContext* TigerParser::If_stat_lhsContext::expr() {
  return getRuleContext<TigerParser::ExprContext>(0);
}

tree::TerminalNode* TigerParser::If_stat_lhsContext::THEN() {
  return getToken(TigerParser::THEN, 0);
}

TigerParser::Stat_seq_thenContext* TigerParser::If_stat_lhsContext::stat_seq_then() {
  return getRuleContext<TigerParser::Stat_seq_thenContext>(0);
}


size_t TigerParser::If_stat_lhsContext::getRuleIndex() const {
  return TigerParser::RuleIf_stat_lhs;
}

void TigerParser::If_stat_lhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_stat_lhs(this);
}

void TigerParser::If_stat_lhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_stat_lhs(this);
}

TigerParser::If_stat_lhsContext* TigerParser::if_stat_lhs() {
  If_stat_lhsContext *_localctx = _tracker.createInstance<If_stat_lhsContext>(_ctx, getState());
  enterRule(_localctx, 58, TigerParser::RuleIf_stat_lhs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    match(TigerParser::IF);
    setState(283);
    expr();
    setState(284);
    match(TigerParser::THEN);
    setState(285);
    stat_seq_then();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stat_seq_thenContext ------------------------------------------------------------------

TigerParser::Stat_seq_thenContext::Stat_seq_thenContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TigerParser::Stat_seqContext* TigerParser::Stat_seq_thenContext::stat_seq() {
  return getRuleContext<TigerParser::Stat_seqContext>(0);
}


size_t TigerParser::Stat_seq_thenContext::getRuleIndex() const {
  return TigerParser::RuleStat_seq_then;
}

void TigerParser::Stat_seq_thenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat_seq_then(this);
}

void TigerParser::Stat_seq_thenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TigerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat_seq_then(this);
}

TigerParser::Stat_seq_thenContext* TigerParser::stat_seq_then() {
  Stat_seq_thenContext *_localctx = _tracker.createInstance<Stat_seq_thenContext>(_ctx, getState());
  enterRule(_localctx, 60, TigerParser::RuleStat_seq_then);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
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
  enterRule(_localctx, 62, TigerParser::RuleStat_seq_else);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
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
  enterRule(_localctx, 64, TigerParser::RuleStat_seq_while);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
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
  enterRule(_localctx, 66, TigerParser::RuleStat_seq_for);

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
  enterRule(_localctx, 68, TigerParser::RuleOpt_return);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(297);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(295);
      expr();
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
  enterRule(_localctx, 70, TigerParser::RuleOpt_prefix);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(303);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(299);
      lvalue();
      setState(300);
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
  enterRule(_localctx, 72, TigerParser::RuleL_tail);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(310);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(305);
      match(TigerParser::ASSIGN);
      setState(306);
      lvalue();
      setState(307);
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
  enterRule(_localctx, 74, TigerParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(314);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(312);
      expr_no_op();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(313);
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
  enterRule(_localctx, 76, TigerParser::RuleUnambiguous_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
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
  enterRule(_localctx, 78, TigerParser::RuleLogical_op_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    compare_op_expr();
    setState(319);
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
  enterRule(_localctx, 80, TigerParser::RuleLogical_op_expr_ext);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(326);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::AND:
      case TigerParser::OR: {
        enterOuterAlt(_localctx, 1);
        setState(321);
        _la = _input->LA(1);
        if (!(_la == TigerParser::AND

        || _la == TigerParser::OR)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(322);
        compare_op_expr();
        setState(323);
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
  enterRule(_localctx, 82, TigerParser::RuleCompare_op_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    add_op_expr();
    setState(329);
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
  enterRule(_localctx, 84, TigerParser::RuleCompare_op_expr_ext);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(336);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::EQUAL:
      case TigerParser::NEQUAL:
      case TigerParser::LESS:
      case TigerParser::GREAT:
      case TigerParser::LESSEQ:
      case TigerParser::GREATEQ: {
        enterOuterAlt(_localctx, 1);
        setState(331);
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
        setState(332);
        add_op_expr();
        setState(333);
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
  enterRule(_localctx, 86, TigerParser::RuleAdd_op_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    mult_op_expr();
    setState(339);
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
  enterRule(_localctx, 88, TigerParser::RuleAdd_op_expr_ext);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(346);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::PLUS:
      case TigerParser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(341);
        _la = _input->LA(1);
        if (!(_la == TigerParser::PLUS

        || _la == TigerParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(342);
        mult_op_expr();
        setState(343);
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
  enterRule(_localctx, 90, TigerParser::RuleMult_op_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
    pow_op_expr();
    setState(349);
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
  enterRule(_localctx, 92, TigerParser::RuleMult_op_expr_ext);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(356);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::MULT:
      case TigerParser::DIV: {
        enterOuterAlt(_localctx, 1);
        setState(351);
        _la = _input->LA(1);
        if (!(_la == TigerParser::MULT

        || _la == TigerParser::DIV)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(352);
        pow_op_expr();
        setState(353);
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

TigerParser::Pow_op_expr_extContext* TigerParser::Pow_op_exprContext::pow_op_expr_ext() {
  return getRuleContext<TigerParser::Pow_op_expr_extContext>(0);
}

TigerParser::Expr_no_opContext* TigerParser::Pow_op_exprContext::expr_no_op() {
  return getRuleContext<TigerParser::Expr_no_opContext>(0);
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
  enterRule(_localctx, 94, TigerParser::RulePow_op_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(358);
    pow_op_expr_ext(0);
    setState(359);
    expr_no_op();
   
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

TigerParser::Pow_op_expr_extContext* TigerParser::Pow_op_expr_extContext::pow_op_expr_ext() {
  return getRuleContext<TigerParser::Pow_op_expr_extContext>(0);
}

TigerParser::Expr_no_opContext* TigerParser::Pow_op_expr_extContext::expr_no_op() {
  return getRuleContext<TigerParser::Expr_no_opContext>(0);
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
   return pow_op_expr_ext(0);
}

TigerParser::Pow_op_expr_extContext* TigerParser::pow_op_expr_ext(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TigerParser::Pow_op_expr_extContext *_localctx = _tracker.createInstance<Pow_op_expr_extContext>(_ctx, parentState);
  TigerParser::Pow_op_expr_extContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 96;
  enterRecursionRule(_localctx, 96, TigerParser::RulePow_op_expr_ext, precedence);

    

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
    _ctx->stop = _input->LT(-1);
    setState(368);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Pow_op_expr_extContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RulePow_op_expr_ext);
        setState(362);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(363);
        expr_no_op();

        setState(364);
        match(TigerParser::POW); 
      }
      setState(370);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
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
  enterRule(_localctx, 98, TigerParser::RuleExpr_no_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(377);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::INTLIT: {
        enterOuterAlt(_localctx, 1);
        setState(371);
        constant();
        break;
      }

      case TigerParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(372);
        lvalue();
        break;
      }

      case TigerParser::OPENPAREN: {
        enterOuterAlt(_localctx, 3);
        setState(373);
        match(TigerParser::OPENPAREN);
        setState(374);
        expr();
        setState(375);
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
  enterRule(_localctx, 100, TigerParser::RuleConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379);
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
  enterRule(_localctx, 102, TigerParser::RuleExpr_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(385);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(381);
      expr();
      setState(382);
      expr_list_tail();
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
  enterRule(_localctx, 104, TigerParser::RuleExpr_list_tail);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(392);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(387);
        match(TigerParser::COMMA);
        setState(388);
        expr();
        setState(389);
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
  enterRule(_localctx, 106, TigerParser::RuleLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    match(TigerParser::ID);
    setState(395);
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
  enterRule(_localctx, 108, TigerParser::RuleLvalue_tail);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(402);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TigerParser::OPENBRACK: {
        enterOuterAlt(_localctx, 1);
        setState(397);
        match(TigerParser::OPENBRACK);
        setState(398);
        expr();
        setState(399);
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

bool TigerParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 48: return pow_op_expr_extSempred(dynamic_cast<Pow_op_expr_extContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TigerParser::pow_op_expr_extSempred(Pow_op_expr_extContext *_localctx, size_t predicateIndex) {
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
  "ret_type", "param", "stat_seq_func", "stat_seq", "stat", "assignment_stat", 
  "if_stat", "if_else_stat", "while_stat", "for_stat", "fncall_stat", "break_stat", 
  "return_stat", "sub_scope_stat", "if_stat_lhs", "stat_seq_then", "stat_seq_else", 
  "stat_seq_while", "stat_seq_for", "opt_return", "opt_prefix", "l_tail", 
  "expr", "unambiguous_expr", "logical_op_expr", "logical_op_expr_ext", 
  "compare_op_expr", "compare_op_expr_ext", "add_op_expr", "add_op_expr_ext", 
  "mult_op_expr", "mult_op_expr_ext", "pow_op_expr", "pow_op_expr_ext", 
  "expr_no_op", "constant", "expr_list", "expr_list_tail", "lvalue", "lvalue_tail"
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
    0x3, 0x35, 0x197, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0x80, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x86, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x8c, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x9c, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xad, 
    0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xb2, 0xa, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0xc2, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x5, 0x10, 0xc9, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 
    0x11, 0xce, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 
    0xda, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xe5, 0xa, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x12c, 0xa, 0x24, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x132, 0xa, 0x25, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x139, 
    0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x13d, 0xa, 0x27, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
    0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x149, 0xa, 0x2a, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
    0x2c, 0x5, 0x2c, 0x153, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x15d, 
    0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 
    0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x167, 0xa, 0x30, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x7, 0x32, 0x171, 0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 0x174, 0xb, 
    0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x5, 0x33, 0x17c, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x184, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x18b, 0xa, 0x36, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
    0x38, 0x5, 0x38, 0x195, 0xa, 0x38, 0x3, 0x38, 0x2, 0x3, 0x62, 0x39, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
    0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 
    0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 
    0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x2, 0x7, 0x4, 0x2, 0x13, 0x13, 
    0x17, 0x17, 0x3, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x28, 0x2d, 0x3, 0x2, 0x23, 
    0x24, 0x3, 0x2, 0x25, 0x26, 0x2, 0x180, 0x2, 0x70, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x78, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x8, 0x85, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x8b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x8d, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x10, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x14, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xac, 0x3, 0x2, 0x2, 0x2, 0x18, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xb3, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xc8, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x22, 0xcf, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x26, 0xd9, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xe6, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0xec, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xf0, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x32, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x108, 0x3, 0x2, 0x2, 0x2, 0x36, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x38, 0x112, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x116, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x11c, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x121, 0x3, 0x2, 0x2, 0x2, 0x40, 0x123, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x125, 0x3, 0x2, 0x2, 0x2, 0x44, 0x127, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x48, 0x131, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x13e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x140, 0x3, 0x2, 0x2, 0x2, 0x52, 0x148, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x56, 0x152, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x154, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x15c, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x166, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x168, 0x3, 0x2, 0x2, 0x2, 0x62, 0x16b, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x66, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x183, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x18c, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x194, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 
    0x11, 0x2, 0x2, 0x71, 0x72, 0x7, 0x34, 0x2, 0x2, 0x72, 0x73, 0x7, 0xf, 
    0x2, 0x2, 0x73, 0x74, 0x5, 0x4, 0x3, 0x2, 0x74, 0x75, 0x7, 0x4, 0x2, 
    0x2, 0x75, 0x76, 0x5, 0xa, 0x6, 0x2, 0x76, 0x77, 0x7, 0x8, 0x2, 0x2, 
    0x77, 0x3, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x5, 0x6, 0x4, 0x2, 0x79, 
    0x7a, 0x5, 0x8, 0x5, 0x2, 0x7a, 0x5, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 
    0x5, 0xc, 0x7, 0x2, 0x7c, 0x7d, 0x5, 0x6, 0x4, 0x2, 0x7d, 0x80, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x7f, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x82, 0x5, 0x12, 0xa, 0x2, 0x82, 0x83, 0x5, 0x8, 0x5, 0x2, 
    0x83, 0x86, 0x3, 0x2, 0x2, 0x2, 0x84, 0x86, 0x3, 0x2, 0x2, 0x2, 0x85, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x85, 0x84, 0x3, 0x2, 0x2, 0x2, 0x86, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x5, 0x1a, 0xe, 0x2, 0x88, 0x89, 0x5, 
    0xa, 0x6, 0x2, 0x89, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8c, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8a, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x16, 0x2, 0x2, 
    0x8e, 0x8f, 0x7, 0x34, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x31, 0x2, 0x2, 0x90, 
    0x91, 0x5, 0xe, 0x8, 0x2, 0x91, 0x92, 0x7, 0x1c, 0x2, 0x2, 0x92, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x9c, 0x5, 0x10, 0x9, 0x2, 0x94, 0x95, 0x7, 
    0x3, 0x2, 0x2, 0x95, 0x96, 0x7, 0x1f, 0x2, 0x2, 0x96, 0x97, 0x7, 0x35, 
    0x2, 0x2, 0x97, 0x98, 0x7, 0x20, 0x2, 0x2, 0x98, 0x99, 0x7, 0x10, 0x2, 
    0x2, 0x99, 0x9c, 0x5, 0x10, 0x9, 0x2, 0x9a, 0x9c, 0x7, 0x34, 0x2, 0x2, 
    0x9b, 0x93, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x94, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0xf, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 
    0x7, 0xe, 0x2, 0x2, 0x9e, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x5, 
    0x14, 0xb, 0x2, 0xa0, 0xa1, 0x5, 0x16, 0xc, 0x2, 0xa1, 0xa2, 0x7, 0x1b, 
    0x2, 0x2, 0xa2, 0xa3, 0x5, 0xe, 0x8, 0x2, 0xa3, 0xa4, 0x5, 0x18, 0xd, 
    0x2, 0xa4, 0xa5, 0x7, 0x1c, 0x2, 0x2, 0xa5, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0xa7, 0x9, 0x2, 0x2, 0x2, 0xa7, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0xad, 0x7, 0x34, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x34, 0x2, 0x2, 0xaa, 0xab, 
    0x7, 0x19, 0x2, 0x2, 0xab, 0xad, 0x5, 0x16, 0xc, 0x2, 0xac, 0xa8, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xad, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xaf, 0x7, 0x30, 0x2, 0x2, 0xaf, 0xb2, 0x5, 0x66, 0x34, 
    0x2, 0xb0, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x19, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0xb4, 0x7, 0xc, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0x34, 0x2, 0x2, 0xb5, 0xb6, 
    0x7, 0x1d, 0x2, 0x2, 0xb6, 0xb7, 0x5, 0x1c, 0xf, 0x2, 0xb7, 0xb8, 0x7, 
    0x1e, 0x2, 0x2, 0xb8, 0xb9, 0x5, 0x20, 0x11, 0x2, 0xb9, 0xba, 0x7, 0x4, 
    0x2, 0x2, 0xba, 0xbb, 0x5, 0x24, 0x13, 0x2, 0xbb, 0xbc, 0x7, 0x8, 0x2, 
    0x2, 0xbc, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x5, 0x22, 0x12, 0x2, 
    0xbe, 0xbf, 0x5, 0x1e, 0x10, 0x2, 0xbf, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc0, 
    0xc2, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0xc2, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x7, 
    0x19, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x22, 0x12, 0x2, 0xc5, 0xc6, 0x5, 0x1e, 
    0x10, 0x2, 0xc6, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc9, 0x3, 0x2, 0x2, 
    0x2, 0xc8, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc7, 0x3, 0x2, 0x2, 0x2, 
    0xc9, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x1b, 0x2, 0x2, 0xcb, 
    0xce, 0x5, 0xe, 0x8, 0x2, 0xcc, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xca, 
    0x3, 0x2, 0x2, 0x2, 0xcd, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x34, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x1b, 
    0x2, 0x2, 0xd1, 0xd2, 0x5, 0xe, 0x8, 0x2, 0xd2, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0xd3, 0xd4, 0x5, 0x26, 0x14, 0x2, 0xd4, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0xd5, 0xda, 0x5, 0x28, 0x15, 0x2, 0xd6, 0xd7, 0x5, 0x28, 0x15, 0x2, 
    0xd7, 0xd8, 0x5, 0x26, 0x14, 0x2, 0xd8, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xd5, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xda, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0xdb, 0xe5, 0x5, 0x2a, 0x16, 0x2, 0xdc, 0xe5, 0x5, 
    0x2c, 0x17, 0x2, 0xdd, 0xe5, 0x5, 0x2e, 0x18, 0x2, 0xde, 0xe5, 0x5, 
    0x30, 0x19, 0x2, 0xdf, 0xe5, 0x5, 0x32, 0x1a, 0x2, 0xe0, 0xe5, 0x5, 
    0x34, 0x1b, 0x2, 0xe1, 0xe5, 0x5, 0x36, 0x1c, 0x2, 0xe2, 0xe5, 0x5, 
    0x38, 0x1d, 0x2, 0xe3, 0xe5, 0x5, 0x3a, 0x1e, 0x2, 0xe4, 0xdb, 0x3, 
    0x2, 0x2, 0x2, 0xe4, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xdd, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xdf, 0x3, 0x2, 0x2, 
    0x2, 0xe4, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe5, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0x6c, 0x37, 0x2, 0xe7, 0xe8, 
    0x5, 0x4a, 0x26, 0x2, 0xe8, 0xe9, 0x7, 0x30, 0x2, 0x2, 0xe9, 0xea, 0x5, 
    0x4c, 0x27, 0x2, 0xea, 0xeb, 0x7, 0x1c, 0x2, 0x2, 0xeb, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0xec, 0xed, 0x5, 0x3c, 0x1f, 0x2, 0xed, 0xee, 0x7, 0xa, 0x2, 
    0x2, 0xee, 0xef, 0x7, 0x1c, 0x2, 0x2, 0xef, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xf1, 0x5, 0x3c, 0x1f, 0x2, 0xf1, 0xf2, 0x7, 0x7, 0x2, 0x2, 0xf2, 
    0xf3, 0x5, 0x40, 0x21, 0x2, 0xf3, 0xf4, 0x7, 0xa, 0x2, 0x2, 0xf4, 0xf5, 
    0x7, 0x1c, 0x2, 0x2, 0xf5, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x7, 
    0x18, 0x2, 0x2, 0xf7, 0xf8, 0x5, 0x4c, 0x27, 0x2, 0xf8, 0xf9, 0x7, 0x6, 
    0x2, 0x2, 0xf9, 0xfa, 0x5, 0x42, 0x22, 0x2, 0xfa, 0xfb, 0x7, 0x9, 0x2, 
    0x2, 0xfb, 0xfc, 0x7, 0x1c, 0x2, 0x2, 0xfc, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0xfd, 0xfe, 0x7, 0xb, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x34, 0x2, 0x2, 0xff, 
    0x100, 0x7, 0x30, 0x2, 0x2, 0x100, 0x101, 0x5, 0x4c, 0x27, 0x2, 0x101, 
    0x102, 0x7, 0x15, 0x2, 0x2, 0x102, 0x103, 0x5, 0x4c, 0x27, 0x2, 0x103, 
    0x104, 0x7, 0x6, 0x2, 0x2, 0x104, 0x105, 0x5, 0x44, 0x23, 0x2, 0x105, 
    0x106, 0x7, 0x9, 0x2, 0x2, 0x106, 0x107, 0x7, 0x1c, 0x2, 0x2, 0x107, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x5, 0x48, 0x25, 0x2, 0x109, 
    0x10a, 0x7, 0x34, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x1d, 0x2, 0x2, 0x10b, 
    0x10c, 0x5, 0x68, 0x35, 0x2, 0x10c, 0x10d, 0x7, 0x1e, 0x2, 0x2, 0x10d, 
    0x10e, 0x7, 0x1c, 0x2, 0x2, 0x10e, 0x35, 0x3, 0x2, 0x2, 0x2, 0x10f, 
    0x110, 0x7, 0x5, 0x2, 0x2, 0x110, 0x111, 0x7, 0x1c, 0x2, 0x2, 0x111, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x7, 0x12, 0x2, 0x2, 0x113, 
    0x114, 0x5, 0x46, 0x24, 0x2, 0x114, 0x115, 0x7, 0x1c, 0x2, 0x2, 0x115, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x7, 0xf, 0x2, 0x2, 0x117, 0x118, 
    0x5, 0x4, 0x3, 0x2, 0x118, 0x119, 0x7, 0x4, 0x2, 0x2, 0x119, 0x11a, 
    0x5, 0x26, 0x14, 0x2, 0x11a, 0x11b, 0x7, 0x8, 0x2, 0x2, 0x11b, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0xd, 0x2, 0x2, 0x11d, 0x11e, 
    0x5, 0x4c, 0x27, 0x2, 0x11e, 0x11f, 0x7, 0x14, 0x2, 0x2, 0x11f, 0x120, 
    0x5, 0x3e, 0x20, 0x2, 0x120, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 
    0x5, 0x26, 0x14, 0x2, 0x122, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 
    0x5, 0x26, 0x14, 0x2, 0x124, 0x41, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 
    0x5, 0x26, 0x14, 0x2, 0x126, 0x43, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 
    0x5, 0x26, 0x14, 0x2, 0x128, 0x45, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12c, 
    0x5, 0x4c, 0x27, 0x2, 0x12a, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 
    0x3, 0x2, 0x2, 0x2, 0x12b, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x12d, 0x12e, 0x5, 0x6c, 0x37, 0x2, 0x12e, 0x12f, 0x7, 
    0x30, 0x2, 0x2, 0x12f, 0x132, 0x3, 0x2, 0x2, 0x2, 0x130, 0x132, 0x3, 
    0x2, 0x2, 0x2, 0x131, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x131, 0x130, 0x3, 
    0x2, 0x2, 0x2, 0x132, 0x49, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x7, 0x30, 
    0x2, 0x2, 0x134, 0x135, 0x5, 0x6c, 0x37, 0x2, 0x135, 0x136, 0x5, 0x4a, 
    0x26, 0x2, 0x136, 0x139, 0x3, 0x2, 0x2, 0x2, 0x137, 0x139, 0x3, 0x2, 
    0x2, 0x2, 0x138, 0x133, 0x3, 0x2, 0x2, 0x2, 0x138, 0x137, 0x3, 0x2, 
    0x2, 0x2, 0x139, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13d, 0x5, 0x64, 
    0x33, 0x2, 0x13b, 0x13d, 0x5, 0x4e, 0x28, 0x2, 0x13c, 0x13a, 0x3, 0x2, 
    0x2, 0x2, 0x13c, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x13e, 0x13f, 0x5, 0x50, 0x29, 0x2, 0x13f, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x140, 0x141, 0x5, 0x54, 0x2b, 0x2, 0x141, 0x142, 0x5, 0x52, 0x2a, 
    0x2, 0x142, 0x51, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x9, 0x3, 0x2, 0x2, 
    0x144, 0x145, 0x5, 0x54, 0x2b, 0x2, 0x145, 0x146, 0x5, 0x52, 0x2a, 0x2, 
    0x146, 0x149, 0x3, 0x2, 0x2, 0x2, 0x147, 0x149, 0x3, 0x2, 0x2, 0x2, 
    0x148, 0x143, 0x3, 0x2, 0x2, 0x2, 0x148, 0x147, 0x3, 0x2, 0x2, 0x2, 
    0x149, 0x53, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x5, 0x58, 0x2d, 0x2, 
    0x14b, 0x14c, 0x5, 0x56, 0x2c, 0x2, 0x14c, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x14d, 0x14e, 0x9, 0x4, 0x2, 0x2, 0x14e, 0x14f, 0x5, 0x58, 0x2d, 0x2, 
    0x14f, 0x150, 0x5, 0x56, 0x2c, 0x2, 0x150, 0x153, 0x3, 0x2, 0x2, 0x2, 
    0x151, 0x153, 0x3, 0x2, 0x2, 0x2, 0x152, 0x14d, 0x3, 0x2, 0x2, 0x2, 
    0x152, 0x151, 0x3, 0x2, 0x2, 0x2, 0x153, 0x57, 0x3, 0x2, 0x2, 0x2, 0x154, 
    0x155, 0x5, 0x5c, 0x2f, 0x2, 0x155, 0x156, 0x5, 0x5a, 0x2e, 0x2, 0x156, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x157, 0x158, 0x9, 0x5, 0x2, 0x2, 0x158, 0x159, 
    0x5, 0x5c, 0x2f, 0x2, 0x159, 0x15a, 0x5, 0x5a, 0x2e, 0x2, 0x15a, 0x15d, 
    0x3, 0x2, 0x2, 0x2, 0x15b, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x157, 
    0x3, 0x2, 0x2, 0x2, 0x15c, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x15e, 0x15f, 0x5, 0x60, 0x31, 0x2, 0x15f, 0x160, 0x5, 
    0x5e, 0x30, 0x2, 0x160, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x9, 
    0x6, 0x2, 0x2, 0x162, 0x163, 0x5, 0x60, 0x31, 0x2, 0x163, 0x164, 0x5, 
    0x5e, 0x30, 0x2, 0x164, 0x167, 0x3, 0x2, 0x2, 0x2, 0x165, 0x167, 0x3, 
    0x2, 0x2, 0x2, 0x166, 0x161, 0x3, 0x2, 0x2, 0x2, 0x166, 0x165, 0x3, 
    0x2, 0x2, 0x2, 0x167, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x5, 0x62, 
    0x32, 0x2, 0x169, 0x16a, 0x5, 0x64, 0x33, 0x2, 0x16a, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x16b, 0x172, 0x8, 0x32, 0x1, 0x2, 0x16c, 0x16d, 0xc, 0x4, 
    0x2, 0x2, 0x16d, 0x16e, 0x5, 0x64, 0x33, 0x2, 0x16e, 0x16f, 0x7, 0x27, 
    0x2, 0x2, 0x16f, 0x171, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16c, 0x3, 0x2, 
    0x2, 0x2, 0x171, 0x174, 0x3, 0x2, 0x2, 0x2, 0x172, 0x170, 0x3, 0x2, 
    0x2, 0x2, 0x172, 0x173, 0x3, 0x2, 0x2, 0x2, 0x173, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x174, 0x172, 0x3, 0x2, 0x2, 0x2, 0x175, 0x17c, 0x5, 0x66, 0x34, 
    0x2, 0x176, 0x17c, 0x5, 0x6c, 0x37, 0x2, 0x177, 0x178, 0x7, 0x1d, 0x2, 
    0x2, 0x178, 0x179, 0x5, 0x4c, 0x27, 0x2, 0x179, 0x17a, 0x7, 0x1e, 0x2, 
    0x2, 0x17a, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x175, 0x3, 0x2, 0x2, 
    0x2, 0x17b, 0x176, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x177, 0x3, 0x2, 0x2, 
    0x2, 0x17c, 0x65, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17e, 0x7, 0x35, 0x2, 
    0x2, 0x17e, 0x67, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x180, 0x5, 0x4c, 0x27, 
    0x2, 0x180, 0x181, 0x5, 0x6a, 0x36, 0x2, 0x181, 0x184, 0x3, 0x2, 0x2, 
    0x2, 0x182, 0x184, 0x3, 0x2, 0x2, 0x2, 0x183, 0x17f, 0x3, 0x2, 0x2, 
    0x2, 0x183, 0x182, 0x3, 0x2, 0x2, 0x2, 0x184, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x185, 0x186, 0x7, 0x19, 0x2, 0x2, 0x186, 0x187, 0x5, 0x4c, 0x27, 0x2, 
    0x187, 0x188, 0x5, 0x6a, 0x36, 0x2, 0x188, 0x18b, 0x3, 0x2, 0x2, 0x2, 
    0x189, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x185, 0x3, 0x2, 0x2, 0x2, 
    0x18a, 0x189, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x18c, 
    0x18d, 0x7, 0x34, 0x2, 0x2, 0x18d, 0x18e, 0x5, 0x6e, 0x38, 0x2, 0x18e, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x7, 0x1f, 0x2, 0x2, 0x190, 
    0x191, 0x5, 0x4c, 0x27, 0x2, 0x191, 0x192, 0x7, 0x20, 0x2, 0x2, 0x192, 
    0x195, 0x3, 0x2, 0x2, 0x2, 0x193, 0x195, 0x3, 0x2, 0x2, 0x2, 0x194, 
    0x18f, 0x3, 0x2, 0x2, 0x2, 0x194, 0x193, 0x3, 0x2, 0x2, 0x2, 0x195, 
    0x6f, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x7f, 0x85, 0x8b, 0x9b, 0xac, 0xb1, 
    0xc1, 0xc8, 0xcd, 0xd9, 0xe4, 0x12b, 0x131, 0x138, 0x13c, 0x148, 0x152, 
    0x15c, 0x166, 0x172, 0x17b, 0x183, 0x18a, 0x194, 
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
