#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>
#include <string>

std::string happyLadybugs(std::string b)
{
    if (std::all_of(b.begin(), b.end(), [](char c) { return c == '_'; }))
    {
        return "YES";
    }
    if (b.find('_') != std::string::npos)
    {
        std::sort(b.begin(), b.end());
    }
    for (size_t i = 0; i < b.size() && b[i] != '_';)
    {
        size_t j = i + 1;
        for (; b[i] == b[j] && j < b.size(); ++j)
            ;
        if (j == i + 1)
        {
            return "NO";
        }
        i = j;
    }

    return "YES";
}

TEST(LadyBugs, sample)
{
    EXPECT_EQ(happyLadybugs("AABBC"), "NO");
    EXPECT_EQ(happyLadybugs("AABBC_C"), "YES");
    EXPECT_EQ(happyLadybugs("_"), "YES");
    EXPECT_EQ(happyLadybugs("DD__FQ_QQF"), "YES");
    EXPECT_EQ(happyLadybugs("AABCBC"), "NO");
}