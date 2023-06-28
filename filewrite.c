#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void writeToFile(PNode pHead) {
    FILE* file = fopen("result.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    PNode pNode = pHead->_PNext;
    while (pNode != NULL) {
        fprintf(file, "%s, %d\n", pNode->_data.name, pNode->_data.totalcount);
        pNode = pNode->_PNext;
    }

    fclose(file);
}
