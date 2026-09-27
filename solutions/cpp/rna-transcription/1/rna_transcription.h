#pragma once

#include <string>

namespace rna_transcription {
  unsigned char to_rna(unsigned char strand);
  std::string to_rna(const std::string& strand);
}  // namespace rna_transcription
