#include "pangram.h"

namespace pangram {

bool is_pangram(const std::string &pangram) {
    for (char alphabet = 'a'; alphabet <= 'z'; alphabet++) {
        if (pangram.find(alphabet) == pangram.npos &&
            pangram.find(toupper(alphabet)) == pangram.npos)
            return false;
    }
    return true;
}
} // namespace pangram
