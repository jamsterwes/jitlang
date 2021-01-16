#include <stdio.h>

extern void llMain();

// rename to "??printNum" in bitcode
void printNum(double num)
{
    printf("%f\n", num);
}

int main(int argc, const char** argv)
{
    llMain();
    return 0;
}