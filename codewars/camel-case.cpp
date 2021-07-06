#include <gtest/gtest.h>

#include <sstream>
#include <string>

std::string camel_case(std::string text)
{
    std::string r;
    r.reserve(text.size());
    bool u = false;
    for (const auto c : text)
    {
        if (c == '_' || c == '-')
        {
            u = true;
            continue;
        }
        r.push_back(u ? std::toupper(c) : c);
        u = false;
    }
    return r;
}

TEST(CodeWars, camel_case)
{
    std::string s = "the_stealth_warrior";
    EXPECT_EQ(camel_case(s), "theStealthWarrior");
}