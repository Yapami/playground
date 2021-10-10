#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

std::vector<int> cutTheSticks(const std::vector<int> &arr)
{
    std::vector<int> r = arr;
    std::vector<int> o;
    std::sort(r.begin(), r.end());
    o.push_back(arr.size());
    auto s = r.begin();
    do
    {
        auto e = std::upper_bound(s, r.end(), *s);
        auto d = o.back() - std::distance(s, e);
        if (d)
        {
            o.push_back(d);
        }
        s = e;
    } while (s != r.end());
    return o;
}

TEST(CutTheSticks, sample)
{
    EXPECT_THAT(cutTheSticks({1, 2, 3, 4, 3, 3, 2, 1}),
                testing::ContainerEq(std::vector<int>{8, 6, 4, 1}));
    EXPECT_THAT(cutTheSticks({5, 4, 4, 2, 2, 8}),
                testing::ContainerEq(std::vector<int>{6, 4, 2, 1}));
}