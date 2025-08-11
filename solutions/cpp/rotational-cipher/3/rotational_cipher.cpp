#include "rotational_cipher.h"
#include <algorithm>
#include <iostream>
#include <numeric>

namespace rotational_cipher {

// NOTE int(*)(int) doesn't work as a type for the capitalize declaraction? Why
std::string rotate(const std::string &str, uint8_t rot) {
    std::string encryption{"abcdefghijklmnopqrstuvwxyz"};
    std::rotate(encryption.begin(), encryption.begin() + rot, encryption.end());

    std::string result{};
    result.reserve(str.length());
    for (auto &c : str) {
        if (isalpha(c)) {
            auto capitalize = std::islower(c)
                                  ? static_cast<int (*)(int)>(std::tolower)
                                  : static_cast<int (*)(int)>(std::toupper);
            result += capitalize(encryption.at(tolower(c) - 'a'));
            continue;
        }
        result += c;
    }

    return result;
}
} // namespace rotational_cipher
