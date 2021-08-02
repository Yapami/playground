#include <gtest/gtest.h>

#include <regex>
#include <sstream>
#include <string>

std::string value_to_str(int v, int i)
{
    if (v == 0)
    {
        return {};
    }
    if (i == 3)
    {
        std::string r = v > 0 ? "+" : "";
        return r + std::to_string(v);
    }
    std::string sv = std::to_string(v);
    if (v == 1)
    {
        return i == 0 ? "" : "+";
    }
    if (v == -1)
    {
        return "-";
    }
    if (i == 0)
    {
        return sv;
    }
    return v > 0 ? std::string("+") + sv : sv;
}

std::string quadratic_builder(const std::string &expression)
{
    std::string e = expression;
    std::regex re("[-]?\\d*[a-z]?");
    auto end = std::sregex_iterator();
    int values[4];
    size_t v_index = 0;
    char variable = 0;
    for (auto i = std::sregex_iterator(e.begin(), e.end(), re); i != end; ++i)
    {
        auto s = i->str();
        if (s.empty())
        {
            continue;
        }
        if (std::none_of(s.begin(), s.end(), [](char c) { return std::isdigit(c); }))
        {
            values[v_index] = s.front() == '-' ? -1 : 1;
        }
        else
        {
            values[v_index] = std::atoi(s.c_str());
        }
        ++v_index;
        if (!variable && std::isalpha(s.back()))
        {
            variable = s.back();
        }
    }

    std::stringstream ss;
    auto a = values[0] * values[2];
    auto b = values[0] * values[3] + values[1] * values[2];
    auto c = values[1] * values[3];
    if (a)
    {
        ss << value_to_str(a, 0) << variable << "^2";
    }
    if (b)
    {
        ss << value_to_str(b, 1) << variable;
    }
    if (c)
    {
        ss << value_to_str(c, 2);
    }
    return ss.str();
}

TEST(quadratic_builder, samples)
{
    EXPECT_EQ(quadratic_builder("(x+2)(x+3)"), "x^2+5x+6");
    EXPECT_EQ(quadratic_builder("(x-2)(x+7)"), "x^2+5x-14");
    EXPECT_EQ(quadratic_builder("(3y+2)(y+5)"), "3y^2+17y+10");
    EXPECT_EQ(quadratic_builder("(-h-7)(4h+3)"), "-4h^2-31h-21");
}