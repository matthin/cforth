#include "cforth/array.h"
#include "cforth/words.h"
#include "cforth/hash.h"
#include "cforth/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  CFStack *stack = malloc(sizeof(CFStack));
  CFHashMap *words = cf_hash_new();

  cf_hash_add(words, "+", words_add);
  cf_hash_add(words, "-", words_minus);
  cf_hash_add(words, "*", words_multiply);
  cf_hash_add(words, "/", words_divide);
  cf_hash_add(words, ".", words_print);

  char commands[] = "2 3 + 4 * .";
  char *token = strtok(commands, " ");
  while (token != NULL) {
    ValueType word = cf_hash_get(words, token);
    if (word != NULL) {
      (*word)(stack);
    } else {
      int *entry = malloc(sizeof(int));
      *entry = atoi(token);
      cf_stack_push(stack, entry);
    }

    token = strtok(NULL, " ");
  }

  return 0;
}
