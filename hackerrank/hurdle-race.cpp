#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

int hurdleRace(int k, std::vector<int> height)
{
    int m = *std::max_element(height.begin(), height.end());
    return std::max(m - k, 0);
}

TEST(HurdleRace, sample)
{
    EXPECT_EQ(hurdleRace(4, {1, 6, 3, 5, 2}), 2);
    EXPECT_EQ(hurdleRace(7, {2, 5, 4, 5, 2}), 0);
}