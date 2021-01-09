#include "FuncDefineNode.h"

ASTValue* FuncDefineNode::slowRun(SlowContext* ctx)
{
    ctx->defineFunction(name, Function(args, (uint8_t)retType, block));
    return nullptr;
}

llvm::Value* FuncDefineNode::llEval(LLContext* ctx)
{
    return nullptr;
}