#include <gtest/gtest.h>

#include <array>
#include <cstdint>
#include <memory.h>
#include <unordered_map>

template<std::size_t S>
std::int64_t solve(const std::array<int, S> &input)
{
    // std::unordered_map<int, std::size_t> m;
    const std::size_t max = 100001;
    std::vector<int> m(max);
    std::size_t sum = S;
    const int *ptr = input.data();
    std::unordered_map<int, std::vector<std::size_t>> sums;
    for (std::size_t i = 0; i < S; ++i)
    {
        memset(m.data(), 0, sizeof(int) * max);
        ++m[ptr[i]];
        size_t even_count = 0;
        std::size_t current_sum = 0;
        for (std::size_t j = i + 1; j < S; ++j)
        {
            const auto jv = ++m[ptr[j]];
            if (jv > 1)
            {
                even_count += jv & 1 ? -1 : +1;
            }
            if (!even_count)
            {
                ++sum;
                ++current_sum;
            }
        }
        sums[ptr[i]].push_back(current_sum);
    }
    return sum;
}

// template<std::size_t S>
// std::int64_t solve(const std::array<int, S> &input)
// {
//     // std::unordered_map<int, std::size_t> m;
//     const std::size_t max = 100001;
//     std::unordered_map<int, std::size_t> m;
//     std::size_t sum = S;
//     const int *ptr = input.data();
//     std::size_t current_count = 1;
//     for (std::size_t i = 0; i < S; ++i)
//     {
//         ++m[ptr[i]];
//         if (!(m[ptr[i]] & 1))
//         {
//             sum += current_count * (current_count + 1) >> 1;
//             current_count = 1;
//             m.clear();
//             ++m[ptr[i]];
//         }
//         else
//         {
//             ++current_count;
//         }
//     }
//     return sum;
// }

TEST(CodeWars, naive_subarray)
{
    // std::array<int, 4> a1 = {2, 2, 2, 3};
    // std::array<int, 5> a1 = {2, 2, 2, 2, 3};
    std::array<int, 14> a2 = {2, 5, 2, 3, 6, 7, 8, 23, 13, 65, 31, 3, 4, 3};
    // std::array<int, 27> a3 = {6, 1, 7, 4, 6, 7, 1, 4, 7, 1, 4, 6, 6, 7,
    //                           4, 1, 6, 4, 7, 1, 4, 5, 3, 2, 1, 6, 9};
    // EXPECT_EQ(solve(a1), 7);
    EXPECT_EQ(solve(a2), 79);
    // EXPECT_EQ(solve(a3), 114);
}