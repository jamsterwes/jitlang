#include "BlockNode.h"

ASTValue* BlockNode::slowRun(SlowContext* ctx)
{
    ASTValue* lastValue = nullptr;
    for (auto* node : this->nodes)
    {
        if (node == nullptr) continue;

        lastValue = node->slowRun(ctx);
    }
    return lastValue;
}

llvm::Value* BlockNode::llEval(LLContext* ctx)
{
    llvm::Value* retVal = nullptr;
    for (auto* node : nodes)
    {
        auto* val = node->llEval(ctx);
        if (val != nullptr) retVal = val;
    }
    return retVal;
}