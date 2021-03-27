#include "Rng.h"

#include <assert.h>

Rng::Rng()
    : m_rd()
    , m_g(m_rd())
{
}

Seed Rng::generate(Seed min, Seed max)
{
    assert(min < max);
    return m_rd() % (max - min + 1) + min;
}