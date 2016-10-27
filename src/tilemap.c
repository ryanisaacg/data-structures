#pragma once

#include <stdlib.h>
#include <string.h>
#include "tilemap.h"

static int index(const tilemap map, int x, int y);

tilemap tl_new(size_t item_size, int width, int height, int tile_size) {
	return tl_prealloc(item_size, width, height, tile_size, malloc(width * height * item_size), malloc(width * height * sizeof(bool)));
}

tilemap tl_prealloc(size_t item_size, int width, int height, int tile_size, char *buffer, bool *boolBuffer) {
	return (tilemap){width, height, tile_size, item_size, buffer, boolBuffer};
}

void *tl_get(tilemap map, int x, int y) {
	return map.buffer + (index(map) * map.tile);
}

void tl_set(tilemap map, const void *source, int x, int y) {
	memcpy(map.buffer, source, map.tile);
}

bool tl_free(tilemap map, int x, int y) {
	return map.boolBuffer[index(map, x, y)];
}

bool tl_empty(tilemap map, int x, int y, int width, int height) {
	for(int i = x; i < x + width; i += map.tile) {
		for(int j = y; j < y + height; j += map.tile) {
			if(!tl_free(map, i, j)) return false;
	return tl_free(map, x, y + height) && tl_free(map, x + width, y) && tl_free(map, x + width, y + height);
}

static int index(const tilemap map, int x, int y) {
	return x * map.height + y;
}
