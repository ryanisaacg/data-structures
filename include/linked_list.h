#pragma once

#include "util.h"
#include <stdbool.h>

DEFSTRUCT(LinkedList);
DEFSTRUCT(LinkedNode);
DEFSTRUCT(LinkedIterator);

struct LinkedNode {
	void *data;
	LinkedNode *next, *prev;
};
struct LinkedList {
	LinkedNode *head, *tail;
};
struct LinkedIterator {
	LinkedList *origin;
	LinkedNode *current;
	bool goesForward;
};

LinkedList *ll_new();
LinkedList *ll_duplicate(LinkedList *list);
void ll_add_first(LinkedList *list, void *value);
void ll_add_last(LinkedList *list, void *value);
void ll_concat(LinkedList *mutated, LinkedList *newItems);
void *ll_get_first(LinkedList *list);
void *ll_get_last(LinkedList *list);
void *ll_get(LinkedList *list, int index);
void *ll_remove_last(LinkedList *list);
void *ll_remove_first(LinkedList *list);
bool ll_empty(LinkedList *list);
void ll_clear(LinkedList *list);
void ll_destroy(LinkedList *list);
void ll_delete_all(LinkedList *list);
int ll_size(LinkedList *list);

LinkedIterator ll_iter_head(LinkedList *list);
LinkedIterator ll_iter_tail(LinkedList *list);
void *ll_iter_next(LinkedIterator *iter);
bool ll_iter_has_next(LinkedIterator *iter);
void ll_iter_clear_to_current(LinkedIterator *iter);
void ll_iter_clear_remaining(LinkedIterator *iter);
