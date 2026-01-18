#include "atbash_cipher.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *atbash_encode(const char *input) {
    size_t length = 0;
    char *message = (char *)calloc(strlen(input) + 1, sizeof(char));

    int num_chars = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        char encrypted = ('z' - tolower(input[i]) + 'a');
        if (encrypted >= 'a' && encrypted <= 'z') {
            message[length++] = encrypted;
            num_chars++;
        } else if (isdigit(input[i])) {
            message[length++] = input[i];
            num_chars++;
        }

        if (num_chars == 5) {
            message[length++] = ' ';
            num_chars = 0;
        }
    }

    if (message[strlen(message) - 1] == ' ')
        message[strlen(message) - 1] = '\0';

    return message;
}

char *atbash_decode(const char *input) {
    char *encrypted = atbash_encode(input);

    size_t length = 0;
    char *plain = (char *)calloc(strlen(input) + 1, sizeof(char));

    for (int i = 0; encrypted[i] != '\0'; i++) {
        if (!isspace(encrypted[i]))
            plain[length++] = encrypted[i];
    }

    free(encrypted);

    return plain;
}
