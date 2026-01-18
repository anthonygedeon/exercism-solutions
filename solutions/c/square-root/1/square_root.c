#include "square_root.h"

uint16_t square_root(uint16_t n) {
    uint16_t F = 1;

    while ((F + 1) * (F + 1) <= n)
        F++;

    return F;
}
