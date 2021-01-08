#pragma once
#include <cinttypes>

enum class ASTNodeType : uint8_t
{
    DEFINITION = 0,
    ASSIGNMENT,
    STRING_LITERAL,
    NUMBER_LITERAL,
    IDENTIFIER,
    INCR,
    DECR,
    FUNC_CALL,
    BLOCK,  // Sequence of statements
    FUNC_DEFINITION,
    COMPARE,
    IF
};

class ASTNode
{
public:
    virtual ASTNodeType getType() = 0;
};