#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"

char* readString(const char* fileName) {
    char* line = (char*)malloc(MAX_LINE_LEN + 1); 
    if (line == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    FILE* file = fopen(fileName, "r"); 
    if (file == NULL) {
        perror("Error opening file");
        free(line); 
        exit(EXIT_FAILURE);
    }

    if (fgets(line, MAX_LINE_LEN + 1, file) == NULL) {
        perror("Error reading line");
        free(line); 
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
    return line;
}

char* mysteryExplode(const char* str) {
    int len = strlen(str);
    char* result = (char*)malloc(len * (len + 1) + 1);

    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            result[index++] = str[j];
        }
    }

    result[index] = '\0';
    return result;
}
