#include <gtest/gtest.h>

#include <list>
#include <string>
#include <utility>

using psi = std::pair<std::string, int>;

std::pair<std::string, int> encode(const std::string &s)
{
    if (s.size() <= 1)
    {
        return {"", 0};
    }
    std::list<char> v;
    std::copy(s.begin(), s.end(), std::back_inserter(v));
    std::vector<std::string> p = {s};
    for (size_t i = 1; i < s.size(); ++i)
    {
        v.push_front(v.back());
        v.pop_back();
        p.emplace_back(v.begin(), v.end());
    }
    std::sort(p.begin(), p.end());
    std::pair<std::string, int> result;
    for (size_t i = 0; i < s.size(); ++i)
    {
        result.first.push_back(p[i].back());
        if (p[i] == s)
        {
            result.second = i;
        }
    }
    return result;
}

std::string decode(const std::string &s, int n)
{
    if (s.size() <= 1)
    {
        return s;
    }
    std::vector<char> v;
    std::copy(s.begin(), s.end(), std::back_inserter(v));
    auto vs = v;
    std::sort(vs.begin(), vs.end());
    std::vector<std::list<char>> p(s.size());
    for (size_t i = 0; i < s.size(); ++i)
    {
        p[i].push_back(vs[i]);
    }

    for (size_t i = 1; i < s.size(); ++i)
    {
        for (size_t j = 0; j < s.size(); ++j)
        {
            p[j].push_front(v[j]);
        }
        std::sort(p.begin(), p.end());
    }
    std::string result;
    std::copy(p[n].begin(), p[n].end(), std::back_inserter(result));
    return result;
}

TEST(CodeWars, burrows_wheeler_transformation)
{
    auto b = encode("bananabar");
    EXPECT_EQ(b.first, "nnbbraaaa");
    EXPECT_EQ(b.second, 4);
    b = encode("Humble Bundle");
    EXPECT_EQ(b.first, "e emnllbduuHB");
    EXPECT_EQ(b.second, 2);

    b = encode("Mellow Yellow");
    EXPECT_EQ(b.first, "ww MYeelllloo");
    EXPECT_EQ(b.second, 1);
    EXPECT_EQ(decode("nnbbraaaa", 4), "bananabar");
    EXPECT_EQ(decode("e emnllbduuHB", 2), "Humble Bundle");
    EXPECT_EQ(decode("ww MYeelllloo", 1), "Mellow Yellow");
}
