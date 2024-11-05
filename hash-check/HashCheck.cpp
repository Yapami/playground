#include "HashCheck.h"

#include <functional>

std::size_t pos_hash_repeats(int32_t x, int32_t y)
{
    return std::hash<int32_t>()(x) ^ std::hash<int32_t>()(y);
}

std::size_t pos_hash_unique(int32_t x, int32_t y)
{
    return std::hash<int32_t>()(x<<8) ^ std::hash<int32_t>()(y);
}
