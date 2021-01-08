#pragma once
#include <string>
#include "ASTNode.h"

class IncrNode : public ASTNode
{
public:
    IncrNode(ASTNode* value) : value(value) {}
    virtual ASTNodeType getType() { return ASTNodeType::INCR; }

    ASTNode* value;
};
