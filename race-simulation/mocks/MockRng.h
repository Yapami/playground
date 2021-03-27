#pragma once

#include "Rng.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockRng : public Rng
{
public:
    MOCK_METHOD(Seed, generate, (Seed min, Seed max), (override));
};
