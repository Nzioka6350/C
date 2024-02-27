#ifndef STACK_H
#define STACK_H

typedef struct {
    char *array;
    int capacity;
    int top;
} Stack;

Stack* createStack(int capacity);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, char item);
char pop(Stack* stack);
char peek(Stack* stack);
void freeStack(Stack* stack);

#endif
