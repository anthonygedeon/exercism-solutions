#include "etl.h"
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>

int sort_alphabetical(const void * a, const void * b);

int convert(const legacy_map *input, const size_t input_len, new_map **output) {
	*output = (new_map *)malloc(sizeof(new_map));

	size_t length = 0;
	for (size_t i = 0; i < input_len; i++)	{
		for (int j = 0; input[i].keys[j] != '\0'; j++) {
			new_map score = { .key = tolower(input[i].keys[j]), .value = input[i].value };
			(*output)[length] = score;
			length++;
			*output = realloc(*output, sizeof(new_map)*(length+1));
		}
	}

	qsort(*output, length, sizeof(new_map), sort_alphabetical);

	return length;
}

int sort_alphabetical(const void * a, const void * b) { 
    return ((new_map *)a)->key - ((new_map *)b)->key; 
}
