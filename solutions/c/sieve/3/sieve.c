#include "sieve.h"
#include <stdio.h>
#include <stdlib.h> // Required for qsort()

int compare_numbers(const void *a, const void *b);

// Custom comparison function for qsort
int compare_numbers(const void *a, const void *b) {
    uint32_t int_a = *((const uint32_t *)a);
    uint32_t int_b = *((const uint32_t *)b);

    // Rule 1: If both are zero, their order doesn't matter relative to each
    // other (return 0 or compare as equal)
    if (int_a == 0 && int_b == 0) {
        return 0;
    }
    // Rule 2: If int_a is zero, it should come *after* int_b (return positive
    // value)
    if (int_a == 0) {
        return 1;
    }
    // Rule 3: If int_b is zero, it should come *after* int_a (return negative
    // value)
    if (int_b == 0) {
        return -1;
    }
    // Rule 4: If neither is zero, sort in standard ascending order (smallest to
    // largest)
    return int_a - int_b;
}

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    uint32_t result = 0;

    int primes_length = 0;
    for (uint32_t i = 2; i <= limit; i++)
        primes[primes_length++] = i;

    for (uint32_t i = 0; i < limit; i++) {
        uint32_t curr = primes[i];
        for (uint32_t j = i + 1; j < limit - 1; j++) {
            uint32_t next = primes[j];
            if (curr == 0 || next == 0)
                continue;

            if (next % curr == 0)
                primes[j] = 0;
        }
    }

    qsort(primes, limit, sizeof(uint32_t), compare_numbers);

    for (size_t i = 0; i < max_primes; i++) {
        if (primes[i])
            result++;
    }

    return result;
}
