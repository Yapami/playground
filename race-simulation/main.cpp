#include <ConsoleTrack.h>
#include <Race.h>

#include <thread>

int main(int argc, char *argv[])
{
    Rng rng;
    const Competitor::Movement length = 70;
    ConsoleTrack track(length);
    Race r(length, track);
    while (r.update() != Race::State::Finish)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}