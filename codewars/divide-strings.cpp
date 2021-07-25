#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

using SV = std::vector<std::string>;

int subtract(std::string &a, const std::string &b)
{
    char rest = 0;
    std::string result;
    auto a_it = a.begin();
    auto b_it = b.begin();
    while (*a_it == '0')
    {
        ++a_it;
    }
    if (*a_it < *b_it)
    {
        ++a_it;
    }
    // if (*a_it == *b_it)
    a_it += b.length() - 1;
    b_it += b.length() - 1;
    auto dist = std::distance(a_it, a.end());
    if (dist <= 0)
    {
        return -1;
    }
    char carry = 0;
    for (; b_it >= b.begin(); --b_it, --a_it)
    {
        char sub = (*a_it - '0') - (*b_it - '0') - carry;
        if (sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        result.push_back(sub + '0');
    }
    if (carry)
    {
        --(*a_it);
    }
    std::copy(result.rbegin(), result.rend(), std::next(a_it));
    // a.erase(0, a.find_first_not_of('0'));

    return dist;
}

SV divide_strings(std::string a, std::string b)
{
    std::string d;
    auto d_it = d.begin();
    std::ptrdiff_t s = a.length() - b.length() + 1;
    auto l = a.length();
    // auto ns = s - 1;
    do
    {
        auto ns = subtract(a, b);
        if (ns < 0)
        {
            break;
        }
        for (; ns <= s; --s)
        {
            d.push_back('0');
        }
        ++d.back();
    } while (true);
    for (; s; --s)
    {
        d.push_back('0');
    }

    a.erase(0, a.find_first_not_of('0'));
    d.erase(0, d.find_first_not_of('0'));
    return {d.empty() ? "0" : d, a.empty() ? "0" : a};
}

TEST(divide_strings, substract)
{
    // {
    //     std::string a{"17"};
    //     std::string b{"3"};
    //     EXPECT_TRUE(subtract(a, b));
    //     EXPECT_EQ(a, "14");
    // }
    // {
    //     std::string a{"219"};
    //     std::string b{"11"};
    //     subtract(a, b);
    //     EXPECT_EQ(a, "109");
    // }
    // {
    //     std::string a{"219"};
    //     std::string b{"41"};
    //     subtract(a, b);
    //     EXPECT_EQ(a, "178");
    // }
    // {
    //     std::string a{"8589934597"};
    //     std::string b{"4294967298"};
    //     const uint64_t e = 8589934597ull - 4294967298ull;
    //     subtract(a, b);
    //     EXPECT_EQ(a, std::to_string(e));
    // }
    // {
    //     std::string a{"113"};
    //     std::string b{"5"};
    //     const uint64_t e = 63;
    //     subtract(a, b);
    //     EXPECT_EQ(a, std::to_string(e));
    // }
}

TEST(CodeWars, divide_strings)
{
    // EXPECT_THAT(divide_strings("0", "5"), testing::ContainerEq(SV{"0", "0"}));
    // EXPECT_THAT(divide_strings("4", "5"), testing::ContainerEq(SV{"0", "4"}));
    // EXPECT_THAT(divide_strings("10", "2"), testing::ContainerEq(SV{"5", "0"}));
    // EXPECT_THAT(divide_strings("20", "3"), testing::ContainerEq(SV{"6", "2"}));
    // EXPECT_THAT(divide_strings("60", "5"), testing::ContainerEq(SV{"12", "0"}));
    EXPECT_THAT(divide_strings("219", "11"), testing::ContainerEq(SV{"19", "10"}));
    // EXPECT_THAT(divide_strings("729", "9"), testing::ContainerEq(SV{"81", "0"}));
    // EXPECT_THAT(divide_strings("1000", "10"), testing::ContainerEq(SV{"100", "0"}));
    // EXPECT_THAT(divide_strings("600001", "100"), testing::ContainerEq(SV{"6000", "1"}));
    // EXPECT_THAT(divide_strings("8589934597", "2"), testing::ContainerEq(SV{"4294967298", "1"}));
}