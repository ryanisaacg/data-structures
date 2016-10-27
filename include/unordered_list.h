#pragma once

#include <stddef.h>
#include "util.h"

DEFSTRUCT(unordered_list);
struct unordered_list {
	size_t length, capacity, item;
	char *buffer;
};

//Create a new unordered list
unordered_list ul_new(size_t item_size);
//Get an item from the list (can change based on removals)
void *ul_get(const unordered_list list, size_t index);
void ul_add(unordered_list *list, const void *item, size_t index);
void ul_remove(unordered_list *list, size_t index);
void ul_set(unordered_list list, const void *item, size_t index);