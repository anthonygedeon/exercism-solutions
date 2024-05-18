#include "sum_of_multiples.h"
#include <stddef.h>
#include <stdio.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit) {
	unsigned int sum = 0;
	
	for (unsigned int i = 0; i < limit; i++) {
		for (size_t j = 0; j < number_of_factors; j++) {
			unsigned int factor = factors[j];
			if (factor != 0 && i % factor == 0) {
				sum += i;
				break;
			}
		}
	}
	
	return sum;
}
