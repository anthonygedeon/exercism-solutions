#include "clock.h"
#include <stdio.h>
#include <string.h>

#define MINUTE 60

clock_t clock_create(int hour, int minute) {
	clock_t clock;
	while (minute >= MINUTE) {
		hour++;
		minute -= MINUTE;
	}

	while (minute < 0) {
		hour--;	
		minute += MINUTE;
	}

	if (hour < 0) {
		hour = ((hour % -24) + 24) % 24;
	} else {
		hour %= 24;
	}

	snprintf(clock.text, MAX_STR_LEN, "%.2d:%.2d", hour , minute % MINUTE);
	return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
	int hour, minute;
	sscanf(clock.text, "%d:%d", &hour, &minute);
	return clock_create(hour, minute + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
	return clock_add(clock, -minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b) {
	return strcmp(a.text, b.text) == 0;
}
