#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

std::string angryProfessor(int k, std::vector<int> a)
{
    int c = std::count_if(a.begin(), a.end(), [](int n) { return n <= 0; });
    return c >= k ? "NO" : "YES";
}

TEST(AngryProfessor, sample)
{
    EXPECT_EQ(angryProfessor(3, {-1, -3, 4, 2}), "YES");
    EXPECT_EQ(angryProfessor(2, {0, -1, 2, 1}), "NO");
}