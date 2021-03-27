#include "Rules.h"

#include "MockRng.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace
{
Competitor::Movement TEST_LENGTH = 1000;

class TestRules : public Rules, public testing::Test
{
public:
    TestRules()
        : Rules(TEST_LENGTH)
    {
    }

protected:
    Competitors::const_iterator get_competitor(CompetitorId id)
    {
        auto s = competitors().cbegin();
        auto e = competitors().cend();
        return std::find_if(s, e, [id](const Competitor &c) { return c.id() == id; });
    }
};
} // namespace

TEST_F(TestRules, default_values)
{
    EXPECT_EQ(length(), TEST_LENGTH);
}

TEST_F(TestRules, competetors_list)
{
    ASSERT_TRUE(competitors().size() == static_cast<size_t>(CompetitorId::Total));
    for (size_t i = 0; i < competitors().size(); ++i)
    {
        auto c = get_competitor(static_cast<CompetitorId>(i));
        ASSERT_TRUE(c != competitors().end());
        EXPECT_EQ(c->allowed_seed(), 100);
    }
}

TEST_F(TestRules, fairness)
{
    std::vector<Competitor::Movement> v(competitors().size());
    for (uint32_t c = 0; c < v.size(); ++c)
    {
        v[c] = competitors()[c].velocity();
    }
    EXPECT_THAT(v, testing::Each(testing::Eq(v.front())));
}