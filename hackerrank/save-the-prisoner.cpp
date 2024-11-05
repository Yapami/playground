#include <gmock/gmock.h>
#include <gtest/gtest.h>

int saveThePrisoner(int n, int m, int s)
{
    return ((s + m - 2) % n) + 1;
}

TEST(SaveThePrisoner, sample)
{
    EXPECT_EQ(saveThePrisoner(4, 6, 2), 3);
    EXPECT_EQ(saveThePrisoner(5, 2, 1), 2);
    EXPECT_EQ(saveThePrisoner(5, 2, 2), 3);
    EXPECT_EQ(saveThePrisoner(7, 19, 2), 6);
    EXPECT_EQ(saveThePrisoner(3, 7, 3), 3);
    EXPECT_EQ(saveThePrisoner(4, 1, 4), 4);
    EXPECT_EQ(saveThePrisoner(4, 2, 4), 1);
}