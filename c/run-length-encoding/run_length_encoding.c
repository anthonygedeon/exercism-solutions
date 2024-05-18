#include "run_length_encoding.h"
#include <limits.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// How does this work?
#define MAX ((CHAR_BIT * sizeof(int) - 1) / 3 + 2)

char *encode(const char *text) {
	if (text == NULL) {
		return NULL;
	}

	int count = 0;
	char *output = malloc(1024 * sizeof(char));
	
	int acc = 1;

	int prev = 0;
	for (size_t i = 1; i <= strlen(text); i++) {
		int curr = i;

		if (text[prev] == text[curr]) {
			acc++;
		} else {
			if (acc != 1) {
				char itoa[MAX];
				snprintf(itoa, MAX, "%d", acc);
				for (int i = 0; itoa[i] != 0; i++) {
					output[count] = itoa[i];
					count++;
				}
			}
			output[count] = text[prev];
			acc = 1;
			prev = curr;
			count++;
		}
	}

	output[count] = '\0';

	return output;
}

char *decode(const char *data) {
	 int count = 0;
	 char *output = malloc(1024 * sizeof(char));
	
	 int nums_n = 0;
	 char nums[1024];

	 for (int i = 0; data[i] != '\0'; i++) {
		 if (isdigit(data[i])) {
			nums[nums_n] = data[i];
			nums_n++;
		 } else if (isalpha(data[i]) || data[i] == *" ") {
			int n;
			sscanf(nums, "%d", &n);
			if (n == 0) {
				n = 1;
			}
			output[count] = data[i];
			count++;
			if (n > 0) {
				for (int j = 1; j < n; j++) {
					output[count] = data[i];
					count++;
				}
			}
			memset(nums, 0, sizeof(nums));
			nums_n = 0;
			n = 0;
		 }
	 }

	 output[count] = '\0';

	 return output;
}
