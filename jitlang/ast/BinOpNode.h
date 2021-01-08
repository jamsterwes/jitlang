#pragma once
#include "ASTNode.h"

class BinOpNode : public ASTNode
{
public:
    BinOpNode(ASTNode* lhs, ASTNode* rhs, std::string binOp) : lhs(lhs), rhs(rhs), binOp(binOp) {}

    virtual ASTNodeType getType() override { return ASTNodeType::BIN_OP; }

    virtual ASTValue* slowRun(SlowContext* ctx) override;
    virtual llvm::Value* llEval(LLContext* ctx) override;
private:
    ASTNode* lhs;
    ASTNode* rhs;
    std::string binOp;
};