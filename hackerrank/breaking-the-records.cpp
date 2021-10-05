#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

std::vector<int> breakingRecords(const std::vector<int> &scores)
{
    std::vector<int> r(2);
    int cmin = scores[0];
    int cmax = scores[0];
    for (auto s : scores)
    {
        if (s < cmin)
        {
            ++r[1];
            cmin = s;
        }
        else if (s > cmax)
        {
            ++r[0];
            cmax = s;
        }
    }
    return r;
}

TEST(BreakingRecords, sample)
{
    EXPECT_THAT(breakingRecords({3, 4, 21, 36, 10, 28, 35, 5, 24, 42}),
                testing::ContainerEq(std::vector<int>{4, 0}));
}