#pragma once

#include <stdbool.h>
#include "util.h"

DEFSTRUCT(Optional);
struct Optional {
	void *data;
	bool has;
};

Optional op_empty();
Optional op_wrap(void *data);
void *op_get(Optional op);
bool op_has(Optional op);
void *op_if_else(Optional op, void *default_val);
