#include "resistor_color_duo.h"

namespace resistor_color_duo {
std::vector<std::string> bands{"black", "brown", "red",    "orange", "yellow",
                               "green", "blue",  "violet", "grey",   "white"};

int color_code(std::string key) {
    for (size_t i = 0; i < bands.size(); i++) {
        if (bands.at(i) == key)
            return i;
    }
    return -1;
}

int value(const std::vector<std::string> &bands) {
    return (10 * color_code(bands.at(0))) + color_code(bands.at(1));
}

} // namespace resistor_color_duo
