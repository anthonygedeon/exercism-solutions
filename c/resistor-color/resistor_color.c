#include "resistor_color.h"
#include <stdlib.h>


resistor_band_t *colors() {
	static resistor_band_t bands[10];
	for (resistor_band_t i = BLACK; i <= WHITE; i++) {
		bands[i] = i; 
	}
	return bands;
}

int color_code(resistor_band_t color) {
	return color;
}
