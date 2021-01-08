#include <antlr4-runtime.h>
#include "grammar/JITLangLexer.h"
#include "grammar/JITLangParser.h"
#include "Parser.h"

#include "ast/BlockNode.h"
#include <string>

using namespace std;
using namespace antlr4;

int main(int argc, const char** argv)
{
    std::ifstream stream;
    if (argc > 1) stream.open(argv[1]);
    else stream.open("samples/count.jit");

    ANTLRInputStream input(stream);
    JITLangLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    JITLangParser antlrParser(&tokens);
    JITLangParser::FileContext* file = antlrParser.file();

    jitlang::Parser parser;

    BlockNode* rootBlockNode = (BlockNode*)parser.visitFile(file);

    auto* ctx = new SlowContext();

    auto* res = rootBlockNode->slowRun(ctx);
    res->print();

    stream.close();
    if (argc <= 1)
    {
        std::cout << "-- Program finished!";
        std::cin.get();
    }

    return 0;
}