#pragma once
#include "ASTNode.h"

class PostOpNode : public ASTNode
{
public:
    PostOpNode(ASTNode* node, std::string op) : node(node), op(op) {}

    virtual ASTNodeType getType() override { return ASTNodeType::POST_OP; }

    virtual ASTValue* slowRun(SlowContext* ctx) override;
    virtual llvm::Value* llEval(LLContext* ctx) override;
private:
    ASTNode* node;
    std::string op;
};