#include "SetOperations.h"

#include <numeric>
#include <sstream>

std::tuple<char, uint32_t, uint32_t> Set::parse_input(const std::string &in)
{
    std::stringstream s(in);
    char op;
    uint32_t a;
    uint32_t b;
    s >> op;
    if (s >> a; s.fail())
    {
        a = INVALID_VALUE;
    }
    if (op == 's')
    {
        if (s >> b; s.fail())
        {
            b = INVALID_VALUE;
        }
    }
    return {op, a, b};
}

std::string Set::process(const std::string &in)
{
    if (in.empty())
    {
        return {};
    }

    auto [op, v, r] = parse_input(in);
    if (v == INVALID_VALUE)
    {
        return {};
    }

    switch (op)
    {
    case '+':
        insert(v);
        break;
    case '-':
        remove(v);
        break;
    case '?':
        return has(v) ? "Found" : "Not found";
    case 's':
        if (r == INVALID_VALUE)
        {
            return {};
        }
        return std::to_string(sum(v, r));
    default:
        break;
    }
    return {};
}

void Set::insert(uint32_t i)
{
    m_v.insert(i);
}

void Set::remove(uint32_t i)
{
    m_v.erase(i);
}

bool Set::has(uint32_t i)
{
    return m_v.find(i) != m_v.end();
}

uint64_t Set::sum(uint32_t l, uint32_t r)
{
    auto from = m_v.lower_bound(l);
    auto to = m_v.upper_bound(r);
    return std::accumulate(from, to, 0u);
}

uint32_t Set::invalid_value() const
{
    return INVALID_VALUE;
}
