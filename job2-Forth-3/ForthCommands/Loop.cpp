#include "Loop.h"

#include "Base/CommandManager.h"
#include "Base/Function__CheckStack.h"

void Do::Debug(CommandManager & manager, std::stringstream & buffer, std::istream & in, std::stack<std::string> & keywords)
{
    std::string currentKeyword;
    keywords.emplace("do");
    while (true)
    {
        while (!(buffer >> currentKeyword))
        {
            getline(in, currentKeyword);
            std::string forReplace = buffer.str() + '\n' + currentKeyword;
            size_t pos = buffer.str().size();
            buffer.clear();
            buffer.str(forReplace);
            buffer.seekg(long(pos));
        }
        manager.Debug(currentKeyword, buffer, in);
        if (currentKeyword == "loop")
        {
            break;
        }
    }
}

void Do::Execute(CommandManager & manager, std::stack<int> & stack, std::stringstream & buffer, std::ostream & out)
{
    CheckStack(stack, 2);
    int i_start = stack.top();
    stack.pop();
    int i_end = stack.top();
    stack.pop();
    long loop_start = buffer.tellg();
    std::string original = buffer.str();
    std::string s;
    for (int i = i_start; i < i_end; i++)
    {
        std::string forReplace = buffer.str();
        while (buffer >> s && s != "loop")
        {
            if (s == "i")
            {
                forReplace.replace(size_t(buffer.tellg()) - 1, 1, std::to_string(i));
                long bufferCurrentPos = buffer.tellg();
                buffer.str(forReplace);
                buffer.seekg(bufferCurrentPos);
                while (buffer.get() != ' ');
            }
            if (s == "do")
            {
                manager.Pass(s, buffer);
            }
        }
        buffer.str(forReplace);
        buffer.seekg(loop_start);

        while (buffer >> s && s != "loop")
        {
            manager.Execute(s, buffer, stack, out);
        }

        buffer.str(original);
        buffer.seekg(loop_start);
    }
    while (buffer >> s && s != "loop")
    {
        manager.Pass(s, buffer);
    }
    buffer >> s;
}

void Do::Pass(CommandManager & manager, std::stringstream &buffer)
{
    std::string s;
    while (buffer >> s && s != "loop")
    {
        manager.Pass(s, buffer);
    }
    buffer >> s;
}

void Loop::Debug(CommandManager &, std::stringstream & buffer, std::istream & in, std::stack<std::string> & keywords)
{
    if (keywords.top() != "do")
    {
        throw std::invalid_argument("Got keyword \"loop\" "
                                    "without if statement");
    }
    else
    {
        keywords.pop();
        std::string currentKeyword;
        while (!(buffer >> currentKeyword))
        {
            getline(in, currentKeyword);
            std::string forReplace = buffer.str() + '\n' + currentKeyword;
            size_t pos = buffer.str().size();
            buffer.clear();
            buffer.str(forReplace);
            buffer.seekg(long(pos));
        }
        if (currentKeyword != ";")
        {
            throw std::invalid_argument("Expected \";\" in the end of "
                                        "do-loop-; statement");
        }

    }
}

void Loop::Execute(CommandManager &, std::stack<int> &, std::stringstream &, std::ostream &) {}