#pragma once

#include "linked_list.h"
#include <stdbool.h>

DEFSTRUCT(HashEntry);
DEFSTRUCT(HashMap);

#define HASHMAP_ENTRY_LENGTH 1024

struct HashEntry {
	int hash;
	void *key, *value;
};
struct HashMap {
	LinkedList entries[HASHMAP_ENTRY_LENGTH];
	bool (*eq)(void *a, void *b);
};

HashMap *hm_new();
HashMap *hm_new_eqfunc(bool (*eq)(void*, void*));
void hm_put(HashMap *map, int hash, void *key, void *value);
void *hm_get(HashMap *map, int hash, void *key);
bool hm_has(HashMap *map, int hash, void *key);
