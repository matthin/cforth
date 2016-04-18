#include "cforth/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  struct cf_Stack *stack = malloc(sizeof(struct cf_Stack));

  char commands[] = "1 3 +";
  char *token = strtok(commands, " ");
  while (token != NULL) {
    if (strcmp(token, "+") == 0) {
      const int first = atoi(cf_stack_pop(stack));
      const int second = atoi(cf_stack_pop(stack));
      const int result = first + second;

      printf("%d\n", result);
    } else {
      cf_stack_push(stack, token);
    }

    token = strtok(NULL, " ");
  }

  return 0;
}
