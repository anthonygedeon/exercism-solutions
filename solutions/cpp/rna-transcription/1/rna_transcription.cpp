#include "rna_transcription.h"

namespace rna_transcription {

#include <map>

std::map<char, char> complements{
    {'G', 'C'},
    {'C', 'G'},
    {'T', 'A'},
    {'A', 'U'},
};

char to_rna(char strand) { return complements[strand]; }

std::string to_rna(std::string strand) {
    std::string result{};
    result.reserve(strand.size());
    for (auto &nucleotide : strand) {
        result += complements[nucleotide];
    }
    return result;
}

} // namespace rna_transcription
