#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

int surfaceArea(const std::vector<std::vector<int>> &a)
{
    int row = a.size();
    int col = a.front().size();
    int total = (row * col) * 2;
    // top and bottom

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int value = a[i][j];
            int max = value * 4;
            // front, back, left, right
            if (i - 1 >= 0)
            {
                max -= std::min(value, a[i - 1][j]);
            }
            if (j - 1 >= 0)
            {
                max -= std::min(value, a[i][j - 1]);
            }
            if (i + 1 <= row - 1)
            {
                max -= std::min(value, a[i + 1][j]);
            }
            if (j + 1 <= col - 1)
            {
                max -= std::min(value, a[i][j + 1]);
            }
            total += max;
        }
    }
    return total;
}

TEST(SurfaceArea, sample)
{
    std::vector<std::vector<int>> A = {{1, 3, 4}, {2, 2, 3}, {1, 2, 4}};

    EXPECT_EQ(surfaceArea(A), 60);
}