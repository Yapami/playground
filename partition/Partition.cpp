#include "Partition.h"

template<int32_t DIR>
void arrange_pivots(std::vector<int32_t> &v, int32_t p, size_t &i)
{
    size_t n = DIR > 0 ? v.size() - 1 : 0;
    do
    {
        while (DIR > 0 ? v[i] <= p : v[i] >= p)
        {
            i += DIR;
        }
        if (v[n] == p)
        {
            std::swap(v[n], v[i]);
            i += DIR;
        }
        n -= DIR;
    } while (DIR > 0 ? n > i : n < i);
}

std::pair<size_t, size_t> partition(std::vector<int32_t> &v, int32_t p)
{
    assert(v.size() > 1);
    size_t i = 0;
    size_t j = v.size() - 1;
    while (i < j)
    {
        while (i < j && v[i] < p)
        {
            ++i;
        }
        while (i < j && v[j] > p)
        {
            --j;
        }
        if (i == j)
        {
            break;
        }
        std::swap(v[i++], v[j--]);
    }
    arrange_pivots<-1>(v, p, j);
    arrange_pivots<1>(v, p, i);
    return {j + 1, i};
}