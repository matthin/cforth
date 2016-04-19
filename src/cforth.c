#include "cforth/array.h"
#include "cforth/functions.h"
#include "cforth/hash.h"
#include "cforth/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  CFStack *stack = malloc(sizeof(CFStack));
  CFHashMap *functions = cf_hash_new();

  cf_hash_add(functions, "+", functions_add);

  char commands[] = "1 3 +";
  char *token = strtok(commands, " ");
  while (token != NULL) {
    ValueType function = cf_hash_get(functions, token);
    if (function != NULL) {
      (*function)(stack);
    } else {
      cf_stack_push(stack, token);
    }

    token = strtok(NULL, " ");
  }

  printf("%d\n", *(int*) cf_stack_pop(stack));

  return 0;
}
