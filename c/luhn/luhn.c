#include "luhn.h"
#include <ctype.h>
#include <stddef.h>
#include <string.h>

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

bool luhn(const char *num) {
	if (num == NULL) {
		return false;
	}
	
	int total = 0;
	
	int card_len = 0;
	int card[1024] = { 0 };

	for (size_t i = 0; i < strlen(num); i++) {
		if (isdigit(num[i])) {
			int card_number = num[i] - '0';
			card[card_len] = card_number;
			card_len++;
		} else if (!isspace(num[i])) {
			return false;
		}
	}
	
	if (card_len <= 1) {
		return false;
	}

	for (int i = card_len - 2; i >= 0; i -= 2) {
		card[i] *= 2;

		if (card[i] > 9) {
			card[i] -= 9;
		}
	}

	for (int i = 0; i < card_len; i++) {
		total += card[i];
	}


	return total % 10 == 0;
}
