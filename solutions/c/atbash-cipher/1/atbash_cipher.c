#include "atbash_cipher.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char cipher_lookup[] = {
    ['a'] = 'z', ['b'] = 'y', ['c'] = 'x', ['d'] = 'w', ['e'] = 'v',
    ['f'] = 'u', ['g'] = 't', ['h'] = 's', ['i'] = 'r', ['j'] = 'q',
    ['k'] = 'p', ['l'] = 'o', ['m'] = 'n', ['n'] = 'm', ['o'] = 'l',
    ['p'] = 'k', ['q'] = 'j', ['r'] = 'i', ['s'] = 'h', ['t'] = 'g',
    ['u'] = 'f', ['v'] = 'e', ['w'] = 'd', ['x'] = 'c', ['y'] = 'b',
    ['z'] = 'a'};

char *atbash_encode(const char *input) {
    size_t length = 0;
    char *message = (char *)calloc(strlen(input) + 1, sizeof(char));

    int num_chars = 0;
    while (*input) {
        char encrypted = cipher_lookup[tolower(*input)];
        if (encrypted >= 'a' && encrypted <= 'z') {
            message[length++] = encrypted;
            num_chars++;
        } else if (isdigit(*input)) {
            message[length++] = *input;
            num_chars++;
        }

        if (num_chars == 5) {
            message[length++] = ' ';
            num_chars = 0;
        }

        input++;
    }

    if (message[strlen(message) - 1] == ' ')
        message[strlen(message) - 1] = '\0';

    return message;
}

char *atbash_decode(const char *input) {
    char *encrypted = atbash_encode(input);

    size_t length = 0;
    char *plain = (char *)calloc(strlen(input) + 1, sizeof(char));

    while (*encrypted) {
        if (!isspace(*encrypted))
            plain[length++] = *encrypted;
        encrypted++;
    }

    return plain;
}
