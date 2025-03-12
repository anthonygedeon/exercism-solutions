#include "dnd_character.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROLLS 4

static int roll_d6() {
	srand(time(NULL));
	return (rand() % 6) + 1;
}

static int hitpoints(dnd_character_t d) {
	return modifier(d.constitution) + 10;
}

int ability(void) {
	int sum = 0, min = 6; 

	for (int i = 0; i < MAX_ROLLS; i++)	{
		int die = roll_d6();
		if (die < min)
			min = die;
		sum += die;
	}

	return sum - min;
}

int modifier(int score) {
	return floor((score - 10.0) / 2.0);
}

dnd_character_t make_dnd_character(void) {
	dnd_character_t character = {
		.strength     = ability(),
		.dexterity    = ability(),
		.constitution = ability(),
		.intelligence = ability(),
		.wisdom       = ability(),
		.charisma     = ability()
	};
	character.hitpoints = hitpoints(character);
	return character;
}
