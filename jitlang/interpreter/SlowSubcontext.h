#pragma once
#include "SlowContext.h"

class SlowSubcontext : public SlowContext
{
public:
    SlowSubcontext(SlowContext* parent) : SlowContext(), parent(parent) {}

    // Not overriding insertVar -- all new variables go in deepest subcontext
    virtual class ASTValue* getVar(std::string name, bool verbose=true) override;
    virtual void setVar(std::string name, class ASTValue* newValue) override;
    /* Function definition goes straight to global */
    virtual void defineFunction(std::string name, Function func) override;
    virtual ASTValue* callFunction(std::string name, std::vector<class ASTNode*> args, SlowContext* ctx = nullptr);
private:
    SlowContext* parent;
};