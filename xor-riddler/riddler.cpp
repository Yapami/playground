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
    f.open(argv[1], std::ios::binary | std::ios::out);
    if (!f.is_open())
    {
        std::cerr << "Failed to open " << argv[1] << std::endl;
        return 1;
    }

    std::string s;
    for (bool ok = false; !ok;)
    {
        std::getline(std::cin, s);
        ok = validate_chars(s);
        if (!ok)
        {
            std::cerr << "Input string doesn't match requirements, please use 'a'-'z' or ' '"
                      << std::endl;
        }
    }

    std::srand(std::time(0));
    uint8_t key = std::rand() % 256;

    std::cout << "Encrypting string with key " << static_cast<uint32_t>(key) << std::endl;
    std::string encrypted = encrypt(s, key);

    f << encrypted.data();

    return 0;
}