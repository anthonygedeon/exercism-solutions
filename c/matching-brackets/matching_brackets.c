#include "matching_brackets.h"
#include <stdlib.h>
#include <stdio.h>

static char brace_lookup(const char brace) {
	switch(brace) {
		case ']':
			return '[';
		case ')':
			return '(';
		case '}':
			return '{';
		default:
			return -1;
	}
}

stack_t *stack_new() {
	stack_t *s = malloc(sizeof(stack_t));
	s->sp = 0;
	s->size = 0;
	s->data = malloc(sizeof(char));
	return s;
}

void stack_push(stack_t *stack, char data) {
	stack->data[stack->sp] = data;
	stack->sp++;
	stack->size++;
	stack->data = realloc(stack->data, sizeof(char)*stack->sp);
}

char stack_last(stack_t *stack) {
	return stack->data[stack->size-1];
}

char stack_pop(stack_t *stack) {
	stack->sp--;
	stack->size--;
	stack->data = realloc(stack->data, sizeof(char)*stack->sp+1);
	return stack->data[stack->sp];
}

bool stack_is_empty(stack_t *stack) {
	return stack->size == 0;
}

void stack_delete(stack_t *stack) {
	free(stack->data);
	free(stack);
}

bool is_paired(const char *input) {
	stack_t *stack = stack_new();

	while (*input) {
		switch(*input) {
			case '[':
			case '(':
			case '{':
				stack_push(stack, *input);
				break;
			case ']':
			case ')':
			case '}':
				if (!stack_is_empty(stack)) {
					if (brace_lookup(*input) == stack_last(stack)) {
						stack_pop(stack);
					} else {
						stack_delete(stack);
						return false;
					}
				} else {
					stack_delete(stack);
					return false;
				}
				break;
		}
		++input;
	}

	bool result = stack_is_empty(stack);
	stack_delete(stack);
	return result;
}
