#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* data;
    struct Node* link;
};

struct Stack {
    struct Node* top;
};

// Function to create an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, const char* string) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    newNode->data = (char*)malloc(strlen(string) + 1);
    if (newNode->data == NULL) {
        printf("Memory allocation for string failed\n");
        exit(1);
    }
    
    strcpy(newNode->data, string);
    newNode->link = stack->top;
    stack->top = newNode;
    printf("Pushed: %s\n", string);
}

// Function to pop an element from the stack
char* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow. Stack is empty.\n");
        return NULL;
    }
    
    struct Node* temp = stack->top;
    stack->top = stack->top->link;
    
    char* poppedData = temp->data;
    free(temp);
    
    return poppedData;
}

// Function to display the stack
void display(struct Stack* stack) {
    struct Node* current = stack->top;
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack contents:\n");
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->link;
    }
    printf("\n");
}

// Main function to test the stack
int main() {
    struct Stack* stack = createStack();

    push(stack, "Hello");
    push(stack, "World");
    push(stack, "Stack");
    
    display(stack);

    char* popped = pop(stack);
    if (popped != NULL) {
        printf("Popped: %s\n", popped);
        free(popped); // Free the popped string memory
    }
    
    display(stack);

    // Clean up remaining stack nodes
    while (!isEmpty(stack)) {
        char* data = pop(stack);
        if (data != NULL) free(data);
    }
    free(stack); // Free the stack itself

    return 0;
}
