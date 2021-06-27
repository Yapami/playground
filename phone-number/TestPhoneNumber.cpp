#include "PhoneNumber.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(PhoneNumber, distance_generation)
{
    auto d = distances();
    EXPECT_NEAR(d[0][8], 1.0f, 0.0001);
    const float one_to_zero = std::pow(10, 0.5f);
    EXPECT_NEAR(d[1][0], one_to_zero, 0.0001);
}

TEST(PhoneNumber, simple_case)
{
    float r = fastest_input({1, 2});
    EXPECT_NEAR(r, 4.0, 0.001);
    r = fastest_input({1, 2, 9});
    EXPECT_NEAR(r, 5.0, 0.001);
    r = fastest_input({1, 2, 9, 4});
    EXPECT_NEAR(r, 5.0 + std::pow(2.0, 0.5), 0.001);
}