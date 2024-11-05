#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

int getMoneySpent(std::vector<int> keyboards, std::vector<int> drives, int b)
{
    int m = -1;
    for (auto k : keyboards)
    {
        for (auto d : drives)
        {
            auto c = k + d;
            if (c <= b && c > m)
            {
                m = c;
            }
        }
    }
    return m;
}

TEST(ElectronicsShop, sample)
{
    EXPECT_EQ(getMoneySpent({40, 50, 60}, {5, 8, 12}, 60), 58);
}