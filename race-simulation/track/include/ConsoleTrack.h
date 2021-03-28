#pragma once

#include "Track.h"

class ConsoleTrack : public Track
{
public:
    ConsoleTrack();
    ~ConsoleTrack() override;

    void set_length(int32_t l) override;
    void update(const std::vector<CompetitorPosition> &positions) override;
    void finish(const std::vector<Winner> &winners) override;

protected:
    char character(CompetitorId id) const;
    void draw_markup(const char *text, char c, int pos, int height, int lines_count);
    void write_text(const char *text, int v);

private:
    int32_t m_length;
    int32_t m_height;
};