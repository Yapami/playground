#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

void almostSorted(std::vector<int> arr)
{
    if (std::is_sorted(arr.begin(), arr.end()))
    {
        std::cout << "yes" << std::endl;
    }
    size_t i = 0;
    size_t j = arr.size() - 1;
    while (i < j && arr[i] < arr[i + 1])
    {
        ++i;
    }
    while (j > i && arr[j] > arr[j - 1])
    {
        --j;
    }
    std::vector<int> r(j - i + 1);
    std::copy(arr.rbegin() + arr.size() - j - 1, arr.rbegin() + arr.size() - i, r.begin());
    if (std::is_sorted(arr.rbegin() + arr.size() - j - 1, arr.rbegin() + arr.size() - i))
    {
        std::cout << "yes" << std::endl;
        std::cout << "reverse " << i + 1 << ' ' << j + 1 << std::endl;
        return;
    }
}

TEST(AlmostSorted, sample)
{
    int b;
    constexpr int a = 4;
    std::cout << &a << " " << &b;
    const std::vector<int> A1 = {1, 5, 4, 3, 2, 6};
    almostSorted(A1);
    const std::vector<int> A2 = {3, 1, 2};
    almostSorted(A2);
    const std::vector<int> A3 = {4, 2};
    almostSorted(A3);
}