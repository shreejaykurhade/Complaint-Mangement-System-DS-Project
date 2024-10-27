// stack.h
#ifndef STACK_H
#define STACK_H

struct Node {
    char* data;
    struct Node* link;
};

struct Stack {
    struct Node* topElement;
};

struct Stack* createStack();
int isEmptyStack(struct Stack* stk);
void push(struct Stack* stk, const char* string);
char* pop(struct Stack* stk);
void displayStack(struct Stack* stack);

#endif
