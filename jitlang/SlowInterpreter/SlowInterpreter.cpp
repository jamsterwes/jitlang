#include "SlowInterpreter.h"
#include "../ast/AssignmentNode.h"
#include "../ast/BlockNode.h"
#include "../ast/CompareNode.h"
#include "../ast/DecrNode.h"
#include "../ast/DefinitionNode.h"
#include "../ast/FuncCallNode.h"
#include "../ast/FunctionDefinitionNode.h"
#include "../ast/IdentifierNode.h"
#include "../ast/IfNode.h"
#include "../ast/IncrNode.h"
#include "../ast/NumberLiteralNode.h"
#include "../ast/StringLiteralNode.h"

#include <iostream>

namespace slow
{
    void SlowInterpreter::runNode(ASTNode* node)
    {
        switch (node->getType())
        {
        case ASTNodeType::DEFINITION:
            evalDefinition((DefinitionNode*)node);
            break;
        case ASTNodeType::ASSIGNMENT:
            evalAssignment((AssignmentNode*)node);
            break;
        case ASTNodeType::STRING_LITERAL:
            std::cout << ((StringLiteralNode*)node)->value << std::endl;
            break;
        case ASTNodeType::NUMBER_LITERAL:
            std::cout << ((NumberLiteralNode*)node)->value << std::endl;
            break;
        case ASTNodeType::IDENTIFIER:
            evalIdentifier((IdentifierNode*)node);
            break;
        case ASTNodeType::INCR:
            evalIncr((IncrNode*)node);
            break;
        case ASTNodeType::DECR:
            evalDecr((DecrNode*)node);
            break;
        case ASTNodeType::FUNC_CALL:
            evalFuncCall((FuncCallNode*)node);
            break;
        case ASTNodeType::BLOCK:
            // TODO: add block-level context
            for (auto* node : ((BlockNode*)node)->statements) runNode(node);
            break;
        case ASTNodeType::FUNC_DEFINITION:
            evalFuncDefine((FunctionDefinitionNode*)node);
            break;
        case ASTNodeType::COMPARE:
            std::cout << evalCompareNode((CompareNode*)node) << std::endl;
            break;
        case ASTNodeType::IF:
            evalIfNode((IfNode*)node);
            break;
        default:
            break;
        }
    }

    void SlowInterpreter::evalDefinition(DefinitionNode* node)
    {
        if (_symbolTypes.find(node->name) != _symbolTypes.end())
        {
            std::cout << "ERROR: " << node->name << " already defined (no redefinition yet)";
            return;
        }

        if (node->type == "num")
        {
            double val = ((NumberLiteralNode*)node->value)->value;
            _symbolTypes[node->name] = Type::NUMBER;
            _numberValues[node->name] = val;
        }
        else if (node->type == "str")
        {
            std::string val = ((StringLiteralNode*)node->value)->value;
            _symbolTypes[node->name] = Type::STRING;
            _stringValues[node->name] = val;
        }
        else
        {
            std::cout << "ERROR: unknown type " << node->type << std::endl;
        }
    }

    void SlowInterpreter::evalAssignment(AssignmentNode* node)
    {
        if (_symbolTypes.find(node->name) == _symbolTypes.end())
        {
            std::cout << "ERROR: " << node->name << " not defined yet (no type inference yet)";
            return;
        }

        Type ty = _symbolTypes[node->name];

        if (ty == Type::STRING)
        {
            _stringValues[node->name] = ((StringLiteralNode*)node->value)->value;
        }
        else if (ty == Type::NUMBER)
        {
            _numberValues[node->name] = ((NumberLiteralNode*)node->value)->value;
        }
        else
        {
            std::cout << "RUNTIME ERROR: unknown type " << (int)ty << " for variable " << node->name << std::endl;
        }
    }

    void SlowInterpreter::evalIdentifier(IdentifierNode* node)
    {
        if (_symbolTypes.find(node->name) == _symbolTypes.end())
        {
            std::cout << "ERROR: " << node->name << " not defined";
            return;
        }

        Type ty = _symbolTypes[node->name];

        if (ty == Type::STRING)
        {
            std::cout << "\"" << _stringValues[node->name] << "\"" << std::endl;
        }
        else if (ty == Type::NUMBER)
        {
            std::cout << _numberValues[node->name] << std::endl;
        }
        else
        {
            std::cout << "RUNTIME ERROR: unknown type " << (int)ty << " for variable " << node->name << std::endl;
        }
    }

    void SlowInterpreter::evalFuncCall(FuncCallNode* node)
    {
        if (_functionTable.find(node->name) == _functionTable.end())
        {
            std::cout << "ERROR: function " << node->name << " not defined";
            return;
        }
        runNode(_functionTable[node->name]);
    }

    void SlowInterpreter::evalFuncDefine(FunctionDefinitionNode* node)
    {
        if (_functionTable.find(node->name) != _functionTable.end())
        {
            std::cout << "ERROR: function " << node->name << " already defined (no redefinition)";
            return;
        }
        _functionTable[node->name] = node->block;
    }

    void SlowInterpreter::evalIncr(IncrNode* node)
    {
        // For now, value must be an IdentifierNode
        if (node->value->getType() != ASTNodeType::IDENTIFIER)
        {
            std::cout << "ERROR: ++ only compatible with IDENTIFIER" << std::endl;
            return;
        }

        std::string name = ((IdentifierNode*)node->value)->name;

        if (_symbolTypes.find(name) == _symbolTypes.end())
        {
            std::cout << "ERROR: " << name << " not defined";
            return;
        }

        Type ty = _symbolTypes[name];

        if (ty == Type::NUMBER)
        {
            _numberValues[name] += 1.0;
        }
        else
        {
            std::cout << "ERROR: variable " << name << " of type " << (int)ty << " not compatible with ++" << std::endl;
        }
    }

    void SlowInterpreter::evalDecr(DecrNode* node)
    {
        // For now, value must be an IdentifierNode
        if (node->value->getType() != ASTNodeType::IDENTIFIER)
        {
            std::cout << "ERROR: -- only compatible with IDENTIFIER" << std::endl;
            return;
        }

        std::string name = ((IdentifierNode*)node->value)->name;

        if (_symbolTypes.find(name) == _symbolTypes.end())
        {
            std::cout << "ERROR: " << name << " not defined" << std::endl;
            return;
        }

        Type ty = _symbolTypes[name];

        if (ty == Type::NUMBER)
        {
            _numberValues[name] -= 1.0;
        }
        else
        {
            std::cout << "ERROR: variable " << name << " of type " << (int)ty << " not compatible with --" << std::endl;
        }
    }

    void SlowInterpreter::evalIfNode(IfNode* node)
    {
        // Only working with cond = COMPARE for now
        if (node->condition->getType() != ASTNodeType::COMPARE)
        {
            std::cout << "ERROR: If statements only compatible with comparison conditions for now" << std::endl;
            return;
        }

        // Evaluate comparison
        bool shouldRun = evalCompareNode((CompareNode*)node->condition);
        if (shouldRun) runNode(node->block);
    }

    bool SlowInterpreter::evalCompareNode(CompareNode* node)
    {
        // Step 1: Are both lhs and rhs identifiers?
        if (node->lhs->getType() != ASTNodeType::IDENTIFIER || node->rhs->getType() != ASTNodeType::IDENTIFIER)
        {
            std::cout << "ERROR: comparison only compatible with identifiers for now" << std::endl;
            return false;
        }
        // Step 2: Are both lhs and rhs defined?
        auto* lhsID = (IdentifierNode*)node->lhs;
        auto* rhsID = (IdentifierNode*)node->rhs;

        // TODO: figure out which one undefined(?)
        if (_symbolTypes.find(lhsID->name) == _symbolTypes.end() || _symbolTypes.find(rhsID->name) == _symbolTypes.end())
        {
            std::cout << "ERROR: undefined symbol in comparison" << std::endl;
            return false;
        }

        // Step 3: matching types?
        Type lhsTy = _symbolTypes[lhsID->name];
        Type rhsTy = _symbolTypes[rhsID->name];

        if (lhsTy != rhsTy)
        {
            std::cout << "ERROR: mismatching types in comparison" << std::endl;
            return false;
        }

        // Step 4: compare

        // For string, only == and != are valid
        if (lhsTy == Type::STRING)
        {
            if (node->cmpop == "==") return _stringValues[lhsID->name] == _stringValues[rhsID->name];
            else if (node->cmpop == "!=") return _stringValues[lhsID->name] == _stringValues[rhsID->name];
            else
            {
                std::cout << "ERROR: cmpop " << node->cmpop << " not compatible with strings" << std::endl;
                return false;
            }
        }
        else if (lhsTy == Type::NUMBER)
        {
            if (node->cmpop == ">") return _numberValues[lhsID->name] > _numberValues[rhsID->name];
            else if (node->cmpop == ">=") return _numberValues[lhsID->name] >= _numberValues[rhsID->name];
            else if (node->cmpop == "<") return _numberValues[lhsID->name] < _numberValues[rhsID->name];
            else if (node->cmpop == "<=") return _numberValues[lhsID->name] <= _numberValues[rhsID->name];
            else if (node->cmpop == "==") return _numberValues[lhsID->name] == _numberValues[rhsID->name];
            else if (node->cmpop == "!=") return _numberValues[lhsID->name] != _numberValues[rhsID->name];
            else
            {
                std::cout << "ERROR: cmpop " << node->cmpop << " not compatible with strings" << std::endl;
                return false;
            }
        }
        else
        {
            std::cout << "ERROR: type " << (int)lhsTy << " not compatible with comparison" << std::endl;
            return false;
        }
    }
}