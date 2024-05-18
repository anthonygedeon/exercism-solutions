#include "nucleotide_count.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INVALID_STRAND -1
#define LENGTH 20

static strand_t find_index(const char c);

char *count(const char *dna_strand) {
	if (dna_strand == NULL) {
		return NULL;
	}

	char *tally = malloc(sizeof(char)*LENGTH);
	if (tally == NULL) {
		return NULL;
	}

	int frequency[4] = { 0 };

	for (size_t i = 0; i < strlen(dna_strand); i++) {
		strand_t strand_index = find_index(dna_strand[i]);
		if ((int)strand_index == INVALID_STRAND) {
			char *empty_string = calloc(1, sizeof(char));
			if (empty_string == NULL) {
				return NULL;
			}
			return  empty_string;
		}
		frequency[strand_index]++;
	}

	snprintf(tally, LENGTH, "A:%i C:%i G:%i T:%i", 
			frequency[0], frequency[1], frequency[2], frequency[3]);
 
	return tally;
}

static strand_t find_index(const char c) {
	switch(c) {
		case 'A':
			return A;
		case 'C':
			return C;
		case 'G':
			return G;
		case 'T':
			return T;
		default: 
			return INVALID_STRAND;
	}
}
