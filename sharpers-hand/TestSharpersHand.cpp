#include "SharpersHand.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(TestSharpresHand, verify_chance)
{
    // 6 times 1/9 of getting ace and 1/4 getting trump.
    // This is a rough approximation, since the real probability should take into account that card
    // values aren't independant.
    const double expected = 6.0 / (9.0 * 4.0);
    EXPECT_NEAR(trump_ace_chance(), expected, expected * 0.25);
}