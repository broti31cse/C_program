/*WAP in c where A single cinema hall has one ticket counter .one customer arrives at a time.
Simulate the ticket counter using queue.
The requriment are :
1.Add customer 2.Serve customer 3.Show "housefull" if the seats are full 
4.Display the all customer
*/
#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void addCustomer(int customer)
{
    if (rear == MAX - 1)
    {
        printf("Housefull! No more customers can be added.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = customer;

    printf("Customer %d added.\n", customer);
}

void serveCustomer()
{
    if (front == -1 || front > rear)
    {
        printf("No customer to serve.\n");
        return;
    }

    printf("Customer %d served.\n", queue[front]);
    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("No customers in queue.\n");
        return;
    }

    printf("Customers in queue: ");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    int choice, customer;

    while (1)
    {
        printf("\n1. Add Customer");
        printf("\n2. Serve Customer");
        printf("\n3. Display Customers");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter customer number: ");
                scanf("%d", &customer);
                addCustomer(customer);
                break;

            case 2:
                serveCustomer();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}