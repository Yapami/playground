#pragma once

#include <vector>

const uint8_t STAR = 10;
const uint8_t HASH = 11;

using Key = uint8_t;
using Distance = float;
using Distances = std::vector<std::vector<Distance>>;

Distances distances();

Distance fastest_input(const std::vector<Key> &number);