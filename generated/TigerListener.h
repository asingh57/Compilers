
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

  virtual void enterStat_seq_func(TigerParser::Stat_seq_funcContext *ctx) = 0;
  virtual void exitStat_seq_func(TigerParser::Stat_seq_funcContext *ctx) = 0;

  virtual void enterStat_seq(TigerParser::Stat_seqContext *ctx) = 0;
  virtual void exitStat_seq(TigerParser::Stat_seqContext *ctx) = 0;

  virtual void enterStat(TigerParser::StatContext *ctx) = 0;
  virtual void exitStat(TigerParser::StatContext *ctx) = 0;

  virtual void enterAssignment_stat(TigerParser::Assignment_statContext *ctx) = 0;
  virtual void exitAssignment_stat(TigerParser::Assignment_statContext *ctx) = 0;

  virtual void enterIf_stat(TigerParser::If_statContext *ctx) = 0;
  virtual void exitIf_stat(TigerParser::If_statContext *ctx) = 0;

  virtual void enterIf_else_stat(TigerParser::If_else_statContext *ctx) = 0;
  virtual void exitIf_else_stat(TigerParser::If_else_statContext *ctx) = 0;

  virtual void enterWhile_stat(TigerParser::While_statContext *ctx) = 0;
  virtual void exitWhile_stat(TigerParser::While_statContext *ctx) = 0;

  virtual void enterFor_stat(TigerParser::For_statContext *ctx) = 0;
  virtual void exitFor_stat(TigerParser::For_statContext *ctx) = 0;

  virtual void enterFncall_stat(TigerParser::Fncall_statContext *ctx) = 0;
  virtual void exitFncall_stat(TigerParser::Fncall_statContext *ctx) = 0;

  virtual void enterBreak_stat(TigerParser::Break_statContext *ctx) = 0;
  virtual void exitBreak_stat(TigerParser::Break_statContext *ctx) = 0;

  virtual void enterReturn_stat(TigerParser::Return_statContext *ctx) = 0;
  virtual void exitReturn_stat(TigerParser::Return_statContext *ctx) = 0;

  virtual void enterSub_scope_stat(TigerParser::Sub_scope_statContext *ctx) = 0;
  virtual void exitSub_scope_stat(TigerParser::Sub_scope_statContext *ctx) = 0;

  virtual void enterStat_seq_if(TigerParser::Stat_seq_ifContext *ctx) = 0;
  virtual void exitStat_seq_if(TigerParser::Stat_seq_ifContext *ctx) = 0;

  virtual void enterStat_seq_else(TigerParser::Stat_seq_elseContext *ctx) = 0;
  virtual void exitStat_seq_else(TigerParser::Stat_seq_elseContext *ctx) = 0;

  virtual void enterStat_seq_while(TigerParser::Stat_seq_whileContext *ctx) = 0;
  virtual void exitStat_seq_while(TigerParser::Stat_seq_whileContext *ctx) = 0;

  virtual void enterStat_seq_for(TigerParser::Stat_seq_forContext *ctx) = 0;
  virtual void exitStat_seq_for(TigerParser::Stat_seq_forContext *ctx) = 0;

  virtual void enterOpt_return(TigerParser::Opt_returnContext *ctx) = 0;
  virtual void exitOpt_return(TigerParser::Opt_returnContext *ctx) = 0;

  virtual void enterOpt_prefix(TigerParser::Opt_prefixContext *ctx) = 0;
  virtual void exitOpt_prefix(TigerParser::Opt_prefixContext *ctx) = 0;

  virtual void enterL_tail(TigerParser::L_tailContext *ctx) = 0;
  virtual void exitL_tail(TigerParser::L_tailContext *ctx) = 0;

  virtual void enterExpr(TigerParser::ExprContext *ctx) = 0;
  virtual void exitExpr(TigerParser::ExprContext *ctx) = 0;

  virtual void enterUnambiguous_expr(TigerParser::Unambiguous_exprContext *ctx) = 0;
  virtual void exitUnambiguous_expr(TigerParser::Unambiguous_exprContext *ctx) = 0;

  virtual void enterLogical_op_expr(TigerParser::Logical_op_exprContext *ctx) = 0;
  virtual void exitLogical_op_expr(TigerParser::Logical_op_exprContext *ctx) = 0;

  virtual void enterLogical_op_expr_ext(TigerParser::Logical_op_expr_extContext *ctx) = 0;
  virtual void exitLogical_op_expr_ext(TigerParser::Logical_op_expr_extContext *ctx) = 0;

  virtual void enterCompare_op_expr(TigerParser::Compare_op_exprContext *ctx) = 0;
  virtual void exitCompare_op_expr(TigerParser::Compare_op_exprContext *ctx) = 0;

  virtual void enterCompare_op_expr_ext(TigerParser::Compare_op_expr_extContext *ctx) = 0;
  virtual void exitCompare_op_expr_ext(TigerParser::Compare_op_expr_extContext *ctx) = 0;

  virtual void enterAdd_op_expr(TigerParser::Add_op_exprContext *ctx) = 0;
  virtual void exitAdd_op_expr(TigerParser::Add_op_exprContext *ctx) = 0;

  virtual void enterAdd_op_expr_ext(TigerParser::Add_op_expr_extContext *ctx) = 0;
  virtual void exitAdd_op_expr_ext(TigerParser::Add_op_expr_extContext *ctx) = 0;

  virtual void enterMult_op_expr(TigerParser::Mult_op_exprContext *ctx) = 0;
  virtual void exitMult_op_expr(TigerParser::Mult_op_exprContext *ctx) = 0;

  virtual void enterMult_op_expr_ext(TigerParser::Mult_op_expr_extContext *ctx) = 0;
  virtual void exitMult_op_expr_ext(TigerParser::Mult_op_expr_extContext *ctx) = 0;

  virtual void enterPow_op_expr(TigerParser::Pow_op_exprContext *ctx) = 0;
  virtual void exitPow_op_expr(TigerParser::Pow_op_exprContext *ctx) = 0;

  virtual void enterPow_op_expr_ext(TigerParser::Pow_op_expr_extContext *ctx) = 0;
  virtual void exitPow_op_expr_ext(TigerParser::Pow_op_expr_extContext *ctx) = 0;

  virtual void enterExpr_no_op(TigerParser::Expr_no_opContext *ctx) = 0;
  virtual void exitExpr_no_op(TigerParser::Expr_no_opContext *ctx) = 0;

  virtual void enterConstant(TigerParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(TigerParser::ConstantContext *ctx) = 0;

  virtual void enterExpr_list(TigerParser::Expr_listContext *ctx) = 0;
  virtual void exitExpr_list(TigerParser::Expr_listContext *ctx) = 0;

  virtual void enterExpr_list_tail(TigerParser::Expr_list_tailContext *ctx) = 0;
  virtual void exitExpr_list_tail(TigerParser::Expr_list_tailContext *ctx) = 0;

  virtual void enterLvalue(TigerParser::LvalueContext *ctx) = 0;
  virtual void exitLvalue(TigerParser::LvalueContext *ctx) = 0;

  virtual void enterLvalue_tail(TigerParser::Lvalue_tailContext *ctx) = 0;
  virtual void exitLvalue_tail(TigerParser::Lvalue_tailContext *ctx) = 0;


};

