#include "resistor_color.h"

namespace resistor_color {
std::vector<std::pair<std::string, int>> bands{
    {"black", 0}, {"brown", 1}, {"red", 2},    {"orange", 3}, {"yellow", 4},
    {"green", 5}, {"blue", 6},  {"violet", 7}, {"grey", 8},   {"white", 9}};

int color_code(std::string key) {
    for (const auto &band : bands) {
        if (band.first == key) {
            return band.second;
        }
    }
    return -1;
}

std::vector<std::string> colors() {
    std::vector<std::string> result;

    for (auto &pair : bands) {
        result.push_back(pair.first);
    }

    return result;
}
} // namespace resistor_color
