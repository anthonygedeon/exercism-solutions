#include "gigasecond.h"
#include <time.h>

#define GIGASECOND (time_t)1e9

inline static time_t gigasecond_after(time_t time) {
	return time + GIGASECOND;
}

void gigasecond(time_t input, char *output, size_t size) {
	time_t after = gigasecond_after(input);
	strftime(output, size, "%F %T", gmtime(&after));
}
