#include "string_reverse.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <string>

std::string reversed(const char *s)
{
    std::string r(s);
    std::reverse(r.begin(), r.end());

    if (std::find(r.begin(), r.end(), ' ') == r.end())
    {
        return r;
    }
    const auto s_e = r.end();
    auto w_s = r.begin();
    for (auto w_e = w_s; w_s != s_e; w_s = w_e)
    {
        w_e = std::find(w_e, s_e, ' ');
        std::reverse(w_s, w_e);
        if (w_e != s_e)
        {
            ++w_e;
        }
    }
    return r;
}

TEST(string_reverse, simple_case)
{
    char s[] = "abcdef";
    auto r = reversed(s);
    reverse_string(s);
    EXPECT_EQ(r, s);
}

TEST(string_reverse, three_words)
{
    char s[] = "abcdef ghij klmno";
    auto r = reversed(s);
    reverse_string(s);
    EXPECT_EQ(r, s);
}