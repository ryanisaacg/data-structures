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
