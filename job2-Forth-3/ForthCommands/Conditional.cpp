#include "Conditional.h"

#include "../CommandManager.h"

void If::Debug(std::stringstream & buffer, std::istream & in,
               std::stack<std::string> & keywords)
{
    std::string currentKeyword;
    keywords.emplace("if");
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
        ForthCommandManager::Instance().Debug(currentKeyword, buffer, in);
        if (currentKeyword == "else" || currentKeyword == "then")
        {
            break;
        }
    }
}

void If::Execute(std::stack<int> & stack, std::stringstream & buffer, std::ostream & out)
{
    if (stack.empty())
    {
        throw std::runtime_error("Stack underflow");
    }
    if (stack.top())
    {
        stack.pop();
        std::string currentKeyword;
        while (buffer >> currentKeyword && currentKeyword != "else" && currentKeyword != "then")
        {
            ForthCommandManager::Instance().Execute(currentKeyword, buffer, stack, out);
        }
        if (currentKeyword == "else")
        {
            while (buffer >> currentKeyword && currentKeyword != "then")
            {
                ForthCommandManager::Instance().Pass(currentKeyword, buffer);
            }
        }
        buffer >> currentKeyword;
    }
    else
    {
        stack.pop();
        std::string currentKeyword;
        while (buffer >> currentKeyword && currentKeyword != "else" && currentKeyword != "then")
        {
            ForthCommandManager::Instance().Pass(currentKeyword, buffer);
        }
        if (currentKeyword == "else")
        {
            while (buffer >> currentKeyword && currentKeyword != "then")
            {
                ForthCommandManager::Instance().Execute(currentKeyword, buffer, stack, out);
            }
        }
        buffer >> currentKeyword;
    }
}

void If::Pass(std::stringstream & buffer)
{
    std::string currentKeyword;
    while (buffer >> currentKeyword && currentKeyword != "then")
    {
        ForthCommandManager::Instance().Pass(currentKeyword, buffer);
    }
    buffer >> currentKeyword;
}

void Else::Debug(std::stringstream & buffer, std::istream & in,
                 std::stack<std::string> & keywords)
{
    if (keywords.top() != "if")
    {
        throw std::invalid_argument("Got keyword \"else\" "
                                    "without if statement");
    }
    else
    {
        std::string currentKeyword;
        keywords.pop();
        keywords.emplace("else");
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
            ForthCommandManager::Instance().Debug(currentKeyword, buffer, in);
            if (currentKeyword == "then")
            {
                break;
            }
        }
    }
}

void Else::Execute(std::stack<int> &, std::stringstream &, std::ostream &) {}

void Then::Debug(std::stringstream & buffer, std::istream & in,
                 std::stack<std::string> & keywords)
{
    if (keywords.top() == "if" || keywords.top() == "else")
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
                                        "if-then-; or if-else-then-; statement");
        }
    }
    else
    {
        throw std::invalid_argument("Got keyword \"then\" "
                                    "without if statement");
    }
}

void Then::Execute(std::stack<int> &, std::stringstream &, std::ostream &) {}
