#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_set>
#include <vector>

bool check_vals(const std::vector<int> &a, int v, bool f)
{
    return std::all_of(a.begin(), a.end(), [v, f](int x) { return f ? x % v == 0 : v % x == 0; });
}

int getTotalX(std::vector<int> a, std::vector<int> b)
{
    int r = 0;
    int from = *std::max_element(a.begin(), a.end());
    int to = *std::min_element(b.begin(), b.end());
    for (int i = from; i <= to; ++i)
    {
        if (check_vals(a, i, false) && check_vals(b, i, true))
        {
            ++r;
        }
    }
    return r;
}

TEST(BetweenTwoSets, sample)
{
    EXPECT_EQ(getTotalX({2, 6}, {24, 36}), 2);
    EXPECT_EQ(getTotalX({2, 4}, {16, 32, 96}), 3);
    EXPECT_EQ(getTotalX({3, 4}, {24, 48}), 2);
}