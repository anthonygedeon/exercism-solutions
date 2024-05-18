#include "isogram.h"
#include <stdint.h>
#include <ctype.h>

#define ALPHABET_SIZE 25

bool is_isogram(const char phrase[]) {
	if (!phrase) { return false; }
	
	bool seen_alphas[ALPHABET_SIZE] = { false };
	
	for (; *phrase; ++phrase) {
		uint8_t letter = tolower(*phrase) - 'a';
		
		if (isalpha(*phrase)) {
			if (seen_alphas[letter]) {
				return false;
			} else {
				seen_alphas[letter] = true;
			}
		}

	}
	
	return true;
}
