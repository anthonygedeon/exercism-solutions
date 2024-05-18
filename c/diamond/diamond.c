#include "diamond.h"
#include <stdlib.h>

char **make_diamond(const char letter) {
	char **diamond = malloc(1024*sizeof(char));
	if (diamond == NULL) {
		return NULL;
	}

	int padding = 'A' - letter;
	int diamond_index = 0;
	for (char c = 'A'; c != letter; c++) {
		diamond[diamond_index][0] = c;

		padding--;

		diamond_index++;
	}

	return diamond;
}

void free_diamond(char **diamond) {
	free(diamond);
}
