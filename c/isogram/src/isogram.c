#include "isogram.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// implementation of a case-insensitive strchr
// returns 0 if `t` is not found in string `s`
const char *strichr(const char *s, int t) {
  char it = tolower(t);
  do
    if (tolower(*s) == it) return s;
  while (*s++);
  return NULL;
}

// if the char 'needle' occurs more than once,
// function will return true
bool is_duplicate(const char *hay, const char needle) {
  const char *found = strichr(hay, needle);
  return strichr(++found, needle) != NULL;
}

// returns true if the text has no duplicates
// If 'check_only_alpha' is set, duplicate checking is 
// limited to alphabets only
bool has_no_duplicates(const char *text, bool check_only_alpha) {
  char c;
  while ((c = *text)) {
    if (check_only_alpha && !isalpha(c)) {
      text++;
      continue;
    }
    if (is_duplicate(text, c)) return false;
    text++;
  }
  return true;
}

// calling has_no_duplicate with 'true' so that duplicate
// checking is invoked only on alphabets
bool is_isogram(const char *text) {
  return has_no_duplicates(text, true);
}