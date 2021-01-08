#pragma once
#include <string>
#include <vector>
#include "ASTNode.h"

class BlockNode : public ASTNode
{
public:
    BlockNode(std::vector<ASTNode*> statements) : statements(statements) {}
    virtual ASTNodeType getType() { return ASTNodeType::BLOCK; }

    std::vector<ASTNode*> statements;
};
