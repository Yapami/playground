#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

int designerPdfViewer(const std::vector<int> &h, const std::string &word)
{
    int m = 0;
    for (char c : word)
    {
        m = std::max(h[c - 'a'], m);
    }
    return m * word.length();
}

TEST(DesignerPdfViewer, sample)
{
    EXPECT_EQ(
        designerPdfViewer(
            {1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7}, "zaba"),
        28);
}