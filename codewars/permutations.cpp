#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

std::vector<std::string> permutations(std::string s)
{
    std::sort(s.begin(), s.end());
    std::vector<std::string> r{s};
    while (std::next_permutation(s.begin(), s.end()))
    {
        r.push_back(s);
    }
    return r;
}

TEST(permutations, sample)
{
    EXPECT_THAT(permutations("a"), testing::ContainerEq(std::vector<std::string>{"a"}));
    EXPECT_THAT(permutations("ab"), testing::ContainerEq(std::vector<std::string>{"ab", "ba"}));
    EXPECT_THAT(permutations("aabb"), testing::ContainerEq(std::vector<std::string>{
                                          "aabb", "abab", "abba", "baab", "baba", "bbaa"}));
}