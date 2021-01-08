#pragma once
#include "../ast/ASTNode.h"
#include "../ast/BlockNode.h"
#include "SlowContext.h"
#include <iostream>

FunctionArg::FunctionArg(std::string name, uint8_t ty) : name(name), ty(ty) {}
Function::Function() : args(), funcBlock(new BlockNode({})) {}
Function::Function(std::vector<FunctionArg> args, BlockNode* funcBlock) : args(args), funcBlock(funcBlock) {}

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

    // TODO: context/argument handling
    /*std::vector<ASTValue*> arg = 
    for (auto* argNode : args)
    {
        auto* argVal
    }*/

    // TODO: context handling
    return f.funcBlock->slowRun(this);
}