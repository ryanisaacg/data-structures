#pragma once

#include "util.h"
#include <stdbool.h>

DEFSTRUCT(llist);
DEFSTRUCT(lnode);
DEFSTRUCT(literator);

struct lnode {
	void *data;
	lnode *next, *prev;
};
struct llist {
	lnode *head, *tail;
};
struct literator {
	llist *origin;
	lnode *current;
	bool goesForward;
};

llist *ll_new();
llist *ll_duplicate(llist *list);
void ll_add_first(llist *list, void *value);
void ll_add_last(llist *list, void *value);
void ll_concat(llist *mutated, llist *newItems);
void *ll_get_first(llist *list);
void *ll_get_last(llist *list);
void *ll_get(llist *list, int index);
void *ll_remove_last(llist *list);
void *ll_remove_first(llist *list);
bool ll_empty(llist *list);
void ll_clear(llist *list);
void ll_destroy(llist *list);
void ll_delete_all(llist *list);
int ll_size(llist *list);

literator ll_iter_head(llist *list);
literator ll_iter_tail(llist *list);
void *ll_iter_next(literator *iter);
bool ll_iter_has_next(literator *iter);
void ll_iter_clear_to_current(literator *iter);
void ll_iter_clear_remaining(literator *iter);
