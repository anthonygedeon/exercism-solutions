#include "protein_translation.h"

#include <stdio.h>
#include <string.h>

#define CODON_LEN 3
#define BUFSIZE (CODON_LEN + 1)
#define CODON_STOP ((amino_acid_t) - 1)
#define CODON_ERROR ((amino_acid_t) - 2)

typedef struct {
    const char *codon;
    amino_acid_t amino_acid;
} codon_map;

static const codon_map codon_table[] = {
    {"AUG", Methionine}, {"UUU", Phenylalanine}, {"UUC", Phenylalanine},
    {"UUA", Leucine},    {"UUG", Leucine},       {"UCU", Serine},
    {"UCC", Serine},     {"UCA", Serine},        {"UCG", Serine},
    {"UAU", Tyrosine},   {"UAC", Tyrosine},      {"UGC", Cysteine},
    {"UGU", Cysteine},   {"UGG", Tryptophan},    {"UAA", CODON_STOP},
    {"UAG", CODON_STOP}, {"UGA", CODON_STOP}};

static const int codon_map_size =
    (sizeof(codon_table) / sizeof(codon_table[0]));

amino_acid_t codon_get(const char *codon) {
    for (int i = 0; i < codon_map_size; i++) {
        if (strcmp(codon, codon_table[i].codon) == 0) {
            return codon_table[i].amino_acid;
        }
    }
    return CODON_ERROR;
}

protein_t protein(const char *const rna) {
    protein_t result = {.count = 0, .valid = true};

    char codon[BUFSIZE];
    for (int i = 0; rna[i] != '\0'; i += CODON_LEN) {
        strncpy(codon, rna + i, BUFSIZE - 1);
        codon[BUFSIZE - 1] = '\0';

        amino_acid_t amino_acid = codon_get(codon);
        if (amino_acid == CODON_STOP)
            break;
        else if (amino_acid == CODON_ERROR) {
            result.valid = false;
            result.count = 0;
            break;
        }

        result.amino_acids[result.count++] = amino_acid;
    }

    return result;
}
