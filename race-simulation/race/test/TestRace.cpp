#include "Race.h"

#include <MockTrack.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace
{
Competitor::Movement TEST_LENGTH = 100;
class TestRace : public Race, public testing::Test
{
public:
    TestRace()
        : Race(TEST_LENGTH, m_track)
    {
    }

protected:
    MockTrack m_track;
};
} // namespace

TEST_F(TestRace, init)
{
    EXPECT_EQ(state(), State::Start);
}

TEST_F(TestRace, simulate_race)
{
    std::map<CompetitorId, uint32_t> s;
    const uint32_t samples = 100;
    EXPECT_CALL(m_track, update(testing::_)).Times(testing::AnyNumber());
    EXPECT_CALL(m_track, finish(testing::_))
        .Times(samples)
        .WillRepeatedly(testing::Invoke([&s](const std::vector<Track::Winner> &winners) {
            for (const auto &w : winners)
            {
                ++s[w.first];
            }
        }));
    for (uint32_t i = 0; i < samples; ++i)
    {
        for (Race r(TEST_LENGTH, m_track); r.update() != State::Finish;)
            ;
    }
    EXPECT_EQ(s.size(), competitors());
}