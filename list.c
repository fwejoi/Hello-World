#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void initList(PNode* pHead) {
    *pHead = (PNode)malloc(sizeof(Node));
    (*pHead)->_PNext = NULL;
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

