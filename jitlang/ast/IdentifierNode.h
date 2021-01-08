#pragma once
#include <string>
#include "ASTNode.h"

class IdentifierNode : public ASTNode
{
public:
    IdentifierNode(std::string name) : name(name) {}
    virtual ASTNodeType getType() { return ASTNodeType::IDENTIFIER; }

    std::string name;
};
