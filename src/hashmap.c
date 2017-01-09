#include "hashmap.h"
#include <stdbool.h>
#include "linked_list.h"
#include "util.h"

static int get_hash(int key);
static bool void_ptr_equals(void *a, void *b);

static bool void_ptr_equals(void *a, void *b) {
	return a == b;
}

HashMap *hm_new() {
	HashMap *map = new(map);
	map->eq = &void_ptr_equals;
	map->keys = al_new(sizeof(void*));
	for(int i = 0; i < HASHMAP_ENTRY_LENGTH; i++)
		map->entries[i].head = map->entries[i].tail = NULL;
	return map;
}

HashMap *hm_new_eqfunc(bool (*eq)(void*, void*)) {
	HashMap *map = hm_new();
	map->eq = eq;
	return map;
}

void hm_put(HashMap *map, int hash, void *key, void *value) {
	int index = get_hash(hash);
	HashEntry *entry = new(entry);
	entry->hash = hash;
	entry->key = key;
	entry->value = value;
	al_add(&map->keys, key);
	ll_add_last(&(map->entries[index]), entry);
}

void *hm_get(HashMap *map, int hash, void *key) {
	int index = get_hash(hash);
	LinkedList data = map->entries[index];
	LinkedIterator iterator = ll_iter_head(&data);
	while(ll_iter_has_next(&iterator)) {
		HashEntry *entry = ll_iter_next(&iterator);
		if(entry->hash == hash && map->eq(entry->key, key)) {
			return entry->value;
		}
	}
	return NULL;
}

ArrayList hm_get_keys(HashMap *map) {
	return map->keys;
}

bool hm_has(HashMap *map, int hash, void *key){
	return hm_get(map, hash, key) != NULL;
}

static int get_hash(int key) {
	return abs(key) % HASHMAP_ENTRY_LENGTH;
}

void hm_destroy(HashMap *map) {
	free(map);
}
