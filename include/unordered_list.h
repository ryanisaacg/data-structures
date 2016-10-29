#pragma once

#include <stddef.h>
#include "util.h"

DEFSTRUCT(UnorderedList);
struct UnorderedList {
	size_t length, capacity, item;
	char *buffer;
};

//Create a new unordered list
UnorderedList ul_new(size_t item_size);
//Create a new unordered list using a pre-allocated buffer
UnorderedList ul_prealloc(size_t item_size, void *buffer, size_t buffer_size);
//Get an item from the list (can change based on removals)
void *ul_get(const UnorderedList list, size_t index);
//Add an item to an unordered list
void ul_add(UnorderedList *list, const void *item);
//Remove an item from an unordered list
void ul_remove(UnorderedList *list, size_t index);
//Set the value of an index in an unordered list
void ul_set(UnorderedList list, const void *item, size_t index);
