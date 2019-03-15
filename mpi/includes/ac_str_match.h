#ifndef __AC_STR_MATCH_H
#define __AC_STR_MATCH_H

#define MAX_STR_LEN 100

void detect_patterns(struct trie_node *root, const char *input, int start); // outputs all the matched patterns to stdout

#endif /* __AC_STR_MATCH_H */