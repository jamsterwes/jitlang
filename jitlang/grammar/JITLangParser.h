
// Generated from .\JITLang.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"




class  JITLangParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    AND = 27, OR = 28, IDENT = 29, STRING = 30, NUMBER = 31, WHITESPACE = 32, 
    COMMENT = 33
  };

  enum {
    RuleFile = 0, RuleStmt = 1, RuleFunction_define = 2, RuleIf_stmt = 3, 
    RuleDefine = 4, RuleAssign = 5, RuleExpr = 6, RuleAtom = 7, RuleArg_list = 8, 
    RuleFunc_call = 9, RuleLiteral = 10
  };

  explicit JITLangParser(antlr4::TokenStream *input);
  ~JITLangParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class StmtContext;
  class Function_defineContext;
  class If_stmtContext;
  class DefineContext;
  class AssignContext;
  class ExprContext;
  class AtomContext;
  class Arg_listContext;
  class Func_callContext;
  class LiteralContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    JITLangParser::StmtContext *stmtContext = nullptr;
    std::vector<StmtContext *> statements;
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> COMMENT();
    antlr4::tree::TerminalNode* COMMENT(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

   
  };

  FileContext* file();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    If_stmtContext *if_stmt();
    Function_defineContext *function_define();
    DefineContext *define();
    AssignContext *assign();

   
  };

  StmtContext* stmt();

  class  Function_defineContext : public antlr4::ParserRuleContext {
  public:
    JITLangParser::StmtContext *stmtContext = nullptr;
    std::vector<StmtContext *> statements;
    Function_defineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    std::vector<antlr4::tree::TerminalNode *> COMMENT();
    antlr4::tree::TerminalNode* COMMENT(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

   
  };

  Function_defineContext* function_define();

  class  If_stmtContext : public antlr4::ParserRuleContext {
  public:
    JITLangParser::ExprContext *cond = nullptr;
    JITLangParser::StmtContext *stmtContext = nullptr;
    std::vector<StmtContext *> statements;
    If_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    std::vector<antlr4::tree::TerminalNode *> COMMENT();
    antlr4::tree::TerminalNode* COMMENT(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

   
  };

  If_stmtContext* if_stmt();

  class  DefineContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;
    antlr4::Token *type = nullptr;
    JITLangParser::ExprContext *value = nullptr;
    DefineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENT();
    antlr4::tree::TerminalNode* IDENT(size_t i);
    ExprContext *expr();

   
  };

  DefineContext* define();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;
    JITLangParser::ExprContext *value = nullptr;
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    ExprContext *expr();

   
  };

  AssignContext* assign();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    JITLangParser::ExprContext *cond = nullptr;
    antlr4::Token *preIncr = nullptr;
    antlr4::Token *mult = nullptr;
    antlr4::Token *add = nullptr;
    antlr4::Token *gt = nullptr;
    antlr4::Token *eq = nullptr;
    antlr4::Token *logAnd = nullptr;
    antlr4::Token *logOr = nullptr;
    antlr4::Token *tern = nullptr;
    JITLangParser::ExprContext *t = nullptr;
    JITLangParser::ExprContext *f = nullptr;
    antlr4::Token *postIncr = nullptr;
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    Func_callContext *func_call();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();

   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralContext *literal();
    antlr4::tree::TerminalNode *IDENT();

   
  };

  AtomContext* atom();

  class  Arg_listContext : public antlr4::ParserRuleContext {
  public:
    JITLangParser::ExprContext *exprContext = nullptr;
    std::vector<ExprContext *> args;
    Arg_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

   
  };

  Arg_listContext* arg_list();

  class  Func_callContext : public antlr4::ParserRuleContext {
  public:
    Func_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();
    Arg_listContext *arg_list();

   
  };

  Func_callContext* func_call();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *STRING();

   
  };

  LiteralContext* literal();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

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

