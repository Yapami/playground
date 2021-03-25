#include "ReverseSentence.h"

#include <algorithm>
#include <random>

std::random_device rd;
std::mt19937 g(rd());

std::string random_word()
{
    std::string result;
    for (int i = 0; i < rd() % 10 + 1; ++i)
    {
        result.push_back((rd() % 26) + 'a');
    }
    return result;
}

std::string random_sentence()
{
    std::string s = random_word();
    for (int i = 0; i < rd() % 10 + 1; ++i)
    {
        s += ' ';
        s += random_word();
    }
    return s;
}

void reverse_sentence(std::string &s)
{
    std::reverse(s.begin(), s.end());
    const auto s_e = s.end();
    auto w_s = s.begin();
    for (auto w_e = w_s; w_s != s_e; w_s = w_e)
    {
        w_e = std::find(w_e, s_e, ' ');
        std::reverse(w_s, w_e);
        if (w_e != s_e)
        {
            ++w_e;
        }
    }
}