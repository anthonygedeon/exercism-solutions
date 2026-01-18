#include "rotational_cipher.h"
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key) {
    size_t length = 0;
    char *message = (char *)calloc(strlen(text) + 1, sizeof(char));

    while (*text) {
        if (*text >= 'A' && *text <= 'Z') {
            message[length++] = ((*text - 'A' + shift_key) % 26) + 'A';
        } else if (*text >= 'a' && *text <= 'z') {
            message[length++] = ((*text - 'a' + shift_key) % 26) + 'a';
        } else {
            message[length++] = *text;
        }
        text++;
    }

    return message;
}
