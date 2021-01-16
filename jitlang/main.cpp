#include "drivers\LLDriver.h"
#include <fstream>

int main(int argc, const char** argv)
{
    LLDriver::run(std::ifstream("samples/lltest.jit"));

    std::cout << std::endl;

    if (argc <= 1)
    {
        std::cout << "-- Program finished!";
        std::cin.get();
    }

    return 0;
}