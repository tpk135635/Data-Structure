#include <stdio.h>
#include <stdlib.h>

typedef struct StackArray {
    int *array;
    int top;
    int capacity;
} StackArray;

StackArray* createStackArray(int capacity) {
    StackArray *stack = (StackArray*)malloc(sizeof(StackArray));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFullArray(StackArray *stack) {
    return stack->top == stack->capacity - 1;
}

int isEmptyArray(StackArray *stack) {
    return stack->top == -1;
}

void pushArray(StackArray *stack, int item) {
    if (isFullArray(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int popArray(StackArray *stack) {
    if (isEmptyArray(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

void displayArray(StackArray *stack) {
    if (isEmptyArray(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    StackArray *stackArray = createStackArray(5);

    pushArray(stackArray, 10);
    pushArray(stackArray, 20);
    pushArray(stackArray, 30);
    pushArray(stackArray, 40);
    pushArray(stackArray, 50);

    printf("Popped element is %d\n", popArray(stackArray));
    displayArray(stackArray);

    return 0;
}
