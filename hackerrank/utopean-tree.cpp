#include <gmock/gmock.h>
#include <gtest/gtest.h>

int utopianTree(int n)
{
    int h = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 2)
        {
            h *= 2;
        }
        else
        {
            ++h;
        }
    }
    return h;
}

TEST(UtopeanTree, sample)
{
    EXPECT_EQ(utopianTree(3), 6);
    EXPECT_EQ(utopianTree(4), 7);
    EXPECT_EQ(utopianTree(5), 14);
}