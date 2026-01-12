#include "pascals_triangle.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int fact(int n) {
    int sum = 1;
    for (int i = 1; i <= n; i++)
        sum *= i;
    return sum;
}

void free_triangle(uint8_t **triangle, size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

uint8_t **create_triangle(size_t rows) {
    uint8_t **triangle = (uint8_t **)malloc(sizeof(uint8_t *) * fmax(1, rows));
    if (triangle == NULL) {
        // TODO
    }

    for (size_t i = 0; i < fmax(1, rows); i++) {
        triangle[i] = (uint8_t *)malloc(sizeof(uint8_t) * fmax(1, rows));
        memset(triangle[i], 0, sizeof(uint8_t) * fmax(1, rows));
        if (triangle == NULL) {
            // TODO
        }
    }

    for (size_t n = 0; n < rows; n++) {
        // Notice that each row has n + 1 elements
        for (size_t k = 0; k < n + 1; k++) {
            uint8_t entry = fact(n) / (fact(k) * fact(n - k));
            triangle[n][k] = entry;
        }
    }

    return triangle;
}
