#pragma once

#include <sys/types.h>

typedef struct CFArray {
  void **elements;
  size_t element_size;
  size_t length;
  size_t reserved_length;
} CFArray;

CFArray *cf_array_new(size_t element_size);
void cf_array_push(CFArray *array, void *element);
void *cf_array_get(CFArray *array, size_t index);
void cf_array_remove(CFArray *array, size_t index);

void cf_array_resize(CFArray *array);
