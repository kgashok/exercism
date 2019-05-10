#include "matching_brackets.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const char* openers = "[{(";
const char* closers = "]})";

bool is_paired(const char* code) {
    char *stack = calloc(100, 1);

    for (; *code; code++) {
        const char* idx;
        // push the corresponding closer for an opener
        // on to the stack
        if((idx = strchr(openers, *code))){
            stack[strlen(stack)] = closers[idx-openers];
            stack[strlen(stack)+1] = '\0';
        }
        // does the closer match the token on the top of the
        // stack?
        if(strchr(closers, *code)) {
            if (stack[strlen(stack)-1] == *code)
                stack[strlen(stack)-1] = '\0';
            else
                return false;
        }
    }
    // if the stack is empty, then pairs are balanced
    return strlen(stack)? false: true;

}
