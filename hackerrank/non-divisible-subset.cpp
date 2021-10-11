#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

int nonDivisibleSubset(int k, std::vector<int> s)
{
    std::vector<int> counts(k);
    for (int n : s)
    {
        ++counts[n % k];
    }
    int count = !!counts[0];
    for (size_t i = 1; i <= k / 2; ++i)
    {
        if (i != k - i)
        {
            count += std::max(counts[i], counts[k - i]);
        }
        else
        {
            ++count;
        }
    }
    return count;
}

TEST(NonDivisibleSubset, sample)
{
    EXPECT_EQ(nonDivisibleSubset(3, {1, 7, 2, 4}), 3);
}