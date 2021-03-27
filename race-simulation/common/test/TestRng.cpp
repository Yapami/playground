#include <Rng.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <set>

TEST(RaceRng, movement_generation)
{
    Rng rng;
    const Seed min = 1;
    const Seed max = 10;
    const Seed spread = max - min + 1;
    const uint32_t sample = 1 << 12;
    const double low_bound = (sample / spread) * 80 / 100;
    const double high_bound = (sample / spread) * 120 / 100;
    std::vector<uint32_t> occurances(spread);
    for (uint32_t i = 0; i < sample; ++i)
    {
        ++occurances[rng.generate(min, max) - min];
    }
    EXPECT_THAT(occurances,
                testing::Each(testing::AllOf(testing::Ge(low_bound), testing::Le(high_bound))));
}