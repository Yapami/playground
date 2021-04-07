#include "BullsAndCows.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(TestBullsAndCows, generation)
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

TEST(TestBullsAndCows, user_input_validation)
{
    const std::string valid = "1234";
    std::vector<uint8_t> r;
    EXPECT_TRUE(process_user_input(valid, r));
    EXPECT_THAT(r, testing::ElementsAreArray({1, 2, 3, 4}));
    r.clear();

    const std::string invalid_letter = "34f5";
    EXPECT_FALSE(process_user_input(invalid_letter, r));
    r.clear();

    const std::string invalid_size = "567";
    EXPECT_FALSE(process_user_input(invalid_size, r));
    r.clear();

    const std::string invalid_unique = "5675";
    EXPECT_FALSE(process_user_input(invalid_unique, r));
    r.clear();
}