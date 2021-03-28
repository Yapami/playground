#pragma once

#include <Race.h>

class RaceSimulation
{
public:
    RaceSimulation(Track &track);

    void run(const Competitor::Movement length, std::chrono::milliseconds step_duration);

private:
    Competitor::Movement m_length;
    Track &m_track;
};