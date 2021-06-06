
// Generated from Tiger.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  TigerLexer : public antlr4::Lexer {
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

  explicit TigerLexer(antlr4::CharStream *input);
  ~TigerLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

