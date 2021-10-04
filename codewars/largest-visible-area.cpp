#include <gtest/gtest.h>

int largest_visible_area(int k, std::vector<std::pair<int, int>> cylinders)
{
    for (size_t i = 0; i < cylinders.size(); ++i)
    {
        for (size_t j = 1; j < cylinders.size(); ++j)
        {
        }
    }
    return 0;
}

TEST(LargetsVisibleArea, sample)
{
    int result1 = largest_visible_area(2, {{2, 16}, {2, 14}, {3, 27}});
    int result2 = largest_visible_area(3, {{1, 80}, {3, 100}, {2, 80}, {3, 90}, {2, 80}});

    EXPECT_EQ(result1, 52);
    EXPECT_EQ(result2, 269);
}