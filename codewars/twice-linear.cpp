#include <gtest/gtest.h>

#include <cmath>
#include <set>

class DoubleLinear
{
public:
    static int dblLinear(int n)
    {
        std::set<int> u = {1};
        int i = 1;
        int c = 0;
        while (c < n)
        {
            u.insert(2 * i + 1);
            u.insert(3 * i + 1);
            i = *u.upper_bound(i);
            ++c;
        }
        return i;
    }
};

TEST(CodeWars, twice_linear)
{
    EXPECT_EQ(DoubleLinear::dblLinear(10), 22);
    EXPECT_EQ(DoubleLinear::dblLinear(20), 57);
    EXPECT_EQ(DoubleLinear::dblLinear(30), 91);
    EXPECT_EQ(DoubleLinear::dblLinear(50), 175);
}