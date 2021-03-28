#include "GamblersFallacy.h"

#include <random>

uint32_t attempts(uint32_t pow)
{
    std::random_device rd;
    std::mt19937 g(rd());

    uint32_t c = 1;
    uint32_t t = 1;
    uint32_t p = rd() % 2;

    do
    {
        uint32_t v = rd() % 2;
        if (v == p)
        {
            ++c;
        }
        else
        {
            c = 1;
        }
        p = v;
        ++t;
    } while (c < pow);
    return t;
}
