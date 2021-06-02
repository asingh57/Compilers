
// Generated from Tiger.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "TigerListener.h"


/**
 * This class provides an empty implementation of TigerListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  TigerBaseListener : public TigerListener {
public:

  virtual void enterR(TigerParser::RContext * /*ctx*/) override { }
  virtual void exitR(TigerParser::RContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

