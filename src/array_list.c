#include <stdlib.h>
#include <string.h>

#include "array_list.h"

ArrayList al_new(size_t item_size) {
    return al_new_sized(item_size, 10);
}

ArrayList al_new_sized(size_t item_size, int init_capacity) {
    ArrayList list = {item_size, 0, init_capacity, malloc(item_size * init_capacity)};
    return list;
}

void *al_get(ArrayList list, int index) {
    return list.buffer + list.item_size * index;
}

void al_add(ArrayList *list, void *item) {
    if(list->length < list->capacity) {
        al_set(list, list->length, item);
        list->length++;
    } else {
        list->capacity *= 2;
        list->buffer = realloc(list->buffer, list->capacity * list->item_size);
        al_add(list, item);
    }
}

void al_remove_index(ArrayList *list, int index) {
    memmove(list->buffer + list->item_size * index, list->buffer + list->item_size * (index + 1), list->length - index);
    list->length -= 1;
}

void al_remove_item(ArrayList *list, void *item) {
    al_remove_index(list, al_index(list, item));
}

int al_index(ArrayList *list, void *item) {
    int size = al_size(list);
    for(int i = 0; i < size; i++) {
        if(memcmp(al_get(*list, i), item, list->item_size) == 0) {
            return i;
        }
    }
    return -1;
}

void al_set(ArrayList *list, int index, void *data) {
    memcpy(list->buffer + index * list->item_size, data, list->item_size);
}

int al_size(ArrayList *list) {
    return list->length;
}
