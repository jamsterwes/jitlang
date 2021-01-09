#pragma once
#include <map>
#include <string>
#include <vector>

struct FunctionArg
{
    std::string name;
    uint8_t ty;

    FunctionArg(std::string name, uint8_t ty);
};

struct Function
{
    uint8_t retTy;
    std::vector<FunctionArg> args;
    class BlockNode* funcBlock;

    Function();
    Function(std::vector<FunctionArg> args, uint8_t retTy, class BlockNode* funcBlock);
};

class SlowContext
{
public:
    SlowContext() : _vars() {}

    // Variable access
    virtual void insertVar(std::string name, class ASTValue* value);
    virtual class ASTValue* getVar(std::string name, bool verbose=true);
    virtual void setVar(std::string name, class ASTValue* newValue);

    // Function access
    virtual void defineFunction(std::string name, Function func);
    virtual ASTValue* callFunction(std::string name, std::vector<class ASTNode*> args, SlowContext* ctx = nullptr);
private:
    std::map<std::string, class ASTValue*> _vars;
    std::map<std::string, Function> _funcs;
};