#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

typedef enum {
	A = 0, C, G, T 
} strand_t;

char *count(const char *dna_strand);

#endif
