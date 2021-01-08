#pragma once
#include "ASTNode.h"
#include <string>
#include <vector>

class FuncCallNode : public ASTNode
{
public:
    FuncCallNode(std::string funcName, std::vector<ASTNode*> args) : name(funcName), args(args) {}

    virtual ASTNodeType getType() override { return ASTNodeType::FUNC_CALL; }

    virtual ASTValue* slowRun(SlowContext* ctx) override;
    virtual llvm::Value* llEval(LLContext* ctx) override;
private:
    std::string name;
    std::vector<ASTNode*> args;
};