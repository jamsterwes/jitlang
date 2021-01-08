#pragma once
#include <string>
#include "ASTNode.h"

class NumberLiteralNode : public ASTNode
{
public:
    NumberLiteralNode(std::string numberText) : value(std::stod(numberText)) {}
    NumberLiteralNode(double value) : value(value) {}
    virtual ASTNodeType getType() { return ASTNodeType::NUMBER_LITERAL; }

    double value;
};