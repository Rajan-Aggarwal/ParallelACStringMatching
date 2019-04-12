/**
* Author: 	Rajan
* File: 	trie.c
* Purpose: 	src file for the implementation of a basic trie 
*			(without backtracking functionality)
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/trie.h"

struct trie_node *get_node() {
	struct trie_node *newnode = NULL;
	newnode = (struct trie_node *)malloc(sizeof(struct trie_node));

	if (newnode) {
		for (int i=0; i<ASCII_SET_SZ; i++) {
			newnode->children[i] = NULL;
		}
		newnode->is_leaf = FALSE; 
	}

	return newnode;
}

void insert_pattern(struct trie_node *root, const char *pattern) {
	struct trie_node *cursor = root;
	int len = strlen(pattern);

	for (int i=0; i<len; i++) {
		int index = (int)pattern[i];  
		if (cursor->children[index] == NULL) {
			cursor->children[index] = get_node();
		} 
		cursor = cursor->children[index];
	}

	cursor->is_leaf = TRUE;

} 
