#include "RaceSimulation.h"
#include <ConsoleTrack.h>

int main(int argc, char *argv[])
{
    bool resume = false;
    const Competitor::Movement l = 70;
    const std::chrono::milliseconds s(100);
    ConsoleTrack track;
    RaceSimulation sim(track);
    do
    {
        sim.run(l, s);
        resume = getchar() == ' ';
    } while (resume);

    return 0;
}