#include "SquareSums.h"

#include <cmath>
#include <vector>

uint32_t highest_square_root(uint32_t n)
{
    const double s = n;
    return static_cast<uint32_t>(std::pow(s + s - 1, 0.5));
}

std::list<uint32_t> possible_values(const std::list<uint32_t> &r, uint32_t v,
                                    const std::vector<uint32_t> &roots)
{
    std::list<uint32_t> p;
    for (auto i : roots)
    {
        if (auto n = i - v; i > v && std::find(r.begin(), r.end(), n) == r.end())
        {
            p.push_back(n);
        }
    }
    return p;
}

std::vector<uint32_t> generate_roots(uint32_t bound)
{
    std::vector<uint32_t> roots(bound - 1);
    std::generate(roots.begin(), roots.end(), [v = 2]() mutable {
        auto vr = v * v;
        ++v;
        return vr;
    });
    return roots;
}

std::list<uint32_t> permute(std::list<uint32_t> r, uint32_t n, const std::vector<uint32_t> &roots)
{
    if (r.size() == n)
    {
        return r;
    }
    auto fpv = possible_values(r, r.front(), roots);
    for (auto i : fpv)
    {
        std::list<uint32_t> ir = r;
        ir.push_front(i);
        ir = permute(ir, n, roots);
        if (ir.size() == n)
        {
            return ir;
        }
    }
    auto bpv = possible_values(r, r.back(), roots);
    for (auto j : bpv)
    {
        std::list<uint32_t> jr = r;
        jr.push_back(j);
        jr = permute(jr, n, roots);
        if (jr.size() == n)
        {
            return jr;
        }
    }
    return r;
}

std::list<uint32_t> generate(uint32_t n)
{
    auto hsr = highest_square_root(n);
    if (hsr <= 2)
    {
        return {};
    }
    std::vector<uint32_t> roots = generate_roots(hsr);
    std::list<uint32_t> r;
    r.push_back(1);
    r = permute(r, n, roots);
    return r.size() == n ? r : std::list<uint32_t>{};
}
