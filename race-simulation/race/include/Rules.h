#pragma once

#include "Competitor.h"

#include <set>

class Rules
{
public:
    using Competitors = std::vector<Competitor>;

    Rules(Competitor::Movement length);

    const Competitors &competitors() const;

    virtual Competitor::Movement length() const;

protected:
    const Competitors::const_iterator competitor(CompetitorId id) const;

private:
    Competitor::Movement m_length;
};