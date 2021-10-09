#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

using M = std::vector<std::vector<int>>;

std::vector<M> variants = {
    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},

    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},

    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},

    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},

    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},

    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},

    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},

    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
};

int formingMagicSquare(const M &s)
{
    int m = 99;
    for (const auto v : variants)
    {
        int cm = 0;
        for (size_t j = 0; j < 3; ++j)
        {
            for (size_t i = 0; i < 3; ++i)
            {
                cm += std::abs(v[j][i] - s[j][i]);
            }
        }
        m = std::min(cm, m);
    }

    return m;
}

TEST(MagicSquare, sample)
{
    for (const auto s : variants)
    {
        EXPECT_EQ(formingMagicSquare(s), 0);
    }
    EXPECT_EQ(formingMagicSquare({{4, 8, 2}, {4, 5, 7}, {6, 1, 6}}), 4);
}