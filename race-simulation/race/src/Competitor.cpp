#include "Competitor.h"

Competitor::Competitor(const CompetitorId id, const std::string &name, const AllowedMoves &moves)
    : m_id(id)
    , m_name(name)
    , m_moves(moves)
    , m_allowed_seed(0)
    , m_velocity(0)
{
    for (const auto &m : m_moves)
    {
        m_allowed_seed += m.first;
        m_velocity += m.first * m.second;
    }
}

Competitor::Movement Competitor::move(Rng &rng) const
{
    const auto max_seed = allowed_seed();
    const auto seed = rng.generate(1, max_seed);
    auto it = std::find_if(m_moves.begin(), m_moves.end(), [seed, p = 0](const Move &m) mutable {
        if (p + m.first >= seed)
        {
            return true;
        }
        p += m.first;
        return false;
    });
    assert(it != m_moves.end());
    return it->second;
}

CompetitorId Competitor::id() const
{
    return m_id;
}

const std::string &Competitor::name() const
{
    return m_name;
}

Seed Competitor::allowed_seed() const
{
    return m_allowed_seed;
}

Competitor::Movement Competitor::velocity() const
{
    return m_velocity;
}
