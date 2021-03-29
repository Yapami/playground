#include "SharpersHand.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(TestSharpresHand, verify_chance)
{
    const double expected = 6.0 / (9.0 * 4.0); // 6 times 1/9 of getting ace and 1/4 getting trump
    EXPECT_NEAR(trump_ace_chance(), expected, expected * 0.25);
}