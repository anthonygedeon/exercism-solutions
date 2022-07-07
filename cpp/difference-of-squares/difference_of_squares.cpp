#include "difference_of_squares.h"

#include <cmath>

namespace difference_of_squares {
        int square_of_sum(int n) {
                int result{0};
                for (int i{1}; i <= n; ++i) {
                        result += i;
                }
                return std::pow(result, 2);
        }

        int sum_of_squares(int n) {
                int result{0};
                for (int i{1}; i <= n; ++i) {
                        result += std::pow(i, 2);
                }
                return result; 
        }

        int difference(int n) {
                return square_of_sum(n) - sum_of_squares(n);
        }
}  // namespace difference_of_squares
