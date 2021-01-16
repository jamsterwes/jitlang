#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Double -> int (needed for NUMBER type in JITLang)
// rename to "??repstr" in bitcode
char* repstr(char* str, double times)
{
    int N = (int)times;
    // Sanity check times
    if (N <= 0)
    {
        printf("RUNTIME ERR: cannot repstr <=0 times\n");
        return NULL;
    }

    // Optimize rep 1 -> return original
    else if (N == 1)
    {
        return str;
    }

    size_t len = strlen(str);
    char* out = (char*)calloc((len * N) + 1, sizeof(char));  // + 1 for NULL byte, use calloc to zero-init, leaving trailing null byte(s) in event of under-write

    // Copy len-sized blocks from str to out
    for (int n = 0; n < N; n++)
    {
        strcpy(&out[n * len], str);
    }

    return out;
}

// Rename to "??catstr" in bitcode
char* catstr(char* lhs, char* rhs)
{
    char* out = (char*)calloc(strlen(lhs) + strlen(rhs) + 1, sizeof(char));
    strcat(out, lhs);
    strcat(out, rhs);
    return out;
}