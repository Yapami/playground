#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <set>
#include <vector>

std::vector<int> climbingLeaderboard(std::vector<int> ranked, std::vector<int> player)
{
    std::set<int> s;
    for (int r : ranked)
    {
        s.insert(r);
    }
    std::vector<int> o;
    for (int p : player)
    {
        auto it = s.upper_bound(p);
        int f = std::distance(s.begin(), it);
        o.push_back(s.size() - f + 1);
        s.insert(p);
    }
    return o;
}

TEST(ClimbingTheLeaderboard, sample)
{
    EXPECT_THAT(climbingLeaderboard({100, 90, 90, 80}, {70, 80, 105}),
                testing::ContainerEq(std::vector<int>{4, 3, 1}));
    EXPECT_THAT(climbingLeaderboard({100, 100, 50, 40, 40, 20, 10}, {5, 25, 50, 120}),
                testing::ContainerEq(std::vector<int>{6, 4, 2, 1}));
}