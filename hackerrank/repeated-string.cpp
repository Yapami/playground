#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <unordered_set>

long repeatedString(const std::string &s, long n)
{
    long count = 0;
    std::unordered_set<long> a;
    for (long i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'a')
        {
            a.insert(i);
        }
    }
    long repeats = n / s.length();
    long remain = n % s.length();
    for (long p : a)
    {
        count += repeats + (remain && p < remain ? 1 : 0);
    }
    return count;
}

TEST(RepeatedString, sample)
{
    EXPECT_EQ(repeatedString("abcac", 10), 4);
    EXPECT_EQ(repeatedString("aba", 10), 7);
    EXPECT_EQ(repeatedString("a", 100000), 100000);
}