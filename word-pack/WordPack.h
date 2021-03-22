#pragma once

#include <string>

std::string random_word();
uint32_t pack(const std::string &word);
std::string unpack(uint32_t word);