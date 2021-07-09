#include <gtest/gtest.h>

#include <string>

std::string sum_strings(const std::string &a, const std::string &b)
{
    auto ai = a.rbegin();
    auto bi = b.rbegin();
    std::string r;
    char n = 0;
    for (; ai != a.rend() && bi != b.rend(); ++ai, ++bi)
    {
        n += (*ai - '0') + (*bi - '0');
        r.push_back(n % 10 + '0');
        n /= 10;
    }
    for (; ai != a.rend(); ++ai)
    {
        n += *ai - '0';
        r.push_back(n % 10 + '0');
        n /= 10;
    }
    for (; bi != b.rend(); ++bi)
    {
        n += *bi - '0';
        r.push_back(n % 10 + '0');
        n /= 10;
    }
    if (n)
    {
        r.push_back(n + '0');
    }
    std::reverse(r.begin(), r.end());
    return r;
}

TEST(CodeWars, sum_strings)
{
    EXPECT_EQ(sum_strings("99", "2"), "101");
}