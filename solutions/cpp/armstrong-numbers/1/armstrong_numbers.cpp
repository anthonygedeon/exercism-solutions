#include "armstrong_numbers.h"
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

namespace armstrong_numbers {

bool is_armstrong_number(int number) {
    int sum{0};
    size_t length{std::to_string(number).length()};

    int base{1};
    int is_number{number};
    while (is_number) {
        is_number = (number / base) % 10;
        sum += std::pow(is_number, length);
        base *= 10;
    }

    return sum == number;
}
} // namespace armstrong_numbers
