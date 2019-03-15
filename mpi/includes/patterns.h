#ifndef __PATTERNS_H
#define __PATTERNS_H

/**
*	File consists of pattern list that are percieved threats for an IDS:
*		1. Reverse shell code
*		2. Reference to /bin/sh
*		3. Any executable
**/

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

#endif /* __PATTERNS_H */