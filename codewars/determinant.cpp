#include <gtest/gtest.h>

#include <cmath>
#include <vector>

using M = std::vector<std::vector<long long>>;

void getCofactor(const M m, M &t, size_t p, size_t q, size_t n)
{
    size_t i = 0, j = 0;

    for (size_t row = 0; row < n; row++)
    {
        for (size_t col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                t[i][j++] = m[row][col];

                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

long long determinant(M m)
{
    long long D = 0;

    if (m.size() == 1)
        return m[0][0];

    const size_t n = m.size();

    M temp(n - 1, std::vector<long long>(n - 1));

    long long sign = 1;

    for (size_t f = 0; f < m.size(); f++)
    {
        getCofactor(m, temp, 0, f, n);
        D += sign * m[0][f] * determinant(temp);
        sign = -sign;
    }

    return D;
}

TEST(CodeWars, determinant)
{
    EXPECT_EQ(determinant(std::vector<std::vector<long long>>{std::vector<long long>{2, 5, 3},
                                                              std::vector<long long>{1, -2, -1},
                                                              std::vector<long long>{1, 3, 4}}),
              -20);
}
