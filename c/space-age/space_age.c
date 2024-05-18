#include "space_age.h"

#define PLANET(NAME) \
	if (NAME == planet) { \
		return day / NAME ## _ORBITAL; \
	} \

const float MERCURY_ORBITAL = 87.97;
const float VENUS_ORBITAL = 224.7;
const float EARTH_ORBITAL = 365.249;
const float MARS_ORBITAL = 686.98;
const float JUPITER_ORBITAL = 4332.59;
const float SATURN_ORBITAL = 10756.0;
const float URANUS_ORBITAL = 30687.0;
const float NEPTUNE_ORBITAL = 60190.0;

float age(planet_t planet, int64_t seconds) {
	float day = ((seconds / 60.0) / 60.0) / 24.0;
	PLANET(MERCURY);
	PLANET(VENUS);
	PLANET(EARTH);
	PLANET(MARS);
	PLANET(JUPITER);
	PLANET(SATURN);
	PLANET(URANUS);
	PLANET(NEPTUNE);
	return -1; 
}
