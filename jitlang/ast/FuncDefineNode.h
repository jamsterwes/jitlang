#pragma once
#include "ASTNode.h"
#include "BlockNode.h"
#include <string>
#include <vector>

class FuncDefineNode : public ASTNode
{
public:
    FuncDefineNode(std::string funcName, std::vector<FunctionArg> args, BlockNode* funcBlock) : name(funcName), args(args), block(funcBlock), retType((ASTValueType)-1) {}
    FuncDefineNode(std::string funcName, ASTValueType retType, std::vector<FunctionArg> args, BlockNode* funcBlock) : name(funcName), args(args), block(funcBlock), retType(retType) {}

    virtual ASTNodeType getType() override { return ASTNodeType::FUNC_DEFINE; }

    virtual ASTValue* slowRun(SlowContext* ctx) override;
    virtual llvm::Value* llEval(LLContext* ctx) override;
private:
    std::string name;
    std::vector<FunctionArg> args;
    ASTValueType retType;
    BlockNode* block;
};