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

int jumpingOnClouds(const std::vector<int> &c)
{
    int j = 0;
    auto s = c.size() - 2;
    size_t i;
    for (i = 0; i < s; ++j)
    {
        if (c[i + 2] == 0)
        {
            i += 2;
        }
        else
        {
            ++i;
        }
    }
    if (i < c.size() - 1)
    {
        ++j;
    }
    return j;
}

TEST(JumpingOnTheClouds, sample)
{
    EXPECT_EQ(jumpingOnClouds({0, 0, 1, 0}, 2), 96);
    EXPECT_EQ(jumpingOnClouds({0, 0, 1, 0, 0, 1, 1, 0}, 2), 92);
    EXPECT_EQ(jumpingOnClouds({0, 1, 0, 0, 0, 1, 0}), 3);
    EXPECT_EQ(jumpingOnClouds({0, 0, 0, 0, 1, 0}), 3);
    EXPECT_EQ(jumpingOnClouds({0, 0, 0, 1, 0, 0}), 3);
}