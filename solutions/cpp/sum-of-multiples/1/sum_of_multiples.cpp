#include "sum_of_multiples.h"

#include <numeric>
#include <set>

namespace sum_of_multiples {
int to(std::vector<int> multiples, int number) {
    std::set<int> numbers;

    for (auto i{1}; i < number; i++) {
        for (auto &multiple : multiples) {
            if ((i % multiple) == 0) {
                numbers.insert(i);
            }
        }
    }

    return std::accumulate(numbers.begin(), numbers.end(), 0);
}
} // namespace sum_of_multiples
