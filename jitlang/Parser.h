#pragma once

#include <antlr4-runtime.h>
#include "ast/ASTNode.h"
#include "ast/BlockNode.h"
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
        // Visit function call
        ASTNode* visitFuncCall(JITLangParser::Func_callContext* ctx);
        // Visit atom
        ASTNode* visitAtom(JITLangParser::AtomContext* ctx);
        // Visit literal
        ASTNode* visitLiteral(JITLangParser::LiteralContext* ctx);
    private:
        // Handle special expr cases
        ASTNode* visitPostExpr(JITLangParser::ExprContext* ctx);
        ASTNode* visitPreExpr(JITLangParser::ExprContext* ctx);
        ASTNode* visitBinOpExpr(JITLangParser::ExprContext* ctx, std::string binOp);
        ASTNode* visitTernExpr(JITLangParser::ExprContext* ctx);
        // Handle function/if/file statements
        BlockNode* visitStatements(std::vector<JITLangParser::StmtContext*> statements);
    };
}