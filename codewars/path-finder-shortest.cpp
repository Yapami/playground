#include <gtest/gtest.h>

#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>

using Map = std::vector<std::vector<char>>;
using Pos = std::pair<size_t, size_t>;
struct Path
{
    Pos p;
    int l;
};

Map load_map(const std::string &map)
{
    Map m;
    auto s = map.cbegin();
    auto p = map.find('\n');
    auto e = s + (p == std::string::npos ? 1 : p);
    while (s != map.end())
    {
        auto d = std::distance(s, e);
        m.push_back(std::vector<char>(d));
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

int path_finder(const std::string &maze)
{
    auto m = load_map(maze);
    Path c{{0, 0}, 0};
    Path end = {{m.size() - 1, m.size() - 1}, std::numeric_limits<int>::max()};
    std::stack<Path> s;
    std::map<Pos, int> visited;
    s.push(c);
    while (!s.empty())
    {
        c = s.top();
        s.pop();
        auto c_it = visited.find(c.p);
        if (c_it != visited.end() && c.l < c_it->second)
        {
            c_it->second = c.l;
        }
        else if (c_it == visited.end())
        {
            visited[c.p] = c.l;
        }
        if (c.p == end.p && c.l < end.l)
        {
            end.l = c.l;
        }
        auto dirs = get_available_directions(m, c.p);
        for (const auto d : dirs)
        {
            auto v_it = visited.find(d);
            if (v_it == visited.end() || (v_it != visited.end() && v_it->second > c.l + 1))
            {
                s.push({d, c.l + 1});
            }
        }
    }
    return end.l < std::numeric_limits<int>::max() ? end.l : -1;
}

TEST(PathFinder, examples)
{
    EXPECT_EQ(path_finder(".W.\n.W.\n..."), 4);
    EXPECT_EQ(path_finder(".W.\n.W.\nW.."), -1);
    EXPECT_EQ(path_finder("......\n......\n......\n......\n......\n......"), 10);
    EXPECT_EQ(path_finder("......\n......\n......\n......\n.....W\n....W."), -1);
}