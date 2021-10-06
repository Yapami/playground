#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_map>

int sockMerchant(int n, std::vector<int> ar)
{
    std::unordered_map<int, int> m;
    for (auto i : ar)
    {
        ++m[i];
    }
    int r = 0;
    for (auto i : m)
    {
        r += i.second / 2;
    }
    return r;
}

TEST(SalesByMatch, sample)
{
    EXPECT_EQ(sockMerchant(9, {10, 20, 20, 10, 10, 30, 50, 10, 20}), 3);
    EXPECT_EQ(sockMerchant(9, {1, 1, 3, 1, 2, 1, 3, 3, 3, 3}), 4);
}