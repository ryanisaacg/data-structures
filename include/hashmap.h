#pragma once

#include "array_list.h"
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
	ArrayList keys;
	bool (*eq)(void *a, void *b);
};

HashMap *hm_new();
HashMap *hm_new_eqfunc(bool (*eq)(void*, void*));
void hm_put(HashMap *map, int hash, void *key, void *value);
void *hm_get(HashMap *map, int hash, void *key);
ArrayList hm_get_keys(HashMap *map);
bool hm_has(HashMap *map, int hash, void *key);
void hm_destroy(HashMap *map);
