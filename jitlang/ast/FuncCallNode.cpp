#include "FuncCallNode.h"

ASTValue* FuncCallNode::slowRun(SlowContext* ctx)
{
    return ctx->callFunction(name, args);
}

llvm::Value* FuncCallNode::llEval(LLContext* ctx)
{
    return nullptr;
}