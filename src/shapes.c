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
	if(a.type == SHAPE_RECT && b.type == SHAPE_RECT) { 
		rect r1 = a.data.rectangle;
		rect r2 = b.data.rectangle;
		return r1.x < r2.x + r2.width && r1.x + r1.width > r2.x && r1.y < r2.y + r2.height && r1.y + r1.height > r2.y;
	} else if(a.type == SHAPE_CIRC && b.type == SHAPE_CIRC) {
		circle c1 = a.data.circ;
		circle c2 = b.data.circ;
		int x = c1.x - c2.x;
		int y = c1.y - c2.y;
		int radius = c1.radius + c2.radius;
		return radius * radius >= x * x + y * y;
	} else if(a.type == SHAPE_RECT) {
		rect r = a.data.rectangle;
		circle c = b.data.circ;
		int x = c.x;
		int y = c.y;
		if (c.x < r.x) {
			x = r.x;
		} else if (c.x > r.x + r.width) {
			x = r.x + r.width;
		}
		if (c.y < r.y) {
			y = r.y;
		} else if (c.y > r.y + r.height) {
			y = r.y + r.height;
		}
		x = x - c.x;
		y = y - c.y;
		return x * x + y * y < c.radius * c.radius;
	} else {
		return shape_overlaps(b, a); //only write code to cover rect - circle
	}
}

bool shape_contains(shape s, vector2 point) {
	switch(s.type) {
	case SHAPE_RECT: {
		rect r = s.data.rectangle;
		return point.x >= r.x && point.y >= r.y && point.x < r.x + r.width && point.y < r.y + r.height;
		}
	case SHAPE_CIRC: {
		circle c = s.data.circ;
		int x = c.x - point.x;
		int y = c.y - point.y;
		return c.radius * c.radius >= x * x + y * y;
		}
	}
	return false;
}

