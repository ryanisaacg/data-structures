#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "slice.h"
#include "util.h"
#include "optional.h"

Slice new_slice(char* string) {
	return make_slice(string, strlen(string));
}

Slice make_slice(char* string, int length) {
	Slice s;
	s.data = string;
	s.len = length;
	return s;
}

bool equals(Slice s1, Slice s2) {
	if(s1.len != s2.len)
		return false;
	for(int i = 0; i < s1.len; i++) {
		if(s1.data[i] != s2.data[i]) {
			return false;
		}
	}
	return true;
}

bool starts_with(Slice s1, Slice s2) {
	if(s1.len < s2.len) {
		return false;
	}
	for(int i = 0; i < s2.len; i++) {
		if(s1.data[i] != s2.data[i]) {
			return false;
		}
	}
	return true;
}

bool equals_string(Slice s1, char* data) {
	int string_length = strlen(data);
	if(s1.len != string_length) {
		return false;
	}
	for(int i = 0; i < s1.len; i++) {
		if(s1.data[i] != data[i]) {
			return false;
		}
	}
	return true;
}

char* evaluate(Slice str) {
	char *string = array(string, str.len);
	int i = 0;
	for(; i < str.len; i++) {
		string[i] = str.data[i];
	}
	string[i] = '\0';
	return string;
}

bool slice_contains(Slice s1, char c) {
	for(int i = 0; i < s1.len; i++) {
		if(s1.data[i] == c) {
			return true;
		}
	}
	return false;
}

int slice_hash(Slice s) {
	unsigned hash;
	int i;
    for(hash = i = 0; i < s.len; ++i)
    {
        hash += s.data[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

bool is_numeric(Slice s) {
	bool period = false;
	for(int i = 0; i < s.len; i++) {
		if(s.data[i] > '9' || s.data[i] < '0') {
			if(s.data[i] == '.') {
				if(period) {
					return false;
				} else {
					period = true;
				}
			} else {
				return false;
			}
		}
	}
	return s.len > 0;
}

Optional parse_int(Slice s) {
	if(!is_numeric(s) || slice_contains(s, '.'))
		return op_empty();
	else {
		int value = 0;
		for(int i = 0; i < s.len; i++) {
			value *= 10;
			value += s.data[i] - '0';
		}
		int *boxed = new(boxed);
		*boxed = value;
		return op_wrap(boxed);
	}
}

bool slice_eq_voidptr(void *slice1, void *slice2) {
	Slice *a = slice1;
	Slice *b = slice2;
	return equals(*a, *b);
}

Slice int_to_slice(int number) {
    if(number == 0) 
        return new_slice("0");
    else 
    {
        int characters = (int)ceil(log10(number)) + 1;
        if(number < 0)
            characters ++;
        char *str = string(characters);
        for(int i = characters - 1; number != 0; i--) {
            str[i] = number % 10 + '0';
            number /= 10;
        }
        if(number < 0)
            str[0] = '-';
        return new_slice(str);
    }
}

