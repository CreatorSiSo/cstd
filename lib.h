#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// ALIAS {

typedef enum {
	false = 0,
	true = !false
} bool;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef intptr_t isize;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint64_t u64;
typedef uintptr_t usize;

// }

// DEBUG {

static void print_bytes(const void *object, usize size) {
  const u8* const bytes = object;
  printf("[ ");
  for(usize i = 0; i < size; i++) {
    printf("%02x ", bytes[i]);
  }
  printf("]\n");
}

// }

// ARENA {

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

// }

// STRING {

typedef struct String {
	u8* data;
	usize len;
} String;

String str_alloc(Arena* arena, usize len) {
	String string = {0};
	string.data = arena_alloc(arena, len + 1);
	memset(string.data, 32, len);
	string.data[len] = 0;
	string.len = len;
	return string;
}
