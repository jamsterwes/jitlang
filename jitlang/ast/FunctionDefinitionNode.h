#pragma once
#include <string>
#include "ASTNode.h"
#include "BlockNode.h"

// TODO: add arguments & return
class FunctionDefinitionNode : public ASTNode
{
public:
    FunctionDefinitionNode(std::string name, BlockNode* block) : name(name), block(block) {}
    virtual ASTNodeType getType() { return ASTNodeType::FUNC_DEFINITION; }

    std::string name;
    BlockNode* block;
};
