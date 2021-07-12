#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <array>
#include <memory.h>
#include <numeric>
#include <set>

using Row = std::array<int, 4>;
using Permutations = std::vector<Row>;
using Axis = std::array<Permutations, 4>;

bool check_permutation(const Row &p, int h, bool forward)
{
    if (!h)
    {
        return true;
    }
    size_t u = 0;
    int c = p[forward ? 0 : 3];
    for (size_t i = 1; i < 4; ++i)
    {
        auto v = p[forward ? i : 4 - i - 1];
        if (c < v)
        {
            c = v;
            ++u;
        }
    }
    return u == h - 1 && c == 4;
}

Permutations permutation(int hf, int hb)
{
    Permutations result;
    Row p;
    std::iota(p.begin(), p.end(), 1);
    do
    {
        if (!hf && !hb)
        {
            result.push_back(p);
            continue;
        }
        if (!check_permutation(p, hf, true) || !check_permutation(p, hb, false))
        {
            continue;
        }
        result.push_back(p);
    } while (std::next_permutation(p.begin(), p.end()));
    return result;
}

Permutations oncoming_intersection(const Permutations &a, const Permutations &b)
{
    Permutations r;
    for (const auto &pa : a)
    {
        for (const auto &pb : b)
        {
            if (std::equal(pa.begin(), pa.end(), pb.begin()))
            {
                r.push_back(pa);
            }
        }
    }
    return r;
}

void filter(Permutations &a, Permutations &b, size_t ai, size_t bi)
{
    std::set<size_t> ka;
    std::set<size_t> kb;
    for (size_t pa = 0; pa < a.size(); ++pa)
    {
        for (size_t pb = 0; pb < b.size(); ++pb)
        {
            if (a[pa][ai] == b[pb][bi])
            {
                ka.insert(pa);
                kb.insert(pb);
            }
        }
    }
    Permutations r;
    for (auto i : ka)
    {
        r.push_back(a[i]);
    }
    a = r;
    r.clear();
    for (auto i : kb)
    {
        r.push_back(b[i]);
    }
    b = r;
}

int **SolvePuzzle(int *clues)
{
    Axis rows;
    Axis columns;
    for (size_t i = 0; i < 4; ++i)
    {
        rows[i] = permutation(clues[15 - i], clues[i + 4]);
        columns[i] = permutation(clues[i], clues[11 - i]);
    }

    bool c = true;
    do
    {
        for (size_t i = 0; i < 4; ++i)
        {
            for (size_t j = 0; j < 4; ++j)
            {
                filter(rows[i], columns[j], j, i);
            }
        }
        c = std::any_of(rows.begin(), rows.end(),
                        [](const Permutations &p) { return p.size() != 1; });
    } while (c);

    int **result = new int *[4];

    for (size_t r = 0; r < 4; ++r)
    {
        result[r] = new int[4];
        memcpy(result[r], rows[r].data(), sizeof(int) * 4);
    }

    return result;
}

static int clues[][16] = {
    {2, 2, 1, 3, 2, 2, 3, 1, 1, 2, 2, 3, 3, 2, 1, 3},
    {0, 0, 1, 2, 0, 2, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0},
};

int outcomes[][4][4] = {
    {{1, 3, 4, 2}, {4, 2, 1, 3}, {3, 4, 2, 1}, {2, 1, 3, 4}},
    {{2, 1, 4, 3}, {3, 4, 1, 2}, {4, 2, 3, 1}, {1, 3, 2, 4}},
};

int equal(int **puzzle, int expected[4][4])
{
    if (!puzzle || !expected)
        return 0;
    for (int i = 0; i < 4; ++i)
        if (memcmp(puzzle[i], expected[i], 4 * sizeof(int)))
            return 0;
    return 1;
}

TEST(CodeWars, skyscrapers_permutation)
{
    auto p = permutation(0, 3);
    EXPECT_EQ(p.size(), 6);

    p = permutation(2, 0);
    EXPECT_EQ(p.size(), 11);

    p = permutation(3, 0);
    EXPECT_EQ(p.size(), 6);

    p = permutation(4, 0);
    EXPECT_EQ(p.size(), 1);
}

TEST(CodeWars, skyscrapers_intersection)
{
}

TEST(CodeWars, skyscrapers)
{
    // EXPECT_TRUE(equal(SolvePuzzle(clues[0]), outcomes[0]));
    EXPECT_TRUE(equal(SolvePuzzle(clues[1]), outcomes[1]));
}