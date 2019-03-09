#ifndef __TRIE_H
#define __TRIE_H

#define FALSE 0
#define TRUE !FALSE

#define ASCII_SET_SZ 128

struct trie_node {
	struct trie_node *children[ASCII_SET_SZ];
	int is_leaf;
}

struct trie_node *get_node(); 

void insert_pattern(struct trie_node *root, char *pattern); 

void string_matching(struct trie_node *root, char *string, int start_index); //look for any pattern match and print

#endif /* __TRIE_H */



