#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>

char complement_strand(const char nucleotide) {
	switch(nucleotide) {
		case 'G':
			return 'C';
		case 'C':
			return 'G';
		case 'T':
			return 'A';
		case 'A':
			return 'U';
		default:
			// error-checking
			return '\0';
	}
}

char *to_rna(const char *dna) {
	if (!dna) { return NULL; }

	size_t length = strlen(dna) + 1;

	char *rna = calloc(length, sizeof(char));
	if (!rna) { return NULL; }

	for (size_t i = 0; i < length - 1; i++) {
		rna[i] = complement_strand(dna[i]);

		// handle error when we come across an unknown character
		if (rna[i] == '\0') {
			free(rna);
			return NULL;
		}
	}

	rna[length] = '\0';

	return rna;
}
