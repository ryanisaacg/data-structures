#pragma once

#include "util.h"

DEFSTRUCT(HashSet);
DEFSTRUCT(HashSetIterator);

struct HashSet {
	ArrayList buffer;
};
struct HashSetIterator {
	HashSet *set;
	int index;
}

HashSet hs_new(size_t item_size);
HashSet hs_new_capacity(size_t item_size, size_t initial_capacity);
void hs_add(HashSet *set, void *item);
HashSetIterator hs_iterator(HashSet *set);
bool hs_iterator_has_next(HashSetIterator iterator);
void *hs_iterator_peek(HashSetIterator iterator);
void *hs_iterator_next(HashSetIterator *iterator);
