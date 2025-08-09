#pragma once
#include <bitset>
#include <cstdint>
#include <string>
#include <vector>

namespace secret_handshake {
std::vector<std::string> commands(std::bitset<5> code);
} // namespace secret_handshake
