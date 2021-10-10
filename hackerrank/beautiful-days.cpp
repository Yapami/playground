#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

int reverse(int n)
{
    int r = 0;
    for (; n; n /= 10)
    {
        r *= 10;
        r += n % 10;
    }
    return r;
}

int beautifulDays(int i, int j, int k)
{
    int r = 0;
    for (int n = i; n <= j; ++n)
    {
        if (std::abs(n - reverse(n)) % k == 0)
        {
            ++r;
        }
    }
    return r;
}

TEST(BeautifulDayls, reverse)
{
    EXPECT_EQ(reverse(20), 2);
    EXPECT_EQ(reverse(23), 32);
    EXPECT_EQ(reverse(7), 7);
    EXPECT_EQ(reverse(144), 441);
    EXPECT_EQ(reverse(150), 51);
}

TEST(BeautifulDays, sample)
{
    EXPECT_EQ(beautifulDays(20, 23, 6), 2);
    EXPECT_EQ(beautifulDays(13, 45, 3), 33);
}