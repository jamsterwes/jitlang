
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
          case JITLangParser::T__2:
          case JITLangParser::T__7:
          case JITLangParser::T__10:
          case JITLangParser::T__11:
          case JITLangParser::T__12:
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
      | (1ULL << JITLangParser::T__2)
      | (1ULL << JITLangParser::T__7)
      | (1ULL << JITLangParser::T__10)
      | (1ULL << JITLangParser::T__11)
      | (1ULL << JITLangParser::T__12)
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

std::vector<tree::TerminalNode *> JITLangParser::Function_defineContext::IDENT() {
  return getTokens(JITLangParser::IDENT);
}

tree::TerminalNode* JITLangParser::Function_defineContext::IDENT(size_t i) {
  return getToken(JITLangParser::IDENT, i);
}

JITLangParser::Typed_arg_listContext* JITLangParser::Function_defineContext::typed_arg_list() {
  return getRuleContext<JITLangParser::Typed_arg_listContext>(0);
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
    dynamic_cast<Function_defineContext *>(_localctx)->name = match(JITLangParser::IDENT);
    setState(48);
    match(JITLangParser::T__2);
    setState(50);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JITLangParser::IDENT) {
      setState(49);
      typed_arg_list();
    }
    setState(52);
    match(JITLangParser::T__3);
    setState(55);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JITLangParser::T__4) {
      setState(53);
      match(JITLangParser::T__4);
      setState(54);
      dynamic_cast<Function_defineContext *>(_localctx)->rettype = match(JITLangParser::IDENT);
    }
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JITLangParser::T__0) {
      setState(57);
      match(JITLangParser::T__0);
      setState(62);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(63);
    match(JITLangParser::T__5);
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JITLangParser::T__0)
      | (1ULL << JITLangParser::T__1)
      | (1ULL << JITLangParser::T__2)
      | (1ULL << JITLangParser::T__7)
      | (1ULL << JITLangParser::T__10)
      | (1ULL << JITLangParser::T__11)
      | (1ULL << JITLangParser::T__12)
      | (1ULL << JITLangParser::IDENT)
      | (1ULL << JITLangParser::STRING)
      | (1ULL << JITLangParser::NUMBER)
      | (1ULL << JITLangParser::COMMENT))) != 0)) {
      setState(67);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case JITLangParser::T__1:
        case JITLangParser::T__2:
        case JITLangParser::T__7:
        case JITLangParser::T__10:
        case JITLangParser::T__11:
        case JITLangParser::T__12:
        case JITLangParser::IDENT:
        case JITLangParser::STRING:
        case JITLangParser::NUMBER: {
          setState(64);
          dynamic_cast<Function_defineContext *>(_localctx)->stmtContext = stmt();
          dynamic_cast<Function_defineContext *>(_localctx)->statements.push_back(dynamic_cast<Function_defineContext *>(_localctx)->stmtContext);
          break;
        }

        case JITLangParser::T__0: {
          setState(65);
          match(JITLangParser::T__0);
          break;
        }

        case JITLangParser::COMMENT: {
          setState(66);
          match(JITLangParser::COMMENT);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(71);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(72);
    match(JITLangParser::T__6);
   
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
    setState(74);
    match(JITLangParser::T__7);
    setState(75);
    match(JITLangParser::T__2);
    setState(76);
    dynamic_cast<If_stmtContext *>(_localctx)->cond = expr(0);
    setState(77);
    match(JITLangParser::T__3);
    setState(81);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JITLangParser::T__0) {
      setState(78);
      match(JITLangParser::T__0);
      setState(83);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(84);
    match(JITLangParser::T__5);
    setState(90);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JITLangParser::T__0)
      | (1ULL << JITLangParser::T__1)
      | (1ULL << JITLangParser::T__2)
      | (1ULL << JITLangParser::T__7)
      | (1ULL << JITLangParser::T__10)
      | (1ULL << JITLangParser::T__11)
      | (1ULL << JITLangParser::T__12)
      | (1ULL << JITLangParser::IDENT)
      | (1ULL << JITLangParser::STRING)
      | (1ULL << JITLangParser::NUMBER)
      | (1ULL << JITLangParser::COMMENT))) != 0)) {
      setState(88);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case JITLangParser::T__1:
        case JITLangParser::T__2:
        case JITLangParser::T__7:
        case JITLangParser::T__10:
        case JITLangParser::T__11:
        case JITLangParser::T__12:
        case JITLangParser::IDENT:
        case JITLangParser::STRING:
        case JITLangParser::NUMBER: {
          setState(85);
          dynamic_cast<If_stmtContext *>(_localctx)->stmtContext = stmt();
          dynamic_cast<If_stmtContext *>(_localctx)->statements.push_back(dynamic_cast<If_stmtContext *>(_localctx)->stmtContext);
          break;
        }

        case JITLangParser::T__0: {
          setState(86);
          match(JITLangParser::T__0);
          break;
        }

        case JITLangParser::COMMENT: {
          setState(87);
          match(JITLangParser::COMMENT);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(93);
    match(JITLangParser::T__6);
   
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
    setState(95);
    dynamic_cast<DefineContext *>(_localctx)->name = match(JITLangParser::IDENT);
    setState(96);
    match(JITLangParser::T__8);
    setState(97);
    dynamic_cast<DefineContext *>(_localctx)->type = match(JITLangParser::IDENT);
    setState(98);
    match(JITLangParser::T__9);
    setState(99);
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
    setState(101);
    dynamic_cast<AssignContext *>(_localctx)->name = match(JITLangParser::IDENT);
    setState(102);
    match(JITLangParser::T__9);
    setState(103);
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

JITLangParser::Func_callContext* JITLangParser::ExprContext::func_call() {
  return getRuleContext<JITLangParser::Func_callContext>(0);
}

JITLangParser::AtomContext* JITLangParser::ExprContext::atom() {
  return getRuleContext<JITLangParser::AtomContext>(0);
}

std::vector<JITLangParser::ExprContext *> JITLangParser::ExprContext::expr() {
  return getRuleContexts<JITLangParser::ExprContext>();
}

JITLangParser::ExprContext* JITLangParser::ExprContext::expr(size_t i) {
  return getRuleContext<JITLangParser::ExprContext>(i);
}

tree::TerminalNode* JITLangParser::ExprContext::AND() {
  return getToken(JITLangParser::AND, 0);
}

tree::TerminalNode* JITLangParser::ExprContext::OR() {
  return getToken(JITLangParser::OR, 0);
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

    size_t _la = 0;

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
    setState(114);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(106);
      func_call();
      break;
    }

    case 2: {
      setState(107);
      atom();
      break;
    }

    case 3: {
      setState(108);
      dynamic_cast<ExprContext *>(_localctx)->preop = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JITLangParser::T__10)
        | (1ULL << JITLangParser::T__11)
        | (1ULL << JITLangParser::T__12))) != 0))) {
        dynamic_cast<ExprContext *>(_localctx)->preop = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(109);
      expr(9);
      break;
    }

    case 4: {
      setState(110);
      match(JITLangParser::T__2);
      setState(111);
      dynamic_cast<ExprContext *>(_localctx)->paren = expr(0);
      setState(112);
      match(JITLangParser::T__3);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(144);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(142);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(116);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(117);
          dynamic_cast<ExprContext *>(_localctx)->mult = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << JITLangParser::T__13)
            | (1ULL << JITLangParser::T__14)
            | (1ULL << JITLangParser::T__15))) != 0))) {
            dynamic_cast<ExprContext *>(_localctx)->mult = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(118);
          expr(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(119);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(120);
          dynamic_cast<ExprContext *>(_localctx)->add = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == JITLangParser::T__16

          || _la == JITLangParser::T__17)) {
            dynamic_cast<ExprContext *>(_localctx)->add = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(121);
          expr(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(122);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(123);
          dynamic_cast<ExprContext *>(_localctx)->gt = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << JITLangParser::T__18)
            | (1ULL << JITLangParser::T__19)
            | (1ULL << JITLangParser::T__20)
            | (1ULL << JITLangParser::T__21))) != 0))) {
            dynamic_cast<ExprContext *>(_localctx)->gt = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(124);
          expr(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(125);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(126);
          dynamic_cast<ExprContext *>(_localctx)->eq = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == JITLangParser::T__22

          || _la == JITLangParser::T__23)) {
            dynamic_cast<ExprContext *>(_localctx)->eq = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(127);
          expr(6);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(128);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(129);
          dynamic_cast<ExprContext *>(_localctx)->logAnd = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == JITLangParser::T__24

          || _la == JITLangParser::AND)) {
            dynamic_cast<ExprContext *>(_localctx)->logAnd = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(130);
          expr(4);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(131);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(132);
          dynamic_cast<ExprContext *>(_localctx)->logOr = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == JITLangParser::T__25

          || _la == JITLangParser::OR)) {
            dynamic_cast<ExprContext *>(_localctx)->logOr = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(133);
          expr(3);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->cond = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(134);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(135);
          dynamic_cast<ExprContext *>(_localctx)->tern = match(JITLangParser::T__26);
          setState(136);
          dynamic_cast<ExprContext *>(_localctx)->t = expr(0);
          setState(137);
          match(JITLangParser::T__8);
          setState(138);
          dynamic_cast<ExprContext *>(_localctx)->f = expr(2);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(140);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(141);
          dynamic_cast<ExprContext *>(_localctx)->postop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == JITLangParser::T__10

          || _la == JITLangParser::T__11)) {
            dynamic_cast<ExprContext *>(_localctx)->postop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        default:
          break;
        } 
      }
      setState(146);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

JITLangParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JITLangParser::LiteralContext* JITLangParser::AtomContext::literal() {
  return getRuleContext<JITLangParser::LiteralContext>(0);
}

tree::TerminalNode* JITLangParser::AtomContext::IDENT() {
  return getToken(JITLangParser::IDENT, 0);
}


size_t JITLangParser::AtomContext::getRuleIndex() const {
  return JITLangParser::RuleAtom;
}


JITLangParser::AtomContext* JITLangParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 14, JITLangParser::RuleAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(149);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JITLangParser::STRING:
      case JITLangParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(147);
        literal();
        break;
      }

      case JITLangParser::IDENT: {
        enterOuterAlt(_localctx, 2);
        setState(148);
        match(JITLangParser::IDENT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Typed_arg_listContext ------------------------------------------------------------------

JITLangParser::Typed_arg_listContext::Typed_arg_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JITLangParser::Typed_argContext *> JITLangParser::Typed_arg_listContext::typed_arg() {
  return getRuleContexts<JITLangParser::Typed_argContext>();
}

JITLangParser::Typed_argContext* JITLangParser::Typed_arg_listContext::typed_arg(size_t i) {
  return getRuleContext<JITLangParser::Typed_argContext>(i);
}


size_t JITLangParser::Typed_arg_listContext::getRuleIndex() const {
  return JITLangParser::RuleTyped_arg_list;
}


JITLangParser::Typed_arg_listContext* JITLangParser::typed_arg_list() {
  Typed_arg_listContext *_localctx = _tracker.createInstance<Typed_arg_listContext>(_ctx, getState());
  enterRule(_localctx, 16, JITLangParser::RuleTyped_arg_list);
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
    setState(151);
    dynamic_cast<Typed_arg_listContext *>(_localctx)->typed_argContext = typed_arg();
    dynamic_cast<Typed_arg_listContext *>(_localctx)->args.push_back(dynamic_cast<Typed_arg_listContext *>(_localctx)->typed_argContext);
    setState(156);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JITLangParser::T__27) {
      setState(152);
      match(JITLangParser::T__27);
      setState(153);
      dynamic_cast<Typed_arg_listContext *>(_localctx)->typed_argContext = typed_arg();
      dynamic_cast<Typed_arg_listContext *>(_localctx)->args.push_back(dynamic_cast<Typed_arg_listContext *>(_localctx)->typed_argContext);
      setState(158);
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

//----------------- Typed_argContext ------------------------------------------------------------------

JITLangParser::Typed_argContext::Typed_argContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> JITLangParser::Typed_argContext::IDENT() {
  return getTokens(JITLangParser::IDENT);
}

tree::TerminalNode* JITLangParser::Typed_argContext::IDENT(size_t i) {
  return getToken(JITLangParser::IDENT, i);
}


size_t JITLangParser::Typed_argContext::getRuleIndex() const {
  return JITLangParser::RuleTyped_arg;
}


JITLangParser::Typed_argContext* JITLangParser::typed_arg() {
  Typed_argContext *_localctx = _tracker.createInstance<Typed_argContext>(_ctx, getState());
  enterRule(_localctx, 18, JITLangParser::RuleTyped_arg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    dynamic_cast<Typed_argContext *>(_localctx)->name = match(JITLangParser::IDENT);
    setState(160);
    match(JITLangParser::T__8);
    setState(161);
    dynamic_cast<Typed_argContext *>(_localctx)->type = match(JITLangParser::IDENT);
   
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
  enterRule(_localctx, 20, JITLangParser::RuleArg_list);
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
    setState(163);
    dynamic_cast<Arg_listContext *>(_localctx)->exprContext = expr(0);
    dynamic_cast<Arg_listContext *>(_localctx)->args.push_back(dynamic_cast<Arg_listContext *>(_localctx)->exprContext);
    setState(168);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JITLangParser::T__27) {
      setState(164);
      match(JITLangParser::T__27);
      setState(165);
      dynamic_cast<Arg_listContext *>(_localctx)->exprContext = expr(0);
      dynamic_cast<Arg_listContext *>(_localctx)->args.push_back(dynamic_cast<Arg_listContext *>(_localctx)->exprContext);
      setState(170);
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
  enterRule(_localctx, 22, JITLangParser::RuleFunc_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(179);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(171);
      match(JITLangParser::IDENT);
      setState(172);
      match(JITLangParser::T__2);
      setState(173);
      arg_list();
      setState(174);
      match(JITLangParser::T__3);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(176);
      match(JITLangParser::IDENT);
      setState(177);
      match(JITLangParser::T__2);
      setState(178);
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
    setState(181);
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
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);
    case 6: return precpred(_ctx, 1);
    case 7: return precpred(_ctx, 10);

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
  "atom", "typed_arg_list", "typed_arg", "arg_list", "func_call", "literal"
};

std::vector<std::string> JITLangParser::_literalNames = {
  "", "'\n'", "'fn'", "'('", "')'", "'->'", "'{'", "'}'", "'if'", "':'", 
  "'='", "'++'", "'--'", "'!'", "'*'", "'/'", "'%'", "'+'", "'-'", "'>'", 
  "'>='", "'<='", "'<'", "'=='", "'!='", "'&&'", "'||'", "'\u003F'", "','", 
  "'and'", "'or'"
};

std::vector<std::string> JITLangParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "AND", "OR", "IDENT", "STRING", 
  "NUMBER", "WHITESPACE", "COMMENT"
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
    0x3, 0x25, 0xba, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x20, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x23, 0xb, 0x2, 0x3, 0x2, 0x5, 0x2, 0x26, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2f, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x35, 0xa, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x3a, 0xa, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x3d, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x40, 0xb, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x46, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0x49, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x7, 0x5, 0x52, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x55, 0xb, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x5b, 0xa, 0x5, 
    0xc, 0x5, 0xe, 0x5, 0x5e, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x75, 0xa, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x91, 0xa, 0x8, 0xc, 
    0x8, 0xe, 0x8, 0x94, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x98, 0xa, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x9d, 0xa, 0xa, 0xc, 0xa, 
    0xe, 0xa, 0xa0, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xa9, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 
    0xac, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xb6, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x2, 0x3, 0xe, 0xf, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x2, 0xb, 0x3, 0x2, 0xd, 0xf, 0x3, 0x2, 
    0x10, 0x12, 0x3, 0x2, 0x13, 0x14, 0x3, 0x2, 0x15, 0x18, 0x3, 0x2, 0x19, 
    0x1a, 0x4, 0x2, 0x1b, 0x1b, 0x1f, 0x1f, 0x4, 0x2, 0x1c, 0x1c, 0x20, 
    0x20, 0x3, 0x2, 0xd, 0xe, 0x3, 0x2, 0x22, 0x23, 0x2, 0xcd, 0x2, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x30, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x4c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x67, 0x3, 0x2, 0x2, 0x2, 0xe, 0x74, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x12, 0x99, 0x3, 0x2, 0x2, 0x2, 0x14, 0xa1, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x18, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x20, 0x5, 0x4, 
    0x3, 0x2, 0x1d, 0x20, 0x7, 0x3, 0x2, 0x2, 0x1e, 0x20, 0x7, 0x25, 0x2, 
    0x2, 0x1f, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x23, 0x3, 0x2, 0x2, 0x2, 0x21, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x24, 0x26, 0x5, 
    0x4, 0x3, 0x2, 0x25, 0x24, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x3, 0x2, 
    0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x7, 0x2, 0x2, 
    0x3, 0x28, 0x3, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2f, 0x5, 0xe, 0x8, 0x2, 
    0x2a, 0x2f, 0x5, 0x8, 0x5, 0x2, 0x2b, 0x2f, 0x5, 0x6, 0x4, 0x2, 0x2c, 
    0x2f, 0x5, 0xa, 0x6, 0x2, 0x2d, 0x2f, 0x5, 0xc, 0x7, 0x2, 0x2e, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x2f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x7, 0x4, 0x2, 
    0x2, 0x31, 0x32, 0x7, 0x21, 0x2, 0x2, 0x32, 0x34, 0x7, 0x5, 0x2, 0x2, 
    0x33, 0x35, 0x5, 0x12, 0xa, 0x2, 0x34, 0x33, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x39, 
    0x7, 0x6, 0x2, 0x2, 0x37, 0x38, 0x7, 0x7, 0x2, 0x2, 0x38, 0x3a, 0x7, 
    0x21, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3d, 0x7, 0x3, 0x2, 
    0x2, 0x3c, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x40, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x41, 0x47, 
    0x7, 0x8, 0x2, 0x2, 0x42, 0x46, 0x5, 0x4, 0x3, 0x2, 0x43, 0x46, 0x7, 
    0x3, 0x2, 0x2, 0x44, 0x46, 0x7, 0x25, 0x2, 0x2, 0x45, 0x42, 0x3, 0x2, 
    0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x44, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x49, 0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x47, 0x48, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x49, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x9, 0x2, 0x2, 0x4b, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0xa, 0x2, 0x2, 0x4d, 0x4e, 0x7, 
    0x5, 0x2, 0x2, 0x4e, 0x4f, 0x5, 0xe, 0x8, 0x2, 0x4f, 0x53, 0x7, 0x6, 
    0x2, 0x2, 0x50, 0x52, 0x7, 0x3, 0x2, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x55, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x56, 0x3, 0x2, 0x2, 0x2, 0x55, 
    0x53, 0x3, 0x2, 0x2, 0x2, 0x56, 0x5c, 0x7, 0x8, 0x2, 0x2, 0x57, 0x5b, 
    0x5, 0x4, 0x3, 0x2, 0x58, 0x5b, 0x7, 0x3, 0x2, 0x2, 0x59, 0x5b, 0x7, 
    0x25, 0x2, 0x2, 0x5a, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x5a, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5e, 0x3, 0x2, 0x2, 
    0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 0x2, 0x2, 
    0x5d, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5f, 
    0x60, 0x7, 0x9, 0x2, 0x2, 0x60, 0x9, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 
    0x7, 0x21, 0x2, 0x2, 0x62, 0x63, 0x7, 0xb, 0x2, 0x2, 0x63, 0x64, 0x7, 
    0x21, 0x2, 0x2, 0x64, 0x65, 0x7, 0xc, 0x2, 0x2, 0x65, 0x66, 0x5, 0xe, 
    0x8, 0x2, 0x66, 0xb, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x21, 0x2, 
    0x2, 0x68, 0x69, 0x7, 0xc, 0x2, 0x2, 0x69, 0x6a, 0x5, 0xe, 0x8, 0x2, 
    0x6a, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x8, 0x8, 0x1, 0x2, 0x6c, 
    0x75, 0x5, 0x18, 0xd, 0x2, 0x6d, 0x75, 0x5, 0x10, 0x9, 0x2, 0x6e, 0x6f, 
    0x9, 0x2, 0x2, 0x2, 0x6f, 0x75, 0x5, 0xe, 0x8, 0xb, 0x70, 0x71, 0x7, 
    0x5, 0x2, 0x2, 0x71, 0x72, 0x5, 0xe, 0x8, 0x2, 0x72, 0x73, 0x7, 0x6, 
    0x2, 0x2, 0x73, 0x75, 0x3, 0x2, 0x2, 0x2, 0x74, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x74, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x74, 0x6e, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x70, 0x3, 0x2, 0x2, 0x2, 0x75, 0x92, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x77, 0xc, 0xa, 0x2, 0x2, 0x77, 0x78, 0x9, 0x3, 0x2, 0x2, 0x78, 0x91, 
    0x5, 0xe, 0x8, 0xb, 0x79, 0x7a, 0xc, 0x9, 0x2, 0x2, 0x7a, 0x7b, 0x9, 
    0x4, 0x2, 0x2, 0x7b, 0x91, 0x5, 0xe, 0x8, 0xa, 0x7c, 0x7d, 0xc, 0x8, 
    0x2, 0x2, 0x7d, 0x7e, 0x9, 0x5, 0x2, 0x2, 0x7e, 0x91, 0x5, 0xe, 0x8, 
    0x9, 0x7f, 0x80, 0xc, 0x7, 0x2, 0x2, 0x80, 0x81, 0x9, 0x6, 0x2, 0x2, 
    0x81, 0x91, 0x5, 0xe, 0x8, 0x8, 0x82, 0x83, 0xc, 0x5, 0x2, 0x2, 0x83, 
    0x84, 0x9, 0x7, 0x2, 0x2, 0x84, 0x91, 0x5, 0xe, 0x8, 0x6, 0x85, 0x86, 
    0xc, 0x4, 0x2, 0x2, 0x86, 0x87, 0x9, 0x8, 0x2, 0x2, 0x87, 0x91, 0x5, 
    0xe, 0x8, 0x5, 0x88, 0x89, 0xc, 0x3, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x1d, 
    0x2, 0x2, 0x8a, 0x8b, 0x5, 0xe, 0x8, 0x2, 0x8b, 0x8c, 0x7, 0xb, 0x2, 
    0x2, 0x8c, 0x8d, 0x5, 0xe, 0x8, 0x4, 0x8d, 0x91, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x8f, 0xc, 0xc, 0x2, 0x2, 0x8f, 0x91, 0x9, 0x9, 0x2, 0x2, 0x90, 
    0x76, 0x3, 0x2, 0x2, 0x2, 0x90, 0x79, 0x3, 0x2, 0x2, 0x2, 0x90, 0x7c, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x90, 0x82, 0x3, 
    0x2, 0x2, 0x2, 0x90, 0x85, 0x3, 0x2, 0x2, 0x2, 0x90, 0x88, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x91, 0x94, 0x3, 0x2, 0x2, 
    0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x93, 0xf, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 0x2, 0x95, 
    0x98, 0x5, 0x1a, 0xe, 0x2, 0x96, 0x98, 0x7, 0x21, 0x2, 0x2, 0x97, 0x95, 
    0x3, 0x2, 0x2, 0x2, 0x97, 0x96, 0x3, 0x2, 0x2, 0x2, 0x98, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x9e, 0x5, 0x14, 0xb, 0x2, 0x9a, 0x9b, 0x7, 0x1e, 
    0x2, 0x2, 0x9b, 0x9d, 0x5, 0x14, 0xb, 0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 
    0x2, 0x9d, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 
    0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa0, 
    0x9e, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x21, 0x2, 0x2, 0xa2, 0xa3, 
    0x7, 0xb, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x21, 0x2, 0x2, 0xa4, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0xa5, 0xaa, 0x5, 0xe, 0x8, 0x2, 0xa6, 0xa7, 0x7, 0x1e, 
    0x2, 0x2, 0xa7, 0xa9, 0x5, 0xe, 0x8, 0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 
    0x2, 0xa9, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 
    0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0x17, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0xaa, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x7, 0x21, 0x2, 0x2, 0xae, 0xaf, 
    0x7, 0x5, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x16, 0xc, 0x2, 0xb0, 0xb1, 0x7, 
    0x6, 0x2, 0x2, 0xb1, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0x21, 
    0x2, 0x2, 0xb3, 0xb4, 0x7, 0x5, 0x2, 0x2, 0xb4, 0xb6, 0x7, 0x6, 0x2, 
    0x2, 0xb5, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb2, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0x19, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x9, 0xa, 0x2, 0x2, 0xb8, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0x15, 0x1f, 0x21, 0x25, 0x2e, 0x34, 0x39, 
    0x3e, 0x45, 0x47, 0x53, 0x5a, 0x5c, 0x74, 0x90, 0x92, 0x97, 0x9e, 0xaa, 
    0xb5, 
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
