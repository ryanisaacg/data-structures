#include "shapes.h"

shape shape_rect(int x, int y, int width, int height) {
	rect r = {x, y, width, height};
	shape s;
	s.type = SHAPE_RECT;
	s.data.rectangle = r;
	return s;
}

shape shape_circ(int x, int y, int radius) {
	circle c = {x, y, radius};
	shape s;
	s.type = SHAPE_CIRC;
	s.data.circ = c;
	return s;
}

int shape_x(shape s) {
	return s.data.circ.x;
}

int shape_y(shape s) {
	return s.data.circ.y;
}

int shape_left(shape s) {
	switch(s.type) {
	case SHAPE_RECT:
		return s.data.rectangle.x;
	case SHAPE_CIRC:
		return s.data.circ.x - s.data.circ.radius;
	}
	return 0;
}

int shape_right(shape s) {
	switch(s.type) {
	case SHAPE_RECT:
		return s.data.rectangle.x + s.data.rectangle.width;
	case SHAPE_CIRC:
		return s.data.circ.x + s.data.circ.radius;
	}
	return 0;
}

int shape_top(shape s) {
	switch(s.type) {
	case SHAPE_RECT:
		return s.data.rectangle.y;
	case SHAPE_CIRC:
		return s.data.circ.y - s.data.circ.radius;
	}
	return 0;
}

int shape_bottom(shape s) {
	switch(s.type) {
	case SHAPE_RECT:
		return s.data.rectangle.y + s.data.rectangle.height;
	case SHAPE_CIRC:
		return s.data.circ.y + s.data.circ.radius;
	}
	return 0;
}

void shape_set_pos(shape *s, int x, int y) {
	s->data.circ.x = x;
	s->data.circ.y = y;
}

bool shape_overlaps(shape a, shape b) {
	return false;
}

bool shape_contains(shape s, vector2 point) {
	switch(s.type) {
	case SHAPE_RECT: {
		rect r = s.data.rectangle;
		return point.x >= r.x && point.y >= r.y && point.x < r.x + r.width && point.y < r.y + r.height;
	}
	case SHAPE_CIRC: {
		circ c = s.data.circ;
		int x = c.x - point.x;
		int y = c.y - point.y;
		return radius * radius >= x * x + y * y;
	}
}

