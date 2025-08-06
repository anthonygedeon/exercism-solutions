#pragma once

#include <map>
#include <string>

namespace rna_transcription {
char to_rna(char strand);
std::string to_rna(std::string strand);
} // namespace rna_transcription
