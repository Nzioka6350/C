#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->array[stack->top--];
}

char peek(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->array[stack->top];
}

void freeStack(Stack* stack) {
    free(stack->array);
    free(stack);
}
