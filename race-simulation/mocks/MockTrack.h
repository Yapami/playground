#pragma once

#include "Track.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockTrack : public Track
{
public:
    MOCK_METHOD(void, set_length, (int32_t l), (override));
    MOCK_METHOD(void, update, (const std::vector<CompetitorPosition> &positions), (override));
    MOCK_METHOD(void, finish, (const std::vector<Winner> &winners), (override));
};
