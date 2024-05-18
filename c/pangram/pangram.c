#include "pangram.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define ALPHABETS 26

static bool is_uniq(const uint32_t tally[], int size) {
	for (int i = 0; i < size; i++) {
		if (tally[i] == 0) {
			return false;
		}
	}
	return true;
}

// Determine if a sentence uses every alphabet more than once
bool is_pangram(const char *sentence) {
	if (sentence == NULL) { return false; }

	uint32_t alphabets[ALPHABETS] = { 0 };

	for (int i = 0; sentence[i] != '\0'; i++) {
		char alphabet = tolower(sentence[i]);
		if (isalpha(alphabet)) {
			alphabets[alphabet % 'a'] += 1;
		}
	}
	
	return is_uniq(alphabets, ALPHABETS);
}
