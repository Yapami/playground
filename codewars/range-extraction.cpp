#include <gtest/gtest.h>

#include <string>
#include <vector>

std::string range_to_str(int a, int b)
{
    auto r = std::to_string(a);
    const auto d = b - a == 1 ? ',' : '-';
    if (a != b)
    {
        r += d;
        r += std::to_string(b);
    }
    return r;
}

std::string range_extraction(const std::vector<int> &args)
{
    if (args.empty())
    {
        return {};
    }
    if (args.size() == 1)
    {
        return range_to_str(args.front(), args.front());
    }
    std::string r;
    auto s = args.front();
    for (size_t i = 1; i < args.size(); ++i)
    {
        if (args[i] - args[i - 1] > 1)
        {
            r += range_to_str(s, args[i - 1]) + ',';
            s = args[i];
        }
    }
    r += range_to_str(s, args.back());
    return r;
}

TEST(range_extraction, sample_tests)
{
    EXPECT_EQ(
        range_extraction({-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20}),
        "-6,-3-1,3-5,7-11,14,15,17-20");
    EXPECT_EQ(range_extraction({-3, -2, -1, 2, 10, 15, 16, 18, 19, 20}), "-3--1,2,10,15,16,18-20");
}