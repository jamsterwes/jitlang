#pragma once
#include <string>
#include "ASTNode.h"

class StringLiteralNode : public ASTNode
{
public:
    StringLiteralNode(std::string value) : value(value.substr(1, value.size() - 2)) {}
    virtual ASTNodeType getType() { return ASTNodeType::STRING_LITERAL; }

    std::string value;
};