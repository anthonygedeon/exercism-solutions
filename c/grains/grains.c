#include "grains.h"

/**
 * Square the result by the power of N - 1.
 * @param {uint8_t} - power of 2 
 * @return uint64_t - base 2 computation given N
 */
uint64_t square(uint8_t index) {
    // Instead of including the math header file and generating more assembly
    // code, I opt to use the << operator because all we're doing is going up
    // based on the power of 2 all we need to do is make sure that the most
    // significant bit is always on.
    return (index < 1 || index > 64) ? 0 : 1ul<<(index-1);
}

/**
 * Return the total uint64_t maximum.
 */
uint64_t total(void) { 
      return ~(uint64_t)0;
}

