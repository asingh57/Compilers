
// Generated from Tiger.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "TigerParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by TigerParser.
 */
class  TigerListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterR(TigerParser::RContext *ctx) = 0;
  virtual void exitR(TigerParser::RContext *ctx) = 0;


};

