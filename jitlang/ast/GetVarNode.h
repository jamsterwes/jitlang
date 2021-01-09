#pragma once
#include "ASTNode.h"
#include <string>

class GetVarNode : public ASTNode
{
public:
    GetVarNode(std::string varName) : name(varName) {}

    virtual ASTNodeType getType() override { return ASTNodeType::GET_VAR; }

    virtual ASTValue* slowRun(SlowContext* ctx) override;
    virtual llvm::Value* llEval(LLContext* ctx) override;

    std::string getName() { return name; }
private:
    std::string name;
};