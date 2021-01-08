#include "IfNode.h"

ASTValue* IfNode::slowRun(SlowContext* ctx)
{
    auto* val = this->cond->slowRun(ctx);
    if (val->type == ASTValueType::NUMBER)
    {
        if (val->data.numberValue != 0) return this->block->slowRun(ctx);
        else return nullptr;
    }
    else if (val->type == ASTValueType::BOOL)
    {
        if (val->data.boolValue) return this->block->slowRun(ctx);
        else return nullptr;
    }
    else
    {
        std::cout << "ERROR: string not a compatible type for if-condition" << std::endl;
        return nullptr;
    }
}

llvm::Value* IfNode::llEval(LLContext* ctx)
{
    return nullptr;
}