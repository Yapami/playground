#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <unordered_set>
#include <vector>

int pickingNumbers(const std::vector<int> &a)
{
    std::vector<int> s(100, 0);

    std::for_each(a.begin(), a.end(), [&s](int n) { ++s[n]; });
    int m = 0;
    for (size_t i = 1; i < 100; ++i)
    {
        m = std::max(s[i - 1] + s[i], m);
    }
    return m;
}

TEST(PickingNumbers, sample)
{
    EXPECT_EQ(pickingNumbers({4, 6, 5, 3, 3, 1}), 3);
    EXPECT_EQ(pickingNumbers({1, 2, 2, 3, 1, 2}), 5);
    EXPECT_EQ(pickingNumbers({4,  97, 5,  97, 97, 4,  97, 4,  97, 97, 97, 97, 4,  4,  5,  5,  97,
                              5,  97, 99, 4,  97, 5,  97, 97, 97, 5,  5,  97, 4,  5,  97, 97, 5,
                              97, 4,  97, 5,  4,  4,  97, 5,  5,  5,  4,  97, 97, 4,  97, 5,  4,
                              4,  97, 97, 97, 5,  5,  97, 4,  97, 97, 5,  4,  97, 97, 4,  97, 97,
                              97, 5,  4,  4,  97, 4,  4,  97, 5,  97, 97, 97, 97, 4,  97, 5,  97,
                              5,  4,  97, 4,  5,  97, 97, 5,  97, 5,  97, 5,  97, 97, 97}),
              50);
}