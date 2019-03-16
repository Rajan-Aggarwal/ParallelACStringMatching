/**
* Author: 	Rajan
* File: 	main.c
* Purpose: 	Brings the entire project together. Inits a trie, 
* 			adds patterns to it, reads the input file
* 			detect patterns given in patterns.h (if any)
* 			and prints them stdout
**/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include <mpi.h>

#include "../includes/trie.h"
#include "../includes/ac_str_match.h"

#include "../includes/patterns.h"

#define MAX_INPUT_SZ 500

const char 	*input_file_path 	= "../files/input_stream.txt";
const size_t NUMBER_OF_PATTERNS = sizeof(pattern_list) / sizeof(char *);

/**
* This function adds patterns to the initialized trie
**/
struct trie_node *add_patterns(struct trie_node *root) {
	for (int i=0; i<NUMBER_OF_PATTERNS; i++) {
		insert_pattern(root, pattern_list[i]);
	}
	return root;
}

int main(int argc, char *argv[]) {

	struct trie_node *root = get_node(); 									// initialize a trie
	add_patterns(root); 													// add patterns from the header file

	char *input_buffer = (char *)malloc(sizeof(char) * MAX_INPUT_SZ);		// initialize buffer
	FILE *fhandle = fopen(input_file_path, "r");							// open file as read-only
	size_t ret = fread(input_buffer, sizeof(char), MAX_INPUT_SZ, fhandle); 	// read file into the buffer  

	if (MPI_Init(&argc, &argv) != MPI_SUCCESS) {
		fprintf(stderr, "Unable to initialize MPI\n");
	}

	int rank;
	int size;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 				// get rank of the process
	MPI_Comm_size(MPI_COMM_WORLD, &size); 				// get number of processes

	if (rank < ret) {
		detect_patterns(root, input_buffer, rank); 		// allot each character to each rank 
	}

	MPI_Finalize();

	return 0;
}