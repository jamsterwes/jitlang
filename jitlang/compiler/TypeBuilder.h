#pragma once

// Fix "unary minus operator ..." errors in LLVM headers
#pragma warning (disable : 4146)

#include <llvm/IR/IRBuilder.h>

//using namespace llvm;

// Note, this file was written for ease-of-use, not to look pretty...

/*
Base Template
Handles core types
*/
template<class T>
class TypeBuilder
{
public:
    static llvm::Type* get(llvm::LLVMContext& ctx);
    static llvm::Value* makeConst(llvm::LLVMContext& ctx, T value);
};

/*
Array Template
Sometimes works, sometimes is parsed as pointer type
At its best, it handles the [6 x i8] style types in llvm
- which aren't necessarily better than raw pointers
*/
template<class T, uint64_t num>
class TypeBuilder<T[num]>
{
public:
    static llvm::ArrayType* get(llvm::LLVMContext& ctx);
};

/*
Pointer Template
Handles pointers (chainable via recursive parsing i.e. int*** is seen as ((int*)*)* and handled inside-out)
*/
template<class T>
class TypeBuilder<T*>
{
public:
    static llvm::PointerType* get(llvm::LLVMContext& ctx);
};

/*
Return-less Function Template
void(...) causes errors in templating without being explicitly handled
- Here, this is avoided by defining a void(...) function directly
-- varArgs=true allows varargs after the explicitly defined ones
*/
template<class ... Args>
class TypeBuilder<void(Args...)>
{
public:
    static llvm::FunctionType* get(llvm::LLVMContext& ctx, bool varArgs = false);
};

/*
Value-returning Function Template
Handles functions that return variables
-- varArgs=true allows varargs after the explicitly defined ones
*/
template<class Ret, class ... Args>
class TypeBuilder<Ret(Args...)>
{
public:
    static llvm::FunctionType* get(llvm::LLVMContext& ctx, bool varArgs = false);
};

/*
0 Argument List Template
Handles creating the vector for an empty argument list
- Allows the unpacking template to handle an empty pack
*/
template<class ... A>
typename ::std::enable_if<sizeof...(A) == 0, ::std::vector<llvm::Type*>>::type func(llvm::LLVMContext& ctx)
{
    return std::vector<llvm::Type*>();
}

/*
Argument List Template
Handles creating a vector of the function argument types
- Uses [v, vs...] recursive parsing
*/
template<class A, class ...B> ::std::vector<llvm::Type*> func(llvm::LLVMContext& ctx)
{
    std::vector<llvm::Type*> types = func<B...>(ctx);
    types.push_back(TypeBuilder<A>::get(ctx));
    return types;
}

/** Built-in types **/

inline llvm::Type* TypeBuilder<bool>::get(llvm::LLVMContext& ctx)
{
    return llvm::Type::getInt1Ty(ctx);
}

inline llvm::Value* TypeBuilder<bool>::makeConst(llvm::LLVMContext& ctx, bool value)
{
    return llvm::ConstantInt::get(ctx, llvm::APInt(1, value));
}

inline llvm::Type* TypeBuilder<char>::get(llvm::LLVMContext& ctx)
{
    return llvm::Type::getInt8Ty(ctx);
}

inline llvm::Value* TypeBuilder<char>::makeConst(llvm::LLVMContext& ctx, char value)
{
    return llvm::ConstantInt::get(ctx, llvm::APInt(8, value));
}

inline llvm::Type* TypeBuilder<short>::get(llvm::LLVMContext& ctx)
{
    return llvm::Type::getInt16Ty(ctx);
}

inline llvm::Value* TypeBuilder<short>::makeConst(llvm::LLVMContext& ctx, short value)
{
    return llvm::ConstantInt::get(ctx, llvm::APInt(16, value));
}

inline llvm::Type* TypeBuilder<int>::get(llvm::LLVMContext& ctx)
{
    return llvm::Type::getInt32Ty(ctx);
}

inline llvm::Value* TypeBuilder<int>::makeConst(llvm::LLVMContext& ctx, int value)
{
    return llvm::ConstantInt::get(ctx, llvm::APInt(32, value));
}

inline llvm::Type* TypeBuilder<float>::get(llvm::LLVMContext& ctx)
{
    return llvm::Type::getFloatTy(ctx);
}

inline llvm::Type* TypeBuilder<double>::get(llvm::LLVMContext& ctx)
{
    return llvm::Type::getDoubleTy(ctx);
}

inline llvm::Value* TypeBuilder<double>::makeConst(llvm::LLVMContext& ctx, double value)
{
    auto llVal = llvm::APFloat(value);
    return llvm::ConstantFP::get(ctx, llVal);
}

// void* is an invalid type in LLVM, therefore, handling void* as i8* (a byte array is an appropriate replacement type)
inline llvm::PointerType* TypeBuilder<void*>::get(llvm::LLVMContext& ctx)
{
    return TypeBuilder<char*>::get(ctx);
}

/** Pointer/Array specialized types **/

template<class T, uint64_t num>
inline llvm::ArrayType* TypeBuilder<T[num]>::get(llvm::LLVMContext& ctx)
{
    return llvm::ArrayType::get(TypeBuilder<T>::get(ctx), num);
}

template<class T>
inline llvm::PointerType* TypeBuilder<T*>::get(llvm::LLVMContext& ctx)
{
    return TypeBuilder<T>::get(ctx)->getPointerTo();
}

/** void(...) function type **/

template<class ...Args>
inline llvm::FunctionType* TypeBuilder<void(Args...)>::get(llvm::LLVMContext& ctx, bool varArgs)
{
    auto args = func<Args...>(ctx);
    std::reverse(args.begin(), args.end());
    return llvm::FunctionType::get(llvm::Type::getVoidTy(ctx), args, varArgs);
}

/** Ret(...) function type **/

template<class Ret, class ...Args>
inline llvm::FunctionType* TypeBuilder<Ret(Args...)>::get(llvm::LLVMContext& ctx, bool varArgs)
{
    auto args = func<Args...>(ctx);
    std::reverse(args.begin(), args.end());
    return llvm::FunctionType::get(TypeBuilder<Ret>::get(ctx), args, varArgs);
}