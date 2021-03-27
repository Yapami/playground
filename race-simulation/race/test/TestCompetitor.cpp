#include "Competitor.h"

#include <MockRng.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace
{
const std::string test_name = "TestCompetitor";
const CompetitorId test_id = CompetitorId::Robo;
const Competitor::AllowedMoves test_moves{{10, 1}, {30, 4}, {40, -2}, {20, 0}};

class TestCompetitor : public Competitor, public testing::Test
{
public:
    TestCompetitor()
        : Competitor(test_id, test_name, test_moves)
    {
    }
    MockRng mock_rng;
};
} // namespace

TEST_F(TestCompetitor, creation)
{
    EXPECT_EQ(id(), test_id);
    EXPECT_EQ(name(), test_name);
}

TEST_F(TestCompetitor, moves_seed)
{
    auto s = allowed_seed();
    EXPECT_EQ(s, 100);
}

TEST_F(TestCompetitor, move)
{
    EXPECT_CALL(mock_rng, generate(1, allowed_seed()))
        .WillOnce(testing::Return(40))
        .WillOnce(testing::Return(41))
        .WillOnce(testing::Return(90))
        .WillOnce(testing::Return(30))
        .WillOnce(testing::Return(1))
        .WillOnce(testing::Return(100));
    EXPECT_EQ(move(mock_rng), 4);
    EXPECT_EQ(move(mock_rng), -2);
    EXPECT_EQ(move(mock_rng), 0);
    EXPECT_EQ(move(mock_rng), 4);
    EXPECT_EQ(move(mock_rng), 1);
    EXPECT_EQ(move(mock_rng), 0);
}