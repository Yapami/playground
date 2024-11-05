#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <numeric>
#include <vector>

int birthday(std::vector<int> s, int d, int m)
{
    int sum = std::accumulate(s.begin(), s.begin() + m, 0);
    int r = sum == d;
    for (size_t i = 0; i < s.size() - m; ++i)
    {
        sum -= s[i];
        sum += s[i + m];
        r += sum == d;
    }
    return r;
}

TEST(SubarrayDivision, sample)
{
    EXPECT_EQ(birthday({1, 2, 1, 3, 2}, 3, 2), 2);
    EXPECT_EQ(birthday({1, 1, 1, 1, 1, 1}, 3, 2), 0);
    EXPECT_EQ(birthday({1, 2, 3, 4, 5, 6}, 11, 2), 1);
}