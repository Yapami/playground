#include "XorRiddler.h"

#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Not enough arguments, please specify file name" << std::endl;
        return 1;
    }
    std::fstream f;
    f.open(argv[1], std::ios::binary | std::ios::in);
    if (!f.is_open())
    {
        std::cerr << "Failed to open " << argv[1] << std::endl;
        return 1;
    }

    std::string s;
    std::getline(f, s);

    auto variants = decrypt(s);

    if (variants.empty())
    {
        std::cout << "Failed to find a key for the input";
        return 0;
    }

    std::cout << "Found the following variants: " << std::endl;
    for (const auto &variant : variants)
    {
        std::cout << variant << std::endl;
    }

    return 0;
}