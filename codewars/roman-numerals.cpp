#include <string>

#include <gtest/gtest.h>

std::string solution(int number)
{
    // convert the number to a roman numeral
    std::vector<int> d(4, 0);
    const std::vector<std::string> p{"", "0", "00", "000", "01", "1", "10", "100", "1000", "02"};
    const std::vector<std::string> r{"MMM", "CDM", "XLC", "IVX"};
    int i = 0;
    for (int m = 1000; m; m /= 10)
    {
        d[i++] = number / m;
        number %= m;
    }
    std::string s;
    for (i = 0; i < d[0]; ++i)
    {
        s.push_back('M');
    }

    for (int n = 1; n < d.size(); ++n)
    {
        auto m = p[d[n]];
        std::replace(m.begin(), m.end(), '0', r[n][0]);
        std::replace(m.begin(), m.end(), '1', r[n][1]);
        std::replace(m.begin(), m.end(), '2', r[n][2]);
        s += m;
    }
    return s;
}

TEST(CodeWars, roman_numerals)
{
    EXPECT_EQ(solution(182), "CLXXXII");
    EXPECT_EQ(solution(1990), "MCMXC");
    EXPECT_EQ(solution(1875), "MDCCCLXXV");
}
