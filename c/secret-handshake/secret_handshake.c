#include "secret_handshake.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HANDSHAKE_CAPACITY 4

const char **commands(size_t number) {
	int len = 0;
	const char **handshakes = calloc(HANDSHAKE_CAPACITY, sizeof(char*));
		if (handshakes == NULL) {
			return NULL;
		}
	
	if ((number & 0x1) != 0) {  
		handshakes[len] = "wink";
		len++;
	}

	if ((number & 0x2) != 0) {  
		handshakes[len] = "double blink";
		len++;
	}

	if ((number & 0x4) != 0) {  
		handshakes[len] = "close your eyes";
		len++;
	}

	if ((number & 0x8) != 0) {  
		handshakes[len] = "jump";
		len++;
	}

	if ((number & 0x10) != 0) { 
		const char **rev_handshakes = calloc(HANDSHAKE_CAPACITY, sizeof(char*));
		if (rev_handshakes == NULL) {
			return NULL;
		}
		for (int i = (int)len-1; i >= 0; i--) {
			rev_handshakes[(len - 1)- i] = handshakes[i];
		}

		return rev_handshakes;
	} else {
		return handshakes;
	}
}

