#pragma once
#include "ASTNode.h"

class PreOpNode : public ASTNode
{
public:
    PreOpNode(ASTNode* node, std::string op) : node(node), op(op) {}

    virtual ASTNodeType getType() override { return ASTNodeType::PRE_OP; }

    virtual ASTValue* slowRun(SlowContext* ctx) override;
    virtual llvm::Value* llEval(LLContext* ctx) override;
private:
    ASTNode* node;
    std::string op;
};