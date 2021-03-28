#include "ConsoleTrack.h"

#include <ncurses.h>

#include <map>
#include <sstream>

ConsoleTrack::ConsoleTrack()
    : m_length(0)
    , m_height(0)
{
    initscr();
    raw();
    noecho();
    curs_set(0);
}

ConsoleTrack::~ConsoleTrack()
{
    refresh();
    endwin();
}

void ConsoleTrack::set_length(int32_t l)
{
    m_length = l;
}

void ConsoleTrack::update(const std::vector<CompetitorPosition> &positions)
{
    m_height = positions.size() + 2;
    clear();
    draw_markup("START", '|', 2, m_height, 1);
    draw_markup("FINISH", '|', 2 + m_length, m_height, 2);
    move(0, 10);
    for (int i = 10; i < m_length; i += 10)
    {
        auto s = std::to_string(i);
        draw_markup(s.c_str(), '.', 2 + i, m_height, 1);
    }

    for (size_t i = 0; i < positions.size(); ++i)
    {
        const auto &p = positions[i];
        mvaddch(i + 2, p.second + 2, character(p.first));
    }
    refresh();
}

void ConsoleTrack::finish(const std::vector<Winner> &winners)
{
    std::stringstream ss;
    ss << "THE WINNERS: ";
    for (const auto &w : winners)
    {
        ss << w.second << " ";
    }
    write_text(ss.str().c_str(), m_height + 1);
    write_text("Press SPACE to restart", m_height + 2);
    refresh();
}

char ConsoleTrack::character(CompetitorId id) const
{
    static std::map<CompetitorId, char> chars = {
        {CompetitorId::Tortoise, 'T'}, {CompetitorId::Hare, 'H'}, {CompetitorId::Robo, 'R'}};
    return chars[id];
}

void ConsoleTrack::draw_markup(const char *text, char c, int pos, int height, int lines_count)
{
    move(0, pos - ((strlen(text) - 1) >> 1));
    printw(text);
    for (int l = 0; l < lines_count; ++l)
    {
        move(1, pos + l);
        vline(c, height);
    }
}

void ConsoleTrack::write_text(const char *text, int v)
{
    move(v, (m_length >> 1) - (strlen(text) >> 1));
    printw(text);
}
