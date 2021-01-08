#pragma once
#include <string>
#include "ASTNode.h"

class DecrNode : public ASTNode
{
public:
    DecrNode(ASTNode* value) : value(value) {}
    virtual ASTNodeType getType() { return ASTNodeType::DECR; }

    ASTNode* value;
};
