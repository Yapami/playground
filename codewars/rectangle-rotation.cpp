#include <gtest/gtest.h>

#include <cmath>

void rotate(float &x, float &y, float a)
{
    float rx = x * std::cos(a) - y * std::sin(a);
    float ry = x * std::sin(a) + y * std::cos(a);
    x = rx;
    y = ry;
}

bool inside(float px, float py, float x1, float y1, float x2, float y2)
{
    return ((x2 - x1) * (py - y1) - (px - x1) * (y2 - y1)) <= 0.0f;
}

long long rectangle_rotation(int a, int b)
{
    float sx = a / 2.0f;
    float sy = b / 2.0f;
    float d = std::sqrt(sx * sx + sy * sy) + 1.0f;
    d = std::ceil(d);

    float x[4] = {sx, sx, -sx, -sx};
    float y[4] = {sy, -sy, -sy, sy};
    for (size_t i = 0; i < 4; ++i)
    {
        rotate(x[i], y[i], M_PI_4);
    }
    long long result = 0;
    for (float ty = -d; ty <= d; ++ty)
    {
        for (float tx = -d; tx <= d; ++tx)
        {
            if (inside(tx, ty, x[0], y[0], x[1], y[1]) && inside(tx, ty, x[1], y[1], x[2], y[2]) &&
                inside(tx, ty, x[2], y[2], x[3], y[3]) && inside(tx, ty, x[3], y[3], x[0], y[0]))
            {
                ++result;
            }
        }
    }
    return result;
}

TEST(RectangleRotation, sample)
{
    EXPECT_EQ(rectangle_rotation(6, 4), 23);
    EXPECT_EQ(rectangle_rotation(30, 2), 65);
    EXPECT_EQ(rectangle_rotation(8, 6), 49);
    EXPECT_EQ(rectangle_rotation(16, 20), 333);
}
