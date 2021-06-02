
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

  virtual void enterStat_seq(TigerParser::Stat_seqContext * /*ctx*/) override { }
  virtual void exitStat_seq(TigerParser::Stat_seqContext * /*ctx*/) override { }

  virtual void enterStat(TigerParser::StatContext * /*ctx*/) override { }
  virtual void exitStat(TigerParser::StatContext * /*ctx*/) override { }

  virtual void enterOpt_return(TigerParser::Opt_returnContext * /*ctx*/) override { }
  virtual void exitOpt_return(TigerParser::Opt_returnContext * /*ctx*/) override { }

  virtual void enterOpt_prefix(TigerParser::Opt_prefixContext * /*ctx*/) override { }
  virtual void exitOpt_prefix(TigerParser::Opt_prefixContext * /*ctx*/) override { }

  virtual void enterL_tail(TigerParser::L_tailContext * /*ctx*/) override { }
  virtual void exitL_tail(TigerParser::L_tailContext * /*ctx*/) override { }

  virtual void enterExpr(TigerParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(TigerParser::ExprContext * /*ctx*/) override { }

  virtual void enterConstant(TigerParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(TigerParser::ConstantContext * /*ctx*/) override { }

  virtual void enterBinary_operator(TigerParser::Binary_operatorContext * /*ctx*/) override { }
  virtual void exitBinary_operator(TigerParser::Binary_operatorContext * /*ctx*/) override { }

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

