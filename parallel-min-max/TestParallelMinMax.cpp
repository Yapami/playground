#include "ParallelMinMax.h"

#include <gtest/gtest.h>

TEST(TestParallelMinMax, predefined)
{
    std::vector<uint32_t> v;
    EXPECT_THROW(find_min_max(v), std::invalid_argument);
    v = {10, 20, 30, 40, 50};
    {
        auto [min, max] = find_min_max(v);
        EXPECT_EQ(min, v.front());
        EXPECT_EQ(max, v.back());
    }
    v.push_back(99);
    v.push_back(6);
    {
        auto [min, max] = find_min_max(v);
        EXPECT_EQ(min, 6);
        EXPECT_EQ(max, 99);
    }
}