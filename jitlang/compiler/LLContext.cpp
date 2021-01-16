#include "LLContext.h"
#include <iostream>
#include "TypeBuilder.h"

// Fix "unary minus operator ..." errors in LLVM headers.
#pragma warning (disable : 4146)

#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>

using namespace llvm;

LLContext::LLContext()
{
    _ctx = std::make_unique<LLVMContext>();
    _mod = std::make_unique<Module>("jit", *_ctx);
    _builder = std::make_unique<IRBuilder<>>(*_ctx);

    auto* printNum = Function::Create(TypeBuilder<void(double)>::get(getLLVM()), Function::LinkageTypes::ExternalLinkage, "??printNum", getMod());
    auto* printStr = Function::Create(TypeBuilder<void(char*)>::get(getLLVM()), Function::LinkageTypes::ExternalLinkage, "??printStr", getMod());
    auto* repStr = Function::Create(TypeBuilder<char*(char*, double)>::get(getLLVM()), Function::LinkageTypes::ExternalLinkage, "??repstr", getMod());
    auto* catStr = Function::Create(TypeBuilder<char*(char*, char*)>::get(getLLVM()), Function::LinkageTypes::ExternalLinkage, "??catstr", getMod());
}

llvm::IRBuilder<>* LLContext::getBuilder()
{
    return _builder.get();
}

llvm::LLVMContext& LLContext::getLLVM()
{
    return *_ctx;
}

llvm::Module* LLContext::getMod()
{
    return _mod.get();
}

void LLContext::print()
{
    _mod->print(outs(), nullptr);
}