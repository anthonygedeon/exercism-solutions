#include "diamond.h"
#include <stdlib.h>
#include <string.h>

char **make_diamond(const char letter) {
    unsigned int size = (letter - 'A') * 2 + 1;

    char **diamond = (char **)malloc(sizeof(char *) * size);

    for (size_t i = 0; i < size; i++) {
        diamond[i] = (char *)malloc(sizeof(char) * size);
        memset(diamond[i], ' ', sizeof(char) * size);
        diamond[i][size] = '\0';
    }

    unsigned int col = size / 2;
    unsigned int left = col, right = col;
    char c = 'A';
    for (int i = 0; i < (int)size; i++) {
        if (i >= (int)col) {
            diamond[i][left++] = c;
            diamond[i][right--] = c;
            c--;
        } else {
            diamond[i][left--] = c;
            diamond[i][right++] = c;
            c++;
        }
    }

    return diamond;
}

void free_diamond(char **diamond) {
    int size = (int)strlen(diamond[0]);
    for (int i = 0; i < size; i++) {
        free(diamond[i]);
    }
    free(diamond);
}
