#include "array_list.h"
#include "shapes.h"
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

int shape_tests() {
	shape s1, s2, s3;
	s1 = shape_rect(0, 0, 16, 16);
	s2 = shape_circ(15, 16, 3);
	s3 = shape_rect(17, 2, 1, 3);
	ASSERT(shape_x(s1) == 0, 1, "shape_x for rects");
	ASSERT(shape_x(s2) == 15, 2, "shape_x for circ");
	ASSERT(shape_y(s3) == 2, 3, "shape_y for rects");
	ASSERT(shape_y(s2) == 16, 4, "shape_y for circ");
	ASSERT(shape_overlaps(s1, s2), 5, "Rectangle - circle overlap");
	ASSERT(!shape_overlaps(s2, s3), 6, "Circle - rectangle overlap");
	ASSERT(shape_overlaps(s1, s1), 7, "Rectangle - rectangle overlap");
	ASSERT(!shape_overlaps(s1, s3), 8, "Rectangle - rectangle overlap #2");
	shape_set_pos(&s1, 5, 5);
	ASSERT(shape_top(s1) == 5, 9, "shape_top and shape_set_pos for rects");
	shape_set_pos(&s2, 300, 300);
	ASSERT(!shape_overlaps(s1, s2), 10, "shape_set_pos for circ");
	return 0;
}

int main(int argc, char *argv[]) {
	if(argc == 1) return -1;
	else if(strcmp(argv[1], "al") == 0) {
		return al_tests();
	}
	return 0;
}
