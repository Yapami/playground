#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

std::vector<int> permutationEquation(const std::vector<int> &p)
{
    std::vector<int> r(p.size());
    for (size_t i = 1; i <= p.size(); ++i)
    {
        r[i - 1] = p[p[i]];
    }
    return r;
}

TEST(SubsequenceEquatation, sample)
{
    EXPECT_THAT(permutationEquation({5, 2, 1, 3, 4}),
                testing::ContainerEq(std::vector<int>({4, 2, 5, 1, 3})));
}