#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <numeric>
#include <string>
#include <vector>

std::string organizingContainers(const std::vector<std::vector<int>> &container)
{
    std::vector<long long> s_r(container.size());
    std::vector<long long> s_c(container.size());
    for (size_t j = 0; j < container.size(); ++j)
    {
        for (size_t i = 0; i < container.front().size(); ++i)
        {
            s_r[i] += container[j][i];
            s_c[j] += container[j][i];
        }
    }
    std::sort(s_r.begin(), s_r.end());
    std::sort(s_c.begin(), s_c.end());
    return s_r == s_c ? "Possible" : "Impossible";
}

TEST(OrganizingContainers, sample)
{
    EXPECT_EQ(organizingContainers({{1, 4}, {2, 3}}), "Impossible");
    EXPECT_EQ(organizingContainers({{1, 3, 1}, {2, 1, 2}, {3, 3, 3}}), "Impossible");
    EXPECT_EQ(organizingContainers({{0, 2, 1}, {1, 1, 1}, {2, 0, 0}}), "Possible");
}