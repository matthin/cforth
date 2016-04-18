#pragma once

typedef struct cf_Node {
  void *data;
  struct cf_Node *next;
} cf_Node;

struct cf_Stack {
  cf_Node *top;
};

void cf_stack_push(struct cf_Stack *stack, void *element);
void *cf_stack_pop(struct cf_Stack *stack);
