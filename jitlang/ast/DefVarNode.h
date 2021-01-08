#pragma once
#include "ASTNode.h"
#include <string>

class DefVarNode : public ASTNode
{
public:
    DefVarNode(std::string varName, ASTValueType type, ASTNode* value) : name(varName), type(type), value(value) {}

    virtual ASTNodeType getType() override { return ASTNodeType::DEF_VAR; }

    virtual ASTValue* slowRun(SlowContext* ctx) override;
    virtual llvm::Value* llEval(LLContext* ctx) override;
private:
    std::string name;
    ASTValueType type;
    ASTNode* value;
};