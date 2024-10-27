// main.c
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "stack.h"
#include "queue.h"

int main() {
    struct QueueNode* start = NULL;
    int task_count[MAX_PRIORITY + 1] = {0};
    struct Stack* resolvedStack = createStack();
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. Display Queue (in order of removal)\n");
        printf("3. Dequeue/Resolve Task\n");
        printf("4. View Recently Resolved Tasks\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        char task[SIZE];
        switch (choice) {
            case 1:
                while (1) {
                    int optn;
                    printf("Enter '1' for Complaint1\nEnter '2' for Complaint2\nEnter '3' for Complaint3\nEnter '4' for Complaint4\nEnter '5' for custom complaint\n");
                    printf("Enter '0' to go back to the main menu\n");
                    scanf("%d", &optn);
                    getchar();
                    if (optn == 0) break;
                    switch (optn) {
                        case 1: start = enqueue("Complaint1", start, task_count); break;
                        case 2: start = enqueue("Complaint2", start, task_count); break;
                        case 3: start = enqueue("Complaint3", start, task_count); break;
                        case 4: start = enqueue("Complaint4", start, task_count); break;
                        case 5:
                            printf("Enter complaint (use '_' instead of spaces)\n");
                            fgets(task, SIZE, stdin);
                            task[strcspn(task, "\n")] = '\0';
                            start = enqueue(task, start, task_count);
                            break;
                        default: printf("Enter a valid option\n"); break;
                    }
                    displayQueue(start);
                }
                break;
            case 2: displayQueue(start); break;
            case 3: start = dequeue(start, task_count, resolvedStack); break;
            case 4: displayStack(resolvedStack); break;
            case 5:
                printf("Exiting program.\n");
                while (start != NULL) {
                    struct QueueNode* temp = start;
                    start = start->link;
                    free(temp);
                }
                while (!isEmptyStack(resolvedStack)) {
                    char* data = pop(resolvedStack);
                    if (data != NULL) free(data);
                }
                free(resolvedStack);
                return 0;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    }
}
