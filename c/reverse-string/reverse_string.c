#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *reverse(const char *value) {
	if (value == NULL) {
		return NULL;
	}

	int length = strlen(value);

	char *reverse_string = malloc(sizeof(char)*length);

	for (int i = 0; i < length; i++) {
		reverse_string[i] = value[length - i - 1];
	}

	reverse_string[length] = '\0';

	return reverse_string;
}
