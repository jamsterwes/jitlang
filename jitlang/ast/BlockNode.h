#pragma once
#include "ASTNode.h"
#include <vector>

class BlockNode : public ASTNode
{
public:
    BlockNode(std::vector<ASTNode*> nodes) : nodes(nodes) {}

    virtual ASTNodeType getType() override { return ASTNodeType::BLOCK; };

    virtual ASTValue* slowRun(SlowContext* ctx) override;
    virtual llvm::Value* llEval(LLContext* ctx) override;
private:
    std::vector<ASTNode*> nodes;
};