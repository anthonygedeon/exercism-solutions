#include "allergies.h"

const unsigned int BIT_FIELD = 0b0000000;

bool is_allergic_to(allergen_t allergen, int score) {
	BIT_FIELD | (score << allergen);	
}

allergen_list_t get_allergens(int score) {

}
