#include "Loop.h"

#include "FunctionClearStack.h"
#include "FunctionGetCommandType.h"

bool IsCorrectLoop(std::stringstream & inputCopy)
{
    std::string s;
    while (inputCopy >> s && s != "do" && s != "loop" && s != ";");
    if (s == "do")
    {
        if (!IsCorrectLoop(inputCopy))
        {
            return false;
        }
        while (inputCopy >> s && s != "loop" && s != ";");
    }
    if (s == "loop")
    {
        if (inputCopy >> s && s == ";")
        {
            return true;
        }
    }
    return false;
}


void Do::DoCommand(std::stack<int> & fStack_,
                       std::stringstream & input, std::string & output)
{
    if (fStack_.size() < 2)
    {
        ClearStack(fStack_);
        throw std::invalid_argument("Stack Underflow");
    }

    {
        std::stringstream inputCopy;
        inputCopy.str(input.str());
        inputCopy.seekg(input.tellg());

        if (!IsCorrectLoop(inputCopy))
        {
            throw std::invalid_argument("Incorrect Loop Structure");
        }
    }

//    std::string forReplace = input.str();
//    long pos = input.tellg();
//    auto it = forReplace.find("loop", input.tellg());
//    forReplace.replace(it, 4, " ");
//    input.str(forReplace);
//    input.seekg(pos + 1);


    int i = fStack_.top();
    fStack_.pop();
    int n = fStack_.top();
    fStack_.pop();

    std::string s;
    for (; i < n; i++)
    {
        std::stringstream inputCopy;
        inputCopy.str(input.str());
        inputCopy.seekg(input.tellg());

        while (inputCopy >> s && s != "loop")
        {
            if (s == "i")
            {
                fStack_.push(i);
            }
            else
            {
                auto inputCommandType = GetCommandType(s);

                switch (inputCommandType)
                {
                    case PUSH_INT:
                    {
                        fStack_.push(std::stoi(s));
                    }
                    case COMMAND:
                    {
                        Command * command = CommandFactory::Instance().CreateObject(s);
                        try
                        {
                            command->DoCommand(fStack_, inputCopy, output);
                        }
                        catch (std::invalid_argument & e)
                        {
                            delete command;
                            throw e;
                        }
                        delete command;
                    }
                }
            }
        }
    }
}

