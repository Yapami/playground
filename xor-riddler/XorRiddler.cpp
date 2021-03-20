#include "XorRiddler.h"

bool validate_chars(const std::string &s)
{
    return std::all_of(s.begin(), s.end(),
                       [](const char c) { return std::islower(c) || c == ' '; });
}

inline std::string apply_key(const std::string &in, char key)
{
    std::string result;
    std::transform(in.begin(), in.end(), std::back_inserter(result),
                   [key](const char c) { return c ^ key; });
    return result;
}

std::string encrypt(const std::string &in, char key)
{
    return apply_key(in, key);
}

std::vector<std::string> decrypt(const std::string &in)
{
    std::vector<std::string> result;
    for (int i = 0; i <= 255; ++i)
    {
        std::string s = apply_key(in, static_cast<char>(i));
        if (validate_chars(s))
        {
            result.push_back(s);
        }
    }
    return result;
}