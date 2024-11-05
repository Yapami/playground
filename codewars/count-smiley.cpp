#include <gtest/gtest.h>

#include <regex>
#include <string>
#include <vector>

int countSmileys(std::vector<std::string> arr)
{
    int c = 0;
    std::regex smile_regex("[:;][~-]?[D)]");
    for (const auto &s : arr)
    {
        auto s_it = std::sregex_iterator(s.begin(), s.end(), smile_regex);
        auto e_it = std::sregex_iterator{};
        c += std::distance(s_it, e_it);
    }
    return c;
}

TEST(CodeWars, count_smiley)
{
    EXPECT_EQ(countSmileys({}), 0);
    EXPECT_EQ(countSmileys({":D", ":~)", ";~)", ":)"}), 4);
    EXPECT_EQ(countSmileys({":)", ":(", ":D", ":O", ":;"}), 2);
    EXPECT_EQ(countSmileys({";]", ":[", ";*", ":$", ";-D"}), 1);
}