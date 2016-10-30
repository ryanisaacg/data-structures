#include "hashset.h"
#include <stdlib.h>
#include <string.h>

static unsigned char *get_index(HashSet set, int index) {
	return set.buffer + (abs(index) * (1 + sizeof(int) + set.item_size));
}

HashSet hs_new(size_t item_size) {
	return hs_new_capacity(item_size, 10);
}

HashSet hs_new_capacity(size_t item_size, size_t initial_capacity) {
	return (HashSet){0, initial_capacity, item_size, calloc((item_size + 1 + sizeof(int)) * initial_capacity, 0)};
}

void hs_add(HashSet *set, int hash, void *item) {
	if(set->length * 2 < set->capacity) {
		//Find the correct index
		int current = hash % set->capacity;
		//Probe linearly
		while(*get_index(*set, current)  == 1) current++;
		//Find the correct spot in the buffer
		unsigned char *target = get_index(*set, current);
		//Set the 'item is here' byte
		target[0] = 1;
		//Store the hash value
		memcpy(target + 1, &hash, sizeof(int));
		//Copy the actual value
		memcpy(target + 1 + sizeof(int), item, set->item_size);
		//Increase the length
		set->length++;
	} else {
		//Double the capacity 
		set->capacity *= 2;
		HashSet old = *set; //store the old hashset
		set->buffer = calloc((set->item_size + 1 + sizeof(int)) * set->capacity, 0); //alocate the new memory
		//Insert the new item
		hs_add(set, hash, item);
		//Insert the old items
		for(int i = 0; i < old.capacity; i++) {
			unsigned char *chunk = get_index(old, i);
			if(*chunk == 1)  {
				int hash;
				memcpy(&hash, chunk + 1, sizeof(int));
				hs_add(set, hash, chunk + 1 + sizeof(int));
			}
		}
	}
}

HashSetIterator hs_iter(HashSet set) {
	return set;
}

bool hs_iter_has_next(HashSetIterator iter) {
	if(iter.capacity == 0) return false;
	if(*(iter.buffer) == 1) return true;
	else {
		iter.buffer += 1 + sizeof(int) + iter.item_size;
		return hs_iter_has_next(iter);
	}
}

void *hs_iter_next(HashSetIterator *iter) {
	if(iter->capacity == 0) return NULL;
	if(*(iter->buffer) == 1) {
		void *buffer = iter->buffer + 1 + sizeof(int); 
		iter->buffer += iter->item_size;
		iter->capacity -= 1;
		return buffer;
	} else {
		iter->buffer += 1 + sizeof(int) + iter->item_size;
		return hs_iter_next(iter);
	}
}
