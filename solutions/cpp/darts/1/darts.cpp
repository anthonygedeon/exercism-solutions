#include "darts.h"

#include <cmath>
#include <cstdint>

namespace darts {

const uint8_t INNER_CIRCLE_POINTS = 10;
const uint8_t MIDDLE_CIRCLE_POINTS = 5;
const uint8_t OUTER_CIRCLE_POINTS = 1;
const uint8_t OUTSIDE_CIRCLE_POINTS = 0;

int score(float x, float y) {
    float distance = hypot(x, y);
    if (distance <= 1)
        return INNER_CIRCLE_POINTS;
    if (distance <= 5)
        return MIDDLE_CIRCLE_POINTS;
    if (distance <= 10)
        return OUTER_CIRCLE_POINTS;

    return OUTSIDE_CIRCLE_POINTS;
}
} // namespace darts
