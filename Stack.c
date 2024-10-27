// stack.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

struct Stack* createStack() {
    struct Stack* stk = (struct Stack*)malloc(sizeof(struct Stack));
    stk->topElement = NULL;
    return stk;
}

int isEmptyStack(struct Stack* stk) {
    return stk->topElement == NULL;
}

void push(struct Stack* stk, const char* string) {
    struct Node* new_Node = (struct Node*)malloc(sizeof(struct Node));
    if (new_Node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_Node->data = (char*)malloc(strlen(string) + 1);
    if (new_Node->data == NULL) {
        printf("Memory allocation for string failed\n");
        exit(1);
    }
    strcpy(new_Node->data, string);
    new_Node->link = stk->topElement;
    stk->topElement = new_Node;
    printf("Pushed to stack: %s\n", string);
}

char* pop(struct Stack* stk) {
    if (isEmptyStack(stk)) {
        printf("Stack Underflow. Stack is empty.\n");
        return NULL;
    }
    struct Node* temporary = stk->topElement;
    stk->topElement = stk->topElement->link;
    char* poppedData = temporary->data;
    free(temporary);
    return poppedData;
}

void displayStack(struct Stack* stack) {
    struct Node* current_ele = stack->topElement;
    if (isEmptyStack(stack)) {
        printf("Resolved tasks stack is empty.\n");
        return;
    }
    printf("Resolved tasks (most recently completed):\n");
    while (current_ele != NULL) {
        printf("%s\n", current_ele->data);
        current_ele = current_ele->link;
    }
    printf("\n");
}
