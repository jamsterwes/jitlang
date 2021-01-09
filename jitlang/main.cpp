#include <antlr4-runtime.h>
#include "grammar/JITLangLexer.h"
#include "grammar/JITLangParser.h"
#include "Parser.h"

#include "ast/BlockNode.h"
#include <string>

using namespace std;
using namespace antlr4;

jitlang::Parser* parser;
SlowContext* ctx;

void interpret(std::string line)
{
    ANTLRInputStream input(line);
    JITLangLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    JITLangParser antlrParser(&tokens);

    JITLangParser::FileContext* stmt = antlrParser.file();
    auto* res = parser->visitFile(stmt)->slowRun(ctx);
    res->print();
}

std::string readBlock(int n)
{
    std::string inputStr = "";
    char* input = new char[256];
    do {
        if (inputStr.length() > 0 && inputStr[inputStr.length() - 1] == '{') inputStr += readBlock(n + 1);
        for (int i = 0; i < n; ++i) printf("    ");
        std::cin.getline(input, 256);
        inputStr += input;
    } while (inputStr[inputStr.length() - 1] != '}');
    return inputStr;
}

int main(int argc, const char** argv)
{
    //std::ifstream stream;
    //if (argc > 1) stream.open(argv[1]);
    //else stream.open("samples/func.jit");

    //ANTLRInputStream input(stream);
    //BlockNode* rootBlockNode = (BlockNode*)parser.visitFile(file);
    //stream.close();

    parser = new jitlang::Parser();
    ctx = new SlowContext();

    while (true)
    {
        printf("jitlang: ");
        std::string inputStr = "";
        char* input = new char[256];
        std::cin.getline(input, 256);
        inputStr += input;
        if (inputStr[inputStr.length() - 1] == '{') inputStr += readBlock(1);
        interpret(inputStr);
    }

    if (argc <= 1)
    {
        std::cout << "-- Program finished!";
        std::cin.get();
    }

    return 0;
}