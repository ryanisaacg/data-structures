#pragma once

#include <stdbool.h>
#include "util.h"

DEFSTRUCT(optional);
struct optional {
	void *data;
	bool has;
};

optional op_empty();
optional op_wrap(void *data);
void *op_get(optional op);
bool op_has(optional op);
void *op_if_else(optional op, void *default_val);
