#include <stdio.h>

// rename to "??printNum" in bitcode
void printNum(double num)
{
    printf("%f\n", num);
}

// rename to "??printStr" in bitcode
void printStr(char* str)
{
    printf("%s\n", str);
}