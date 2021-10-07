#include <gmock/gmock.h>
#include <gtest/gtest.h>

int pageCount(int n, int p)
{
    return std::min(p / 2, n / 2 - p / 2);
}

TEST(DrawingPage, sample)
{
    EXPECT_EQ(pageCount(6, 2), 1);
    EXPECT_EQ(pageCount(5, 4), 0);
    EXPECT_EQ(pageCount(6, 4), 1);
    EXPECT_EQ(pageCount(6, 5), 1);
}