#pragma once
#include "../Parser.h"

class LLDriver
{
public:
    static void run(std::ifstream inFile);
    static void run(std::string text);
private:
    static void run(antlr4::ANTLRInputStream inStream);
};