#include "BullsAndCows.h"

#include <algorithm>
#include <random>

std::vector<uint8_t> values()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::vector<uint8_t> v(9);
    std::generate(v.begin(), v.end(), [n = 1]() mutable { return n++; });
    std::shuffle(v.begin(), v.end(), g);
    v.resize(4);
    return v;
}

bool process_user_input(const std::string &s, std::vector<uint8_t> &digits)
{
    if (s.length() != 4)
    {
        return false;
    }
    bool invalid = false;
    std::transform(s.begin(), s.end(), std::back_inserter(digits), [&digits, &invalid](char c) {
        auto d = c - '0';
        invalid |= (d != std::clamp(d, 1, 9));
        return d;
    });

    bool dublicates = false;
    for (size_t n = 0, m = n + 1; n < 3;)
    {
        dublicates |= digits[n] == digits[n + m];
        ++m;
        if (m == 4)
        {
            ++n;
            m = n + 1;
        }
    }
    return !invalid && !dublicates;
}