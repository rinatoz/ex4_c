#include <stdio.h>
#include <string.h>
#include "trie.h"

#define WORD 30

int main(int argc, char* argv[]) {
	int flag = 1;
	if (argc == 2)
		if (**(argv + 1) == 'r')
			flag = 0;

	node* trie = _alloc();
	char c = 0;
	char word[WORD];

	while ((c = getchar()) != EOF) {
		int index = 0;
		while (c != '\n' && c != '\t' && c != ' ') {
			if ((c >= 97 && c <= 122) ||(c>=65&&c<=92)) {
				word[index] = c;
				index++;
			}
			c = getchar();
		}
		word[index] = 0;
		if (strlen(word) > 0) {
			insert(trie, word);
		}
	}

	printFinal(trie, flag);
	freeAll(trie);
	return 0;
}