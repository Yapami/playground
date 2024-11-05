#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <numeric>
#include <string>
#include <vector>

std::string encryption(std::string s)
{
    std::string r;
    s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return c == ' '; }), s.end());
    size_t l = s.length();
    size_t w = std::ceil(std::sqrt(l));
    size_t h = (l / w);
    h += w * h >= l ? 0 : 1;
    for (size_t i = 0; i < w; ++i)
    {
        size_t j;
        for (j = 0; j < h; ++j)
        {
            if (w * j + i >= l)
            {
                continue;
            }
            r.push_back(s[w * j + i]);
        }
        if (i * h + j < l)
        {
            r.push_back(' ');
        }
    }
    return r;
}

TEST(Encryption, sample)
{
    EXPECT_EQ(encryption("if man was meant to stay on the ground god would have given us roots"),
              "imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn sseoau");
    EXPECT_EQ(encryption("haveaniceday"), "hae and via ecy");
    EXPECT_EQ(encryption("feedthedog"), "fto ehg ee dd");
    EXPECT_EQ(encryption("chillout"), "clu hlt io");
}