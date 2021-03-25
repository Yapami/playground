#include "ReverseSentence.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(ReverseSentence, sentence_generation)
{
    auto s = random_sentence();
    EXPECT_GE(std::count(s.begin(), s.end(), ' '), 1);
    EXPECT_THAT(s, testing::Each(testing::AnyOf(testing::AllOf(testing::Ge('a'), testing::Le('z')),
                                                testing::Eq(' '))));
}

TEST(ReverseSentence, generated_sentence)
{
    std::string s = random_sentence();
    std::string copy = s;
    reverse_sentence(s);
    reverse_sentence(s);
    EXPECT_EQ(copy, s);
}