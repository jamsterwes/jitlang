#include "PostOpNode.h"
#include "GetVarNode.h"

#include <cmath>
#include <iostream>

/* EVAL IMPLEMENTATIONS */

ASTValue* PostOpNode::slowRun(SlowContext* ctx)
{
    // If ++/--, check for GetVar
    if (node->getType() == ASTNodeType::GET_VAR)
    {
        std::string name = ((GetVarNode*)node)->getName();
        auto* val = ctx->getVar(name);
        if (this->op == "++" && val->type == ASTValueType::NUMBER) return ASTValue::create(val->data.numberValue++);
        else if (this->op == "--" && val->type == ASTValueType::NUMBER) return ASTValue::create(val->data.numberValue--);
        else
        {
            std::cout << "ERROR: invalid type " << getValueTypeName(val->type) << " for post-op " << this->op << std::endl;
            return nullptr;
        }
    }
    // Else, error only works with GetVar
    else
    {
        std::cout << "ERROR: post-op " << this->op << " only compatible with variables" << std::endl;
        return nullptr;
    }
}

llvm::Value* PostOpNode::llEval(LLContext* ctx)
{
    return nullptr;
}