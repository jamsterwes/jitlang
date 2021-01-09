#include "PreOpNode.h"
#include "GetVarNode.h"

#include <cmath>
#include <iostream>

/* EVAL IMPLEMENTATIONS */

ASTValue* PreOpNode::slowRun(SlowContext* ctx)
{
    // If ++/--, check for GetVar
    if (node->getType() == ASTNodeType::GET_VAR)
    {
        std::string name = ((GetVarNode*)node)->getName();
        auto* val = ctx->getVar(name);
        if (this->op == "++" && val->type == ASTValueType::NUMBER) return ASTValue::create(++val->data.numberValue);
        else if (this->op == "--" && val->type == ASTValueType::NUMBER) return ASTValue::create(--val->data.numberValue);
        else if (this->op == "!" && val->type == ASTValueType::BOOL) return ASTValue::create(!val->data.boolValue);
        else
        {
            std::cout << "ERROR: invalid type " << getValueTypeName(val->type) << " for pre-op " << this->op << std::endl;
            return nullptr;
        }
    }
    // Else if !(expr), do not constant
    else if (this->op == "!")
    {
        auto* val = node->slowRun(ctx);
        if (val->type == ASTValueType::BOOL) return ASTValue::create(!val->data.boolValue);
        else
        {
            std::cout << "ERROR: invalid type " << getValueTypeName(val->type) << " for pre-op !" << std::endl;
            return nullptr;
        }
    }
    // Else, error only works with GetVar
    else
    {
        std::cout << "ERROR: pre-op " << this->op << " only compatible with variables" << std::endl;
        return nullptr;
    }
}

llvm::Value* PreOpNode::llEval(LLContext* ctx)
{
    return nullptr;
}