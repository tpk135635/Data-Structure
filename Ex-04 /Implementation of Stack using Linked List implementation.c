#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct StackLL {
    Node *top;
} StackLL;

StackLL* createStackLL() {
    StackLL *stack = (StackLL*)malloc(sizeof(StackLL));
    stack->top = NULL;
    return stack;
}

int isEmptyLL(StackLL *stack) {
    return stack->top == NULL;
}

void pushLL(StackLL *stack, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int popLL(StackLL *stack) {
    if (isEmptyLL(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node *temp = stack->top;
    int poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedData;
}

void displayLL(StackLL *stack) {
    if (isEmptyLL(stack)) {
        printf("Stack is empty\n");
        return;
    }
    Node *current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    StackLL *stackLL = createStackLL();

    pushLL(stackLL, 10);
    pushLL(stackLL, 20);
    pushLL(stackLL, 30);
    pushLL(stackLL, 40);
    pushLL(stackLL, 50);

    printf("Popped element is %d\n", popLL(stackLL));
    displayLL(stackLL);

    return 0;
}
