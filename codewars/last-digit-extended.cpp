#include <gtest/gtest.h>

#include <cmath>
#include <list>

int last_digit(std::list<int> array)
{
    if (array.empty() || array.front() == 0)
    {
        return 1;
    }
    std::vector<std::vector<int>> pows = {{0, 0, 0, 0}, {1, 1, 1, 1}, {6, 2, 4, 8}, {1, 3, 9, 7},
                                          {6, 4, 6, 4}, {5, 5, 5, 5}, {6, 6, 6, 6}, {9, 3, 1, 7},
                                          {4, 2, 6, 8}, {1, 9, 1, 9}};

    int b = *array.rbegin();
    for (auto a = std::next(array.rbegin()); a != array.rend(); ++a)
    {
        b = pows[*a % 10][b % 4];
    }
    return b;
}

TEST(CodeWars, last_digit)
{
    // EXPECT_EQ(last_digit({}), 1);
    // EXPECT_EQ(last_digit({0, 0}), 1);
    // EXPECT_EQ(last_digit({0, 0, 0}), 0);
    // EXPECT_EQ(last_digit({1, 2}), 1);
    // EXPECT_EQ(last_digit({3, 4}), 1);
    // EXPECT_EQ(last_digit({12, 3}), 8);

    EXPECT_EQ(last_digit({3, 4, 5}), 1);
    EXPECT_EQ(last_digit({4, 3, 6}), 4);
    EXPECT_EQ(last_digit({7, 6, 21}), 1);
    EXPECT_EQ(last_digit({12, 30, 21}), 6);
    EXPECT_EQ(last_digit({2, 2, 2, 0}), 4);
    EXPECT_EQ(last_digit({937640, 767456, 981242}), 0);
    EXPECT_EQ(last_digit({123232, 694022, 140249}), 6);
    EXPECT_EQ(last_digit({499942, 898102, 846073}), 6);
}