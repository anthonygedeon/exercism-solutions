#include <string.h>
#include <stdio.h>

#include "raindrops.h"

#define PLING "Pling"
#define PLANG "Plang"
#define PLONG "Plong"

// Counts the total length of chars including ther null character.
#define CHAR_LEN(x) (size_t)sizeof(x)

// Values that the raindrop need to modded (%) against.
enum mod_raindrop_const {
        raindrop_1 = 3, 
        raindrop_2 = 5, 
        raindrop_3 = 7
};

/**
 * Compare the raindrop int to see if they're evenly divisble by 3, 5, 7. 
 * @param result - The result of char being concatentated.
 * @param drops - The int to mod against.
 * @return the result of all the characters.
 */
char *convert(char result[], int drops) {
    if (drops % raindrop_1 == 0) strncat(result, PLING, CHAR_LEN(PLING));
    if (drops % raindrop_2 == 0) strncat(result, PLANG, CHAR_LEN(PLANG));
    if (drops % raindrop_3 == 0) strncat(result, PLONG, CHAR_LEN(PLONG));
    if (drops % raindrop_1 != 0 && drops % raindrop_2 != 0 && drops % raindrop_3 != 0)
        sprintf(result, "%d", drops);
    return result;
}
