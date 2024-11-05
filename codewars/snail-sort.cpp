#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map)
{
    size_t n = snail_map.size();
    if (!n)
    {
        return {};
    }
    std::vector<int> r(n * n);
    --n;
    if (!n)
    {
        return {snail_map.front()};
    }
    const size_t N = n;
    size_t row = 0;
    size_t column = 0;
    const auto e = r.end();
    for (auto i = r.begin(); i != e;)
    {
        for (; column < n && i != e; ++column, ++i)
        {
            *i = snail_map[row][column];
        }
        for (; row < n && i != e; ++row, ++i)
        {
            *i = snail_map[row][column];
        }
        for (; column > N - n && i != e; --column, ++i)
        {
            *i = snail_map[row][column];
        }
        for (; row > N - n && i != e; --row, ++i)
        {
            *i = snail_map[row][column];
        }
        ++row;
        ++column;
        --n;
        if (!(N & 1) && n == (N >> 1))
        {
            *i = snail_map[row][column];
            return r;
        }
    }

    return r;
}

// std::vector<std::vector<int>> A = {
//     { 710, 783, 540, 537, 779, 109, 496, 294, 878, 234, 134, 937},
//     { 510, 88,  635, 859, 33,  405, 766, 58,  774, 932, 492, 878},
//     { 435, 551, 707, 790, 248, 873, 389, 305, 77,  142, 886, 356},
//     { 1,   745, 697, 521, 490, 746, 853, 49,  581, 796, 869, 28 },
//     { 591, 686, 447, 662, 144, 711, 642, 505, 202, 36,  80,  822},
//     { 257, 277, 8,   807, 662, 770, 208, 758, 598, 834, 887, 955},
//     { 985, 295, 931, 997, 776, 250, 315, 813, 126, 143, 465, 131},
//     { 745, 852, 961, 365, 920, 655, 385, 74,  531, 521, 835, 263},
//     { 384, 443, 50,  941, 591, 913, 561, 293, 240, 147, 459, 999},
//     164, 389, 285, 303, 572, 313, 646, 569, 990, 767, 967, 628, 53,  980, 359, 170, 152, 57,
//     787, 204, 12,  908, 312, 142, 598, 563, 892, 268, 345, 205, 280, 452, 220, 572, 39,  248};

std::vector<int> B = {
    710, 783, 540, 537, 779, 109, 496, 294, 878, 234, 134, 937, 510, 88,  635, 859, 33,  405,
    766, 58,  774, 932, 492, 878, 435, 551, 707, 790, 248, 873, 389, 305, 77,  142, 886, 356,
    1,   745, 697, 521, 490, 746, 853, 49,  581, 796, 869, 28,  591, 686, 447, 662, 144, 711,
    642, 505, 202, 36,  80,  822, 257, 277, 8,   807, 662, 770, 208, 758, 598, 834, 887, 955,
    886, 356, 1,   745, 697, 521, 490, 746, 853, 49,  581, 796, 869, 28,  591, 686, 447, 662,
    144, 365, 920, 655, 385, 74,  531, 521, 835, 263, 384, 443, 50,  941, 591, 913, 985, 356,
    1,   745, 697, 521, 490, 746, 853, 49,  581, 796, 869, 28,  591, 686, 447, 662, 961, 313,
    646, 569, 990, 767, 967, 628, 53,  980, 359, 170, 561, 295, 1,   745, 697, 521, 490, 746};

TEST(CodeWars, snail_sort)
{
    std::vector<std::vector<int>> v;
    std::vector<int> expected;

    v = {{}};
    expected = {};
    EXPECT_THAT(snail(v), testing::ContainerEq(expected));

    v = {{1}};
    expected = {1};
    EXPECT_THAT(snail(v), testing::ContainerEq(expected));

    v = {{1, 2}, {4, 3}};
    expected = {1, 2, 3, 4};
    EXPECT_THAT(snail(v), testing::ContainerEq(expected));

    v = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_THAT(snail(v), testing::ContainerEq(expected));

    // v.resize(12);
    // for (auto &r : v)
    // {
    //     for (size_t i = 0; i < 12; ++i)
    //     {
    //         r.push_back(i);
    //         std::cout << r.back() << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // auto s = snail(v);
    // EXPECT_THAT(s, testing::ContainerEq(expected));

    v = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
    expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    EXPECT_THAT(snail(v), testing::ContainerEq(expected));
}