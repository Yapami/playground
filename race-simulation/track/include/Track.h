#pragma once

#include <common.h>

#include <vector>

class Track
{
public:
    using CompetitorPosition = std::pair<CompetitorId, Position>;
    using Winner = std::pair<CompetitorId, std::string>;

    virtual ~Track() = default;

    virtual void set_length(int32_t l) = 0;
    virtual void update(const std::vector<CompetitorPosition> &positions) = 0;
    virtual void finish(const std::vector<Winner> &winners) = 0;
};