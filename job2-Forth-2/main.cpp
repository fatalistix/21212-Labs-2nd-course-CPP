#include <iostream>
#include <string>

#include "Forth.h"

int main()
{
    // #TODO: Add stream exceptions catch as at doc

    std::string output;
    std::string inputBufferString;

    while (true)
    {
        std::cout << "> " << std::flush;

        getline(std::cin, inputBufferString);
        if (inputBufferString == "exit()")
        {
            break;
        }

        std::stringstream input;
        input << inputBufferString;

        input >> ForthInterpreter::Instance();
        output << ForthInterpreter::Instance();

        size_t it;
        while ((it = output.find('\n', it)) != std::string::npos)
        {
            output.replace(it, 1, "\n< ");
            ++it;
        }

        std::cout << "< " << output << std::endl;
    }

    std::cout << "< exited without errors" << std::endl;
    return 0;
}

//    do
//    {
//        std::cout << "> " << std::flush;
//        getline(std::cin, inputString);
//        if (inputString == "exit()")
//        {
//            break;
//        }
//        inputString  >> ForthInterpreter::Instance();
//        outputString << ForthInterpreter::Instance();
//
//        size_t it;
//        while ((it = outputString.find('\n', it)) != std::string::npos)
//        {
//            outputString.replace(it, 1, "\n< ");
//            ++it;
//        }
//        std::cout << "< " << outputString << std::endl;
//
//    } while (true);
