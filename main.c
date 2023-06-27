#include <stdio.h>
#include "head.h" // 包含头文件

int main() {
    PNode pHead = createList(); // 创建链表

    readFile("user_login.txt", pHead); // 读取文件

    mergeNodes(pHead); // 合并节点

    writeToFile(pHead); // 输出文件

    destroyList(pHead); // 销毁链表

    return 0;
}
