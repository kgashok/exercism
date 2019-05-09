#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "word_count.h"

// to get around the warning for the compiler on Ubuntu (c9)
char *strdup(const char *);

// returns the object if the text matches the token
// NULL if no match is found
word_count_word_t *find_word(const char *token, word_count_word_t *words,
                             int i) {
  while (i--)
    if (!strcmp(token, words[i].text))
      return &words[i];
  return NULL;
}

// convert all characters in string to lower_case
char *str_to_lower(char *t) {
  char *start = t;
  do
    *t = tolower(*t);
  while (*t++);
  return start;
}

char *strip_pair_of_quotes(char *token) {
  char quote = '\'';
  if (token && *token == quote) {
    token++; // skip the 1st quote
    *strchr(token, quote) = '\0'; // terminate at the 2nd quote
  }
  return token;
}

int word_count(const char *input_text, word_count_word_t *words) {
  // clear out any previous values to 0
  memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);

  char *text = strdup(input_text);
  char delims[40];
  const char *wspace = " \n";
  const char *punctuations = "'!\"#$%&()*+,-./:;<=>?@[\\]^_`{|}~";
  strcpy(delims, wspace);
  strcat(delims, punctuations+1); // skip the apostrophe

  char *token = strtok(text, delims);
  int idx = 0; // doubles as an index and counter for words
  while (token && *token) {
    // normalize the token
    token = str_to_lower(strip_pair_of_quotes(token));
    // check if it is already in the list of words
    word_count_word_t *loc = find_word(token, words, idx);
    if (loc) { 
      // increment counter for already existing word
      loc->count += 1;
    } else {
      if (idx >= MAX_WORDS) {
        idx = EXCESSIVE_NUMBER_OF_WORDS;
        break;
      }
      if (strlen(token) > MAX_WORD_LENGTH) {
        idx = EXCESSIVE_LENGTH_WORD;
        break;
      }
      strcpy(words[idx].text, token);
      words[idx].count = 1;
      idx++;
    }
    // get the next token
    token = strtok(NULL, delims);
  }
  free(text);
  return idx;
}