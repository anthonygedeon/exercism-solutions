#include "secret_handshake.h"
#include <algorithm>

namespace secret_handshake {

std::vector<std::string> commands(std::bitset<5> code) {
    std::vector<std::string> result{};
    if (code[0])
        result.push_back("wink");
    if (code[1])
        result.push_back("double blink");
    if (code[2])
        result.push_back("close your eyes");
    if (code[3])
        result.push_back("jump");
    if (code[4])
        std::reverse(result.begin(), result.end());
    return result;
}

} // namespace secret_handshake
