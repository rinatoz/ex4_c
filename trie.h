#ifndef TRIE_H_
#define TRIE_H_
#define NUM_LETTERS ((int)26)
#define WORD 30

typedef enum { FALSE = 0, TRUE = 1 } boolean;

typedef struct node {
	char letter;
	char word[WORD];
	long unsigned int count;
	struct node* children[NUM_LETTERS];
} node;

node* _alloc();
void insert(node* head, char* str);
void freeAll(node* head);
void printFinal(node* head, int whichorder);



#endif /* TRIE_H_ */