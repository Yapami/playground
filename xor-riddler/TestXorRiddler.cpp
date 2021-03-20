#include "XorRiddler.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(XorRiddler, validation)
{
    EXPECT_TRUE(validate_chars("correct input"));
    EXPECT_TRUE(validate_chars(""));
    EXPECT_FALSE(validate_chars("number 1"));
    EXPECT_FALSE(validate_chars("WRONG"));
}

TEST(XorRiddler, encryption)
{
    std::string s = "hello world";
    auto encrypted = encrypt(s, 0b10101010);
    auto decrypted = decrypt(encrypted);
    EXPECT_TRUE(std::count(decrypted.begin(), decrypted.end(), s));
}

TEST(XorRiddler, multiple_results)
{
    std::string s = "swaplastbit";
    auto encrypted = encrypt(s, 0b1);
    auto decrypted = decrypt(encrypted);
    EXPECT_GT(decrypted.size(), 1);
    EXPECT_TRUE(std::count(decrypted.begin(), decrypted.end(), s));
}