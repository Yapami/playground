#include <gtest/gtest.h>

#include <map>
#include <stack>
#include <string>

std::string to_postfix(std::string infix)
{
    static std::map<char, int> priorities = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2},
                                             {'^', 3}, {'(', 0}, {')', 4}};

    std::stack<char> op;
    std::string r;
    for (auto c : infix)
    {
        if (c == '(')
        {
            op.push(c);
            continue;
        }
        if (c == ')')
        {
            while (!op.empty() && op.top() != '(')
            {
                r.push_back(op.top());
                op.pop();
            }
            if (!op.empty())
            {
                op.pop();
            }
        }
        if (std::isdigit(c))
        {
            r.push_back(c);
            continue;
        }
        while (!op.empty() && priorities[c] <= priorities[(op.top())])
        {
            if (op.top() != '(' && op.top() != ')')
            {
                r.push_back(op.top());
            }
            op.pop();
        }
        op.push(c);
    }
    while (!op.empty())
    {
        if (op.top() != ')')
        {
            r.push_back(op.top());
        }
        op.pop();
    }

    return r;
}

TEST(CodeWars, infix_to_postfix)
{
    EXPECT_EQ(to_postfix("2+7*5"), "275*+");
    EXPECT_EQ(to_postfix("3*3/(7+1)"), "33*71+/");
    EXPECT_EQ(to_postfix("5+(6-2)*9+3^(7-1)"), "562-9*+371-^+");
    EXPECT_EQ(to_postfix("(5-4-1)+9/5/2-7/1/7"), "54-1-95/2/+71/7/-");
}
