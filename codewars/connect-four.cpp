#include <gtest/gtest.h>

#include <string>
#include <vector>

enum class Color
{
    Red,
    Yellow,
    None,
};

const size_t COLUMNS = 7;
const size_t ROWS = 6;
const size_t SCORE = 3;

std::string who_is_winner(std::vector<std::string> pieces_position_list)
{
    std::vector<std::vector<Color>> grid(ROWS, std::vector<Color>(COLUMNS, Color::None));
    static const std::vector<std::pair<int8_t, int8_t>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};

    for (const auto turn : pieces_position_list)
    {
        const size_t column = turn.at(0) - 'A';
        const Color color = turn.at(2) == 'R' ? Color::Red : Color::Yellow;
        size_t row = 0;
        for (; row < ROWS - 1 && grid[row + 1][column] == Color::None; ++row)
            ;
        grid[row][column] = color;
        for (const auto &d : directions)
        {
            size_t count = 0;
            auto fc = column + d.second;
            auto fr = row + d.first;
            auto rc = column - d.second;
            auto rr = row - d.first;
            for (size_t i = 0; i < SCORE && fc < COLUMNS && fr < ROWS && grid[fr][fc] == color; ++i)
            {
                fc += d.second;
                fr += d.first;
                ++count;
            }
            for (size_t i = 0; i < SCORE && rc < COLUMNS && rr < ROWS && grid[rr][rc] == color; ++i)
            {
                rc -= d.second;
                rr -= d.first;
                ++count;
            }
            if (count == SCORE)
            {
                return color == Color::Red ? std::string{"Red"} : std::string{"Yellow"};
            }
        }
    }
    return "Draw";
}

TEST(CodeWars, connect_four)
{
    EXPECT_EQ(who_is_winner({"A_Red", "B_Yellow", "A_Red", "B_Yellow", "A_Red", "B_Yellow", "G_Red",
                             "B_Yellow"}),
              "Yellow");
    EXPECT_EQ(who_is_winner({"C_Yellow", "E_Red", "G_Yellow", "B_Red", "D_Yellow", "B_Red",
                             "B_Yellow", "G_Red", "C_Yellow", "C_Red", "D_Yellow", "F_Red",
                             "E_Yellow", "A_Red", "A_Yellow", "G_Red", "A_Yellow", "F_Red",
                             "F_Yellow", "D_Red", "B_Yellow", "E_Red", "D_Yellow", "A_Red",
                             "G_Yellow", "D_Red", "D_Yellow", "C_Red"}),
              "Yellow");
    EXPECT_EQ(who_is_winner({"A_Yellow", "B_Red", "B_Yellow", "C_Red", "G_Yellow", "C_Red",
                             "C_Yellow", "D_Red", "G_Yellow", "D_Red", "G_Yellow", "D_Red",
                             "F_Yellow", "E_Red", "D_Yellow"}),
              "Red");
    EXPECT_EQ(who_is_winner({"F_Yellow", "G_Red", "D_Yellow", "C_Red", "A_Yellow", "A_Red",
                             "E_Yellow", "D_Red", "D_Yellow", "F_Red", "B_Yellow", "E_Red",
                             "C_Yellow", "D_Red", "F_Yellow", "D_Red", "D_Yellow", "F_Red",
                             "G_Yellow", "C_Red", "F_Yellow", "E_Red", "A_Yellow", "A_Red",
                             "C_Yellow", "B_Red", "E_Yellow", "C_Red", "E_Yellow", "G_Red",
                             "A_Yellow", "A_Red", "G_Yellow", "C_Red", "B_Yellow", "E_Red",
                             "F_Yellow", "G_Red", "G_Yellow", "B_Red", "B_Yellow", "B_Red"}),
              "Red");
    EXPECT_EQ(who_is_winner({"C_Yellow", "B_Red", "B_Yellow", "E_Red", "D_Yellow", "G_Red",
                             "B_Yellow", "G_Red", "E_Yellow", "A_Red", "G_Yellow", "C_Red",
                             "A_Yellow", "A_Red", "D_Yellow", "B_Red", "G_Yellow", "A_Red",
                             "F_Yellow", "B_Red", "D_Yellow", "A_Red", "F_Yellow", "F_Red",
                             "B_Yellow", "F_Red", "F_Yellow", "G_Red", "A_Yellow", "F_Red",
                             "C_Yellow", "C_Red", "G_Yellow", "C_Red", "D_Yellow", "D_Red",
                             "E_Yellow", "D_Red", "E_Yellow", "C_Red", "E_Yellow", "E_Red"}),
              "Yellow");
}