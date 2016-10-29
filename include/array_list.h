#pragma once

#include <stdbool.h>

#include "util.h"

DEFSTRUCT(ArrayList);
struct ArrayList {
    size_t item_size;
    int length, capacity;
    void *buffer;
};

ArrayList al_new(size_t item_size);
ArrayList al_new_sized(size_t item_size, int init_capacity);
void *al_get(ArrayList list, int index);
void al_add(ArrayList *list, void *item);
void al_remove_index(ArrayList *list, int index);
void al_remove_item(ArrayList *list, void *item);
void al_set(ArrayList *list, int index, void *data);
int al_index(ArrayList *list, void *item);
int al_size(ArrayList *list);
