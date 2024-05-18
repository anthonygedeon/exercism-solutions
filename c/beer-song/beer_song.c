#include "beer_song.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
	uint16_t verse = 0;
	for (int i = start_bottles; i > (start_bottles - take_down); i--) {
		if (i == 2) {
			snprintf(song[verse++], 1024, "%d bottles of beer on the wall, %d bottles of beer.", i, i);
			snprintf(song[verse++], 1024, "Take one down and pass it around, %d bottle of beer on the wall.", i - 1);
		} else if (i == 1) {
			snprintf(song[verse++], 1024, "%d bottle of beer on the wall, %d bottle of beer.", i, i);
			snprintf(song[verse++], 1024, "Take it down and pass it around, no more bottles of beer on the wall.");
		} else if (i == 0) {
			snprintf(song[verse++], 1024, "No more bottles of beer on the wall, no more bottles of beer.");
			snprintf(song[verse], 1024, "Go to the store and buy some more, 99 bottles of beer on the wall.");
			break;
		} else {
			snprintf(song[verse++], 1024, "%d bottles of beer on the wall, %d bottles of beer.", i, i);
			snprintf(song[verse++], 1024, "Take one down and pass it around, %d bottles of beer on the wall.", i - 1);
		}

		memset(song[verse], '\0', 1);

		verse++;
	}
}
