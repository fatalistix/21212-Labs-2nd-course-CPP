#include "ConditionalOperator.h"

enum ConditionType
{
    INCORRECT = 0,
    IF_THEN = 1,
    IF_ELSE_THEN = 2,
};

typedef char ConditionType_t;

ConditionType_t CheckCondition(std::stringstream & input)
{
    std::stringstream inputCopy;
    inputCopy.str(input.str());
    inputCopy.seekg(input.tellg());

    std::string s;
    while (inputCopy >> s && s != "else" && s != "then" && s != ";");
    if (s == "then")
    {
        if (inputCopy >> s && s == ";")
        {
            return IF_THEN;
        }
    }
    else if (s == "else")
    {
        while (inputCopy >> s && s != "then" && s != ";");
        if (s == "then")
        {
            if (inputCopy >> s && s == ";")
            {
                return IF_ELSE_THEN;
            }
        }
    }
    return INCORRECT;
}

inline void PassTill(std::stringstream & input, const std::string & cmp)
{
    std::string s;
    while (input >> s && s != cmp);
}

void If::DoCommand(std::stack<int> & fStack_,
                       std::stringstream & input, std::string & output)
{
    switch (CheckCondition(input))
    {
        case IF_THEN:
        {
            if (fStack_.empty())
            {
                throw std::invalid_argument("Stack Underflow");
            }
            if (fStack_.top())
            {
                fStack_.pop();

                std::string forReplace = input.str();
                long inputCurrentPos = input.tellg();
                auto it = forReplace.find("then", input.tellg());
                forReplace.replace(it, 4, "");
                it = forReplace.find(';', it + 1);
                forReplace.replace(it, 1, "");
                input.str(forReplace);
                input.seekg(inputCurrentPos + 1);
            }
            else
            {
                fStack_.pop();
                PassTill(input, ";");
            }
            break;
        }
        case IF_ELSE_THEN:
        {
            if (fStack_.empty())
            {
                throw std::invalid_argument("Stack Underflow");
            }
            if (fStack_.top())
            {
                fStack_.pop();

                std::string forReplace = input.str();
                long pos = input.tellg();
                auto it = forReplace.find("else", input.tellg());
                forReplace.replace(it, forReplace.find(';', it) + 1 - it, "");
                input.str(forReplace);
                input.seekg(pos + 1);
            }
            else
            {
                fStack_.pop();
                PassTill(input, "else");

                std::string forReplace = input.str();

                long inputCurrentPos = input.tellg();
                auto it = forReplace.find("then", input.tellg());
                forReplace.replace(it, 4, "");
                it = forReplace.find(';', it + 4);
                forReplace.replace(it, 1, "");
                input.str(forReplace);
                input.seekg(inputCurrentPos + 1);
            }
            break;
        }
        default:
        {
            throw std::invalid_argument("Incorrect Condition Structure");
        }
    }
}

//void Else::DoCommand(std::stack<int> &, std::stringstream & input, std::string &)
//{
//    PassTill(input, "then");
//}
//
//void Then::DoCommand(std::stack<int> &, std::stringstream &, std::string &) {}
