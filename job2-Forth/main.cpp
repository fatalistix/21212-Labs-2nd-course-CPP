#include <iostream>
#include <string>

#include "Forth.h"
#include "Singleton.h"

typedef SingletonHolder<Forth> ForthInterpreter;

int main()
{
    std::string inputString;
    std::string outputString;
    do
    {
        std::cout << "> " << std::flush;
        getline(std::cin, inputString);
        if (inputString == "exit()")
        {
            break;
        }
        inputString >> ForthInterpreter::Instance();
        outputString << ForthInterpreter::Instance();
        std::cout << "< " << outputString << std::endl;
    } while (true);

    std::cout << "< exited without errors" << std::endl;
}


//bool IsNumber(std::string & s)
//{
//    if (std::ranges::any_of(s.begin(), s.end(),
//                            [](char c) {return !std::isdigit(c);}))
//    {
//        return false;
//    }
//    return true;
//}


//
//int main()
//{
//    // Preparing data for interpreter
//    std::string stringCommand;
//    std::string output;
//    std::stringstream input;
//    std::map<std::string, Command *> RegisteredCommands;
//    std::map<std::string, std::string> Functions;
//    Command * command;
//
//    do
//    {
//        // Getting User's input and writing it to string stream
//        std::cout << "> " << std::flush;
//        getline(std::cin, stringCommand);
//        if (stringCommand == "exit()")
//        {
//            break;
//        }
//        input << stringCommand;
//
//
//
//
//
//
//        // Analyzing User's input
//        while (!input.eof())
//        {
//            input >> stringCommand;
//            if (IsNumber(stringCommand))
//            {
//                ForthStack::Instance().push(std::stoi(stringCommand));
//                output = "ok";
//            }
//            else
//            {
//                auto it = RegisteredCommands.find(stringCommand);
//
//                if (it == RegisteredCommands.end())
//                {
//                    try
//                    {
//                        command = CommandFactory::Instance().CreateObject(stringCommand);
//                        RegisteredCommands.insert(std::make_pair(stringCommand, command));
//                    }
//                    catch(std::invalid_argument & e)
//                    {
//                        output = e.what();
//                        break;
//                    }
//                }
//                else
//                {
//                    command = it->second;
//                }
//                try
//                {
//                    command->DoCommand(ForthStack::Instance(), input);
//                }
//                catch(std::invalid_argument& e)
//                {
//                    output = e.what();
//                }
//            }
//        }
//
//
//
//
//
//
//        // Preparing for next iteration
//        std::cout << "< " << output << " || Top -> ";
//        std::stack forOut(ForthStack::Instance());
//        while (!forOut.empty())
//        {
//            std::cout << forOut.top() << ' ';
//            forOut.pop();
//        }
//        std::cout << std::endl;
//        input.clear();
//    } while (true);
//
//    for (auto & c : RegisteredCommands)
//    {
//        delete c.second;
//    }
//
//    std::cout << "< exited without errors" << std::endl;
//}
