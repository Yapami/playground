#include <gtest/gtest.h>

#include <cmath>
#include <cstdint>
#include <cstring>
#include <string>

unsigned conv_base_3(unsigned n, unsigned max, unsigned *out)
{
    unsigned i = 0;
    while (i < max && n > 0)
    {
        out[i] = n % 3;
        n /= 3;
        i++;
    }
    return i;
}

unsigned binom_max_2(unsigned n, unsigned k)
{
    if (n < k)
        return 0;
    switch (n)
    {
    case 0:
    case 1:
        return 1;
    case 2:
        return 1 + (k == 1);

    // shouldn't happen
    default:
        return 0;
    }
}

unsigned lucas_3(unsigned len_n, const unsigned *dig_n, unsigned len_k, const unsigned *dig_k)
{
    // use modulo product rule:
    // prod[i] % 3 = ((prod[i - 1] % 3) * value[i])
    unsigned prod = 1;
    for (unsigned i = 0; i < len_n; i++)
    {
        unsigned n_i = dig_n[i];
        unsigned k_i = (i < len_k) ? dig_k[i] : 0;
        prod = (prod * binom_max_2(n_i, k_i)) % 3;
    }
    return prod % 3;
}

char int_2_char(int i)
{
    switch (i)
    {
    case 0:
        return 'R';
    case 1:
        return 'G';
    case 2:
        return 'B';

    // shouldn't happen
    default:
        return '\0';
    }
}

// convert from RGB to 012
unsigned char_2_int(char c)
{
    switch (c)
    {
    case 'R':
        return 0;
    case 'G':
        return 1;
    case 'B':
        return 2;

    // shouldn't happen
    default:
        return 3;
    }
}

char triangle(const std::string &input)
{
    const unsigned int MAX_N_LOG_3 = 11;
    unsigned sum = 0;
    const int n = input.length();

    // calculate digits of n - 1
    unsigned dig_n[MAX_N_LOG_3];
    unsigned len_n = conv_base_3(n - 1, MAX_N_LOG_3, dig_n);

    for (unsigned km1 = 0; km1 < n; km1++)
    {
        // calculate digits of k - 1
        unsigned dig_k[MAX_N_LOG_3];
        unsigned len_k = conv_base_3(km1, MAX_N_LOG_3, dig_k);

        // calculate C(n - 1, k - 1) mod 3
        unsigned Cnk_mod3 = lucas_3(len_n, dig_n, len_k, dig_k);

        // add using the modulo rule
        sum = (sum + Cnk_mod3 * char_2_int(input[km1])) % 3;
    }

    // value of (-1) ** (n - 1)
    // (no need for pow; just need to know if n is odd or even)
    int sign = (n % 2) * 2 - 1;

    // for negative numbers, must resolve the difference
    // between C's % operator and mathematical mod
    int sum_mod3 = (3 + (sign * (int)(sum % 3))) % 3;
    return int_2_char(sum_mod3);
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

    EXPECT_EQ(triangle("RBRGBRBGGRRRBGBBBGG"), 'G');
}