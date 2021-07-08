#include <gtest/gtest.h>

#include <cmath>
#include <string>

int mod(int a, const std::string &b)
{
    int mod = 0;
    for (auto c : b)
    {
        mod = (mod * 10 + c - '0') % a;
    }
    return mod;
}

int last_digit(const std::string &str1, const std::string &str2)
{
    if (str2.front() == '0')
    {
        return 1;
    }
    if (str1.back() == '0')
    {
        return 0;
    }
    int exp = mod(4, str2);
    exp = exp ? exp : 4;
    return static_cast<int>(std::pow(str1.back() - '0', exp)) % 10;
}

TEST(CodeWars, last_digit)
{
    EXPECT_EQ(last_digit("4", "1"), 4);
    EXPECT_EQ(last_digit("4", "2"), 6);
    EXPECT_EQ(last_digit("9", "7"), 9);
    EXPECT_EQ(last_digit("10", "10000000000"), 0);
    EXPECT_EQ(last_digit("1606938044258990275541962092341162602522202993782792835301376",
                         "2037035976334486086268445688409378161051468393665936250636140449354381299"
                         "763336706183397376"),
              6);
}