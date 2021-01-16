#include "LLDriver.h"
#include "../grammar/JITLangLexer.h"
#include "../grammar/JITLangParser.h"
#include "../ast/FuncDefineNode.h"

using namespace antlr4;

void LLDriver::run(std::ifstream inFile)
{
    run(ANTLRInputStream(inFile));
}

void LLDriver::run(std::string text)
{
    run(ANTLRInputStream(text));
}

void LLDriver::run(ANTLRInputStream inStream)
{
    auto* parser = new jitlang::Parser();
    auto* ctx = new LLContext();

    JITLangLexer lexer(&inStream);
    CommonTokenStream tokens(&lexer);
    JITLangParser antlrParser(&tokens);

    JITLangParser::FileContext* fileAST = antlrParser.file();

    BlockNode* res = (BlockNode*)parser->visitFile(fileAST);
    FuncDefineNode* mainNode = new FuncDefineNode("llMain", {}, res);
    mainNode->llEval(ctx);

    ctx->print();
}