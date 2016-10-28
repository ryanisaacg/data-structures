#pragma once

#include <stdbool.h>

#include "util.h"

DEFSTRUCT(alist);
struct alist {
    size_t item_size;
    int length, capacity;
    void *buffer;
};

alist al_new(size_t item_size);
alist al_new_sized(size_t item_size, int init_capacity);
void *al_get(alist list, int index);
void al_add(alist *list, void *item);
void al_remove_index(alist *list, int index);
void al_remove_item(alist *list, void *item);
void al_set(alist *list, int index, void *data);
int al_index(alist *list, void *item);
int al_size(alist *list);
