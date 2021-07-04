#include "SquareSums.h"

#include <gtest/gtest.h>

TEST(SquareSums, max_square_calculation)
{
    EXPECT_EQ(highest_square_root(5), 3);
    EXPECT_EQ(highest_square_root(10), 4);
}

TEST(SquareSums, case_15)
{
    const uint32_t n = 780;
    auto r = square_sums_row(n);
    EXPECT_FALSE(r.empty());
    auto roots = generate_roots(highest_square_root(n));

    auto i = r.begin();
    auto j = std::next(i);

    for (; j != r.end(); ++i, ++j)
    {
        EXPECT_TRUE(std::find(roots.begin(), roots.end(), *i + *j) != roots.end());
    }
}
