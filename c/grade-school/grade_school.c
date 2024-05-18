#include "grade_school.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

void init_roster(roster_t *roster) {
	roster->count = 0;
}

int compare_grades(const void* a, const void* b) {
	student_t arg1 = *(const student_t*)a;
    student_t arg2 = *(const student_t*)b;
 
    if (arg1.grade < arg2.grade) return -1;
    if (arg1.grade > arg2.grade) return 1;
    return strcmp(arg1.name, arg2.name);
}

bool add_student(roster_t *roster, const char *name, int grade) {
	if (roster == NULL) {
		return false;
	}

	student_t student;
	student.grade = grade;
	memcpy(student.name, name, MAX_NAME_LENGTH);

	for (size_t i = 0; i < roster->count; i++) {
		if (strcmp(roster->students[i].name, name) == 0) {
			return false;
		}
	}

	roster->students[roster->count] = student; 

	roster->count++;

	qsort(roster->students, roster->count, sizeof(student_t), compare_grades);

	return true;
}

roster_t get_grade(roster_t *roster, uint8_t grade) {
	roster_t filtered_roster;
	filtered_roster.count = 0;
	
	for (size_t i = 0; i < roster->count; i++) {
		if (roster->students[i].grade == grade) {
			filtered_roster.students[filtered_roster.count] = roster->students[i];
			filtered_roster.count++;
		}
	}

	return filtered_roster;
}
