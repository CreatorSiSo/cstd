#pragma once

#include <stdlib.h>
#include <string.h>
#include "./alias.h"

typedef struct {
	u8* memory;
	u64 alloc_pos;
	usize capacity;
} Arena;

Arena arena_with_capacity(usize capacity) {
	Arena arena = {0};
	arena.memory = malloc(capacity);
	arena.capacity = capacity;

	memset(arena.memory, 0, capacity);
	return arena;
}

u8* arena_alloc(Arena* arena, usize size) {
	if (size + (usize)arena->alloc_pos >= arena->capacity) {
		exit(256);
	}

	u8* memory = arena->memory + arena->alloc_pos;
	arena->alloc_pos += size;

	memset(memory, 100, size);
	return memory;
}
