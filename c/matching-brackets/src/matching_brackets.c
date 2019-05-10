#include "matching_brackets.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const char* openers = "[{(";
const char* closers = "]})";

bool is_paired(const char* code) {
    char *stack = calloc(100, 1);
    int top = -1; // empty stack

    for (; *code; code++) {
        const char* idx;
        // push the corresponding closer for an opener
        // on to the stack
        if((idx = strchr(openers, *code)))
            stack[++top] = closers[idx-openers];

        // does the closer match the token on the top of the
        // stack?
        if(strchr(closers, *code)) {
            if (stack[top] == *code)
                top--;
            else
                return false;
        }
    }
    // if the stack is empty, then pairs are balanced
    return top == -1? true: false;

}
