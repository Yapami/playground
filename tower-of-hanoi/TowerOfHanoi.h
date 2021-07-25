#pragma once

#include <array>
#include <assert.h>
#include <limits>
#include <stack>
#include <stdint.h>

using DiskSize = uint32_t;
inline const DiskSize BOTTOM_DISK_SIZE = std::numeric_limits<uint32_t>::max();

enum class Peg : size_t
{
    From,
    To,
    Tmp,
    Total,
};

inline constexpr size_t peg(Peg p)
{
    assert(p <= Peg::Total);
    return static_cast<size_t>(p);
}

using Stack = std::stack<DiskSize>;
using Stacks = std::array<Stack, peg(Peg::Total)>;

class TowerOfHanoi
{
public:
    class SolutionValidator
    {
    public:
        virtual ~SolutionValidator() = default;
        virtual void validate_move(DiskSize from, DiskSize to) = 0;
        virtual void validate_solution(const Stacks &stacks) = 0;
    };

    void solve_recursively(DiskSize n, SolutionValidator &validator);
    void solve_iteratively(DiskSize n, SolutionValidator &validator);

protected:
    Stacks create_stacks(DiskSize n) const;
    DiskSize top(const Stacks &stacks, Peg p);
    void swap(Stacks &stacks, SolutionValidator &validator, Peg from, Peg to);

    void step(Stacks &stacks, DiskSize n, SolutionValidator &validator, Peg from, Peg to, Peg tmp);
    std::pair<Peg, Peg> pick_peg(const Stacks &stacks, Peg a, Peg b);
};