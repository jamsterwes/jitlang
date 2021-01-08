
// Generated from .\JITLang.g4 by ANTLR 4.9



#include "JITLangParser.h"


using namespace antlrcpp;
using namespace antlr4;

JITLangParser::JITLangParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

JITLangParser::~JITLangParser() {
  delete _interpreter;
}

std::string JITLangParser::getGrammarFileName() const {
  return "JITLang.g4";
}

const std::vector<std::string>& JITLangParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& JITLangParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

JITLangParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JITLangParser::FileContext::EOF() {
  return getToken(JITLangParser::EOF, 0);
}

std::vector<tree::TerminalNode *> JITLangParser::FileContext::COMMENT() {
  return getTokens(JITLangParser::COMMENT);
}

tree::TerminalNode* JITLangParser::FileContext::COMMENT(size_t i) {
  return getToken(JITLangParser::COMMENT, i);
}

std::vector<JITLangParser::StmtContext *> JITLangParser::FileContext::stmt() {
  return getRuleContexts<JITLangParser::StmtContext>();
}

JITLangParser::StmtContext* JITLangParser::FileContext::stmt(size_t i) {
  return getRuleContext<JITLangParser::StmtContext>(i);
}


size_t JITLangParser::FileContext::getRuleIndex() const {
  return JITLangParser::RuleFile;
}


JITLangParser::FileContext* JITLangParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, JITLangParser::RuleFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(31);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(29);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case JITLangParser::T__1:
          case JITLangParser::T__6:
          case JITLangParser::IDENT:
          case JITLangParser::STRING:
          case JITLangParser::NUMBER: {
            setState(26);
            dynamic_cast<FileContext *>(_localctx)->stmtContext = stmt();
            dynamic_cast<FileContext *>(_localctx)->statements.push_back(dynamic_cast<FileContext *>(_localctx)->stmtContext);
            break;
          }

          case JITLangParser::T__0: {
            setState(27);
            match(JITLangParser::T__0);
            break;
          }

          case JITLangParser::COMMENT: {
            setState(28);
            match(JITLangParser::COMMENT);
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(33);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(35);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JITLangParser::T__1)
      | (1ULL << JITLangParser::T__6)
      | (1ULL << JITLangParser::IDENT)
      | (1ULL << JITLangParser::STRING)
      | (1ULL << JITLangParser::NUMBER))) != 0)) {
      setState(34);
      dynamic_cast<FileContext *>(_localctx)->stmtContext = stmt();
      dynamic_cast<FileContext *>(_localctx)->statements.push_back(dynamic_cast<FileContext *>(_localctx)->stmtContext);
    }
    setState(37);
    match(JITLangParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

JITLangParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JITLangParser::ExprContext* JITLangParser::StmtContext::expr() {
  return getRuleContext<JITLangParser::ExprContext>(0);
}

JITLangParser::If_stmtContext* JITLangParser::StmtContext::if_stmt() {
  return getRuleContext<JITLangParser::If_stmtContext>(0);
}

JITLangParser::Function_defineContext* JITLangParser::StmtContext::function_define() {
  return getRuleContext<JITLangParser::Function_defineContext>(0);
}

JITLangParser::DefineContext* JITLangParser::StmtContext::define() {
  return getRuleContext<JITLangParser::DefineContext>(0);
}

JITLangParser::AssignContext* JITLangParser::StmtContext::assign() {
  return getRuleContext<JITLangParser::AssignContext>(0);
}


size_t JITLangParser::StmtContext::getRuleIndex() const {
  return JITLangParser::RuleStmt;
}


JITLangParser::StmtContext* JITLangParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 2, JITLangParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(44);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(39);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(40);
      if_stmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(41);
      function_define();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(42);
      define();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(43);
      assign();
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

//----------------- Function_defineContext ------------------------------------------------------------------

JITLangParser::Function_defineContext::Function_defineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JITLangParser::Function_defineContext::IDENT() {
  return getToken(JITLangParser::IDENT, 0);
}

std::vector<tree::TerminalNode *> JITLangParser::Function_defineContext::COMMENT() {
  return getTokens(JITLangParser::COMMENT);
}

tree::TerminalNode* JITLangParser::Function_defineContext::COMMENT(size_t i) {
  return getToken(JITLangParser::COMMENT, i);
}

std::vector<JITLangParser::StmtContext *> JITLangParser::Function_defineContext::stmt() {
  return getRuleContexts<JITLangParser::StmtContext>();
}

JITLangParser::StmtContext* JITLangParser::Function_defineContext::stmt(size_t i) {
  return getRuleContext<JITLangParser::StmtContext>(i);
}


size_t JITLangParser::Function_defineContext::getRuleIndex() const {
  return JITLangParser::RuleFunction_define;
}


JITLangParser::Function_defineContext* JITLangParser::function_define() {
  Function_defineContext *_localctx = _tracker.createInstance<Function_defineContext>(_ctx, getState());
  enterRule(_localctx, 4, JITLangParser::RuleFunction_define);
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
    setState(46);
    match(JITLangParser::T__1);
    setState(47);
    match(JITLangParser::IDENT);
    setState(48);
    match(JITLangParser::T__2);
    setState(49);
    match(JITLangParser::T__3);
    setState(53);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JITLangParser::T__0) {
      setState(50);
      match(JITLangParser::T__0);
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(56);
    match(JITLangParser::T__4);
    setState(62);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JITLangParser::T__0)
      | (1ULL << JITLangParser::T__1)
      | (1ULL << JITLangParser::T__6)
      | (1ULL << JITLangParser::IDENT)
      | (1ULL << JITLangParser::STRING)
      | (1ULL << JITLangParser::NUMBER)
      | (1ULL << JITLangParser::COMMENT))) != 0)) {
      setState(60);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case JITLangParser::T__1:
        case JITLangParser::T__6:
        case JITLangParser::IDENT:
        case JITLangParser::STRING:
        case JITLangParser::NUMBER: {
          setState(57);
          dynamic_cast<Function_defineContext *>(_localctx)->stmtContext = stmt();
          dynamic_cast<Function_defineContext *>(_localctx)->statements.push_back(dynamic_cast<Function_defineContext *>(_localctx)->stmtContext);
          break;
        }

        case JITLangParser::T__0: {
          setState(58);
          match(JITLangParser::T__0);
          break;
        }

        case JITLangParser::COMMENT: {
          setState(59);
          match(JITLangParser::COMMENT);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(64);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(65);
    match(JITLangParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_stmtContext ------------------------------------------------------------------

JITLangParser::If_stmtContext::If_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JITLangParser::ExprContext* JITLangParser::If_stmtContext::expr() {
  return getRuleContext<JITLangParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> JITLangParser::If_stmtContext::COMMENT() {
  return getTokens(JITLangParser::COMMENT);
}

tree::TerminalNode* JITLangParser::If_stmtContext::COMMENT(size_t i) {
  return getToken(JITLangParser::COMMENT, i);
}

std::vector<JITLangParser::StmtContext *> JITLangParser::If_stmtContext::stmt() {
  return getRuleContexts<JITLangParser::StmtContext>();
}

JITLangParser::StmtContext* JITLangParser::If_stmtContext::stmt(size_t i) {
  return getRuleContext<JITLangParser::StmtContext>(i);
}


size_t JITLangParser::If_stmtContext::getRuleIndex() const {
  return JITLangParser::RuleIf_stmt;
}


JITLangParser::If_stmtContext* JITLangParser::if_stmt() {
  If_stmtContext *_localctx = _tracker.createInstance<If_stmtContext>(_ctx, getState());
  enterRule(_localctx, 6, JITLangParser::RuleIf_stmt);
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
    setState(67);
    match(JITLangParser::T__6);
    setState(68);
    match(JITLangParser::T__2);
    setState(69);
    dynamic_cast<If_stmtContext *>(_localctx)->cond = expr(0);
    setState(70);
    match(JITLangParser::T__3);
    setState(74);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JITLangParser::T__0) {
      setState(71);
      match(JITLangParser::T__0);
      setState(76);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(77);
    match(JITLangParser::T__4);
    setState(83);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JITLangParser::T__0)
      | (1ULL << JITLangParser::T__1)
      | (1ULL << JITLangParser::T__6)
      | (1ULL << JITLangParser::IDENT)
      | (1ULL << JITLangParser::STRING)
      | (1ULL << JITLangParser::NUMBER)
      | (1ULL << JITLangParser::COMMENT))) != 0)) {
      setState(81);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case JITLangParser::T__1:
        case JITLangParser::T__6:
        case JITLangParser::IDENT:
        case JITLangParser::STRING:
        case JITLangParser::NUMBER: {
          setState(78);
          dynamic_cast<If_stmtContext *>(_localctx)->stmtContext = stmt();
          dynamic_cast<If_stmtContext *>(_localctx)->statements.push_back(dynamic_cast<If_stmtContext *>(_localctx)->stmtContext);
          break;
        }

        case JITLangParser::T__0: {
          setState(79);
          match(JITLangParser::T__0);
          break;
        }

        case JITLangParser::COMMENT: {
          setState(80);
          match(JITLangParser::COMMENT);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(85);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(86);
    match(JITLangParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefineContext ------------------------------------------------------------------

JITLangParser::DefineContext::DefineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> JITLangParser::DefineContext::IDENT() {
  return getTokens(JITLangParser::IDENT);
}

tree::TerminalNode* JITLangParser::DefineContext::IDENT(size_t i) {
  return getToken(JITLangParser::IDENT, i);
}

JITLangParser::ExprContext* JITLangParser::DefineContext::expr() {
  return getRuleContext<JITLangParser::ExprContext>(0);
}


size_t JITLangParser::DefineContext::getRuleIndex() const {
  return JITLangParser::RuleDefine;
}


JITLangParser::DefineContext* JITLangParser::define() {
  DefineContext *_localctx = _tracker.createInstance<DefineContext>(_ctx, getState());
  enterRule(_localctx, 8, JITLangParser::RuleDefine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    dynamic_cast<DefineContext *>(_localctx)->name = match(JITLangParser::IDENT);
    setState(89);
    match(JITLangParser::T__7);
    setState(90);
    dynamic_cast<DefineContext *>(_localctx)->type = match(JITLangParser::IDENT);
    setState(91);
    match(JITLangParser::T__8);
    setState(92);
    dynamic_cast<DefineContext *>(_localctx)->value = expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

JITLangParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JITLangParser::AssignContext::IDENT() {
  return getToken(JITLangParser::IDENT, 0);
}

JITLangParser::ExprContext* JITLangParser::AssignContext::expr() {
  return getRuleContext<JITLangParser::ExprContext>(0);
}


size_t JITLangParser::AssignContext::getRuleIndex() const {
  return JITLangParser::RuleAssign;
}


JITLangParser::AssignContext* JITLangParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 10, JITLangParser::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    dynamic_cast<AssignContext *>(_localctx)->name = match(JITLangParser::IDENT);
    setState(95);
    match(JITLangParser::T__8);
    setState(96);
    dynamic_cast<AssignContext *>(_localctx)->value = expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

JITLangParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JITLangParser::LiteralContext* JITLangParser::ExprContext::literal() {
  return getRuleContext<JITLangParser::LiteralContext>(0);
}

tree::TerminalNode* JITLangParser::ExprContext::IDENT() {
  return getToken(JITLangParser::IDENT, 0);
}

JITLangParser::Incr_decrContext* JITLangParser::ExprContext::incr_decr() {
  return getRuleContext<JITLangParser::Incr_decrContext>(0);
}

JITLangParser::Func_callContext* JITLangParser::ExprContext::func_call() {
  return getRuleContext<JITLangParser::Func_callContext>(0);
}

std::vector<JITLangParser::ExprContext *> JITLangParser::ExprContext::expr() {
  return getRuleContexts<JITLangParser::ExprContext>();
}

JITLangParser::ExprContext* JITLangParser::ExprContext::expr(size_t i) {
  return getRuleContext<JITLangParser::ExprContext>(i);
}


size_t JITLangParser::ExprContext::getRuleIndex() const {
  return JITLangParser::RuleExpr;
}



JITLangParser::ExprContext* JITLangParser::expr() {
   return expr(0);
}

JITLangParser::ExprContext* JITLangParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  JITLangParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  JITLangParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, JITLangParser::RuleExpr, precedence);

    

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
    setState(103);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(99);
      literal();
      break;
    }

    case 2: {
      setState(100);
      match(JITLangParser::IDENT);
      break;
    }

    case 3: {
      setState(101);
      incr_decr();
      break;
    }

    case 4: {
      setState(102);
      func_call();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(125);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(123);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->lhs = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(105);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(106);
          dynamic_cast<ExprContext *>(_localctx)->cmpop = match(JITLangParser::T__9);
          setState(107);
          dynamic_cast<ExprContext *>(_localctx)->rhs = expr(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->lhs = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(108);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(109);
          dynamic_cast<ExprContext *>(_localctx)->cmpop = match(JITLangParser::T__10);
          setState(110);
          dynamic_cast<ExprContext *>(_localctx)->rhs = expr(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->lhs = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(111);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(112);
          dynamic_cast<ExprContext *>(_localctx)->cmpop = match(JITLangParser::T__11);
          setState(113);
          dynamic_cast<ExprContext *>(_localctx)->rhs = expr(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->lhs = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(114);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(115);
          dynamic_cast<ExprContext *>(_localctx)->cmpop = match(JITLangParser::T__12);
          setState(116);
          dynamic_cast<ExprContext *>(_localctx)->rhs = expr(4);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->lhs = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(117);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(118);
          dynamic_cast<ExprContext *>(_localctx)->cmpop = match(JITLangParser::T__13);
          setState(119);
          dynamic_cast<ExprContext *>(_localctx)->rhs = expr(3);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->lhs = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(120);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(121);
          dynamic_cast<ExprContext *>(_localctx)->cmpop = match(JITLangParser::T__14);
          setState(122);
          dynamic_cast<ExprContext *>(_localctx)->rhs = expr(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(127);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Arg_listContext ------------------------------------------------------------------

JITLangParser::Arg_listContext::Arg_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JITLangParser::ExprContext *> JITLangParser::Arg_listContext::expr() {
  return getRuleContexts<JITLangParser::ExprContext>();
}

JITLangParser::ExprContext* JITLangParser::Arg_listContext::expr(size_t i) {
  return getRuleContext<JITLangParser::ExprContext>(i);
}


size_t JITLangParser::Arg_listContext::getRuleIndex() const {
  return JITLangParser::RuleArg_list;
}


JITLangParser::Arg_listContext* JITLangParser::arg_list() {
  Arg_listContext *_localctx = _tracker.createInstance<Arg_listContext>(_ctx, getState());
  enterRule(_localctx, 14, JITLangParser::RuleArg_list);
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
    setState(128);
    dynamic_cast<Arg_listContext *>(_localctx)->exprContext = expr(0);
    dynamic_cast<Arg_listContext *>(_localctx)->args.push_back(dynamic_cast<Arg_listContext *>(_localctx)->exprContext);
    setState(133);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JITLangParser::T__15) {
      setState(129);
      match(JITLangParser::T__15);
      setState(130);
      dynamic_cast<Arg_listContext *>(_localctx)->exprContext = expr(0);
      dynamic_cast<Arg_listContext *>(_localctx)->args.push_back(dynamic_cast<Arg_listContext *>(_localctx)->exprContext);
      setState(135);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_callContext ------------------------------------------------------------------

JITLangParser::Func_callContext::Func_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JITLangParser::Func_callContext::IDENT() {
  return getToken(JITLangParser::IDENT, 0);
}

JITLangParser::Arg_listContext* JITLangParser::Func_callContext::arg_list() {
  return getRuleContext<JITLangParser::Arg_listContext>(0);
}


size_t JITLangParser::Func_callContext::getRuleIndex() const {
  return JITLangParser::RuleFunc_call;
}


JITLangParser::Func_callContext* JITLangParser::func_call() {
  Func_callContext *_localctx = _tracker.createInstance<Func_callContext>(_ctx, getState());
  enterRule(_localctx, 16, JITLangParser::RuleFunc_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(144);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(136);
      match(JITLangParser::IDENT);
      setState(137);
      match(JITLangParser::T__2);
      setState(138);
      arg_list();
      setState(139);
      match(JITLangParser::T__3);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(141);
      match(JITLangParser::IDENT);
      setState(142);
      match(JITLangParser::T__2);
      setState(143);
      match(JITLangParser::T__3);
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

//----------------- Incr_decrContext ------------------------------------------------------------------

JITLangParser::Incr_decrContext::Incr_decrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JITLangParser::IncrContext* JITLangParser::Incr_decrContext::incr() {
  return getRuleContext<JITLangParser::IncrContext>(0);
}

JITLangParser::DecrContext* JITLangParser::Incr_decrContext::decr() {
  return getRuleContext<JITLangParser::DecrContext>(0);
}


size_t JITLangParser::Incr_decrContext::getRuleIndex() const {
  return JITLangParser::RuleIncr_decr;
}


JITLangParser::Incr_decrContext* JITLangParser::incr_decr() {
  Incr_decrContext *_localctx = _tracker.createInstance<Incr_decrContext>(_ctx, getState());
  enterRule(_localctx, 18, JITLangParser::RuleIncr_decr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(148);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(146);
      incr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(147);
      decr();
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

//----------------- IncrContext ------------------------------------------------------------------

JITLangParser::IncrContext::IncrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JITLangParser::IncrContext::IDENT() {
  return getToken(JITLangParser::IDENT, 0);
}


size_t JITLangParser::IncrContext::getRuleIndex() const {
  return JITLangParser::RuleIncr;
}


JITLangParser::IncrContext* JITLangParser::incr() {
  IncrContext *_localctx = _tracker.createInstance<IncrContext>(_ctx, getState());
  enterRule(_localctx, 20, JITLangParser::RuleIncr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    match(JITLangParser::IDENT);
    setState(151);
    match(JITLangParser::T__16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecrContext ------------------------------------------------------------------

JITLangParser::DecrContext::DecrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JITLangParser::DecrContext::IDENT() {
  return getToken(JITLangParser::IDENT, 0);
}


size_t JITLangParser::DecrContext::getRuleIndex() const {
  return JITLangParser::RuleDecr;
}


JITLangParser::DecrContext* JITLangParser::decr() {
  DecrContext *_localctx = _tracker.createInstance<DecrContext>(_ctx, getState());
  enterRule(_localctx, 22, JITLangParser::RuleDecr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(JITLangParser::IDENT);
    setState(154);
    match(JITLangParser::T__17);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

JITLangParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JITLangParser::LiteralContext::NUMBER() {
  return getToken(JITLangParser::NUMBER, 0);
}

tree::TerminalNode* JITLangParser::LiteralContext::STRING() {
  return getToken(JITLangParser::STRING, 0);
}


size_t JITLangParser::LiteralContext::getRuleIndex() const {
  return JITLangParser::RuleLiteral;
}


JITLangParser::LiteralContext* JITLangParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 24, JITLangParser::RuleLiteral);
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
    setState(156);
    _la = _input->LA(1);
    if (!(_la == JITLangParser::STRING

    || _la == JITLangParser::NUMBER)) {
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

bool JITLangParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool JITLangParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);
    case 4: return precpred(_ctx, 2);
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> JITLangParser::_decisionToDFA;
atn::PredictionContextCache JITLangParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN JITLangParser::_atn;
std::vector<uint16_t> JITLangParser::_serializedATN;

std::vector<std::string> JITLangParser::_ruleNames = {
  "file", "stmt", "function_define", "if_stmt", "define", "assign", "expr", 
  "arg_list", "func_call", "incr_decr", "incr", "decr", "literal"
};

std::vector<std::string> JITLangParser::_literalNames = {
  "", "'\n'", "'fn'", "'('", "')'", "'{'", "'}'", "'if'", "':'", "'='", 
  "'>'", "'<'", "'>='", "'<='", "'=='", "'!='", "','", "'++'", "'--'"
};

std::vector<std::string> JITLangParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "IDENT", "STRING", "NUMBER", "WHITESPACE", "COMMENT"
};

dfa::Vocabulary JITLangParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> JITLangParser::_tokenNames;

JITLangParser::Initializer::Initializer() {
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
    0x3, 0x19, 0xa1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x20, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x23, 0xb, 0x2, 0x3, 0x2, 0x5, 0x2, 0x26, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2f, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x36, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x39, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x7, 0x4, 0x3f, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x42, 0xb, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x7, 0x5, 0x4b, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x4e, 0xb, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x54, 0xa, 0x5, 0xc, 0x5, 
    0xe, 0x5, 0x57, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x6a, 
    0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x7e, 0xa, 
    0x8, 0xc, 0x8, 0xe, 0x8, 0x81, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x7, 0x9, 0x86, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x89, 0xb, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x5, 0xa, 0x93, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x97, 0xa, 0xb, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x2, 0x3, 0xe, 0xf, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x2, 0x3, 0x3, 0x2, 0x16, 0x17, 
    0x2, 0xaf, 0x2, 0x21, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x30, 0x3, 0x2, 0x2, 0x2, 0x8, 0x45, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x5a, 0x3, 0x2, 0x2, 0x2, 0xc, 0x60, 0x3, 0x2, 0x2, 0x2, 0xe, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x82, 0x3, 0x2, 0x2, 0x2, 0x12, 0x92, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x96, 0x3, 0x2, 0x2, 0x2, 0x16, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x9e, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x20, 0x5, 0x4, 0x3, 0x2, 0x1d, 0x20, 0x7, 0x3, 0x2, 0x2, 
    0x1e, 0x20, 0x7, 0x19, 0x2, 0x2, 0x1f, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1f, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x3, 
    0x2, 0x2, 0x2, 0x22, 0x25, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x24, 0x26, 0x5, 0x4, 0x3, 0x2, 0x25, 0x24, 0x3, 0x2, 0x2, 
    0x2, 0x25, 0x26, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x27, 0x28, 0x7, 0x2, 0x2, 0x3, 0x28, 0x3, 0x3, 0x2, 0x2, 0x2, 0x29, 
    0x2f, 0x5, 0xe, 0x8, 0x2, 0x2a, 0x2f, 0x5, 0x8, 0x5, 0x2, 0x2b, 0x2f, 
    0x5, 0x6, 0x4, 0x2, 0x2c, 0x2f, 0x5, 0xa, 0x6, 0x2, 0x2d, 0x2f, 0x5, 
    0xc, 0x7, 0x2, 0x2e, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2a, 0x3, 0x2, 
    0x2, 0x2, 0x2e, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x31, 0x7, 0x4, 0x2, 0x2, 0x31, 0x32, 0x7, 0x15, 0x2, 0x2, 0x32, 
    0x33, 0x7, 0x5, 0x2, 0x2, 0x33, 0x37, 0x7, 0x6, 0x2, 0x2, 0x34, 0x36, 
    0x7, 0x3, 0x2, 0x2, 0x35, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x3a, 0x40, 0x7, 0x7, 0x2, 0x2, 0x3b, 0x3f, 0x5, 0x4, 0x3, 0x2, 
    0x3c, 0x3f, 0x7, 0x3, 0x2, 0x2, 0x3d, 0x3f, 0x7, 0x19, 0x2, 0x2, 0x3e, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x3f, 0x42, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x7, 0x8, 0x2, 
    0x2, 0x44, 0x7, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x7, 0x9, 0x2, 0x2, 
    0x46, 0x47, 0x7, 0x5, 0x2, 0x2, 0x47, 0x48, 0x5, 0xe, 0x8, 0x2, 0x48, 
    0x4c, 0x7, 0x6, 0x2, 0x2, 0x49, 0x4b, 0x7, 0x3, 0x2, 0x2, 0x4a, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x4b, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 0x3, 
    0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x55, 0x7, 0x7, 0x2, 
    0x2, 0x50, 0x54, 0x5, 0x4, 0x3, 0x2, 0x51, 0x54, 0x7, 0x3, 0x2, 0x2, 
    0x52, 0x54, 0x7, 0x19, 0x2, 0x2, 0x53, 0x50, 0x3, 0x2, 0x2, 0x2, 0x53, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x53, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 0x57, 
    0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 
    0x2, 0x2, 0x2, 0x56, 0x58, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x59, 0x7, 0x8, 0x2, 0x2, 0x59, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x5b, 0x7, 0x15, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0xa, 0x2, 0x2, 
    0x5c, 0x5d, 0x7, 0x15, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0xb, 0x2, 0x2, 0x5e, 
    0x5f, 0x5, 0xe, 0x8, 0x2, 0x5f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 
    0x7, 0x15, 0x2, 0x2, 0x61, 0x62, 0x7, 0xb, 0x2, 0x2, 0x62, 0x63, 0x5, 
    0xe, 0x8, 0x2, 0x63, 0xd, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x8, 0x8, 
    0x1, 0x2, 0x65, 0x6a, 0x5, 0x1a, 0xe, 0x2, 0x66, 0x6a, 0x7, 0x15, 0x2, 
    0x2, 0x67, 0x6a, 0x5, 0x14, 0xb, 0x2, 0x68, 0x6a, 0x5, 0x12, 0xa, 0x2, 
    0x69, 0x64, 0x3, 0x2, 0x2, 0x2, 0x69, 0x66, 0x3, 0x2, 0x2, 0x2, 0x69, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x7f, 
    0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0xc, 0x8, 0x2, 0x2, 0x6c, 0x6d, 0x7, 
    0xc, 0x2, 0x2, 0x6d, 0x7e, 0x5, 0xe, 0x8, 0x9, 0x6e, 0x6f, 0xc, 0x7, 
    0x2, 0x2, 0x6f, 0x70, 0x7, 0xd, 0x2, 0x2, 0x70, 0x7e, 0x5, 0xe, 0x8, 
    0x8, 0x71, 0x72, 0xc, 0x6, 0x2, 0x2, 0x72, 0x73, 0x7, 0xe, 0x2, 0x2, 
    0x73, 0x7e, 0x5, 0xe, 0x8, 0x7, 0x74, 0x75, 0xc, 0x5, 0x2, 0x2, 0x75, 
    0x76, 0x7, 0xf, 0x2, 0x2, 0x76, 0x7e, 0x5, 0xe, 0x8, 0x6, 0x77, 0x78, 
    0xc, 0x4, 0x2, 0x2, 0x78, 0x79, 0x7, 0x10, 0x2, 0x2, 0x79, 0x7e, 0x5, 
    0xe, 0x8, 0x5, 0x7a, 0x7b, 0xc, 0x3, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x11, 
    0x2, 0x2, 0x7c, 0x7e, 0x5, 0xe, 0x8, 0x4, 0x7d, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x7d, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x7d, 0x74, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x77, 0x3, 0x2, 0x2, 0x2, 0x7d, 
    0x7a, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 
    0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x82, 0x87, 0x5, 0xe, 
    0x8, 0x2, 0x83, 0x84, 0x7, 0x12, 0x2, 0x2, 0x84, 0x86, 0x5, 0xe, 0x8, 
    0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x86, 0x89, 0x3, 0x2, 0x2, 0x2, 
    0x87, 0x85, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 
    0x7, 0x15, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x5, 0x2, 0x2, 0x8c, 0x8d, 0x5, 
    0x10, 0x9, 0x2, 0x8d, 0x8e, 0x7, 0x6, 0x2, 0x2, 0x8e, 0x93, 0x3, 0x2, 
    0x2, 0x2, 0x8f, 0x90, 0x7, 0x15, 0x2, 0x2, 0x90, 0x91, 0x7, 0x5, 0x2, 
    0x2, 0x91, 0x93, 0x7, 0x6, 0x2, 0x2, 0x92, 0x8a, 0x3, 0x2, 0x2, 0x2, 
    0x92, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x93, 0x13, 0x3, 0x2, 0x2, 0x2, 0x94, 
    0x97, 0x5, 0x16, 0xc, 0x2, 0x95, 0x97, 0x5, 0x18, 0xd, 0x2, 0x96, 0x94, 
    0x3, 0x2, 0x2, 0x2, 0x96, 0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x98, 0x99, 0x7, 0x15, 0x2, 0x2, 0x99, 0x9a, 0x7, 0x13, 
    0x2, 0x2, 0x9a, 0x17, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x15, 0x2, 
    0x2, 0x9c, 0x9d, 0x7, 0x14, 0x2, 0x2, 0x9d, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x9e, 0x9f, 0x9, 0x2, 0x2, 0x2, 0x9f, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x1f, 0x21, 0x25, 0x2e, 0x37, 0x3e, 0x40, 0x4c, 0x53, 0x55, 0x69, 0x7d, 
    0x7f, 0x87, 0x92, 0x96, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

JITLangParser::Initializer JITLangParser::_init;
