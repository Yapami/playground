#include <map>
#include <stddef.h>
#include <string>

#include <gtest/gtest.h>

size_t duplicateCount(const char *in)
{
    std::map<char, size_t> r;
    for (size_t i = 0; in[i]; ++i)
    {
        r[std::tolower(in[i])]++;
    }
    size_t d = 0;
    for (const auto &i : r)
    {
        d += i.second > 1;
    }
    return d;
}

TEST(CodeWars, counting_duplicates)
{
    EXPECT_EQ(duplicateCount(" "), 0);
    EXPECT_EQ(duplicateCount(""), 0);
    EXPECT_EQ(duplicateCount("aabbcde"), 2);
    EXPECT_EQ(duplicateCount("aabBcde"), 2);
    EXPECT_EQ(duplicateCount("Indivisibility"), 1);
    EXPECT_EQ(duplicateCount("Indivisibilities"), 2);
    EXPECT_EQ(duplicateCount("ABBA"), 2);
}