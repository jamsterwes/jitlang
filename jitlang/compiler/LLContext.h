#pragma once

// Fix "unary minus operator ..." errors in LLVM headers.
#pragma warning (disable : 4146)

#include <llvm/IR/IRBuilder.h>
#include <memory>

class LLContext
{
public:
    LLContext();

    llvm::IRBuilder<>* getBuilder();
    llvm::LLVMContext& getLLVM();
    llvm::Module* getMod();

    void print();
private:
    std::unique_ptr<llvm::LLVMContext> _ctx;
    std::unique_ptr<llvm::Module> _mod;
    std::unique_ptr<llvm::IRBuilder<>> _builder;
};