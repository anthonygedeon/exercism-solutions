#include "largest_series_product.h"
#include <ctype.h>
#include <string.h>

#define MAX(x, y) (x >= y ? x : y)

int64_t largest_series_product(char *digits, size_t span) {
    if ((int)span < 0)
        return -1;

    int64_t largest = -1;

    char chunk[span];
    while (strlen(digits) >= span) {
        int product = 1;

        memcpy(chunk, digits, span * sizeof(char));

        for (size_t i = 0; i < span; i++) {
            if (!isdigit(chunk[i])) {
                return -1;
            }
            product *= chunk[i] - '0';
        }

        largest = MAX(product, largest);

        digits++;
    }

    return largest;
}
