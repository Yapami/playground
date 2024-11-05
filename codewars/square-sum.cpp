#include <gtest/gtest.h>

#include <numeric>
#include <vector>

int square_sum(const std::vector<int> &numbers)
{
    return std::accumulate(numbers.begin(), numbers.end(), 0,
                           [](int a, int b) { return a + (b * b); });
}

TEST(CodeWars, square_sum)
{
    EXPECT_EQ(square_sum({1, 2}), 5);
    EXPECT_EQ(square_sum({0, 3, 4, 5}), 50);
}
