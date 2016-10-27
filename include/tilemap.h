#pragma once

#include <stdbool.h>
#include "array_list.h"
#include "util.h"

DEFSTRUCT(tilemap);
struct tilemap {
	const int width, height, tile;
	const size_t item_size;
	const char *buffer;
	const bool *has;
};
//Creates a new tilemap
tilemap tl_new(size_t item_size, int width, int height, int tile_size);
//Creates a new tilemap on a preallocated block of memory
tilemap tl_prealloc(size_t item_size, int width, int height, int tile_size, char *buffer, bool *boolBuffer);
//Gets the item from that position
void *tl_get(int x, int y);
//Sets the data of an item
void tl_set(const void *source, int x, int y);
//Finds if a point is free
bool tl_free(tilemap map, int x, int y);
//Finds if a region is empty
bool tl_empty(int x, int y, int width, int height);
