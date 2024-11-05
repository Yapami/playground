#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

std::vector<int> gradingStudents(std::vector<int> grades)
{
    std::vector<int> r = grades;
    for (auto &g : r)
    {
        if (g < 38)
        {
            continue;
        }
        int n = (g + 5) - (g % 5);
        if (n - g < 3)
        {
            g = n;
        }
    }
    return r;
}

TEST(GradingStudents, sample)
{
    std::vector<int> grades = {73, 67, 38, 33};
    EXPECT_THAT(gradingStudents(grades), testing::ContainerEq(std::vector<int>{75, 67, 40, 33}));
}