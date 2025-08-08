#include "rna_transcription.h"
#include <algorithm>

namespace rna_transcription {

char to_rna(char strand) {
    switch (strand) {
    case 'G':
        return 'C';
    case 'C':
        return 'G';
    case 'T':
        return 'A';
    case 'A':
        return 'U';
    }
    return strand;
}

std::string to_rna(std::string strand) {
    std::string result{};
    std::transform(strand.begin(), strand.end(), std::back_inserter(result),
                   [](auto nucleotide) -> auto { return to_rna(nucleotide); });
    return result;
}

} // namespace rna_transcription
