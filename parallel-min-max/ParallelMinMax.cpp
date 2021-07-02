#include "ParallelMinMax.h"

#include <algorithm>
#include <execution>

std::pair<uint32_t, uint32_t> find_min_max(const std::vector<uint32_t> &v)
{
    return std::minmax_element(std::execution::par, v.begin(), v.end());
}