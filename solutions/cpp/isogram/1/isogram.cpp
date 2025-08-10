#include "isogram.h"
#include <set>
namespace isogram {
bool is_isogram(std::string s) {
    std::set<char> result;
    for (auto &c : s) {
        c = tolower(c);
        if (isalpha(c)) {
            if (result.find(c) == result.end())
                result.insert(c);
            else
                return false;
        }
    }
    return true;
}
} // namespace isogram
