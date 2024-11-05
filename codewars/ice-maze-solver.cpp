#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <cmath>
#include <list>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

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

std::pair<Pos, Pos> ends(const Map &m)
{
    std::pair<Pos, Pos> r;
    for (size_t y = 0; y < m.size(); ++y)
    {
        for (size_t x = 0; x < m.front().size(); ++x)
        {
            if (m[y][x] == 'S')
            {
                r.first = {x, y};
            }
            if (m[y][x] == 'E')
            {
                r.second = {x, y};
            }
        }
    }
    return r;
}

std::list<char> get_available_directions(const Map &m, const Pos &p, const Pos &prev)
{
    std::list<char> r;
    if (p.second > 0 && m[p.second - 1][p.first] != '#' && prev.second >= p.second)
    {
        r.push_back('u');
    }
    if (p.second < m.size() - 1 && m[p.second + 1][p.first] != '#' && prev.second <= p.second)
    {
        r.push_back('d');
    }
    if (p.first > 0 && m[p.second][p.first - 1] != '#' && prev.first >= p.first)
    {
        r.push_back('l');
    }
    if (p.first < m.front().size() - 1 && m[p.second][p.first + 1] != '#' && prev.first <= p.first)
    {
        r.push_back('r');
    }
    return r;
}

Pos slide(const Map &m, const Pos &c, char direction)
{
    Pos r = c;
    static const std::unordered_map<char, Pos> dirs = {
        {'u', {0, -1}}, {'d', {0, 1}}, {'l', {-1, 0}}, {'r', {1, 0}}};
    const auto &d = dirs.at(direction);
    Pos nc = {r.first + d.first, r.second + d.second};
    while (nc.first < m.front().size() && nc.second < m.size() &&
           m.at(nc.second).at(nc.first) == ' ')
    {
        r = nc;
        nc = {r.first + d.first, r.second + d.second};
    }
    auto [s, e] = ends(m);
    if (nc.first < m.front().size() && nc.second < m.size())
    {
        if (m.at(nc.second).at(nc.first) == 'x' || nc == s || nc == e)
        {
            r = nc;
        }
    }
    return r;
}

size_t distance(const Pos &a, const Pos &b)
{
    auto d = std::max(a.first, b.first) - std::min(a.first, b.first) +
             std::max(a.second, b.second) - std::min(a.second, b.second);
    return d;
}

std::pair<size_t, std::vector<char>> restore_path(const std::map<Pos, Pos> &v, Pos c)
{
    std::vector<char> r;
    auto f = v.at(c);
    size_t l = 0;
    do
    {
        if (f.second == c.second)
        {
            char m = f.first < c.first ? 'r' : 'l';
            r.push_back(m);
        }
        else
        {
            char m = f.second < c.second ? 'd' : 'u';
            r.push_back(m);
        }
        l += distance(f, c);
        c = f;
        f = v.at(c);
    } while (f != c);
    std::reverse(r.begin(), r.end());
    return {l, r};
}

std::vector<char> ice_maze_solver(const std::string &map)
{
    std::vector<char> result;
    std::map<Pos, Pos> visited;
    std::list<std::tuple<char, Pos, Pos>> nodes;
    auto m = load_map(map);
    auto [c, end] = ends(m);
    auto directions = get_available_directions(m, c, c);
    for (auto dir : directions)
    {
        nodes.emplace_back(dir, c, c);
    }

    while (!nodes.empty())
    {
        auto current = nodes.front();
        nodes.pop_front();
        c = std::get<1>(current);
        auto cc = std::get<2>(current);
        auto pc = visited.find(c);
        if (pc == visited.end())
        {
            visited[c] = cc;
        }
        if (pc != visited.end() && pc->second != cc)
        {
            auto cp = restore_path(visited, cc);
            auto pp = restore_path(visited, pc->second);
            if (cp.second.size() <= pp.second.size() &&
                cp.first + distance(c, cc) < pp.first + distance(c, pc->second))
            {
                visited[c] = cc;
            }
        }
        if (c == end)
        {
            continue;
        }
        directions = get_available_directions(m, c, visited[c]);
        for (auto dir : directions)
        {
            auto nc = slide(m, c, dir);
            if (visited.find(nc) == visited.end())
            {
                nodes.emplace_back(dir, nc, c);
            }
        }
    }

    if (visited.find(end) != visited.end())
    {
        result = restore_path(visited, end).second;
    }
    return result;
}

TEST(IceMazeSolver, simple_spiral)
{
    std::string map = "#  x  #   #  ## ###   \n"
                      "  # x ### #       # # \n"
                      "  #####  #  #     x#  \n"
                      "  #x         #        \n"
                      "  # ##     # ##  #    \n"
                      " x #   x    ##    #   \n"
                      "#   ##  S ##     #    \n"
                      "  # #   x# #        # \n"
                      "        #   ####  #   \n"
                      "      #       ##  # ##\n"
                      "x      x           x  \n"
                      "  x  #   #        #   \n"
                      "## # #   #    #    E  \n"
                      "# #  # ##x       ##   \n"
                      "#         ## #        \n"
                      "#    #   x          ##\n"
                      "#    #   # x ##    # #\n"
                      "  #  #          #     \n"
                      "x #     #  #    #    #";
    EXPECT_THAT(ice_maze_solver(map),
                testing::ContainerEq(std::vector<char>({'l', 'd', 'r', 'd', 'r', 'd'})));

    //                 0123456789ABCDEF
    // std::string map = "x  x   #  #          ##   \n" // 0
    //                   "             #  ##        \n" // 1
    //                   "#   #     #      #   # #  \n" // 2
    //                   " ###    ##S  # #   #     #\n" // 3
    //                   " #     #          x       \n" // 4
    //                   "  #  # #  x       #     # \n" // 5
    //                   "      #     #    #   #    \n" // 6
    //                   "    #    ##       # x     \n" // 7
    //                   "  #  x  x             # ##\n" // 8
    //                   "  x        E  #  #   #    \n" // 9
    //                   " #    # #  #  #   x    ## \n" // 10
    //                   "  #     x   ##     x#     \n"
    //                   "#   #    #  #   ##  #     \n"
    //                   "  #           #   # # #  #\n"
    //                   "#### #           #    #   \n"
    //                   "      #   #   # #x x    # \n"
    //                   "     x ##        #  ##    \n"
    //                   "##         #          ##  \n"
    //                   " ##  #       ##  #   x    \n"
    //                   "     ##   #  # ##x  # #   \n"
    //                   "          #  x #   #      \n"
    //                   "         # ##   #   # x ##\n"
    //                   "    # ##   #  #   # #    #\n"
    //                   "  #                 #   #x\n"
    //                   "  ###        ##    x x    \n"
    //                   "         #       ###  x#  \n"
    //                   "  ##     #      #   #   x \n"
    //                   " #     # #    x  #     x  \n"
    //                   " ##x  #   x #        #  # \n"
    //                   "##        #            #  \n"
    //                   " x    # #           x     \n"
    //                   "####  #   #x##    #       \n"
    //                   "    # # x    #   x #      \n"
    //                   "  #   #x x         x   #  ";
    // EXPECT_THAT(ice_maze_solver(map),
    //             testing::ContainerEq(std::vector<char>({'d', 'd', 'r', 'd'})));

    // std::string map = "    x \n"
    //                   "  #   \n"
    //                   "   E  \n"
    //                   " #    \n"
    //                   "    # \n"
    //                   "S    #";
    // EXPECT_THAT(ice_maze_solver(map),
    //             testing::ContainerEq(std::vector<char>({'u', 'r', 'd', 'l', 'u', 'r'})));
    // auto map = "    E \n"
    //            "     #\n"
    //            "      \n"
    //            "# #   \n"
    //            "    # \n"
    //            " #  S ";
    // EXPECT_THAT(ice_maze_solver(map),
    //             testing::ContainerEq(std::vector<char>({'l', 'u', 'r', 'u', 'r'})));
    //          0123456789ABCD
    // auto map = "        #     \n" // 0
    //            "   #          \n" // 1
    //            "         #    \n" // 2
    //            " #            \n" // 3
    //            "#       #     \n" // 4
    //            "             #\n" // 5
    //            "      #       \n" // 6
    //            "  #          E\n" // 7
    //            "             #\n" // 8
    //            "       #      \n" // 9
    //            "     #   #    \n" // A
    //            "              \n" // B
    //            "#############S";  // C
    // EXPECT_THAT(ice_maze_solver(map),
    //             testing::ContainerEq(std::vector<char>({'u', 'l', 'u', 'r', 'u', 'r', 'd', 'l',
    //             'u',
    //                                                     'l', 'd', 'r', 'd', 'r', 'u', 'r'})));
    //          0123456789
    // auto map = "x     x # \n" // 0
    //            "     #  # \n" // 1
    //            " ##x E    \n" // 2
    //            " #    x   \n" // 3
    //            " #  #     \n" // 4
    //            " #  x    x\n" // 5
    //            "x       # \n" // 6
    //            "     #  # \n" // 7
    //            " #x  x   x\n" // 8
    //            " #     x  \n" // 9
    //            " #      # \n" // 10
    //            " # x  x # \n" // 11
    //            " #x#xx#x# \n" // 12
    //            " #x#xx### \n" // 13
    //            "x xxxxxx x\n" // 14
    //            "# xxSxxx #";  // 15
    // EXPECT_THAT(ice_maze_solver(map),
    //             testing::ContainerEq(
    //                 std::vector<char>({'u', 'u', 'u', 'u', 'l', 'u', 'r', 'd', 'l', 'u', 'r'})));

    // auto map = "       #  ###xx##   #    \n"
    //            "#   #x     ##   #   x    \n"
    //            "     x              x    \n"
    //            " x        x  #x  #       \n"
    //            "  x    x   #   #     x   \n"
    //            "         # ##    # # x   \n"
    //            "     x #        #        \n"
    //            "  x#  #             # #x#\n"
    //            "  #           #   # S#  #\n"
    //            "     #   #x#   #         \n"
    //            "## # # #x  ##      x  E  \n"
    //            " #  x  #    #    ##      \n"
    //            "#   #    # ##    x #     \n"
    //            " x #     #    #      #   \n"
    //            "   ##  #    #x   #       \n"
    //            "                  #    # ";
    // EXPECT_THAT(ice_maze_solver(map), testing::ContainerEq(std::vector<char>({'l', 'd', 'r'})));
}
