/**
* Author: 	Vishnu
* File: 	ac_str_match.cu
* Purpose: 	src file for the implementation of the accelerated 
*			AC string matching algorithm
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/trie.h"
#include "../include/ac_str_match.h"

__global__ void detect_patterns(char *input, char *patterns, int *indices, int *matches, int len) {
	int start = blockIdx.x;
	int idx = threadIdx.x;

	int beg = indices[idx], end = indices[idx+1];

	if((len-start+1) >= (end-beg+1)) {
		int index = start;
		for(int i=beg;i<end;i++) {
			if(patterns[i] != input[index++]) {
				return;
			}
		}
		matches[idx] = 1;
	}
}
