#include "anagram.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tolowercase(char *dest, const char *src) {
    while (*src)
        *(dest++) = (char)tolower(*(src++));
    *dest = '\0';
}

int compare(const void *a, const void *b) {
    char c1 = *(const char *)a;
    char c2 = *(const char *)b;

    if (c1 < c2)
        return -1;
    if (c1 > c2)
        return 1;
    return 0;
}

void find_anagrams(const char *subject, struct candidates *candidates) {
    char lower_subject[MAX_STR_LEN];
    tolowercase(lower_subject, subject);

    for (size_t i = 0; i < candidates->count; i++) {
        struct candidate *possible_candidate = &candidates->candidate[i];

        char lower_target[MAX_STR_LEN];
        tolowercase(lower_target, possible_candidate->word);

        // There the same before any mutation occurs
        if (strcmp(lower_subject, lower_target) == 0) {
            possible_candidate->is_anagram = NOT_ANAGRAM;
        } else {
            qsort(lower_subject, strlen(lower_subject), sizeof(char), compare);
            qsort(lower_target, strlen(lower_target), sizeof(char), compare);

            possible_candidate->is_anagram =
                strcmp(lower_subject, lower_target) == 0 ? IS_ANAGRAM
                                                         : NOT_ANAGRAM;
        }
    }
}
