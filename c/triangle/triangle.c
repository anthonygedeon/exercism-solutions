#include "triangle.h"
#include <stdbool.h>

static bool is_triangle(triangle_t t) {
	return t.a+t.b >= t.c && t.a+t.c >= t.b && t.c+t.b >= t.a;
}

bool is_scalene(triangle_t t) {
	if (!is_triangle(t)) {
		return false;
	}
	return t.a != t.b && t.b != t.c && t.c != t.a;
}

bool is_equilateral(triangle_t t) {
	if (t.a == 0) {
		return false;
	}
	return t.a == t.b && t.b == t.c && t.c == t.a;
}

bool is_isosceles(triangle_t t) {
	if (!is_triangle(t)) {
		return false;
	}
	return t.a == t.b || t.b == t.c || t.c == t.a;
}
