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
    std::vector<FunctionArg> args;
    class BlockNode* funcBlock;

    Function();
    Function(std::vector<FunctionArg> args, class BlockNode* funcBlock);
};

class SlowContext
{
public:
    SlowContext() : _vars() {}

    // Variable access
    void insertVar(std::string name, class ASTValue* value);
    class ASTValue* getVar(std::string name);
    void setVar(std::string name, class ASTValue* newValue);

    // Function access
    void defineFunction(std::string name, Function func);
    ASTValue* callFunction(std::string name, std::vector<class ASTNode*> args);
private:
    std::map<std::string, class ASTValue*> _vars;
    std::map<std::string, Function> _funcs;
};