/**
* Author: 	Rajan
* File: 	trie.h
* Purpose: 	header file for the implementation of a basic trie 
*			(without backtracking functionality)
**/

#ifndef __TRIE_H
#define __TRIE_H

#define FALSE 0
#define TRUE !FALSE

#define ASCII_SET_SZ 128
#define MAX_STR_LEN 100

/**
* A struct for a node of the trie
* Each node has 128 possible children (each denoting a character)
* Leaf node has is_leaf = TRUE
**/
struct trie_node {
	struct trie_node *children[ASCII_SET_SZ]; 	// only one child can have non-null value
	int is_leaf; 								// denotes end of a word or pattern matched
};

/**
* This function allocated memory and returns a trie node
* with is_leaf = FALSE
* and all children as NULL
**/
struct trie_node *get_node(); 										

/**
*	use struct trie_node *root = get_node(); to initialize the trie
**/

/**
* This function inserts a given pattern in the trie
**/
void insert_pattern(struct trie_node *root, const char *pattern); 	

#endif /* __TRIE_H */

