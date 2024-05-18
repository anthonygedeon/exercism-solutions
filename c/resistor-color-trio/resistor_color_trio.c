#include "resistor_color_trio.h"
#include <math.h>
#include <stdint.h>

resistor_value_t color_code(resistor_band_t bands[]) {
	resistor_value_t r;
	uint64_t value = (bands[0] * 10 + bands[1]) * (uint64_t)pow(10, bands[2]);

	r.unit  = OHMS;

	while (value > 1000) {
		value /= 1000;
		r.unit++;
	}

	r.value = (uint16_t)value;

	return r;
}
