#include "crypto_square.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void normalize(char *dest, const char *src) {
    while (*src) {
        if (isalnum(*src))
            *dest++ = tolower(*src);
        src++;
    }
}

char *ciphertext(const char *input) {
    char *message = (char *)calloc(strlen(input), sizeof(char));

    normalize(message, input);

    /* if (strlen(message) == 1) { */
    /*     return message; */
    /* } */

    int r = 0, c = 0;
    int limit = (int)strlen(message);
    for (int row = 1; row <= limit; row++) {
        for (int col = 1; col <= limit; col++) {
            if (row * col >= limit && col >= row && col - row <= 1) {
                r = row;
                c = col;
                goto here;
            }
        }
    }
here:;

    char *buffer[r];
    for (int i = 0; i < r; i++) {
        int total_size = strlen(message);
        buffer[i] = calloc(c, sizeof(char));
        memset(buffer[i], ' ', c);
        memcpy(buffer[i], message, total_size < c ? total_size : c);
        message += c;
    }

    /* for (int i = 0; i < r; i++) { */
    /*     printf("%s\n", buffer[i]); */
    /* } */
    char *m = (char *)malloc(1024 * sizeof(char));

    size_t count = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            m[count++] = buffer[j][i];
        }
        m[count++] = ' ';
    }

    m[count - 1] = '\0';

    return m;
}
