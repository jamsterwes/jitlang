#include "Parser.h"
#include "ast/AssignmentNode.h"
#include "ast/BlockNode.h"
#include "ast/CompareNode.h"
#include "ast/DecrNode.h"
#include "ast/DefinitionNode.h"
#include "ast/FuncCallNode.h"
#include "ast/FunctionDefinitionNode.h"
#include "ast/IdentifierNode.h"
#include "ast/IfNode.h"
#include "ast/IncrNode.h"
#include "ast/NumberLiteralNode.h"
#include "ast/StringLiteralNode.h"

namespace jitlang
{
    ASTNode* Parser::visitFile(JITLangParser::FileContext* ctx)
    {
        std::vector<ASTNode*> statements{};
        for (auto* stmt : ctx->statements)
        {
            statements.push_back(visitStmt(stmt));
        }
        return new BlockNode(statements);
    }

    ASTNode* Parser::visitStmt(JITLangParser::StmtContext* ctx)
    {
        if (ctx->expr()) return visitExpr(ctx->expr());
        else if (ctx->if_stmt()) return visitIfStmt(ctx->if_stmt());
        else if (ctx->function_define()) return visitFunctionDefine(ctx->function_define());
        else if (ctx->define()) return visitDefine(ctx->define());
        else if (ctx->assign()) return visitAssign(ctx->assign());
        else return nullptr;
    }

    ASTNode* Parser::visitIfStmt(JITLangParser::If_stmtContext* ctx)
    {
        std::vector<ASTNode*> statements{};
        for (auto* stmt : ctx->statements)
        {
            statements.push_back(visitStmt(stmt));
        }
        return new IfNode(visitExpr(ctx->cond), new BlockNode(statements));
    }

    ASTNode* Parser::visitFunctionDefine(JITLangParser::Function_defineContext* ctx)
    {
        std::vector<ASTNode*> statements{};
        for (auto* stmt : ctx->statements)
        {
            statements.push_back(visitStmt(stmt));
        }
        return new FunctionDefinitionNode(ctx->IDENT()->getText(), new BlockNode(statements));
    }

    ASTNode* Parser::visitDefine(JITLangParser::DefineContext* ctx)
    {
        return new DefinitionNode(ctx->name->getText(), ctx->type->getText(), visitExpr(ctx->value));
    }

    ASTNode* Parser::visitAssign(JITLangParser::AssignContext* ctx)
    {
        return new AssignmentNode(ctx->name->getText(), visitExpr(ctx->value));
    }

    ASTNode* Parser::visitExpr(JITLangParser::ExprContext* ctx)
    {
        if (ctx->cmpop) return visitCompareExpr(ctx);
        else if (ctx->literal()) return visitLiteral(ctx->literal());
        else if (ctx->IDENT()) return new IdentifierNode(ctx->IDENT()->getText());
        else if (ctx->incr_decr()) return visitIncrDecr(ctx->incr_decr());
        else if (ctx->func_call()) return visitFuncCall(ctx->func_call());
        else return nullptr;
    }

    ASTNode* Parser::visitCompareExpr(JITLangParser::ExprContext* ctx)
    {
        return new CompareNode(visitExpr(ctx->lhs), visitExpr(ctx->rhs), ctx->cmpop->getText());
    }

    ASTNode* Parser::visitLiteral(JITLangParser::LiteralContext* ctx)
    {
        if (ctx->NUMBER()) return new NumberLiteralNode(ctx->NUMBER()->getText());
        else if (ctx->STRING()) return new StringLiteralNode(ctx->STRING()->getText());
        else return nullptr;
    }

    ASTNode* Parser::visitIncrDecr(JITLangParser::Incr_decrContext* ctx)
    {
        if (ctx->incr()) return new IncrNode(new IdentifierNode(ctx->incr()->IDENT()->getText()));
        else if (ctx->decr()) return new DecrNode(new IdentifierNode(ctx->decr()->IDENT()->getText()));
        else return nullptr;
    }

    ASTNode* Parser::visitFuncCall(JITLangParser::Func_callContext* ctx)
    {
        if (!ctx->arg_list()) return new FuncCallNode(ctx->IDENT()->getText(), {});
    
        std::vector<ASTNode*> args{};
        for (auto* argExpr : ctx->arg_list()->args)
        {
            args.push_back(visitExpr(argExpr));
        }

        return new FuncCallNode(ctx->IDENT()->getText(), args);
    }
}