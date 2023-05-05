#pragma once

#include "./alias.h"
#include "./arena.h"
#include "./math.h"
#include "./string.h"

static void print_bytes(const void* object, usize size) {
  const u8* const bytes = object;
  printf("[ ");
  for (usize i = 0; i < size; i++) {
    printf("%02x ", bytes[i]);
  }
  printf("]\n");
}

typedef struct List {
  // Pointer to the start of the data
  void* m_ptr;
  // Size of one item
  usize m_size;
  // Capacity
  usize m_cap;
  // Current length
  usize len;
} List;

void List_alloc(List* const self) {
  usize new_size = self->m_cap * self->m_size;
  printf("cap: %li\n", self->m_cap);
  printf("new size: %li\n", new_size);
  // free(self->m_ptr);
  // self->m_ptr = calloc(self->m_cap, self->m_size);
  self->m_ptr = realloc(self->m_ptr, self->m_cap * self->m_size);
}

List List_new(usize size) {
  List self = {0};
  self.m_cap = 0;
  self.m_size = size;
  // self.m_size = max(size, sizeof(u32));
  List_alloc(&self);

  printf("List {\n  ptr: %p,\n  size: %li,\n  cap: %li,\n  len: %li,\n}\n",
         self.m_ptr, self.m_size, self.m_cap, self.len);

  return self;
}

void* List_get(const List* const self, usize index) {
  if (index >= self->len) {
    printf("Out of bounds access!\n");
    abort();
  }
  printf("adress: %li\n", (usize)(self->m_ptr + index * self->m_size));
  return self->m_ptr + (index * self->m_size);
}

#define List_push(self, item)                             \
  {                                                       \
    self.len += 1;                                        \
    if (self.len >= self.m_cap) {                         \
      self.m_cap = self.len * 2;                          \
      List_alloc(&self);                                  \
    }                                                     \
    *(typeof(item)*)List_get(&self, self.len - 1) = item; \
  }

void List_dealloc(List* const self) { free(self->m_ptr); }
