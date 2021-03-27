#pragma once

#include <random>

#include "common.h"

class Rng
{
public:
    Rng();
    virtual ~Rng() = default;

    virtual Seed generate(Seed min, Seed max);

private:
    std::random_device m_rd;
    std::mt19937 m_g;
};