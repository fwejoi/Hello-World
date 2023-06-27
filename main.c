#include <stdio.h>
#include <stdlib.h>
#include "head.h" // 包含头文件

// 声明 fileread.c 中的函数
void readFile(const char* filename, PNode pHead);

// 声明 filewrite.c 中的函数
void writeToFile(PNode pHead);

int main() {
    PNode pHead = createList(); // 创建链表

    readFile("user_login.txt", pHead); // 调用读取文件的函数

    // 执行其他操作...

    writeToFile(pHead); // 调用将链表写入文件的函数

    return 0;
}
