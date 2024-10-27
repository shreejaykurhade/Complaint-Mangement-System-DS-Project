// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"

#define SIZE 100
#define MAX_PRIORITY 5
#define MAX_TASKS 5

struct QueueNode {
    char task[SIZE];
    int priority;
    int token_number;
    struct QueueNode* link;
};

int get_priority(const char *task);
struct QueueNode* rearrange_queue(struct QueueNode* s);
void update_node_priorities(struct QueueNode* s);
struct QueueNode* adjust_priorities(struct QueueNode* s, int task_count[]);
struct QueueNode* enqueue(const char *task, struct QueueNode* s, int task_count[]);
void displayQueue(struct QueueNode* s);
struct QueueNode* dequeue(struct QueueNode* s, int task_count[], struct Stack* stk);

#endif
