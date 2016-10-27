#pragma once

#include "array_list.h"
#include "util.h"

DEFSTRUCT(tilemap);
struct tilemap {
	array_list contents;
	int width, height, tile;
};

tilemap tl_new(size_t item_size, int width, int height, int tile_size);
void *tl_get(int x, int y);
void tl_set(void *source, int x, int y);
