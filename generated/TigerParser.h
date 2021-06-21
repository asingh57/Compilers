
// Generated from Tiger.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  TigerParser : public antlr4::Parser {
public:
  enum {
    ARRAY = 1, BEGIN = 2, BREAK = 3, DO = 4, ELSE = 5, END = 6, ENDDO = 7, 
    ENDIF = 8, FOR = 9, FUNCTION = 10, IF = 11, INT = 12, LET = 13, OF = 14, 
    PROGRAM = 15, RETURN = 16, STATIC = 17, THEN = 18, TO = 19, TYPE = 20, 
    VAR = 21, WHILE = 22, COMMA = 23, DOT = 24, COLON = 25, SEMICOLON = 26, 
    OPENPAREN = 27, CLOSEPAREN = 28, OPENBRACK = 29, CLOSEBRACK = 30, OPENCURLY = 31, 
    CLOSECURLY = 32, PLUS = 33, MINUS = 34, MULT = 35, DIV = 36, POW = 37, 
    EQUAL = 38, NEQUAL = 39, LESS = 40, GREAT = 41, LESSEQ = 42, GREATEQ = 43, 
    AND = 44, OR = 45, ASSIGN = 46, TASSIGN = 47, WS = 48, COMMENT = 49, 
    ID = 50, INTLIT = 51
  };

  enum {
    RuleTiger_program = 0, RuleDeclaration_segment = 1, RuleType_declaration_list = 2, 
    RuleVar_declaration_list = 3, RuleFunct_list = 4, RuleType_declaration = 5, 
    RuleType = 6, RuleType_id = 7, RuleVar_declaration = 8, RuleStorage_class = 9, 
    RuleId_list = 10, RuleOptional_init = 11, RuleFunct = 12, RuleParam_list = 13, 
    RuleParam_list_tail = 14, RuleRet_type = 15, RuleParam = 16, RuleStat_seq_func = 17, 
    RuleStat_seq = 18, RuleStat = 19, RuleAssignment_stat = 20, RuleIf_stat = 21, 
    RuleIf_else_stat = 22, RuleWhile_stat = 23, RuleFor_stat = 24, RuleFncall_stat = 25, 
    RuleBreak_stat = 26, RuleReturn_stat = 27, RuleSub_scope_stat = 28, 
    RuleStat_seq_if = 29, RuleStat_seq_else = 30, RuleStat_seq_while = 31, 
    RuleStat_seq_for = 32, RuleOpt_return = 33, RuleOpt_prefix = 34, RuleL_tail = 35, 
    RuleExpr = 36, RuleUnambiguous_expr = 37, RuleLogical_op_expr = 38, 
    RuleLogical_op_expr_ext = 39, RuleCompare_op_expr = 40, RuleCompare_op_expr_ext = 41, 
    RuleAdd_op_expr = 42, RuleAdd_op_expr_ext = 43, RuleMult_op_expr = 44, 
    RuleMult_op_expr_ext = 45, RulePow_op_expr = 46, RulePow_op_expr_ext = 47, 
    RuleExpr_no_op = 48, RuleConstant = 49, RuleExpr_list = 50, RuleExpr_list_tail = 51, 
    RuleLvalue = 52, RuleLvalue_tail = 53
  };

  explicit TigerParser(antlr4::TokenStream *input);
  ~TigerParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class Tiger_programContext;
  class Declaration_segmentContext;
  class Type_declaration_listContext;
  class Var_declaration_listContext;
  class Funct_listContext;
  class Type_declarationContext;
  class TypeContext;
  class Type_idContext;
  class Var_declarationContext;
  class Storage_classContext;
  class Id_listContext;
  class Optional_initContext;
  class FunctContext;
  class Param_listContext;
  class Param_list_tailContext;
  class Ret_typeContext;
  class ParamContext;
  class Stat_seq_funcContext;
  class Stat_seqContext;
  class StatContext;
  class Assignment_statContext;
  class If_statContext;
  class If_else_statContext;
  class While_statContext;
  class For_statContext;
  class Fncall_statContext;
  class Break_statContext;
  class Return_statContext;
  class Sub_scope_statContext;
  class Stat_seq_ifContext;
  class Stat_seq_elseContext;
  class Stat_seq_whileContext;
  class Stat_seq_forContext;
  class Opt_returnContext;
  class Opt_prefixContext;
  class L_tailContext;
  class ExprContext;
  class Unambiguous_exprContext;
  class Logical_op_exprContext;
  class Logical_op_expr_extContext;
  class Compare_op_exprContext;
  class Compare_op_expr_extContext;
  class Add_op_exprContext;
  class Add_op_expr_extContext;
  class Mult_op_exprContext;
  class Mult_op_expr_extContext;
  class Pow_op_exprContext;
  class Pow_op_expr_extContext;
  class Expr_no_opContext;
  class ConstantContext;
  class Expr_listContext;
  class Expr_list_tailContext;
  class LvalueContext;
  class Lvalue_tailContext; 

  class  Tiger_programContext : public antlr4::ParserRuleContext {
  public:
    Tiger_programContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROGRAM();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LET();
    Declaration_segmentContext *declaration_segment();
    antlr4::tree::TerminalNode *BEGIN();
    Funct_listContext *funct_list();
    antlr4::tree::TerminalNode *END();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Tiger_programContext* tiger_program();

  class  Declaration_segmentContext : public antlr4::ParserRuleContext {
  public:
    Declaration_segmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_declaration_listContext *type_declaration_list();
    Var_declaration_listContext *var_declaration_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_segmentContext* declaration_segment();

  class  Type_declaration_listContext : public antlr4::ParserRuleContext {
  public:
    Type_declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_declarationContext *type_declaration();
    Type_declaration_listContext *type_declaration_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_declaration_listContext* type_declaration_list();

  class  Var_declaration_listContext : public antlr4::ParserRuleContext {
  public:
    Var_declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    Var_declaration_listContext *var_declaration_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_declaration_listContext* var_declaration_list();

  class  Funct_listContext : public antlr4::ParserRuleContext {
  public:
    Funct_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctContext *funct();
    Funct_listContext *funct_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Funct_listContext* funct_list();

  class  Type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *TASSIGN();
    TypeContext *type();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_declarationContext* type_declaration();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_idContext *type_id();
    antlr4::tree::TerminalNode *ARRAY();
    antlr4::tree::TerminalNode *OPENBRACK();
    antlr4::tree::TerminalNode *INTLIT();
    antlr4::tree::TerminalNode *CLOSEBRACK();
    antlr4::tree::TerminalNode *OF();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeContext* type();

  class  Type_idContext : public antlr4::ParserRuleContext {
  public:
    Type_idContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_idContext* type_id();

  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Storage_classContext *storage_class();
    Id_listContext *id_list();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();
    Optional_initContext *optional_init();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_declarationContext* var_declaration();

  class  Storage_classContext : public antlr4::ParserRuleContext {
  public:
    Storage_classContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *STATIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Storage_classContext* storage_class();

  class  Id_listContext : public antlr4::ParserRuleContext {
  public:
    Id_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COMMA();
    Id_listContext *id_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Id_listContext* id_list();

  class  Optional_initContext : public antlr4::ParserRuleContext {
  public:
    Optional_initContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGN();
    ConstantContext *constant();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Optional_initContext* optional_init();

  class  FunctContext : public antlr4::ParserRuleContext {
  public:
    FunctContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNCTION();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *OPENPAREN();
    Param_listContext *param_list();
    antlr4::tree::TerminalNode *CLOSEPAREN();
    Ret_typeContext *ret_type();
    antlr4::tree::TerminalNode *BEGIN();
    Stat_seq_funcContext *stat_seq_func();
    antlr4::tree::TerminalNode *END();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctContext* funct();

  class  Param_listContext : public antlr4::ParserRuleContext {
  public:
    Param_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamContext *param();
    Param_list_tailContext *param_list_tail();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Param_listContext* param_list();

  class  Param_list_tailContext : public antlr4::ParserRuleContext {
  public:
    Param_list_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    ParamContext *param();
    Param_list_tailContext *param_list_tail();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Param_list_tailContext* param_list_tail();

  class  Ret_typeContext : public antlr4::ParserRuleContext {
  public:
    Ret_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ret_typeContext* ret_type();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParamContext* param();

  class  Stat_seq_funcContext : public antlr4::ParserRuleContext {
  public:
    Stat_seq_funcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Stat_seqContext *stat_seq();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Stat_seq_funcContext* stat_seq_func();

  class  Stat_seqContext : public antlr4::ParserRuleContext {
  public:
    Stat_seqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatContext *stat();
    Stat_seqContext *stat_seq();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Stat_seqContext* stat_seq();

  class  StatContext : public antlr4::ParserRuleContext {
  public:
    StatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Assignment_statContext *assignment_stat();
    If_statContext *if_stat();
    If_else_statContext *if_else_stat();
    While_statContext *while_stat();
    For_statContext *for_stat();
    Fncall_statContext *fncall_stat();
    Break_statContext *break_stat();
    Return_statContext *return_stat();
    Sub_scope_statContext *sub_scope_stat();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatContext* stat();

  class  Assignment_statContext : public antlr4::ParserRuleContext {
  public:
    Assignment_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LvalueContext *lvalue();
    L_tailContext *l_tail();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Assignment_statContext* assignment_stat();

  class  If_statContext : public antlr4::ParserRuleContext {
  public:
    If_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    ExprContext *expr();
    antlr4::tree::TerminalNode *THEN();
    Stat_seq_ifContext *stat_seq_if();
    antlr4::tree::TerminalNode *ENDIF();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  If_statContext* if_stat();

  class  If_else_statContext : public antlr4::ParserRuleContext {
  public:
    If_else_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    ExprContext *expr();
    antlr4::tree::TerminalNode *THEN();
    Stat_seq_ifContext *stat_seq_if();
    antlr4::tree::TerminalNode *ELSE();
    Stat_seq_elseContext *stat_seq_else();
    antlr4::tree::TerminalNode *ENDIF();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  If_else_statContext* if_else_stat();

  class  While_statContext : public antlr4::ParserRuleContext {
  public:
    While_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    ExprContext *expr();
    antlr4::tree::TerminalNode *DO();
    Stat_seq_whileContext *stat_seq_while();
    antlr4::tree::TerminalNode *ENDDO();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  While_statContext* while_stat();

  class  For_statContext : public antlr4::ParserRuleContext {
  public:
    For_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *DO();
    Stat_seq_forContext *stat_seq_for();
    antlr4::tree::TerminalNode *ENDDO();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  For_statContext* for_stat();

  class  Fncall_statContext : public antlr4::ParserRuleContext {
  public:
    Fncall_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Opt_prefixContext *opt_prefix();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *OPENPAREN();
    Expr_listContext *expr_list();
    antlr4::tree::TerminalNode *CLOSEPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Fncall_statContext* fncall_stat();

  class  Break_statContext : public antlr4::ParserRuleContext {
  public:
    Break_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Break_statContext* break_stat();

  class  Return_statContext : public antlr4::ParserRuleContext {
  public:
    Return_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    Opt_returnContext *opt_return();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Return_statContext* return_stat();

  class  Sub_scope_statContext : public antlr4::ParserRuleContext {
  public:
    Sub_scope_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LET();
    Declaration_segmentContext *declaration_segment();
    antlr4::tree::TerminalNode *BEGIN();
    Stat_seqContext *stat_seq();
    antlr4::tree::TerminalNode *END();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Sub_scope_statContext* sub_scope_stat();

  class  Stat_seq_ifContext : public antlr4::ParserRuleContext {
  public:
    Stat_seq_ifContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Stat_seqContext *stat_seq();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Stat_seq_ifContext* stat_seq_if();

  class  Stat_seq_elseContext : public antlr4::ParserRuleContext {
  public:
    Stat_seq_elseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Stat_seqContext *stat_seq();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Stat_seq_elseContext* stat_seq_else();

  class  Stat_seq_whileContext : public antlr4::ParserRuleContext {
  public:
    Stat_seq_whileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Stat_seqContext *stat_seq();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Stat_seq_whileContext* stat_seq_while();

  class  Stat_seq_forContext : public antlr4::ParserRuleContext {
  public:
    Stat_seq_forContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Stat_seqContext *stat_seq();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Stat_seq_forContext* stat_seq_for();

  class  Opt_returnContext : public antlr4::ParserRuleContext {
  public:
    Opt_returnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Opt_returnContext* opt_return();

  class  Opt_prefixContext : public antlr4::ParserRuleContext {
  public:
    Opt_prefixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LvalueContext *lvalue();
    antlr4::tree::TerminalNode *ASSIGN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Opt_prefixContext* opt_prefix();

  class  L_tailContext : public antlr4::ParserRuleContext {
  public:
    L_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGN();
    LvalueContext *lvalue();
    L_tailContext *l_tail();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  L_tailContext* l_tail();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr_no_opContext *expr_no_op();
    Unambiguous_exprContext *unambiguous_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExprContext* expr();

  class  Unambiguous_exprContext : public antlr4::ParserRuleContext {
  public:
    Unambiguous_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logical_op_exprContext *logical_op_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unambiguous_exprContext* unambiguous_expr();

  class  Logical_op_exprContext : public antlr4::ParserRuleContext {
  public:
    Logical_op_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Compare_op_exprContext *compare_op_expr();
    Logical_op_expr_extContext *logical_op_expr_ext();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Logical_op_exprContext* logical_op_expr();

  class  Logical_op_expr_extContext : public antlr4::ParserRuleContext {
  public:
    Logical_op_expr_extContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Compare_op_exprContext *compare_op_expr();
    Logical_op_expr_extContext *logical_op_expr_ext();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Logical_op_expr_extContext* logical_op_expr_ext();

  class  Compare_op_exprContext : public antlr4::ParserRuleContext {
  public:
    Compare_op_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Add_op_exprContext *add_op_expr();
    Compare_op_expr_extContext *compare_op_expr_ext();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compare_op_exprContext* compare_op_expr();

  class  Compare_op_expr_extContext : public antlr4::ParserRuleContext {
  public:
    Compare_op_expr_extContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Add_op_exprContext *add_op_expr();
    Compare_op_expr_extContext *compare_op_expr_ext();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *NEQUAL();
    antlr4::tree::TerminalNode *LESS();
    antlr4::tree::TerminalNode *GREAT();
    antlr4::tree::TerminalNode *LESSEQ();
    antlr4::tree::TerminalNode *GREATEQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compare_op_expr_extContext* compare_op_expr_ext();

  class  Add_op_exprContext : public antlr4::ParserRuleContext {
  public:
    Add_op_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mult_op_exprContext *mult_op_expr();
    Add_op_expr_extContext *add_op_expr_ext();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Add_op_exprContext* add_op_expr();

  class  Add_op_expr_extContext : public antlr4::ParserRuleContext {
  public:
    Add_op_expr_extContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mult_op_exprContext *mult_op_expr();
    Add_op_expr_extContext *add_op_expr_ext();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Add_op_expr_extContext* add_op_expr_ext();

  class  Mult_op_exprContext : public antlr4::ParserRuleContext {
  public:
    Mult_op_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Pow_op_exprContext *pow_op_expr();
    Mult_op_expr_extContext *mult_op_expr_ext();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Mult_op_exprContext* mult_op_expr();

  class  Mult_op_expr_extContext : public antlr4::ParserRuleContext {
  public:
    Mult_op_expr_extContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Pow_op_exprContext *pow_op_expr();
    Mult_op_expr_extContext *mult_op_expr_ext();
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *DIV();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Mult_op_expr_extContext* mult_op_expr_ext();

  class  Pow_op_exprContext : public antlr4::ParserRuleContext {
  public:
    Pow_op_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr_no_opContext *expr_no_op();
    Pow_op_expr_extContext *pow_op_expr_ext();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Pow_op_exprContext* pow_op_expr();

  class  Pow_op_expr_extContext : public antlr4::ParserRuleContext {
  public:
    Pow_op_expr_extContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr_no_opContext *expr_no_op();
    Pow_op_expr_extContext *pow_op_expr_ext();
    antlr4::tree::TerminalNode *POW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Pow_op_expr_extContext* pow_op_expr_ext();

  class  Expr_no_opContext : public antlr4::ParserRuleContext {
  public:
    Expr_no_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstantContext *constant();
    LvalueContext *lvalue();
    antlr4::tree::TerminalNode *OPENPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CLOSEPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr_no_opContext* expr_no_op();

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTLIT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConstantContext* constant();

  class  Expr_listContext : public antlr4::ParserRuleContext {
  public:
    Expr_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    Expr_list_tailContext *expr_list_tail();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr_listContext* expr_list();

  class  Expr_list_tailContext : public antlr4::ParserRuleContext {
  public:
    Expr_list_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    ExprContext *expr();
    Expr_list_tailContext *expr_list_tail();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr_list_tailContext* expr_list_tail();

  class  LvalueContext : public antlr4::ParserRuleContext {
  public:
    LvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Lvalue_tailContext *lvalue_tail();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LvalueContext* lvalue();

  class  Lvalue_tailContext : public antlr4::ParserRuleContext {
  public:
    Lvalue_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPENBRACK();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CLOSEBRACK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Lvalue_tailContext* lvalue_tail();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

