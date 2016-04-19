#include "cforth/functions.h"
#include <stdlib.h>

void functions_add(CFStack *stack)  {
  const int first = atoi(cf_stack_pop(stack));
  const int second = atoi(cf_stack_pop(stack));

  int *result = malloc(sizeof(int));
  *result = first + second;
  cf_stack_push(stack, result);
}
