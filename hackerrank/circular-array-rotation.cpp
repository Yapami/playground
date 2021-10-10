#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

std::vector<int> circularArrayRotation(const std::vector<int> &a, int k,
                                       const std::vector<int> queries)
{
    std::vector<int> r;
    const int l = a.size();
    for (int n : queries)
    {
        int i = a[(l - (k % l) + n) % l];
        r.push_back(i);
    }
    return r;
}

TEST(CircularArrayRotation, sample)
{
    EXPECT_THAT(circularArrayRotation({3, 4, 5}, 2, {1, 2}),
                testing::ContainerEq(std::vector<int>({5, 3})));
    EXPECT_THAT(circularArrayRotation({1, 2, 3}, 2, {0, 1, 2}),
                testing::ContainerEq(std::vector<int>({2, 3, 1})));
}