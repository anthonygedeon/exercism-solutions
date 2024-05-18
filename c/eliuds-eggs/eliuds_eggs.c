#include "eliuds_eggs.h"

/// Iterate each bit in `n` and increment when you encounter a `1`
unsigned int egg_count(unsigned int n) {
	unsigned int sum = 0;

	for (; n; n >>= 1) {
		if (n & 0x1) sum++;
	}

	return sum;
}
