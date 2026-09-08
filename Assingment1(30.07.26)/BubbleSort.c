/*A class teacher has a list of marks of 10th students in a random fashion. All the marks are whole numbers. Before publishing the result, the teacher
wants to arrange the marks in an order so that the rank of the students can easily be deleted.
Use a method to order the marks in ascending order. Which method is used here? Implement the method using C.
Sample Input:
[99, 85, 58, 77, 46, 80, 78, 65, 42, 55]*/

#include <stdio.h>
int main()
{
    int marks[] = {92, 85, 58, 71, 46, 80, 76, 64, 49, 57};
    int n = 10;
    int i, j, temp;

    // Bubble Sort
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(marks[j] > marks[j+1])
            {
                temp = marks[j];
                marks[j] = marks[j+1];
                marks[j+1] = temp;
            }
        }
    }

    printf("Marks in ascending order:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", marks[i]);
    }

    return 0;
}
