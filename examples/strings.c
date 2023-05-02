#include <stdio.h>
#include "../lib.h"

int main() {
	Arena arena = arena_with_capacity(256);
	String string1 = str_alloc(&arena, 20);
	String string2 = str_alloc(&arena, 20);
	String string3 = str_alloc(&arena, 20);
	arena_alloc(&arena, 100);
	print_bytes(arena.memory, arena.capacity);
	printf("~%s~ ~%s~ ~%s~", string1.data, string2.data, string3.data);
	return 0;
}
