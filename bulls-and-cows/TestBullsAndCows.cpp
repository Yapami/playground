#include "BullsAndCows.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(CowsAndBulls, generation)
{
    uint32_t attempts = 10000;
    std::array<double, 9> digits = {0};

    const double probability = attempts * (4.0 / 9.0); // Each digit has 1/9 chance to appear
    const double spread = attempts * 0.1;              // 10% threshold

    for (uint32_t i = 0; i < attempts; ++i)
    {
        auto v = values();
        std::for_each(v.begin(), v.end(), [&digits](const uint8_t d) { ++digits[d - 1]; });
    }
    EXPECT_THAT(digits, testing::Each(testing::DoubleNear(probability, spread)));
}