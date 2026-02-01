#include "kindergarten_garden.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 2
#define MAX_TOKEN_LENGTH 256

plants_t plants(const char *diagram, const char *student) {
    plants_t result = {.plants = {0}};

    int index = (*student - 'A') % 26;

    char copy[MAX_TOKEN_LENGTH] = {0};
    strcpy(copy, diagram);

    char *garden[MAX_TOKENS];
    for (int j = 0; j < MAX_TOKENS; j++)
        garden[j] = malloc(MAX_TOKEN_LENGTH); // Allocate memory for each token

    int i = 0;
    char *token = strtok(copy, "\n");
    while (token != NULL) {
        memcpy(garden[i++], token, strlen(token));
        token = strtok(NULL, "\n");
    }

    int count = 1;
    for (; count <= index; count++)
        ;

    char str[64] = "";
    for (int i = 0; i < 2; i++) {
        int start = index + count;
        int end = start + 1;

        garden[i][end] = '\0';
        garden[i] += start - 1;

        strcat(str, garden[i]);
    }

    int plant_count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        plant_t plant;
        switch (str[i]) {
        case 'C':
            plant = CLOVER;
            break;
        case 'G':
            plant = GRASS;
            break;
        case 'R':
            plant = RADISHES;
            break;
        case 'V':
            plant = VIOLETS;
            break;
        default:
            plant = 0;
            break;
        }
        result.plants[plant_count++] = plant;
    }

    return result;
}
