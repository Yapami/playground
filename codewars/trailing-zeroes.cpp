#include <gtest/gtest.h>

#include <regex>
#include <string>
#include <vector>

long zeros(long n)
{
    long count = 0;
    for (long i = 5; n / i >= 1; i *= 5)
    {
        count += n / i;
    }
    return count;
}

TEST(CodeWars, count_smiley)
{
    EXPECT_EQ(zeros(0), 0);
    EXPECT_EQ(zeros(6), 1);
    EXPECT_EQ(zeros(30), 7);
    EXPECT_EQ(zeros(100), 24);
    EXPECT_EQ(zeros(1000), 249);
    EXPECT_EQ(zeros(100000), 24999);
    EXPECT_EQ(zeros(1000000000), 249999998);
}