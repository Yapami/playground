#include "SetOperations.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class TestSetOperations : public Set, public testing::Test
{
};

TEST_F(TestSetOperations, test_valid_parse)
{
    {
        std::string input = "+ 100";
        auto [op, v, r] = parse_input(input);
        EXPECT_EQ(op, '+');
        EXPECT_EQ(v, 100);
    }

    {
        std::string input = "- 34";
        auto [op, v, r] = parse_input(input);
        EXPECT_EQ(op, '-');
        EXPECT_EQ(v, 34);
    }

    {
        std::string input = "? 33";
        auto [op, v, r] = parse_input(input);
        EXPECT_EQ(op, '?');
        EXPECT_EQ(v, 33);
    }

    {
        std::string input = "s 31 55";
        auto [op, v, r] = parse_input(input);
        EXPECT_EQ(op, 's');
        EXPECT_EQ(v, 31);
        EXPECT_EQ(r, 55);
    }
}

TEST_F(TestSetOperations, test_invalid_parse)
{
    {
        std::string input = "+ ff";
        auto [op, v, r] = parse_input(input);
        EXPECT_EQ(v, invalid_value());
    }

    {
        std::string input = "s 34";
        auto [op, v, r] = parse_input(input);
        EXPECT_EQ(v, 34);
        EXPECT_EQ(r, invalid_value());
    }
}

TEST_F(TestSetOperations, simple_case)
{
    std::vector<std::string> inputs = {"? 0", "+ 0", "? 0", "- 0", "? 0"};
    std::vector<std::string> results;
    for (const auto &i : inputs)
    {
        if (auto r = process(i); !r.empty())
        {
            results.push_back(r);
        }
    }
    EXPECT_EQ(results.size(), 3u);
    EXPECT_EQ(results[0], "Not found");
    EXPECT_EQ(results[1], "Found");
    EXPECT_EQ(results[2], "Not found");
}

TEST_F(TestSetOperations, complex_case)
{
    std::vector<std::string> inputs = {"+ 491572259", "? 491572259", "? 899375874",
                                       "s 310971296 877523306", "+ 352411209"};
    std::vector<std::string> results;
    for (const auto &i : inputs)
    {
        if (auto r = process(i); !r.empty())
        {
            results.push_back(r);
        }
    }
    EXPECT_EQ(results.size(), 3u);
    EXPECT_EQ(results[0], "Found");
    EXPECT_EQ(results[1], "Not found");
    EXPECT_EQ(results[2], "491572259");
}
