#include "array_list.h"
#include <stdio.h>
#include <string.h>

#define ASSERT(cond, err, msg) if(!(cond)) { fprintf(stderr, "Test failed:\t%s", msg);  return (err); }

int al_tests() {
	alist list = al_new(sizeof(int));
	int temp = 5;
	al_add(&list, &temp);
	temp = 6;
	al_add(&list, &temp);
	int *extract = al_get(list, 0);
	ASSERT(*extract == 5, 1, "add and get #1");
	extract = al_get(list, 1);
	ASSERT(*extract == 6, 2, "add and get #2");
	int i;
	for(i = 0; i < 15; i++)
		al_add(&list, &i);
	ASSERT(list.length == 17, 3, "length tracking");
	extract = al_get(list, 16);
	ASSERT(*extract == 14, 4, "array growing");
	return 0;
}

int main(int argc, char *argv[]) {
	if(argc == 1) return -1;
	else if(strcmp(argv[1], "al") == 0) {
		return al_tests();
	}
	return 0;
}
