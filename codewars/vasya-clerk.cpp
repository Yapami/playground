#include <string>
#include <vector>

#include <gtest/gtest.h>

std::string tickets(const std::vector<int> &peopleInLine)
{
    // your code here
    int banknotes[2] = {0, 0};
    for (const auto b : peopleInLine)
    {
        switch (b)
        {
        case 25:
            ++banknotes[0];
            break;
        case 50:
            if (!banknotes[0])
            {
                return "NO";
            }
            --banknotes[0];
            ++banknotes[1];
            break;
        case 100:
            if (banknotes[1] >= 1 && banknotes[0] >= 1)
            {
                --banknotes[0];
                --banknotes[1];
            }
            else if (banknotes[0] >= 3)
            {
                banknotes[0] -= 3;
            }
            else
            {
                return "NO";
            }
            break;
        default:
            break;
        }
    }
    return "YES";
}

TEST(CodeWars, tickets)
{
    EXPECT_EQ(tickets({25, 25, 50, 50}), "YES");
    EXPECT_EQ(tickets({25, 100}), "NO");
}