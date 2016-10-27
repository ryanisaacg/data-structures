#include <stdlib.h>
#include <string.h>
#include "unordered_list.h"

unordered_list ul_new(size_t item_size) {
	return ul_prealloc(item_size, malloc(item_size * 10), item_size * 10);
}

unordered_list ul_prealloc(size_t item_size, void *buffer, size_t buffer_size) {
	return (unordered_list){0, buffer_size, item_size, buffer};
}

void *ul_get(const unordered_list list, size_t index) {
	return list.buffer + (index * list.item);
}

void ul_add(unordered_list *list, const void *item) {
	if(list->length * 2 < list->capacity) {
		memcpy(list->buffer + (list->item * list->length), item, list->item);
		list->length++;
	} else {
		list->buffer = realloc(list->buffer, list->capacity * 2);
		list->capacity *= 2;
		ul_add(list, item);
	}
}

void ul_remove(unordered_list *list, size_t index) {
	//Replace the item with the last item
	memcpy(list->buffer + (list->item * index), list->buffer + (list->item * (list->length - 1)), list->item);
	list->length--;
}

void ul_set(unordered_list list, const void *item, size_t index) {
	memcpy(list.buffer + (list.item * index), item, list.item);
}


