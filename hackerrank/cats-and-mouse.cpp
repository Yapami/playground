#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

std::string catAndMouse(int x, int y, int z)
{
    if (std::abs(x - z) < std::abs(y - z))
    {
        return "Cat A";
    }
    if (std::abs(y - z) < std::abs(x - z))
    {
        return "Cat B";
    }
    return "Mouse C";
}