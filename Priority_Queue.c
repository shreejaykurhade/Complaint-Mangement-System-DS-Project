#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100
#define MAX_PRIORITY 5

struct node {
    char complaint[size];
    int priority;
    struct node *link;
};

// Assigning priority
int assign_priority(const char *complaint) {
    if (strcmp(complaint, "a") == 0) {
        return 1;
    } else if (strcmp(complaint, "b") == 0) {
        return 2;
    } else if (strcmp(complaint, "c") == 0) {
        return 3;
    } else if (strcmp(complaint, "d") == 0) {
        return 4;
    } else {
        return 5;
    }
}

// Enqueue Function
struct node** enqueue(const char *complaint, struct node **s, int task_count[]) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory not allocated\n");
        return s;
    }
    
    int pri = assign_priority(complaint);
    strcpy(temp->complaint, complaint);  
    temp->priority = pri;
    temp->link = NULL;
    
    task_count[pri]++;

    // If the list is empty or new node has higher priority (min-priority)
    if (s[pri] == NULL || s[pri]->priority > pri) {
        // Insert at the front of the queue
        temp->link = s[pri];
        s[pri] = temp;
    } else {
        // Traverse to find the correct position
        struct node* q = s[pri];
        while (q->link != NULL && q->link->priority <= pri) {
            q = q->link;
        }
        // Insert the node in the correct position
        temp->link = q->link;
        q->link = temp;
    }

    return s;
}

// Creating Array of Queues
struct node** create() {
    struct node** queues = (struct node**)malloc((MAX_PRIORITY + 1) * sizeof(struct node*));
    for (int i = 0; i <= MAX_PRIORITY; i++) {
        queues[i] = NULL;
    }
    return queues;
}

// Swapping tasks 
void swap_tasks(struct node** queues, int priority1, int priority2, int task_count[]) {
    struct node* temp1 = queues[priority1];
    struct node* temp2 = queues[priority2];
    
    // Swapping tasks
    queues[priority1] = temp2;
    queues[priority2] = temp1;
    
    // Swapping task counts
    int temp_count = task_count[priority1];
    task_count[priority1] = task_count[priority2];
    task_count[priority2] = temp_count;
}

// Changing priority function
struct node** changing_priority(struct node** queues, int task_count[]) {
    for (int i = 1; i < MAX_PRIORITY; i++) {
        // If tasks exceed 5 in any priority, swapping with the next higher priority
        if (task_count[i] > 5) {
            swap_tasks(queues, i, i + 1, task_count);
        }
    }
    
    return queues;
}

void display(struct node *s)
{ printf("Elements of queue\n");
    struct node *q=s;
    if(q==NULL)
    {
        printf("Queue is empty\n");
    }
    else
      {while(q!=NULL)
        {
           printf("%s ",q->complaint);
           q=q->link;
        }
        printf("\n");
      }
}

struct node *dequeue(struct node *s)
{
    struct node *q=s;
    if(s==NULL)
    {
        printf("Nothing to delete\n");
        return s;
    }
    else if ( s->link==NULL)
    {
        free(s);
        printf("All deleted\n");
        return s;
    }
    else
    {s=s->link;
    printf("Removed element is %s\n",q->complaint);
    free(q);
    printf("After deletion\n");
    display(s);
    return s;}
};

int main() {
    // Create queues and task count array
    struct node** queues = create();
    int task_count[MAX_PRIORITY + 1] = {0};

    enqueue("Task1",queues,task_count);
    for (int i = 1; i <= MAX_PRIORITY; i++) {
        printf("Priority %d: ", i);
        display(queues[i]);
    }

    return 0;
}
