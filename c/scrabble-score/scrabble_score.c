#include "scrabble_score.h"
#include <ctype.h>
#include <stddef.h>

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

scrabble_score scores[] = { { 'a', 1 },  { 'b', 3 }, { 'c', 3 }, { 'd', 2 },
                              { 'e', 1 },  { 'f', 4 }, { 'g', 2 }, { 'h', 4 },
                              { 'i', 1 },  { 'j', 8 }, { 'k', 5 }, { 'l', 1 },
                              { 'm', 3 },  { 'n', 1 }, { 'o', 1 }, { 'p', 3 },
                              { 'q', 10 }, { 'r', 1 }, { 's', 1 }, { 't', 1 },
                              { 'u', 1 },  { 'v', 4 }, { 'w', 4 }, { 'x', 8 },
                              { 'y', 4 },  { 'z', 10 } };

static int find_score(const scrabble_score *scores, size_t len, const char letter) {
	for (size_t j = 0; j < len; j++) {
		if (scores[j].key == letter) {
			return scores[j].value;
		}
	}
	return 0;
}

unsigned int score(const char *word) {
	unsigned int total = 0;
	
	for (int i = 0; word[i] != '\0'; i++) {
		char letter = tolower(word[i]);
		int score = find_score(scores, ARRAY_LENGTH(scores), letter);
		total += score;
	}

	return total;
}
