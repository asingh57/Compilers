
// Generated from Tiger.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "TigerParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by TigerParser.
 */
class  TigerListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterTiger_program(TigerParser::Tiger_programContext *ctx) = 0;
  virtual void exitTiger_program(TigerParser::Tiger_programContext *ctx) = 0;

  virtual void enterDeclaration_segment(TigerParser::Declaration_segmentContext *ctx) = 0;
  virtual void exitDeclaration_segment(TigerParser::Declaration_segmentContext *ctx) = 0;

  virtual void enterType_declaration_list(TigerParser::Type_declaration_listContext *ctx) = 0;
  virtual void exitType_declaration_list(TigerParser::Type_declaration_listContext *ctx) = 0;

  virtual void enterVar_declaration_list(TigerParser::Var_declaration_listContext *ctx) = 0;
  virtual void exitVar_declaration_list(TigerParser::Var_declaration_listContext *ctx) = 0;

  virtual void enterFunct_list(TigerParser::Funct_listContext *ctx) = 0;
  virtual void exitFunct_list(TigerParser::Funct_listContext *ctx) = 0;

  virtual void enterType_declaration(TigerParser::Type_declarationContext *ctx) = 0;
  virtual void exitType_declaration(TigerParser::Type_declarationContext *ctx) = 0;

  virtual void enterType(TigerParser::TypeContext *ctx) = 0;
  virtual void exitType(TigerParser::TypeContext *ctx) = 0;

  virtual void enterType_id(TigerParser::Type_idContext *ctx) = 0;
  virtual void exitType_id(TigerParser::Type_idContext *ctx) = 0;

  virtual void enterVar_declaration(TigerParser::Var_declarationContext *ctx) = 0;
  virtual void exitVar_declaration(TigerParser::Var_declarationContext *ctx) = 0;

  virtual void enterStorage_class(TigerParser::Storage_classContext *ctx) = 0;
  virtual void exitStorage_class(TigerParser::Storage_classContext *ctx) = 0;

  virtual void enterId_list(TigerParser::Id_listContext *ctx) = 0;
  virtual void exitId_list(TigerParser::Id_listContext *ctx) = 0;

  virtual void enterOptional_init(TigerParser::Optional_initContext *ctx) = 0;
  virtual void exitOptional_init(TigerParser::Optional_initContext *ctx) = 0;

  virtual void enterFunct(TigerParser::FunctContext *ctx) = 0;
  virtual void exitFunct(TigerParser::FunctContext *ctx) = 0;

  virtual void enterParam_list(TigerParser::Param_listContext *ctx) = 0;
  virtual void exitParam_list(TigerParser::Param_listContext *ctx) = 0;

  virtual void enterParam_list_tail(TigerParser::Param_list_tailContext *ctx) = 0;
  virtual void exitParam_list_tail(TigerParser::Param_list_tailContext *ctx) = 0;

  virtual void enterRet_type(TigerParser::Ret_typeContext *ctx) = 0;
  virtual void exitRet_type(TigerParser::Ret_typeContext *ctx) = 0;

  virtual void enterParam(TigerParser::ParamContext *ctx) = 0;
  virtual void exitParam(TigerParser::ParamContext *ctx) = 0;

  virtual void enterStat_seq(TigerParser::Stat_seqContext *ctx) = 0;
  virtual void exitStat_seq(TigerParser::Stat_seqContext *ctx) = 0;

  virtual void enterStat(TigerParser::StatContext *ctx) = 0;
  virtual void exitStat(TigerParser::StatContext *ctx) = 0;

  virtual void enterOpt_return(TigerParser::Opt_returnContext *ctx) = 0;
  virtual void exitOpt_return(TigerParser::Opt_returnContext *ctx) = 0;

  virtual void enterOpt_prefix(TigerParser::Opt_prefixContext *ctx) = 0;
  virtual void exitOpt_prefix(TigerParser::Opt_prefixContext *ctx) = 0;

  virtual void enterL_tail(TigerParser::L_tailContext *ctx) = 0;
  virtual void exitL_tail(TigerParser::L_tailContext *ctx) = 0;

  virtual void enterExpr(TigerParser::ExprContext *ctx) = 0;
  virtual void exitExpr(TigerParser::ExprContext *ctx) = 0;

  virtual void enterConstant(TigerParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(TigerParser::ConstantContext *ctx) = 0;

  virtual void enterBinary_operator(TigerParser::Binary_operatorContext *ctx) = 0;
  virtual void exitBinary_operator(TigerParser::Binary_operatorContext *ctx) = 0;

  virtual void enterExpr_list(TigerParser::Expr_listContext *ctx) = 0;
  virtual void exitExpr_list(TigerParser::Expr_listContext *ctx) = 0;

  virtual void enterExpr_list_tail(TigerParser::Expr_list_tailContext *ctx) = 0;
  virtual void exitExpr_list_tail(TigerParser::Expr_list_tailContext *ctx) = 0;

  virtual void enterLvalue(TigerParser::LvalueContext *ctx) = 0;
  virtual void exitLvalue(TigerParser::LvalueContext *ctx) = 0;

  virtual void enterLvalue_tail(TigerParser::Lvalue_tailContext *ctx) = 0;
  virtual void exitLvalue_tail(TigerParser::Lvalue_tailContext *ctx) = 0;


};

