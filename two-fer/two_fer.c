#include "two_fer.h"
#include <stdio.h>

// Basic Greeting primitive
void two_fer(char *buffer, const char *name) {
        sprintf(buffer, "One for %s, one for me.", name ? name : "you");
}
