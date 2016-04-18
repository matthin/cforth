#include "cforth/stack.h"
#include <stdlib.h>

void cf_stack_push(struct cf_Stack *stack, void *element) {
  struct cf_Node *node = malloc(sizeof(struct cf_Node));
  node->data = element;

  if (stack->top == NULL) {
    node->next = NULL;
  } else {
    node->next = stack->top;
  }

  stack->top = node;
}

void *cf_stack_pop(struct cf_Stack *stack) {
  if (stack->top == NULL) {
    return NULL;
  }

  void *temp = stack->top->data;
  stack->top = stack->top->next;
  return temp;
}
