#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    if (limit < 2)
        return 0;

    uint32_t result = 0;
    primes[0] = 2;
    for (size_t i = 1, j = 3; i < limit - 1; i++, j++)
        primes[i] = j;

    for (size_t i = 0; i < limit - 1; i++) {
        if (primes[i] == 0)
            continue;
        for (size_t j = i + 1; j < limit - 1; j++) {
            if (primes[j] == 0)
                continue;
            if (primes[j] % primes[i] == 0) {
                primes[j] = 0;
            }
        }
    }

    // prune all zeros
    if (limit >= max_primes)
        limit = max_primes + 1;
    size_t count = 0;
    uint32_t actual_primes[max_primes];
    for (uint32_t i = 0; i <= limit; i++) {
        if (primes[i] != 0) {
            result++;
            actual_primes[count++] = primes[i];
        }
    }

    for (size_t i = 0; i < result; i++)
        primes[i] = actual_primes[i];

    return result;
}
