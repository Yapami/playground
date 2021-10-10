#include <gmock/gmock.h>
#include <gtest/gtest.h>

int viralAdvertising(int n)
{
    int t = 0;
    int l = 5;
    for (int i = 1; i <= n; ++i)
    {
        l = (l / 2);
        t += l;
        l *= 3;
    }
    return t;
}

TEST(ViralAdvertising, sample)
{
    EXPECT_EQ(viralAdvertising(3), 9);
    EXPECT_EQ(viralAdvertising(4), 15);
    EXPECT_EQ(viralAdvertising(5), 24);
}