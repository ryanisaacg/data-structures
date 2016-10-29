#include "optional.h"
#include <stdio.h>
#include <stdlib.h>

Optional op_empty() {
	return op_wrap(NULL);
}

Optional op_wrap(void *data) {
	Optional op;
	op.data = data;
	op.has = data != NULL;
	return op;
}

void *op_get(Optional op) {
	if(!op.has) {
		fprintf(stderr, "Attempt to get from empty Optional.");
		exit(-1);
	}
	return op.data;
}

bool op_has(Optional op) {
	return op.has;
}

void *op_if_else(Optional op, void *default_val) {
	if(op.has)
		return op.data;
	else
		return default_val;
}
