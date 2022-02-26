#include "armstrong_numbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/**
 *
 */
bool is_armstrong_number(int candidate) {
    int sum = 0;
    char buffer[10];
    snprintf(buffer, 10, "%d", candidate);
    
    for (size_t i = 0; i < strlen(buffer); i++) {
        const char *c = buffer[i];
        if (isdigit(c)) {
                sum += (int)pow(atoi(c), strlen(buffer));
        }
    }

    return sum == candidate;
}
