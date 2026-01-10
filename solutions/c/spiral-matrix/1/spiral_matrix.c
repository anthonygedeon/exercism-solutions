#include "spiral_matrix.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum { RIGHT = 0, LEFT, UP, DOWN } Direction;

typedef struct {
    int row, col;
} Position;

spiral_matrix_t *spiral_matrix_create(int size) {
    spiral_matrix_t *spiral = malloc(sizeof(spiral_matrix_t));
    if (size <= 0) {
        spiral->matrix = NULL;
        return spiral;
    }
    spiral->size = size;
    spiral->matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        spiral->matrix[i] = malloc(size * sizeof(int));
    }

    Direction move = RIGHT;
    Position positions[] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int count = 1;
    int row = 0, col = 0;
    while (count <= (size * size)) {
        spiral->matrix[row][col] = count++;

        for (int i = 0; i < 4; i++) {
            Position neighbor = positions[i];
            int row_n = row + neighbor.row;
            int col_n = col + neighbor.col;

            if (row_n < 0 || row_n >= size)
                continue;
            if (col_n < 0 || col_n >= size)
                continue;

            if (spiral->matrix[row_n][col_n] == 0) {
                if (i == (int)move) {
                    move = (Direction)i;
                    break;
                } else {
                    move = (Direction)i;
                }
            } else if (spiral->matrix[row_n][col_n] != 0) {
                continue;
            }
        }

        row += positions[move].row;
        col += positions[move].col;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", spiral->matrix[i][j]);
        }
        printf("\n");
    }

    return spiral;
}

void spiral_matrix_destroy(spiral_matrix_t *matrix) {
    for (int i = 0; i < matrix->size; i++) {
        if (matrix->matrix[i] != NULL) {
            free(matrix->matrix[i]);
            matrix->matrix[i] = NULL;
        }
    }

    if (matrix->matrix != NULL) {
        free(matrix->matrix);
        matrix->matrix = NULL;
    }

    free(matrix);
    matrix = NULL;
}
