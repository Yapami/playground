#include <gtest/gtest.h>

#include <utility>
#include <vector>

using M = std::vector<std::vector<int>>;

std::optional<int> get(const M &f, size_t i, size_t j)
{
    if (i >= 10 || j >= 10)
    {
        return {};
    }
    return {f[j][i]};
}

bool wrong_diag(const M &f)
{
    ssize_t ii[] = {-1, 1, 1, -1};
    ssize_t ij[] = {-1, -1, 1, 1};
    for (size_t j = 0; j < 10; ++j)
    {
        for (size_t i = 0; i < 10; ++i)
        {
            if (!f[j][i])
            {
                continue;
            }
            for (size_t n = 0; n < 4; ++n)
            {
                if (auto c = get(f, i + ii[n], j + ij[n]); c && *c)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool validate_battlefield(std::vector<std::vector<int>> field)
{
    if (wrong_diag(field))
    {
        return false;
    }

    std::vector<size_t> ships(4);

    for (size_t j = 0; j < 10; ++j)
    {
        for (size_t i = 0; i < 10; ++i)
        {
            if (field[j][i] == 0 || field[j][i] == 2)
            {
                continue;
            }
            size_t sizei = 1;
            size_t sizej = 1;
            field[j][i] = 2;
            for (size_t n = 1; n + i < 10 && field[j][i + n] == 1; ++n)
            {
                field[j][i + n] = 2;
                ++sizei;
            }
            for (size_t n = 1; n + j < 10 && field[j + n][i] == 1; ++n)
            {
                field[j + n][i] = 2;
                ++sizej;
            }
            const auto l = std::max(sizei, sizej);
            if (l > 4)
            {
                return false;
            }
            ++ships[l - 1];
        }
    }

    return ships[0] == 4 && ships[1] == 3 && ships[2] == 2 && ships[3] == 1;
}

std::vector<std::vector<int>> SAMPLE = {
    std::vector<int>{1, 0, 0, 0, 0, 1, 1, 0, 0, 0}, std::vector<int>{1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
    std::vector<int>{1, 0, 1, 0, 1, 1, 1, 0, 1, 0}, std::vector<int>{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, std::vector<int>{0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, std::vector<int>{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    std::vector<int>{0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

TEST(Battleship, sample)
{
    EXPECT_TRUE(validate_battlefield(SAMPLE));
}