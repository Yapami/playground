#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <array>
#include <memory.h>
#include <numeric>
#include <set>
#include <vector>

const size_t N = 6;

using Row = std::array<int, N>;
using Permutations = std::vector<Row>;
using Axis = std::array<Permutations, N>;

bool check_permutation(const Row &p, int h, bool forward)
{
    if (!h)
    {
        return true;
    }
    size_t u = 0;
    int c = p[forward ? 0 : N - 1];
    for (size_t i = 1; i < N; ++i)
    {
        auto v = p[forward ? i : N - i - 1];
        if (c < v)
        {
            c = v;
            ++u;
        }
    }
    return u == h - 1 && c == N;
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

std::vector<std::vector<int>> SolvePuzzle(const std::vector<int> &clues)
{
    Axis rows;
    Axis columns;
    for (size_t i = 0; i < N; ++i)
    {
        rows[i] = permutation(clues[N * 4 - i - 1], clues[i + N]);
        columns[i] = permutation(clues[i], clues[N * 3 - i - 1]);
    }

    bool c = true;
    do
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < N; ++j)
            {
                filter(rows[i], columns[j], j, i);
            }
        }
        c = std::any_of(rows.begin(), rows.end(),
                        [](const Permutations &p) { return p.size() != 1; });
    } while (c);

    std::vector<std::vector<int>> result(N, std::vector<int>(N));

    for (size_t r = 0; r < N; ++r)
    {
        std::copy(rows[r].front().begin(), rows[r].front().end(), result[r].begin());
    }

    return result;
}

// static int clues[][N * 4] = {
//     {2, 2, 1, 3, 2, 2, 3, 1, 1, 2, 2, 3, 3, 2, 1, 3},
//     {0, 0, 1, 2, 0, 2, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0},
// };

// int outcomes[][N][N] = {
//     {{1, 3, 4, 2}, {4, 2, 1, 3}, {3, 4, 2, 1}, {2, 1, 3, 4}},
//     {{2, 1, 4, 3}, {3, 4, 1, 2}, {4, 2, 3, 1}, {1, 3, 2, 4}},
// };

static std::vector<std::vector<int>> clues = {
    {3, 2, 2, 3, 2, 1, 1, 2, 3, 3, 2, 2, 5, 1, 2, 2, 4, 3, 3, 2, 1, 2, 2, 4},
    {0, 0, 0, 2, 2, 0, 0, 0, 0, 6, 3, 0, 0, 4, 0, 0, 0, 0, 4, 4, 0, 3, 0, 0},
    {0, 3, 0, 5, 3, 4, 0, 0, 0, 0, 0, 1, 0, 3, 0, 3, 2, 3, 3, 2, 0, 3, 1, 0}};

static std::vector<std::vector<std::vector<int>>> expected = {{{2, 1, 4, 3, 5, 6},
                                                               {1, 6, 3, 2, 4, 5},
                                                               {4, 3, 6, 5, 1, 2},
                                                               {6, 5, 2, 1, 3, 4},
                                                               {5, 4, 1, 6, 2, 3},
                                                               {3, 2, 5, 4, 6, 1}},
                                                              {{5, 6, 1, 4, 3, 2},
                                                               {4, 1, 3, 2, 6, 5},
                                                               {2, 3, 6, 1, 5, 4},
                                                               {6, 5, 4, 3, 2, 1},
                                                               {1, 2, 5, 6, 4, 3},
                                                               {3, 4, 2, 5, 1, 6}},
                                                              {{5, 2, 6, 1, 4, 3},
                                                               {6, 4, 3, 2, 5, 1},
                                                               {3, 1, 5, 4, 6, 2},
                                                               {2, 6, 1, 5, 3, 4},
                                                               {4, 3, 2, 6, 1, 5},
                                                               {1, 5, 4, 3, 2, 6}}};

int equal(const std::vector<std::vector<int>> &puzzle,
          const std::vector<std::vector<int>> &expected)
{
    if (puzzle.empty() || expected.empty())
        return 0;
    for (int i = 0; i < N; ++i)
        if (memcmp(puzzle[i].data(), expected[i].data(), N * sizeof(int)))
            return 0;
    return 1;
}

TEST(CodeWars, skyscrapers)
{
    EXPECT_TRUE(equal(SolvePuzzle(clues[0]), expected[0]));
    EXPECT_TRUE(equal(SolvePuzzle(clues[1]), expected[1]));
}