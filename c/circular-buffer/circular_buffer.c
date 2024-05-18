#include "circular_buffer.h"
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

static bool is_full(circular_buffer_t *buffer) {
	return buffer->length == buffer->capacity;
}

static bool is_empty(circular_buffer_t *buffer) {
	return (buffer->head == buffer->tail) && !is_full(buffer);
}

circular_buffer_t *new_circular_buffer(size_t capacity) {
	circular_buffer_t *c = calloc(1, sizeof(circular_buffer_t));
	c->head = 0;
	c->tail = 0;
	c->length = 0;
	c->capacity = capacity;
	c->buf = calloc(capacity, sizeof(buffer_value_t));
	return c;
}

void delete_buffer(circular_buffer_t *buffer) {
	free(buffer->buf);
	free(buffer);
}

void clear_buffer(circular_buffer_t *buffer) {
	buffer->head = 0;
	buffer->tail = 0;
	buffer->length = 0;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value) {
	if (is_empty(buffer)) {
		errno = ENODATA;
		return EXIT_FAILURE;
	}
	
	buffer->length--;
	*value = buffer->buf[buffer->head];
	buffer->head = (buffer->head + 1) % (buffer->capacity);

	return EXIT_SUCCESS;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value) {
	if (is_full(buffer)) {
		errno = ENOBUFS;
		return EXIT_FAILURE;
	}
	
	buffer->length++;
	buffer->buf[buffer->tail] = value;
	buffer->tail = (buffer->tail + 1) % (buffer->capacity);

	return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
	if (!is_full(buffer)) {
		return write(buffer, value);
	}
	buffer->buf[buffer->head] = value;
	buffer->head = (buffer->head + 1) % (buffer->capacity);
	buffer->tail = (buffer->tail + 1) % (buffer->capacity);

	return EXIT_SUCCESS;
}
