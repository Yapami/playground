#include <gmock/gmock.h>
#include <gtest/gtest.h>

long taumBday(long b, long w, long bc, long wc, long z)
{
    return b * std::min(bc, wc + z) + w * std::min(wc, bc + z);
}

TEST(TaumBDay, sample)
{
    EXPECT_EQ(taumBday(3, 5, 3, 4, 1), 29);
    EXPECT_EQ(taumBday(10, 10, 1, 1, 1), 20);
    EXPECT_EQ(taumBday(5, 9, 2, 3, 4), 37);
    EXPECT_EQ(taumBday(3, 6, 9, 1, 1), 12);
    EXPECT_EQ(taumBday(7, 7, 4, 2, 1), 35);
    EXPECT_EQ(taumBday(3, 3, 1, 9, 2), 12);
}