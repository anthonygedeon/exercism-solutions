#include "rna_transcription.h"
#include <algorithm>
#include <unordered_map>

namespace rna_transcription {

  std::unordered_map<unsigned char, unsigned char> complement
  {
    {'G', 'C'},
    {'C', 'G'},
    {'T', 'A'},
    {'A', 'U'},
  };

  unsigned char to_rna(unsigned char strand)
  {
    return complement[strand];
  }

  std::string to_rna(const std::string& strand)
  {
    std::string result;
    result.reserve(strand.size());
    std::transform(strand.begin(), strand.end(), std::back_inserter(result),
		   [](unsigned char c){ return to_rna(c); });
    return result;
  }

}  // namespace rna_transcription
