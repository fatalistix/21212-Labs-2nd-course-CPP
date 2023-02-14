#include <iostream>
#include "Forth.h"

int main()
{
    std::cin.exceptions(std::ios::badbit | std::ios::failbit);
    Forth ForthInterpreter;
    try
    {
        while (true)
        {
            std::cout << "> " << std::flush;

            if (!ForthInterpreter.ReadAndExecute(std::cin, std::cout))
            {
                break;
            }
        }

    }
    catch (std::istream::failure &)
    {
        std::cout << "< Input/output streams error" << std::endl;
        return 0;
    }
    
    std::cout << "< Exited without errors" << std::endl;
    return 0;
}

