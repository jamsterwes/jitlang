#include "ConstNode.h"
#include "../compiler/TypeBuilder.h"

ASTValue* ConstNode::slowRun(SlowContext* ctx)
{
    return val;
}

llvm::Value* ConstNode::llEval(LLContext* ctx)
{
    if (val->type == ASTValueType::BOOL)
    {
        return TypeBuilder<bool>::makeConst(ctx->getLLVM(), val->data.boolValue);
    }
    else if (val->type == ASTValueType::NUMBER)
    {
        return TypeBuilder<double>::makeConst(ctx->getLLVM(), val->data.numberValue);
    }
    else if (val->type == ASTValueType::STRING)
    {
        return ctx->getBuilder()->CreateGlobalStringPtr(val->data.stringValue);
    }
    else return nullptr;
}