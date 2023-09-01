#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

int flatlandSpaceStations(int n, std::vector<int> c)
{
    std::vector<int> res(n);
    std::fill(res.begin(), res.end(), 1000000);
    for (int p : c)
    {
        res[p] = 0;
    }
    int ci = 1000000;
    for (int i = 0; i < res.size(); ++i)
    {
        res[i] = std::min(ci, res[i]);
        ci = res[i] + 1;
    }
    ci = 1000000;
    for (int i = res.size() - 1; i >= 0; --i)
    {
        res[i] = std::min(ci, res[i]);
        ci = res[i] + 1;
    }
    int result = 0;
    for (int i : res)
    {
        if (i > result && i < 1000000)
        {
            result = i;
        }
    }
    return result;
}

TEST(FlatlandSpaceStations, sample)
{
    EXPECT_EQ(flatlandSpaceStations(5, {0, 4}), 2);
}