#include "allergies.h"
#include <stdio.h>

bool is_allergic_to(allergen_t allergen, int score) {
    return (score >> allergen) & 0x1;
}

allergen_list_t get_allergens(int score) {
    allergen_list_t result = {.count = 0};

    for (allergen_t allergen = ALLERGEN_EGGS; allergen < ALLERGEN_COUNT;
         allergen++) {
        result.allergens[allergen] = is_allergic_to(allergen, score);
        if (result.allergens[allergen])
            result.count++;
    }

    return result;
}
