#include <cmath>
#include <string_view>

namespace binary {

int convert(const std::string_view number) {
    int result{};
    int power = number.size() - 1;
    for (auto &n : number) {
        if (n != '1' && n != '0')
            return 0;
        result += (n - '0') << power;
        power--;
    }
    return result;
}
} // namespace binary
