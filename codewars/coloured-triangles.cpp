#include <gtest/gtest.h>

#include <map>
#include <stdint.h>
#include <string>
#include <thread>
#include <vector>

std::unordered_map<uint32_t, char> PREDEFINED;

char sum(char a, char b)
{
    if (a == b)
    {
        return a;
    }
    if (a == 'R' || b == 'R')
    {
        return a == 'G' || b == 'G' ? 'B' : 'G';
    }
    return 'R';
}

char generate(const char *f, size_t count)
{
    std::vector<std::vector<char>> b(2, std::vector<char>(count));
    size_t it = 0;
    memcpy(b[it].data(), f, count);
    for (size_t l = count - 1; l; --l)
    {
        for (std::size_t i = 0; i < l; ++i)
        {
            const auto c = b[it][i];
            const auto n = b[it][i + 1];
            b[1 - it][i] = sum(c, n);
        }
        // b[1 - it][l] = 0;
        it = !it;
    }
    return b[it][0];
}

char generate(const char *f)
{
    char b[2][4] = {0};
    *reinterpret_cast<int32_t *>(b[0]) = *reinterpret_cast<const int32_t *>(f);
    size_t it = 0;

    for (size_t l = sizeof(int32_t) - 1; l; --l)
    {
        for (std::size_t i = 0; i < l; ++i)
        {
            const auto c = *(b[it] + i);
            const auto n = *(b[it] + i + 1);
            b[1 - it][i] = sum(c, n);
        }
        // b[1 - it][l] = 0;
        it = !it;
    }
    return b[it][0];
}

char triangle(const std::string &row)
{
    auto l = row.length();
    size_t b_idx = 0;
    size_t i = 0;
    std::vector<std::vector<char>> b(2, std::vector<char>((l >> 2) + 3));
    {
        const char *p = row.data();
        const auto end = p + l;
        for (; end - p >= sizeof(int32_t); ++i)
        {
            int32_t v = *reinterpret_cast<const int32_t *>(p);
            auto c = PREDEFINED[v];
            if (!c)
            {
                c = generate(p);
            }
            b[b_idx][i] = c;
            p += sizeof(int32_t);
        }
        if (end - p)
        {
            auto c = generate(p, end - p);
            b[b_idx][i] = sum(b[b_idx][i], c);
            ++i;
            b[b_idx][i] = c;
        }
        ++i;
    }

    for (l = i, b_idx = !b_idx; l; b_idx = !b_idx)
    {
        char *p = b[1 - b_idx].data();
        const char *e = p + l;
        for (i = 0; l - i >= sizeof(int32_t); ++i)
        {
            int32_t v = *reinterpret_cast<const int32_t *>(p + i);
            auto c = PREDEFINED[v];
            if (!c)
            {
                c = generate(p);
            }
            b[b_idx][i] = c;
            p += sizeof(int32_t);
        }
        b[b_idx][i] = generate(p, e - p);
        ++i;
        l = i;
    }
    return b[b_idx].front();
}

TEST(ColouredTriangles, basic_tests)
{
    // EXPECT_EQ(triangle("B"), 'B');
    // EXPECT_EQ(triangle("GB"), 'R');
    // EXPECT_EQ(triangle("RRR"), 'R');
    // EXPECT_EQ(triangle("RGBG"), 'B');
    EXPECT_EQ(triangle("RBRGBRB"), 'G');
    // RB RG BR B
    // G G B R G G
    // G RGB G
    // BB RR
    // B G R
    // R B
    // G

    // EXPECT_EQ(triangle("RBRGBRBGGRRRBGBBBGG"), 'G');
    // GGBRGG
}