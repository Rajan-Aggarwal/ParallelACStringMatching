#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/trie.h"
#include "../includes/ac_str_match.h"

void detect_patterns(struct trie_node *root, char *input, int start) {
	int len = strlen(input);

	char buffer[MAX_STR_LEN];
	int bufcount = 0;

	struct trie_node *cursor = root;

	for (int i=start; i<len; i++) {
		int index = (int)input[i];
		if (cursor->children[index]) {
			buffer[bufcount++] = input[i];
			cursor = cursor->children[index];
			if (cursor->is_leaf) {
				printf("Pattern %s has been found!\n", buffer);
				return;
			}
		} 
		else return;
	}
}