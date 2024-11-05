#include <vector>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class Tortoise
{
public:
    static std::vector<int> race(int v1, int v2, int g)
    {
        const auto v1_fps = static_cast<double>(v1); // / 3600.0f;
        const auto v2_fps = static_cast<double>(v2); // / 3600.0f;
        auto t = static_cast<double>(g) / (v2_fps - v1_fps);
        if (t <= 0.0)
        {
            return {-1, -1, -1};
        }
        const int h = t;
        const int m = std::fmod(t * 60.0, 60.0);
        const int s = std::fmod(t * 3600.0, 60.0);
        return {h, m, s};
    }
};

TEST(CodeWars, tortoise_racing)
{
    EXPECT_THAT(Tortoise::race(720, 850, 70), testing::ContainerEq(std::vector<int>{0, 32, 18}));
    EXPECT_THAT(Tortoise::race(820, 81, 550), testing::ContainerEq(std::vector<int>{-1, -1, -1}));
    EXPECT_THAT(Tortoise::race(80, 91, 37), testing::ContainerEq(std::vector<int>{3, 21, 49}));
}
