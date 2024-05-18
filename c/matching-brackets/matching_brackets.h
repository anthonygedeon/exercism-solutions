#ifndef MATCHING_BRACKETS_H
#define MATCHING_BRACKETS_H

#include <stdlib.h>
#include <stdbool.h>

bool is_paired(const char *input);

typedef char brace_t;

typedef struct {
	int sp;
	size_t size;
	brace_t *data;
} stack_t;

stack_t *stack_new();
void stack_push(stack_t *stack, char data);
char stack_pop(stack_t *stack);
char stack_last(stack_t *stack);
bool stack_is_empty(stack_t *stack);
void stack_delete(stack_t *stack);

#endif
