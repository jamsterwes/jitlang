#pragma once
#include <string>
#include <vector>
#include "ASTNode.h"

class FuncCallNode : public ASTNode
{
public:
    FuncCallNode(std::string name, std::vector<ASTNode*> args) : name(name), args(args) {}
    virtual ASTNodeType getType() { return ASTNodeType::FUNC_CALL; }

    std::string name;
    std::vector<ASTNode*> args;
};