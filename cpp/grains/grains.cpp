#include "grains.h"

#include <climits>
#include <cmath>

namespace grains {

        unsigned long long int square(std::int16_t num) {
            return std::pow(2, num-1);
        }

        unsigned long long int total() {
                return ULLONG_MAX;
        }
}  // namespace grains
