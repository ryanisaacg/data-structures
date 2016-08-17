#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

#include <stdbool.h>

#include "util.h"

DEFSTRUCT(array_list);
struct array_list {
    size_t item_size;
    int length, capacity;
    void *buffer;
};

array_list al_new(size_t item_size);
array_list al_new_sized(size_t item_size, int init_capacity);
void *al_get(array_list *list, int index);
void al_add(array_list *list, void *item);
void al_remove_index(array_list *list, int index);
void al_remove_item(array_list *list, void *item);
void al_set(array_list *list, int index, void *data);
int al_index(array_list *list, void *item);
int al_size(array_list *list);
#endif