#include "linked_list.h"
#include "util.h"
#include <stdlib.h>

/************************
LIST
************************/

LinkedList *ll_new() {
	LinkedList *list = new(list);
	list->head = list->tail = NULL;
	return list;
}

LinkedList *ll_duplicate(LinkedList *list) {
	LinkedIterator iterator = ll_iter_head(list);
	LinkedList *newList = ll_new();
	while(ll_iter_has_next(&iterator)) {
		ll_add_last(newList, ll_iter_next(&iterator));
	}
	return newList;
}

void ll_add_first(LinkedList *list, void *value) {
	LinkedNode *node = new(node);
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

void ll_add_last(LinkedList *list, void *value) {
	if(list->head == NULL) {
		ll_add_first(list, value);
	} else {
		LinkedNode *node = new(node);
		node->data = value;
		node->prev = list->tail;
		if(list->tail != NULL) {
			list->tail->next = node;
		}
		node->next = NULL;
		list->tail = node;
	}
}

void ll_concat(LinkedList *mutated, LinkedList *newItems) {
    LinkedIterator iterator = ll_iter_head(newItems);
    while(ll_iter_has_next(&iterator)) {
        ll_add_last(mutated, ll_iter_next(&iterator));
    }
}

void *ll_get_first(LinkedList *list) {
	return list->head->data;
}

void *ll_get_last(LinkedList *list) {
	return list->tail->data;
}

void *ll_remove_last(LinkedList *list) {
	void *data = list->tail->data;
	if(list->head == list->tail) {
		free(list->head);
		list->head = list->tail = NULL;
	} else {
		LinkedNode *tail = list->tail;
		list->tail = list->tail->prev;
		list->tail->next = NULL;
		free(tail);
	}
	return data;
}

void *ll_remove_first(LinkedList *list) {
	void *data = list->head->data;
	if(list->head == list->tail) {
		free(list->head);
		list->head = list->tail = NULL;
	} else {
		LinkedNode *head = list->head;
		list->head = list->head->next;
		list->head->prev = NULL;
		free(head);
	}
	return data;
}

bool ll_empty(LinkedList *list) {
	return list->head == NULL;
}

void ll_clear(LinkedList *list) {
	list->tail = NULL;
	while(list->head != NULL) {
		LinkedNode *next = list->head->next;
		free(list->head);
		list->head = next;
	}
}

void ll_destroy(LinkedList *list) {
	ll_clear(list);
	free(list);
}

void ll_delete_all(LinkedList *list) {
	LinkedIterator iterator = ll_iter_head(list);
	while(ll_iter_has_next(&iterator)) {
		free(ll_iter_next(&iterator));
	}
	ll_destroy(list);
}

int ll_size(LinkedList *list) {
	int size = 0;
	LinkedIterator iter = ll_iter_head(list);
	while(ll_iter_has_next(&iter)) {
		ll_iter_next(&iter);
		size += 1;
	}
	return size;
}

void *ll_get(LinkedList *list, int index) {
	LinkedIterator iterator = ll_iter_head(list);
	for(int i = 0; i < index; i++) {
		ll_iter_next(&iterator);
	}
	return ll_iter_next(&iterator);
}

/************************
ITERATOR
************************/

LinkedIterator ll_iter_head(LinkedList *list) {
	LinkedIterator iterator;
	iterator.current = list->head;
	iterator.goesForward = true;
	iterator.origin = list;
	return iterator;
}

LinkedIterator ll_iter_tail(LinkedList *list) {
	LinkedIterator iterator;
	iterator.current = list->tail;
	iterator.goesForward = false;
	iterator.origin = list;
	return iterator;
}

void *ll_iter_next(LinkedIterator *iter) {
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

bool ll_iter_has_next(LinkedIterator *iter) {
	return iter->current != NULL;
}

void ll_iter_clear_to_current(LinkedIterator *iter) {
	if(iter->current == NULL) {
		ll_clear(iter->origin);
	}
	if(ll_empty(iter->origin)) {
		return;
	}
	if(iter->goesForward) {
		LinkedNode *current = iter->origin->head;
		while(current->next != iter->current) {
			LinkedNode *next = current->next;
			free(current);
			current = next;
		}
		iter->origin->head = iter->current;
		iter->origin->head->prev = NULL;
	} else {
		LinkedNode *current = iter->origin->tail;
		while(current->prev != iter->current) {
			LinkedNode *prev = current->prev;
			free(current);
			current = prev;
		}
		iter->origin->tail = iter->current;
		iter->origin->tail->next = NULL;
	}
}

void ll_iter_clear_remaining(LinkedIterator *iter) {
	if(iter->current == NULL) {
		return;
	}
	if(!iter->goesForward) {
		LinkedNode *current = iter->origin->head;
		while(current->next != iter->current) {
			LinkedNode *next = current->next;
			free(current);
			current = next;
		}
		iter->origin->head = iter->current;
		iter->origin->head->prev = NULL;
	} else {
		LinkedNode *current = iter->origin->tail;
		while(current->prev != iter->current) {
			LinkedNode *prev = current->prev;
			free(current);
			current = prev;
		}
		iter->origin->tail = iter->current;
		iter->origin->tail->next = NULL;
	}
}
