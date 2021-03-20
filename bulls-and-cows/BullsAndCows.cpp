#include <algorithm>
#include <random>

std::vector<uint8_t> values()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::vector<uint8_t> v(9);
    std::generate(v.begin(), v.end(), [n = 1]() mutable { return n++; });
    std::shuffle(v.begin(), v.end(), g);
    v.resize(4);
    return v;
}
