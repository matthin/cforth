#include "cforth/array.h"
#include <stdlib.h>

CFArray *cf_array_new(const size_t element_size) {
  CFArray *array = malloc(sizeof(CFArray));
  array->element_size = element_size;
  cf_array_resize(array);
}

void cf_array_push(CFArray *array, void *element) {
  if (array->length == array->reserved_length) {
    cf_array_resize(array);
  }

  array->elements[array->length++] = element;
}

void *cf_array_get(CFArray *array, const size_t index) {
  return array->elements[index];
}

void cf_array_remove(CFArray *array, size_t index) {
  while (index < array->length) {
    array->elements[index] = array->elements[++index];
  }

  array->length--;
}

void cf_array_resize(CFArray *array) {
  array->reserved_length = (array->length + 50) * 1.5;
  array->elements = realloc(array->elements, array->reserved_length * array->element_size);
}
