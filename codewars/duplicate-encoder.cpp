#include <gtest/gtest.h>

#include <set>
#include <string>

std::string duplicate_encoder(const std::string &word)
{
    std::map<char, size_t> s;
    std::for_each(word.begin(), word.end(), [&s](char c) { s[tolower(c)]++; });
    std::string r;
    std::transform(word.begin(), word.end(), std::back_inserter(r),
                   [&s](char c) { return s[tolower(c)] == 1 ? '(' : ')'; });
    return r;
}

TEST(CodeWars, duplicate_encoder)
{
    EXPECT_EQ(duplicate_encoder("din"), "(((");
    EXPECT_EQ(duplicate_encoder("recede"), "()()()");
    EXPECT_EQ(duplicate_encoder("Success"), ")())())");
    EXPECT_EQ(duplicate_encoder("CodeWarrior"), "()(((())())");
    EXPECT_EQ(duplicate_encoder("Supralapsarian"), ")()))()))))()(");
    EXPECT_EQ(duplicate_encoder("(( @"), "))((");
    EXPECT_EQ(duplicate_encoder(" ( ( )"), ")))))(");
}
