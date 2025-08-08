#include "etl.h"
#include <cctype>

namespace etl {

std::map<char, int> transform(std::map<int, std::vector<char>> old_format) {
    std::map<char, int> new_format;

    for (auto const &[score, letters] : old_format) {
        for (auto &l : letters) {
            new_format[std::tolower(l)] = score;
        }
    }

    return new_format;
}

} // namespace etl
