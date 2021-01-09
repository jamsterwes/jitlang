#include "SlowSubcontext.h"
#include "../ast/ASTNode.h"

ASTValue* SlowSubcontext::getVar(std::string name, bool verbose)
{
    auto* val = SlowContext::getVar(name, false);
    if (val == nullptr) return parent->getVar(name, verbose);
    else return val;
}

void SlowSubcontext::setVar(std::string name, ASTValue* newValue)
{
    auto* val = SlowContext::getVar(name);
    if (val == nullptr) parent->setVar(name, newValue);
    else SlowContext::setVar(name, newValue);
}

void SlowSubcontext::defineFunction(std::string name, Function func)
{
    parent->defineFunction(name, func);
}

ASTValue* SlowSubcontext::callFunction(std::string name, std::vector<ASTNode*> args)
{
    return parent->callFunction(name, args);
}