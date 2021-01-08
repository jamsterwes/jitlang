#pragma once
#include "ASTNode.h"

class ConstNode : public ASTNode
{
public:
    ConstNode(ASTValue* val) : val(val) {}

    virtual ASTNodeType getType() override { return ASTNodeType::CONST; };

    virtual ASTValue* slowRun(SlowContext* ctx) override;
    virtual llvm::Value* llEval(LLContext* ctx) override;
private:
    ASTValue* val;
};