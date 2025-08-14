#include "acronym.h"
#include <regex>

namespace acronym {
std::string acronym(const std::string &s) {
    std::string result{};

    const auto pattern = std::regex(R"(([a-zA-Z']+))");

    auto iterator = std::sregex_iterator(s.begin(), s.end(), pattern);
    auto iterator_done = std::sregex_iterator();

    for (; iterator != iterator_done; iterator++) {
        auto letter = iterator->str().front();
        result += std::toupper(letter);
    }

    return result;
}
} // namespace acronym
