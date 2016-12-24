#include <stdlib.h>
#include <string.h>
#include "tilemap.h"

static int get_index(const TileMap map, int x, int y);

TileMap tl_new(size_t item_size, int width, int height, int tile_size) {
	return tl_prealloc(item_size, width, height, tile_size, malloc(width * height * item_size), 
			calloc(width * height * sizeof(bool), sizeof(bool)) );
}

TileMap tl_prealloc(size_t item_size, int width, int height, int tile_size, char *buffer, bool *boolBuffer) {
	return (TileMap){width, height, tile_size, item_size, buffer, boolBuffer};
}

void *tl_get(TileMap map, int x, int y) {
	return map.buffer + (get_index(map, x, y) * map.tile);
}

void tl_remove(TileMap map, int x, int y) {
	map.has[get_index(map, x, y)] = false;
}

void tl_set(TileMap map, const void *source, int x, int y) {
	map.has[get_index(map, x, y)] = true;
	memcpy(map.buffer + get_index(map, x, y), source, map.tile);
}

bool tl_free(TileMap map, int x, int y) {
	return x >= 0 && y >= 0 && x < map.width && y < map.height && !map.has[get_index(map, x, y)];
}

bool tl_empty(TileMap map, int x, int y, int width, int height) {
	for(int i = x; i < x + width; i += map.tile) {
		for(int j = y; j < y + height; j += map.tile) {
			if(!tl_free(map, i, j)) return false;
		}
	}
	return tl_free(map, x, y + height) && tl_free(map, x + width, y) && tl_free(map, x + width, y + height);
}

void tl_destroy(TileMap map) {
	free(map.buffer);
	free(map.has);
}

static int get_index(const TileMap map, int x, int y) {
	return x * map.height + y;
}
