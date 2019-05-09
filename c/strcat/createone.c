#include <string.h> 
#include <assert.h> 
#include <stdlib.h>
#include <stdio.h> 

char *mystrcat (char *target, char *source) { 
    //return strcat(target, source); 
    
    while (*target) target++; 
    while ((*target++ = *source++));
    return --target;
    
}

/*#define STRING_SIZE 594503
#define ARRAY_SIZE 14
*/

#define STRING_SIZE 100000
#define ARRAY_SIZE  15000

char string[STRING_SIZE]; 

int create_one (int ss, int as) {
    /*if (ss > STRING_SIZE) 
        ss = STRING_SIZE;
    if (as > ARRAY_SIZE) 
        as = ARRAY_SIZE;
    */
    
    for (int i = 0; i < ss; i++) 
        string[i] = 'a';
    string[ss] = '\0'; 
    
    char *char_array[as];
    for (int i = 0; i < as; i++) {
        char_array[i] = string; 
    }
    
    char *one = (char *) malloc(ss * as + 1);
    //char *one = malloc(8190000 + 100000);
    if (one != NULL) { 
        printf("malloc succeed! "); 
    }
    
    char *onep = one;
    for (int i = 0; i < as; i++) {
        onep = mystrcat(onep, char_array[i]); 
    }
    //assert (strlen(one) == ss * as); 

    printf("%dMB\n", ss  * as / 1000000);
    return strlen(one);
}

#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>


int main() {
  struct rusage usage;
  struct timeval start, end;
  int i, j, k = 0;

  getrusage(RUSAGE_SELF, &usage);
  start = usage.ru_stime;
  
  create_one(STRING_SIZE, ARRAY_SIZE);
  
  getrusage(RUSAGE_SELF, &usage);
  end = usage.ru_stime;

  printf("Started at: %ld.%lds\n", start.tv_sec, start.tv_usec);
  printf("Ended at: %ld.%lds\n", end.tv_sec, end.tv_usec);
  return 0;
}
