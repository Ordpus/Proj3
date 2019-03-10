#include <stdio.h>
#include "word_map.h"
#include <string.h>
#include <stdlib.h>

Entry* entry(const char* key, unsigned int value) {
  Entry* result = malloc(sizeof(Entry));
  result->key = calloc(strlen(key) + 1, sizeof(char));
  strcpy(result->key, key);
  result->value = value;
  return result;
}

void free_entry(Entry** entry) {
  Entry* temp = *entry;
  free(temp->key);
  free(temp);
  *entry = NULL;
}

void free_entries_in_map(Entry** map, int map_length) {
  for(int i = 0; i < map_length; ++i) {
    Entry* node = map[i];
    while(node) {
      Entry* temp = node;
      node = node->next;
      free_entry(&temp);
    }
  }
}

unsigned int hash(Entry* entry) {
  entry->hash = hash_key(entry->key);
  return entry->hash;
}

unsigned int hash_key(char* str) {
  int i = 0;
  unsigned int hash = 5381;
  while(str[i] != '\0') 
    hash = ((hash << 5) + hash) + str[i++];
  return hash;
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
      if(strcmp(node->key, entry->key) == 0) {
        node->value = entry->value;
        return 0;
      }
      if(!node->next) node->next = entry;
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
  printf("{ key: %s, value: %i, hash: %u }\n", entry->key, entry->value, entry->hash);
}

int main(void) {
  int map_length = 64;
  Entry* map[map_length];
  for(int i = 0; i < map_length; ++i)
    map[i] = NULL;
  char* c = "dfas";
  char* b[5] = {"sadjgkl", "adjsklghs", "dsajfjh", "jsadhodh", "dhsakj"};
  for(int i = 0; i < 5; ++i) {
    Entry* ent = entry(b[i], 3);
    putVal(map, ent, map_length);
  }
  printMap(map, map_length);
  free_entries_in_map(map, map_length);
}