/**
* Author: 	Vishnu
* File: 	main.cu
* Purpose: 	Brings the entire project together. Inits a trie, 
* 			adds patterns to it, reads the input file
* 			detect patterns given in patterns.h (if any)
* 			and prints them stdout
**/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "../include/trie.h"
#include "../include/ac_str_match.h"

#include "../include/patterns.h"

#define MAX_INPUT_SZ 500

const char *input_file_path = "../files/input_stream.txt";

const char *pattern_list[] = {
	// 1.
	"bash -i >& /dev/tcp/",
	"subprocess.call",
	"sprintf",
	"exec",
	"nc",

	// 2.
	"/bin",
	"/sh",

	// 3.
	".pl",
	".php",
	".py",
	".sh"
};

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

void initializePatterns(char *patterns, int *indices) {
	int idx_cnt = 0, pat_cnt = 0;
	indices[idx_cnt++] = 0;
	for(int i=0;i<NUMBER_OF_PATTERNS;i++) {
		indices[idx_cnt] = indices[idx_cnt++-1] + strlen(pattern_list[i]);
		for(int j=0;j<strlen(pattern_list[i]);j++) {
			patterns[pat_cnt++] = pattern_list[i][j];
		}
	}
	patterns[pat_cnt] = '\0';
}

int main(int argc, char *argv[]) {

	struct trie_node *root = get_node(); 									// initialize a trie
	add_patterns(root); 													// add patterns from the header file

	char *input_buffer = (char *)malloc(sizeof(char) * MAX_INPUT_SZ);		// initialize buffer
	FILE *fhandle = fopen(input_file_path, "r");							// open file as read-only
	size_t ret = fread(input_buffer, sizeof(char), MAX_INPUT_SZ, fhandle); 	// read file into the buffer

	int* indices = (int*)malloc(sizeof(int) * (NUMBER_OF_PATTERNS+1));
	int* matches = (int*)calloc(NUMBER_OF_PATTERNS, sizeof(int));
	char *patterns = (char*)malloc(sizeof(char) * 1024);

	initializePatterns(patterns, indices);

	int *d_indices, *d_matches;
	char *d_patterns, *d_input;

	cudaMalloc((void**)&d_indices, sizeof(int) * (NUMBER_OF_PATTERNS+1));
	cudaMalloc((void**)&d_patterns, sizeof(char) * strlen(patterns));
	cudaMalloc((void**)&d_input, sizeof(char) * ret);
	cudaMalloc((void**)&d_matches, sizeof(int) * NUMBER_OF_PATTERNS);

	cudaMemcpy(d_indices, indices, sizeof(int) * (NUMBER_OF_PATTERNS+1), cudaMemcpyHostToDevice);
	cudaMemcpy(d_matches, matches, sizeof(int) * NUMBER_OF_PATTERNS, cudaMemcpyHostToDevice);
	cudaMemcpy(d_patterns, patterns, sizeof(char) * strlen(patterns), cudaMemcpyHostToDevice);
	cudaMemcpy(d_input, input_buffer, sizeof(char) * ret, cudaMemcpyHostToDevice);

	int len = strlen(input_buffer);
	dim3 grid_size(ret,1,1);
	dim3 block_size(NUMBER_OF_PATTERNS, 1, 1);
	
	detect_patterns<<<grid_size, block_size>>>(d_input, d_patterns, d_indices, d_matches, len);

	cudaDeviceSynchronize();

	cudaMemcpy(matches, d_matches, sizeof(int) * NUMBER_OF_PATTERNS, cudaMemcpyDeviceToHost);

	char buffer[1024];
	int cnt = 0;
	for(int i=0;i<NUMBER_OF_PATTERNS;i++) {
		if(matches[i] == 1) {
			cnt = 0;
			for(int j=indices[i];j<indices[i+1];j++) {
				buffer[cnt++] = patterns[j];
			}
			buffer[cnt] = '\0';
			printf("Pattern %s has been found!\n", buffer);
		}
	}
	
	cudaFree(d_input);
	cudaFree(d_patterns);
	cudaFree(d_indices);
	cudaFree(d_matches);

	free(input_buffer);
	free(patterns);
	free(indices);
	free(matches);

	return 0;
}
