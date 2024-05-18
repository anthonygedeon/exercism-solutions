#include "list_ops.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>

list_t *new_list(size_t length, list_element_t elements[]) {
	list_t *list = malloc(offsetof(list_t, elements) + (length * sizeof(list_element_t)));
	if (!list) {
		return NULL;
	}
	list->length = length;
	if (elements) {
		memcpy(list->elements, elements, length * sizeof(list_element_t));
	}
	return list;
}

list_t *append_list(list_t *list1, list_t *list2) {
	if (!list1 || !list2) {
		return NULL;
	}

	list_t *list = new_list(list1->length + list2->length, NULL);

	if (!list) {
		return NULL;
	}

	memcpy(list->elements, list1->elements, list1->length * sizeof(list_element_t));
	memcpy(list->elements + list1->length, list2->elements , list2->length * sizeof(list_element_t));
	return list;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
	if (!list) {
		return NULL;
	}

	list_t *result = new_list(list->length, NULL);

	if (!result) {
		return NULL;
	}
	
	result->length = 0;
	for (size_t i = 0; i < list->length; i++) {
		if (filter(list->elements[i])) {
			result->elements[result->length] = list->elements[i];
			result->length++;			
		}
	}

	return result;
}


size_t length_list(list_t *list) {
	return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
	if (!list) {
		return NULL;
	}

	list_t *result = new_list(list->length, NULL);

	if (!result) {
		return NULL;
	}
	
	for (size_t i = 0; i < list->length; i++) {
		result->elements[i] = map(list->elements[i]);
	}
	return result;
}

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
	if (!list) {
		return initial;
	}
	
	list_element_t sum = initial;
	for (size_t i = 0; i < list->length; i++) {
		sum = foldl(sum, list->elements[i]);
	}
	return sum;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
	if (!list) {
		return initial;
	}

	list_element_t sum = initial;
	for (int i = (int)list->length-1; i >= 0; i--) {
		sum = foldr(list->elements[i], sum);
	}
	return sum;
}

list_t *reverse_list(list_t *list) {
	if (!list) {
		return NULL;
	}

	list_t *result = new_list(list->length, list->elements);
	for (int i = list->length-1; i >= 0; i--) {
		result->elements[(list->length-1) - i] = list->elements[i];
	}
	return result;
}


void delete_list(list_t *list) {
	free(list);
}
