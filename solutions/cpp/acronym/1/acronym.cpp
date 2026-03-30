#include "acronym.h"
#include <cctype>
#include <regex>

namespace acronym {
std::string acronym(const std::string &s) {
    std::string result{};

    const auto pattern = std::regex(R"((?:\b|^)[a-zA-Z])");

    auto words_begin = std::sregex_iterator(s.begin(), s.end(), pattern);
    auto words_end = std::sregex_iterator();

    while (words_begin != words_end) {
        std::smatch match = *words_begin;
        auto letter = match.str();
        result += toupper(letter.at(0));
        ++words_begin;
    }

    return result;
}
} // namespace acronym
