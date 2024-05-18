#include "prime_factors.h"
#include <stdbool.h>
#include <stdio.h>

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]) {
	size_t length = 0;

	for (uint64_t i = 2; i <= n;) {
		if ((n % i) == 0) {
			n /= i;
			factors[length++] = i;
		} else {
			i++;
		}
	}
	
	return length;
}
