#ifndef HEAD_H
#define HEAD_H

typedef struct {
    char name[100];
    int totalcount;
} Data;

typedef struct Node {
    Data _data;
    struct Node* _PNext;
} Node, *PNode;

void initList(PNode* pHead);
void insertNode(PNode pHead, char* name);
void mergeNodes(PNode pHead);
void printList(PNode pHead);
void freeList(PNode pHead);
void writeToFile(PNode pHead);
void readFile(PNode pHead, const char* filename, int num_records);

#endif  // HEAD_H
