 /* 
consider a book rack,where books are placed in stack.Each book has acc_no
(1,2,3,4........)if you one asked to place book in stack using acc_no
have you performe these operation on stack of books.the sequence of operation
push(1),push(2),push(3),pop(3),push(4),push(5),pop(5) display the final position of books
*/
 #include <stdio.h>

#define MAX 10

int top = -1;

void push(int stack[], int x)
{
    if(top == MAX-1)
        printf("Stack is full\n");
    else
        stack[++top] = x;
}

int pop(int stack[])
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

void display(int stack[])
{
    int i;

    printf("Final stack: ");
    for(i = 0; i <= top; i++)
        printf("%d ", stack[i]);

    printf("\n");
}

int main()
{
    int acc_no, choice, stack[MAX];

    while(1)
    {
        printf("\nEnter your choice: PUSH:1 POP:2 EXIT:3\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter acc-no to be pushed: ");
                scanf("%d", &acc_no);
                push(stack, acc_no);
                break;

            case 2:
                acc_no = pop(stack);
                if(acc_no == -1)
                    printf("Stack is empty\n");
                else
                    printf("\nThe book %d is taken away\n", acc_no);
                break;

            case 3:
                display(stack);
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}