#include <stdio.h>

#include "../src/lib.h"

int main() {
  List nums = List_new(sizeof(u8));

  for (usize i = 0; i < 9; i += 1) {
    List_push(nums, i);
    printf("%i\n", *(u8*)List_get(&nums, i));
  }

  print_bytes(nums.m_ptr, nums.m_cap * nums.m_size);

  List_dealloc(&nums);
  return 0;
}
