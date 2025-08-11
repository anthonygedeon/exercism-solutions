#pragma once

#include <cstdint>
#include <string>

namespace rotational_cipher {
std::string rotate(const std::string &str, uint8_t rot);
} // namespace rotational_cipher
