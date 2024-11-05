#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

int countingValleys(int steps, std::string path)
{
    int v = 0;
    int c = 0;
    for (auto s : path)
    {
        if (c == 0 && s == 'D')
        {
            ++v;
        }
        c += s == 'D' ? -1 : +1;
    }
    return v;
}

TEST(CountingValleys, sample)
{
    EXPECT_EQ(countingValleys(8, "DDUUUUDD"), 1);
    EXPECT_EQ(countingValleys(8, "UDDDUDUU"), 1);
}
