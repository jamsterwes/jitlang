#pragma once
#include "../ast/ASTNode.h"
#include <map>
#include <string>
#include <vector>

class DefinitionNode;
class AssignmentNode;
class IdentifierNode;
class IncrNode;
class DecrNode;
class FunctionDefinitionNode;
class CompareNode;
class FuncCallNode;
class BlockNode;
class IfNode;

namespace slow
{
    enum class Type : uint8_t
    {
        STRING = 0,
        NUMBER
    };

    class SlowInterpreter
    {
    public:
        SlowInterpreter() : _symbolTypes(), _numberValues(), _stringValues() {}
        void runNode(ASTNode* node);
    private:
        void evalDefinition(DefinitionNode* node);
        void evalAssignment(AssignmentNode* node);
        void evalIdentifier(IdentifierNode* node);
        void evalFuncCall(FuncCallNode* node);
        void evalFuncDefine(FunctionDefinitionNode* node);
        void evalIncr(IncrNode* node);
        void evalDecr(DecrNode* node);
        void evalIfNode(IfNode* node);
        bool evalCompareNode(CompareNode* node);
        // Symbol table / Simulated memory
        std::map<std::string, Type> _symbolTypes;
        std::map<std::string, double> _numberValues;
        std::map<std::string, std::string> _stringValues;
        // Function table
        // TODO: function arguments
        std::map<std::string, BlockNode*> _functionTable;
        // TODO: hardcoded functions
    };
}