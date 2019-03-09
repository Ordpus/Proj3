#ifndef WORD_MAP
#define WORD_MAP

typedef struct entry {
  char key[32];
  int value;
  int hash;
  struct entry* next;
} Entry;

int hash(Entry* entry);
int hash_key(char* str);
int putVal(Entry** map, Entry* entry, int map_length);
Entry* getVal(Entry** map, char* key, int map_length);
void printMap(Entry** map, int map_length);
void printEntry(Entry* entry);

#endif
