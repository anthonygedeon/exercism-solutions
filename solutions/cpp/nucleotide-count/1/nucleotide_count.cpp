#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {
std::map<char, int> count(const std::string s) {
    std::map<char, int> result{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
    for (auto &c : s) {
        auto findit = result.find(c);
        if (findit != result.end()) {
            result[c]++;
        } else {
            throw std::invalid_argument("Error: not a valid nucleotide");
        }
    }

    return result;
}
} // namespace nucleotide_count
