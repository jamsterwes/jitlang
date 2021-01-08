#pragma once
#include "ASTNode.h"
#include "BlockNode.h"
#include <string>

class IfNode : public ASTNode
{
public:
    IfNode(ASTNode* cond, BlockNode* block) : cond(cond), block(block) {}

    virtual ASTNodeType getType() override { return ASTNodeType::IF; }

    virtual ASTValue* slowRun(SlowContext* ctx) override;
    virtual llvm::Value* llEval(LLContext* ctx) override;
private:
    ASTNode* cond;
    BlockNode* block;
};