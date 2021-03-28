#include "Rules.h"

#include <algorithm>

const Rules::Competitors COMPETITORS = {
    {CompetitorId::Hare, "The Hare", {{30, 0}, {20, 9}, {10, -12}, {20, 1}, {20, -1}}},
    {CompetitorId::Tortoise, "The Tortoise", {{50, 3}, {20, -6}, {30, 1}}},
    {CompetitorId::Robo, "The RoboCleaner", {{20, 2}, {30, 1}, {10, -1}, {40, 0}}}};

Rules::Rules(Competitor::Movement length)
    : m_length(length)
{
}

const Rules::Competitors &Rules::competitors() const
{
    return COMPETITORS;
}

const Rules::Competitors::const_iterator Rules::competitor(CompetitorId id) const
{
    return std::find_if(COMPETITORS.begin(), COMPETITORS.end(),
                        [id](const Competitor &c) { return c.id() == id; });
}

Competitor::Movement Rules::length() const
{
    return m_length;
}
