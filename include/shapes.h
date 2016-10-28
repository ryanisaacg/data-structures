#pragma once

#include <stdbool.h>
#include "util.h"

DEFSTRUCT(rect);
struct rect {
	int x, y, width, height;
};

DEFSTRUCT(vector2);
struct vector2 {
	int x, y;
};

DEFSTRUCT(circle);
struct circle {
	int x, y, radius;
};

DEFSTRUCT(shape);
struct shape {
	enum { SHAPE_RECT, SHAPE_CIRC} type;
	union {
		rect rectangle;
		circle circ;
	} data;
};

shape shape_rect(int x, int y, int width, int height);
shape shape_circ(int x, int y, int radius);
int shape_x(shape s);
int shape_y(shape s);
int shape_left(shape s);
int shape_right(shape s);
int shape_top(shape s);
int shape_bottom(shape s);
void shape_set_pos(shape *s, int x, int y);
bool shape_overlaps(shape a, shape b); 
