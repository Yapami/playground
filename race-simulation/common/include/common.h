#pragma once

#include <cstdint>

using Seed = uint32_t;

enum class CompetitorId
{
    Tortoise,
    Hare,
    Robo,
    Total,
};

using Position = int32_t;