#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

using M = std::vector<std::vector<int>>;

int queensAttack(int n, int r_q, int c_q, const M &obstacles)
{
    M d(3, std::vector<int>(3));
    d[0][0] = std::min(r_q - 1, c_q - 1);
    d[0][1] = r_q - 1;
    d[0][2] = std::min(r_q - 1, n - c_q);

    d[1][0] = c_q - 1;
    d[1][2] = n - c_q;

    d[2][0] = std::min(n - r_q, c_q - 1);
    d[2][1] = n - r_q;
    d[2][2] = std::min(n - r_q, n - c_q);
    for (const auto &o : obstacles)
    {
        int di = o[1] - c_q;
        int dj = o[0] - r_q;
        if (!di)
        {
            if (dj > 0)
            {
                d[2][1] = std::min(d[2][1], dj - 1);
            }
            else
            {
                d[0][1] = std::min(d[0][1], -dj - 1);
            }
        }
        else if (!dj)
        {
            if (di > 0)
            {
                d[1][2] = std::min(d[1][2], di - 1);
            }
            else
            {
                d[1][0] = std::min(d[1][0], -di - 1);
            }
        }
        else if (std::abs(di) == std::abs(dj))
        {
            if (di < 0)
            {
                if (dj < 0)
                {
                    d[0][0] = std::min(d[0][0], -dj - 1);
                }
                else
                {
                    d[2][0] = std::min(d[2][0], dj - 1);
                }
            }
            else
            {
                if (dj < 0)
                {
                    d[0][2] = std::min(d[0][2], -dj - 1);
                }
                else
                {
                    d[2][2] = std::min(d[2][2], dj - 1);
                }
            }
        }
    }
    return d[0][0] + d[0][1] + d[0][2] + d[1][0] + d[1][2] + d[2][0] + d[2][1] + d[2][2];
}

TEST(queensAttack, sample)
{
    EXPECT_EQ(queensAttack(8, 4, 4, {}), 5 * 3 + 3 * 4);
    EXPECT_EQ(queensAttack(8, 4, 4, {{2, 6}}), 25);
    EXPECT_EQ(queensAttack(8, 4, 4, {{3, 5}}), 24);
    EXPECT_EQ(queensAttack(4, 4, 4, {}), 9);
    EXPECT_EQ(queensAttack(5, 4, 3, {{5, 5}, {4, 2}, {2, 3}}), 10);
    EXPECT_EQ(queensAttack(5, 4, 3, {{5, 2}, {4, 2}, {2, 3}}), 9);
    EXPECT_EQ(queensAttack(5, 4, 3, {{5, 3}, {4, 2}, {2, 3}}), 9);
    EXPECT_EQ(queensAttack(5, 4, 3, {{5, 4}, {4, 2}, {2, 3}}), 9);
    EXPECT_EQ(queensAttack(5, 4, 3, {{4, 4}, {4, 2}, {2, 3}}), 8);
    EXPECT_EQ(queensAttack(5, 4, 3, {{3, 2}, {4, 2}, {2, 3}}), 8);
    EXPECT_EQ(queensAttack(5, 4, 3, {{3, 3}, {4, 2}, {2, 3}}), 9);
    EXPECT_EQ(queensAttack(5, 4, 3, {{3, 4}, {4, 2}, {2, 3}}), 8);
}