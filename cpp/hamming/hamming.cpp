#include "hamming.h"

#include <stdexcept>

namespace hamming {
   int compute(const std::string& strand_1, const std::string& strand_2) {
      if (strand_1.length() != strand_2.length()) {
        throw std::domain_error("strands must be the same length.");
      }
      int difference{0};
      for (int i = 0; i < static_cast<int>(strand_1.length()); ++i) {
        if (strand_1.at(i) != strand_2.at(i)) {
                ++difference;
        }
      }
      return difference;
   }
}  // namespace hamming
