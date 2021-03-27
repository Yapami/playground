#include "Race.h"

Race::Race(Competitor::Movement length, Track &track)
    : m_state(State::Start)
    , m_rules(length)
    , m_positions(m_rules.competitors().size(), 1)
    , m_track(track)
{
}

Race::State Race::update()
{
    if (m_state == State::Finish)
    {
        return m_state;
    }
    m_state = State::Ongoing;
    const auto count = m_rules.competitors().size();
    std::vector<Track::CompetitorPosition> positions;
    std::vector<Track::Winner> winners;
    for (size_t i = 0; i < count; ++i)
    {
        const auto &c = m_rules.competitors()[i];
        auto &p = m_positions[i];
        p += c.move(m_rng);
        p = std::clamp(p, 1, m_rules.length());
        positions.emplace_back(c.id(), p);
        if (p >= m_rules.length())
        {
            m_state = State::Finish;
            winners.emplace_back(c.id(), c.name());
        }
    }
    m_track.update(positions);
    if (state() == State::Finish)
    {
        m_track.finish(winners);
    }
    return m_state;
}

size_t Race::competitors() const
{
    return m_positions.size();
}

Race::State Race::state() const
{
    return m_state;
}
