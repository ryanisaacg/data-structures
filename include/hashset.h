#pragma once

#include <stdbool.h>
#include "util.h"

DEFSTRUCT(HashSet);

struct HashSet {
	size_t length, capacity, item_size;
	unsigned char *buffer;
};

typedef HashSet HashSetIterator;

HashSet hs_new(size_t item_size);
HashSet hs_new_capacity(size_t item_size, size_t initial_capacity);
void hs_add(HashSet *set, int hash, void *item);
bool hs_has(HashSet set, int has, void *item);
HashSetIterator hs_iter(HashSet set);
bool hs_iter_has_next(HashSetIterator iter);
void *hs_iter_next(HashSetIterator *iter);
