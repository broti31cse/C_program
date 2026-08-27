/*1. Case Study: Student Registration Management
A university department wants to develop a simple system to maintain a list of students who have registered for a technical workshop.
The number of students registering for the workshop is not fixed. Therefore, using a static array may result in either:
•	Wastage of memory when fewer students register, or
•	Insufficient space when more students register.
To solve this problem, the software developer decides to use a Singly Linked List.
Each student record will be represented using a node containing:
•	Student ID
•	Pointer to the next student
The first node of the linked list is accessed through a pointer called HEAD.
The department wants the system to perform the following basic operations:
1.	Create a singly linked list.
2.	Add student records dynamically.
3.	Traverse the linked list.
4.	Display all student records in the order in which they were added.
________________________________________*/ 
#include <stdio.h>
#include <stdlib.h>

// Structure for each student node
struct Node
{
    int studentID;
    struct Node *next;
};

// HEAD pointer
struct Node *head = NULL;

// Function to add a student
void addStudent(int id)
{
    struct Node *newNode;
    struct Node *temp;

    // Create new node dynamically
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->studentID = id;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        // Traverse to the last node
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Add new node at the end
        temp->next = newNode;
    }
}

// Function to display all students
void displayStudents()
{
    struct Node *temp;

    // Check if list is empty
    if (head == NULL)
    {
        printf("No students registered.\n");
        return;
    }

    printf("\nRegistered Students:\n");

    // Traverse the linked list
    temp = head;

    while (temp != NULL)
    {
        printf("Student ID: %d\n", temp->studentID);
        temp = temp->next;
    }
}

int main()
{
    int n, id, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Add student records dynamically
    for (i = 1; i <= n; i++)
    {
        printf("Enter Student ID: ");
        scanf("%d", &id);

        addStudent(id);
    }

    // Display all student records
    displayStudents();

    return 0;
}
