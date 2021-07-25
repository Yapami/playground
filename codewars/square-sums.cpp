#include <gtest/gtest.h>

#include <cmath>
#include <list>
#include <map>
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
    std::generate(roots.rbegin(), roots.rend(), [v = 2]() mutable {
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

struct Sum
{
    int a;
    int b;
    bool operator<(const Sum &other) const
    {
        return a < other.a;
    }
};

std::vector<int> square_sums_row(int n)
{
    auto hsr = highest_square_root(n);
    if (hsr <= 2)
    {
        return {};
    }
    std::vector<int> roots = generate_roots(hsr);
    int min_pow = static_cast<int>(std::sqrt(n));
    std::vector<Sum> v;
    int chosen_root = 0;
    for (auto root : roots)
    {
        v.clear();
        for (int i = 1; i <= (n >> 1); ++i)
        {
            int a = root - i;
            if (a > n ||
                std::find_if(v.begin(), v.end(), [a](const Sum &s) { return s.b == a; }) != v.end())
            {
                break;
            }
            v.emplace_back(i, a);
        }
        if (v.size() == n >> 1)
        {
            chosen_root = root;
            break;
        }
    }

    if (v.size() != n >> 1)
    {
        return {};
    }

    // std::vector<int> result;
    // for (auto i : v)
    // {
    //     result.push_back(i.a);
    //     result.push_back(i.b);
    // }
    // if (n & 1)
    // {
    //     auto sum = (n >> 1) + result.front() + 1;
    //     if (std::find(roots.begin(), roots.end(), sum) != roots.end())
    //     {
    //         result.push_back(n >> 1);
    //     }
    //     else
    //     {
    //         sum = (n >> 1) + result.back() + 1;
    //         if (std::find(roots.begin(), roots.end(), sum) != roots.end())
    //         {
    //             result.insert(result.begin(), sum);
    //         }
    //     }
    // }

    return result;
}

TEST(SquareSums, case_15)
{
    const uint32_t n = 25;
    auto r = square_sums_row(n);
    EXPECT_FALSE(r.empty());
    auto roots = generate_roots(highest_square_root(n));

    // auto i = r.begin();
    // auto j = std::next(i);

    // for (; j != r.end(); ++i, ++j)
    // {
    //     EXPECT_TRUE(std::find(roots.begin(), roots.end(), *i + *j) != roots.end());
    // }
}