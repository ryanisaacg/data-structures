#pragma once

#include <stdbool.h>
#include "array_list.h"
#include "util.h"

DEFSTRUCT(TileMap);
struct TileMap {
	const int width, height, tile;
	const size_t item_size;
	char *buffer;
	bool *has;
};
//Creates a new TileMap
TileMap tl_new(size_t item_size, int width, int height, int tile_size);
//Creates a new TileMap on a preallocated block of memory
TileMap tl_prealloc(size_t item_size, int width, int height, int tile_size, char *buffer, bool *boolBuffer);
//Gets the item from that position
void *tl_get(TileMap map, int x, int y);
//Sets the data of an item
void tl_set(TileMap map, const void *source, int x, int y);
//Removes whatever is in the TileMap at this point
void tl_remove(TileMap map, int x, int y);
//Finds if a point is free
bool tl_free(TileMap map, int x, int y);
//Finds if a region is empty
bool tl_empty(TileMap map, int x, int y, int width, int height);
//Free the memory from the tilemap
void tl_destroy(TileMap map);
