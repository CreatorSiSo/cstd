#pragma once

#include "./lib.h"

typedef struct String {
	u8* data;
	usize len;
} String;

String String_new(Arena* arena) {
	String string = {0};
	// string.data = arena_alloc(arena, len + 1);
	// memset(string.data, 32, len);
	// string.data[len] = 0;
	// string.len = len;
	return string;
}

// TODO Is there any way to make this safer
char* str_to_cstr(String* self) {
	return (char*)self->data;
}
