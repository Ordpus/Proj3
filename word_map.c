#include <stdio.h>
#include "word_map.h"
#include <string.h>

int hash(Entry* entry) {
  entry->hash = hash_key(entry->key);
  return entry->hash;
}

int hash_key(char* str) {
  int i = 0;
  int result = 0;
  while(str[i] != '\0') 
    result = 31 * result + str[i++];
  return result;
}

int putVal(Entry** map, Entry* entry, int map_length) {
  hash(entry);
  int i = (map_length - 1) & entry->hash; 
  if(map[i] == NULL) {
    map[i] = entry;
    return 0;
  } else {
    Entry* node = map[i];
    while(node) {
      printf("%s\n", node->key);
      if(strcmp(node->key, entry->key) == 0) {
        node->value = entry->value;
        return 0;
      }
      if(!node->next) {
        node->next = entry;
        return 0;
      }
      node = node->next;
    }
    return 0;
  }
  return -1;
}

Entry* getVal(Entry** map, char* key, int map_length) {
  int hash = hash_key(key);
  int i = (map_length - 1) & hash;
  Entry* node = map[i];
  while(node) {
    if(strcmp(node->key, key) == 0) return node;
    node = node->next;
  }
  return NULL;
}

void printMap(Entry** map, int map_length) {
  for(int i = 0; i < map_length; ++i) {
    Entry* node = map[i];
    while(node) {
      printEntry(node);
      node = node->next;
    }
  }
}

void printEntry(Entry* entry) {
  printf("{ key: %s, value: %i }\n", entry->key, entry->value);
}

int main(void) {
  Entry* map[32];
  for(int i = 0; i < 32; ++i)
    map[i] = NULL;
  Entry a = {"asdsa", 1, -1, NULL};
  Entry b = {"asdasdf", 1, -1, NULL};
  Entry c = {"dggsfs", 1, -1, NULL};
  Entry d = {"asdffe3", 1, -1, NULL};
  Entry e = {"aeefd", 1, -1, NULL};
  Entry f = {"asdffe3", 5, -1, NULL};
  printf("aaa\n");
  putVal(map, &a, 32);
  printf("aaa\n");
  putVal(map, &b, 32);
  putVal(map, &c, 32);
  putVal(map, &d, 32);
  putVal(map, &e, 32);
  putVal(map, &f, 32);
  putVal(map, &a, 32);
  printMap(map, 32);
}
