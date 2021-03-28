#include "GamblersFallacy.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(GamblersFallacy, verification)
{
    const uint32_t pow = 8;
    const uint32_t expected = 1 << pow;
    const uint32_t error = expected / 10;
    const uint32_t runs = 5000;

    uint32_t total = 0;

    for (uint32_t i = 0; i < runs; ++i)
    {
        total += attempts(pow);
    }
    uint32_t average = total / runs;
    EXPECT_NEAR(average, expected, error);
}