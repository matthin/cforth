#include "cforth/hash.h"
#include <stdlib.h>

#define NUMBER_OF_BUCKETS 100

CFHashMap *cf_hash_new() {
  CFHashMap *hash_map = malloc(sizeof(CFHashMap));
  hash_map->buckets = cf_array_new(sizeof(CFArray) * NUMBER_OF_BUCKETS);

  // Initialize all the buckets.
  for (int i = 0; i < 100; ++i) {
    cf_array_push(hash_map->buckets, cf_array_new(sizeof(CFHashNode) * 5));
  }

  return hash_map;
}

void cf_hash_add(CFHashMap *hash_map, char *key, ValueType value) {
  const unsigned long hash = cf_hash_str(key);
  CFArray *bucket = cf_hash_find_bucket(hash_map, key);

  CFHashNode *node = malloc(sizeof(CFHashNode));
  node->key = key;
  node->value = value;
  node->hash = hash;

  cf_array_push(bucket, node);
}

ValueType cf_hash_get(CFHashMap *hash_map, char *key) {
  const unsigned long hash = cf_hash_str(key);
  CFArray *bucket = cf_hash_find_bucket(hash_map, key);

  for (int i = 0; i < bucket->length; ++i) {
    CFHashNode *element = (CFHashNode*) cf_array_get(bucket, i);
    if (hash == element->hash) {
      return element->value;
    }
  }

  return NULL;
}

unsigned long cf_hash_str(char *str) {
  unsigned long hash = 5487;
  int c;

  while (c = *str++) {
    hash = ((hash << 5) + hash) + c;
  }

  return hash;
}

CFArray *cf_hash_find_bucket(CFHashMap *hash_map, char *key) {
  const unsigned long hash = cf_hash_str(key);
  const int index = hash % NUMBER_OF_BUCKETS;
  return cf_array_get(hash_map->buckets, index);
}
