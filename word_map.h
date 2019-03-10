#ifndef WORD_MAP
#define WORD_MAP

typedef struct entry {
  char* key;
  unsigned int value;
  unsigned int hash;
  struct entry* next;
} Entry;

Entry* entry(const char* key, unsigned int value);
void free_entry(Entry** entry);
unsigned int hash(Entry* entry);
unsigned int hash_key(char* str);
int putVal(Entry** map, Entry* entry, int map_length);
Entry* getVal(Entry** map, char* key, int map_length);
void printMap(Entry** map, int map_length);
void printEntry(Entry* entry);

#endif