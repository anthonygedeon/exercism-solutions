#include "perfect_numbers.h"
#include <stdexcept>

namespace perfect_numbers {

classification classify(int number) {
    if (number <= 0)
        throw std::domain_error("error");
    int sum{0};
    for (int i = 1; i < number; i++) {
        if ((number % i) == 0) {
            sum += i;
        }
    }
    if (sum == number)
        return classification::perfect;
    if (sum > number)
        return classification::abundant;
    return classification::deficient;
}

} // namespace perfect_numbers
