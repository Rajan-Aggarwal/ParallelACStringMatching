#ifndef __TRIE_H
#define __TRIE_H

#define FALSE 0
#define TRUE !FALSE

#define ASCII_SET_SZ 128
#define MAX_STR_LEN 100

struct trie_node {
	struct trie_node *children[ASCII_SET_SZ]; // only one can have non-null value
	int is_leaf; // denotes end of a word or pattern matched
};

struct trie_node *get_node(); // memory allocation

/*
	use struct trie_node *root = get_node(); to initialize the trie
*/

void insert_pattern(struct trie_node *root, char *pattern); 

#endif /* __TRIE_H */



