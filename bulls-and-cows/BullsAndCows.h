#pragma once

#include <stdint.h>
#include <string>
#include <vector>

std::vector<uint8_t> values();
bool process_user_input(const std::string &s, std::vector<uint8_t> &digits);