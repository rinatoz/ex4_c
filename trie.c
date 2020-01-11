#include "trie.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_LETTERS ((int)26)
#define WORD 30

node* _alloc() {
	node* p = (node*)calloc(1, sizeof(node));
	return p;
}


void insert(node* head, char* str) {
	node* current = head;
	while (*str) {
		char c = *str;
		if (c >= 65 && c <= 92)
		{
			c = c + 32;
		}
		if (current->children[c - 97] == NULL) {
			current->children[c - 97] = (node*)calloc(1, sizeof(node));
			current->children[c - 97]->letter = c;
			strcpy(current->children[c - 97]->word, current->word);
			int index_last = strlen(current->children[c - 97]->word);
			current->children[c - 97]->word[index_last] = c;
		}
		current = current->children[c - 97];
		str++;
	}
	current->count++;

}

void freeAll(node* head) {
	if (head == NULL)
		return;
	for (int i = 0; i < NUM_LETTERS; i++)
	{
		freeAll(head->children[i]);
	}
	free(head);
	return;
}


void printFinal(node* head, int whichorder) {
	if (head == NULL)
		return;
	if (head->count >0)
		printf("%s\t%ld\n", head->word, head->count);

	if (whichorder == 1) {
		for (int i = 0; i < NUM_LETTERS; i++)  // z to a
			printFinal(head->children[i], 1);
	}
	if (whichorder == 0)
	{
		for (int i =0; i <= NUM_LETTERS - 1; i++)   //regular print (a to z)
			printFinal(head->children[NUM_LETTERS - 1-i], 0);
	}

}
