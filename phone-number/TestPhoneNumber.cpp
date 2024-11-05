#include "PhoneNumber.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(PhoneNumber, distance_generation)
{
    auto d = distances();
    EXPECT_FLOAT_EQ(d[0][8], 1.0f);
    const float one_to_zero = std::pow(10, 0.5f);
    EXPECT_FLOAT_EQ(d[1][0], one_to_zero);
}

TEST(PhoneNumber, simple_case)
{
    float r = fastest_input({1, 2});
    EXPECT_FLOAT_EQ(r, 4.0);
    r = fastest_input({1, 2, 9});
    EXPECT_FLOAT_EQ(r, 5.0);
    r = fastest_input({1, 2, 9, 4});
    EXPECT_FLOAT_EQ(r, 5.0 + std::pow(2.0, 0.5));
}