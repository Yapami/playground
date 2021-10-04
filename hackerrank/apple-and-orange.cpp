#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

void countApplesAndOranges(int s, int t, int ap, int op, std::vector<int> a, std::vector<int> o)
{
    std::transform(a.begin(), a.end(), a.begin(), [ap](int p) { return ap + p; });
    std::transform(o.begin(), o.end(), o.begin(), [op](int p) { return op + p; });

    size_t ac = std::count_if(a.begin(), a.end(), [s, t](int p) { return p >= s && p <= t; });
    size_t oc = std::count_if(o.begin(), o.end(), [s, t](int p) { return p >= s && p <= t; });
    std::cout << ac << std::endl;
    std::cout << oc << std::endl;
}

TEST(countApplesAndOranges, sample)
{
    countApplesAndOranges(7, 11, 5, 15, {-2, 2, 1}, {5, -6});
}