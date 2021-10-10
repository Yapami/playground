#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

std::string appendAndDelete(std::string s, std::string t, int k)
{
    int i = 0;
    for (; i < std::min(s.size(), t.size()); ++i)
    {
        if (s[i] != t[i])
        {
            break;
        }
    }
    int tl = s.size() + t.size();
    if (tl - 2 * i > k)
    {
        return "No";
    }
    else if ((tl - 2 * i) % 2 == k % 2)
    {
        return "Yes";
    }
    else if (tl - k < 0)
    {
        return "Yes";
    }
    return "No";
}

TEST(AppendAndDelete, sample)
{
    EXPECT_EQ(appendAndDelete("hackerhappy", "hackerrank", 9), "Yes");
    EXPECT_EQ(appendAndDelete("abc", "def", 6), "Yes");
    EXPECT_EQ(appendAndDelete("ashley", "ash", 2), "No");
}