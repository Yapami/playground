#include <gmock/gmock.h>
#include <gtest/gtest.h>

int squares(int a, int b)
{
    int r = std::sqrt(a - 1) + 1;
    int t = 0;
    for (int s = std::pow(r, 2); s >= a && s <= b; ++r, s = std::pow(r, 2))
    {
        ++t;
    }
    return t;
}

TEST(SherlockAndSquares, sample)
{
    EXPECT_EQ(squares(24, 49), 3);
    EXPECT_EQ(squares(3, 9), 2);
    EXPECT_EQ(squares(17, 24), 0);
}