#include "yacht.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE(x) (sizeof(x) / sizeof(x[0]))

typedef int (*score_func)(const dice_t, size_t);

static int ascending(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

static int sum(dice_t haystack, size_t length, int target) {
    int sum = 0;
    for (size_t i = 0; i < length; i++) {
        if (target == -1) {
            sum += haystack.faces[i];
        } else if (haystack.faces[i] == target) {
            sum += haystack.faces[i];
        }
    }
    return sum;
}

static int score_ones(const dice_t d, size_t length) {
    return sum(d, length, 1);
}

static int score_twos(const dice_t d, size_t length) {
    return sum(d, length, 2);
}

static int score_threes(const dice_t d, size_t length) {
    return sum(d, length, 3);
}

static int score_fours(const dice_t d, size_t length) {
    return sum(d, length, 4);
}

static int score_fives(const dice_t d, size_t length) {
    return sum(d, length, 5);
}

static int score_sixes(const dice_t d, size_t length) {
    return sum(d, length, 6);
}

static int score_choice(const dice_t d, size_t length) {
    return sum(d, length, -1);
}

static int score_full_house(const dice_t d, size_t length) {
    int tally[length + 1];

    for (size_t i = 0; i < length + 1; i++)
        tally[i] = 0;

    for (size_t i = 0; i < length; i++)
        tally[d.faces[i] - 1]++;

    int total = 0;
    for (size_t i = 0; i < SIZE(tally); i++) {
        if (tally[i] == 2 || tally[i] == 3)
            total += tally[i];
    }

    return total == 5 ? sum(d, length, -1) : 0;
}

static int score_four_kind(const dice_t d, size_t length) {
    int tally[length + 1];

    for (size_t i = 0; i < length + 1; i++)
        tally[i] = 0;

    for (size_t i = 0; i < length; i++)
        tally[d.faces[i] - 1]++;

    bool exists = false;
    size_t i;
    for (i = 0; i < SIZE(tally); i++) {
        int amount = tally[i];

        if (amount >= 4) {
            exists = true;
            break;
        }
    }

    return exists ? (i + 1) * 4 : 0;
}

static int score_sm_straight(const dice_t d, size_t length) {
    dice_t sorted_dice = d;

    qsort(sorted_dice.faces, length, sizeof(sorted_dice.faces[0]), ascending);

    if (sorted_dice.faces[0] == 2)
        return 0;

    for (size_t i = 0; i < length - 1; i++) {
        if (sorted_dice.faces[i] + 1 != sorted_dice.faces[i + 1])
            return 0;
    }

    return 30;
}

static int score_bg_straight(const dice_t d, size_t length) {
    dice_t sorted_dice = d;

    qsort(sorted_dice.faces, length, sizeof(sorted_dice.faces[0]), ascending);

    if (sorted_dice.faces[0] == 1)
        return 0;

    for (size_t i = 0; i < length - 1; i++) {
        if (sorted_dice.faces[i] + 1 != sorted_dice.faces[i + 1])
            return 0;
    }

    return 30;
}

static int score_yacht(const dice_t d, size_t length) {
    int needle = d.faces[0];
    for (size_t i = 1; i < length; i++) {
        if (needle != d.faces[i])
            return 0;
    }
    return 50;
}

score_func category_table[] = {
    score_ones,        score_twos,        score_threes,     score_fours,
    score_fives,       score_sixes,       score_full_house, score_four_kind,
    score_sm_straight, score_bg_straight, score_choice,     score_yacht,
};

int score(dice_t dice, category_t category) {
    return category_table[category](dice, SIZE(dice.faces));
}
