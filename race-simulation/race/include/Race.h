#pragma once

#include "Rules.h"

#include <Rng.h>
#include <Track.h>

class Race
{
public:
    enum class State
    {
        Start,
        Ongoing,
        Finish,
    };

    Race(Competitor::Movement length, Track &track);

    State update();
    size_t competitors() const;

protected:
    State state() const;

private:
    State m_state;
    Rules m_rules;
    std::vector<Competitor::Movement> m_positions;
    Rng m_rng;
    Track &m_track;
};