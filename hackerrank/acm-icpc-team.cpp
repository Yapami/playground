#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

std::vector<int> acmTeam(const std::vector<std::string> &topic)
{
    const int n = topic.size();
    const int m = topic.front().length();
    std::vector<int> result;
    int max_known = 0;
    int team_count = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int known = 0;
            const auto &ti = topic[i];
            const auto &tj = topic[j];
            for (int k = 0; k < m; ++k)
            {
                if (ti[k] == '1' || tj[k] == '1')
                {
                    ++known;
                }
                if (known > max_known)
                {
                    max_known = known;
                    team_count = 0;
                }
                if (known == max_known)
                {
                    ++team_count;
                }
            }
        }
    }
    return {max_known, team_count};
}

TEST(AcmIcpcTeam, sample)
{
    EXPECT_THAT(acmTeam({"10101", "11100", "11010", "00101"}),
                testing::ContainerEq(std::vector<int>{5, 2}));
}