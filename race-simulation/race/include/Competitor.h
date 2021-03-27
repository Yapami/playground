#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <Rng.h>
#include <common.h>

class Competitor
{
public:
    using Movement = int32_t;
    using Move = std::pair<Seed, Movement>;
    using AllowedMoves = std::vector<Move>;
    friend class TestRules;

    Competitor(const CompetitorId id, const std::string &name, const AllowedMoves &moves);

    Movement move(Rng &rng) const;
    CompetitorId id() const;
    const std::string &name() const;

    Seed allowed_seed() const;

    Movement velocity() const;

private:
    CompetitorId m_id;
    std::string m_name;
    AllowedMoves m_moves;
    Seed m_allowed_seed;
    Movement m_velocity;
};