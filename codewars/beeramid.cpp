#include <gtest/gtest.h>

#include <cmath>

int beeramid(int bonus, double price)
{
    int result = 0;
    int count = bonus / price;
    for (int h = 1; count > 0; ++h)
    {
        if (count -= static_cast<int>(std::pow(h, 2.0f)); count >= 0)
        {
            ++result;
        }
    }
    return result;
}

TEST(CodeWars, beeramid)
{
    EXPECT_EQ(beeramid(21, 1.5), 3);
    EXPECT_EQ(beeramid(454, 5), 5);
    EXPECT_EQ(beeramid(455, 5), 6);
}