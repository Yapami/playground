#include "TowerOfHanoi.h"

#include <utility>
#include <vector>

void TowerOfHanoi::solve_recursively(DiskSize n, SolutionValidator &validator)
{
    auto stacks = create_stacks(n);
    step(stacks, n, validator, Peg::From, Peg::To, Peg::Tmp);
    validator.validate_solution(stacks);
}

void TowerOfHanoi::solve_iteratively(DiskSize n, SolutionValidator &validator)
{
    static std::vector<std::pair<Peg, Peg>> moves_even{
        {Peg::From, Peg::Tmp}, {Peg::From, Peg::To}, {Peg::Tmp, Peg::To}};
    static std::vector<std::pair<Peg, Peg>> moves_odd{
        {Peg::From, Peg::To}, {Peg::From, Peg::Tmp}, {Peg::Tmp, Peg::To}};
    const auto &moves = n & 1 ? moves_odd : moves_even;
    auto stacks = create_stacks(n);
    for (auto m = moves.begin(); stacks[peg(Peg::To)].size() != n;
            m = std::next(m) == moves.end() ? moves.begin() : std::next(m))
    {
        auto [from, to] = pick_peg(stacks, m->first, m->second);
        swap(stacks, validator, from, to);
    }
    validator.validate_solution(stacks);
}

Stacks TowerOfHanoi::create_stacks(DiskSize n) const
{
    Stacks stacks;
    for (DiskSize i = n; i; stacks[peg(Peg::From)].push(i--))
        ;
    return stacks;
}

DiskSize TowerOfHanoi::top(const Stacks &stacks, Peg p)
{
    return stacks[peg(p)].empty() ? BOTTOM_DISK_SIZE : stacks[peg(p)].top();
}

void TowerOfHanoi::swap(Stacks &stacks, SolutionValidator &validator, Peg from, Peg to)
{
    auto f_v = top(stacks, from);
    auto t_v = top(stacks, to);
    validator.validate_move(f_v, t_v);
    stacks[peg(from)].pop();
    stacks[peg(to)].push(f_v);
}

void TowerOfHanoi::step(Stacks &stacks, DiskSize n, SolutionValidator &validator, Peg from, Peg to,
                        Peg tmp)
{
    if (!n)
    {
        return;
    }

    step(stacks, n - 1, validator, from, tmp, to);
    swap(stacks, validator, from, to);
    step(stacks, n - 1, validator, tmp, to, from);
}

std::pair<Peg, Peg> TowerOfHanoi::pick_peg(const Stacks &stacks, Peg a, Peg b)
{
    return top(stacks, a) < top(stacks, b) ? std::pair{a, b} : std::pair{b, a};
}