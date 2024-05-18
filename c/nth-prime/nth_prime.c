#include "nth_prime.h"
#include <stdio.h>
#include <stdbool.h>

#define MAX 200000

static bool is_prime(uint32_t n) {
	if (n < 1) return false; 
	
	for (uint32_t i = 2; i < n - 1; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;

}

uint32_t nth(uint32_t n) {
	if (n <= 0) return 0;

	uint32_t primes[MAX] = { 0 };
	uint32_t count = 0;

	for (uint32_t i = 0; i <= MAX; i++) {
		if (is_prime(i)) {
			primes[count++] = i;
		}
	}

	return primes[n];
}
