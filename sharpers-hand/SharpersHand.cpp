#include "SharpersHand.h"

#include <algorithm>
#include <random>
#include <vector>

uint32_t suit(uint32_t card)
{
    return card % 4;
}

uint32_t face(uint32_t card)
{
    return card % 9;
}

bool is_ace(uint32_t card)
{
    return card < 4; // Consider aces 0-3, kings 32-35
}

double trump_ace_chance()
{
    const size_t deck_size = 36;
    const uint32_t samples = 5000;
    std::vector<uint32_t> deck(deck_size);
    std::generate(deck.begin(), deck.end(), [n = 0]() mutable { return n++; });

    std::random_device rd;
    std::mt19937 rg(rd());

    uint32_t count = 0;

    for (uint32_t i = 0; i < samples; ++i)
    {
        std::shuffle(deck.begin(), deck.end(), rd);
        const uint32_t trump = suit(deck.back());
        for (size_t i = 0; i < 6; ++i)
        {
            const auto card = deck[i];
            if (is_ace(card) && suit(card) == trump)
            {
                ++count;
                break;
            }
        }
    }
    return static_cast<double>(count) / samples;
}