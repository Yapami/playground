#include "HashCheck.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <unordered_set>

TEST(TestHashCheck, verify_uniqueness)
{
    std::unordered_set<size_t> hashes_repeat;
    std::unordered_set<size_t> hashes_unique;
    for (int32_t x = 0; x < 8; ++x)
    {
        for (int32_t y = 0; y < 8; ++y)
        {
            hashes_repeat.insert(pos_hash_repeats(x,y));
            hashes_unique.insert(pos_hash_unique(x,y));
        }
    }
    EXPECT_EQ(hashes_unique.size(), 64u);
    EXPECT_LT(hashes_repeat.size(), 64u);
}
