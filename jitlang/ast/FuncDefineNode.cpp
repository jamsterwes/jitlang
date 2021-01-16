#include "FuncDefineNode.h"

ASTValue* FuncDefineNode::slowRun(SlowContext* ctx)
{
    ctx->defineFunction(name, Function(args, (uint8_t)retType, block));
    return nullptr;
}

// todo, move elsewhere
llvm::Type* getLLType(ASTValueType ty, LLContext* ctx)
{
    switch (ty)
    {
    case ASTValueType::BOOL:
        return llvm::Type::getInt1Ty(ctx->getLLVM());
    case ASTValueType::NUMBER:
        return llvm::Type::getDoubleTy(ctx->getLLVM());
    case ASTValueType::STRING:
        return llvm::Type::getInt8PtrTy(ctx->getLLVM());
    default:
        return llvm::Type::getVoidTy(ctx->getLLVM());
    }
}

llvm::Value* FuncDefineNode::llEval(LLContext* ctx)
{
    auto* retTy = getLLType(retType, ctx);

    std::vector<llvm::Type*> argTys{};
    for (auto arg : args)
    {
        argTys.push_back(getLLType((ASTValueType)arg.ty, ctx));
    }

    // TODO: vararg?
    // Get function signature
    auto* ty = llvm::FunctionType::get(retTy, argTys, false);
    auto* func = llvm::Function::Create(ty, llvm::Function::LinkageTypes::ExternalLinkage, name, ctx->getMod());
    auto* bb = llvm::BasicBlock::Create(ctx->getLLVM(), "", func);
    auto* inBlock = ctx->getBuilder()->GetInsertBlock();
    ctx->getBuilder()->SetInsertPoint(bb);
    auto* retVal = block->llEval(ctx);
    if (retType != (ASTValueType)-1) ctx->getBuilder()->CreateRet(retVal);
    else ctx->getBuilder()->CreateRetVoid();

    if (inBlock) ctx->getBuilder()->SetInsertPoint(inBlock);

    return nullptr;
}