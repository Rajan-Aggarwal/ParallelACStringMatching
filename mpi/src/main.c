#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "../includes/trie.h"
#include "../includes/ac_str_match.h"

#include "../includes/patterns.h"

const size_t NUMBER_OF_PATTERNS = sizeof(pattern_list) / sizeof(char *);

struct trie_node *add_patterns(struct trie_node *root) {
	for (int i=0; i<NUMBER_OF_PATTERNS; i++) {
		insert_pattern(root, pattern_list[i]);
	}
	return root;
}

int main(int argc, char *argv[]) {
	struct trie_node *root = get_node();
	add_patterns(root);
	return 0;
}