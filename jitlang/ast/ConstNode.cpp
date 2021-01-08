#include "ConstNode.h"

ASTValue* ConstNode::slowRun(SlowContext* ctx)
{
    return val;
}

llvm::Value* ConstNode::llEval(LLContext* ctx)
{
    return nullptr;
}