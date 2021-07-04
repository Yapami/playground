#include "SquareSums.h"

#include <cmath>
#include <list>
#include <vector>

int highest_square_root(int n)
{
    const double s = n;
    return static_cast<int>(std::pow(s + s - 1, 0.5));
}

std::list<int> possible_values(const std::list<int> &r, int n, int v, const std::vector<int> &roots)
{
    std::list<int> p;
    for (auto root : roots)
    {
        if (auto i = root - v; i <= n && root > v && std::find(r.begin(), r.end(), i) == r.end())
        {
            p.push_back(i);
        }
    }
    return p;
}

std::vector<int> generate_roots(int bound)
{
    std::vector<int> roots(bound - 1);
    std::generate(roots.begin(), roots.end(), [v = 2]() mutable {
        auto vr = v * v;
        ++v;
        return vr;
    });
    return roots;
}

std::list<int> permute(std::list<int> r, int n, const std::vector<int> &roots)
{
    if (r.size() == n)
    {
        return r;
    }
    auto fpv = possible_values(r, n, r.front(), roots);
    for (auto i : fpv)
    {
        std::list<int> ir = r;
        ir.push_front(i);
        ir = permute(ir, n, roots);
        if (ir.size() == n)
        {
            return ir;
        }
    }
    auto bpv = possible_values(r, n, r.back(), roots);
    for (auto j : bpv)
    {
        std::list<int> jr = r;
        jr.push_back(j);
        jr = permute(jr, n, roots);
        if (jr.size() == n)
        {
            return jr;
        }
    }
    return r;
}

std::vector<int> square_sums_row(int n)
{
    auto hsr = highest_square_root(n);
    if (hsr <= 2)
    {
        return {};
    }
    std::vector<int> roots = generate_roots(hsr);
    std::list<int> r;
    r.push_back(1);
    r = permute(r, n, roots);
    std::vector<int> result;
    std::copy(r.begin(), r.end(), std::back_inserter(result));
    return result.size() == n ? result : std::vector<int>{};
}
