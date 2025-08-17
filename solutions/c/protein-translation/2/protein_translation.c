#include "protein_translation.h"

#include <stdio.h>
#include <string.h>

#define BUFSIZE 3

amino_acid_t codon_lookup(const char *codon) {
    if (strcmp(codon, "AUG") == 0)
        return Methionine;
    else if (strcmp(codon, "UUU") == 0 || strcmp(codon, "UUC") == 0)
        return Phenylalanine;
    else if (strcmp(codon, "UUA") == 0 || strcmp(codon, "UUG") == 0)
        return Leucine;
    else if (strcmp(codon, "UCU") == 0 || strcmp(codon, "UCC") == 0 ||
             strcmp(codon, "UCA") == 0 || strcmp(codon, "UCG") == 0)
        return Serine;
    else if (strcmp(codon, "UAU") == 0 || strcmp(codon, "UAC") == 0)
        return Tyrosine;
    else if (strcmp(codon, "UGC") == 0 || strcmp(codon, "UGU") == 0)
        return Cysteine;
    else if (strcmp(codon, "UGG") == 0)
        return Tryptophan;
    else if (strcmp(codon, "UAA") == 0 || strcmp(codon, "UAG") == 0 ||
             strcmp(codon, "UGA") == 0)
        return -2;

    return -1;
}

protein_t protein(const char *const rna) {
    protein_t result;
    result.count = 0;
    result.valid = true;

    int slice = 0;
    char buf[BUFSIZE + 1];
    for (int i = 0; rna[i] != '\0'; i++) {
        if (*(rna + slice) == '\0')
            break;
        strncpy(buf, rna + slice, sizeof(char) * BUFSIZE);
        buf[BUFSIZE + 1] = '\0';

        amino_acid_t amino_acid = codon_lookup(buf);
        if (amino_acid == (amino_acid_t)-2) {
            result.valid = true;
            break;
        }

        if (amino_acid == (amino_acid_t)-1) {
            // handle error
            result.valid = false;
            result.count = 0;
        }
        result.amino_acids[result.count++] = amino_acid;

        slice += 3;
    }

    return result;
}
