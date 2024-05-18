#include "acronym.h"
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

enum character_t {
	ALPHABET = 0, NON_ALPHABET = 1
};

char *abbreviate(const char *phrase) {
	if (phrase == NULL || strcmp(phrase, "") == 0) {
		return NULL;
	}

	char *acronynm = malloc(strlen(phrase) + 1);
	if (acronynm == NULL) {
		return NULL;
	}
	
	bool state = ALPHABET;
	size_t acronym_length = 0;
	for (int i = 0; phrase[i] != '\0'; i++) {
		if (isalpha(phrase[i]) && state == ALPHABET) {
			acronynm[acronym_length++] = toupper(phrase[i]);
			state = NON_ALPHABET;
		}

		if (phrase[i] == '_' ||
			phrase[i] == '-' ||
			phrase[i] == ' ') {
			state = ALPHABET;
		}
	}

	acronynm[acronym_length] = '\0';

	return acronynm;
}
