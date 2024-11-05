#include <vector>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

int FindOutlier(std::vector<int> arr)
{
    auto c = arr.begin();
    auto n = std::next(c);
    while (n != arr.end())
    {
        if ((*c & 1) != (*n & 1))
        {
            return (*std::next(n) & 1) == (*n & 1) ? *c : *n;
        }
        ++c;
        ++n;
    }
    return *c;
}

void test_for(const std::vector<int> &arr, int result)
{
    EXPECT_EQ(FindOutlier(arr), result);
}

TEST(CodeWars, find_outliner)
{
    test_for({2, 3, 4}, 3);
    test_for({2, 4, 3}, 3);
    test_for({1, 2, 3}, 2);
    test_for({1, 5, 2, 3}, 2);
    test_for({4, 1, 3, 5, 9}, 4);
}