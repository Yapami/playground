#include <gtest/gtest.h>

#include <iomanip>
#include <sstream>
#include <string>

class RGBToHex
{
public:
    static std::string rgb(int r, int g, int b)
    {
        r = std::clamp(r, 0, 255);
        g = std::clamp(g, 0, 255);
        b = std::clamp(b, 0, 255);
        std::stringstream ss;
        ss << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << r << std::setw(2)
           << g << std::setw(2) << b;
        return ss.str();
    }
};

TEST(RgbToHex, example_tests)
{
    EXPECT_EQ(RGBToHex::rgb(0, 0, 0), "000000");
    EXPECT_EQ(RGBToHex::rgb(1, 2, 3), "010203");
    EXPECT_EQ(RGBToHex::rgb(255, 255, 255), "FFFFFF");
    EXPECT_EQ(RGBToHex::rgb(254, 253, 252), "FEFDFC");
    EXPECT_EQ(RGBToHex::rgb(-20, 275, 125), "00FF7D");
}
