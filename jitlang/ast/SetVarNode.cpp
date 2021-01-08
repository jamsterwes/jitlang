#include "SetVarNode.h"

ASTValue* SetVarNode::slowRun(SlowContext* ctx)
{
    auto* val = this->value->slowRun(ctx);
    auto* oldValue = ctx->getVar(this->name);
    if (oldValue->type != val->type)
    {
        std::cout << "ERROR: variable " << this->name << "defined as type " << getValueTypeName(oldValue->type) << " but assigned value of type " << getValueTypeName(val->type) << std::endl;
        return nullptr;
    }
    ctx->setVar(this->name, val);
    return nullptr;
}

llvm::Value* SetVarNode::llEval(LLContext* ctx)
{
    return nullptr;
}