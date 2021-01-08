#pragma once
#include <string>
#include "ASTNode.h"

class DefinitionNode : public ASTNode
{
public:
    DefinitionNode(std::string name, std::string type, ASTNode* value) : name(name), type(type), value(value) {}
    virtual ASTNodeType getType() { return ASTNodeType::DEFINITION; }

    std::string name, type;
    ASTNode* value;
};