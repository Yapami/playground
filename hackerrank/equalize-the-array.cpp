#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <numeric>
#include <vector>

int equalizeArray(const std::vector<int> &arr)
{
    std::vector<int> c(100);
    for (int i : arr)
    {
        ++c[i - 1];
    }
    int m = *std::max_element(c.begin(), c.end());
    int t = std::accumulate(c.begin(), c.end(), 0);
    return t - m;
}

TEST(EqualizeTheArray, sample)
{
    EXPECT_EQ(equalizeArray({1, 2, 2, 3}), 2);
    EXPECT_EQ(equalizeArray({3, 3, 2, 1, 3}), 2);
}