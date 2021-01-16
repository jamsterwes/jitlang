#include "BinOpNode.h"
#include "../compiler/TypeBuilder.h"

#include <cmath>
#include <iostream>

/* INTERPRETER BINOP IMPLEMENTATIONS */

ASTValue* add(ASTValue* lhs, ASTValue* rhs)
{
    // Mismatched types -> nullptr
    if (lhs->type != rhs->type)
    {
        std::cout << "ERROR: mismatching types " << (int)lhs->type << " and " << (int)rhs->type << " for binop(+)" << std::endl;
        return nullptr;
    }
    // number + number -> add (number)
    else if (lhs->type == ASTValueType::NUMBER)
    {
        return ASTValue::create(lhs->data.numberValue + rhs->data.numberValue);
    }
    // string + string -> concat (string)
    else if (lhs->type == ASTValueType::STRING)
    {
        std::string output = std::string(lhs->data.stringValue) + rhs->data.stringValue;
        return ASTValue::create((char*)output.c_str());
    }
    // ? + ? -> nullptr
    else
    {
        std::cout << "ERROR: type " << getValueTypeName(lhs->type) << " incompatible with binop(+)" << std::endl;
        return nullptr;
    }
}

ASTValue* sub(ASTValue* lhs, ASTValue* rhs)
{
    // Mismatched types -> nullptr
    if (lhs->type != rhs->type)
    {
        std::cout << "ERROR: mismatching types " << (int)lhs->type << " and " << (int)rhs->type << " for binop(-)" << std::endl;
        return nullptr;
    }
    // number - number -> subtract (number)
    else if (lhs->type == ASTValueType::NUMBER)
    {
        return ASTValue::create(lhs->data.numberValue - rhs->data.numberValue);
    }
    // ? + ? -> nullptr
    else
    {
        std::cout << "ERROR: type " << getValueTypeName(lhs->type) << " incompatible with binop(-)" << std::endl;
        return nullptr;
    }
}

ASTValue* mul(ASTValue* lhs, ASTValue* rhs)
{
    // string * number -> repeat (string)
    if (lhs->type == ASTValueType::STRING && rhs->type == ASTValueType::NUMBER)
    {
        int repAmt = (int)rhs->data.numberValue;
        // amt<=0 -> nullptr
        if (repAmt <= 0)
        {
            std::cout << "ERROR: cannot repeat string " << repAmt << " times" << std::endl;
            return nullptr;
        }
        // amt==1 -> return lhs (string)
        else if (repAmt == 1)
        {
            return lhs;
        }
        // amt>1 -> repeat (string)
        else if (repAmt > 1)
        {
            std::string output = "";
            for (int i = 0; i < repAmt; i++) output += lhs->data.stringValue;
            return ASTValue::create((char*)output.c_str());
        }
        // unknown error -> nullptr
        else
        {
            std::cout << "RUNTIME ERROR: unreachable path reached in string multiply" << std::endl;
            return nullptr;
        }
    }
    // Mismatched types -> nullptr
    else if (lhs->type != rhs->type)
    {
        std::cout << "ERROR: mismatching types " << (int)lhs->type << " and " << (int)rhs->type << " for binop(*)" << std::endl;
        return nullptr;
    }
    // number * number -> multiply (number)
    else if (lhs->type == ASTValueType::NUMBER)
    {
        return ASTValue::create(lhs->data.numberValue * rhs->data.numberValue);
    }
    // ? + ? -> nullptr
    else
    {
        std::cout << "ERROR: type " << getValueTypeName(lhs->type) << " incompatible with binop(*)" << std::endl;
        return nullptr;
    }
}

ASTValue* div(ASTValue* lhs, ASTValue* rhs)
{
    // Mismatched types -> nullptr
    if (lhs->type != rhs->type)
    {
        std::cout << "ERROR: mismatching types " << (int)lhs->type << " and " << (int)rhs->type << " for binop(/)" << std::endl;
        return nullptr;
    }
    // number / number -> divide (number)
    else if (lhs->type == ASTValueType::NUMBER)
    {
        return ASTValue::create(lhs->data.numberValue / rhs->data.numberValue);
    }
    // ? + ? -> nullptr
    else
    {
        std::cout << "ERROR: type " << getValueTypeName(lhs->type) << " incompatible with binop(/)" << std::endl;
        return nullptr;
    }
}

ASTValue* rem(ASTValue* lhs, ASTValue* rhs)
{
    // Mismatched types -> nullptr
    if (lhs->type != rhs->type)
    {
        std::cout << "ERROR: mismatching types " << (int)lhs->type << " and " << (int)rhs->type << " for binop(%)" << std::endl;
        return nullptr;
    }
    // number % number -> remainder (number)
    else if (lhs->type == ASTValueType::NUMBER)
    {
        double output = fmod(lhs->data.numberValue, rhs->data.numberValue);
        return ASTValue::create(output);
    }
    // ? % ? -> nullptr
    else
    {
        std::cout << "ERROR: type " << getValueTypeName(lhs->type) << " incompatible with binop(%)" << std::endl;
        return nullptr;
    }
}

ASTValue* gt(ASTValue* lhs, ASTValue* rhs)
{
    // Mismatched types -> nullptr
    if (lhs->type != rhs->type)
    {
        std::cout << "ERROR: mismatching types " << (int)lhs->type << " and " << (int)rhs->type << " for binop(>)" << std::endl;
        return nullptr;
    }
    // number > number -> gt (bool)
    else if (lhs->type == ASTValueType::NUMBER)
    {
        return ASTValue::create(lhs->data.numberValue > rhs->data.numberValue);
    }
    // ? > ? -> nullptr
    else
    {
        std::cout << "ERROR: type " << getValueTypeName(lhs->type) << " incompatible with binop(>)" << std::endl;
        return nullptr;
    }
}

ASTValue* gte(ASTValue* lhs, ASTValue* rhs)
{
    // Mismatched types -> nullptr
    if (lhs->type != rhs->type)
    {
        std::cout << "ERROR: mismatching types " << (int)lhs->type << " and " << (int)rhs->type << " for binop(>=)" << std::endl;
        return nullptr;
    }
    // number >= number -> gte (bool)
    else if (lhs->type == ASTValueType::NUMBER)
    {
        return ASTValue::create(lhs->data.numberValue >= rhs->data.numberValue);
    }
    // ? >= ? -> nullptr
    else
    {
        std::cout << "ERROR: type " << getValueTypeName(lhs->type) << " incompatible with binop(>=)" << std::endl;
        return nullptr;
    }
}

ASTValue* lt(ASTValue* lhs, ASTValue* rhs)
{
    // Mismatched types -> nullptr
    if (lhs->type != rhs->type)
    {
        std::cout << "ERROR: mismatching types " << (int)lhs->type << " and " << (int)rhs->type << " for binop(<)" << std::endl;
        return nullptr;
    }
    // number < number -> lt (bool)
    else if (lhs->type == ASTValueType::NUMBER)
    {
        return ASTValue::create(lhs->data.numberValue < rhs->data.numberValue);
    }
    // ? < ? -> nullptr
    else
    {
        std::cout << "ERROR: type " << getValueTypeName(lhs->type) << " incompatible with binop(<)" << std::endl;
        return nullptr;
    }
}

ASTValue* lte(ASTValue* lhs, ASTValue* rhs)
{
    // Mismatched types -> nullptr
    if (lhs->type != rhs->type)
    {
        std::cout << "ERROR: mismatching types " << (int)lhs->type << " and " << (int)rhs->type << " for binop(<=)" << std::endl;
        return nullptr;
    }
    // number <= number -> lte (bool)
    else if (lhs->type == ASTValueType::NUMBER)
    {
        return ASTValue::create(lhs->data.numberValue <= rhs->data.numberValue);
    }
    // ? <= ? -> nullptr
    else
    {
        std::cout << "ERROR: type " << getValueTypeName(lhs->type) << " incompatible with binop(<=)" << std::endl;
        return nullptr;
    }
}

ASTValue* eq(ASTValue* lhs, ASTValue* rhs)
{
    // Mismatched types -> nullptr
    if (lhs->type != rhs->type)
    {
        std::cout << "ERROR: mismatching types " << (int)lhs->type << " and " << (int)rhs->type << " for binop(==)" << std::endl;
        return nullptr;
    }
    // number == number -> eq (bool)
    else if (lhs->type == ASTValueType::NUMBER)
    {
        return ASTValue::create(lhs->data.numberValue == rhs->data.numberValue);
    }
    // bool == bool -> eq (bool)
    else if (lhs->type == ASTValueType::BOOL)
    {
        return ASTValue::create(lhs->data.boolValue == rhs->data.boolValue);
    }
    // string == string -> eq (bool)
    else if (lhs->type == ASTValueType::STRING)
    {
        return ASTValue::create(strcmp(lhs->data.stringValue, rhs->data.stringValue) == 0);
    }
    // ? == ? -> nullptr
    else
    {
        std::cout << "ERROR: type " << getValueTypeName(lhs->type) << " incompatible with binop(==)" << std::endl;
        return nullptr;
    }
}

ASTValue* neq(ASTValue* lhs, ASTValue* rhs)
{
    // Mismatched types -> nullptr
    if (lhs->type != rhs->type)
    {
        std::cout << "ERROR: mismatching types " << (int)lhs->type << " and " << (int)rhs->type << " for binop(!=)" << std::endl;
        return nullptr;
    }
    // number != number -> neq (bool)
    else if (lhs->type == ASTValueType::NUMBER)
    {
        return ASTValue::create(lhs->data.numberValue != rhs->data.numberValue);
    }
    // bool != bool -> neq (bool)
    else if (lhs->type == ASTValueType::BOOL)
    {
        return ASTValue::create(lhs->data.boolValue != rhs->data.boolValue);
    }
    // string != string -> neq (bool)
    else if (lhs->type == ASTValueType::STRING)
    {
        return ASTValue::create(strcmp(lhs->data.stringValue, rhs->data.stringValue) != 0);
    }
    // ? != ? -> nullptr
    else
    {
        std::cout << "ERROR: type " << getValueTypeName(lhs->type) << " incompatible with binop(!=)" << std::endl;
        return nullptr;
    }
}

ASTValue* logAnd(ASTValue* lhs, ASTValue* rhs)
{
    // Mismatched types -> nullptr
    if (lhs->type != rhs->type)
    {
        std::cout << "ERROR: mismatching types " << (int)lhs->type << " and " << (int)rhs->type << " for binop(&&)" << std::endl;
        return nullptr;
    }
    // bool && bool -> logAnd (bool)
    else if (lhs->type == ASTValueType::BOOL)
    {
        return ASTValue::create(lhs->data.boolValue && rhs->data.boolValue);
    }
    // ? && ? -> nullptr
    else
    {
        std::cout << "ERROR: type " << getValueTypeName(lhs->type) << " incompatible with binop(&&)" << std::endl;
        return nullptr;
    }
}

ASTValue* logOr(ASTValue* lhs, ASTValue* rhs)
{
    // Mismatched types -> nullptr
    if (lhs->type != rhs->type)
    {
        std::cout << "ERROR: mismatching types " << (int)lhs->type << " and " << (int)rhs->type << " for binop(||)" << std::endl;
        return nullptr;
    }
    // bool || bool -> logOr (bool)
    else if (lhs->type == ASTValueType::BOOL)
    {
        return ASTValue::create(lhs->data.boolValue || rhs->data.boolValue);
    }
    // ? || ? -> nullptr
    else
    {
        std::cout << "ERROR: type " << getValueTypeName(lhs->type) << " incompatible with binop(||)" << std::endl;
        return nullptr;
    }
}

/* EVAL IMPLEMENTATIONS */

ASTValue* BinOpNode::slowRun(SlowContext* ctx)
{
    auto* lhsValue = this->lhs->slowRun(ctx);
    auto* rhsValue = this->rhs->slowRun(ctx);

    if (lhsValue == nullptr || rhsValue == nullptr) return nullptr;

    if (this->binOp == "+") return add(lhsValue, rhsValue);
    else if (this->binOp == "-") return sub(lhsValue, rhsValue);
    else if (this->binOp == "*") return mul(lhsValue, rhsValue);
    else if (this->binOp == "/") return div(lhsValue, rhsValue);
    else if (this->binOp == "%") return rem(lhsValue, rhsValue);
    else if (this->binOp == ">") return gt(lhsValue, rhsValue);
    else if (this->binOp == ">=") return gte(lhsValue, rhsValue);
    else if (this->binOp == "<") return lt(lhsValue, rhsValue);
    else if (this->binOp == "<=") return lte(lhsValue, rhsValue);
    else if (this->binOp == "==") return eq(lhsValue, rhsValue);
    else if (this->binOp == "!=") return neq(lhsValue, rhsValue);
    else if (this->binOp == "&&") return logAnd(lhsValue, rhsValue);
    else if (this->binOp == "||") return logOr(lhsValue, rhsValue);
    else return nullptr;
}

/* LLVM BINOP IMPLEMENTATIONS */

llvm::Value* llAdd(LLContext* ctx, llvm::Value* lhs, llvm::Value* rhs)
{
    if (lhs->getType() != rhs->getType())
    {
        std::cout << "ERROR: mismatched types for binop(+)" << std::endl;
        return nullptr;
    }

    if (lhs->getType()->isDoubleTy()) return ctx->getBuilder()->CreateFAdd(lhs, rhs);
    else if (lhs->getType() == TypeBuilder<char*>::get(ctx->getLLVM()))
    {
        std::cout << "ERROR: concat not implemented yet for LLVM compiler" << std::endl;
        return nullptr;
    }
    else
    {
        std::cout << "ERROR: incompatible type for binop(+)" << std::endl;
        return nullptr;
    }
}

llvm::Value* llSub(LLContext* ctx, llvm::Value* lhs, llvm::Value* rhs)
{
    if (lhs->getType() != rhs->getType())
    {
        std::cout << "ERROR: mismatched types for binop(-)" << std::endl;
        return nullptr;
    }

    if (lhs->getType()->isDoubleTy()) return ctx->getBuilder()->CreateFSub(lhs, rhs);
    else
    {
        std::cout << "ERROR: incompatible type for binop(-)" << std::endl;
        return nullptr;
    }
}

llvm::Value* llMul(LLContext* ctx, llvm::Value* lhs, llvm::Value* rhs)
{
    if (lhs->getType() != rhs->getType())
    {
        std::cout << "ERROR: mismatched types for binop(*)" << std::endl;
        return nullptr;
    }

    if (lhs->getType()->isDoubleTy()) return ctx->getBuilder()->CreateFMul(lhs, rhs);
    else if (lhs->getType() == TypeBuilder<char*>::get(ctx->getLLVM()))
    {
        std::cout << "ERROR: repeatstr not implemented yet for LLVM compiler" << std::endl;
        return nullptr;
    }
    else
    {
        std::cout << "ERROR: incompatible type for binop(*)" << std::endl;
        return nullptr;
    }
}

llvm::Value* llDiv(LLContext* ctx, llvm::Value* lhs, llvm::Value* rhs)
{
    if (lhs->getType() != rhs->getType())
    {
        std::cout << "ERROR: mismatched types for binop(/)" << std::endl;
        return nullptr;
    }

    if (lhs->getType()->isDoubleTy()) return ctx->getBuilder()->CreateFDiv(lhs, rhs);
    else
    {
        std::cout << "ERROR: incompatible type for binop(/)" << std::endl;
        return nullptr;
    }
}

llvm::Value* llRem(LLContext* ctx, llvm::Value* lhs, llvm::Value* rhs)
{
    if (lhs->getType() != rhs->getType())
    {
        std::cout << "ERROR: mismatched types for binop(%)" << std::endl;
        return nullptr;
    }

    if (lhs->getType()->isDoubleTy()) return ctx->getBuilder()->CreateFRem(lhs, rhs);
    else
    {
        std::cout << "ERROR: incompatible type for binop(%)" << std::endl;
        return nullptr;
    }
}

llvm::Value* llGT(LLContext* ctx, llvm::Value* lhs, llvm::Value* rhs)
{
    if (lhs->getType() != rhs->getType())
    {
        std::cout << "ERROR: mismatched types for binop(>)" << std::endl;
        return nullptr;
    }

    if (lhs->getType()->isDoubleTy()) return ctx->getBuilder()->CreateFCmpUGT(lhs, rhs);
    else
    {
        std::cout << "ERROR: incompatible type for binop(>)" << std::endl;
        return nullptr;
    }
}

llvm::Value* llGTE(LLContext* ctx, llvm::Value* lhs, llvm::Value* rhs)
{
    if (lhs->getType() != rhs->getType())
    {
        std::cout << "ERROR: mismatched types for binop(>=)" << std::endl;
        return nullptr;
    }

    if (lhs->getType()->isDoubleTy()) return ctx->getBuilder()->CreateFCmpUGE(lhs, rhs);
    else
    {
        std::cout << "ERROR: incompatible type for binop(>=)" << std::endl;
        return nullptr;
    }
}

llvm::Value* llLT(LLContext* ctx, llvm::Value* lhs, llvm::Value* rhs)
{
    if (lhs->getType() != rhs->getType())
    {
        std::cout << "ERROR: mismatched types for binop(<)" << std::endl;
        return nullptr;
    }

    if (lhs->getType()->isDoubleTy()) return ctx->getBuilder()->CreateFCmpULT(lhs, rhs);
    else
    {
        std::cout << "ERROR: incompatible type for binop(<)" << std::endl;
        return nullptr;
    }
}

llvm::Value* llLTE(LLContext* ctx, llvm::Value* lhs, llvm::Value* rhs)
{
    if (lhs->getType() != rhs->getType())
    {
        std::cout << "ERROR: mismatched types for binop(<=)" << std::endl;
        return nullptr;
    }

    if (lhs->getType()->isDoubleTy()) return ctx->getBuilder()->CreateFCmpULE(lhs, rhs);
    else
    {
        std::cout << "ERROR: incompatible type for binop(<=)" << std::endl;
        return nullptr;
    }
}

llvm::Value* llEQ(LLContext* ctx, llvm::Value* lhs, llvm::Value* rhs)
{
    if (lhs->getType() != rhs->getType())
    {
        std::cout << "ERROR: mismatched types for binop(==)" << std::endl;
        return nullptr;
    }

    if (lhs->getType()->isIntegerTy()) return ctx->getBuilder()->CreateICmpEQ(lhs, rhs);
    else if (lhs->getType() == TypeBuilder<char*>::get(ctx->getLLVM()))
    {
        std::cout << "ERROR: == not implemented yet for LLVM compiler" << std::endl;
        return nullptr;
    }
    else if (lhs->getType()->isDoubleTy()) return ctx->getBuilder()->CreateFCmpUEQ(lhs, rhs);
    else
    {
        std::cout << "ERROR: incompatible type for binop(==)" << std::endl;
        return nullptr;
    }
}

llvm::Value* llNEQ(LLContext* ctx, llvm::Value* lhs, llvm::Value* rhs)
{
    if (lhs->getType() != rhs->getType())
    {
        std::cout << "ERROR: mismatched types for binop(!=)" << std::endl;
        return nullptr;
    }

    if (lhs->getType()->isIntegerTy()) return ctx->getBuilder()->CreateICmpNE(lhs, rhs);
    else if (lhs->getType() == TypeBuilder<char*>::get(ctx->getLLVM()))
    {
        std::cout << "ERROR: != not implemented yet for LLVM compiler" << std::endl;
        return nullptr;
    }
    else if (lhs->getType()->isDoubleTy()) return ctx->getBuilder()->CreateFCmpUNE(lhs, rhs);
    else
    {
        std::cout << "ERROR: incompatible type for binop(!=)" << std::endl;
        return nullptr;
    }
}

llvm::Value* BinOpNode::llEval(LLContext* ctx)
{
    llvm::Value* lhsValue = this->lhs->llEval(ctx);
    llvm::Value* rhsValue = this->rhs->llEval(ctx);

    if (lhsValue == nullptr || rhsValue == nullptr) return nullptr;

    if (this->binOp == "+") return llAdd(ctx, lhsValue, rhsValue);
    else if (this->binOp == "-") return llSub(ctx, lhsValue, rhsValue);
    else if (this->binOp == "*") return llMul(ctx, lhsValue, rhsValue);
    else if (this->binOp == "/") return llDiv(ctx, lhsValue, rhsValue);
    else if (this->binOp == "%") return llRem(ctx, lhsValue, rhsValue);
    else if (this->binOp == ">") return llGT(ctx, lhsValue, rhsValue);
    else if (this->binOp == ">=") return llGTE(ctx, lhsValue, rhsValue);
    else if (this->binOp == "<") return llLT(ctx, lhsValue, rhsValue);
    else if (this->binOp == "<=") return llLTE(ctx, lhsValue, rhsValue);
    else if (this->binOp == "==") return llEQ(ctx, lhsValue, rhsValue);
    else if (this->binOp == "!=") return llNEQ(ctx, lhsValue, rhsValue);
    //else if (this->binOp == "&&") return logAnd(lhsValue, rhsValue);
    //else if (this->binOp == "||") return logOr(lhsValue, rhsValue);
    else return nullptr;
}