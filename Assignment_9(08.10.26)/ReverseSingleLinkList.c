/*
Q.8.1.
Reversing a Delivery Route using a Singly Linked List.

A delivery company stores its delivery stops in a singly linked list.
Each node contains a stop number and a pointer to the next stop.
After completing the deliveries, the driver needs the stops displayed in
reverse order for the return journey.

Task: WACP to create the route, display it, reverse the singly linked list,
and display the reversed route.

Example:
    Original Route : 101 -> 102 -> 103 -> 104 -> NULL
    Reversed Route : 104 -> 103 -> 102 -> 101 -> NULL
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int stop;
    struct node *next;
};

struct node *createNode(int stop) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->stop = stop;
    newnode->next = NULL;
    return newnode;
}

void display(struct node *head) {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d", temp->stop);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

struct node *reverse(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main(void) {
    struct node *head = NULL;

    // Creating the route
    head = createNode(101);
    head->next = createNode(102);
    head->next->next = createNode(103);
    head->next->next->next = createNode(104);

    printf("Original Route : ");
    display(head);

    // Reverse the route
    head = reverse(head);

    printf("Reversed Route : ");
    display(head);

    return 0;
}

