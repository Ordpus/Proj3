
typedef struct Word{
	char* name;
	int count;
	struct Word* next;
} WORD;



WORD* is_contain(char* name, WORD* head);

void word_insert(char* word, WORD** dprt);

void word_print(WORD* head);

