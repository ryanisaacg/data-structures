#pragma once

#include <stdbool.h>
#include "util.h"

DEFSTRUCT(Rectangle);
struct Rectangle {
	int x, y, width, height;
};

DEFSTRUCT(Vector2);
struct Vector2 {
	int x, y;
};

DEFSTRUCT(Circle);
struct Circle {
	int x, y, radius;
};

DEFSTRUCT(Shape);
struct Shape {
	enum { SHAPE_RECT, SHAPE_CIRC} type;
	union {
		Rectangle rectangle;
		Circle circ;
	} data;
};

Shape shape_rect(int x, int y, int width, int height);
Shape shape_circ(int x, int y, int radius);
int shape_x(Shape s);
int shape_y(Shape s);
int shape_left(Shape s);
int shape_right(Shape s);
int shape_top(Shape s);
int shape_bottom(Shape s);
void shape_set_pos(Shape *s, int x, int y);
bool shape_overlaps(Shape a, Shape b); 
bool shape_contains(Shape a, Vector2 point);

