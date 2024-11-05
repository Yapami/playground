#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

std::string biggerIsGreater(std::string w)
{
    ssize_t i = w.length() - 1;
    while (i > 0 && w[i - 1] >= w[i])
    {
        --i;
    }
    if (i <= 0)
    {
        return "no answer";
    }
    ssize_t j = w.length() - 1;
    while (w[j] <= w[i - 1])
    {
        --j;
    }
    std::swap(w[i - 1], w[j]);
    j = w.length() - 1;
    while (i < j)
    {
        std::swap(w[i], w[j]);
        ++i;
        --j;
    }
    return w;
}

TEST(BiggerIsGreater, sample)
{
    EXPECT_EQ(biggerIsGreater("ab"), "ba");
    EXPECT_EQ(biggerIsGreater("bb"), "no answer");
    EXPECT_EQ(biggerIsGreater("hefg"), "hegf");
    EXPECT_EQ(biggerIsGreater("dhck"), "dhkc");
    EXPECT_EQ(biggerIsGreater("dkhc"), "hcdk");
    EXPECT_EQ(biggerIsGreater("lmno"), "lmon");
    EXPECT_EQ(biggerIsGreater("dcba"), "no answer");
    EXPECT_EQ(biggerIsGreater("dcbb"), "no answer");
}