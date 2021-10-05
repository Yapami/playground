#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <numeric>

void bonAppetit(std::vector<int> bill, int k, int b)
{
    // (3 + 2 + 9) / 2
    int e = std::accumulate(bill.begin(), bill.end(), 0) - bill[k];
    int d = b - (e / 2);
    if (d > 0)
    {
        std::cout << d << std::endl;
    }
    else
    {
        std::cout << "Bon Appetit" << std::endl;
    }
}

TEST(BonAppetit, sample)
{
    bonAppetit({3, 10, 2, 9}, 1, 12);
    bonAppetit({3, 10, 2, 9}, 1, 7);
}