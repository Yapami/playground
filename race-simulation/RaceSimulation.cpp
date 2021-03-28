#include "RaceSimulation.h"

#include <thread>

RaceSimulation::RaceSimulation(Track &track)
    : m_track(track)
{
}

void RaceSimulation::run(const Competitor::Movement length, std::chrono::milliseconds step_duration)
{
    Race r(length, m_track);
    m_track.set_length(length);
    while (r.update() != Race::State::Finish)
    {
        std::this_thread::sleep_for(step_duration);
    }
}
