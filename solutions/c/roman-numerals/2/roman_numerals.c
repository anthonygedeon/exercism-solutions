#include "roman_numerals.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMERALS_MAX 9
#define ROMAN_MAX 13

static const char *romans[] = {
    [1000] = "M", [900] = "CM", [500] = "D", [400] = "CD", [100] = "C",
    [90] = "XC",  [50] = "L",   [40] = "XL", [10] = "X",   [9] = "IX",
    [5] = "V",    [4] = "IV",   [1] = "I"};

static const unsigned int numerals[] = {1000, 900, 500, 400, 100, 90, 50,
                                        40,   10,  9,   5,   4,   1};

char *to_roman_numeral(unsigned int number) {
    assert(number >= 1 && number < 4000);

    unsigned int n = number;
    unsigned int n_length = floor(log10(number)) + 1;

    char *result = (char *)calloc(NUMERALS_MAX + 1, sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    // Break the number into it's individual components preserving it's place
    // Ex. 1499 = { 1000, 400, 90, 9 }
    int tens = 1;
    size_t components_length = n_length - 1;
    unsigned int components[n_length];
    while (n != 0) {
        unsigned int digit = n % 10;
        components[components_length--] = digit * tens;
        n /= 10;
        tens *= 10;
    }

    for (size_t i = 0; i < n_length; i++) {
        unsigned int target = components[i];
        while (target != 0) {
            unsigned int minimum_distance = 0;
            for (size_t j = 0; j < ROMAN_MAX; j++) {
                if (target >= numerals[j]) {
                    minimum_distance = numerals[j];
                    break;
                }
            }
            strcat(result, romans[minimum_distance]);

            target -= minimum_distance;
        }
    }

    // If the component doesn't exist then the component must go through
    // repeated subtraction util a match from the S1 { M, D, C, L, X, V, I } |
    // S2 { IV, IX, XL, XC, CD, CM } exist .

    // Implement a `close` function:
    // Given a number X that is <= Y but closest to Y where Y ∈ ℕ
    //
    // The close function is simple to implement since S1 | S2 are already
    // sorted

    // Once the component is 0 then go to the next number

    printf("%s\n", result);
    return result;
}
