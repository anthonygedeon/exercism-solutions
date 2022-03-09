#include "difference_of_squares.h"
#include <math.h>

// squares of the first ten natural numbers is 1² + 2² + ... + 10² = 385.
unsigned int sum_of_squares(unsigned int number) {
      unsigned int sum = 0;
      for (unsigned int i = 1; i <= number; i++) {
        sum += pow(i, 2);
      }
      return sum;
}

// sum of the first ten natural numbers is (1 + 2 + ... + 10)² = 55² = 3025.
unsigned int square_of_sum(unsigned int number) {
       unsigned int sum = 0;
       for (unsigned int i = 1; i <= number; i++) {
         sum += i;
       }
       return pow(sum, 2);
}

// difference between for square_of_sum & sum_of_squares
unsigned int difference_of_squares(unsigned int number) {
        return square_of_sum(number) - sum_of_squares(number);
}
