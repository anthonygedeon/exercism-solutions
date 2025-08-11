#include "rotational_cipher.h"
#include <iostream>

namespace rotational_cipher {
std::string rotate(const std::string &str, uint8_t rot) {
    std::string result{};

    for (auto &c : str) {
        if (isalpha(c)) {
            if (islower(c)) {
                char encrypted = (c + rot) % ('z' + 1);
                if (encrypted < 'a')
                    encrypted += 'a';
                result += encrypted;
            } else {
                char encrypted = (c + rot) % ('Z' + 1);
                if (encrypted < 'A')
                    encrypted += 'A';
                result += encrypted;
            }
        } else {
            result += c;
        }
    }

    return result;
}
} // namespace rotational_cipher
