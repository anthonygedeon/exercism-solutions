#include "darts.h"
#include "math.h"
#include <stdint.h>

const uint8_t INNER_CIRCLE_POINTS   = 10;
const uint8_t MIDDLE_CIRCLE_POINTS  = 5;
const uint8_t OUTER_CIRCLE_POINTS   = 1;
const uint8_t OUTSIDE_CIRCLE_POINTS = 0;

// Compute the distance between two points (0, 0) and the dart (X, Y)
__attribute((always_inline)) inline uint8_t score(coordinate_t vec) {
	float distance = hypot(vec.x, vec.y);
	if (distance <= 1) { return INNER_CIRCLE_POINTS; } 
	if (distance <= 5) { return MIDDLE_CIRCLE_POINTS; } 
	if (distance <= 10) { return OUTER_CIRCLE_POINTS; } 
	return OUTSIDE_CIRCLE_POINTS;
}
