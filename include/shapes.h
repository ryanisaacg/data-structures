#pragma once

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
