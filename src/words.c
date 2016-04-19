#include "cforth/words.h"
#include <stdio.h>
#include <stdlib.h>

void words_add(CFStack *stack)  {
  const int second = atoi(cf_stack_pop(stack));
  const int first = atoi(cf_stack_pop(stack));

  int *result = malloc(sizeof(int));
  *result = first + second;
  cf_stack_push(stack, result);
}

void words_minus(CFStack *stack)  {
  const int second = atoi(cf_stack_pop(stack));
  const int first = atoi(cf_stack_pop(stack));

  int *result = malloc(sizeof(int));
  *result = first - second;
  cf_stack_push(stack, result);
}

void words_multiply(CFStack *stack)  {
  const int second = atoi(cf_stack_pop(stack));
  const int first = atoi(cf_stack_pop(stack));

  int *result = malloc(sizeof(int));
  *result = first * second;
  cf_stack_push(stack, result);
}

void words_divide(CFStack *stack)  {
  const int second = atoi(cf_stack_pop(stack));
  const int first = atoi(cf_stack_pop(stack));

  int *result = malloc(sizeof(int));
  *result = first / second;
  cf_stack_push(stack, result);
}

void words_print(CFStack *stack) {
  printf("%d\n", *((int*) cf_stack_pop(stack)));
}
