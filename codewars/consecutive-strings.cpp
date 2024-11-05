#include <gtest/gtest.h>

#include <string>
#include <vector>

#include <numeric>

class LongestConsec
{
public:
    static std::string longestConsec(std::vector<std::string> &strarr, int k)
    {
        if (k == 0 || strarr.empty() || strarr.size() < k)
        {
            return "";
        }
        std::vector<size_t> s(strarr.size());
        std::transform(strarr.begin(), strarr.end(), s.begin(),
                       [](const std::string &v) { return v.size(); });
        std::pair<size_t, size_t> c = {std::accumulate(s.begin(), s.begin() + k, 0u), 0};
        std::pair<size_t, size_t> max = c;
        for (size_t i = k; i < s.size(); ++i)
        {
            c.first -= s[c.second];
            ++c.second;
            c.first += s[i];
            if (c.first > max.first)
            {
                max.first = c.first;
                max.second = c.second;
            }
        }
        return std::accumulate(strarr.begin() + max.second, strarr.begin() + max.second + k,
                               std::string{});
    }
};

TEST(CodeWars, consecutive_strings)
{
    std::vector<std::string> arr = {"zone", "abigail", "theta", "form",
                                    "libe", "zas",     "theta", "abigail"};
    EXPECT_EQ(LongestConsec::longestConsec(arr, 2), "abigailtheta");
    arr = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"};
    EXPECT_EQ(LongestConsec::longestConsec(arr, 1), "oocccffuucccjjjkkkjyyyeehh");
}