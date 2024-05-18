#include "binary.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

/**
 * Convert Base 2 to Base 10.
 * 
 * @param input the binary number as a char string.
 * @return the decimal equivalent of the binary number.
 */
int convert(const char *input) {
    int sum = 0;
    for (size_t i = strlen(input); i > 0; i--) {
        if (input[i-1] != *"0" && input[i-1] != *"1") {
            return INVALID;
        }

        size_t rev_i = strlen(input)-i; // count from 0 to len(input)
        if (input[i-1] == *"0") {
            continue;
        }
        sum += pow(2, rev_i);
    }
    return sum;
}
