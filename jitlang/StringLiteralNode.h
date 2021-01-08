#pragma once
#include <string>
#include "ASTNode.h"

class StringLiteralNode : public ASTNode
{
public:
    StringLiteralNode(std::string value) : value(value) {}
    virtual ASTNodeType getType() { return ASTNodeType::STRING_LITERAL; }

    std::string value;
};