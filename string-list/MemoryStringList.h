#pragma once

#include "StringList.h"

#include <list>

class MemoryStringList : public StringList
{
public:
    // StringList
    bool insert(const std::string &s, uint32_t pos) override;
    bool remove(uint32_t pos) override;
    const std::string &string(uint32_t pos) override;
};