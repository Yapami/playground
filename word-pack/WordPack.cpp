#include "WordPack.h"

#include <bitset>
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
    uint32_t r = 0;
    for (uint32_t i = 0; i < word.length(); ++i)
    {
        r |= static_cast<uint32_t>(word[i] - 'a') << (i * 5);
    }
    return r;
}

std::string unpack(uint32_t word)
{
    std::string r;
    for (uint32_t i = 0; i < 6; ++i)
    {
        r.push_back(static_cast<char>((word >> (i * 5)) & 0b11111) + 'a');
    }
    return r;
}