#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node {
    int32_t value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void pushBack(Node** head, int32_t value) {
    Node* new_node = createNode(value);
    if (*head == NULL) {
        *head = new_node;
    } 
    else {
        Node* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void deleteLastNode(Node** head) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        Node* temp = *head;
        Node* prev = NULL;

        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        free(temp);
        prev->next = NULL;
    }
}

void clearList(Node** head) {
    Node* current = *head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void printList(Node** head) {
    Node* current = (*head);
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* list = NULL;
    pushBack(&list, 26);
    pushBack(&list, 500);
    pushBack(&list, 250);
    printList(&list);
    deleteLastNode(&list);
    printList(&list);
    clearList(&list);
    return EXIT_SUCCESS;
}
