#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strdup(const char *s);

char *abbreviate(const char *phrase) {
  char *text;
  if (!phrase || !*phrase || !(text = strdup(phrase)))
    return NULL;

  char *acronym = calloc(20, 1);
  char *delims = "- _";
  int idx = 0;

  char *token = strtok(text, delims);
  while (token) {
    acronym[idx++] = toupper(*token);
    token = strtok(NULL, delims);
  }
  free(text);
  return acronym;
}