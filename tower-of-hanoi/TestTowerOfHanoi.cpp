#include "TowerOfHanoi.h"

#include <gtest/gtest.h>

namespace
{
class TestValidator : public TowerOfHanoi::SolutionValidator
{
    void validate_move(DiskSize from, DiskSize to) override
    {
        EXPECT_LT(from, to);
    }

    void validate_solution(const Stacks &stacks) override
    {
        assert(stacks[0].empty());
        assert(stacks[2].empty());
        auto c = stacks[1];
        const auto s = c.size();
        for (; !c.empty(); c.pop())
        {
            EXPECT_EQ(c.top(), s - c.size() + 1);
        }
    }
};
} // namespace

TEST(TestTowerOfHanoi, simple_case)
{
    TestValidator validator;
    TowerOfHanoi toh;
    toh.solve_recursively(4, validator);
    toh.solve_iteratively(4, validator);
    toh.solve_recursively(7, validator);
    toh.solve_iteratively(7, validator);
}