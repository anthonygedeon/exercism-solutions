#include "eliuds_eggs.h"

namespace chicken_coop {
std::uint8_t positions_to_quantity(unsigned int number) {
    std::uint8_t total{0};
    while (number != 0) {
        if (number & 1) {
            total++;
            number >>= 1;
        }
    }
    return total;
}
} // namespace chicken_coop
