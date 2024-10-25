#include<stdio.h>
#include<stdlib.h>

struct node {
    char data;
    struct node *link;
};

void push(char ele, struct node **t) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = ele;
    temp->link = *t;
    *t = temp;
}

