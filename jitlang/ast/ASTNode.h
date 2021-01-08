#pragma once
#pragma warning (disable : 4146)

#include <cinttypes>
#include <iostream>
#include <llvm\IR\Value.h>
#include "../compiler/LLContext.h"
#include "../interpreter/SlowContext.h"

enum class ASTNodeType : uint8_t
{
    GET_VAR = 0,
    BIN_OP = 1,
    CONST = 2,
    BLOCK = 3,
    DEF_VAR = 4,
    SET_VAR = 5,
    IF = 6,
    FUNC_CALL = 7,
    FUNC_DEFINE = 8,
};

enum class ASTValueType
{
    BOOL,
    NUMBER,
    STRING
};

inline std::string getValueTypeName(ASTValueType ty)
{
    switch (ty)
    {
    case ASTValueType::BOOL:
        return "bool";
    case ASTValueType::NUMBER:
        return "num";
    case ASTValueType::STRING:
        return "str";
    default:
        return "unknown";
    }
}

union ASTValueData
{
    bool boolValue;
    double numberValue;
    std::string* stringValue;

    ASTValueData() : numberValue(0.0) {}
    ASTValueData(bool val) : boolValue(val) {}
    ASTValueData(double val) : numberValue(val) {}
    ASTValueData(std::string* val) : stringValue(val) {}
};

struct ASTValue
{
    ASTValueType type;
    ASTValueData data;

    ASTValue(ASTValueType type, ASTValueData data) : type(type), data(data) {}
    static ASTValue* create(bool val) { return new ASTValue(ASTValueType::BOOL, ASTValueData(val)); }
    static ASTValue* create(double val) { return new ASTValue(ASTValueType::NUMBER, ASTValueData(val)); }
    static ASTValue* create(std::string* val) { return new ASTValue(ASTValueType::STRING, ASTValueData(val)); }

    void print()
    {
        if (this == nullptr) return;
        switch (type)
        {
        case ASTValueType::BOOL:
            std::cout << data.boolValue << std::endl;
            break;
        case ASTValueType::NUMBER:
            std::cout << data.numberValue << std::endl;
            break;
        case ASTValueType::STRING:
            std::cout << data.stringValue << std::endl;
            break;
        default:
            break;
        }
    }
};

class ASTNode
{
public:
    virtual ASTNodeType getType() = 0;
    virtual ASTValue* slowRun(SlowContext* ctx) = 0;
    virtual llvm::Value* llEval(LLContext* ctx) = 0;
};