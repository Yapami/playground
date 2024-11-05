#include <gmock/gmock.h>
#include <gtest/gtest.h>

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2)
{
    if (y1 > y2)
    {
        return 10000;
    }
    if (y1 < y2)
    {
        return 0;
    }
    if (m1 > m2)
    {
        return (m1 - m2) * 500;
    }
    if (m1 < m2)
    {
        return 0;
    }
    if (d1 > d2)
    {
        return (d1 - d2) * 15;
    }
    return 0;
}

TEST(LibraryFine, sample)
{
    EXPECT_EQ(libraryFine(14, 7, 2018, 5, 7, 2018), 135);
    EXPECT_EQ(libraryFine(9, 6, 2015, 6, 6, 2018), 45);
}