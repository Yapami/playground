#include <gmock/gmock.h>
#include <gtest/gtest.h>

int findDigits(int n)
{
    int c = 0;
    for (int i = n; i; i /= 10)
    {
        int r = i % 10;
        c += r && !(n % r);
    }
    return c;
}

TEST(FindDigits, sample)
{
    EXPECT_EQ(findDigits(124), 3);
    EXPECT_EQ(findDigits(111), 3);
    EXPECT_EQ(findDigits(10), 1);
    EXPECT_EQ(findDigits(12), 2);
    EXPECT_EQ(findDigits(1012), 3);
}