#pragma once

#include <stdbool.h>
#include "util.h"
#include "optional.h"
DEFSTRUCT(Slice);
/*
Create a Slice of a string for much faster string manipulation
Use pointer math to offset the beginning
*/
struct Slice {
	char* data;
	int len;
};
/*
Create a new Slice that is identical to the parameter string
*/
Slice new_slice(char* string);
/*
Create a new Slice that starts with the provided pointer with the given length
*/
Slice make_slice(char* string, int length);
/*
Checks if every character in each Slice matches to the same character in the same position
*/
bool equals(Slice s1, Slice s2);
/*
Checks if every character in the Slice matches every character in the string
*/
bool equals_string(Slice s1, char* data);
/*
Checks if s1 starts with s2
*/
bool starts_with(Slice s1, Slice s2);
/*
Checks to see if the Slice contains the character
*/
bool slice_contains(Slice s1, char c);
/*
Checks to see if a Slice is a numeric value
*/
bool is_numeric(Slice s);
/*
Convert the Slice to a string separate from the source
Useful if the string will be destroyed or the Slice must be printed to stdout
*/
char* evaluate(Slice s1);
/*
Gets a hash value for the slice
Useful for insertion into the hashmap
*/
int slice_hash(Slice s);
/*
Parses an int from a slice
*/
Optional parse_int(Slice s);
/*
Useful for hashmap, mostly
*/
bool slice_eq_voidptr(void *slice1, void *slice2);
/*
Convert an integer into a slice
*/
Slice int_to_slice(int number);
