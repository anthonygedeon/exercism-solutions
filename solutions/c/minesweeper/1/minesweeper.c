#include "minesweeper.h"
#include <stdlib.h>
#include <string.h>

struct offset {
    int row, col;
} offsets[] = {
    {0, 1},   // right
    {0, -1},  // left
    {1, 0},   // down
    {-1, 0},  // up
    {1, 1},   // down-right
    {1, -1},  // down-left
    {-1, 1},  // up-right
    {-1, -1}, // up-left
};

char **annotate(const char **minefield, const size_t rows) {
    if (rows == 0) {
        return NULL;
    }
    char **minefield_hint = (char **)malloc(sizeof(char *) * rows);

    for (size_t i = 0; i < rows; i++) {
        minefield_hint[i] = (char *)malloc(sizeof(char) * strlen(*minefield));
        memset(minefield_hint[i], ' ', strlen(*minefield));
        minefield_hint[i][strlen(*minefield)] = '\0';
    }

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < strlen(*minefield); j++) {
            char mark = minefield[i][j];

            if (mark == ' ') {
                int bomb_count = 0;
                for (int k = 0; k < 8; k++) {
                    int row = i + offsets[k].row;
                    int col = j + offsets[k].col;
                    if ((row >= 0 && row < (int)rows) &&
                        (col >= 0 && col < (int)strlen(*minefield))) {
                        if (minefield[row][col] == '*') {
                            bomb_count++;
                        }
                    }
                }
                if (bomb_count != 0) {
                    minefield_hint[i][j] = bomb_count + '0';
                }
            } else if (mark == '*') {
                minefield_hint[i][j] = '*';
            }
        }
    }

    return minefield_hint;
}

void free_annotation(char **annotation) { free(annotation); }
