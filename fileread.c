#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void readFile(PNode pHead, const char* filename, int num_records) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[100];
    int count = 0;
    while (fgets(line, sizeof(line), file) && count < num_records) {
        char* username = strtok(line, ",");
        insertNode(pHead, username);
        count++;
    }
 

    fclose(file);
}
