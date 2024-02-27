#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

char* infixToPostfix(char* infix) {
    int length = strlen(infix);
    char* postfix = (char*)malloc((length + 1) * sizeof(char));
    Stack* stack = createStack(length);
    int i, j;

    for (i = 0, j = 0; i < length; i++) {
        char currentChar = infix[i];

        if (isalnum(currentChar)) {
            postfix[j++] = currentChar;
        } else if (currentChar == '(') {
            push(stack, currentChar);
        } else if (currentChar == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Invalid expression\n");
                free(postfix);
                freeStack(stack);
                return NULL;
            } else {
                pop(stack); // Pop '('
            }
        } else if (isOperator(currentChar)) {
            while (!isEmpty(stack) && getPrecedence(peek(stack)) >= getPrecedence(currentChar)) {
                postfix[j++] = pop(stack);
            }
            push(stack, currentChar);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';

    freeStack(stack);

    return postfix;
}

int main() {
    char infix[100];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Remove newline character if present
    if (infix[strlen(infix) - 1] == '\n') {
        infix[strlen(infix) - 1] = '\0';
    }

    char* postfix = infixToPostfix(infix);

    if (postfix != NULL) {
        printf("Postfix expression: %s\n", postfix);
        free(postfix);
    }

    return 0;
}