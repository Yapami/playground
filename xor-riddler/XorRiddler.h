#pragma once

#include <string>
#include <vector>

bool validate_chars(const std::string &s);
std::string encrypt(const std::string &in, char key);
std::vector<std::string> decrypt(const std::string &in);
