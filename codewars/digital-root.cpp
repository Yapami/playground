#include <gtest/gtest.h>

int digital_root(int n)
{
    int d = 0;
    while (n)
    {
        d += n % 10;
        n /= 10;
    }
    return d >= 10 ? digital_root(d) : d;
}

TEST(CodeWars, digital_root)
{
    EXPECT_EQ(digital_root(16), 7);
    EXPECT_EQ(digital_root(195), 6);
    EXPECT_EQ(digital_root(992), 2);
    EXPECT_EQ(digital_root(167346), 9);
    EXPECT_EQ(digital_root(0), 0);
}
