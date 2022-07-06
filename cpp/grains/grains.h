#if !defined(GRAINS_H)
#define GRAINS_H

#include <cstdint>

namespace grains {
        // Multiply by the power of 2 for argument 
        unsigned long long int square(std::int16_t);
        
        // Return max number for ULL
        unsigned long long int total();
}  // namespace grains

#endif // GRAINS_H
