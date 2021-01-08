#pragma once

#include <antlr4-runtime.h>
#include "ast/ASTNode.h"
#include "grammar/JITLangParser.h"
    
namespace jitlang
{
    class Parser
    {
    public:
        // Visit file (returns root node)
        ASTNode* visitFile(JITLangParser::FileContext* ctx);
        // Visit stmt
        ASTNode* visitStmt(JITLangParser::StmtContext* ctx);
        // Visit if stmt
        ASTNode* visitIfStmt(JITLangParser::If_stmtContext* ctx);
        // Visit function define
        ASTNode* visitFunctionDefine(JITLangParser::Function_defineContext* ctx);
        // Visit define
        ASTNode* visitDefine(JITLangParser::DefineContext* ctx);
        // Visit assign
        ASTNode* visitAssign(JITLangParser::AssignContext* ctx);
        // Visit expr
        ASTNode* visitExpr(JITLangParser::ExprContext* ctx);
        ASTNode* visitCompareExpr(JITLangParser::ExprContext* ctx);
        // Visit literal
        ASTNode* visitLiteral(JITLangParser::LiteralContext* ctx);
        // Visit incr/decr
        ASTNode* visitIncrDecr(JITLangParser::Incr_decrContext* ctx);
        // Visit function call
        ASTNode* visitFuncCall(JITLangParser::Func_callContext* ctx);
    private:
        // Possibly keep up with preprocessor directives, etc here(?)
    };
}