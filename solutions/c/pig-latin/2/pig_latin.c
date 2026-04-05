#include "pig_latin.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 3

static const char vowels[] = {'a', 'e', 'i', 'o', 'u'};

static bool is_vowel(char letter) {
    bool result = false;
    for (int i = 0; i < 5; i++)
        if (vowels[i] == letter)
            result = true;
    return result;
}

static void substr(char *dest, const char *src, size_t from, size_t to) {
    strncpy(dest, src + from, to);
    dest[to] = '\0';
}

static bool is_xr_or_yt(const char *phrase) {
    char prefix[2];
    substr(prefix, phrase, 0, 2);
    return strcmp(prefix, "xr") == 0 || strcmp(prefix, "yt") == 0;
}

static bool is_qu(const char *phrase) {
    char prefix[2];
    substr(prefix, phrase, 0, 2);
    return strcmp(prefix, "qu") == 0;
}

char *translate(const char *phrase) {
    char *result = calloc(strlen(phrase) + LEN, sizeof(char));
    bool is_y = false;

    char tokens[1024] = {'\0'};
    strncpy(tokens, phrase, strlen(phrase));
    char *token = strtok(tokens, " ");

    while (token) {
        char buffer[12] = {'\0'};

        if (is_vowel(*token) || is_xr_or_yt(token)) {
            memcpy(result, token, strlen(token));
        } else {
            size_t count = 0;
            char consonants[12] = {'\0'};
            for (size_t i = 0; i < strlen(token); i++) {
                if (!is_qu(token + i)) {
                    if (!is_vowel(token[i])) {
                        if (count >= 1 && token[i] == 'y') {
                            buffer[0] = 'y';
                            count++;
                            is_y = true;
                            break;
                        }
                        consonants[count++] = token[i];
                    } else {
                        break;
                    }
                } else {
                    strcat(consonants, "qu");
                    count += 2;
                }
            }
            char remaining[12] = {'\0'};
            substr(remaining, token + count, 0, strlen(token + count));

            if (!is_y) {
                memcpy(buffer, remaining, strlen(remaining));
            } else {
                strcat(buffer, remaining);
            }
            strcat(buffer, consonants);
        }

        strcat(buffer, "ay");

        strcat(result, buffer);

        token = strtok(NULL, " ");
        if (token != NULL) {
            strcat(result, " ");
        } else {
            break;
        }
    }

    return result;
}
