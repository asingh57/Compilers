
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

  virtual void enterTiger_program(TigerParser::Tiger_programContext * /*ctx*/) override { }
  virtual void exitTiger_program(TigerParser::Tiger_programContext * /*ctx*/) override { }

  virtual void enterDeclaration_segment(TigerParser::Declaration_segmentContext * /*ctx*/) override { }
  virtual void exitDeclaration_segment(TigerParser::Declaration_segmentContext * /*ctx*/) override { }

  virtual void enterType_declaration_list(TigerParser::Type_declaration_listContext * /*ctx*/) override { }
  virtual void exitType_declaration_list(TigerParser::Type_declaration_listContext * /*ctx*/) override { }

  virtual void enterVar_declaration_list(TigerParser::Var_declaration_listContext * /*ctx*/) override { }
  virtual void exitVar_declaration_list(TigerParser::Var_declaration_listContext * /*ctx*/) override { }

  virtual void enterFunct_list(TigerParser::Funct_listContext * /*ctx*/) override { }
  virtual void exitFunct_list(TigerParser::Funct_listContext * /*ctx*/) override { }

  virtual void enterType_declaration(TigerParser::Type_declarationContext * /*ctx*/) override { }
  virtual void exitType_declaration(TigerParser::Type_declarationContext * /*ctx*/) override { }

  virtual void enterType(TigerParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(TigerParser::TypeContext * /*ctx*/) override { }

  virtual void enterType_id(TigerParser::Type_idContext * /*ctx*/) override { }
  virtual void exitType_id(TigerParser::Type_idContext * /*ctx*/) override { }

  virtual void enterVar_declaration(TigerParser::Var_declarationContext * /*ctx*/) override { }
  virtual void exitVar_declaration(TigerParser::Var_declarationContext * /*ctx*/) override { }

  virtual void enterStorage_class(TigerParser::Storage_classContext * /*ctx*/) override { }
  virtual void exitStorage_class(TigerParser::Storage_classContext * /*ctx*/) override { }

  virtual void enterId_list(TigerParser::Id_listContext * /*ctx*/) override { }
  virtual void exitId_list(TigerParser::Id_listContext * /*ctx*/) override { }

  virtual void enterOptional_init(TigerParser::Optional_initContext * /*ctx*/) override { }
  virtual void exitOptional_init(TigerParser::Optional_initContext * /*ctx*/) override { }

  virtual void enterFunct(TigerParser::FunctContext * /*ctx*/) override { }
  virtual void exitFunct(TigerParser::FunctContext * /*ctx*/) override { }

  virtual void enterParam_list(TigerParser::Param_listContext * /*ctx*/) override { }
  virtual void exitParam_list(TigerParser::Param_listContext * /*ctx*/) override { }

  virtual void enterParam_list_tail(TigerParser::Param_list_tailContext * /*ctx*/) override { }
  virtual void exitParam_list_tail(TigerParser::Param_list_tailContext * /*ctx*/) override { }

  virtual void enterRet_type(TigerParser::Ret_typeContext * /*ctx*/) override { }
  virtual void exitRet_type(TigerParser::Ret_typeContext * /*ctx*/) override { }

  virtual void enterParam(TigerParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(TigerParser::ParamContext * /*ctx*/) override { }

  virtual void enterStat_seq_func(TigerParser::Stat_seq_funcContext * /*ctx*/) override { }
  virtual void exitStat_seq_func(TigerParser::Stat_seq_funcContext * /*ctx*/) override { }

  virtual void enterStat_seq(TigerParser::Stat_seqContext * /*ctx*/) override { }
  virtual void exitStat_seq(TigerParser::Stat_seqContext * /*ctx*/) override { }

  virtual void enterStat(TigerParser::StatContext * /*ctx*/) override { }
  virtual void exitStat(TigerParser::StatContext * /*ctx*/) override { }

  virtual void enterAssignment_stat(TigerParser::Assignment_statContext * /*ctx*/) override { }
  virtual void exitAssignment_stat(TigerParser::Assignment_statContext * /*ctx*/) override { }

  virtual void enterIf_stat(TigerParser::If_statContext * /*ctx*/) override { }
  virtual void exitIf_stat(TigerParser::If_statContext * /*ctx*/) override { }

  virtual void enterIf_else_stat(TigerParser::If_else_statContext * /*ctx*/) override { }
  virtual void exitIf_else_stat(TigerParser::If_else_statContext * /*ctx*/) override { }

  virtual void enterWhile_stat(TigerParser::While_statContext * /*ctx*/) override { }
  virtual void exitWhile_stat(TigerParser::While_statContext * /*ctx*/) override { }

  virtual void enterFor_stat(TigerParser::For_statContext * /*ctx*/) override { }
  virtual void exitFor_stat(TigerParser::For_statContext * /*ctx*/) override { }

  virtual void enterFncall_stat(TigerParser::Fncall_statContext * /*ctx*/) override { }
  virtual void exitFncall_stat(TigerParser::Fncall_statContext * /*ctx*/) override { }

  virtual void enterBreak_stat(TigerParser::Break_statContext * /*ctx*/) override { }
  virtual void exitBreak_stat(TigerParser::Break_statContext * /*ctx*/) override { }

  virtual void enterReturn_stat(TigerParser::Return_statContext * /*ctx*/) override { }
  virtual void exitReturn_stat(TigerParser::Return_statContext * /*ctx*/) override { }

  virtual void enterSub_scope_stat(TigerParser::Sub_scope_statContext * /*ctx*/) override { }
  virtual void exitSub_scope_stat(TigerParser::Sub_scope_statContext * /*ctx*/) override { }

  virtual void enterIf_stat_lhs(TigerParser::If_stat_lhsContext * /*ctx*/) override { }
  virtual void exitIf_stat_lhs(TigerParser::If_stat_lhsContext * /*ctx*/) override { }

  virtual void enterStat_seq_then(TigerParser::Stat_seq_thenContext * /*ctx*/) override { }
  virtual void exitStat_seq_then(TigerParser::Stat_seq_thenContext * /*ctx*/) override { }

  virtual void enterStat_seq_else(TigerParser::Stat_seq_elseContext * /*ctx*/) override { }
  virtual void exitStat_seq_else(TigerParser::Stat_seq_elseContext * /*ctx*/) override { }

  virtual void enterStat_seq_while(TigerParser::Stat_seq_whileContext * /*ctx*/) override { }
  virtual void exitStat_seq_while(TigerParser::Stat_seq_whileContext * /*ctx*/) override { }

  virtual void enterStat_seq_for(TigerParser::Stat_seq_forContext * /*ctx*/) override { }
  virtual void exitStat_seq_for(TigerParser::Stat_seq_forContext * /*ctx*/) override { }

  virtual void enterOpt_return(TigerParser::Opt_returnContext * /*ctx*/) override { }
  virtual void exitOpt_return(TigerParser::Opt_returnContext * /*ctx*/) override { }

  virtual void enterOpt_prefix(TigerParser::Opt_prefixContext * /*ctx*/) override { }
  virtual void exitOpt_prefix(TigerParser::Opt_prefixContext * /*ctx*/) override { }

  virtual void enterL_tail(TigerParser::L_tailContext * /*ctx*/) override { }
  virtual void exitL_tail(TigerParser::L_tailContext * /*ctx*/) override { }

  virtual void enterExpr(TigerParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(TigerParser::ExprContext * /*ctx*/) override { }

  virtual void enterUnambiguous_expr(TigerParser::Unambiguous_exprContext * /*ctx*/) override { }
  virtual void exitUnambiguous_expr(TigerParser::Unambiguous_exprContext * /*ctx*/) override { }

  virtual void enterLogical_op_expr(TigerParser::Logical_op_exprContext * /*ctx*/) override { }
  virtual void exitLogical_op_expr(TigerParser::Logical_op_exprContext * /*ctx*/) override { }

  virtual void enterLogical_op_expr_ext(TigerParser::Logical_op_expr_extContext * /*ctx*/) override { }
  virtual void exitLogical_op_expr_ext(TigerParser::Logical_op_expr_extContext * /*ctx*/) override { }

  virtual void enterCompare_op_expr(TigerParser::Compare_op_exprContext * /*ctx*/) override { }
  virtual void exitCompare_op_expr(TigerParser::Compare_op_exprContext * /*ctx*/) override { }

  virtual void enterCompare_op_expr_ext(TigerParser::Compare_op_expr_extContext * /*ctx*/) override { }
  virtual void exitCompare_op_expr_ext(TigerParser::Compare_op_expr_extContext * /*ctx*/) override { }

  virtual void enterAdd_op_expr(TigerParser::Add_op_exprContext * /*ctx*/) override { }
  virtual void exitAdd_op_expr(TigerParser::Add_op_exprContext * /*ctx*/) override { }

  virtual void enterAdd_op_expr_ext(TigerParser::Add_op_expr_extContext * /*ctx*/) override { }
  virtual void exitAdd_op_expr_ext(TigerParser::Add_op_expr_extContext * /*ctx*/) override { }

  virtual void enterMult_op_expr(TigerParser::Mult_op_exprContext * /*ctx*/) override { }
  virtual void exitMult_op_expr(TigerParser::Mult_op_exprContext * /*ctx*/) override { }

  virtual void enterMult_op_expr_ext(TigerParser::Mult_op_expr_extContext * /*ctx*/) override { }
  virtual void exitMult_op_expr_ext(TigerParser::Mult_op_expr_extContext * /*ctx*/) override { }

  virtual void enterPow_op_expr(TigerParser::Pow_op_exprContext * /*ctx*/) override { }
  virtual void exitPow_op_expr(TigerParser::Pow_op_exprContext * /*ctx*/) override { }

  virtual void enterPow_op_expr_ext(TigerParser::Pow_op_expr_extContext * /*ctx*/) override { }
  virtual void exitPow_op_expr_ext(TigerParser::Pow_op_expr_extContext * /*ctx*/) override { }

  virtual void enterExpr_no_op(TigerParser::Expr_no_opContext * /*ctx*/) override { }
  virtual void exitExpr_no_op(TigerParser::Expr_no_opContext * /*ctx*/) override { }

  virtual void enterConstant(TigerParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(TigerParser::ConstantContext * /*ctx*/) override { }

  virtual void enterExpr_list(TigerParser::Expr_listContext * /*ctx*/) override { }
  virtual void exitExpr_list(TigerParser::Expr_listContext * /*ctx*/) override { }

  virtual void enterExpr_list_tail(TigerParser::Expr_list_tailContext * /*ctx*/) override { }
  virtual void exitExpr_list_tail(TigerParser::Expr_list_tailContext * /*ctx*/) override { }

  virtual void enterLvalue(TigerParser::LvalueContext * /*ctx*/) override { }
  virtual void exitLvalue(TigerParser::LvalueContext * /*ctx*/) override { }

  virtual void enterLvalue_tail(TigerParser::Lvalue_tailContext * /*ctx*/) override { }
  virtual void exitLvalue_tail(TigerParser::Lvalue_tailContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

