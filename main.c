#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main() {
    const char* filename = "user_login.txt";
    int num_records = 10000;

    PNode head;
    initList(&head);

    readFile(head, filename, num_records);

    mergeNodes(head);

    printList(head);

    writeToFile(head);


    return 0;
}
