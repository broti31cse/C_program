/*
Q.8.2.
Train coaches using Doubly Linked List:   
A railway system stores the coaches of a train in a doubly linked list. 
Each coach has a coach number and link to both previous and next coaches. 
This allows the railway staff to inspect the coaches from the engine towards 
the last coach and from the last coach back towards the engine.   

Task: — Write a C Program (WACP) to:   
i) Create a doubly linked list of coach numbers.   
ii) Traverse and display the coaches in forward order.   
iii) Traverse and display the coaches in backward order.  
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coach;
    struct Node *prev;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *tail = NULL, *newNode;
    int n, i, coach;

    // Create doubly linked list
    printf("Enter number of coaches: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coach number: ");
        scanf("%d", &coach);

        newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->coach = coach;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Forward traversal
    printf("\nForward Order: ");
    newNode = head;

    while (newNode != NULL) {
        printf("%d <-> ", newNode->coach);
        newNode = newNode->next;
    }
    printf("NULL");

    // Backward traversal
    printf("\nBackward Order: ");
    newNode = tail;

    while (newNode != NULL) {
        printf("%d <-> ", newNode->coach);
        newNode = newNode->prev;
    }
    printf("NULL");

    return 0;
}