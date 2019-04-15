/**
* Author: 	Rajan
* File: 	patterns.h
* Purpose: 	contains all the patterns that are detected by the 
*			accelerated AC string matching algorithm
**/

#ifndef __PATTERNS_H
#define __PATTERNS_H

/**
*	File consists of pattern list that are percieved threats for an IDS:
*		1. Reverse shell code
*		2. Reference to /bin/sh
*		3. Any executable
**/

extern const char *pattern_list[];

#endif /* __PATTERNS_H */