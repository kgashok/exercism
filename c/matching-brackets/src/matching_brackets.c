#include "matching_brackets.h"

#include <stdio.h>

bool is_paired(const char* code) {
    printf("***** %s\n", code);
    if (code[0] != code[1])
        return true;
    return false;
}
