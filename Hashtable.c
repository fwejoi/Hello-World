#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hashtable.h"

#define MAX_BUCKETS 100
#define MULTIPLIER 31

#define LENGTH 30
typedef struct User_login {
    char name[LENGTH];
    int totalcount;
} ELementType; //链表的节点

typedef struct SListNode {
    ELementType data;
    struct SListNode* next;
} Node, *PNode, *List; //封装链表节点和next指针

static PNode table[MAX_BUCKETS];

/*创建一个节点*/
static PNode walloc(const char* str) {
    PNode p = (PNode)malloc(sizeof(Node));
    if (p != NULL) {
        strcpy(p->data.name, str);
        p->data.totalcount = 0;
        p->next = NULL;
    }
    return p;
}

/*计算哈希值*/
static unsigned long hashstring(const char* str) {
    unsigned long hash = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        hash = hash * MULTIPLIER + str[i];
    }
    return hash % MAX_BUCKETS;
}

/*在一个链表中查找人名，找到返回指针，找不到返回NULL*/
static PNode find(PNode wp, const char* str) {
    PNode curr;
    for (curr = wp; curr != NULL; curr = curr->next) {
        if (strcmp(curr->data.name, str) == 0) {
            return curr;
        }
    }
    return NULL;
}

/*将在散列表中查找相应节点，并进行相应操作，找到返回指针，没找到则创建节点并加入散列表,并返回指针*/
static PNode lookup(const char* str) {
    unsigned long hash = hashstring(str);
    PNode wp = table[hash];
    PNode curr = NULL;

    curr = find(wp, str);
    if (!curr) {
        curr = walloc(str);
        curr->next = table[hash];
        table[hash] = curr;
    }

    return curr;
}

/*删除散列表*/
static void cleartable() {
    int i;
    for (i = 0; i < MAX_BUCKETS; i++) {
        PNode wp = table[i];
        while (wp) {
            PNode p = wp;
            wp = wp->next;
            free(p);
        }
        table[i] = NULL;
    }
}

/*读取文件，创建散列表*/
void file_read_ht() {
    FILE* fp = fopen("user_login.txt", "r");
    char word[1024];
    char* name;

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    memset(table, 0, sizeof(table));

    int count = 0;
    while (fscanf(fp, "%s", word) == 1) {
        name = strtok(word, ",");
        if (name != NULL) {
            PNode node = lookup(name);
            node->data.totalcount++;
            count++;
        }
    }
    printf("%d\n", count);
    fclose(fp);
}
