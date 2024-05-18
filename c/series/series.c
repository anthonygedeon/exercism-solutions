#include "series.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void slice_str(const char * str, char * buffer, size_t start, size_t end) {
    size_t j = 0;
    for (size_t i = start; i < end; ++i ) {
        buffer[j] = str[i];
		j++;
    }
    buffer[j] = 0;
}

slices_t slices(char *input_text, unsigned int substring_length) {
	if (input_text == NULL || strcmp(input_text, "") == 0 || substring_length == 0) {
		return (slices_t){ .substring = NULL, .substring_count = 0 };
	}

	slices_t slice; 
	slice.substring_count = 0;
	slice.substring = (char**)malloc(10*sizeof(char));

	if (slice.substring == NULL) {
		return (slices_t){ .substring = NULL, .substring_count = 0 };
	}
	
	for (size_t i = 0; i < strlen(input_text)+1; i++) {
		size_t ahead = i + substring_length;
		if (ahead > strlen(input_text)) break;
		slice.substring[slice.substring_count] = malloc(substring_length * sizeof(char));
		slice_str(input_text, slice.substring[slice.substring_count], i, ahead);
		slice.substring_count++;
	}

	return slice;
}
