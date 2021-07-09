#include <gtest/gtest.h>

#include <map>
#include <utility>
#include <vector>

int sum_intervals(std::vector<std::pair<int, int>> intervals)
{
    std::map<int, int> e;
    for (auto i : intervals)
    {
        ++e[i.first];
        --e[i.second];
    }
    int sum = 0;
    int cv = 0;
    int cs = 0;
    for (const auto &p : e)
    {
        if (cv == 0 && p.second > 0)
        {
            cs = p.first;
        }
        if (cv > 0 && cv + p.second <= 0)
        {
            sum += abs(p.first - cs);
        }
        cv += p.second;
    }
    return sum;
}

TEST(CodeWars, sum_intervals)
{
    std::vector<std::pair<int, int>> intervals = {{1, 5}};
    EXPECT_EQ(sum_intervals(intervals), 4);

    intervals = {{1, 5}, {6, 10}};
    EXPECT_EQ(sum_intervals(intervals), 8);

    intervals = {{1, 5}, {3, 10}};
    EXPECT_EQ(sum_intervals(intervals), 9);

    intervals = {{-1, 4}, {7, 10}, {3, 5}};
    EXPECT_EQ(sum_intervals(intervals), 9);
}