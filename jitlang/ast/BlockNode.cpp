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
    return nullptr;
}