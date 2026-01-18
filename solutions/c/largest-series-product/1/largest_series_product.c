#include "largest_series_product.h"
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX(x, y) (x >= y ? x : y)

static bool contains_alpha(const char *digits) {
    while (*digits) {
        if (!isdigit(*digits))
            return true;
        digits++;
    }
    return false;
}

int64_t largest_series_product(char *digits, size_t span) {
    if (span > strlen(digits) || (int)span < 0 || contains_alpha(digits))
        return -1;

    int64_t largest = -INT64_MAX;
    char chunk[span];

    while (strlen(digits) >= span) {
        int product = 1;

        memcpy(chunk, digits, span * sizeof(char));

        for (size_t i = 0; i < span; i++)
            product *= chunk[i] - '0';

        largest = MAX(product, largest);

        digits++;
    }

    return largest;
}
