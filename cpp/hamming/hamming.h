#if !defined(HAMMING_H)
#define HAMMING_H

#include <string>

namespace hamming {
   // Calculate the Hamming Distance between two DNA strands. 
   int compute(const std::string&, const std::string&);
}  // namespace hamming

#endif // HAMMING_H
