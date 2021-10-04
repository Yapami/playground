#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <numeric>
#include <string>

std::string kangaroo(int x1, int v1, int x2, int v2)
{
    if ((x1 >= x2 && v1 >= v2) || (x2 >= x1 && v2 >= v1))
    {
        return "NO";
    }
    return (x2 - x1) % (v1 - v2) ? "NO" : "YES";
}

TEST(NumberLineJumps, sample)
{
    EXPECT_EQ(kangaroo(0, 3, 4, 2), "YES");
    EXPECT_EQ(kangaroo(0, 2, 5, 3), "NO");
}