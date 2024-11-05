#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

int divisibleSumPairs(int n, int k, std::vector<int> ar)
{
    int r = 0;
    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i < j; ++i)
        {
            r += (ar[i] + ar[j]) % k == 0;
        }
    }
    return r;
}

TEST(DivisibleSumPairs, sample)
{
    // EXPECT_EQ(divisibleSumPairs(6, 5, {1, 2, 3, 4, 5, 6}), 3);
    EXPECT_EQ(divisibleSumPairs(6, 3, {1, 3, 2, 6, 1, 2}), 5);
}