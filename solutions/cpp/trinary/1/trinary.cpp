#include "trinary.h"
#include <cctype>
#include <cmath>
namespace trinary {
int to_decimal(std::string_view number) {
    int result{};
    int power = number.size() - 1;
    for (auto &n : number) {
        if (isalpha(n))
            return 0;
        result += (n - '0') * std::pow(3, power);
        power--;
    }
    return result;
}
} // namespace trinary
