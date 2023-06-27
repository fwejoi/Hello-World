#ifndef HEAD_H
#define HEAD_H

#define LENGTH 30

typedef struct User_login {
    char name[LENGTH];    // 用户名
    int totalcount;       // 登录次数
} SDataType;

typedef struct SListNode {
    SDataType _data;
    struct SListNode* _PNext;
} Node, *PNode;

void initList(PNode* pHead);
void insertNode(PNode pHead, char* name);
void mergeNodes(PNode pHead);
void printList(PNode pHead);
void freeList(PNode pHead);
void writeToFile(PNode pHead);

#endif
