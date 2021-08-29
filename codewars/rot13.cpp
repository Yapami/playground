#include <gtest/gtest.h>

#include <string>

std::string rot13(std::string msg)
{
    std::string r = msg;
    for (auto &c : r)
    {
        if (!std::isalpha(c))
        {
            continue;
        }
        auto base = std::isupper(c) ? 'A' : 'a';
        c = (((c - base) + 13) % 26) + base;
    }
    return r;
}

TEST(Rot13, sample)
{
    EXPECT_EQ(rot13("test"), "grfg");
    EXPECT_EQ(rot13("Test"), "Grfg");
    EXPECT_EQ(rot13("AbCd"), "NoPq");
}