#pragma once

typedef struct CFNode {
  void *data;
  struct CFNode *next;
} CFNode;

typedef struct CFStack {
  CFNode *top;
} CFStack;

void cf_stack_push(CFStack *stack, void *element);
void *cf_stack_pop(CFStack *stack);
