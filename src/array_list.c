#include <stdlib.h>
#include <string.h>

#include "array_list.h"

alist al_new(size_t item_size) {
    return al_new_sized(item_size, 10);
}

alist al_new_sized(size_t item_size, int init_capacity) {
    alist list = {item_size, 0, init_capacity, malloc(item_size * init_capacity)};
    return list;
}

void *al_get(alist list, int index) {
    return list.buffer + list.item_size * index;
}

void al_add(alist *list, void *item) {
    if(list->length < list->capacity) {
        al_set(list, list->length, item);
        list->length++;
    } else {
        list->capacity *= 2;
        list->buffer = realloc(list->buffer, list->capacity * list->item_size);
        al_add(list, item);
    }
}

void al_remove_index(alist *list, int index) {
    memmove(list->buffer + list->item_size * index, list->buffer + list->item_size * (index + 1), list->length - index);
    list->length -= 1;
}

void al_remove_item(alist *list, void *item) {
    al_remove_index(list, al_index(list, item));
}

int al_index(alist *list, void *item) {
    int size = al_size(list);
    for(int i = 0; i < size; i++) {
        if(memcmp(al_get(*list, i), item, list->item_size) == 0) {
            return i;
        }
    }
    return -1;
}

void al_set(alist *list, int index, void *data) {
    memcpy(list->buffer + index * list->item_size, data, list->item_size);
}

int al_size(alist *list) {
    return list->length;
}
