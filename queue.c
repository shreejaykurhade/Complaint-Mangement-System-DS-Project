// queue.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

int a = 1, b = 2, c = 3, d = 4, e = 5;

int get_priority(const char *task) {
    if (strcmp(task, "Complaint4") == 0) return b;
    else if (strcmp(task, "Complaint3") == 0) return c;
    else if (strcmp(task, "Complaint2") == 0) return d;
    else if (strcmp(task, "Complaint1") == 0) return e;
    else return a;
}

struct QueueNode* rearrange_queue(struct QueueNode* s) {
    struct QueueNode* sorted = NULL;
    struct QueueNode* current = s;
    while (current != NULL) {
        struct QueueNode* next = current->link;
        struct QueueNode* temporary = sorted, *prev = NULL;
        while (temporary != NULL && temporary->priority >= current->priority) {
            prev = temporary;
            temporary = temporary->link;
        }
        if (prev == NULL) {
            current->link = sorted;
            sorted = current;
        } else {
            prev->link = current;
            current->link = temporary;
        }
        current = next;
    }
    return sorted;
}

void update_node_priorities(struct QueueNode* s) {
    struct QueueNode* current = s;
    while (current != NULL) {
        current->priority = get_priority(current->task);
        current = current->link;
    }
}

struct QueueNode* adjust_priorities(struct QueueNode* s, int task_count[]) {
    if (task_count[a] > MAX_TASKS) {
        int temp = a; a = b; b = temp;
    } else if (task_count[b] > MAX_TASKS) {
        int temp = b; b = c; c = temp;
    } else if (task_count[c] > MAX_TASKS) {
        int temp = c; c = d; d = temp;
    } else if (task_count[d] > MAX_TASKS) {
        int temp = d; d = e; e = temp;
    }
    update_node_priorities(s);
    return rearrange_queue(s);
}

struct QueueNode* enqueue(const char *task, struct QueueNode* s, int task_count[]) {
    static int token_number = 1;
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (temp == NULL) {
        printf("Memory not allocated\n");
        return s;
    }
    strcpy(temp->task, task);
    temp->priority = get_priority(task);
    temp->token_number = token_number++;
    temp->link = NULL;
    task_count[temp->priority]++;
    if (s == NULL || s->priority < temp->priority) {
        temp->link = s;
        return temp;
    }
    struct QueueNode* current = s, *previous = NULL;
    while (current != NULL && current->priority >= temp->priority) {
        previous = current;
        current = current->link;
    }
    if (previous != NULL) previous->link = temp;
    temp->link = current;
    return adjust_priorities(s, task_count);
}

void displayQueue(struct QueueNode* s) {
    printf("Queue elements in order of removal:\n");
    struct QueueNode* q = s;
    if (q == NULL) {
        printf("Queue is empty\n");
    } else {
        while (q != NULL) {
            printf("Task: %s, Token number: %d, Priority: %d\n", q->task, q->token_number, q->priority);
            q = q->link;
        }
        printf("\n");
    }
}

struct QueueNode* dequeue(struct QueueNode* s, int task_count[], struct Stack* stk) {
    if (s == NULL) {
        printf("Queue is empty\n");
        return s;
    }
    struct QueueNode* temp = s;
    s = s->link;
    char resolved[SIZE];
    sprintf(resolved, "Task %s, Token %d resolved", temp->task, temp->token_number);
    push(stk, resolved);
    task_count[temp->priority]--;
    free(temp);
    return s;
}
