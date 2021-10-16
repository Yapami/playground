#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

int beautifulTriplets(int d, const std::vector<int> &arr)
{
    std::unordered_map<int, int> m;
    int cnt = 0;
    for (int a : arr)
    {
        m[a] += 1;
        cnt += m[a - d] * m[a - 2 * d];
    }
    return cnt;
}

TEST(BeautifulTriplets, sample)
{
    EXPECT_EQ(beautifulTriplets(3, {1, 2, 4, 5, 7, 8, 10}), 3);
}