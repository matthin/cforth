#pragma once

#include "cforth/array.h"
#include "cforth/stack.h"

// Used to easily switch around value types.
typedef void (*ValueType)(CFStack* stack);

typedef struct CFHashNode {
  char *key;
  ValueType value;
  unsigned long hash;
} CFHashNode;

typedef struct CFHashMap {
  CFArray *buckets;
} CFHashMap;

CFHashMap *cf_hash_new();

void cf_hash_add(CFHashMap *hash_map, char *key, ValueType value);

/**
 *  Grabs the value associated with a specific key.
 *  @return The associated key, or NULL if the key doesn't exist.
 */
ValueType cf_hash_get(CFHashMap *hash_map, char *key);

unsigned long cf_hash_str(char *str);
CFArray *cf_hash_find_bucket();
