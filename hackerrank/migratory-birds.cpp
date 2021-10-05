#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <unordered_map>

int migratoryBirds(std::vector<int> arr)
{
    std::unordered_map<int, size_t> r;
    for (auto i : arr)
    {
        ++r[i];
    }
    std::pair<int, size_t> best{std::numeric_limits<int>::max(), 0};
    for (auto it : r)
    {
        if (it.second > best.second || (it.first < best.first && it.second == best.second))
        {
            best = it;
        }
    }
    return best.first;
}

TEST(MigratoryBirds, sample)
{
    EXPECT_EQ(migratoryBirds({1, 1, 2, 23}), 1);
    EXPECT_EQ(migratoryBirds({1, 4, 4, 4, 5, 3}), 4);
}