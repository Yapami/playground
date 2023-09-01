#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

int workbook(int problems_per_page, const std::vector<int>& arr)
{
    int result = 0;
    int current_page = 1;
    for (int problems_per_chapter : arr)
    {
        int pages_per_chapter = (problems_per_chapter + problems_per_page - 1) / problems_per_page;
        int start_page = current_page;
        for (int i = 0; i < pages_per_chapter; ++i)
        {
            int ps = problems_per_page * i + 1;
            int pe = problems_per_page * (i + 1);
            if (current_page - start_page + 1 == pages_per_chapter)
            {
                int page_space_left = pages_per_chapter * problems_per_page - problems_per_chapter;
                pe -= page_space_left;
            }
            if (current_page >= ps && current_page <= pe)
            {
                ++result;
            }
            ++current_page;
        }
    }

    return result;
}

TEST(LisasWorkbook, sample)
{
    EXPECT_EQ(workbook(3, {4, 2, 6, 1, 10}), 4);
}