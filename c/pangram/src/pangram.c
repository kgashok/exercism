#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// implementation of a case-insensitive strchr
// returns 0 if `t` is not found in string `s` 
const char *strichr(const char *s, int t) {
  if (!s) return NULL; 
  
  char it = tolower(t);
  do
    if (tolower(*s) == it) return s;
  while (*s++);
  return NULL;
}

bool is_pangram(const char *sentence) {
  for (char letter = 'a'; letter <= 'z'; letter++)
    if (!strichr(sentence, letter)) return false;
  return true;
}