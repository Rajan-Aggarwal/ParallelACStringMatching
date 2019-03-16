/**
* Author: 	Rajan
* File: 	ac_str_match.h
* Purpose: 	header file for the implementation of accelerated 
*			AC string matching algorithm	
**/

#ifndef __AC_STR_MATCH_H
#define __AC_STR_MATCH_H

#define MAX_STR_LEN 100

/**
* This function takes in a trie and an input buffer and parses the input from start to finish
* to detect patterns and, outputs patterns to stdout.
**/
void detect_patterns(struct trie_node *root, char *input, int start); 

#endif /* __AC_STR_MATCH_H */