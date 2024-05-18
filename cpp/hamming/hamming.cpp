#include "hamming.h"

#include <stdexcept>
#include <numeric>

namespace hamming {
   int compute(const std::string& strand_1, const std::string& strand_2) {
      if (strand_1.length() != strand_2.length()) throw std::domain_error("strands must be of same length.");
      return std::inner_product(
              strand_1.begin(), 
              strand_1.end(), 
              strand_2.begin(), 
              0,
              std::plus<>(), std::not_equal_to<>());
   }
}  // namespace hamming
