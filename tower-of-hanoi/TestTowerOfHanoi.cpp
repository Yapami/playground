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
        EXPECT_TRUE(stacks[peg(Peg::From)].empty());
        EXPECT_TRUE(stacks[peg(Peg::Tmp)].empty());
        auto c = stacks[peg(Peg::To)];
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