#pragma once
#include <string>
#include "ASTNode.h"

class CompareNode : public ASTNode
{
public:
    CompareNode(ASTNode* lhs, ASTNode* rhs, std::string cmpop) : lhs(lhs), rhs(rhs), cmpop(cmpop) {}
    virtual ASTNodeType getType() { return ASTNodeType::COMPARE; }

    ASTNode* lhs;
    ASTNode* rhs;
    std::string cmpop;
};
