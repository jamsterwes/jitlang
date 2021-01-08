#include "DefVarNode.h"

ASTValue* DefVarNode::slowRun(SlowContext* ctx)
{
    auto* val = this->value->slowRun(ctx);
    if (this->type != val->type)
    {
        std::cout << "ERROR: variable " << this->name << "defined as type " << getValueTypeName(this->type) << " but assigned value of type " << getValueTypeName(val->type) << std::endl;
        return nullptr;
    }
    ctx->insertVar(this->name, val);
    return nullptr;
}

llvm::Value* DefVarNode::llEval(LLContext* ctx)
{
    return nullptr;
}