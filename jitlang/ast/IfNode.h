#pragma once
#include <string>
#include "ASTNode.h"
#include "BlockNode.h"

// TODO: add arguments & return
class IfNode : public ASTNode
{
public:
    IfNode(ASTNode* condition, BlockNode* block) : condition(condition), block(block) {}
    virtual ASTNodeType getType() { return ASTNodeType::IF; }

    ASTNode* condition;
    BlockNode* block;
};
