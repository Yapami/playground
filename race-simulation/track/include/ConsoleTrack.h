#pragma once

#include "Track.h"

class ConsoleTrack : public Track
{
public:
    ConsoleTrack(int32_t length);
    ~ConsoleTrack() override;

    void update(const std::vector<CompetitorPosition> &positions) override;
    void finish(const std::vector<Winner> &winners) override;

protected:
    char character(CompetitorId id) const;
    void draw_markup(const char *text, char c, int pos, int height, int lines_count);

private:
    int32_t m_length;
    int32_t m_height;
};