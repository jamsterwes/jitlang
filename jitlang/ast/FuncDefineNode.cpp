#include "FuncDefineNode.h"

ASTValue* FuncDefineNode::slowRun(SlowContext* ctx)
{
    ctx->defineFunction(name, Function(args, block));
    return nullptr;
}

llvm::Value* FuncDefineNode::llEval(LLContext* ctx)
{
    return nullptr;
}