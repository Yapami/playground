#include "WordPack.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(WordPack, word_generation)
{
    auto w = random_word();
    EXPECT_LE(w.length(), 6);
    EXPECT_THAT(w, testing::Each(testing::Ge('a')));
    EXPECT_THAT(w, testing::Each(testing::Le('z')));
}

TEST(WordPack, empty_string)
{
    std::string w;
    auto packed = pack(w);
    auto unpacked = unpack(packed);
    EXPECT_EQ(w, unpacked);
}

TEST(WordPack, real_string)
{
    std::string w = random_word();
    auto packed = pack(w);
    auto unpacked = unpack(packed);
    EXPECT_EQ(w, unpacked);
}