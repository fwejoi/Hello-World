
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void initList(PNode* pHead) {
    *pHead = (PNode)malloc(sizeof(Node));
    (*pHead)->_PNext = NULL;
}

PNode createList() {
    PNode pHead = (PNode)malloc(sizeof(Node));
    if (pHead == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    pHead->_PNext = NULL;
    return pHead;
}

void insertNode(PNode pHead, char* name) {
    PNode pNewNode = (PNode)malloc(sizeof(Node));
    strcpy(pNewNode->_data.name, name);
    pNewNode->_data.totalcount = 1;
    pNewNode->_PNext = NULL;

    PNode pNode = pHead;
    while (pNode->_PNext != NULL) {
        pNode = pNode->_PNext;
    }
    pNode->_PNext = pNewNode;
}

void mergeNodes(PNode pHead) {
    if (pHead == NULL || pHead->_PNext == NULL) {
        return;
    }

    PNode pNode = pHead->_PNext;
    while (pNode != NULL) {
        PNode pTemp = pNode;
        while (pTemp->_PNext != NULL) {
            if (strcmp(pNode->_data.name, pTemp->_PNext->_data.name) == 0) {
                pNode->_data.totalcount++;
                PNode pDelete = pTemp->_PNext;
                pTemp->_PNext = pDelete->_PNext;
                free(pDelete);
            } else {
                pTemp = pTemp->_PNext;
            }
        }
        pNode = pNode->_PNext;
    }
}

void printList(PNode pHead) {
    PNode pNode = pHead->_PNext;
    while (pNode != NULL) {
        printf("%s, %d\n", pNode->_data.name, pNode->_data.totalcount);
        pNode = pNode->_PNext;
    }
}

void freeList(PNode pHead) {
    PNode pNode = pHead;
    while (pNode != NULL) {
        PNode pCurrent = pNode;
        pNode = pNode->_PNext;
        free(pCurrent);
    }
}

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
