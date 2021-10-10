#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

int jumpingOnClouds(std::vector<int> c, int k)
{
    int e = 100;
    int p = 0;
    do
    {
        p = (p + k) % c.size();
        e -= 1 + 2 * c[p];
    } while (p);
    return e;
}

TEST(JumpingOnTheClouds, sample)
{
    EXPECT_EQ(jumpingOnClouds({0, 0, 1, 0}, 2), 96);
    EXPECT_EQ(jumpingOnClouds({0, 0, 1, 0, 0, 1, 1, 0}, 2), 92);
}