#include "GetVarNode.h"

ASTValue* GetVarNode::slowRun(SlowContext* ctx)
{
    return ctx->getVar(this->name);
}

llvm::Value* GetVarNode::llEval(LLContext* ctx)
{
    // TODO: get type, return get expr
    return nullptr;
}