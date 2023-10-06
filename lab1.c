// lab1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"

char* readString(const char* fileName) {
    char* line = NULL;
    size_t len = 0;
    FILE* file = fopen(fileName, "r");
    
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

}
