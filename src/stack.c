#include "cforth/stack.h"
#include <stdlib.h>

void cf_stack_push(CFStack *stack, void *element) {
  CFNode *node = malloc(sizeof(CFNode));
  node->data = element;

  if (stack->top == NULL) {
    node->next = NULL;
  } else {
    node->next = stack->top;
  }

  stack->top = node;
}

void *cf_stack_pop(CFStack *stack) {
  if (stack->top == NULL) {
    return NULL;
  }

  void *temp = stack->top->data;
  stack->top = stack->top->next;
  return temp;
}
