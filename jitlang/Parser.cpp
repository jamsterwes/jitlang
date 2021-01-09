#include "Parser.h"
#include "ast/ASTNode.h"
#include "ast/BinOpNode.h"
#include "ast/BlockNode.h"
#include "ast/ConstNode.h"
#include "ast/DefVarNode.h"
#include "ast/FuncCallNode.h"
#include "ast/FuncDefineNode.h"
#include "ast/GetVarNode.h"
#include "ast/IfNode.h"
#include "ast/PostOpNode.h"
#include "ast/PreOpNode.h"
#include "ast/SetVarNode.h"

namespace jitlang
{
    ASTNode* Parser::visitFile(JITLangParser::FileContext* ctx)
    {
        return visitStatements(ctx->statements);
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
        return new IfNode(visitExpr(ctx->expr()), visitStatements(ctx->statements));
    }

    ASTNode* Parser::visitFunctionDefine(JITLangParser::Function_defineContext* ctx)
    {
        // TODO: handle arguments/return-typing
        return new FuncDefineNode(ctx->IDENT()->getText(), {}, visitStatements(ctx->statements));
    }

    ASTNode* Parser::visitDefine(JITLangParser::DefineContext* ctx)
    {
        ASTValueType ty;
        std::string typeName = ctx->type->getText();
        if (typeName == "str") ty = ASTValueType::STRING;
        else if (typeName == "bool") ty = ASTValueType::BOOL;
        else if (typeName == "num") ty = ASTValueType::NUMBER;
        else
        {
            std::cout << "ERROR: unknown type " << typeName << std::endl;
            return nullptr;
        }
        return new DefVarNode(ctx->name->getText(), ty, visitExpr(ctx->value));
    }

    ASTNode* Parser::visitAssign(JITLangParser::AssignContext* ctx)
    {
        return new SetVarNode(ctx->name->getText(), visitExpr(ctx->value));
    }

    ASTNode* Parser::visitExpr(JITLangParser::ExprContext* ctx)
    {
        if (ctx->atom()) return visitAtom(ctx->atom());
        else if (ctx->postop) return visitPostExpr(ctx);
        else if (ctx->preop) return visitPreExpr(ctx);
        else if (ctx->mult) return visitBinOpExpr(ctx, ctx->mult->getText());
        else if (ctx->add) return visitBinOpExpr(ctx, ctx->add->getText());
        else if (ctx->gt) return visitBinOpExpr(ctx, ctx->gt->getText());
        else if (ctx->eq) return visitBinOpExpr(ctx, ctx->eq->getText());
        else if (ctx->func_call()) return visitFuncCall(ctx->func_call());
        else if (ctx->paren) return visitExpr(ctx->paren);
        else if (ctx->logAnd) return visitBinOpExpr(ctx, ctx->logAnd->getText());
        else if (ctx->logOr) return visitBinOpExpr(ctx, ctx->logOr->getText());
        else if (ctx->tern) return visitTernExpr(ctx);
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

    ASTNode* Parser::visitAtom(JITLangParser::AtomContext* ctx)
    {
        if (ctx->literal()) return visitLiteral(ctx->literal());
        else if (ctx->IDENT()) return new GetVarNode(ctx->IDENT()->getText());
        else return nullptr;
    }

    ASTNode* Parser::visitLiteral(JITLangParser::LiteralContext* ctx)
    {
        if (ctx->NUMBER()) return new ConstNode(ASTValue::create(std::stod(ctx->NUMBER()->getText())));
        else if (ctx->STRING()) 
        {
            std::string value = ctx->STRING()->getText();
            value = value.substr(1, value.length() - 2);
            return new ConstNode(ASTValue::create((char*)value.c_str()));
        }
        else return nullptr;
    }

    ASTNode* Parser::visitPostExpr(JITLangParser::ExprContext* ctx)
    {
        return new PostOpNode(visitExpr(ctx->expr(0)), ctx->postop->getText());
    }

    ASTNode* Parser::visitPreExpr(JITLangParser::ExprContext* ctx)
    {
        return new PreOpNode(visitExpr(ctx->expr(0)), ctx->preop->getText());
    }

    ASTNode* Parser::visitBinOpExpr(JITLangParser::ExprContext* ctx, std::string binOp)
    {
        return new BinOpNode(visitExpr(ctx->expr(0)), visitExpr(ctx->expr(1)), binOp);
    }

    ASTNode* Parser::visitTernExpr(JITLangParser::ExprContext* ctx)
    {
        std::cout << "TernOpNode not written yet" << std::endl;
        return nullptr;
    }

    BlockNode* Parser::visitStatements(std::vector <JITLangParser::StmtContext*> statements)
    {
        std::vector<ASTNode*> nodes{};
        for (auto* stmt : statements)
        {
            nodes.push_back(visitStmt(stmt));
        }
        return new BlockNode(nodes);
    }
}