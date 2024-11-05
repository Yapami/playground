#include <gtest/gtest.h>

#include <functional>
#include <string>
#include <vector>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr)
    {
        auto t = arr;
        bool swap;
        do
        {
            swap = false;
            auto c = t.begin();
            while (c != t.end())
            {
                auto n = std::next(c);
                if (n == t.end())
                {
                    break;
                }
                if ((c->front() == 'N' && n->front() == 'S') ||
                    (c->front() == 'S' && n->front() == 'N') ||
                    (c->front() == 'W' && n->front() == 'E') ||
                    (c->front() == 'E' && n->front() == 'W'))
                {
                    c = t.erase(c, n + 1);
                    swap = true;
                    continue;
                }
                ++c;
            }
        } while (swap);
        return t;
    }
};

TEST(CodeWars, directions_reduction)
{
    std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
    std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
    std::vector<std::string> sol1 = {"WEST"};
    EXPECT_EQ(ans1, sol1);
}