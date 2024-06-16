#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void insertAfter(struct Node* prevNode, int value) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(value);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct Node* findElement(struct Node* head, int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct Node* findNext(struct Node* node) {
    if (node != NULL && node->next != NULL) {
        return node->next;
    }
    return NULL;
}

struct Node* findPrevious(struct Node* head, struct Node* node) {
    if (head == node) {
        return NULL;
    }
    struct Node* current = head;
    while (current != NULL && current->next != node) {
        current = current->next;
    }
    return current;
}

int isLast(struct Node* node) {
    return (node != NULL && node->next == NULL);
}

int isEmpty(struct Node* head) {
    return (head == NULL);
}

void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAfter(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("Invalid previous node\n");
        return;
    }
    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp);
}

void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* secondLast = *head;
    while (secondLast->next->next != NULL) {
        secondLast = secondLast->next;
    }
    free(secondLast->next);
    secondLast->next = NULL;
}

void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAfter(head, 15);

    printf("Initial list:\n");
    displayList(head);

    int searchValue = 15;
    struct Node* searchResult = findElement(head, searchValue);
    if (searchResult != NULL) {
        printf("Element %d found in the list\n", searchValue);
    } else {
        printf("Element %d not found in the list\n", searchValue);
    }

    deleteFirst(&head);
    deleteAfter(head);
    deleteLast(&head);

    printf("List after deletions:\n");
    displayList(head);

    deleteList(&head);
    return 0;
}
