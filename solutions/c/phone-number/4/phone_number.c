#include "phone_number.h"
#include <ctype.h>
#include <errno.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10

char *phone_number_clean(const char *input) {
    char *result = malloc((sizeof(char) * LENGTH) + 1);
    if (result == NULL) {
        return NULL;
    }

    const char *p = input;

    int length = 0;
    while (*p != '\0') {
        if (isdigit(*p)) {
            result[length++] = *p;
        }
        p++;
    }

    result[length] = '\0';
    if (strlen(result) > LENGTH) {
        if (result[0] != '1') {
            printf("hello");
            memset(result, '0', 10);
            result[10] = '\0';
            result[11] = '\0';
            return result;
        } else {
            memcpy(result, result + 1, LENGTH * sizeof(char));
            result[10] = '\0';
            if (result[0] < '2' || result[3] < '2') {
                memset(result, '0', 10);
                result[10] = '\0';
                return result;
            }
        }
    } else if (strlen(result) < LENGTH) {
        memset(result, '0', 10);
        result[10] = '\0';
        return result;
    } else {
        if (result[0] < '2' || result[3] < '2') {
            memset(result, '0', 10);
            result[10] = '\0';
            return result;
        }
    }

    return result;
}
