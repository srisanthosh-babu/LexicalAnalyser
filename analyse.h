#ifndef ANALYSE_H
#define ANALYSE_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Max sizes
#define MAX_TOKEN_LEN 100
#define MAX_KEYWORDS  32

// Function prototypes
int isKeyword(const char *word);
void analyseFile(const char *filename);

#endif
