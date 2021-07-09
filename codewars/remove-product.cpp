#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

class RemovedNumbers
{
public:
    static std::vector<std::vector<long long>> removNb(long long n)
    {
        std::vector<std::vector<long long>> result;
        uint64_t x = n;
        uint64_t t = ((n + 1) * n) / 2;
        for (uint64_t i = 1; i <= x; ++i)
        {
            auto j = (t - i) / (i + 1);
            if (j <= x && j * i == t - i - j)
            {
                result.push_back({static_cast<long long>(i), static_cast<long long>(j)});
            }
        }
        return result;
    }
};

TEST(CodeWars, remove_product)
{
    std::vector<std::vector<long long>> r1 = {{15, 21}, {21, 15}};
    EXPECT_THAT(RemovedNumbers::removNb(26), testing::ContainerEq(r1));
}