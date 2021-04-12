#include "JosephusProblem.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(JosephusProblem, verification_with_formula)
{
    uint32_t n = 11;
    uint32_t k = 3;
    EXPECT_EQ(iterative_solution(n, k), list_solution(n, k));
    n = 14;
    k = 4;
    EXPECT_EQ(iterative_solution(n, k), list_solution(n, k));
}
