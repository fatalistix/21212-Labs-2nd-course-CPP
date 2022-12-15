#include "gtest/gtest.h"

#include "../Forth.h"

#include "../ForthCommands/Base/Function__CheckStack.h"

std::stringstream input;
std::stringstream output;

void inline ClearStack(std::stack<int> & stack)
{
    while (!stack.empty())
    {
        stack.pop();
    }
}

void inline ClearAllAndSetInput(const std::string & s)
{
    input .clear();
    output.clear();
    input .str(s);
    output.str("");
    input .seekg(0);
    output.seekg(0);
    ClearStack(ForthInterpreter::Instance().getStack());
}

TEST(Number, PushNumberCorrect)
{
    ClearAllAndSetInput("      1    2   300     -123    -456  -00 0 100    ");

    std::stack<int> forCompare;
    forCompare.push(1);
    forCompare.push(2);
    forCompare.push(300);
    forCompare.push(-123);
    forCompare.push(-456);
    forCompare.push(0);
    forCompare.push(0);
    forCompare.push(100);

    ForthInterpreter::Instance().ReadAndExecute(input, output);
    std::stack<int> forthStack = ForthInterpreter::Instance().getStack();
    while (!forCompare.empty())
    {
        EXPECT_EQ(forthStack.top(), forCompare.top());
        forthStack.pop();
        forCompare.pop();
    }
}

TEST(Number, Overflow)
{
    ClearAllAndSetInput("      1    20000000000000    ");

    ForthInterpreter::Instance().ReadAndExecute(input, output);
    EXPECT_EQ(1, ForthInterpreter::Instance().getStack().top());
    EXPECT_EQ(output.str(), "<  Got incorrect number (too big or too small)\n");
}

TEST(ArithmeticOperators, Add)
{
    ClearAllAndSetInput("3 4 +");
    ForthInterpreter::Instance().ReadAndExecute(input, output);
    EXPECT_EQ(7, ForthInterpreter::Instance().getStack().top());
    EXPECT_EQ(1, ForthInterpreter::Instance().getStack().size());

    ClearAllAndSetInput(" +  ");
    ForthInterpreter::Instance().ReadAndExecute(input, output);
    EXPECT_EQ(output.str(), "<  Stack underflow\n");
    EXPECT_EQ(0, ForthInterpreter::Instance().getStack().size());
    
    ClearAllAndSetInput("+");
    ForthInterpreter::Instance().ReadAndExecute(input, output);
    EXPECT_EQ(output.str(), "<  Stack underflow\n");
    EXPECT_EQ(0, ForthInterpreter::Instance().getStack().size());
}





int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}