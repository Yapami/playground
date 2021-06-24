#pragma once

#include <set>
#include <string>

class Set
{
public:
    std::string process(const std::string &in);

protected:
    std::tuple<char, uint32_t, uint32_t> parse_input(const std::string &in);

    void insert(uint32_t i);
    void remove(uint32_t i);
    bool has(uint32_t i);
    uint64_t sum(uint32_t l, uint32_t r);

    uint32_t invalid_value() const;

private:
    std::set<uint32_t> m_v;
    uint32_t INVALID_VALUE = std::numeric_limits<uint32_t>::max();
};