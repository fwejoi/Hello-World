#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char username[50];
    int login_count;
    struct Node* next;
} Node;

Node* createNode(char* username) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->username, username);
    newNode->login_count = 1;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, char* username) {
    if (*head == NULL) {
        *head = createNode(username);
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        if (strcmp(temp->username, username) == 0) {
            temp->login_count++;
            return;
        }
        temp = temp->next;
    }
    if (strcmp(temp->username, username) == 0) {
        temp->login_count++;
        return;
    }
    temp->next = createNode(username);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("Username: %s, Login Count: %d\n", temp->username, temp->login_count);
        temp = temp->next;
    }
}

void freeList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* current = temp;
        temp = temp->next;
        free(current);
    }
}

int main() {
    FILE* file = fopen("user_login.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    Node* head = NULL;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char* username = strtok(line, " \n");
        insertNode(&head, username);
    }
    fclose(file);
    
    printList(head);
    freeList(head);
    
    return 0;
}
