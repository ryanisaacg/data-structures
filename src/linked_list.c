#include "linked_list.h"
#include "util.h"
#include <stdlib.h>

/************************
LIST
************************/

llist *ll_new() {
	llist *list = new(list);
	list->head = list->tail = NULL;
	return list;
}

llist *ll_duplicate(llist *list) {
	literator iterator = ll_iter_head(list);
	llist *newList = ll_new();
	while(ll_iter_has_next(&iterator)) {
		ll_add_last(newList, ll_iter_next(&iterator));
	}
	return newList;
}

void ll_add_first(llist *list, void *value) {
	lnode *node = new(node);
	node->data = value;
	node->next = list->head;
	if(list->head != NULL) {
		list->head->prev = node;
	}
	node->prev = NULL;
	list->head = node;
	if(list->tail == NULL) {
		list->tail = node;
	}
}

void ll_add_last(llist *list, void *value) {
	if(list->head == NULL) {
		ll_add_first(list, value);
	} else {
		lnode *node = new(node);
		node->data = value;
		node->prev = list->tail;
		if(list->tail != NULL) {
			list->tail->next = node;
		}
		node->next = NULL;
		list->tail = node;
	}
}

void ll_concat(llist *mutated, llist *newItems) {
    literator iterator = ll_iter_head(newItems);
    while(ll_iter_has_next(&iterator)) {
        ll_add_last(mutated, ll_iter_next(&iterator));
    }
}

void *ll_get_first(llist *list) {
	return list->head->data;
}

void *ll_get_last(llist *list) {
	return list->tail->data;
}

void *ll_remove_last(llist *list) {
	void *data = list->tail->data;
	if(list->head == list->tail) {
		free(list->head);
		list->head = list->tail = NULL;
	} else {
		lnode *tail = list->tail;
		list->tail = list->tail->prev;
		list->tail->next = NULL;
		free(tail);
	}
	return data;
}

void *ll_remove_first(llist *list) {
	void *data = list->head->data;
	if(list->head == list->tail) {
		free(list->head);
		list->head = list->tail = NULL;
	} else {
		lnode *head = list->head;
		list->head = list->head->next;
		list->head->prev = NULL;
		free(head);
	}
	return data;
}

bool ll_empty(llist *list) {
	return list->head == NULL;
}

void ll_clear(llist *list) {
	list->tail = NULL;
	while(list->head != NULL) {
		lnode *next = list->head->next;
		free(list->head);
		list->head = next;
	}
}

void ll_destroy(llist *list) {
	ll_clear(list);
	free(list);
}

void ll_delete_all(llist *list) {
	literator iterator = ll_iter_head(list);
	while(ll_iter_has_next(&iterator)) {
		free(ll_iter_next(&iterator));
	}
	ll_destroy(list);
}

int ll_size(llist *list) {
	int size = 0;
	literator iter = ll_iter_head(list);
	while(ll_iter_has_next(&iter)) {
		ll_iter_next(&iter);
		size += 1;
	}
	return size;
}

void *ll_get(llist *list, int index) {
	literator iterator = ll_iter_head(list);
	for(int i = 0; i < index; i++) {
		ll_iter_next(&iterator);
	}
	return ll_iter_next(&iterator);
}

/************************
ITERATOR
************************/

literator ll_iter_head(llist *list) {
	literator iterator;
	iterator.current = list->head;
	iterator.goesForward = true;
	iterator.origin = list;
	return iterator;
}

literator ll_iter_tail(llist *list) {
	literator iterator;
	iterator.current = list->tail;
	iterator.goesForward = false;
	iterator.origin = list;
	return iterator;
}

void *ll_iter_next(literator *iter) {
	if(iter->current == NULL) {
		return NULL;
	} else {
		void *value = iter->current->data;
		if(iter->goesForward) {
			iter->current = iter->current->next;
		} else {
			iter->current = iter->current->prev;
		}
		return value;
	}
}

bool ll_iter_has_next(literator *iter) {
	return iter->current != NULL;
}

void ll_iter_clear_to_current(literator *iter) {
	if(iter->current == NULL) {
		ll_clear(iter->origin);
	}
	if(ll_empty(iter->origin)) {
		return;
	}
	if(iter->goesForward) {
		lnode *current = iter->origin->head;
		while(current->next != iter->current) {
			lnode *next = current->next;
			free(current);
			current = next;
		}
		iter->origin->head = iter->current;
		iter->origin->head->prev = NULL;
	} else {
		lnode *current = iter->origin->tail;
		while(current->prev != iter->current) {
			lnode *prev = current->prev;
			free(current);
			current = prev;
		}
		iter->origin->tail = iter->current;
		iter->origin->tail->next = NULL;
	}
}

void ll_iter_clear_remaining(literator *iter) {
	if(iter->current == NULL) {
		return;
	}
	if(!iter->goesForward) {
		lnode *current = iter->origin->head;
		while(current->next != iter->current) {
			lnode *next = current->next;
			free(current);
			current = next;
		}
		iter->origin->head = iter->current;
		iter->origin->head->prev = NULL;
	} else {
		lnode *current = iter->origin->tail;
		while(current->prev != iter->current) {
			lnode *prev = current->prev;
			free(current);
			current = prev;
		}
		iter->origin->tail = iter->current;
		iter->origin->tail->next = NULL;
	}
}
