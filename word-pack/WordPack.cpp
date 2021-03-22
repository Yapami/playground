#include "WordPack.h"

#include <random>

std::string random_word()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::string result;
    for (int i = 0; i < 6; ++i)
    {
        result.push_back((rd() % 26) + 'a');
    }
    return result;
}

uint32_t pack(const std::string &word)
{
    return 0;
}

std::string unpack(uint32_t word)
{
    return {};
}