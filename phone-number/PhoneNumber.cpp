#include "PhoneNumber.h"

#include <array>
#include <cmath>

Distance distance(float sx, float ex, float sy, float ey)
{
    return std::pow(std::pow(ex - sx, 2.0f) + std::pow(ey - sy, 2.0f), 0.5f);
}

/*
 1 2 3
 4 5 6
 7 8 9
 * 0 #
*/
std::vector<std::vector<Distance>> distances()
{
    const Key keys = 12;
    std::vector<std::pair<Distance, Distance>> pos(keys);
    std::vector<std::vector<Distance>> result(keys);
    pos[1] = {0.0f, 0.0f};
    pos[2] = {1.0f, 0.0f};
    pos[3] = {2.0f, 0.0f};
    pos[4] = {0.0f, 1.0f};
    pos[5] = {1.0f, 1.0f};
    pos[6] = {2.0f, 1.0f};
    pos[7] = {0.0f, 2.0f};
    pos[8] = {1.0f, 2.0f};
    pos[9] = {2.0f, 2.0f};
    pos[0] = {1.0f, 3.0f};
    pos[STAR] = {0.0f, 3.0f};
    pos[HASH] = {2.0f, 3.0f};
    for (Key i = 0; i < keys; ++i)
    {
        const auto [sx, sy] = pos[i];
        for (Key j = 0; j < keys; ++j)
        {
            const auto [ex, ey] = pos[j];
            result[i].push_back(distance(sx, ex, sy, ey));
        }
    }
    return result;
}

Distance fastest_input(const std::vector<Key> &number)
{
    auto d = distances();
    std::array<Distance, 2> opt;

    auto l = STAR;
    auto r = HASH;

    std::vector<Distance> m(number.size() + 1);

    for (size_t i = 0; i < number.size(); ++i)
    {
        opt[0] = m[i] + d[number[i]][l];
        opt[1] = m[i] + d[number[i]][r];
        if (opt[0] <= opt[1])
        {
            m[i + 1] = opt[0];
            l = number[i];
        }
        else
        {
            m[i + 1] = opt[1];
            r = number[i];
        }
    }
    return m.back();
}