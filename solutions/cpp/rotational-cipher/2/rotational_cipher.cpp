#include "rotational_cipher.h"
#include <algorithm>
#include <iostream>
#include <numeric>

namespace rotational_cipher {

std::string rotate(const std::string &str, uint8_t rot) {
    std::string encryption{"abcdefghijklmnopqrstuvwxyz"};
    std::rotate(encryption.begin(), encryption.begin() + rot, encryption.end());

    std::string result{};
    for (auto &c : str) {
        if (isalpha(c)) {
            if (islower(c))
                result += tolower(encryption.at(c - 'a'));
            else
                result += toupper(encryption.at(tolower(c) - 'a'));
        } else {
            result += c;
        }
    }

    return result;
}
} // namespace rotational_cipher
