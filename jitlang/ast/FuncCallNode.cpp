#include "FuncCallNode.h"

ASTValue* FuncCallNode::slowRun(SlowContext* ctx)
{
    return ctx->callFunction(name, args);
}

llvm::Value* FuncCallNode::llEval(LLContext* ctx)
{
    std::string trueName = name;
    std::vector<llvm::Value*> llArgs{};
    for (auto* arg : args)
    {
        llArgs.push_back(arg->llEval(ctx));
    }

    if (name == "print")
    {
        if (llArgs[0]->getType() == llvm::Type::getDoubleTy(ctx->getLLVM())) trueName = "??printNum";
        else if (llArgs[0]->getType() == llvm::Type::getInt8PtrTy(ctx->getLLVM())) trueName = "??printStr";
    }

    auto* func = ctx->getMod()->getFunction(trueName);
    return ctx->getBuilder()->CreateCall(func, llArgs);
}