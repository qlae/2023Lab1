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

    if (getline(&line, &len, file) == -1) {
        perror("Error reading line");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
    return line;
}

