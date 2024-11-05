#include <gtest/gtest.h>

#include <list>
#include <set>
#include <stack>
#include <string>

using Map = std::vector<std::vector<char>>;
using Pos = std::pair<size_t, size_t>;

Map load_map(const std::string &map)
{
    Map m;
    auto s = map.cbegin();
    auto e = s + map.find('\n');
    while (s != map.end())
    {
        m.push_back(std::vector<char>(std::distance(s, e)));
        std::copy(s, e, m.back().begin());
        if (e == map.end())
        {
            break;
        }
        s = std::next(e);
        e = std::find(s, map.end(), '\n');
    }
    return m;
}

std::list<Pos> get_available_directions(const Map &m, const Pos &p)
{
    std::list<Pos> r;
    if (p.second > 0 && m[p.second - 1][p.first] != 'W')
    {
        r.emplace_back(p.first, p.second - 1);
    }
    if (p.second < m.size() - 1 && m[p.second + 1][p.first] != 'W')
    {
        r.emplace_back(p.first, p.second + 1);
    }
    if (p.first > 0 && m[p.second][p.first - 1] != 'W')
    {
        r.emplace_back(p.first - 1, p.second);
    }
    if (p.first < m.front().size() - 1 && m[p.second][p.first + 1] != 'W')
    {
        r.emplace_back(p.first + 1, p.second);
    }
    return r;
}

bool path_finder(const std::string &maze)
{
    auto m = load_map(maze);
    Pos c{0, 0};
    const Pos end = {m.size() - 1, m.size() - 1};
    std::stack<Pos> s;
    std::set<Pos> visited;
    s.push(c);
    while (!s.empty())
    {
        c = s.top();
        s.pop();
        if (c == end)
        {
            return true;
        }
        visited.insert(c);
        auto dirs = get_available_directions(m, c);
        for (const auto d : dirs)
        {
            if (visited.find(d) == visited.end())
            {
                s.push(d);
            }
        }
    }
    return false;
}

TEST(PathFinder, examples)
{
    EXPECT_EQ(path_finder(".W.\n.W.\n..."), true);
    EXPECT_EQ(path_finder(".W.\n.W.\nW.."), false);
    EXPECT_EQ(path_finder("......\n......\n......\n......\n......\n......"), true);
    EXPECT_EQ(path_finder("......\n......\n......\n......\n.....W\n....W."), false);
}