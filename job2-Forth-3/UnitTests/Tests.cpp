#include "gtest/gtest.h"

#include "../Forth.h"

#include "../ForthCommands/Base/Function__CheckStack.h"

class ForthTest : public testing::TestWithParam<std::pair<std::vector<std::string>, std::vector<std::string>>> {

    void SetUp() override {
        Forth_t = std::make_unique<Forth>();
    }

    void TearDown() override {

    }

protected:
    std::stringstream input;
    std::stringstream output;
    std::unique_ptr<Forth> Forth_t;
};

namespace {
    [[maybe_unused]]
    void ClearStack(std::stack<int> &stack) {
        while (!stack.empty()) {
            stack.pop();
        }
    }

    void ClearAndSetup(std::stringstream & ss, const std::string & str)
    {
        ss.clear();
        ss.str(str);
        ss.seekg(0);
    }


    const std::vector<std::string> TEST_ADD = {
            "1 3 + .",
            "-1 1 + .",
            "1 100 + .",
            "100 + 1",
            "+ .",
            "+ + + .",
    };

    const std::vector<std::string> TEST_ADD_RESULT = {
            "< 4  ok\n",
            "< 0  ok\n",
            "< 101  ok\n",
            "<  Stack underflow\n",
            "<  Stack underflow\n",
            "<  Stack underflow\n"
    };

    const std::vector<std::string> TEST_SUB = {
            "1 3 - .",
            "-1 1 - .",
            "100 1 - .",
            "100 - 1",
            "-  .",
            "- - - .",
    };

    const std::vector<std::string> TEST_SUB_RESULT = {
            "< -2  ok\n",
            "< -2  ok\n",
            "< 99  ok\n",
            "<  Stack underflow\n",
            "<  Stack underflow\n",
            "<  Stack underflow\n"
    };

    const std::vector<std::string> TEST_MUL = {
            "2 3 * .",
            "2 -3 * .",
            "-3 2 * . ",
            "-100 -1 * . ",
            "100 * -1",
            "* .",
            "* * *"
    };

    const std::vector<std::string> TEST_MUL_RESULT = {
            "< 6  ok\n",
            "< -6  ok\n",
            "< -6  ok\n",
            "< 100  ok\n",
            "<  Stack underflow\n",
            "<  Stack underflow\n",
            "<  Stack underflow\n",
    };


    const std::vector<std::string> TEST_IF_THEN_CORRECT = {
            "1 if then ;",
            "0 if then ;",
            "1 if 1 . then ; 4 .",
            "0 if 1 . then ; 4 .",
            "1 if 1 if 4 . then ; then ; 5 .",
            "1 if 0 if 4 . then ; then ; 5 .",
            "0 if 1 if 4 . then ; then ; 5 .",
            "0 if 0 if 4 . then ; then ; 5 .",
    };

    const std::vector<std::string> TEST_IF_THEN_CORRECT_RESULT = {
            "<  ok\n",
            "<  ok\n",
            "< 1 4  ok\n",
            "< 4  ok\n",
            "< 4 5  ok\n",
            "< 5  ok\n",
            "< 5  ok\n",
            "< 5  ok\n",
    };

    const std::vector<std::string> TEST_IF_ELSE_THEN_CORRECT = {
            "1 if else then ;",
            "0 if else then ;",
            "1 if 1 . else 2 . then ; 4 .",
            "0 if 1 . else 2 . then ; 4 .",
            "1 if 1 if 4 . then ; else 7 . then ; 5 .",
            "1 if 0 if 4 . then ; else 7 . then ; 5 .",
            "0 if 1 if 4 . then ; else 7 . then ; 5 .",
            "0 if 0 if 4 . else 7 . then ; then ; 5 .",
    };

    const std::vector<std::string> TEST_IF_ELSE_THEN_CORRECT_RESULT = {
            "<  ok\n",
            "<  ok\n",
            "< 1 4  ok\n",
            "< 2 4  ok\n",
            "< 4 5  ok\n",
            "< 5  ok\n",
            "< 7 5  ok\n",
            "< 5  ok\n",
    };

    const std::vector<std::string> TEST_PRINT_STRING = {
            ".\"",
            ".\" ",
            ".\" \"",
            ".\" a",
            ".\" a\"",
            ".\" 1     a23 f  ",
            ".\" 1     a23 f  \"",
    };

    const std::vector<std::string> TEST_PRINT_STRING_RESULT = {
            "<  .\" ?\n",
            "<  ok\n",
            "<  ok\n",
            "< a ok\n",
            "< a ok\n",
            "< 1     a23 f   ok\n",
            "< 1     a23 f   ok\n",
    };

    const std::vector<std::string> TEST_EXAM = {
            "20 0 do i 2 mod if i 1 + 0 do i 2 mod if i . else .\" no \" then ; loop ; then ; cr loop ;"
    };

    const std::vector<std::string> TEST_EXAM_RESULT = {
            "< \n"
            "no 1 \n"
            "\n"
            "no 1 no 3 \n"
            "\n"
            "no 1 no 3 no 5 \n"
            "\n"
            "no 1 no 3 no 5 no 7 \n"
            "\n"
            "no 1 no 3 no 5 no 7 no 9 \n"
            "\n"
            "no 1 no 3 no 5 no 7 no 9 no 11 \n"
            "\n"
            "no 1 no 3 no 5 no 7 no 9 no 11 no 13 \n"
            "\n"
            "no 1 no 3 no 5 no 7 no 9 no 11 no 13 no 15 \n"
            "\n"
            "no 1 no 3 no 5 no 7 no 9 no 11 no 13 no 15 no 17 \n"
            "\n"
            "no 1 no 3 no 5 no 7 no 9 no 11 no 13 no 15 no 17 no 19 \n"
            " ok\n"
    };

}  // namespace

TEST_P(ForthTest, CompareOutputs)
{
    for (size_t i = 0; i < GetParam().first.size(); i++)
    {
        ClearAndSetup(input, GetParam().first[i]);
        ClearAndSetup(output, "");
        Forth_t->ReadAndExecute(input, output);
        EXPECT_EQ(output.str(), GetParam().second[i]);
    }
}


INSTANTIATE_TEST_SUITE_P(ADD, ForthTest, ::testing::Values(std::make_pair(TEST_ADD, TEST_ADD_RESULT)));
INSTANTIATE_TEST_SUITE_P(SUB, ForthTest, ::testing::Values(std::make_pair(TEST_SUB, TEST_SUB_RESULT)));
INSTANTIATE_TEST_SUITE_P(MUL, ForthTest, ::testing::Values(std::make_pair(TEST_MUL, TEST_MUL_RESULT)));
INSTANTIATE_TEST_SUITE_P(IF_THEN_CORRECT, ForthTest, ::testing::Values(std::make_pair(TEST_IF_THEN_CORRECT, TEST_IF_THEN_CORRECT_RESULT)));
INSTANTIATE_TEST_SUITE_P(IF_ELSE_THEN_CORRECT, ForthTest, ::testing::Values(std::make_pair(TEST_IF_ELSE_THEN_CORRECT, TEST_IF_ELSE_THEN_CORRECT_RESULT)));
INSTANTIATE_TEST_SUITE_P(PRINT_STRING, ForthTest, ::testing::Values(std::make_pair(TEST_PRINT_STRING, TEST_PRINT_STRING_RESULT)));
INSTANTIATE_TEST_SUITE_P(EXAM, ForthTest, ::testing::Values(std::make_pair(TEST_EXAM, TEST_EXAM_RESULT)));


TEST(ForthTest, PushNumberCorrect)
{
    std::stringstream input;
    std::stringstream output;
    ClearAndSetup(input, "      1    2   300     -123    -456  -00 0 100    ");
    ClearAndSetup(output, "");

    std::stack<int> forCompare;
    forCompare.push(1);
    forCompare.push(2);
    forCompare.push(300);
    forCompare.push(-123);
    forCompare.push(-456);
    forCompare.push(0);
    forCompare.push(0);
    forCompare.push(100);

    Forth f;
    f.ReadAndExecute(input, output);
    std::stack<int> forthStack = f.getStack();
    while (!forCompare.empty())
    {
        EXPECT_EQ(forthStack.top(), forCompare.top());
        forthStack.pop();
        forCompare.pop();
    }
}

TEST(Number, Overflow)
{
    std::stringstream input;
    std::stringstream output;
    ClearAndSetup(input, "      1    20000000000000    ");
    ClearAndSetup(output, "");

    Forth f;

    f.ReadAndExecute(input, output);
    EXPECT_EQ(1, f.getStack().top());
    EXPECT_EQ(output.str(), "<  Got incorrect number (too big or too small)\n");
}

/*
//TES_FT(ForthTest, PushNumberCorrect)
//{
//    ClearAllAndSetInput("      1    2   300     -123    -456  -00 0 100    ");
//
//    std::stack<int> forCompare;
//    forCompare.push(1);
//    forCompare.push(2);
//    forCompare.push(300);
//    forCompare.push(-123);
//    forCompare.push(-456);
//    forCompare.push(0);
//    forCompare.push(0);
//    forCompare.push(100);
//
//    ForthInterpreter.ReadAndExecute(input, output);
//    std::stack<int> forthStack = ForthInterpreter.getStack();
//    while (!forCompare.empty())
//    {
//        EXPECT_EQ(forthStack.top(), forCompare.top());
//        forthStack.pop();
//        forCompare.pop();
//    }
//}
//
//TEST(Number, Overflow)
//{
//    ClearAllAndSetInput("      1    20000000000000    ");
//
//    ForthInterpreter.ReadAndExecute(input, output);
//    EXPECT_EQ(1, ForthInterpreter.getStack().top());
//    EXPECT_EQ(output.str(), "<  Got incorrect number (too big or too small)\n");
//}
//
//TEST(ArithmeticOperators, Add)
//{
//    for (size_t i = 0; i < 6; i++)
//    {
//        ClearAllAndSetInput(TEST_ADD[i]);
//        ForthInterpreter.ReadAndExecute(input, output);
//        EXPECT_EQ(output.str(), TEST_ADD_RESULT[i]);
//    }
////    ClearAllAndSetInput("3 4 +");
////    ForthInterpreter.ReadAndExecute(input, output);
////    EXPECT_EQ(7, ForthInterpreter.getStack().top());
////    EXPECT_EQ(1, ForthInterpreter.getStack().size());
////
////    ClearAllAndSetInput(" +  ");
////    ForthInterpreter.ReadAndExecute(input, output);
////    EXPECT_EQ(output.str(), "<  Stack underflow\n");
////    EXPECT_EQ(0, ForthInterpreter.getStack().size());
////
////    ClearAllAndSetInput("+");
////    ForthInterpreter.ReadAndExecute(input, output);
////    EXPECT_EQ(output.str(), "<  Stack underflow\n");
////    EXPECT_EQ(0, ForthInterpreter.getStack().size());
//}
//
//TEST(ArithmeticOperators, Sub)
//{
//    for (size_t i = 0; i < 6; i++)
//    {
//        ClearAllAndSetInput(TEST_MUL[i]);
//        ForthInterpreter.ReadAndExecute(input, output);
//        EXPECT_EQ(output.str(), TEST_MUL_RESULT[i]);
//    }
//}
//
//TEST(ArithmeticOperators, Mul)
//{
//    for (size_t i = 0; i < 6; i++)
//    {
//        ClearAllAndSetInput(TEST_SUB[i]);
//        ForthInterpreter.ReadAndExecute(input, output);
//        EXPECT_EQ(output.str(), TEST_SUB_RESULT[i]);
//    }
//}
//
//
//
//TEST(Conditional, IfThen)
//{
//    for (size_t i = 0; i < 8; i++)
//    {
//        ClearAllAndSetInput(TEST_IF_THEN_CORRECT[i]);
//        ForthInterpreter.ReadAndExecute(input, output);
//        EXPECT_EQ(output.str(), TEST_IF_THEN_CORRECT_RESULT[i]);
//    }
//}
//
//TEST(Conditional, IfElseThen)
//{
//    for (size_t i = 0; i < 8; i++)
//    {
//        ClearAllAndSetInput(TEST_IF_ELSE_THEN_CORRECT[i]);
//        ForthInterpreter.ReadAndExecute(input, output);
//        EXPECT_EQ(output.str(), TEST_IF_ELSE_THEN_CORRECT_RESULT[i]);
//    }
//}
//
//TEST(Conditional, PrintString)
//{
//    for (size_t i = 0; i < 7; i++)
//    {
//        ClearAllAndSetInput(TEST_PRINT_STRING[i]);
//        ForthInterpreter.ReadAndExecute(input, output);
//        EXPECT_EQ(output.str(), TEST_PRINT_STRING_RESULT[i]);
//    }
//}
//
//
//TEST(Exam, Exam)
//{
//    ClearAllAndSetInput("20 0 do i 2 mod if i 1 + 0 do i 2 mod if i . else .\" no \" then ; loop ; then ; cr loop ;");
//    ForthInterpreter.ReadAndExecute(input, output);
//    EXPECT_EQ(output.str(), "< \n"
//                            "no 1 \n"
//                            "\n"
//                            "no 1 no 3 \n"
//                            "\n"
//                            "no 1 no 3 no 5 \n"
//                            "\n"
//                            "no 1 no 3 no 5 no 7 \n"
//                            "\n"
//                            "no 1 no 3 no 5 no 7 no 9 \n"
//                            "\n"
//                            "no 1 no 3 no 5 no 7 no 9 no 11 \n"
//                            "\n"
//                            "no 1 no 3 no 5 no 7 no 9 no 11 no 13 \n"
//                            "\n"
//                            "no 1 no 3 no 5 no 7 no 9 no 11 no 13 no 15 \n"
//                            "\n"
//                            "no 1 no 3 no 5 no 7 no 9 no 11 no 13 no 15 no 17 \n"
//                            "\n"
//                            "no 1 no 3 no 5 no 7 no 9 no 11 no 13 no 15 no 17 no 19 \n"
//                            " ok\n");
//}
*/




int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}