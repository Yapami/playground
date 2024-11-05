#include <gtest/gtest.h>

#include <set>
#include <stack>
#include <string>
#include <vector>

using Pos = std::pair<size_t, size_t>;

struct Path
{
    Pos pos;
    size_t length;
    std::set<Pos> visited;
};

std::vector<Pos> collect_candidates(const std::vector<std::vector<char>> &board, const Pos &pos,
                                    char next_char, const std::set<Pos> &visited)
{
    std::vector<Pos> result;
    size_t sx = pos.second > 0 ? pos.second - 1 : 0;
    size_t sy = pos.first > 0 ? pos.first - 1 : 0;
    size_t ex = std::min(pos.second + 2, board.front().size());
    size_t ey = std::min(pos.first + 2, board.size());
    for (size_t row = sy; row < ey; ++row)
    {
        for (size_t column = sx; column < ex; ++column)
        {
            if (pos.first == row && pos.second == column)
            {
                continue;
            }
            if (board[row][column] == next_char && visited.find({row, column}) == visited.end())
            {
                result.emplace_back(row, column);
            }
        }
    }
    return result;
}

bool check_word(const std::vector<std::vector<char>> &board, const std::string &word)
{
    std::vector<Pos> starts;
    for (size_t row = 0; row < board.size(); ++row)
    {
        for (size_t column = 0; column < board.front().size(); ++column)
        {
            if (board[row][column] == word.front())
            {
                starts.emplace_back(row, column);
            }
        }
    }
    for (const auto &s : starts)
    {
        std::stack<Path> q;
        q.push({s, word.length(), {}});
        while (!q.empty())
        {
            auto c = q.top();
            q.pop();
            if (c.length == 1)
            {
                return true;
            }
            c.visited.insert(c.pos);
            auto next_char = word[word.length() - c.length + 1];
            auto candidates = collect_candidates(board, c.pos, next_char, c.visited);
            for (const auto &candidate : candidates)
            {
                q.push({candidate, c.length - 1, c.visited});
            }
        }
    }
    return false;
}

TEST(BuggleWordChecker, sample)
{
    std::vector<std::vector<char>> test_board = {
        {'E', 'A', 'R', 'A'}, {'N', 'L', 'E', 'C'}, {'I', 'A', 'I', 'S'}, {'B', 'Y', 'O', 'R'}};

    EXPECT_EQ(check_word(test_board, "C"), true);
    EXPECT_EQ(check_word(test_board, "ENE"), false);
    EXPECT_EQ(check_word(test_board, "EAR"), true);
    EXPECT_EQ(check_word(test_board, "EARS"), false);
    EXPECT_EQ(check_word(test_board, "BAILER"), true);
    EXPECT_EQ(check_word(test_board, "RSCAREIOYBAILNEA"), true);
    EXPECT_EQ(check_word(test_board, "CEREAL"), false); // Valid guesses can't overlap themselves
    EXPECT_EQ(check_word(test_board, "ROBES"), false);  // Valid guesses have to be adjacent
    EXPECT_EQ(check_word(test_board, "BAKER"), false);  // All the letters have to be in the board
    EXPECT_EQ(check_word(test_board, "CARS"), false);
}