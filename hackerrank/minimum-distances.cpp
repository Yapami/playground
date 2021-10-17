#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

int minimumDistances(const std::vector<int> &a)
{
    // value, distance
    int b = std::numeric_limits<int>::max();
    std::unordered_map<int, int> m;
    for (int i = 0; i < a.size(); ++i)
    {
        if (auto it = m.find(a[i]); it != m.end())
        {
            b = std::min(i - m[a[i]], b);
            m[a[i]] = i;
        }
        else
        {
            m[a[i]] = i;
        }
    }
    return b == std::numeric_limits<int>::max() ? -1 : b;
}

TEST(MinimumDistances, sample)
{
    EXPECT_EQ(minimumDistances({7, 1, 3, 4, 1, 7}), 3);
}