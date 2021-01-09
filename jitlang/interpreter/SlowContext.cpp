#pragma once
#include "../ast/ASTNode.h"
#include "../ast/BlockNode.h"
#include "SlowContext.h"
#include <iostream>

FunctionArg::FunctionArg(std::string name, uint8_t ty) : name(name), ty(ty) {}
Function::Function() : args(), funcBlock(new BlockNode({})) {}
Function::Function(std::vector<FunctionArg> args, uint8_t retTy, BlockNode* funcBlock) : args(args), retTy(retTy), funcBlock(funcBlock) {}

void SlowContext::insertVar(std::string name, ASTValue* value)
{
    if (_vars.find(name) != _vars.end())
    {
        std::cout << "ERROR: variable " << name << " already defined!" << std::endl;
        return;
    }

    _vars[name] = value;
}

ASTValue* SlowContext::getVar(std::string name)
{
    if (_vars.find(name) == _vars.end())
    {
        std::cout << "ERROR: variable " << name << " not defined!" << std::endl;
        return nullptr;
    }

    return _vars[name];
}

void SlowContext::setVar(std::string name, ASTValue* newValue)
{
    if (_vars.find(name) == _vars.end())
    {
        std::cout << "ERROR: variable " << name << " not yet defined!" << std::endl;
    }

    // TODO: fix possible memory leak here (leaking old value of _vars[name])
    _vars[name] = newValue;
}

void SlowContext::defineFunction(std::string name, Function func)
{
    if (_funcs.find(name) != _funcs.end())
    {
        std::cout << "ERROR: function " << name << " already defined!" << std::endl;
        return;
    }

    _funcs[name] = func;
}

ASTValue* SlowContext::callFunction(std::string name, std::vector<ASTNode*> args)
{
    // Check builtins
    if (name == "print")
    {
        for (auto* argNode : args)
        {
            auto* argValue = argNode->slowRun(this);
            argValue->print();
        }
        return nullptr;
    }

    if (_funcs.find(name) == _funcs.end())
    {
        std::cout << "ERROR: function " << name << " not defined!" << std::endl;
        return nullptr;
    }

    auto f = _funcs[name];

    std::vector<ASTValue*> argValues{};
    for (auto* argNode : args)
    {
        auto* argVal = argNode->slowRun(this);
        argValues.push_back(argVal);
    }

    for (int i = 0; i < f.args.size(); i++)
    {
        // Set or assign (?)
        if (f.args[i].ty != (uint8_t)argValues[i]->type)
        {
            std::cout << "ERROR: type mismatch on parameter " << f.args[i].name << std::endl;
            continue;
        }

        if (_vars.find(f.args[i].name) == _vars.end()) this->insertVar(f.args[i].name, argValues[i]);
        else this->setVar(f.args[i].name, argValues[i]);
    }

    // TODO: context handling
    auto* ret = f.funcBlock->slowRun(this);
    if ((int8_t)f.retTy == -1) return nullptr;
    else
    {   
        if (ret == nullptr)
        {
            std::cout << "Missing return for function " << name << std::endl;
            return nullptr;
        }
        if ((uint8_t)ret->type != f.retTy)
        {
            std::cout << "Return type mismatch on function " << name << std::endl;
            return nullptr;
        }
        else return ret;
    }
}