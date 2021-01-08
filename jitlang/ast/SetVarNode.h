#pragma once
#include "ASTNode.h"
#include <string>

class SetVarNode : public ASTNode
{
public:
    SetVarNode(std::string varName, ASTNode* value) : name(varName), value(value) {}

    virtual ASTNodeType getType() override { return ASTNodeType::SET_VAR; }

    virtual ASTValue* slowRun(SlowContext* ctx) override;
    virtual llvm::Value* llEval(LLContext* ctx) override;
private:
    std::string name;
    ASTNode* value;
};