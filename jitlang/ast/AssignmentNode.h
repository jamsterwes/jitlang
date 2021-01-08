#pragma once
#include <string>
#include "ASTNode.h"

class AssignmentNode : public ASTNode
{
public:
    AssignmentNode(std::string name, ASTNode* value) : name(name), value(value) {}
    virtual ASTNodeType getType() { return ASTNodeType::ASSIGNMENT; }

    std::string name;
    ASTNode* value;
};